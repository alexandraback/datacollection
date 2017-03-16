using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2015._1C
{
    class a
    {
        static void Main(string[] args)
        {
            var T = int.Parse(System.Console.ReadLine().Trim());
            for (int i = 0; i < T; ++i)
            {
                var line = System.Console.ReadLine().Trim().Split(' ');
                var R = int.Parse(line[0]);
                var C = int.Parse(line[1]);
                var W = int.Parse(line[2]);

                Console.WriteLine("Case #{0:D}: {1:D}", i + 1, solve(R,C,W));
            }
        }

        private static int solve(int R, int C, int W)
        {
            if (W == 1 || W == R * C)
            {
                return R * C;
            }
            var s = Math.Min(R, C);
            var b = Math.Max(R, C);
            var cnt = 0;
            if (s < W)
            {
                cnt += b / W * (s - 1);
                if (W > b / 2)
                {
                    return cnt + W + 1;
                }
                else
                {
                    return cnt + (b - 1) / W + W;
                }
            }
            else
            {
                cnt += s / W * b;
                var a = W - b % W;
                for (int i = 0; i < s%W; ++i)
                {
                    if (i < a)
                    {
                        cnt += s / W;
                    }
                    else
                    {
                        cnt += s / W + 1;
                    }
                }
                if (s <= 2)
                {
                    return cnt + W + 1;
                }
                else
                {
                    return cnt + W + 2;
                }
            }
        }
    }
}
