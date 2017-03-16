using Rozwel.CodeJam.Framework;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rozwel.CodeJam._2014_R1B
{
    public class B_NewLotteryGame : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            UInt64 A;
            UInt64 B;
            UInt64 K;
            public TestCase(TextReader inputStream)
            {
                string Line = inputStream.ReadLine();
                string[] values = Line.Split(' ');
                A = UInt64.Parse(values[0]);
                B = UInt64.Parse(values[1]);
                K = UInt64.Parse(values[2]);
            }
            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();

                UInt64 Wins = 0;
                for (UInt64 a = 0; a < A; a++)
                {
                    token.ThrowIfCancellationRequested();
                    for (UInt64 b = 0; b < B; b++)
                    {
                        token.ThrowIfCancellationRequested();
                        UInt64 r = a & b;
                        if (r < K)
                        {
                            Wins++;
                        }
                    }
                }

                Result = Wins.ToString();


            }
        }
    }
}
