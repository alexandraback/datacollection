using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_QualificationRound
{
    public class C
    {
        private void Run()
        {
            // small only
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                var input = Console.ReadLine().Trim().Split();
                var L = int.Parse(input[0]);
                var X = int.Parse(input[1]);
                var str = string.Concat(Enumerable.Repeat(Console.ReadLine().Trim(), X));
                L *= X;

                // dp[index][before i/after i/after j/after k]][mul]
                var dp = Enumerable.Repeat(0, L + 1).Select(_ => Enumerable.Repeat(0, 4).Select(__ => new bool[8]).ToArray()).ToArray();
                const int P_1 = 0;
                const int M_1 = 1;
                const int P_I = 2;
                const int M_I = 3;
                const int P_J = 4;
                const int M_J = 5;
                const int P_K = 6;
                const int M_K = 7;
                // nextInv[j, i] == i*j
                var nextInv = new int[,]
                {
                    {P_I, M_I, M_1, P_1, M_K, P_K, P_J, M_J},
                    {P_J, M_J, P_K, M_K, M_1, P_1, M_I, P_I},
                    {P_K, M_K, M_J, P_J, P_I, M_I, M_1, P_1},
                };
                dp[0][0][P_1] = true;
                for (int i = 0; i < L; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        for (int k = 0; k < 8; ++k)
                        {
                            if (!dp[i][j][k]) { continue; }

                            int n;
                            switch (str[i])
                            {
                                case 'i': n = nextInv[0, k]; break;
                                case 'j': n = nextInv[1, k]; break;
                                case 'k': n = nextInv[2, k]; break;
                                default: throw new Exception();
                            }
                            dp[i + 1][j][n] = true;
                            if ((j == 0 && n == P_I)
                                || (j == 1 && n == P_J)
                                || (j == 2 && n == P_K))
                            {
                                dp[i + 1][j + 1][P_1] = true;
                            }
                        }
                    }
                }

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine(dp[L][3][P_1] ? "YES" : "NO");
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new C().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
