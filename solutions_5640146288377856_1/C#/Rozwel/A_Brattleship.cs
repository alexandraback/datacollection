using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace Rozwel.CodeJam._2015_R1C
{
    public class A_Brattleship : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            int R;
            int C;
            int W;
            public TestCase(TextReader inputStream)
            {
                string Line = inputStream.ReadLine();
                var CaseParts = Line.Split(' ');
                R = int.Parse(CaseParts[0]);
                C = int.Parse(CaseParts[1]);
                W = int.Parse(CaseParts[2]);
            }

            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                Result = (((C / W) * R) + (W - (C % W == 0 ? 1 : 0))).ToString();

            }
        }
    }
}
