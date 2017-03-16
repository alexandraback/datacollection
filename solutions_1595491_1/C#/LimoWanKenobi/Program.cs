using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {

        public static int SolveB(string line)
        {
            int Ng, S, p;

            string[] parms = line.Split(' ');

            Ng = Int32.Parse(parms[0]);
            S = Int32.Parse(parms[1]);
            p = Int32.Parse(parms[2]);

            if (p == 0)
            {
                return Ng;
            }

            int minScoreNormal = 3 * p - 2;
            int minScoreSpecial = 3 * p - 4;
            int cantNormals = 0;
            int cantSpecials = 0;

            for (int i = 0; i < Ng; i++)
            {
                int score = Int32.Parse(parms[3 + i]);

                if (p > 0 && score == 0)
                {
                    continue;
                }

                if (score >= minScoreNormal)
                {
                    cantNormals++;
                }
                else if (score >= minScoreSpecial)
                {
                    cantSpecials++;
                }
            }

            if (cantSpecials > S)
            {
                cantSpecials = S;
            }

            return cantNormals + cantSpecials;
        }

        public static string SolveC(string line)
        {


            return "";
        }

        public static string SolveD(string line)
        {


            return "";
        }


        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("B-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("B-large.out"))
                {
                    string ll = sr.ReadLine().Trim();

                    int cases = Int32.Parse(ll);

                    for (int kkk = 1; kkk <= cases; kkk++)
                    {
                        string line = sr.ReadLine().Trim();

                        int res = SolveB(line);

                        sw.WriteLine("Case #{0}: {1}", kkk, res);
                        Console.WriteLine("Case #{0}: {1}", kkk, res);
                    }

                }
            }

            Console.ReadLine();
        }
    }
}
