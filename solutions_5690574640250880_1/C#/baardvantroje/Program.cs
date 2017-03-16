using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MinesweeperMaster
{
    class Params
    {
        public int Rows { get; set; }
        public int Cols { get; set; }
        public int Mines { get; set; }
    }

    class CellIndex
    {
        public CellIndex(int row, int col)
        {
            this.Row = row;
            this.Col = col;
        }

        public int Row { get; set; }
        public int Col { get; set; }
    }

    class Program
    {
        string inFilePath, outFilePath;
                
        static void Main(string[] args)
        {
            Program p;
            DateTime begin;

            p = new Program("C:\\gcj\\C-large.in", "C:\\gcj\\C-large.out");
            begin = DateTime.Now;
            p.Solve();
            Console.WriteLine("Solved sample input in {0:F4} seconds.", (DateTime.Now - begin).TotalSeconds);

            Console.WriteLine("{0}Press any key to exit.", Environment.NewLine);
            Console.ReadLine();
        }

        public Program (string inFilePath, string outFilePath)
        {
            this.inFilePath = inFilePath;
            this.outFilePath = outFilePath;
        }

        public void Solve()
        {
            using (StreamReader inStream = new StreamReader(inFilePath))
            using (StreamWriter outStream = new StreamWriter(outFilePath))
            {
                int numProblems = int.Parse(inStream.ReadLine());

                for (int i = 0; i < numProblems; i++)
                {
                    string[] paramStrings = inStream.ReadLine().Split(' ');

                    Params problem = new Params();
                    problem.Rows = int.Parse(paramStrings[0]);
                    problem.Cols = int.Parse(paramStrings[1]);
                    problem.Mines = int.Parse(paramStrings[2]);

                    outStream.WriteLine("Case #{0}: {1}", (i + 1), solveProblem(problem));
                }
            }
        }

        private string solveProblem(Params problem)
        {
            // initialize grid and determine minimum mobility
            int[,] mobilityGrid = initGrid(problem);
            int minMobility = updateMobilityAndGetMinimum(problem, ref mobilityGrid);

            bool deadLock = false;

            // while 1 < minimum mobility < 4
            // AND no deadlock has occurred
            while (1 < minMobility && minMobility < 4 && !deadLock)
            {
                // search for a better mobility / backtrack
                CellIndex ffcIndex = firstFreeIndex(problem, mobilityGrid);
                CellIndex lmIndex = lastMineIndex(problem, mobilityGrid, ffcIndex.Col + 1);

                // determine deadlock
                if (ffcIndex.Col == lmIndex.Col || lmIndex.Row == 0 && lmIndex.Col == 0)
                {
                    deadLock = true;
                }
                // swap and update mobility
                else
                {
                    int temp = mobilityGrid[ffcIndex.Row, ffcIndex.Col];
                    mobilityGrid[ffcIndex.Row, ffcIndex.Col] = mobilityGrid[lmIndex.Row, lmIndex.Col];
                    mobilityGrid[lmIndex.Row, lmIndex.Col] = temp;

                    minMobility = updateMobilityAndGetMinimum(problem, ref mobilityGrid);
                }
            }

            // return solution if applicable
            if (minMobility == 1 || minMobility > 3 || problem.Rows == 1 || problem.Cols == 1)
                return gridToString(problem, mobilityGrid);

            return "\nImpossible";
        }

        private int[,] initGrid(Params problem)
        {
            int[,] result = new int[problem.Rows, problem.Cols];

            int currCell = 0;
            for (int i = 0; i < problem.Rows; i++)
            {
                for (int j = 0; j < problem.Cols; j++)
                {
                    if (currCell < problem.Mines)
                    {
                        result[i, j] = 10;
                        currCell++;
                    }
                    else
                    {
                        result[i, j] = 0;
                    }
                }
            }

            return result;
        }

        private int updateMobilityAndGetMinimum(Params problem, ref int[,] mobilityGrid)
        {
            int minMobility = 10;

            for (int i = 0; i < problem.Rows; i++)
            {
                for (int j = 0; j < problem.Cols; j++)
                {
                    // skip mines
                    if (mobilityGrid[i, j] == 10)
                        continue;

                    // mobility is only granted within bounds
                    mobilityGrid[i, j] = 0;
                    for (int k = Math.Max(0, i - 1); k < Math.Min(problem.Rows, i + 2); k++)
                    {
                        for (int l = Math.Max(0, j - 1); l < Math.Min(problem.Cols, j + 2); l++)
                        {
                            // mines do not grant mobility
                            if (mobilityGrid[k, l] == 10)
                                continue;

                            mobilityGrid[i, j]++;
                        }
                    }

                    // optionally reduce minimum mobility
                    minMobility = Math.Min(minMobility, mobilityGrid[i, j]);
                }
            }

            return minMobility;
        }

        private CellIndex firstFreeIndex(Params problem, int[,] mobilityGrid)
        {
            for (int j = 0; j < problem.Cols; j++)
                for (int i = 0; i < problem.Rows; i++)
                    if (mobilityGrid[i, j] != 10)
                        return new CellIndex(i, j);

            return new CellIndex(problem.Rows - 1, problem.Cols - 1);
        }

        private CellIndex lastMineIndex(Params problem, int[,] mobilityGrid, int rightOfOrOnColumn = 0)
        {
            for (int i = problem.Rows - 1; i >= 0; i--)
                for (int j = problem.Cols - 1; j >= rightOfOrOnColumn; j--)
                    if (mobilityGrid[i, j] == 10)
                        return new CellIndex(i, j);

            return new CellIndex(0, 0);
        }

        private string gridToString(Params problem, int[,] mobilityGrid)
        {
            string result = "\n";
            for (int i = 0; i < problem.Rows; i++)
            {
                for (int j = 0; j < problem.Cols; j++)
                {
                    if (mobilityGrid[i, j] == 10)
                        result += "*";
                    else if (i == problem.Rows - 1 && j == problem.Cols - 1)
                        result += "c";
                    else
                        result += ".";
                }

                if (i != problem.Rows - 1)
                    result += "\n";
            }
            return result;
        }
    }
}
