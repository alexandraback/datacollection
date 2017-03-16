using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int numTestCases = 0;

            StreamReader r = new StreamReader(@"../../files/A-large.in");
            StreamWriter w = new StreamWriter(@"../../files/A-large.out");

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
                    int A = 0;
                    int N = 0;
                    List<int> s = new List<int>();

                    string[] inputNumbers = line.Split(new Char[] { ' ' });
                    int len = inputNumbers.Length;

                    int.TryParse(inputNumbers[0], out A);
                    int.TryParse(inputNumbers[1], out N);

                    line = r.ReadLine();
                    string[] moteStrings = line.Split(new Char[] { ' ' });

                    len = moteStrings.Length;
                    List<int> motes = new List<int>();
                    for (int i = 0; i < len; ++i)
                    {
                        int temp = 0;
                        int.TryParse(moteStrings[i], out temp);
                        motes.Add(temp);
                    }
                    motes.Sort();

                    int current = A;
                    if (current == 1)
                    {
                        Console.WriteLine("Case #{0}: {1}", index, len);
                        w.WriteLine("Case #{0}: {1}", index, len);
                        index++;
                        continue;
                    }

                    int addedCount = 0;
                    List<int> addingCounts = new List<int>(len);
                    for (int i = 0; i < len; ++i )
                    {
                        int mote = motes[i];

                        if (mote >= current)
                        {
                            int addedCountTemp = 0;
                            while (current <= mote)
                            {
                                int adding = current - 1;
                                current += adding;
                                addedCountTemp++;
                            }

                            addingCounts.Add(addedCountTemp);
                            if ((addedCountTemp > (len - i)) || (addedCount + addedCountTemp > len))
                            {
                                for (int j = 0; j < len - i - 1; ++j)
                                {
                                    addingCounts.Add(0);
                                }
                                break;
                            }
                            else
                            {
                                current += mote;
                            }
                        }
                        else
                        {
                            addingCounts.Add(0);
                            current += mote;
                        }
                    }

                    int operationCount = 0;
                    for (int i = 0; i < len; ++i )
                    {
                        if (addingCounts[i] == 0)
                        {
                            continue;
                        }

                        int addingCountSum = 0;
                        bool deleted = false;
                        for (int j = i; j < len; ++j )
                        {
                            addingCountSum += addingCounts[j];
                            if (addingCountSum > len-i)
                            {
                                operationCount += len-i;
                                deleted = true;
                                break;
                            }
                        }

                        if (deleted)
                        {
                            break;
                        }
                        else
                        {
                            operationCount += addingCounts[i];
                        }
                    }

                    Console.WriteLine("Case #{0}: {1}", index, operationCount);
                    w.WriteLine("Case #{0}: {1}", index, operationCount);

                    ++index;
                }
            }

            r.Close();
            w.Close();

        }
    }
}

