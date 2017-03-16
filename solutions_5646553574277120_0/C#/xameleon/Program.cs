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
            string fileName = "C-small-attempt2.in";
            //string fileName = "C-large.in";
            Console.SetIn(new System.IO.StreamReader(fileName));
            Console.SetOut(new System.IO.StreamWriter("out"));
            //Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            //Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                var c = NextInt();
                var dc = NextInt();
                var v = NextInt();
                var d = ReadInts();
                int res = 0;
                var m = new bool[v + 1];
                bool[] m1;
                foreach (var i in d)
                {
                    if (i < m.Length)
                    {
                        m[i] = true;
                        m1 = (bool[])m.Clone();
                        for (int j = 1; j <= v; j++)
                        {
                            if (i != j && m[j] && (i + j) <= v)
                            {
                                m1[i + j] = true;
                            }
                        }
                        m = m1;
                    }
                }
                for (int i = 1; i <= v; i++)
                {
                    if (!m[i])
                    {
                        m[i] = true;
                        res++;
                        m1 = (bool[])m.Clone();
                        for (int j = 1; j <= v; j++)
                        {
                            if (m[j] && j != i)
                            {
                                if (j + i < m.Length)
                                {
                                    m1[i + j] = true;
                                }
                            }
                        }
                        m = m1;
                    }
                    else
                    {
                        //var m1 = (bool[])m.Clone();
                        //for (int j = i + 1; j <= v; j++)
                        //{
                        //    if (m[j])
                        //    {
                        //        if (j + i < m.Length)
                        //        {
                        //            m1[i + j] = true;
                        //        }
                        //    }
                        //}
                        //m = m1;
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
