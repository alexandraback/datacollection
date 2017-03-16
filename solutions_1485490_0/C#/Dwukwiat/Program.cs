using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam.Round1C.C
{
    internal class Program
    {
        class TwoValues
        {
            public decimal First { get; set; }
            public decimal Second { get; set; }
        }
        private class TestCase
        {
            private List<TwoValues> Boxes = new List<TwoValues>();
            private List<TwoValues> Tools = new List<TwoValues>();

            public void Solve()
            {
                decimal maxShipped = 0;
                int max = Boxes.Count + Tools.Count + 1;
                int firstBoxSkip = 1;
                int secondBoxSkip = 2;
                int thirdBoxSkip = 3;
                while(firstBoxSkip < max || secondBoxSkip < max || thirdBoxSkip < max)
                {

                    decimal shipped = 0;
                    int currentSkip = 1;
                    while (Boxes.Count > 0 && Tools.Count > 0)
                    {
                        if (Boxes.First().First == Tools.First().First)
                        {
                            decimal min = Math.Min(Boxes.First().Second, Tools.First().Second);
                            shipped += min;
                            Boxes.First().Second -= min;
                            Tools.First().Second -= min;
                            if (Boxes.First().Second == 0)
                            {
                                Boxes = Boxes.Skip(1).ToList();
                                currentSkip++;
                            }
                            if (Tools.First().Second == 0)
                            {
                                Tools = Tools.Skip(1).ToList();
                                currentSkip++;
                            }
                        }
                        else
                        {
                            if (currentSkip == firstBoxSkip || currentSkip == secondBoxSkip || currentSkip == thirdBoxSkip)
                            {
                                Boxes = Boxes.Skip(1).ToList();
                            }
                            else
                            {
                                Tools = Tools.Skip(1).ToList();
                            }
                            currentSkip++;
                        }
                    }
                    if (shipped > maxShipped)
                        maxShipped = shipped;

                    thirdBoxSkip++;
                    if(thirdBoxSkip > max + 1)
                    {
                        secondBoxSkip++;
                        thirdBoxSkip = secondBoxSkip + 1;
                        if(secondBoxSkip > max + 1)
                        {
                            firstBoxSkip++;
                            secondBoxSkip = firstBoxSkip + 1;
                            thirdBoxSkip = firstBoxSkip + 2;
                        }
                    }
                }
                _result = maxShipped.ToString();
            }

            public void Parse(StreamReader sr)
            {
                sr.ReadLine();
                var boxes = sr.ReadLine().Split(' ');
                for (int i = 0; i < boxes.Length/2; i++)
                {
                    decimal count = Decimal.Parse(boxes[i * 2]);
                    decimal type = Decimal.Parse(boxes[i * 2 + 1]);
                    Boxes.Add(new TwoValues() { First = type, Second = count });
                }

                var tools = sr.ReadLine().Split(' ');
                for (int i = 0; i < tools.Length/2; i++)
                {
                    decimal count = Decimal.Parse(tools[i*2]);
                    decimal type = Decimal.Parse(tools[i * 2 + 1]);
                    Tools.Add(new TwoValues() { First = type, Second = count });
                }
            }

            internal void Output(StreamWriter sw)
            {
                //output
                sw.WriteLine("Case #" + TestCaseNumber + ": " + _result);
            }

            #region Hidden

            private string _result;

            public TestCase(int testCaseNumber)
            {
                TestCaseNumber = testCaseNumber;
            }

            public int TestCaseNumber { get; private set; }

            #endregion
        }

        #region Main

        private static void Main()
        {
            var testCases = new List<TestCase>();
            using (var sr = new StreamReader("input.txt"))
            {
                int testCasesNumber = Int32.Parse(sr.ReadLine());
                for (int i = 0; i < testCasesNumber; i++)
                {
                    var testCase = new TestCase(i + 1);
                    testCase.Parse(sr);
                    testCases.Add(testCase);
                }
            }

            using (var sw = new StreamWriter("output.txt"))
            {
                foreach (var testCase in testCases.OrderBy(x => x.TestCaseNumber))
                {
                    testCase.Solve();
                    testCase.Output(sw);
                }
            }
        }

        #endregion
    }
}
