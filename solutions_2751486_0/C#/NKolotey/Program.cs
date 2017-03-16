using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace A
{
    class Program
    {
        static int Consonates(string s, int begin, int end)
        {
            int max = 0;
            int curr_counter = 0;
            for (int i = begin; i < end; i++)
            {
                char c = s[i];
                bool v = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

                if (v)
                    curr_counter = 0;
                else
                {
                    curr_counter++;
                    max = Math.Max(max, curr_counter);
                }
            }

            return max;
        }

        static int Solve(string s, int nc)
        {
            int n = s.Length;
            int count = 0;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j <= n; j++)
                    if (Consonates(s, i, j) >= nc)
                        count++;

            return count;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                string s = line[0];
                int n = int.Parse(line[1]);
                Console.WriteLine("Case #{0}: {1}", t, Solve(s, n));
            }
        }
    }
}
