using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Threading;
using System.Globalization;

namespace ConsoleApplication1
{
    class Program
    {
        enum State
        {
            None,
            Impossible,
            Exist,
        }
        static long fact(long a)
        {
            if (a <= 1) return 1;
            return a*fact(a-1);
        }

        static long NumWays(string[] trains)
        {
            int[] middles = new int[26];
            int trainCount = 0;

            foreach (string s in trains)
            {
                char[] cString = s.ToCharArray();
                char cStart = cString[0];
                char cEnd = cString[cString.Length - 1];
                // Remove middle characters
                {
                    char lastChar = cStart;
                    bool start = true;
                    bool endCharEncountered = false;
                    foreach (char c in cString)
                    {
                        if (c == cStart && !start)
                        {
                            return 0;
                        }
                        if (endCharEncountered && c != cEnd)
                        {
                            return 0;
                        }
                        if (c != lastChar)
                        {
                            start = false;
                            lastChar = c;
                            if (c != cEnd && c != cStart)
                            {
                                if (middles[c - 'a'] > 0)
                                {
                                    return 0;
                                }
                                else
                                {
                                    ++middles[c - 'a'];
                                }
                            }
                            else if (c == cEnd)
                            {
                                endCharEncountered = true;
                            }
                        }
                    }
                }
            }


            long bothMultiplier = 1;
            // Add to train count trains of a sigle letter which is not used anywhere else
            {
                int[] startOrEnd = new int[26];
                int[] both = new int[26];
                foreach (string s in trains)
                {
                    char[] c = s.ToCharArray();
                    int iS = c[0] - 'a';
                    int iE = c[c.Length - 1] - 'a';
                    if (middles[iS] > 0 || middles[iE] > 0)
                    {
                        return 0;
                    }
                    if (iS == iE)
                    {
                        ++both[iS];
                    }
                    else
                    {
                        ++startOrEnd[iS];
                        ++startOrEnd[iE];
                    }
                }
                for (int i = 0; i < both.Length; ++i)
                {
                    if (both[i] > 0)
                    {
                        bothMultiplier *= fact(both[i]);
                    }
                    if (both[i] > 0 && startOrEnd[i] == 0)
                    {
                        ++trainCount;
                    }
                }
            }

            {
                int[] starts = new int[26];
                int[] ends = new int[26];
                foreach (string s in trains)
                {
                    char[] cString = s.ToCharArray();
                    char cStart = cString[0];
                    char cEnd = cString[cString.Length - 1];
                    int iStart = cStart - 'a';
                    int iEnd = cEnd - 'a';
                    if (cStart != cEnd)
                    {
                        ++trainCount;
                        if (starts[iStart] > 0 || ends[iEnd] > 0 || middles[iStart] > 0 || middles[iEnd] > 0)
                        {
                            return 0;
                        }
                        if (starts[iEnd] > 0)
                        {
                            --trainCount;
                            ++middles[iEnd];
                        }
                        if (ends[iStart] > 0)
                        {
                            --trainCount;
                            ++middles[iStart];
                        }
                        ++starts[iStart];
                        ++ends[iEnd];
                    }
                }
            }

            return fact(trainCount) * bothMultiplier;


        }

        static void Main(string[] args)
        {
            System.IO.StreamReader c = new System.IO.StreamReader("C:\\Users\\Ilod\\Downloads\\B-small-attempt1.in");
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            Scanner s = new Scanner(c.ReadLine());
            int N = s.nextInt();
            for (int iTest = 0; iTest < N; ++iTest)
            {
                s = new Scanner(c.ReadLine());
                int SIZE = s.nextInt();
                s = new Scanner(c.ReadLine());
                string[] trains = new string[SIZE];
                for (int i = 0; i < SIZE; ++i)
                {
                    trains[i] = s.next();
                }
                Debug.WriteLine(string.Format("Case #{0}: {1}", iTest + 1, NumWays(trains)));
            }
        }
    }
}
