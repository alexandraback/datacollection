using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemC
{
    class Program
    {
        private static readonly StreamWriter StreamWriter =
            new StreamWriter(@"C:\codejam\2014-round1C\in-out\C-small-attempt4.out");

        private const string InputFile = @"C:\codejam\2014-round1C\in-out\C-small-attempt4.in";

        private static void Main()
        {
            string[] input = File.ReadAllLines(InputFile);

            int line = 0;
            int t = int.Parse(input[line++]);

            for (int i = 0; i < t; i++)
            {
                string[] values = input[line++].Split(' ');

                int n, m, k;
                n = int.Parse(values[0]);
                m = int.Parse(values[1]);
                k = int.Parse(values[2]);

                int min = k;

                if(n >= 3 && m >= 3)
                {
                    if (n * m == k)
                    {
                        min = n * 2 + m * 2 - 4;
                    }
                    else
                    {


                        int x, y;
                        x = 1;
                        y = 1;

                        if (x*y + 2*x + 2*y == k)
                        {
                            min = 2*x + 2*y;
                        }

                        while (x*y + 2*x + 2*y < k)
                        {
                            int ize = 0;
                            if (x < n)
                            {
                                x++;
                                if (x*y + 2*x + 2*y > k)
                                {
                                    x--;
                                    ize++;
                                }
                            }

                            if (y < m)
                            {
                                y++;
                                if (x*y + 2*x + 2*y > k)
                                {
                                    y--;
                                    ize++;
                                }
                            }

                            if (x*y + 2*x + 2*y == k)
                            {
                                min = 2*x + 2*y;
                                break;
                            }

                            if (ize == 2)
                            {
                                if (x < y && x < n)
                                {
                                    if (2*(x + 1) + 2*y < 2*x + 2*y + (k - (x*y + 2*x + 2*y)))
                                    {
                                        x++;
                                        min = 2*x + 2*y;
                                        break;
                                    }
                                    else
                                    {
                                        min = 2*x + 2*y + (k - (x*y + 2*x + 2*y));
                                        break;
                                    }
                                }
                                if (y <= x && y < m)
                                {
                                    if (2*x + 2*(y + 1) < 2*x + 2*y + (k - (x*y + 2*x + 2*y)))
                                    {
                                        y++;
                                        min = 2*x + 2*y;
                                        break;
                                    }
                                    else
                                    {
                                        min = 2*x + 2*y + (k - (x*y + 2*x + 2*y));
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                StreamWriter.Write("Case #{0}: {1}", i + 1, min);


                StreamWriter.WriteLine();
            }
            StreamWriter.Close();
        }
    }
}
