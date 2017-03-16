using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QualificationRound
{
    //    Problem D. Ominous Omino
    public class OminousOmino
    {
        public string Run(string inputText)
        {
            string[] lines = inputText.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
            int N = lines.Length;

            String answer = "";
            for (int i = 1; i < N; ++i)
            {
                string line = lines[i];
                string[] values = line.Split(' ');
                int X = int.Parse(values[0]);
                int R = int.Parse(values[1]);
                int C = int.Parse(values[2]);

                bool covered = this.Solve(X, R, C);

                answer += string.Format("Case #{0}: {1}", i, (covered ? "GABRIEL" : "RICHARD"));
                answer += Environment.NewLine;
            }

            return answer;
        }

        public bool Solve(int X, int R, int C)
        {
            //area=R*C must be multiple of X.
            int area = R * C;
            if ((area % X) != 0)
            {
                return false;
            }

            //long edge=max(R,C) must be equal or grater than X)
            int max = Math.Max(R, C);
            int min = Math.Min(R, C);
            if (max < X)
            {
                return false;
            }

            // 
            if (X == 1)
            {
                return true;
            }

            if (X == 2)
            {
                return true;
            }

            if (X == 3)
            {
                return (min >= 2);
            }

            if (X == 4)
            {
                return (min >= 3);
            }

            if (X == 5)
            {
                return (min >= 4);
            }

            if (X == 6)
            {
                return (min >= 5);
            }

            // X >= 7.
            // omino can include a one cell hall inside itself.
            return false;
        }
    }
}
