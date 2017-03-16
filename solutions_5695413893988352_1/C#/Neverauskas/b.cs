using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "B-large";

        private static void Main()
        {
            Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
            Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
            var t = cin.NextInt();
            for (var c = 1; c <= t; c++)
            {
                Console.Write("Case #{0}: ", c);
                Solve();
            }
        }

        private static void Solve()
        {

            var ci = cin.NextString().ToCharArray();
            var ji = cin.NextString().ToCharArray();
            var f = 0L;
            var s = 0L;
            var ccs = string.Empty;
            var jjs = string.Empty;
            {
                var c = ci.ToArray();
                var j = ji.ToArray();

                var first = 0L;
                var second = 0L;
                for (var i = 0; i < c.Length; i++)
                {
                    if (c[i] == '?' || j[i] == '?')
                    {
                        if (c[i] == '?' && j[i] == '?')
                        {

                            if (first == second)
                            {
                                c[i] = '0';
                                j[i] = '0';
                            }
                            else if (first < second)
                            {
                                c[i] = '9';
                                j[i] = '0';
                            }
                            else
                            {
                                c[i] = '0';
                                j[i] = '9';
                            }
                        }
                        else if (c[i] == '?')
                        {
                            if (first == second)
                            {
                                c[i] = j[i];
                            }
                            else if (first < second)
                            {
                                c[i] = '9';
                            }
                            else
                            {
                                c[i] = '0';
                            }
                        }
                        else
                        {
                            if (first == second)
                            {
                                j[i] = c[i];
                            }
                            else if (first < second)
                            {
                                j[i] = '0';
                            }
                            else
                            {
                                j[i] = '9';
                            }
                        }
                    }
                    first *= 10;
                    first += c[i] - '0';
                    second *= 10;
                    second += j[i] - '0';
                }

                var cs = new string(c);
                var js = new string(j);

                ccs = cs;
                jjs = js;

                f = long.Parse(cs);
                s = long.Parse(js);
            }
            {
                var c = ci.ToArray();
                var j = ji.ToArray();
                var first = 0L;
                var second = 0L;
                for (var i = 0; i < c.Length; i++)
                {
                    if (c[i] == '?' || j[i] == '?')
                    {
                        if (c[i] == '?' && j[i] == '?')
                        {
                            var digits = new[] { '0', '1', '9' };
                            var diff = long.MaxValue;
                            var mm = 0;
                            var nn = 0;
                            for (var m = 0; m < digits.Length; m++)
                            {
                                for (var n = 0; n < digits.Length; n++)
                                {
                                    c[i] = digits[m];
                                    j[i] = digits[n];

                                    var d2 = new[] { '0', '1', '9' };

                                    for (var g = 0; g < d2.Length; g++)
                                    {
                                        for (var h = 0; h < d2.Length; h++)
                                        {
                                            var cc = c.ToArray();
                                            for (var o = 0; o < cc.Length; o++)
                                            {
                                                if (cc[o] == '?')
                                                {
                                                    cc[o] = d2[g];
                                                }
                                            }
                                            var jj = j.ToArray();
                                            for (var o = 0; o < jj.Length; o++)
                                            {
                                                if (jj[o] == '?')
                                                {
                                                    jj[o] = d2[h];
                                                }
                                            }
                                            var strc = new string(cc);
                                            var strj = new string(jj);
                                            var valc = long.Parse(strc);
                                            var valj = long.Parse(strj);
                                            var d = Math.Abs(valc - valj);
                                            if (d < diff)
                                            {
                                                diff = d;
                                                mm = m;
                                                nn = n;
                                            }
                                        }
                                    }


                                }
                            }
                            c[i] = digits[mm];
                            j[i] = digits[nn];

                            //if (first == second)
                            //{
                            //    c[i] = '0';
                            //    j[i] = '0';
                            //}
                            //else if (first < second)
                            //{
                            //    c[i] = '9';
                            //    j[i] = '0';
                            //}
                            //else
                            //{
                            //    c[i] = '0';
                            //    j[i] = '9';
                            //}
                        }
                        else if (c[i] == '?')
                        {
                            var dig = j[i] - '0';
                            var plus = dig + 1;
                            if (plus == 10)
                            {
                                plus = 0;
                            }
                            var minus = dig - 1;
                            if (minus == -1)
                            {
                                minus = 9;
                            }
                            plus += '0';
                            minus += '0';

                            var digits = new[] { '0', '9', j[i], (char)plus, (char)minus }.OrderBy(x => x).ToArray();
                            var diff = long.MaxValue;
                            var mm = 0;
                            var nn = 0;
                            for (var m = 0; m < digits.Length; m++)
                            {
                                for (var n = 0; n < digits.Length; n++)
                                {
                                    c[i] = digits[m];
                                    //j[i] = digits[n];

                                    var d2 = new[] { '0', '1', '9' };

                                    for (var g = 0; g < d2.Length; g++)
                                    {
                                        for (var h = 0; h < d2.Length; h++)
                                        {
                                            var cc = c.ToArray();
                                            for (var o = 0; o < cc.Length; o++)
                                            {
                                                if (cc[o] == '?')
                                                {
                                                    cc[o] = d2[g];
                                                }
                                            }
                                            var jj = j.ToArray();
                                            for (var o = 0; o < jj.Length; o++)
                                            {
                                                if (jj[o] == '?')
                                                {
                                                    jj[o] = d2[h];
                                                }
                                            }
                                            var strc = new string(cc);
                                            var strj = new string(jj);
                                            var valc = long.Parse(strc);
                                            var valj = long.Parse(strj);
                                            var d = Math.Abs(valc - valj);
                                            if (d < diff)
                                            {
                                                diff = d;
                                                mm = m;
                                                nn = n;
                                            }
                                        }
                                    }


                                }
                            }
                            c[i] = digits[mm];
                            //j[i] = digits[nn];

                            //if (first == second)
                            //{
                            //    c[i] = j[i];
                            //}
                            //else if (first < second)
                            //{
                            //    c[i] = '9';
                            //}
                            //else
                            //{
                            //    c[i] = '0';
                            //}
                        }
                        else
                        {
                            var dig = c[i] - '0';
                            var plus = dig + 1;
                            if (plus == 10)
                            {
                                plus = 0;
                            }
                            var minus = dig - 1;
                            if (minus == -1)
                            {
                                minus = 9;
                            }
                            plus += '0';
                            minus += '0';

                            var digits = new[] { '0', '9', c[i], (char)plus, (char)minus }.OrderBy(x => x).ToArray();
                            var diff = long.MaxValue;
                            var mm = 0;
                            var nn = 0;
                            for (var m = 0; m < digits.Length; m++)
                            {
                                for (var n = 0; n < digits.Length; n++)
                                {
                                    //c[i] = digits[m];
                                    j[i] = digits[n];

                                    var d2 = new[] { '0', '1', '9' };

                                    for (var g = 0; g < d2.Length; g++)
                                    {
                                        for (var h = 0; h < d2.Length; h++)
                                        {
                                            var cc = c.ToArray();
                                            for (var o = 0; o < cc.Length; o++)
                                            {
                                                if (cc[o] == '?')
                                                {
                                                    cc[o] = d2[g];
                                                }
                                            }
                                            var jj = j.ToArray();
                                            for (var o = 0; o < jj.Length; o++)
                                            {
                                                if (jj[o] == '?')
                                                {
                                                    jj[o] = d2[h];
                                                }
                                            }
                                            var strc = new string(cc);
                                            var strj = new string(jj);
                                            var valc = long.Parse(strc);
                                            var valj = long.Parse(strj);
                                            var d = Math.Abs(valc - valj);
                                            if (d < diff)
                                            {
                                                diff = d;
                                                mm = m;
                                                nn = n;
                                            }
                                        }
                                    }


                                }
                            }
                            //c[i] = digits[mm];
                            j[i] = digits[nn];

                            //if (first == second)
                            //{
                            //    j[i] = c[i];
                            //}
                            //else if (first < second)
                            //{
                            //    j[i] = '0';
                            //}
                            //else
                            //{
                            //    j[i] = '9';
                            //}
                        }
                    }
                    first *= 10;
                    first += c[i] - '0';
                    second *= 10;
                    second += j[i] - '0';
                }

                var cs = new string(c);
                var js = new string(j);

                var ff = long.Parse(cs);
                var ss = long.Parse(js);

                var d1 = Math.Abs(f - s);
                var d3 = Math.Abs(ff - ss);
                if (d3 <= d1)
                {
                    if (d3 == d1)
                    {
                        if (ff <= f)
                        {
                            if (ff == f)
                            {
                                if (ss < s)
                                {
                                    ccs = cs;
                                    jjs = js;
                                }
                            }
                            else
                            {
                                ccs = cs;
                                jjs = js;
                            }
                        }
                    }
                    else
                    {
                        ccs = cs;
                        jjs = js;
                    }
                }
            }
            Console.Write(ccs);
            Console.Write(" ");
            Console.WriteLine(jjs);
        }
    }

    internal class Scanner
    {
        private string[] s = new string[0];
        private int i;
        private readonly char[] cs = { ' ' };

        public string NextString()
        {
            if (i < s.Length) return s[i++];
            var line = Console.ReadLine() ?? string.Empty;
            if (line == string.Empty)
            {
                return NextString();
            }
            s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 1;
            return s.First();
        }

        public double NextDouble()
        {
            return double.Parse(NextString());
        }

        public int NextInt()
        {
            return int.Parse(NextString());
        }

        public long NextLong()
        {
            return long.Parse(NextString());
        }
    }
}