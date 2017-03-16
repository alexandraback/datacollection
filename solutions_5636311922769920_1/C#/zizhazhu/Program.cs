using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fractiles
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.StreamReader input = new System.IO.StreamReader(@"D:\codejam\Fractiles\D-large.in");
            System.IO.StreamWriter output = new System.IO.StreamWriter(@"D:\codejam\Fractiles\D-large.out");

            int count = 0;
            List<int[]> data = new List<int[]>();
            string line;
            bool first = true;
            int idx = 0;
            while ((line = input.ReadLine()) != null)
            {
                if (first)
                {
                    count = int.Parse(line);
                    first = false;
                }
                else
                {
                    string[] row = line.Split(' ');
                    int[] cur = new int[3];
                    cur[0] = int.Parse(row[0]);
                    cur[1] = int.Parse(row[1]);
                    cur[2] = int.Parse(row[2]);
                    data.Add(cur);
                    idx++;
                }
            }
            input.Close();

            idx = 0;
            foreach(int[] cur in data)
            {
                string res = null;
                int k = cur[0];
                int c = cur[1];
                int s = cur[2];
                List<long> check = new List<long>();
                int min = 0;
                if (k % c > 0)
                {
                    min = k / c + 1;
                }
                else
                {
                    min = k / c;
                }
                if (s < min)
                {
                    res = "IMPOSSIBLE";
                }
                else
                {
                    for (int start = 0; start < min; start++)
                    {
                        check.Add(GetPos(k, c, start));
                    }
                    res = string.Join(" ", check);
                }
                output.WriteLine("Case #{0}: {1}", idx+1, res);
                idx++;
            }
            output.Close();
        }
        public static long GetPos(long k, long c, long start)
        {
            long pos = 1 + start * c;
            long i = Math.Min(k, pos + 1);
            while (c > 1)
            {
                pos = (pos - 1) * k + i;
                if (i<k)
                {
                    i++;
                }
                c--;
            }
            return pos;
        }
    }
}
