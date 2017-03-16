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
        static void Main(string[] args)
        {
            //string fileName = "in";
            string fileName = "B-small-attempt0.in";
            //string fileName = "B-large.in";
            Console.SetIn(new System.IO.StreamReader(fileName));
            Console.SetOut(new System.IO.StreamWriter("out"));
            //Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            //Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                var k = NextInt();
                var l = NextInt();
                var s = NextInt();
                var alph = Console.ReadLine();
                var targ = Console.ReadLine();
                var d = new Dictionary<char, int>();
                foreach (var c in alph)
                {
                    if (!d.ContainsKey(c))
                    {
                        d.Add(c, 0);
                    }
                    d[c]++;
                }
                double res = 0;
                //int cnt = 0;
                if (s >= targ.Length && targ.All(x => d.ContainsKey(x)))
                {
                    List<string> all = new List<string>();
                    all.Add("");
                    for (int i = 0; i < s; i++)
                    {
                        var prevLst = all.ToArray();
                        all.Clear();
                        foreach (var item in prevLst)
                        {
                            for (int j = 0; j < k; j++)
                            {
                                all.Add(item + alph[j]);
                            }
                        }
                    }
                    int max = 0;
                    int cnt = 0;
                    foreach (var item in all)
                    {
                        int sc = 0;
                        for (int i = 0; i < s - l + 1; i++)
                        {
                            if (item.Substring(i, l) == targ)
                            {
                                sc++;
                            }
                        }
                        if (sc > max)
                        {
                            max = sc;
                        }
                        cnt += sc;
                    }
                    res = max - (cnt + 0.0) / all.Count;
                    //var str = targ;
                    //cnt = 1;
                    //int pos = 0;
                    //int lastind = targ.Length - 1;
                    //while (str.Length < s)
                    //{
                    //    int i = 1;
                    //    while (i <= targ.Length)
                    //    {
                    //        pos++;
                    //        if (str.Substring(pos) == targ.Substring(0, targ.Length - i))
                    //        {
                    //            str += targ.Substring(targ.Length - i);
                    //            if (str.Length <= s)
                    //            {
                    //                lastind = str.Length - 1;
                    //                cnt++;
                    //            }
                    //            break;
                    //        }
                    //        i++;
                    //    }
                    //}
                    //str = str.Substring(0, lastind + 1);
                    //double x = 1;
                    //foreach (var c in str)
                    //{
                    //    x *= (d[c] + 0.0) / k;
                    //}
                    //res = cnt * (1 - x);
                }
                Console.WriteLine("Case #{0}: {1}", testCase, string.Format(NumberFormatInfo.InvariantInfo, "{0:F8}", res));
            }

            //Console.WriteLine(string.Format(NumberFormatInfo.InvariantInfo, "{0:F8}", res));

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
