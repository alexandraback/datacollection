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
            int r = inp[0]; // 1
            int c = inp[1];
            int w = inp[2];
            int res = 0;
            res += (c / w)*r;
            if(w == 1)
                return res;
            res += c % w == 0 ? 1 : 2;
            res += w - 2;
            return res;
        }

        public struct Settings
        {
            public const bool DEBUG = false;
            public const bool EXAMPLE = false;
            public const bool SMALL = false;
            public const char PROBLEM_LETTER = 'A';
            public const int ATTEMPT_NUMBER = 0;
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