using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
//            string fileName = "test";
//            string fileName = "input";
    //        string fileName = "C-small-attempt5";
             string fileName = "C-large";

            string line;

            System.IO.StreamReader inFile =
               new System.IO.StreamReader(fileName + ".in");
            System.IO.StreamWriter outFile = 
                new System.IO.StreamWriter(fileName + ".out");

            line = inFile.ReadLine();

            int testcases;
            bool success = int.TryParse(line, out testcases);

            for (int i = 0; i < testcases; i++)
            {
                solveSingleTestcase(inFile, outFile, i + 1);
            }

            inFile.Close();
            outFile.Close();

            Console.ReadLine();
        }

        private static void solveSingleTestcase(System.IO.StreamReader inFile, System.IO.StreamWriter outFile, int testcaseNumber)
        {
            string line = inFile.ReadLine();
            string[] tokens = line.Split();

            int rows, columns, mines;
            int.TryParse(tokens[0], out rows);
            int.TryParse(tokens[1], out columns);
            int.TryParse(tokens[2], out mines);

            //            Console.WriteLine(r + " " + c + " " + m);

            int e = rows * columns - mines;

            int h = -1;
            int w = -1;
            int extras = -1;
            bool extrasBelow = false;
            bool extrasRight = false;

            if (e == 1)
            {
                h = 1;
                w = 1;
                extras = 0;
            }
            else if (rows == 1)
            {
                h = 1;
                w = e;
                extras = 0;
            }
            else if (columns == 1)
            {
                h = e;
                w = 1;
                extras = 0;
            }
            else
            {
                // i is for height
                for (int i = 2; i <= rows; i++)
                {
                    // j is for width
                    for (int j = 2; j <= columns; j++)
                    {
                        int size = i * j;
                        if (size == e)
                        {
                            h = i;
                            w = j;
                            extras = 0;
                            i = rows;
                            break;
                        }
                        else if (size < e && e < size + j && i < rows && size + 1 != e)
                        {
                            h = i;
                            w = j;
                            extras = e - size;
                            extrasBelow = true;
                            i = rows;
                            break;
                        }
                        else if (size <= e && e < size + i && j < columns && size + 1 != e)
                        {
                            h = i;
                            w = j;
                            extras = e - size;
                            extrasRight = true;
                            i = rows;
                            break;
                        }
                    }
                }
            }

            int hmines = -1;
            int wmines = -1;
            int extraMines = -1;
            bool minesLeft = false;
            bool minesAbove = false;

//            if (testcaseNumber == 53)
//            {
//                Console.WriteLine("######### 53! #########");
//            }

            if (h == -1)
            {
                // try building a square of mines
                for (int i = 1; i <= rows - 2; i++)
                {
                    for (int j = 1; j <= columns - 2; j++)
                    {
                        int mineSize = i * j;
                        if (mineSize == mines)
                        {
                            hmines = i;
                            wmines = j;

                            i = rows - 2;
                            break;
                        }
                        else if (mineSize < mines && mineSize + i >= mines && j < columns - 2)
                        {
                            hmines = i;
                            wmines = j;
                            extraMines = mines - mineSize;
                            minesLeft = true;

                            i = rows - 2;
                            break;
                        }
                        else if (mineSize < mines && mineSize + j >= mines && i < rows - 2)
                        {
                            hmines = i;
                            wmines = j;
                            extraMines = mines - mineSize;
                            minesAbove = true;

                            i = rows - 2;
                            break;
                        }
                    }
                }
            }

            Console.WriteLine("Case #" + testcaseNumber + ": ");
            outFile.WriteLine("Case #" + testcaseNumber + ": ");

            if (h == -1 && hmines == -1)
            {
                Console.WriteLine("Impossible");
                outFile.WriteLine("Impossible");
            }
            else
            {
                // [row, column]
                char[,] field = new char[rows, columns];

                if (h != -1)
                {
                    for (int i = 1; i <= rows; i++)
                    {
                        for (int j = 1; j <= columns; j++)
                        {
                            if (i <= h && j <= w)
                            {
                                field[i - 1, j - 1] = '.';
                            }
                            else
                            {
                                field[i - 1, j - 1] = '*';
                            }
                        }
                    }

                    if (extrasBelow)
                    {
                        for (int j = 1; j <= extras; j++)
                        {
                            field[h + 1 - 1, j - 1] = '.';
                        }
                    }

                    if (extrasRight)
                    {
                        for (int i = 1; i <= extras; i++)
                        {
                            field[i - 1, w + 1 - 1] = '.';
                        }
                    }

                    field[1 - 1, 1 - 1] = 'c';
                }
                else if (hmines != -1)
                {
                    for (int i = 1; i <= rows; i++)
                    {
                        for (int j = 1; j <= columns; j++)
                        {
                            if (i <= rows - hmines || j <= columns - wmines)
                            {
                                field[i - 1, j - 1] = '.';
                            }
                            else
                            {
                                field[i - 1, j - 1] = '*';
                            }
                        }
                    }

                    if (minesAbove)
                    {
                        for (int j = columns; j > columns - extraMines; j--)
                        {
                            field[rows - hmines - 1, j - 1] = '*';
                        }
                    }

                    if (minesLeft)
                    {
                        for (int i = rows; i > rows - extraMines; i--)
                        {
                            field[i - 1, columns - wmines - 1] = '*';
                        }
                    }


                    field[1 - 1, 1 - 1] = 'c';
                }

                for (int i = 1; i <= rows; i++)
                {
                    for (int j = 1; j <= columns; j++)
                    {
                        Console.Write(field[i - 1, j - 1]);
                        outFile.Write(field[i - 1, j - 1]);
                    }
                    Console.WriteLine();
                    outFile.WriteLine();
                }
            }
        }
    }
}
