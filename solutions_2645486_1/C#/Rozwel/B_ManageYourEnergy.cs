using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace _2013_R1A
{
    class B_ManageYourEnergy : ProblemBase
    {
        protected override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        protected class TestCase : TestCaseBase
        {
            string Line1;
            string Line2;
            public TestCase(TextReader inputStream)
            {
                Line1 = inputStream.ReadLine();
                Line2 = inputStream.ReadLine();
            }

            protected override void Solve()
            {
                uint E;
                uint R;
                uint N;
                string[] Parsing = Line1.Split();
                E = uint.Parse(Parsing[0]);
                R = uint.Parse(Parsing[1]);
                N = uint.Parse(Parsing[2]);
                Parsing = Line2.Split();
                uint[] Values = new uint[N];
                ulong Gain = 0;
                for (uint I = 0; I < N; I++)
                {
                    Values[I] = uint.Parse(Parsing[I]);
                }
                if (R >= E)
                {
                    for (uint I = 0; I < N; I++)
                    {
                        Gain += E * Values[I];
                    }
                }
                else
                {
                    uint En = E;
                    uint Look = E / R + 1;
                    uint FullStep = 0;
                    uint Vi;
                    uint LookStep;
                    bool Building = false; ;
                    for (uint I = 0; I < N; I++)
                    {
                        Vi = Values[I];
                        //if (I >= FullStep)
                        //{
                            LookStep = I + Look;
                            Building = false;
                            for (uint J = I + 1; J < N && J <= LookStep; J++)
                            {
                                if (Values[J] >= Vi)
                                {
                                    Building = true;
                                    FullStep = J;
                                    break;
                                }
                            }
                        //}
                        if (Building)
                        {
                            uint Burn = En + ((FullStep - I) * R);
                            if (Burn > E)
                            {
                                Burn -= E;
                            }
                            else
                            {
                                Burn = 0;
                            }
                            if (Burn > En)
                            {
                                Burn = En;
                            }
                            Gain += Burn * Vi;
                            En += (R - Burn);
                        }
                        else
                        {
                            Gain += En * Vi;
                            En = R;
                        }

                    }
                }

                Result = Gain.ToString();
            }
        }
    }
}
