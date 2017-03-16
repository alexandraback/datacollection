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
        class Comb
        {
            public int j;
            public int p;
            public int s;
            public Comb(int j, int p, int s)
            {
                this.j = j;
                this.p = p;
                this.s = s;
            }
        }

        static int res = 0;
        static List<Comb> cmb = null;

        static void PrintComb(List<Comb> lst)
        {
            for (int i = 0; i < lst.Count; i++)
            {
                Console.WriteLine("{0} {1} {2}", lst[i].j, lst[i].p, lst[i].s);
            }
        }

        static void Main(string[] args)
        {
            //string fileName = "in";
            string fileName = "C-small-attempt0.in";
            //string fileName = "C-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                var j = NextInt();
                var p = NextInt();
                var s = NextInt();
                var k = NextInt();
                cmb = new List<Comb>();
                for (int ij = 1; ij <= j; ij++)
                {
                    for (int ip = 1; ip <= p; ip++)
                    {
                        for (int iss = 1; iss <= s; iss++)
                        {
                            cmb.Add(new Comb(ij, ip, iss));
                        }
                    }
                }

                var cmb1 = new List<Comb>();

                for (int ij = 1; ij <= j; ij++)
                {
                    for (int ip = 1; ip <= p; ip++)
                    {
                        for (int iss = 1; iss <= s; iss++)
                        {
                            var cand = new Comb(ij, ip, iss);
                            if (cmb1.Count(x => x.j == cand.j && x.p == cand.p) >= k
                                || cmb1.Count(x => x.j == cand.j && x.s == cand.s) >= k
                                || cmb1.Count(x => x.p == cand.p && x.s == cand.s) >= k)
                            {
                                //
                            }
                            else
                            {
                                cmb1.Add(cand);
                            }
                        }
                    }
                }

                var res1 = cmb1.Count();

                var cmb2 = new List<Comb>();

                for (int ij = 1; ij <= j; ij++)
                {
                    for (int iss = 1; iss <= s; iss++)
                    {
                        for (int ip = 1; ip <= p; ip++)
                        {
                            var cand = new Comb(ij, ip, iss);
                            if (cmb2.Count(x => x.j == cand.j && x.p == cand.p) >= k
                                || cmb2.Count(x => x.j == cand.j && x.s == cand.s) >= k
                                || cmb2.Count(x => x.p == cand.p && x.s == cand.s) >= k)
                            {
                                //
                            }
                            else
                            {
                                cmb2.Add(cand);
                            }
                        }
                    }
                }

                var res2 = cmb2.Count();

                var cmb3 = new List<Comb>();

                for (int ip = 1; ip <= p; ip++)
                {
                    for (int ij = 1; ij <= j; ij++)
                    {
                        for (int iss = 1; iss <= s; iss++)
                        {
                            var cand = new Comb(ij, ip, iss);
                            if (cmb3.Count(x => x.j == cand.j && x.p == cand.p) >= k
                                || cmb3.Count(x => x.j == cand.j && x.s == cand.s) >= k
                                || cmb3.Count(x => x.p == cand.p && x.s == cand.s) >= k)
                            {
                                //
                            }
                            else
                            {
                                cmb3.Add(cand);
                            }
                        }
                    }
                }

                var res3 = cmb3.Count();

                var cmb4 = new List<Comb>();

                for (int ip = 1; ip <= p; ip++)
                {
                    for (int iss = 1; iss <= s; iss++)
                    {
                        for (int ij = 1; ij <= j; ij++)
                        {
                            var cand = new Comb(ij, ip, iss);
                            if (cmb4.Count(x => x.j == cand.j && x.p == cand.p) >= k
                                || cmb4.Count(x => x.j == cand.j && x.s == cand.s) >= k
                                || cmb4.Count(x => x.p == cand.p && x.s == cand.s) >= k)
                            {
                                //
                            }
                            else
                            {
                                cmb4.Add(cand);
                            }
                        }
                    }
                }

                var res4 = cmb4.Count();

                var cmb5 = new List<Comb>();

                for (int iss = 1; iss <= s; iss++)
                {
                    for (int ip = 1; ip <= p; ip++)
                    {
                        for (int ij = 1; ij <= j; ij++)
                        {
                            var cand = new Comb(ij, ip, iss);
                            if (cmb5.Count(x => x.j == cand.j && x.p == cand.p) >= k
                                || cmb5.Count(x => x.j == cand.j && x.s == cand.s) >= k
                                || cmb5.Count(x => x.p == cand.p && x.s == cand.s) >= k)
                            {
                                //
                            }
                            else
                            {
                                cmb5.Add(cand);
                            }
                        }
                    }
                }

                var res5 = cmb5.Count();

                var cmb6 = new List<Comb>();

                for (int iss = 1; iss <= s; iss++)
                {
                    for (int ij = 1; ij <= j; ij++)
                    {
                        for (int ip = 1; ip <= p; ip++)
                        {
                            var cand = new Comb(ij, ip, iss);
                            if (cmb6.Count(x => x.j == cand.j && x.p == cand.p) >= k
                                || cmb6.Count(x => x.j == cand.j && x.s == cand.s) >= k
                                || cmb6.Count(x => x.p == cand.p && x.s == cand.s) >= k)
                            {
                                //
                            }
                            else
                            {
                                cmb6.Add(cand);
                            }
                        }
                    }
                }

                var res6 = cmb6.Count();

                res = (new[] { res1, res2, res3, res4, res5, res6 }).Max();
                
                Console.WriteLine("Case #{0}: {1}", testCase, res);

                if (res1 == res)
                {
                    PrintComb(cmb1);
                }
                else if (res2 == res)
                {
                    PrintComb(cmb2);
                }
                else if (res3 == res)
                {
                    PrintComb(cmb3);
                }
                else if (res4 == res)
                {
                    PrintComb(cmb4);
                }
                else if (res5 == res)
                {
                    PrintComb(cmb5);
                }
                else if (res6 == res)
                {
                    PrintComb(cmb6);
                }
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
