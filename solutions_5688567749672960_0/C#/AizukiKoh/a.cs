using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2015._1B
{
    class a
    {
        static void Main(string[] args)
        {
            var T = int.Parse(System.Console.ReadLine().Trim());
            for (int i = 0; i < T; ++i)
            {
                var line = System.Console.ReadLine().Trim();
                var N = long.Parse(line);
                var ans = solve(N, 0);
                Console.WriteLine("Case #{0:D}: {1:D}", i + 1, ans);
            }
        }

        private static int solve(long N, int cnt)
        {
            if (N == 1)
            {
                return cnt + 1;
            }
            else
            {
                return solve(Math.Min(N - 1, reverse(N)), cnt + 1);
            }
        }

        private static long reverse(long N)
        {
            if (N % 10 != 1)
            {
                return N;
            }
            else
            {
                string s = N.ToString();
                char[] chars = s.ToCharArray();
                Array.Reverse(chars);
                for (int i = 1; i < (chars.Length / 2); ++i)
                {
                    if (chars[i] != '0')
                    {
                        return N;
                    }
                }
                return long.Parse(new string(chars));
            }
        }
    }
}
