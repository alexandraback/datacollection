using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace Rozwel.CodeJam._2014_QR
{
    public class B_CookieClickerAlpha : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            double C;
            double F;
            double X;
            public TestCase(TextReader inputStream)
            {
                string line;
                line = inputStream.ReadLine();

                string[] values = line.Split(' ');
                C = double.Parse(values[0]);
                F = double.Parse(values[1]);
                X = double.Parse(values[2]);
            }
            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                List<double> TimeToBuyFarm = new List<double>();
                List<double> TimeToTarget = new List<double>();

                int I = 0;
                double P = 2;
                TimeToBuyFarm.Insert(I, 0);
                TimeToTarget.Insert(I, X / P);
                do
                {
                    token.ThrowIfCancellationRequested();
                    I++;
                    TimeToBuyFarm.Insert(I,  C / P + TimeToBuyFarm[I-1]);
                    P += F;
                    TimeToTarget.Insert(I,X / P + TimeToBuyFarm[I]);
                } while (TimeToTarget[I] < TimeToTarget[I - 1]);
                Result = TimeToTarget[I - 1].ToString("F7");
            }
        }
    }
}
