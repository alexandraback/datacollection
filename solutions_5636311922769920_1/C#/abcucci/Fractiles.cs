using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2016
{
    public class Fractiles
    {
        public string Solve(int K, int C, int S)
        {
            //This solution is for ONLY Small dataset (S=K).
            if (K <= S)
            {
                //
                StringBuilder answer = new StringBuilder();
                for (int i = 0; i < K; ++i)
                {
                    answer.AppendFormat("{0} ", i + 1);
                }
                //
                return (answer.ToString().Trim());
            }

            // for Large dataset (S < K)
            if (((K - 1) <= S) && (1 < C))
            {
                StringBuilder answer = new StringBuilder();
                for (int i = 1; i < K; ++i)
                {
                    answer.AppendFormat("{0} ", i + 1);
                }
                //
                return (answer.ToString().Trim());
            }

            //
            return "IMPOSSIBLE";

        }
    }
}
