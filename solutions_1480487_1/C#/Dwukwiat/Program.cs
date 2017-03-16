using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam.Round1B.A
{
    class Program
    {
        class TestCase
        {
            public int Count { get; set; }
            public List<int> Elements { get; set; }
            public List<int> Sorted { get; set; }
            public int Sum { get; set; }

            public void Solve()
            {
                _result = "";
                
                
                for (int i = 0; i < Elements.Count; i++)
                {
                    Boolean end = false;
                    double percentage = 0;
                    double currentAdd = 0;
                    int current = Elements[i];

                    var smaller = Sorted.Where(x => x < Elements[i]);
                    foreach (var x in smaller)
                    {
                        percentage += ((current - x)/(double) Sum)*100;
                    }
                    if (percentage >= 100)
                    {
                        _result += "0.000000 ";
                        continue;
                    }

                    double theRest = 100 - percentage;
                    int currentCount = Sorted.Where(x => x<=current).Count();
                    var Bigger = Sorted.Where(x => x > current);
                    while(theRest > 0 && Bigger.Count() > 0 && end != true)
                    {
                        int next = Bigger.OrderBy(x => x).First();
                        int nextCount = Bigger.Count(x => x == next);
                        if((theRest/currentCount) < ((next - current)/(double)Sum)*100)
                        {
                            _result += (currentAdd + (theRest / currentCount)).ToString("0.000000") + " ";
                            end = true;
                            break;
                        }
                        else
                        {
                            currentAdd += ((next - current)/(double) Sum)*100;
                            theRest -= currentCount*((next - current)/(double) Sum)*100;
                            current = next;
                            currentCount = Sorted.Where(x => x <= current).Count();
                            Bigger = Sorted.Where(x => x > current);
                        }
                    }
                    
                    if(end == false)
                        _result += (currentAdd + theRest / Sorted.Count).ToString("0.000000") + " ";
                }
                //TODO: store result as string
                
            }

            public void Parse(StreamReader sr)
            {
                Elements = new List<int>();
                string test = sr.ReadLine();
                var split = test.Split(new char[] {' '});
                Count = Int32.Parse(split[0]);
                for (int i = 1; i <= Count; i++)
                {
                       Elements.Add(Int32.Parse(split[i]));
                }
                Sorted = Elements.OrderBy(x => x).ToList();
                Sum = Elements.Sum(x => x);
            }

            #region Hidden

            private string _result;

            public new String ToString()
            {
                return String.Format("Case #{0}: {1}", TestCaseNumber, _result.Trim().Replace(',', '.'));
            }

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
                    sw.WriteLine(testCase.ToString());
                }
            }
        }

        #endregion
    }
}
