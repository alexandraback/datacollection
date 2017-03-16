using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_2014_1B_A
{
    class Program
    {
        static object SolveCase(Reader rl)
        {
            long[] info = rl().Split(' ').Select(x => long.Parse(x)).ToArray();
            long a = info[0];
            long b = info[1];
            long k = info[2];

            long counter = Math.Min(k, b) * a + (Math.Max(k, a) - k) * k;
            for (long i = k; i < a; i++)
            {
                for (long j = k; j < b; j++)
                {
                    if ((j & i) < k)
                    {
                        counter++;
                    }
                }
            }
            return counter;
        }

        struct Settings
        {
            public const bool DEBUG = false;
            public const bool EXAMPLE = false;
            public const bool SMALL = false;
            public const char PROBLEM_LETTER = 'B';
            public const int ATTEMPT_NUMBER = 0;
            public const bool PRACTICE = false;
        }

        static void Debug()
        {
            for (int i = 0; i <= 3; i++)
            {
                for (int j = 0; j <= 4; j++)
                {
                    Console.WriteLine("{0} & {1} = {2}; {3}",i,j,(i&j),(i&j) < 2);
                } 
            }

        }

        #region Pattern
        static void Main(string[] args)
        {
            if (Settings.DEBUG)
            {
                Debug();
            }
            else
            {
                SolveAll(CreateInfPath(Settings.EXAMPLE, Settings.SMALL, Settings.PROBLEM_LETTER, Settings.ATTEMPT_NUMBER, Settings.PRACTICE));
            }
            Console.ReadKey();
        }
        delegate string Reader();
        static void SolveAll(string infPath)
        {
            StreamReader inf = new StreamReader(infPath);
            Reader rl = inf.ReadLine;
            StreamWriter outf = new StreamWriter(@"C:\Users\Jakob\Desktop\outf.txt");

            int cases = int.Parse(rl());

            DateTime start;
            Console.Title = "Google Code Jam";

            for (int currentCase = 1; currentCase <= cases; currentCase++)
            {
                start = DateTime.Now;
                outf.WriteLine("Case #{0}: {1}", currentCase, SolveCase(rl));
                Console.WriteLine("Case {0} / {1} : {2}ms", currentCase, cases, (DateTime.Now - start).Milliseconds);
            }

            inf.Close();
            outf.Close();

            Console.WriteLine("END!");
            Console.Beep(300, 500);
        }
        static string CreateInfPath(bool example, bool small, char problemLetter, int attemptNumber, bool practice)
        {
            string infPath;
            if (example)
            {
                infPath = @"C:\Users\Jakob\Desktop\ex.txt";
            }
            else
            {
                infPath = @"C:\Users\Jakob\Downloads\" + problemLetter.ToString() + "-";
                if (small)
                {
                    infPath += "small";
                }
                else
                {
                    infPath += "large";
                }
                if (practice)
                {
                    infPath += "-practice";
                }
                else if (small)
                {
                    infPath += "-attempt" + attemptNumber.ToString();
                }
                infPath += ".in";
            }
            return infPath;
        }
        #endregion
    }
}
