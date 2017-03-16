using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A2
{
    class Program
    {
        static bool isConsonant(char c)
        {
            if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        static void Main(string[] args)
        {
            int numTestCases = 0;

            StreamReader r = new StreamReader(@"../../files/A-small-attempt2.in");
            StreamWriter w = new StreamWriter(@"../../files/A-small-attempt2.out");

            string line;
            bool isFirstLine = true;
            int index = 1;
            while ((line = r.ReadLine()) != null)
            {
                if (isFirstLine)
                {
                    isFirstLine = false;
                    int.TryParse(line, out numTestCases);
                }
                else
                {
                    string name = string.Empty;
                    int n = 0;
                    List<int> s = new List<int>();

                    string[] inputNumbers = line.Split(new Char[] { ' ' });
                    int len = inputNumbers.Length;

                    name = inputNumbers[0];
                    int.TryParse(inputNumbers[1], out n);

                    long nameLen = name.Length;
                    int result = 0;
                    for (int i = 0; i < nameLen; ++i)
                    {
                        for (int j = i; j < nameLen; ++j)
                        {
                            string sub = name.Substring(i, j - i + 1);
                            int sublen = sub.Length;
                            int count = 0;
                            for (int k = 0; k < sublen; ++k)
                            {
                                if (isConsonant(sub[k]))
                                {
                                    count++;
                                    if (count >= n)
                                    {
                                        result++;
                                        break;
                                    }
                                }
                                else
                                {
                                    count = 0;
                                }
                            }
                        }
                    }

                    Console.WriteLine("Case #{0}: {1}", index, result);
                    w.WriteLine("Case #{0}: {1}", index, result);

                    ++index;
                }
            }

            r.Close();
            w.Close();

        }
    }
}