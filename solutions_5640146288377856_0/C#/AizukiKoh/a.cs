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
            if (R == 1)
            {
                if (W < C / 2 && C % 2 == 0 || W <= C / 2 && C % 2 != 0)
                {
                    if (C % W == 0)
                    {
                        return R * C / W + W - 1;
                    }
                    else
                    {
                        return R * C / W + W;
                    }
                }
                else
                {
                    return W + 1;
                }
            }
            return 0;
        }
    }
}
