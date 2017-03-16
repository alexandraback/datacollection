using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{


    class Program
    {
        static void Main(string[] args)
        {
            mineSweeper ms = new mineSweeper();
            ms.solve();
        }
    }




    class mineSweeper
    {
        public void solve()
        {
            string result = string.Empty;
            string inputFile = @"C:\Users\dante\Desktop\Google CodeJam 2014\QualificationRound\QualificationRound\input.txt";


            string[] lines = File.ReadAllLines(inputFile);
            int totalRowCounter = 0;

            int testCases = Int32.Parse(lines[totalRowCounter++]);

            for (int i = 0; i < testCases; i++)
            {
                string[] gameInfo = lines[totalRowCounter++].Split(' ').ToArray();
                int R = Int32.Parse(gameInfo[0]);
                int C = Int32.Parse(gameInfo[1]);
                int M = Int32.Parse(gameInfo[2]);

                char[,] gameConf = new char[R, C];
                for (int row = 0; row < R; row++)
                {
                    for (int col = 0; col < C; col++)
                    {
                        gameConf[row, col] = '.';
                    }
                }
                int minesPlaced = 0;

                int headerRow = 0;
                int headerCol = 0;

                while (minesPlaced < M)
                {
                    if ((((C - headerCol) - (M - minesPlaced) == 1)) && ((R - headerRow) - (M - minesPlaced) == 1))
                    {
                        gameConf[headerRow, headerCol] = '*';
                        minesPlaced++;

                        if (minesPlaced == M)
                            break;

                        int half = (int)((M - minesPlaced) / 2);

                        for (int k = 0; k < half; k++)
                        {
                            gameConf[headerRow, headerCol + k + 1] = '*';
                            minesPlaced++;

                            if (minesPlaced == M)
                                break;

                            gameConf[headerRow + k + 1, headerCol] = '*';
                            minesPlaced++;
                        }

                        if (M - minesPlaced == 1)
                        {
                            gameConf[headerRow + half + 1, headerCol] = '*';
                            minesPlaced++;
                        }
                    }
                    else if (((R - headerRow) >= (C - headerCol) && ((C - headerCol) - (M - minesPlaced) != 1)) || ((R - headerRow) - (M - minesPlaced) == 1))
                    {
                        for (int j = headerCol; j < C; j++)
                        {
                            gameConf[headerRow, j] = '*';
                            minesPlaced++;
                            if (minesPlaced == M)
                                j = C;
                        }
                        headerRow++;
                    }
                    else
                    {
                        for (int j = headerRow; j < R; j++)
                        {
                            gameConf[j, headerCol] = '*';
                            minesPlaced++;
                            if (minesPlaced == M)
                                j = R;
                        }
                        headerCol++;
                    }
                }

                if (((R * C) == M + 1) || evalSolution(gameConf))
                    result += String.Format("Case #{0}:\n{1}", i + 1, printCharArray(gameConf));
                else
                    result += String.Format("Case #{0}:\n{1}\n", i + 1, "Impossible");

            }


            string outputFile = @"C:\Users\dante\Desktop\Google CodeJam 2014\QualificationRound\QualificationRound\output.txt";
            File.WriteAllText(outputFile, result);

            Console.WriteLine("Success!");
            Console.Read();
        }

        public static string printCharArray(char[,] ch)
        {
            string msg = string.Empty;
            int rows = ch.GetLength(0);
            int columns = ch.GetLength(1);

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (j == columns - 1 && i == rows - 1)
                        msg += 'c';
                    else
                    {
                        if (ch[i, j] == '*')
                            msg += '*';
                        else
                            msg += '.';
                    }
                }
                msg += '\n';
            }

            return msg;
        }

        public static bool evalSolution(char[,] gameConf)
        {
            int rows = gameConf.GetLength(0);
            int columns = gameConf.GetLength(1);

            int[,] gameData = new int[rows, columns];

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (gameConf[i, j] == '*')
                    {
                        gameData[i, j] = -1;
                    }
                    else
                    {
                        gameData[i, j] = calcWeight(gameConf, i, j);
                    }
                }
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (gameConf[i, j] == '.')
                    {
                        if (!checkPath(gameData, i, j))
                            return false;
                    }
                }
            }

            return true;
        }

        public static int calcWeight(char[,] game, int row, int column)
        {
            int totalWeight = 0;
            for (int i = row - 1; i < row + 2; i++)
            {
                for (int j = column - 1; j < column + 2; j++)
                {
                    if ((i >= 0 && i <= game.GetLength(0) - 1) && (j >= 0 && j <= game.GetLength(1) - 1))
                    {
                        if (game[i, j] == '*')
                            totalWeight++;
                    }
                }
            }

            return totalWeight;
        }

        public static bool checkPath(int[,] game, int row, int column)
        {
            for (int i = row - 1; i < row + 2; i++)
            {
                for (int j = column - 1; j < column + 2; j++)
                {
                    if ((i >= 0 && i <= game.GetLength(0) - 1) && (j >= 0 && j <= game.GetLength(1) - 1))
                    {
                        if (game[i, j] == 0)
                            return true;
                    }
                }
            }

            return false;
        }
    }
}
