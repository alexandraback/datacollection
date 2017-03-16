using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace CodeJam_2016_R1A_2
{
    class Program
    {
        static String Solve(int n, string[] lines, int current)
        {
            Dictionary<Int32, Int32> dict = new Dictionary<int, int>();

            for (int i = 0; i < n * 2 - 1; i++)
            {
                int[] val = lines[i + current].Trim().Split(new char[] { ' ' }).Select(Int32.Parse).ToArray();
                foreach(var item in val)
                {
                    int count;
                    if (dict.TryGetValue(item, out count))
                    {
                        dict[item] = count + 1;
                    } else { dict[item] = 1; }
                }
            }

            List<int> res = new List<int>();
            foreach(var kv in dict)
            {
                if (kv.Value % 2 != 0) res.Add(kv.Key);

            }
            res.Sort();
            return String.Join(" ", res);
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2016\Round1A\Task2_input\B-small-attempt0.in");
            Int32 count = Int32.Parse(lines[0].Trim());
            Int32 current = 1;
            for (Int32 i = 0; i < count; i++)
            {
                int n = Int32.Parse(lines[current].Trim());

                String res = Solve(n, lines, current + 1);
               
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
                current += n * 2;
            }
        }

    }
}
