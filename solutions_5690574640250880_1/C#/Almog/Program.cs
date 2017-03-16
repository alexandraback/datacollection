using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace _3_Minesweeper
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fsInput = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(fsInput);
            FileStream fsOutput = new FileStream(args[0] + ".out", FileMode.Create, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fsOutput);


            string sCases = reader.ReadLine();

            int iCases = int.Parse(sCases);

            char[,] board = new char[50,50];

            for (int i = 0; i < iCases; i++)
            {
                string[] line = reader.ReadLine().Split(' ');
                int R = int.Parse(line[0]);
                int C = int.Parse(line[1]);
                int M = int.Parse(line[2]);


                // TODO: transpose
                bool transpose = false;
                if (R < C)
                {
                    int T = R;
                    R = C;
                    C = T;
                    transpose = true;
                }

                // Now C is the smaller.

                int FR1 = 0;
                int FC1 = 0;
                int FR2 = 0;
                int FC2 = 0;
                int FR3 = 0;
                int FC3 = 0;
                bool isOdd = false;

                bool is_pos = FindFreeRect(R, C, M, ref FR1, ref FC1, ref FR2, ref FC2, ref FR3, ref FC3, ref isOdd);

                writer.WriteLine("Case #{0}:", i + 1);
                if (!is_pos)
                {
                    writer.WriteLine("Impossible");
                }
                else
                {
                    reset(board);

                    for (int r = 0; r < FR1; r++)
                    {
                        for (int c = 0; c < FC1; c++)
                        {
                            board[r, c] = '.';
                        }
                    }

                    for (int r = 0; r < FR2; r++)
                    {
                        for (int c = 0; c < FC2; c++)
                        {
                            board[r, FC1 + c] = '.';
                        }
                    }

                    for (int r = 0; r < FR3; r++)
                    {
                        for (int c = 0; c < FC3; c++)
                        {
                            board[r, FC1 + FC2 + c] = '.';
                        }
                    }

                    if (isOdd)
                    {
                        if (FR3 * FC3 == 0)
                        {
                            int x = FC1;
                            while ((x > 0) && (board[FR2, x - 1] == '*'))
                            {
                                x--;
                            }
                            board[FR2, x] = '.';
                        }
                        else
                        {
                            int x = FC1 + FC2 + FC3 - 1;
                            while ((x > 0) && (board[FR3, x - 1] == '*'))
                            {
                                x--;
                            }
                            board[FR3, x] = '.';
                        }
                    }

                    board[0, 0] = 'c';

                    // Output.
                    if (transpose)
                    {
                        for (int c = 0; c < C; c++)
                        {
                            for (int r = 0; r < R; r++)
                            {
                                writer.Write(board[r, c]);
                            }
                            writer.WriteLine();
                        }
                    }
                    else
                    {
                        for (int r = 0; r < R; r++)
                        {
                            for (int c = 0; c < C; c++)
                            {
                                writer.Write(board[r, c]);
                            }
                            writer.WriteLine();
                        }
                    }
                }
                
            }

            reader.Close();
            writer.Close();

        }

        private static void reset(char[,] board)
        {
            for (int r = 0; r < 50; r++)
            {
                for (int c = 0; c < 50; c++)
                {
                    board[r, c] = '*';
                }
            }
        }

        private static bool FindFreeRect(int R, int C, int M, ref int FR1, ref int FC1, ref int FR2, ref int FC2, ref int FR3, ref int FC3, ref bool isOdd)
        {
            FR1 = 0;
            FC1 = 0;
            FR2 = 0;
            FC2 = 0;
            FR3 = 0;
            FC3 = 0;
            isOdd = false;

            int empty = R * C - M;

            if (M == 0)
            {
                FR1 = R;
                FC1 = C;
                return true;
            }

            if (empty == 1)
            {
                FR1 = 1;
                FC1 = 1;
                return true;
            }

            if (C == 1)
            {
                FR1 = empty;
                FC1 = 1;
                return true;
            }

            if (C == 2)
            {
                // R > 2
                if ((empty % 2 == 0) && (empty > 2))
                {
                    FR1 = empty / 2;
                    FC1 = 2;
                    return true;
                }

                return false;
            }

            // C > 3

            if ((empty == 2) || (empty == 3) || (empty == 5) || (empty == 7))
            {
                return false;
            }

            isOdd = empty % 2 == 1;
            if (isOdd)
            {
                empty--;
            }

            int couples = empty / 2;
            int coupledLines = couples / R;
            int remainder = couples % R;
            if (isOdd)
            {
                if (remainder == 0)
                {
                    // Force remainder
                    // if (coupledLines > 0)
                    //                {
                    coupledLines--;
                    remainder = R - 1;
                    FR3 = 2;
                    FC3 = 1;
                    //                }
                }
                else
                {
                    if (coupledLines == 0)
                    {
                        remainder--;
                        FR3 = 2;
                        FC3 = 1;
                    }
                }
            }
                
            FR1 = R;
            FC1 = coupledLines * 2;

            if (remainder > 0)
            {
                if (remainder == 1)
                {
                    FR2 = 2;
                    FC2 = 1;
                    return true;
                }

                if (C >= coupledLines * 2 + 2)
                {
                    FR2 = remainder;
                    FC2 = 2;
                    return true;
                }

                FR2 = remainder * 2;
                FC2 = 1;
                return true;
            }


            return true;
        }
    }
}
