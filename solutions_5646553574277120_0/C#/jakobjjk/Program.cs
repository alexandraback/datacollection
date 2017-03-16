using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace GCJ
{
    class Program
    {
        public static object SolveCase(Func<string> rl)
        {
            var inp = rl().Split(' ').Select(x => int.Parse(x)).ToArray();
            int c = inp[0]; // 1
            int d = inp[1];
            int v = inp[2];
            bool[] w = new bool[v + 1];
            w[0] = true;
            for(int i=1; i < w.Length; i++)
                w[i] = false;
            HashSet<int> ds = new HashSet<int>(rl().Split(' ').Select(x => int.Parse(x)));
            List<List<int>> p = PowerSet(ds.ToList()).ToList();
            for(int i=0; i < p.Count; i++)
            {
                int sum = p[i].Sum();
                if(sum<=v)
                    w[p[i].Sum()] = true;
            }
            int lastIndex = 0;
            List<int> differences = new List<int>();
            List<List<int>> possible = new List<List<int>>();
            for(int i=1; i < w.Count(); i++)
            {
                if(w[i])
                {
                    lastIndex = i;
                }
                else
                {
                    for(int j=1; j<=i; j++)
                    {
                        if(w[i-j] && !ds.Contains(j))
                        {
                            ds.Add(j);
                            p = PowerSet(ds.ToList()).ToList();
                            for(int a=0; a < p.Count; a++)
                            {
                                int sum = p[a].Sum();
                                if(sum <= v)
                                    w[p[a].Sum()] = true;
                            }
                            break;
                        }
                    }
                }
            }

            return ds.Count - d;
        }

        private static IEnumerable<List<int>> PowerSet(List<int> elements)
        {
            for(int i = 1; i < (1 << elements.Count); i++)
            {
                yield return GenerateSet(i).Select(n => elements[n]).ToList();
            }
        }
        private static IEnumerable<int> GenerateSet(int i)
        {
            int n = 0;
            for(; i != 0; i /= 2)
            {
                if((i & 1) != 0)
                {
                    yield return n;
                }
                n++;
            }
        }

        public struct Settings
        {
            public const bool DEBUG = false;
            public const bool EXAMPLE = false;
            public const bool SMALL = true;
            public const char PROBLEM_LETTER = 'C';
            public const int ATTEMPT_NUMBER = 1;
            public const int NUMBER = 0;
            public const bool PRACTICE = false;
        }

        private static void Debug()
        {
            Console.WriteLine();
            Console.ReadKey();
        }

        private static void Main(string[] args)
        {
            if(Settings.DEBUG)
            {
                Debug();
            }
            else
            {
                Pattern.SolveAll();
            }
            Console.ReadKey();
        }
    }

    static class Pattern
    {
        public static void SolveAll()
        {
            using(StreamReader sr = new StreamReader(CreateInfPath()))
            using(StreamWriter sw = new StreamWriter(@"C:\Users\Jakob\Desktop\outf.txt"))
            {
                int cases = int.Parse(sr.ReadLine());

                DateTime start;
                Console.Title = "Google Code Jam";

                for(int currentCase = 1; currentCase <= cases; currentCase++)
                {
                    start = DateTime.Now;
                    sw.WriteLine("Case #{0}: {1}", currentCase, Program.SolveCase(sr.ReadLine));
                    Console.WriteLine("Case {0} / {1} : {2}ms", currentCase, cases, (DateTime.Now - start).TotalMilliseconds);
                }
            }
            Console.WriteLine("END!");
            Console.Beep(300, 500);
        }
        private static string CreateInfPath()
        {
            string infPath;
            if(Program.Settings.EXAMPLE)
                infPath = @"C:\Users\Jakob\Desktop\ex.txt";
            else
            {
                infPath = @"C:\Users\Jakob\Downloads\" + Program.Settings.PROBLEM_LETTER.ToString() + "-" + (Program.Settings.SMALL ? "small" : "large");
                if(Program.Settings.PRACTICE)
                    infPath += "-practice";
                if(Program.Settings.NUMBER != 0)
                    infPath += "-" + Program.Settings.NUMBER.ToString();
                else if(!Program.Settings.PRACTICE && Program.Settings.SMALL)
                    infPath += "-attempt" + Program.Settings.ATTEMPT_NUMBER.ToString();
                infPath += ".in";
            }
            return infPath;
        }
    }
}