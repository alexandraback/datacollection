using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamZad3
{
    class Program
    {
        static string pathIn = @"C:\Users\Admin\Downloads\C-small-attempt0.in";
        static string pathOut = @"C:\Users\Admin\Downloads\out.txt";

        static void Main(string[] args)
        {
            string[] file = File.ReadAllLines(pathIn);
            int T = int.Parse(file[0]);

            StringBuilder bui = new StringBuilder();
            for (int i = 1; i <= T; ++i)
            {
                int result = 0;

                string[] dane = file[i].Split(' ');
                int A = int.Parse(dane[0]);
                int B = int.Parse(dane[1]);

                for (int j = A; j <= B; ++j)
                {
                    result += Count(A, B, j);
                }

                bui.Append(string.Format("Case #{0}: {1}{2}", i, result, Environment.NewLine));
            }

            File.WriteAllText(pathOut, bui.ToString());
        }

        static int Count(int A, int B, int j)
        {
            string current = j.ToString();

            LinkedList<int> list = new LinkedList<int>();

            for (int i = 0; i < current.Length; ++i)
            {
                int cur = int.Parse(current);

                if (cur > j && cur <= B)
                {
                    list.AddLast(cur);
                }

                current = current[current.Length - 1] + current.Substring(0, current.Length - 1);
            }

            return list.Distinct<int>().Count();
        }
    }
}
