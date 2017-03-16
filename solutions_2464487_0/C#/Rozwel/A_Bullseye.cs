using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace _2013_R1A
{
    class A_Bullseye: ProblemBase
    {
        protected override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        protected class TestCase : TestCaseBase
        {
            string Line;   
            public TestCase(TextReader inputStream)
            {
                Line = inputStream.ReadLine();
            }

            protected override void Solve()
            {
                string[] Values = Line.Split();
                ulong R = ulong.Parse(Values[0]);
                ulong T = ulong.Parse(Values[1]);
                ulong W = R * R;
                R++;
                ulong B = R * R;
                ulong A = B - W;
                int Count = 0;
                while (T >= A)
                {
                    Count++;
                    T -= A;
                    R++;
                    W = R * R;
                    R++;
                    B = R * R;
                    A = B-W;
                }
                Result = Count.ToString();
            }
        }
    }
}
