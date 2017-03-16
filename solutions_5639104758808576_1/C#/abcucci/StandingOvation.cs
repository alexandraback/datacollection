using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QualificationRound
{
    public class StandingOvation
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
                string S = values[1];

                int friend = this.Solve(S);

                answer += string.Format("Case #{0}: {1}", i, friend);
                answer += Environment.NewLine;
            }

            return answer;
        }

        public int Solve(string S)
        {
            int friend = 0;
            int N = S.Length;
            int standing = 0;
            for (int i = 0; i < N; ++i)
            {
                if (standing < i)
                {
                    friend += (i - standing);
                    standing = i;
                }

                char c = S[i];
                int x = c - '0';
                standing += x;
            }

            return friend;
        }

    }
}
