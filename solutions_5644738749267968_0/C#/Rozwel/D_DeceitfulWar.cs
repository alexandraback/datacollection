using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace Rozwel.CodeJam._2014_QR
{
    public class D_DeceitfulWar : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            ushort N;
            List<double> Naomi;
            List<double> Ken;

            public TestCase(TextReader inputStream)
            {
                string Line = inputStream.ReadLine();
                N = ushort.Parse(Line);
                Line = inputStream.ReadLine();
                Naomi = Line.Split(' ').ToList().ConvertAll(Convert.ToDouble);
                Line = inputStream.ReadLine();
                Ken = Line.Split(' ').ToList().ConvertAll(Convert.ToDouble);
            }
            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();

                Naomi.Sort();
                token.ThrowIfCancellationRequested();

                Ken.Sort();
                token.ThrowIfCancellationRequested();

                List<double> NaomiD = new List<double>(Naomi);
                List<double> KenD = new List<double>(Ken);
                token.ThrowIfCancellationRequested();

                /*
                 * Ken Strategy:
                 * If ken can win, play smallest block available that will win
                 * else, play smallest block to preserve future winning potential
                 */
                ushort NaomiPoint = 0;
                for (int R = N - 1; R >= 0; R--)
                {
                    token.ThrowIfCancellationRequested();
                    if (Ken[R] > Naomi[R])
                    {
                        Ken.RemoveAt(R);
                        Naomi.RemoveAt(R);
                    }
                    else
                    {
                        Ken.RemoveAt(0);
                        Naomi.RemoveAt(R);
                        NaomiPoint++;
                    }
                }



                /*
                 * Naomi Strategy:
                 * Must get rid of ken's largest blocks first
                 * If KenMin > NaomiMin, play NaomiMin but KenMax > NaomiTold > KenMax-1 (Ken plays KenMax)
                 * else, play NaomiMin but NaomiTold > KenMax (Ken plays KenMin)
                 */
                ushort NaomiPointD = 0;
                for (int R = N - 1; R >= 0; R--)
                {
                    token.ThrowIfCancellationRequested();
                    if (KenD[0] > NaomiD[0])
                    {
                        KenD.RemoveAt(R);
                        NaomiD.RemoveAt(0);
                    }
                    else
                    {
                        KenD.RemoveAt(0);
                        NaomiD.RemoveAt(0);
                        NaomiPointD++;
                    }
                }

                Result = NaomiPointD.ToString() + " " + NaomiPoint.ToString();
            }
        }
    }
}
