using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            for (int i = 1; i <= N; i++)
            {
                var line = Console.ReadLine().Split(' ');
                int from = int.Parse(line[0]);
                int to = int.Parse(line[1]);

                int ans = 0;

                var max = IntToArr(to);

                for (int j = from; j <= to; j++)
                {
                    var curr = IntToArr(j);
                    ans += RotatedLessThan(curr, max);
                }

                Console.WriteLine("Case #" + i + ": " + ans);
            }
        }

        public static int[] IntToArr(int a)
        {
            string s = a.ToString();
            int[] retval = new int[s.Length];

            for (int i = 0; i < s.Length; i++)
            {
                retval[i] = s[i] - '0';
            }

            return retval;
        }


        public static int RotatedLessThan(int[] num, int[] max)
        {
            int ans = 0;
            int[] ansrotates = new int[num.Length];

            for (int i = 0; i < num.Length; i++)
            {
                bool lessthanmax = CompSmallerEqual(num, i, max);
                if (!lessthanmax)
                    continue;

                bool larger = CompLarger(num, 0, i);
                if (larger)
                {
                    bool unique = true;
                    for (int j = 0; j < ansrotates.Length; j++)
                    {
                        if (ansrotates[j] == 0) continue;

                        if (Comp(num, i, ansrotates[j]))
                            unique = false;
                    }

                    if (unique)
                    {
                        ansrotates[i] = i;
                        ans++;
                    }
                }
            }

            return ans;
        }

        public static bool Comp(int[] a, int afrom, int bfrom)
        {
            int len = a.Length;

            for (int i = 0; i < len; i++)
            {
                int acurr = a[(afrom + i) % len];
                int bcurr = a[(bfrom + i) % len];

                if (acurr != bcurr)
                    return false;
            }

            return true;
        }

        public static bool CompLarger(int[] a, int afrom, int bfrom)
        {
            int len = a.Length;
            for (int i = 0; i < len; i++)
            {
                int acurr = a[(afrom + i) % len];
                int bcurr = a[(bfrom + i) % len];

                if (bcurr < acurr)
                    return false;

                if (bcurr > acurr)
                    return true;
            }

            return false;
        }

        public static bool CompSmallerEqual(int[] a, int bfrom, int[] max)
        {
            int len = a.Length;
            for (int i = 0; i < len; i++)
            {
                int bcurr = a[(bfrom + i) % len];
                int maxcurr = max[i];

                if (bcurr > maxcurr)
                    return false;

                if (bcurr < maxcurr)
                    return true;
            }

            return true;
        }


    }


}
