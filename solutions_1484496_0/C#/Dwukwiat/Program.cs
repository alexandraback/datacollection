using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam.Round1B.C
{
    class Program
    {
        class TestCase
        {
            public List<int> Elements { get; set; }
            public int Count { get; set; }
            public Dictionary<int, List<int>> AllSubstrings { get; set; }

            private string _first;
            private string _second;
            private bool impossible = false;

            public void Solve()
            {
                AllSubstrings = new Dictionary<int, List<int>>();
                for (int i = 1; i < 524288; i++)
                {
                    List<int> res = new List<int>();
                    var temp = Convert.ToString(i, 2).ToCharArray().Reverse().ToArray();
                    char[] bits = new char[20];
                    for (int j = temp.Length; j > 0; j--)
                    {
                        bits[j - 1] = temp[j - 1];
                    }

                    for (int j = 0; j < 20; j++)
                    {
                        if(bits[j] == '1')
                        {
                            res.Add(Elements.ElementAt(j));
                        }
                    }
                    int sum = res.Sum(x => x);
                    if(AllSubstrings.ContainsKey(sum) == false)
                        AllSubstrings[sum] = res;
                    else
                    {
                        var first = AllSubstrings[sum];
                        var second = res;
                        var str = "";
                        for (int j = 0; j < first.Count; j++)
                        {
                            str += first[j] + " ";
                        }
                        _first = str.Trim();
                        str = "";
                        for (int j = 0; j < second.Count; j++)
                        {
                            str += second[j] + " ";
                        }
                        _second = str.Trim();
                        return;
                    }
                }
                //TODO: store result as string
                //_result = "Impossible";
                impossible = true;
            }

            public void Parse(StreamReader sr)
            {
                Elements = new List<int>();
                string test = sr.ReadLine();
                var split = test.Split(new char[] { ' ' });
                Count = Int32.Parse(split[0]);
                for (int i = 1; i <= Count; i++)
                {
                    Elements.Add(Int32.Parse(split[i]));
                }
                Elements = Elements.OrderBy(x => x).ToList();
            }

            #region Hidden

            private string _result;

            public new String ToString()
            {
                return String.Format("Case #{0}:\n{1}", TestCaseNumber, _result.Trim());
            }

            public TestCase(int testCaseNumber)
            {
                TestCaseNumber = testCaseNumber;
            }

            public int TestCaseNumber { get; private set; }

            #endregion

            internal void Output(StreamWriter sw)
            {
                sw.WriteLine("Case #" + TestCaseNumber + ":");
                if(impossible == true)
                    sw.WriteLine("Impossible");
                else
                {
                    sw.WriteLine(_first);
                    sw.WriteLine(_second);
                }
            }
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
                    //sw.WriteLine(testCase.ToString());
                }
            }
        }

        #endregion
    }
}
