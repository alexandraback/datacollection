using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2016
{
    public class Fractiles
    {
        public string Solve(int S, int C, int K)
        {
            //This solution is for ONLY Small dataset (S=K).
            if (S != K)
            {
                return "IMPOSSIBLE";
            }
            //
            StringBuilder answer = new StringBuilder();
            for (int i = 0; i < S; ++i)
            {
                answer.AppendFormat("{0} ", i + 1);
            }
            //
            return (answer.ToString().Trim());
        }
    }
}
