using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class Program
    {
        public static void Main()
        {
            int T = ReadInt();
            for (int t = 1; t <= T; t++)
            {
                int[] line = ReadInts();
                int R = line[0];
                int C = line[1];
                int M = line[2];

                Console.WriteLine("Case #{0}:", t);

                // One Row
                if (R == 1)
                {
                    if (C <= M)
                    {
                        Console.WriteLine("Impossible");
                        continue;
                    }

                    string output = "c";
                    for (int i = 0; i < (C - 1 - M); i++)
                        output += ".";
                    for (int i = 0; i < M; i++)
                        output += "*";
                    Console.WriteLine(output);
                    continue;
                }

                // One Col
                if (C == 1)
                {
                    if (R <= M)
                    {
                        Console.WriteLine("Impossible");
                        continue;
                    }

                    Console.WriteLine("c");
                    for (int i = 0; i < (R - 1 - M); i++)
                        Console.WriteLine(".");
                    for (int i = 0; i < M; i++)
                        Console.WriteLine("*");
                    continue;
                }

                // Other
                if ((R * C) - 1 == M)
                {
                    // 1st (C) Line
                    string outputC = "c";
                    for (int i = 0; i < (C - 1); i++)
                        outputC += "*";
                    Console.WriteLine(outputC);

                    // N Line
                    string outputN = "";
                    for (int i = 0; i < C; i++)
                        outputN += "*";
                    for (int j = 0; j < (R - 1); j++)
                        Console.WriteLine(outputN);
                    
                    continue;
                }

                if ((R * C) - 4 < M)    // 2, 3
                {
                    Console.WriteLine("Impossible");
                    continue;
                }

                if ((((R * C) - M) % 2) == 0)
                {
                    // Even
                    int FreePoints = (R * C) - M - 4;

                    string output1 = "c.";
                    string output2 = "..";
                    for (int i = 0; i < (C - 2); i++)
                        if (FreePoints > 0)
                        {
                            output1 += ".";
                            output2 += ".";
                            FreePoints -= 2;
                        }
                        else
                        {
                            output1 += "*";
                            output2 += "*";
                        }
                    Console.WriteLine(output1);
                    Console.WriteLine(output2);

                    // N Line
                    for (int j = 0; j < (R - 2); j++)
                    {
                        string outputN = "";
                        for (int i = 0; i < C; i++)
                            if (FreePoints > 0)
                            {
                                if ((i == (C - 1)) && (FreePoints == 2))
                                {
                                    outputN += "*";
                                } else {
                                    outputN += ".";
                                    FreePoints--;
                                }
                            }
                            else
                                outputN += "*";
                        Console.WriteLine(outputN);
                    }

                    if (FreePoints > 0)
                        Console.WriteLine("Error");
                }
                else
                {
                    // Odd
                    if ((R < 3) || (C < 3) || (((R * C) - M) == 5) || (((R * C) - M) == 7))
                    {
                        Console.WriteLine("Impossible");
                        continue;
                    }

                    int FreePoints = (R * C) - M - 9;

                    string output1 = "c..";
                    string output2 = "...";
                    string output3 = "...";
                    for (int i = 0; i < (C - 3); i++)
                        if (FreePoints > 0)
                        {
                            output1 += ".";
                            output2 += ".";
                            FreePoints -= 2;
                        }
                        else
                        {
                            output1 += "*";
                            output2 += "*";
                        }
                    for (int i = 0; i < (C - 3); i++)
                        if (FreePoints > 0)
                        {
                            if ((i == (C - 4)) && (FreePoints == 2))
                            {
                                output3 += "*";
                            } else {
                                output3 += ".";
                                FreePoints--;
                            }
                        }
                        else
                            output3 += "*";
                    Console.WriteLine(output1);
                    Console.WriteLine(output2);
                    Console.WriteLine(output3);

                    // N Line
                    for (int j = 0; j < (R - 3); j++)
                    {
                        string outputN = "";
                        for (int i = 0; i < C; i++)
                            if (FreePoints > 0)
                            {
                                if ((i == (C - 1)) && (FreePoints == 2))
                                {
                                    outputN += "*";
                                } else {
                                    outputN += ".";
                                    FreePoints--;
                                }
                            }
                            else
                                outputN += "*";
                        Console.WriteLine(outputN);
                    }

                    if (FreePoints > 0)
                        Console.WriteLine("Error");
                }
            }
        }

        #region Library

        static string ReadLine()
        {
            return Console.ReadLine();
        }

        static string[] ReadWords()
        {
            return ReadLine().Split();
        }

        static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        static long ReadLong()
        {
            return Int64.Parse(ReadLine());
        }

        static int[] ReadInts()
        {
            return Array.ConvertAll(ReadWords(), int.Parse);
        }

        static long[] ReadLongs()
        {
            return Array.ConvertAll(ReadWords(), Int64.Parse);
        }

        static double ReadDouble()
        {
            return Double.Parse(ReadLine(), System.Globalization.NumberStyles.AllowExponent | System.Globalization.NumberStyles.Number);
        }

        static double[] ReadDoubles()
        {
            return Array.ConvertAll(ReadWords(), double.Parse);
        }

        #endregion
    }
}
