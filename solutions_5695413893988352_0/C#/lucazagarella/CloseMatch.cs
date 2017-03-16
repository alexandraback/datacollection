using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace GoogleCoceJam2016
{
    public class CloseMatch
    {
        public const string ProblemCode = "B";

        public static void Solve(string file)
        {
            using (var sr = new StreamReader(file + ".in"))
            {
                using (var sw = new StreamWriter(file + ".out"))
                {
                    string line = sr.ReadLine();
                    var cases = int.Parse(line);

                    for (int i = 1; i <= cases; i++)
                    {
                        line = sr.ReadLine();
                        var spl = line.Split(' ');
                        var restText = SolveInputSmall(spl[0], spl[1]);
                        Console.WriteLine("Case #{0}: {1}", i, restText);
                        sw.WriteLine("Case #{0}: {1}", i, restText);
                    }

                }
            }

            Console.WriteLine();
            Console.WriteLine("FINITO");
            Console.WriteLine();
            Console.ReadKey();
        }

        public static string SolveInputSmall(string J, string C)
        {
            int len = J.Length;
            var Jlist = new List<int>();
            var Clist = new List<int>();
            for (int i = 0; i < Math.Pow(10, len); i++)
            {
                var xx = i.ToString().PadLeft(len, '0');
                bool valid = true;
                for (int k = 0; k < len; k++)
                {
                    if (xx[k] != J[k] && J[k] != '?')
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    Jlist.Add(i);
                }

                valid = true;
                for (int k = 0; k < len; k++)
                {
                    if (xx[k] != C[k] && C[k] != '?')
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    Clist.Add(i);
                }
            }


            var dcit = new Dictionary<int, int[]>();

            foreach (var Citem in Clist)
            {
                foreach (var Jitem in Jlist)
                {
                    int dif = Math.Abs(Citem - Jitem);
                    if (!dcit.ContainsKey(dif) || (dcit[dif][0] > Jitem || (dcit[dif][0] == Jitem && dcit[dif][1] > Citem)))
                    {
                        dcit[dif] = new[] { Jitem, Citem };
                    }
                }
            }

            return string.Join(" ", dcit.OrderBy(x=>x.Key).First().Value.Select(x=>x.ToString().PadLeft(len,'0')));
        }


        public static string SolveInput(string J, string C)
        {
            int len = J.Length;

            for (int i = 0; i < len; i++)
            {
                if (J[i] != '?' && C[i] != '?')
                {
                    if (J[i] > C[i])
                    {
                        return J.Substring(0, i) + Min(J.Substring(i)) + " " + C.Substring(0, i) + Max(C.Substring(i));
                    }
                    if (J[i] < C[i])
                    {
                        return J.Substring(0, i) + Max(J.Substring(i)) + " " + C.Substring(0, i) + Min(C.Substring(i));
                    }
                }

                var Jmax = Max(J.Substring(i));
                var JJJ = long.Parse(Jmax);
                var JJJ1 = long.Parse("1" + Jmax);

                var jmin = Min(J.Substring(i));
                var jjj = long.Parse(jmin);
                var jjj1 = long.Parse("1" + jmin);

                var Cmax = Max(C.Substring(i));
                var CCC = long.Parse(Cmax);
                var CCC1 = long.Parse("1" + Cmax);

                var Cmin = Min(C.Substring(i));
                var ccc = long.Parse(Cmin);
                var ccc1 = long.Parse("1" + Cmin);



            }
            return "";
        }

        private static string Max(string s)
        {
            return s.Replace('?', '9');
        }

        private static string Min(string s)
        {
            return s.Replace('?', '0');
        }

        public static void SolveLarge()
        {
            Solve(ProblemCode + "-large");
        }

        public static void SolveSample()
        {
            Solve(ProblemCode + "-sample");
        }


        public static void SolveSmall()
        {
            Solve(ProblemCode + "-small");
        }


    }
}
