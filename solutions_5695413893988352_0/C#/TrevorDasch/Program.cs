using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Mono.Math;
using System.Linq;

namespace Round1BProblemB
{
    class MainClass
    {
        public static int TryDoThing2(int diff, ref char[] c, ref char[] j, int i, bool roundUpJ, bool roundUpC, bool roundDownJ, bool roundDownC)
        {
            if (c[i] == '?' && j[i] == '?')
            {
                c[i] = roundUpC ? '1' : '0';
                j[i] = roundUpJ ? '1' : '0';
            }
            else if (c[i] == '?')
            {
                c[i] = (char)((int)j[i] + (roundUpC ? 1 : 0) - (roundDownC ? 1 : 0));
            }
            else if (j[i] == '?')
            {
                j[i] = (char)((int)c[i] + (roundUpJ ? 1 : 0) - (roundDownJ ? 1 : 0));
            }

            diff = c[i].CompareTo(j[i]);

            return TryDoThing(diff, ref c, ref j, i + 1);
        }

        public static int TryDoThing3(int diff, char[] c, char[] j, ref char[] cb, ref char[] jb, int i, int b, bool roundUpJ, bool roundUpC, bool roundDownJ, bool roundDownC)
        {
            char[] ca = (char[])c.Clone();
            char[] ja = (char[])j.Clone();

            // Try Branch
            int a = TryDoThing2(diff, ref ca, ref ja, i, roundUpJ, roundUpC, roundDownJ, roundDownC);

            if (a >= b)
            {

                int cav = int.Parse(new string(ca));
                int cbv = int.Parse(new string(cb));
                int jav = int.Parse(new string(ja));
                int jbv = int.Parse(new string(jb));
                if (a == b && (cav < cbv || (cav == cbv && (jav <= jbv))))
                {
                    cb = ca;
                    jb = ja;
                    return a;
                }
            }
            else
            {
                cb = ca;
                jb = ja;
                return a;
            }
            return b;
        }

        public static int TryDoThing(int diff, ref char[] c, ref char[] j, int s)
        {
            for (int i = s; i < c.Length; i++)
            {
                if (diff == 0)
                {
                    int min = int.MaxValue;
                    char[] cmin = null, jmin = null;
                    if(c[i] == '?')
                    {                        
                        if (j[i] != '9')
                        {
                            min = TryDoThing3(diff, c, j, ref cmin, ref jmin, i, min, false, true, false, false);
                        }
                        if (j[i] != '0' && j[i] != '?')
                        {
                            min = TryDoThing3(diff, c, j, ref cmin, ref jmin, i, min, false, false, false, true);
                        }
                    }
                    if (j[i] == '?')
                    {
                        if (c[i] != '9')
                        {
                            min = TryDoThing3(diff, c, j, ref cmin, ref jmin, i, min, true, false, false, false);
                        }
                        if (c[i] != '0' && c[i] != '?')
                        {
                            min = TryDoThing3(diff, c, j, ref cmin, ref jmin, i, min, false, false, true, false);
                        }
                    }

                    if (c[i] == '?' || j[i] == '?')
                    {
                        min = TryDoThing3(diff, c, j, ref cmin, ref jmin, i, min, false, false, false, false);
                    }

                    if (cmin == null)
                    {
                        diff = c[i].CompareTo(j[i]);
                    }
                    else
                    {
                        c = cmin;
                        j = jmin;
                        return min;
                    }
                }
                else if (diff < 0) // c is losing
                {
                    if (c[i] == '?')
                    {
                        c[i] = '9'; 
                    }
                    if (j[i] == '?')
                    {
                        j[i] = '0';
                    }
                }
                else if (diff > 0)
                {
                    if (c[i] == '?')
                    {
                        c[i] = '0'; 
                    }
                    if (j[i] == '?')
                    {
                        j[i] = '9';
                    }
                }
                else
                {
                    throw new Exception("What");
                }
            }

            return Math.Abs(int.Parse(new string(c)) - int.Parse(new string(j)));
        }

        public static void Solve(StringBuilder sb, string[] lines, ref int index) {

            var split = lines[index].Split();
            index++;

            var c = split[0].ToArray();

            var j = split[1].ToArray();


            int diff = 0;

            TryDoThing(diff, ref c, ref j, 0);

            Console.WriteLine(split[0] + " " + split[1]);
            Console.WriteLine(new string(c) + " " + new string(j));

            sb.AppendLine(new string(c) + " " + new string(j));
        }

        public static void Main(string[] args)
        {
            var ifname = args[0];
            var ofname = args[1];

            var lines = File.ReadAllLines(ifname);

            var lineCount = long.Parse(lines[0]);

            var sb = new StringBuilder();
            int index = 1;
            for (long i = 1; i <= lineCount; i++)
            {
                sb.Append("Case #" + i + ": ");



                Solve(sb, lines, ref index);
            }

            File.WriteAllText(ofname, sb.ToString());
        }
    }
}
