using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace google_minesweeper
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter writer = new StreamWriter("result.txt");
            using (StreamReader reader = new StreamReader("C-small-attempt1.in"))
            {
                int numGames = Int32.Parse(reader.ReadLine());

                for (int i = 0; i < numGames; i++)
                {
                    // read in pattern
                    int[] game = reader.ReadLine().Split(' ').Select(Int32.Parse).ToArray();

                    // calculate game
                    string result = "Case #" + (i + 1).ToString() + ":";
                    writer.WriteLine(result);
                    MakeGrid(writer, game[0], game[1], game[2]);
                }
            }

            writer.Close();
        }

        static void MakeGrid(StreamWriter writer, int rows, int cols, int mines)
        {
            int safeSpaces = (rows * cols) - mines;
            char[][] grid = new char[rows][];
            for(int i = 0; i < rows; i++)
                grid[i] = new char[cols];

            if (safeSpaces == 1)    // easy special case
            {
                fillGridWithMines(rows, cols, grid);
                grid[0][0] = 'c';
                printGrid(writer, grid);
                return;
            }

            if (rows == 1)  // special case
            {
                grid[0][0] = 'c';
                safeSpaces--;
                for (int i = 1; i < cols; i++)
                {
                    if (safeSpaces > 0)
                    {
                        grid[0][i] = '.';
                        safeSpaces--;
                    }
                    else
                        grid[0][i] = '*';
                }

                printGrid(writer, grid);
                return;
            }
            if (cols == 1)  // special case
            {
                grid[0][0] = 'c';
                safeSpaces--;
                for (int i = 1; i < rows; i++)
                {
                    if (safeSpaces > 0)
                    {
                        grid[i][0] = '.';
                        safeSpaces--;
                    }
                    else
                        grid[i][0] = '*';
                }

                printGrid(writer, grid);
                return;
            }

            // for grids 2x2 and above
            if (safeSpaces <= 3 || safeSpaces == 5 || safeSpaces == 7)
            {
                writer.WriteLine("Impossible");
                return;
            }
            if ((rows == 2 || cols == 2)
                && (safeSpaces % 2 == 1))
            {
                writer.WriteLine("Impossible");
                return;
            }

            if (safeSpaces == 4)    // corner
            {
                setSafeZone(2, 2, 0, 0, grid);
                grid[0][0] = 'c';
                fillGridWithMines(rows, cols, grid);
                printGrid(writer, grid);
                return;
            }
            else if (safeSpaces == 6)    // edge
            {
                if (cols > 2)
                    setSafeZone(2, 3, 0, 0, grid);
                else
                    setSafeZone(3, 2, 0, 0, grid);
                grid[0][0] = 'c';
                fillGridWithMines(rows, cols, grid);
                printGrid(writer, grid);
                return;
            }
            else if (safeSpaces == 8)   // edge
            {
                if (rows == 3 && cols == 3)
                {
                    setSafeZone(3, 3, 0, 0, grid);
                    grid[0][0] = 'c';
                    grid[2][2] = '*';
                    printGrid(writer, grid);
                    return;
                }
                else
                {
                    if (cols > 3)
                        setSafeZone(2, 4, 0, 0, grid);
                    else
                        setSafeZone(4, 2, 0, 0, grid);
                    grid[0][0] = 'c';
                    fillGridWithMines(rows, cols, grid);
                    printGrid(writer, grid);
                    return;
                }
            }

            // all other cases
            int safeCols = cols;
            int safeRows = safeSpaces / safeCols;
            int leftOver = safeSpaces % safeCols;

            while (safeRows <= 1 || leftOver == 1)   // make a rectangle at least 2x2
            {
                safeCols--;
                safeRows = safeSpaces / safeCols;
                leftOver = safeSpaces % safeCols;
                if (safeRows > rows || safeRows == rows && leftOver > 0)
                {
                    safeCols = cols;
                    safeRows = safeSpaces / safeCols;
                    leftOver = safeSpaces % safeCols;     // use a different method
                    break;
                }
            }

            setSafeZone(safeRows, safeCols, 0, 0, grid);
            setSafeZone(1, leftOver, safeRows, 0, grid);

            if (leftOver == 1)
            {
                grid[safeRows-1][cols - 1] = '*';
                grid[safeRows][1] = '.';
            }
            
            grid[0][0] = 'c';

            fillGridWithMines(rows, cols, grid);
            printGrid(writer, grid);

            verify(writer, grid, mines); // *** for testing
            return;
        }

        static void verify(StreamWriter writer, char[][] grid, int mines)
        {
            int mineCount = 0;
            int clickCount = 0;

            foreach (char[] row in grid)
            {
                foreach (char x in row)
                {
                    if (x == 'c')
                        clickCount++;
                    else if (x == '*')
                        mineCount++;
                }
            }

            if (clickCount != 1 || mineCount != mines)
                writer.WriteLine("           !!!!! WRONG !!!!!!");
        }

        // given a blank grid, set a safe zone ('.') of rows*cols size at (x,y)
        static void setSafeZone(int srows, int scols, int x, int y, char[][] grid)
        {
            for (int i = 0; i < srows; i++)
            {
                for (int j = 0; j < scols; j++)
                    grid[x + i][y + j] = '.';
            }
        }

        // fill all non-blank and non-click spaces on the grid with mines
        static void fillGridWithMines(int rows, int cols, char[][] grid)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (grid[i][j] != 'c' && grid[i][j] != '.')
                        grid[i][j] = '*';
                }
            }
        }

        static void printGrid(StreamWriter writer, char[][] grid)
        {
            foreach (char[] row in grid)
                writer.WriteLine(row);
        }
    }
}
