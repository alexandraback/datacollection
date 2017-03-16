using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;


namespace _2013_R1B
{
    class A_Osmos: ProblemBase
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
                string[] Inputs = Line1.Split();
                uint A = uint.Parse(Inputs[0]);
                byte N = byte.Parse(Inputs[1]);
                Inputs = Line2.Split();
                List<uint> Motes = new List<uint>(N);
                foreach (string In in Inputs)
                {
                    Motes.Add(uint.Parse(In));
                }
                Motes.Sort();
                List<Action> Actions = new List<Action>();

                while (Motes.Count > 0)
                {
                    if (A > Motes[0])
                    {
                        A += Motes[0];
                        Motes.RemoveAt(0);
                    }
                    else if(A > 1)
                    {
                        uint I;
                        for (I = 0; A <= Motes[0]; I++)
                        {
                            A = (A << 1) - 1;
                        }
                        Actions.Add(new Action(I, Motes.Count));
                    }
                    else
                    {
                        Actions.Add(new Action(101, Motes.Count));
                        break;
                    }
                }

                uint TotalInserts = 0;
                int TotalRemoved = 0;
                for (int I = Actions.Count - 1; I >= 0; I--)
                {
                    int StepRemaining = Actions[I].Remaining - TotalRemoved;
                    uint StepInsert = Actions[I].Inserts;
                    if (StepInsert >= StepRemaining)
                    {
                        TotalRemoved += StepRemaining;
                        TotalInserts = 0;
                    }
                    else
                    {
                        TotalInserts += StepInsert;
                        if (TotalInserts >= Actions[I].Remaining)
                        {
                            TotalRemoved = Actions[I].Remaining;
                            TotalInserts = 0;
                        }
                    }
                }

                Result = (TotalInserts + TotalRemoved).ToString();
            }
            struct Action
            {
                public uint Inserts;
                public int Remaining;
                public Action(uint inserts, int remaining)
                {
                    Inserts = inserts;
                    Remaining = remaining;
                }
            }
        }
    }
}
