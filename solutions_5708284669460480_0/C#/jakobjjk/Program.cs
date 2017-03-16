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
            int k = inp[0];
            int l = inp[1];
            int s = inp[2];
            string keys = rl();
            string target = rl();
            for(int i=0; i < target.Length; i++)
            {
                if(!keys.Contains(target[i]))
                {
                    return "0.0";
                }
            }

            List<string> abc = new List<string>(keys.ToCharArray().Select(x=>x.ToString()));
            for(int i = 0; i < s - 1; i++)
            {
                //Console.WriteLine(i);
                List<string> temp =  new List<string>();
                for(int j=0; j<abc.Count; j++)
                {
                    for(int p=0; p<keys.Length; p++)
                    {
                        temp.Add(abc[j] + keys[p]);
                    }
                }
                abc = new List<string>(temp);
                //for(int p=0; p < abc.Count; p++)
                //    Console.WriteLine(abc[p]);
                //Console.ReadKey();
            }
            int count = 0;
            int max = 0;
            for(int i=0; i < abc.Count; i++)
            {
                int sum = 0;
                for(int j=0; j<abc[i].Length - target.Length + 1; j++)
                {
                    //Console.WriteLine(abc[i]);
                    //Console.WriteLine(abc[i].Substring(j, target.Length) + " " + target);
                    if(abc[i].Substring(j, target.Length) == target)
                    {
                        count++;
                        sum++;
                    }
                }
                max = Math.Max(max, sum);
            }
            return ((double) max - (double) count / abc.Count).ToString("0.0######");
        }

        public struct Settings
        {
            public const bool DEBUG = false;
            public const bool EXAMPLE = false;
            public const bool SMALL = true;
            public const char PROBLEM_LETTER = 'B';
            public const int ATTEMPT_NUMBER = 2;
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