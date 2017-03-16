using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round_Q_Task_3
{
    class Program
    {
        const string ResultImpossible = "Impossible";

        static void Main(string[] args)
        {
            int numberOfCases = int.Parse(Console.ReadLine());

            for (int i = 1; i <= numberOfCases; ++i)
            {
                string line = Console.ReadLine();

                string[] caseParameters = line.Split(new char[] { ' ' });
                int boardHeight = int.Parse(caseParameters[0]);
                int boardWidth = int.Parse(caseParameters[1]);
                int minesCount = int.Parse(caseParameters[2]);

                char[,] board = SolveCase(boardWidth, boardHeight, minesCount);

                Console.WriteLine(string.Format("Case #{0}:", i));
                if (board != null)
                {
                    StringBuilder resultOutput = new StringBuilder();

                    for (int r = 0; r < boardHeight; ++r)
                    {
                        for (int c = 0; c < boardWidth; ++c)
                        {
                            resultOutput.Append(board[c, r]);
                        }

                        resultOutput.Append("\n");
                    }

                    Console.Write(resultOutput.ToString());
                }
                else
                {
                    Console.WriteLine(ResultImpossible);
                }
            }
        }

        private static char[,] SolveCase(int boardWidth, int boardHeight, int minesCount)
        {
            char[,] board = new char[boardWidth, boardHeight];

            // if there are no mines on the board
            if (minesCount == 0)
            {
                for (int r = 0; r < boardHeight; ++r)
                {
                    for (int c = 0; c < boardWidth; ++c)
                    {
                        if (c == boardWidth - 1 && r == boardHeight - 1)
                        {
                            board[c, r] = 'c';
                        }
                        else
                        {
                            board[c, r] = '.';
                        }
                    }
                }

                return board;
            }
            //if there is only one safe cell to click
            else if (boardWidth * boardHeight == minesCount + 1)
            {
                for (int r = 0; r < boardHeight; ++r)
                {
                    for (int c = 0; c < boardWidth; ++c)
                    {
                        if (c == boardWidth - 1 && r == boardHeight - 1)
                        {
                            board[c, r] = 'c';
                        }
                        else
                        {
                            board[c, r] = '*';
                        }
                    }
                }

                return board;
            }
            else if (boardWidth == 1 || boardHeight == 1)
            {
                int minesPlaced = 0;
                for (int r = 0; r < boardHeight; ++r)
                {
                    for (int c = 0; c < boardWidth; ++c)
                    {
                        if (minesPlaced < minesCount)
                        {
                            board[c, r] = '*';
                            minesPlaced++;
                        }
                        else if (r == boardHeight - 1 && c == boardWidth - 1)
                        {
                            board[c, r] = 'c';
                        }
                        else
                        {
                            board[c, r] = '.';
                        }
                    }
                }

                return board;
            }
            else if (boardWidth == 2 && boardHeight == 2)
            {
                return null;
            }
            else if (boardWidth == 2 || boardHeight == 2)
            {
                return SolveTwoRowsOrColumnsCase(boardWidth, boardHeight, minesCount);
            }
            else
            {
                int safeMinesCount = (boardWidth - 2) * (boardHeight - 2);

                // place safe mines
                int minesPlaced = 0;
                for (int r = 0; r < boardHeight; ++r)
                {
                    for (int c = 0; c < boardWidth; ++c)
                    {
                        if (minesPlaced < minesCount && c < boardWidth - 2 && r < boardHeight - 2)
                        {
                            board[c, r] = '*';
                            minesPlaced++;
                        }
                        else if (c == boardWidth - 1 && r == boardHeight - 1)
                        {
                            board[c, r] = 'c';
                        }
                        else
                        {
                            board[c, r] = '.';
                        }
                    }
                }

                // if any mines left outside the safe part of the board
                if (minesPlaced < minesCount)
                {
                    int minesLeft = minesCount - minesPlaced;

                    bool oddMinesLeft = (minesLeft % 2 != 0);

                    if (oddMinesLeft && ((boardWidth == 3
                        && boardHeight == 3)
                        || (minesLeft > 2 * (boardWidth - 3) + 2 * (boardHeight - 3))))
                    {
                        return null;
                    }

                    if (boardWidth < boardHeight)
                    {
                        AddUnsafeMinesToWidth(board, boardWidth, boardHeight, ref minesPlaced, minesCount, oddMinesLeft);
                        AddUnsafeMinesToHeight(board, boardWidth, boardHeight, ref minesPlaced, minesCount, oddMinesLeft);
                    }
                    else
                    {
                        AddUnsafeMinesToHeight(board, boardWidth, boardHeight, ref minesPlaced, minesCount, oddMinesLeft);
                        AddUnsafeMinesToWidth(board, boardWidth, boardHeight, ref minesPlaced, minesCount, oddMinesLeft);
                    }

                    if (oddMinesLeft)
                    {
                        //one mine too much was added, remove mine from the corner of the safe area
                        board[boardWidth - 3, boardHeight - 3] = '.';
                    }
                }

                if (minesPlaced < minesCount)
                {
                    return null;
                }
                else
                {
                    return board;
                }
            }
        }

        private static void AddUnsafeMinesToWidth(char[,] board, int boardWidth, int boardHeight, ref int minesPlaced, int minesCount, bool oddMinesLeft)
        {
            int reservedRows = oddMinesLeft ? 3 : 2;

            for (int r = 0; r < boardHeight - reservedRows; ++r)
            {
                if (minesPlaced < minesCount)
                {
                    board[boardWidth - 2, r] = '*';
                    board[boardWidth - 1, r] = '*';

                    minesPlaced += 2;
                }
                else
                {
                    break;
                }
            }
        }

        private static void AddUnsafeMinesToHeight(char[,] board, int boardWidth, int boardHeight, ref int minesPlaced, int minesCount, bool oddMinesLeft)
        {
            int reservedColumns = oddMinesLeft ? 3 : 2;

            for (int c = 0; c < boardWidth - reservedColumns; ++c)
            {
                if (minesPlaced < minesCount)
                {
                    board[c, boardHeight - 2] = '*';
                    board[c, boardHeight - 1] = '*';

                    minesPlaced += 2;
                }
                else
                {
                    break;
                }
            }
        }

        private static char[,] SolveTwoRowsOrColumnsCase(int boardWidth, int boardHeight, int minesCount)
        {
            if (minesCount % 2 != 0)
            {
                return null;
            }

            if (boardWidth == 2)
            {
                if (minesCount / 2 > boardHeight - 2)
                {
                    return null;
                }

                char[,] board = new char[boardWidth, boardHeight];
                int minesPlaced = 0;

                for (int r = 0; r < boardHeight; ++r)
                {
                    for (int c = 0; c < boardWidth; ++c)
                    {
                        if (minesPlaced < minesCount)
                        {
                            board[c, r] = '*';

                            minesPlaced++;
                        }
                        else if (c == boardWidth - 1 && r == boardHeight - 1)
                        {
                            board[c, r] = 'c';
                        }
                        else
                        {
                            board[c, r] = '.';
                        }
                    }
                }

                return board;
            }
            else if (boardHeight == 2)
            {
                if (minesCount / 2 > boardWidth - 2)
                {
                    return null;
                }

                char[,] board = new char[boardWidth, boardHeight];
                int minesPlaced = 0;

                for (int c = 0; c < boardWidth; ++c)
                {
                    for (int r = 0; r < boardHeight; ++r)
                    {
                        if (minesPlaced < minesCount)
                        {
                            board[c, r] = '*';

                            minesPlaced++;
                        }
                        else if (c == boardWidth - 1 && r == boardHeight - 1)
                        {
                            board[c, r] = 'c';
                        }
                        else
                        {
                            board[c, r] = '.';
                        }
                    }
                }

                return board;
            }

            return null;
        }
    }
}
