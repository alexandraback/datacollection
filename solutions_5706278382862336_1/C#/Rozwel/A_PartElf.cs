using Rozwel.CodeJam.Framework;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rozwel.CodeJam._2014_R1C
{
    public class A_PartElf : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            UInt64 P;
            UInt64 Q;
            public TestCase(TextReader inputStream)
            {
                string Line = inputStream.ReadLine();
                string[] Terms = Line.Split('/');
                P = UInt64.Parse(Terms[0]);
                Q = UInt64.Parse(Terms[1]);
            }
            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                Reduce(token);
                if (!IsPowerOf2(Q))
                {
                    Result = "impossible";
                }
                else
                {
                    byte Generations = 0;
                    UInt64 p = P;

                    while (p < Q && Generations <= 40)
                    {
                        token.ThrowIfCancellationRequested();
                        p = p << 1;
                        Generations++;
                    }

                    if (Generations > 40)
                        Result = "impossible";
                    else
                        Result = Generations.ToString();
                }
            }
            bool IsPowerOf2(UInt64 value)
            {
                if (value > 1)
                    if ((value & 1) == 0)
                        return IsPowerOf2(value >> 1);
                    else
                        return false;
                else
                    return true;
            }
            void Reduce(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                UInt64 GCD = GetGreatestCommonDivisor(Q, P, token);
                P = P / GCD;
                Q = Q / GCD;
            }
            UInt64 GetGreatestCommonDivisor(UInt64 t1, UInt64 t2, System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                return t2 == 0 ? t1 : GetGreatestCommonDivisor(t2, t1 % t2, token);
            }
        }
        //public class Fraction
        //{
        //    bool Negative { get; set; }
        //    UInt64 Numerator { get; set; }
        //    UInt64 Denominator { get; set; }

        //    public Fraction(UInt64 numerator, UInt64 denominator, bool negative)
        //    {
        //        Negative = negative;
        //        Numerator = numerator;
        //        Denominator = denominator;
        //    }

        //    //public Fraction Plus(Fraction term)
        //    //{

        //    //}
        //}
    }
}
