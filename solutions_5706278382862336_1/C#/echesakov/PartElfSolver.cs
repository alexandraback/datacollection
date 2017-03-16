using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{
    class PartElfSolver
    {
        public string[] Solve(string[] input)
        {
            List<string> output = new List<string>();

            int index = 0;
            int T = int.Parse(input[index++]);
            const int maxLen = 64;

            for (int i = 0; i < T; i++)
            {
                string[] PQ = input[index++].Split('/');
                long P = long.Parse(PQ[0]);
                long Q = long.Parse(PQ[1]);

                int[] p = new int[maxLen];

                int k = 0;
                for (; k < maxLen; k++)
                {
                    if (P == 0) break;
                    
                    if (P >= Q)
                    {
                        P -= Q;
                        p[k] = 1;
                    }

                    P = P << 1;
                }

                if (k == maxLen)
                {
                    int x = i + 1;
                    output.Add(string.Format("Case #{0}: impossible", x));
                }
                else
                {
                    int minGen = Array.FindIndex(p, item => item > 0);

                    int x = i + 1;
                    int y = minGen;
                    output.Add(string.Format("Case #{0}: {1}", x, y));
                }
            }

            return output.ToArray();
        }
    }
}
