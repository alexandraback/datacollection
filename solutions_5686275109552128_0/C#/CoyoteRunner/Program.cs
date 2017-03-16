using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace google_code_jam
{
    class InfiniteHouseofPancakes
    {
        public string solve(string s)
        {
            var x = new List<int>();

            foreach (var t in s.Split(' '))
            {
                x.Add(int.Parse(t));
            }

            int min = x.Max();

            for (int i = 2; i < 1000; i++)
            {
                int sum = 0;

                for (int j = 0; j < x.Count; j++)
                {
                    int q = x[j] / i;

                    if (x[j] % i > 0)
                    {
                        q++;
                    }

                    sum += q - 1;
                }

                min = Math.Min(min, sum + i);
            }

            return min.ToString();
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            string folder = @"D:\tmp\";
            string input = "input";

            StreamReader reader = new StreamReader(folder + input + ".in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(folder + "out.txt");
            string s = reader.ReadLine();

            int T = int.Parse(s);

            for (int i = 0; i < T; i++)
            {
                reader.ReadLine();
                var x = reader.ReadLine();

                string r = "Case #" + (i + 1).ToString() + ":" + " " + new InfiniteHouseofPancakes().solve(x);

                writer.WriteLine(r);
                Console.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }
    }
}
