using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemC
{
    class Program
    {
        private static StreamWriter writer;

        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Invalid input parameters!");
                return;
            }

            string inputFile = args[0];
            string outputFile = args[1];

            writer = new StreamWriter(outputFile);
            using (var reader = new StreamReader(inputFile))
            {
                int testCases = int.Parse(reader.ReadLine());
                for (int caseNumber = 1; caseNumber <= testCases; caseNumber++)
                {
                    var parameters = reader.ReadLine().Split();
                    var R = int.Parse(parameters[0]);
                    var C = int.Parse(parameters[1]);
                    var M = int.Parse(parameters[2]);

                    Console.WriteLine("Case #{0}:", caseNumber);
                    writer.WriteLine("Case #{0}:", caseNumber);

                    PrintSolution(R, C, R * C - M);
                }
            }
            writer.Close();
        }

        private static void PrintSolution(int R, int C, int E)
        {
            for(int row = 0; row < R; ++ row)
            {
                for (int col = 0; col < C; col++)
                {
                    var gameBoard = new int[R,C];
                    if(Click(row, col, R, C, E, gameBoard))
                        return;
                }
            }
            writer.WriteLine("Impossible");
        }

        private static bool Click(int row, int col, int R, int C, int E, int[,] gameBoard)
        {
            int emptyCell = 1;
            gameBoard[row, col] = 2;

            // special case where M == R * C - 1 || M == 0
            if (emptyCell >= E)
            {
                PrintBoard(gameBoard);
                return true;
            }

            // Update neighbors of the clicked cell
            var updatedCells = UpdateNeighbors(row, col, R, C, gameBoard);
            emptyCell += updatedCells.Count;
            if (emptyCell == E)
            {
                PrintBoard(gameBoard);
                return true;
            }
            if (emptyCell < E)
            {
                foreach (var neighbor in GetNeighbors(row, col, R, C, gameBoard))
                {
                    if (RevealGameBoard(neighbor.Item1, neighbor.Item2, emptyCell, R, C, E, gameBoard))
                        return true;
                }
            }
            return false;
        }

        private static bool RevealGameBoard(int row, int col, int emptyCell, int R, int C, int E, int[,] gameBoard)
        {
            var updatedCells = UpdateNeighbors(row, col, R, C, gameBoard);
            emptyCell += updatedCells.Count;
            if (emptyCell == E)
            {
                PrintBoard(gameBoard);
                return true;
            }
            if (emptyCell < E)
            {
                foreach (var neighbor in GetNeighbors(row, col, R, C, gameBoard))
                {
                    if (RevealGameBoard(neighbor.Item1, neighbor.Item2, emptyCell, R, C, E, gameBoard))
                        return true;
                }
            }
            RestoreChangedCells(updatedCells, gameBoard);
            return false;
        }

        private static IEnumerable<Tuple<int, int>> GetNeighbors(int row, int col, int R, int C, int[,] gameBoard)
        {
            var neighbors = new List<Tuple<int, int>>();
            if (col + 1 < C && ShouldTryReveal(row, col + 1, R, C, gameBoard)) // right cell
            {
                neighbors.Add(Tuple.Create(row, col + 1));
            }
            if (col - 1 >= 0 && ShouldTryReveal(row, col - 1, R, C, gameBoard)) // left cell
            {
                neighbors.Add(Tuple.Create(row, col - 1));
            }
            if (row + 1 < R && ShouldTryReveal(row + 1, col, R, C, gameBoard)) // lower cell
            {
                neighbors.Add(Tuple.Create(row + 1, col));
            }
            if (row - 1 >= 0 && ShouldTryReveal(row - 1, col, R, C, gameBoard)) // upper cell
            {
                neighbors.Add(Tuple.Create(row - 1, col));
            }
            if (col + 1 < C && row + 1 < R && ShouldTryReveal(row + 1, col + 1, R, C, gameBoard)) // lower right
            {
                neighbors.Add(Tuple.Create(row + 1, col + 1));
            }
            if (col + 1 < C && row - 1 >= 0 && ShouldTryReveal(row - 1, col + 1, R, C, gameBoard)) // upper right
            {
                neighbors.Add(Tuple.Create(row - 1, col + 1));
            }
            if (col - 1 >= 0 && row + 1 < R && ShouldTryReveal(row + 1, col - 1, R, C, gameBoard)) // lower left
            {
                neighbors.Add(Tuple.Create(row + 1, col - 1));
            }
            if (col - 1 >= 0 && row - 1 >= 0 && ShouldTryReveal(row - 1, col - 1, R, C, gameBoard)) // upper left
            {
                neighbors.Add(Tuple.Create(row - 1, col - 1));
            }
            return neighbors;
        }

        private static bool ShouldTryReveal(int row, int col, int R, int C, int[,] gameBoard)
        {
            if (col + 1 < C && gameBoard[row, col + 1] == 0) // right cell
                return true;
            if (col - 1 >= 0 && gameBoard[row, col - 1] == 0) // left cell
                return true;
            if (row + 1 < R && gameBoard[row + 1, col] == 0) // lower cell
                return true;
            if (row - 1 >= 0 && gameBoard[row - 1, col] == 0) // upper cell
                return true;
            if (col + 1 < C && row + 1 < R && gameBoard[row + 1, col + 1] == 0) // lower right
                return true;
            if (col + 1 < C && row - 1 >= 0 && gameBoard[row - 1, col + 1] == 0) // upper right
                return true;
            if (col - 1 >= 0 && row + 1 < R && gameBoard[row + 1, col - 1] == 0) // lower left
                return true;
            if (col - 1 >= 0 && row - 1 >= 0 && gameBoard[row - 1, col - 1] == 0) // upper left
                return true;
            return false;
        }

        private static void RestoreChangedCells(IEnumerable<Tuple<int, int, int>> toBeRestored, int[,] gameBoard)
        {
            foreach (var cell in toBeRestored)
            {
                gameBoard[cell.Item1, cell.Item2] = cell.Item3;
            }
        }

        private static List<Tuple<int, int, int>> UpdateNeighbors(int row, int col, int R, int C, int[,] gameBoard)
        {
            var updateddCells = new List<Tuple<int, int, int>>();
            if (col + 1 < C && gameBoard[row, col + 1] == 0) // right cell
            {
                updateddCells.Add(Tuple.Create(row, col + 1, gameBoard[row, col + 1]));
                gameBoard[row, col + 1] = 1;
            }
            if (col - 1 >= 0 && gameBoard[row, col - 1] == 0) // left cell
            {
                updateddCells.Add(Tuple.Create(row, col - 1, gameBoard[row, col -1]));
                gameBoard[row, col - 1] = 1;
            }
            if (row + 1 < R && gameBoard[row + 1, col] == 0) // lower cell
            {
                updateddCells.Add(Tuple.Create(row + 1, col, gameBoard[row + 1, col]));
                gameBoard[row + 1, col] = 1;
            }
            if (row - 1 >= 0 && gameBoard[row - 1, col] == 0) // upper cell
            {
                updateddCells.Add(Tuple.Create(row - 1, col, gameBoard[row - 1, col]));
                gameBoard[row - 1, col] = 1;
            }
            if (col + 1 < C && row + 1 < R && gameBoard[row + 1, col + 1] == 0) // lower right
            {
                updateddCells.Add(Tuple.Create(row + 1, col + 1, gameBoard[row + 1, col + 1]));
                gameBoard[row + 1, col + 1] = 1;
            }
            if (col + 1 < C && row - 1 >= 0 && gameBoard[row - 1, col + 1] == 0) // upper right
            {
                updateddCells.Add(Tuple.Create(row - 1, col + 1, gameBoard[row - 1, col + 1]));
                gameBoard[row - 1, col + 1] = 1;
            }
            if (col - 1 >= 0 && row + 1 < R && gameBoard[row + 1, col - 1] == 0) // lower left
            {
                updateddCells.Add(Tuple.Create(row + 1, col - 1, gameBoard[row + 1, col - 1]));
                gameBoard[row + 1, col - 1] = 1;
            }
            if (col - 1 >= 0 && row - 1 >= 0 && gameBoard[row - 1, col - 1] == 0) // upper left
            {
                updateddCells.Add(Tuple.Create(row - 1, col - 1, gameBoard[row - 1, col - 1]));
                gameBoard[row - 1, col - 1] = 1;
            }

            return updateddCells;
        }

        private static void PrintBoard(int[,] gameBoard)
        {
            for (int row = 0; row < gameBoard.GetLength(0); row++)
            {
                for (int col = 0; col < gameBoard.GetLength(1); col++)
                {
                    switch (gameBoard[row, col])
                    {
                        case 1:
                            writer.Write(".");
                            System.Diagnostics.Debug.Write(".");
                            break;
                        case 0:
                            writer.Write("*");
                            System.Diagnostics.Debug.Write("*");
                            break;
                        case 2:
                            writer.Write("c");
                            System.Diagnostics.Debug.Write("c");
                            break;
                        default:
                            break;
                    }
                }
                writer.WriteLine();
                System.Diagnostics.Debug.WriteLine("");
            }
        }

        //static void Main(string[] args)
        //{
        //    if (args.Length != 2)
        //    {
        //        Console.WriteLine("Invalid input parameters!");
        //        return;
        //    }

        //    string inputFile = args[0];
        //    string outputFile = args[1];

        //    using (var reader = new StreamReader(inputFile))
        //    using (var writer = new StreamWriter(outputFile))
        //    {
        //        int testCases = int.Parse(reader.ReadLine());
        //        for (int caseNumber = 1; caseNumber <= testCases; caseNumber++)
        //        {
        //            var parameters = reader.ReadLine().Split();
        //            var R = int.Parse(parameters[0]);
        //            var C = int.Parse(parameters[1]);
        //            var M = int.Parse(parameters[2]);

        //            Console.WriteLine("Case #{0}:", caseNumber);
        //            writer.WriteLine("Case #{0}:", caseNumber);

        //            if (!PrintSolution(writer, R, C, M))
        //            {
        //                writer.WriteLine("Impossible");
        //            }
        //        }
        //    }
        //}

        //private static bool PrintSolution(StreamWriter writer, int R, int C, int M)
        //{
        //    if (R == 1 || C == 1)
        //    {
        //        if (M >= R*C) return false;
        //        for (int i = 1; i <= R * C; i++)
        //        {
        //            if (i == 1)
        //            {
        //                writer.Write("c");
        //            }
        //            else if(i <= R*C - M)
        //            {
        //                writer.Write(".");
        //            }
        //            else
        //            {
        //                writer.Write("*");
        //            }
        //            if (C == 1 || i == R*C)
        //            {
        //                writer.WriteLine();
        //            }
        //        }
        //    }
        //    else if (R == 2 || C == 2)
        //    {
        //        if (M >= R*C || M % 2 != 0) return false;
        //        if (R == 2)
        //        {
        //            for (int row = 1; row <= 2; row++)
        //            {
        //                for (int i = 1; i <= R * C / 2; i++)
        //                {
        //                    if (row == 1 && i == 1)
        //                    {
        //                        writer.Write("c");
        //                    }
        //                    else if (i <= (R * C - M) / 2)
        //                    {
        //                        writer.Write(".");
        //                    }
        //                    else
        //                    {
        //                        writer.Write("*");
        //                    }
        //                }
        //                writer.WriteLine();
        //            }
        //        }
        //        else
        //        {
        //            for (int i = 1; i <= R*C; i++)
        //            {
        //                if (i == 1)
        //                {
        //                    writer.Write("c");
        //                }
        //                else if (i <= R*C - M)
        //                {
        //                    writer.Write(".");
        //                }
        //                else
        //                {
        //                    writer.Write("*");
        //                }

        //                if (i % 2 == 0)
        //                {
        //                    writer.WriteLine();
        //                }
        //            }
        //        }
        //    }
        //    else
        //    {
        //        return false;
        //    }
        //    return true;
        //}
    }
}
