using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.In.ReadLine());
            int R = 0, C = 0, M = 0;
            string[] rawtemp = new string[4];
            string[] resulttemp = new string[1];

            for (int t = 1; t <= T; t++)
            {
                Console.Out.WriteLine("Case #" + t + ":");
                rawtemp = Console.In.ReadLine().Split(' ');
                R = Convert.ToInt32(rawtemp[0]);
                C = Convert.ToInt32(rawtemp[1]);
                M = Convert.ToInt32(rawtemp[2]);

                resulttemp = Solver.solve(R, C, M);
                for (int i = 0; i < resulttemp.Length; i++)
			    {
			        Console.Out.WriteLine(resulttemp[i]);
			    }
            }
        }
    }

    public class Solver
    {
        public static string[] solve(int R, int C, int M)
        {
            int F = R * C - M;
            string[] toReturn = new string[R];
            if (R == 1)
            {
                toReturn = new string[1]{"c"};
                for (int i = 1; i < F; i++)
                {
                    toReturn[0] += ".";
                }
                for (int i = 0; i < M; i++)
                {
                    toReturn[0] += "*";
                }
            }
            else if (C == 1)
            {
                toReturn[0] = "c";
                for (int i = 1; i < F; i++)
                {
                    toReturn[i] += ".";
                }
                for (int i = F; i < R; i++)
                {
                    toReturn[i] += "*";
                }
            }
            else if (R == 2) 
            {
                if (F == 1)
                {
                    toReturn = new string[2] { "c", "*" };
                    for (int j = 1; j < C; j++)
                    {
                        toReturn[0] += "*";
                        toReturn[1] += "*";
                    }
                }
                else if ((M & 1) == 1||F==2) 
                    toReturn = new string[1] { "Impossible" };
                else
                {
                    toReturn = new string[2] { "c", "." };
                    for (int j = 1; j < C-M/2; j++)
                    {
                        toReturn[0] += ".";
                        toReturn[1] += ".";
                    }
                    for (int j = 0; j < M/2; j++)
                    {
                        toReturn[0] += "*";
                        toReturn[1] += "*";
                    }
                }
            }
            else if (C == 2)
            {
                if (F == 1)
                {
                    toReturn[0] = "c";
                    for (int i = 1; i < R; i++)
                    {
                        toReturn[i] = "*";
                    }
                    for (int j = 1; j < C; j++)
                    {
                        for (int i = 0; i < R; i++)
                        {
                            toReturn[i] += "*";
                        }
                    }
                }
                else if (((M & 1) == 1) || F == 2) toReturn = new string[1] { "Impossible" };
                else
                {
                    toReturn[0] = "c.";
                    for (int i = 1; i < R - M / 2; i++)
                    {
                        toReturn[i] = "..";
                    }
                    for (int i = R - M / 2; i < R; i++)
                    {
                        toReturn[i] = "**";
                    }
                }
            }
            else if (F == 1)
                {
                    toReturn[0]="c";
                    for (int i = 1; i < R; i++)
                    {
                        toReturn[i] = "*";
                    }
                    for (int j = 1; j < C; j++)
                    {
                        for (int i = 0; i < R; i++)
                        {
                            toReturn[i] += "*";
                        }
                    }
            }
            else if (F == 2 || F == 3 || F == 5 || F == 7)
            {
                toReturn = new string[1] { "Impossible" };
            }
            else
            {
                if ((F & 1) == 0)
                {
                    toReturn[0] = "c.";
                    toReturn[1] = "..";
                    int index = 4;
                    for (int i = 2; i < R; i++)
                    {
                        if (index < F)
                        {
                            toReturn[i] = "..";
                            index = index + 2;
                        }
                        else toReturn[i] = "**";
                    }
                    for (int j = 2; j < C; j++)
                    {
                        for (int i = 0; i < R - 1; i++)
                        {
                            if (index < F)
                            {
                                toReturn[i] += ".";
                                index++;
                            }
                            else toReturn[i] += "*";
                        }
                        if ((index != F - 2) && (index < F))
                        {
                            toReturn[R - 1] += ".";
                            index++;
                        }
                        else toReturn[R - 1] += "*";
                    }
                }
                else
                {
                    toReturn[0] = "c..";
                    toReturn[1] = "...";
                    toReturn[2] = "...";
                    int index = 9;
                    for (int i = 3; i < R; i++)
                    {
                        if (index < F)
                        {
                            toReturn[i] = "..";
                            index = index + 2;
                        }
                        else toReturn[i] = "**";
                    }
                    for (int i = 3; i < R - 1; i++)
                    {
                        if (index < F)
                        {
                            toReturn[i] += ".";
                            index = index + 1;
                        }
                        else toReturn[i] += "*";
                    }
                    if (R > 3)
                    {
                        if ((index != F - 2) && (index < F))
                        {
                            toReturn[R - 1] += ".";
                            index = index + 1;
                        }
                        else toReturn[R - 1] += "*";
                    }
                    for (int j = 3; j < C; j++)
                    {
                        for (int i = 0; i < R - 1; i++)
                        {
                            if (index < F)
                            {
                                toReturn[i] += ".";
                                index = index + 1;
                            }
                            else toReturn[i] += "*";
                        }
                        if ((index != F - 2) && (index < F))
                        {
                            toReturn[R - 1] += ".";
                            index = index + 1;
                        }
                        else toReturn[R - 1] += "*";
                    }
                }
            }
            return toReturn;
        }
    }
}
