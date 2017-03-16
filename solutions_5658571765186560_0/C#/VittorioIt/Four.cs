using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace CodeJam2015Qualification
{
    class Four
    {
        static void Main(string[] args)
        {
            TextReader text = File.OpenText("../../input.txt");
            TextWriter outtext = File.CreateText("../../output.txt");
            int T = int.Parse(text.ReadLine());
            for (int n_case = 1; n_case <= T; n_case++)
            {
                string line = text.ReadLine();
                string[] integers = line.Split(' ');
                int X = int.Parse(integers[0]);
                int R = int.Parse(integers[1]);
                int C = int.Parse(integers[2]);
                if ( C < R )
                {
                    var x = R;
                    R = C;
                    C = x;
                }
                bool res = false;
                if (X > R && X > C)
                {
                    res = true;
                }
                else if ((R * C) % X != 0)
                {
                    res = true;
                }
                else if (X < R && X < C)
                {
                    res = false;
                }
                else if (X >= 2 * R + 1)
                {
                    res = true;
                }
                else if (X < 2 * R - 1)
                {
                    res = false;
                }
                else if (X == 2 * R - 1)
                {
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < R; j++)
                        {
                            if (!foo(i,j,X,R,C))
                            {
                                res = true;
                                outtext.WriteLine(i + " " + j);
                            }
                        }
                    }
                }
                else if (X == 2 * R)
                {
                    for (int i = 0; i < R + 1; i++)
                    {
                        for (int j = 0; j < R; j++)
                        {
                            if (!foo2(i, j, X,R, C))
                            {
                                res = true;
                            }
                        }
                    }
                }
                if ( res )
                    outtext.WriteLine("Case #"+n_case+": RICHARD");
                else    outtext.WriteLine("Case #" + n_case + ": GABRIEL");
            }
            outtext.Flush();
        }

        private static bool foo2(int i, int j,int X, int R, int C)
        {
            for (int ind = 0; ind <= C - R; ind++)
            {
                if (((R - 1) * j + ind * R) % X == 0)
                    return true;
            }
            return false;
        }

        private static bool foo(int i, int j,int X, int R, int C)
        {
            for (int ind = 0; ind <= C - R; ind++)
            {
                if (((R - 1)*j + ind * R) % X == 0)
                    return true;
            }
            for (int ind = 0; ind <= C - R; ind++)
            {
                if (((R - 1) * i + ind * R) % X == 0)
                    return true;
            }
            return false;
        }
    }
}
