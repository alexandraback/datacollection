using Rozwel.CodeJam.Framework;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rozwel.CodeJam._2014_R1B
{
    public class A_TheRepeater : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            byte N;
            string[] Strings;
            public TestCase(TextReader inputStream)
            {
                N = byte.Parse(inputStream.ReadLine());
                Strings = new string[N];
                for (int i = 0; i < N; i++)
                {
                    Strings[i] = inputStream.ReadLine();
                }
            }
            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();

                char curLetter = ' ';
                int[] IndexPointers = new int[N];
                ZeroIntArray(IndexPointers);
                int[] CharacterCount = new int[N];
                Dictionary<int,int> StringsWithCount = new Dictionary<int,int>();
                bool[] EOL = new bool[N];
                ZeroIntArray(CharacterCount);
                bool EOF = false;
                Result = null;
                int Changes = 0;
                while (!EOF)
                {
                    ZeroIntArray(CharacterCount);
                    StringsWithCount.Clear();
                    int EOLCount = 0;
                    for (int i = 0; i < N; i++)
                    {
                        if (EOL[i])
                        {
                            EOLCount++;
                        }
                        else
                        {
                            if (i == 0)
                            {
                                curLetter = Strings[i][IndexPointers[i]];
                            }
                            while (!EOL[i] && Strings[i][IndexPointers[i]] == curLetter)
                            {
                                CharacterCount[i]++;
                                IndexPointers[i]++;
                                if (IndexPointers[i] >= Strings[i].Length)
                                {
                                    EOL[i] = true;
                                }
                            }
                            if (StringsWithCount.ContainsKey(CharacterCount[i]))
                            {
                                StringsWithCount[CharacterCount[i]]++;
                            }
                            else
                            {
                                StringsWithCount.Add(CharacterCount[i], 1);
                            }
                        }
                    }
                    if (StringsWithCount.ContainsKey(0) || (EOLCount > 0 && EOLCount < N))
                    {
                        Result = "Fegla Won";
                        EOF = true;
                    }
                    else
                    {
                        List<int> CountKeys = new List<int>(StringsWithCount.Keys);
                        CountKeys.Sort();
                        for (int i = 0; i < StringsWithCount.Count; i++)
                        {
                            int n = N - StringsWithCount[CountKeys[i]];
                            if (StringsWithCount[CountKeys[i]] <= n)
                            {//There are more strings with a higher count roll these up
                                int Steps = CountKeys[i + 1] - CountKeys[i];
                                Changes += StringsWithCount[CountKeys[i]] * Steps;
                                StringsWithCount[CountKeys[i + 1]] += StringsWithCount[CountKeys[i]];
                                StringsWithCount[CountKeys[i]] = 0;
                            }
                            else
                            {
                                break;
                            }
                        }
                        for (int i = StringsWithCount.Count - 1; i >= 0; i--)
                        {
                               int n = N - StringsWithCount[CountKeys[i]];
                            if (StringsWithCount[CountKeys[i]] < n)
                            {//There are more strings with a lower count roll these down
                                int Steps = CountKeys[i] - CountKeys[i - 1];
                                Changes += StringsWithCount[CountKeys[i]] * Steps;
                                StringsWithCount[CountKeys[i - 1]] += StringsWithCount[CountKeys[i]];
                                StringsWithCount[CountKeys[i]] = 0;

                            }
                            else
                            {
                                break;
                            }
                         
                        }



                        EOF = EOLCount == N;
                    }
                }
                if (Result == null)
                {
                    Result = Changes.ToString();
                }
                //throw new NotImplementedException();
            }

            private void ZeroIntArray(int[] intArray)
            {
                for (int i = 0; i < intArray.Length; i++)
                {
                    intArray[i] = 0;
                }
            }
        }
    }
}
