using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dfs.GoogleCodeJam.CodeJam2014.QualificationRound
{
    [ProblemInfo(ContestNames.CodeJam2014, RoundNames.QualificationRound, ProblemIdentifiers.B)]
    internal class CookieClickerAlpha : ProblemBase
    {
        protected override ProblemCaseBase ParseCase(TextReader reader)
        {
            return new CookieClickerAlphaCase(reader);
        }

        private class CookieClickerAlphaCase : ProblemCaseBase
        {
            public CookieClickerAlphaCase(TextReader reader)
            {
                decimal[] numbers = reader.ReadLine().Split(' ').Select(decimal.Parse).ToArray();
                c = numbers[0];
                f = numbers[1];
                x = numbers[2];
            }

            public override string Solve()
            {
                decimal accumulate = 0;
                decimal previous = decimal.MaxValue;
                for (int i = 0; ; i++)
                {
                    decimal current = accumulate + x / (2 + i * f);
                    if (previous <= current) return previous.ToString();
                    previous = current;
                    accumulate += c / (2 + i * f);
                }
            }

            private readonly decimal c;
            private readonly decimal f;
            private readonly decimal x;
        }
    }
}
