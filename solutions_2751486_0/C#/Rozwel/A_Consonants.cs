using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;
using System.Text.RegularExpressions;

namespace Rozwel.CodeJam._2013_R1C
{
    class A_Consonants: ProblemBase
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

            protected override void Solve(CancellationToken token)
            {
                string[] Values = Line.Split();
                string Name = Values[0].ToLower();
                int ConsLength = int.Parse(Values[1]);
                string RegMatch = @"[^aeiou]{" + ConsLength.ToString() + "}";

                int SearchEnd;
                int SearchLength;
                string SearchValue;
                
                int MatchCount = 0;
                for (int I = Name.Length; I >= ConsLength; I--)
                {
                    SearchValue = Name.Substring(0, I);
                    if (Regex.IsMatch(SearchValue, RegMatch))
                    {
                        MatchCount++;
                        SearchEnd = I - ConsLength;
                        for (int J = 1; J <= SearchEnd; J++)
                        {
                            SearchLength = I - J;
                            SearchValue = Name.Substring(J, SearchLength);
                            if (Regex.IsMatch(SearchValue, RegMatch))
                            {
                                MatchCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                Result = MatchCount.ToString();
            }
        }
    }
}
