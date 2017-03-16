using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;

namespace CodeJam
{
    class Program
    {
        static int n;
        static bool[] used;
        static int[] bff;
        static List<int>[] bbff;
        static bool[] bestres;

        static Tuple<int, int> GoForward(int last, int prev)
        {
            used[last] = true;
            var lastbf = bff[last];
            if (!used[lastbf])
            {
                used[lastbf] = true;
                return GoForward(lastbf, last);
            }
            else
            {
                return new Tuple<int, int>(last, prev);
            }
        }

        static bool[] GoBackward(int cur, bool[] u)
        {
            var tmp = (bool[])u.Clone();
            var res = (bool[])u.Clone();
            var cnt = res.Count(x => x);
            foreach (var item in bbff[cur])
            {
                if (!u[item])
                {
                    tmp[item] = true;
                    var nextres = GoBackward(item, tmp);
                    var cnt2 = nextres.Count(x => x);
                    if (cnt2 > cnt)
                    {
                        res = nextres;
                        cnt = cnt2;
                    }
                    tmp[item] = false;
                }
            }
            return res;
        }

        static void Main(string[] args)
        {
            //string fileName = "in";
            //string fileName = "C-small-attempt0.in";
            //string fileName = "C-small-attempt1.in";
            //string fileName = "C-small-attempt2.in";
            string fileName = "C-small-attempt3.in";
            //string fileName = "C-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                n = NextInt();
                used = new bool[n];
                bff = new int[n];
                bbff = new List<int>[n];
                var circle = new bool[n];
                var len = new int[n];
                var lasts = new int[n];
                var prevs = new int[n];
                for (int i = 0; i < n; i++)
                {
                    bbff[i] = new List<int>();
                }
                var row = ReadInts();
                for (int i = 0; i < n; i++)
                {
                    bff[i] = row[i] - 1;
                    bbff[row[i] - 1].Add(i);
                }
                int res = 0;

                for (int i = 0; i < n; i++)
                {
                    used = new bool[n];
                    var tp = GoForward(i, -1);
                    var last = tp.Item1;
                    var prev = tp.Item2;
                    if (bff[last] == i)
                    {
                        len[i] = used.Count(x => x);
                        circle[i] = true;
                        lasts[i] = last;
                        prevs[i] = prev;
                        if (len[i] > res)
                        {
                            res = len[i];
                        }
                    }
                    else
                    {
                        lasts[i] = last;
                        prevs[i] = prev;
                        len[i] = used.Count(x => x);
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (!circle[i])
                    {
                        
                        var firstbest = 0;
                        var lastbest = 0;
                        bool close = bff[lasts[i]] == prevs[i];
                        for (int j = 0; j < n; j++)
                        {
                            if (i != j)
                            {
                                if (lasts[j] == prevs[i] && prevs[j] == lasts[i] && len[j] > lastbest)
                                {
                                    close = true;
                                    lastbest = len[j];
                                }
                                if (lasts[j] == i && len[j] > firstbest)
                                {
                                    firstbest = len[j];
                                }
                            }
                        }
                        if (close)
                        {
                            var cr = len[i] + (firstbest > 0 ? firstbest - 1 : 0) + (lastbest > 0 ? lastbest - 2 : 0);
                            if (cr > res)
                            {
                                res = cr;
                            }
                        }
                        
                    }
                }

                Console.WriteLine("Case #{0}: {1}", testCase, res);
            }

            //Console.WriteLine(string.Format(NumberFormatInfo.InvariantInfo, "{0:F4}", res));

            Console.In.Close();
            Console.Out.Close();
        }

        private static char[] _defaultSplitter = new char[] { ' ', '\t' };

        private static void SetCulture()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        }

        private static char[] ReadChars(int n)
        {
            char[] buffer = new char[n];
            Console.In.ReadBlock(buffer, 0, n);
            return buffer;
        }

        private static string[] ReadAll()
        {
            return Console.In.ReadToEnd().Split(new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords()
        {
            return ReadWords(_defaultSplitter);
        }

        private static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        private static int[] ReadInts(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToArray();
        }

        private static int[] ReadInts()
        {
            return ReadInts(_defaultSplitter);
        }

        private static long ReadLong()
        {
            return long.Parse(Console.ReadLine());
        }

        private static double ReadDouble()
        {
            return double.Parse(Console.ReadLine(), NumberFormatInfo.InvariantInfo);
        }

        private static int _pos = 0;
        private static string[] _inputLine = new string[0];

        private static void CheckInputLine()
        {
            if (_pos >= _inputLine.Length)
            {
                _inputLine = ReadWords();
                _pos = 0;
            }
        }

        private static string NextWord()
        {
            CheckInputLine();
            return _inputLine[_pos++];
        }

        private static int NextInt()
        {
            CheckInputLine();
            return int.Parse(_inputLine[_pos++]);
        }

        private static long NextLong()
        {
            CheckInputLine();
            return long.Parse(_inputLine[_pos++]);
        }
    }
}
