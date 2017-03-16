using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace qr2014ProgC
{
    class qrProgC
    {
        public const string cInputFile = "C:\\Dev\\2014\\qrC\\C-small-attempt5.in";
        public const string cOutputFile = "C:\\Dev\\2014\\qrC\\out.txt";
        public const string cExampleAnswerFile = "C:\\Dev\\2014\\qrC\\ea.txt";

        static void Main(string[] args)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(cOutputFile))
                {
                    using (StreamReader reader = new StreamReader(cInputFile))
                    {
                        int numberOfTestCases = int.Parse(reader.ReadLine());

                       
                        for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
                        {
                            string[] parms = reader.ReadLine().Split(' ');
                            int numberOfRows = int.Parse(parms[0]);
                            int numberOfCols = int.Parse(parms[1]);
                            int numberOfMines = int.Parse(parms[2]);

                            string[,] test;

                            
                            test = generateBoard(numberOfMines, numberOfRows, numberOfCols);
                            string[,] testCopy = copyBoard(test);
                            string[,] result = solveBoard(test, 0, 0);
                            testCopy[0, 0] = "c";
                            bool emptyDetected = checkForEmpty(result);

                            if (emptyDetected)
                            {
                                test = generateBoard2(numberOfMines, numberOfRows, numberOfCols);
                                testCopy = copyBoard(test);
                                result = solveBoard(test, 0, 0);
                                testCopy[0, 0] = "c";
                                emptyDetected = checkForEmpty(result);
                                if (emptyDetected)
                                {
                                    test = generateBoard3(numberOfMines, numberOfRows, numberOfCols);
                                    testCopy = copyBoard(test);
                                    result = solveBoard(test, 0, 0);
                                    testCopy[0, 0] = "c";
                                    emptyDetected = checkForEmpty(result);
                                }
                            }

                            writer.WriteLine("Case #" + (testCaseNum + 1).ToString() + ":");
                            Console.WriteLine("Case #" + (testCaseNum + 1).ToString() + ":");
                           
                            if (emptyDetected)
                            {
                                writer.WriteLine("Impossible");
                                Console.WriteLine("Impossible");
                            }
                            else
                            {
                                for (int row = 0; row < testCopy.GetLength(0); row++)
                                {
                                    for (int col = 0; col < testCopy.GetLength(1); col++)
                                    {
                                        writer.Write(testCopy[row, col]);
                                        Console.Write(testCopy[row, col]);
                                    }
                                    writer.WriteLine("");
                                    Console.WriteLine("");
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception exc)
            {
                Console.WriteLine(exc);
            }
        }

        static string[,] copyBoard(string[,] pBoard)
        {
            string[,] copyOfBoard = new string[pBoard.GetLength(0), pBoard.GetLength(1)];

            for (int row = 0; row < pBoard.GetLength(0); row++)
            {
                for (int col = 0; col < pBoard.GetLength(1); col++)
                {
                    copyOfBoard[row, col] = pBoard[row, col];
                }
            }

            return copyOfBoard;
        }

        static string[,] generateBoard(int pNumberOfMines, int pNumberOfRows, int pNumberOfCols)
        {
            string[,] board = new string[pNumberOfRows, pNumberOfCols];

            int numberOfCells = pNumberOfCols * pNumberOfRows;
            int numberOfOpenCells = numberOfCells - pNumberOfMines;

            //Need to generate a square of empties and surround the starting spot with empties

            //First fill board all up with mines.
            for (int row = 0; row < pNumberOfRows; row++)
            {
                for (int col = 0; col < pNumberOfCols; col++)
                {
                    board[row, col] = "*";
                }
            }

            //Put C in the upper left corner and start surrounding it with empties
            int numberOfOpenCellsPlaced = 0;

            //Determine empty BoxBounds
            int emptyBoxNumCols = (int)Math.Ceiling((double)numberOfOpenCells/2);
            if (pNumberOfRows == 1)
            {
                emptyBoxNumCols = numberOfOpenCells;
            }

            if (emptyBoxNumCols > pNumberOfCols)
            {
                emptyBoxNumCols = pNumberOfCols;
            }

            for (int row = 0; row < pNumberOfRows; row++)
            {
                for (int col = 0; col < emptyBoxNumCols; col++)
                {
                    board[row, col] = ".";
                    numberOfOpenCellsPlaced++;
                    if (numberOfOpenCellsPlaced == numberOfOpenCells)
                    {
                        break;
                    }
                }
                if (numberOfOpenCellsPlaced == numberOfOpenCells)
                {
                    break;
                }
            }

            //Check to see if any row contains only 1 open space
            for (int row = 0; row < pNumberOfRows; row++)
            {
                int numberOfMinesInRow = 0;
                for (int col = 0; col < pNumberOfCols; col++)
                {
                    if (board[row, col] == "*")
                    {
                        numberOfMinesInRow++;
                    }
                }

                //1 open spot in row.
                //relocate mine to row above if possible
                if (numberOfMinesInRow == pNumberOfCols - 1)
                {
                    if (row - 1 >= 0 && pNumberOfCols > 2)
                    {
                        board[row, 1] = ".";
                        board[row - 1, emptyBoxNumCols-1] = "*";
                    }
                }
                else if (numberOfMinesInRow == pNumberOfCols)
                {
                    break;
                }
            }

            if (numberOfOpenCellsPlaced != numberOfOpenCells)
            {
                Console.WriteLine("Problem");
            }

            return board;
        }

        static string[,] generateBoard2(int pNumberOfMines, int pNumberOfRows, int pNumberOfCols)
        {
            string[,] board = new string[pNumberOfRows, pNumberOfCols];

            int numberOfCells = pNumberOfCols * pNumberOfRows;
            int numberOfOpenCells = numberOfCells - pNumberOfMines;

            //Need to generate a square of empties and surround the starting spot with empties

            //First fill board all up with empties.
            for (int row = 0; row < pNumberOfRows; row++)
            {
                for (int col = 0; col < pNumberOfCols; col++)
                {
                    board[row, col] = ".";
                }
            }


            int numberOfMinesPlaced = 0;
            //Start in bottom left
            for (int col = pNumberOfCols -1; col >= 0; col--)
            {
                for(int row = pNumberOfRows -1; row >=0; row--)
                {
                    if (numberOfMinesPlaced < pNumberOfMines)
                    {
                        board[row, col] = "*";
                        numberOfMinesPlaced++;
                    }

                    if (numberOfMinesPlaced == pNumberOfMines)
                    {
                        break;
                    }
                }
                if (numberOfMinesPlaced == pNumberOfMines)
                {
                    break;
                }
            }

            //Check to see if any col contains only 1 open space
            for (int col = 0; col < pNumberOfCols; col++)
            {
                int numberOfMinesInCol = 0;
                for (int row = 0; row < pNumberOfRows; row++)
                {
                    if (board[row, col] == "*")
                    {
                        numberOfMinesInCol++;
                    }
                }

                //1 open spot in Col
                //relocate mine to next col over at bottom if possible
                if (numberOfMinesInCol == pNumberOfRows - 1)
                {
                    if (col - 1 >= 0 && pNumberOfRows > 2)
                    {
                        board[1, col] = ".";
                        board[pNumberOfRows - 1, col - 1] = "*";
                    }
                }
                else if (numberOfMinesInCol == pNumberOfRows)
                {
                    break;
                }
            }

            if (numberOfMinesPlaced != pNumberOfMines)
            {
                Console.WriteLine("Problem");
            }

            return board;
        }

        static string[,] generateBoard3(int pNumberOfMines, int pNumberOfRows, int pNumberOfCols)
        {
            //Perfect square method

            string[,] board = new string[pNumberOfRows, pNumberOfCols];

            int numberOfCells = pNumberOfCols * pNumberOfRows;
            int numberOfOpenCells = numberOfCells - pNumberOfMines;

            //Need to generate a square of empties and surround the starting spot with empties

            //First fill board all up with mines.
            for (int row = 0; row < pNumberOfRows; row++)
            {
                for (int col = 0; col < pNumberOfCols; col++)
                {
                    board[row, col] = "*";
                }
            }

            //Put C in the upper left corner and start surrounding it with empties
            int numberOfOpenCellsPlaced = 0;

            //Determine empty BoxBounds
            int emptyBoxNumCols = 1;
            int squareRootRouded = (int)Math.Sqrt((double)numberOfOpenCells);
            if (squareRootRouded * squareRootRouded != numberOfOpenCells)
            {
                emptyBoxNumCols = squareRootRouded + 1;
            }
            else
            {
                emptyBoxNumCols = squareRootRouded;
            }

            //box won't fit need to adjust the size
            if (emptyBoxNumCols * pNumberOfRows < numberOfOpenCells)
            {
                int minNumberOfColsNeededForMines = (int)Math.Ceiling((double)pNumberOfMines / pNumberOfRows);
                int minColsNeededForEmpties = (int)Math.Ceiling((double) pNumberOfCols - (pNumberOfMines / pNumberOfRows));

                if(minColsNeededForEmpties > 0)
                {
                    emptyBoxNumCols = minColsNeededForEmpties;
                }
                else
                {
                    emptyBoxNumCols = 1;
                }
            }

            if (pNumberOfRows == 1)
            {
                emptyBoxNumCols = numberOfOpenCells;
            }

            if (emptyBoxNumCols > pNumberOfCols)
            {
                emptyBoxNumCols = pNumberOfCols;
            }

            for (int row = 0; row < pNumberOfRows; row++)
            {
                for (int col = 0; col < emptyBoxNumCols; col++)
                {
                    board[row, col] = ".";
                    numberOfOpenCellsPlaced++;
                    if (numberOfOpenCellsPlaced == numberOfOpenCells)
                    {
                        break;
                    }
                }
                if (numberOfOpenCellsPlaced == numberOfOpenCells)
                {
                    break;
                }
            }

            //Check to see if any row contains only 1 open space
            for (int row = 0; row < pNumberOfRows; row++)
            {
                int numberOfMinesInRow = 0;
                for (int col = 0; col < pNumberOfCols; col++)
                {
                    if (board[row, col] == "*")
                    {
                        numberOfMinesInRow++;
                    }
                }

                //1 open spot in row.
                //relocate mine to row above if possible
                if (numberOfMinesInRow == pNumberOfCols - 1)
                {
                    if (row - 1 >= 0 && pNumberOfCols > 2)
                    {
                        board[row, 1] = ".";
                        board[row - 1, emptyBoxNumCols - 1] = "*";
                    }
                }
                else if (numberOfMinesInRow == pNumberOfCols)
                {
                    break;
                }
            }

            if (numberOfOpenCellsPlaced != numberOfOpenCells)
            {
                Console.WriteLine("Problem");
            }

            return board;
        }

        static string[,] solveBoard(string[,] pBoard, int pRowClicked, int pColumnClicked)
        {
            int row = pRowClicked;
            int col = pColumnClicked;

            int maxNumberOfRows = pBoard.GetLength(0);
            int maxNumberOfCols = pBoard.GetLength(1);

            string currentValueAtCell = pBoard[row, col];
            
            int mineCountForCell = -1;
            if (currentValueAtCell == ".")
            {
                mineCountForCell = 0;
                //Determine value for cell
                if (row - 1 >= 0                    &&                              pBoard[row - 1, col] == "*")        { mineCountForCell++; }  //North
                if (row - 1 >= 0                    && col + 1 < maxNumberOfCols && pBoard[row - 1, col + 1] == "*")    { mineCountForCell++; }  //NorthEast
                if (col + 1 < maxNumberOfCols       &&                              pBoard[row, col + 1] == "*")        { mineCountForCell++; }  //East
                if (row + 1 < maxNumberOfRows       && col + 1 < maxNumberOfCols && pBoard[row + 1, col + 1] == "*")    { mineCountForCell++; }  //SouthEast
                if (row + 1 < maxNumberOfRows       &&                              pBoard[row + 1, col] == "*")        { mineCountForCell++; }  //South
                if (row + 1 < maxNumberOfRows       && col - 1 >= 0              && pBoard[row + 1, col - 1] == "*")    { mineCountForCell++; }  //SouthWest
                if (col - 1 >= 0                    &&                              pBoard[row, col - 1] == "*")        { mineCountForCell++; }  //West
                if (row - 1 >= 0                    && col - 1 >= 0              && pBoard[row - 1, col - 1] == "*")    { mineCountForCell++; }  //NorthWest
                pBoard[row, col] = mineCountForCell.ToString();
            }

            if (mineCountForCell == 0)
            {
                if (row - 1 >= 0 && pBoard[row - 1, col] == ".") { pBoard = solveBoard(pBoard, row - 1, col); }  //North
                if (row - 1 >= 0 && col + 1 < maxNumberOfCols && pBoard[row - 1, col + 1] == ".") { pBoard = solveBoard(pBoard, row - 1, col + 1); }  //NorthEast
                if (col + 1 < maxNumberOfCols && pBoard[row, col + 1] == ".") { pBoard = solveBoard(pBoard, row, col + 1);}  //East
                if (row + 1 < maxNumberOfRows && col + 1 < maxNumberOfCols && pBoard[row + 1, col + 1] == ".") { pBoard = solveBoard(pBoard,row + 1, col + 1); }  //SouthEast
                if (row + 1 < maxNumberOfRows && pBoard[row + 1, col] == ".") { pBoard = solveBoard(pBoard,row + 1, col); }  //South
                if (row + 1 < maxNumberOfRows && col - 1 >= 0 && pBoard[row + 1, col - 1] == ".") { pBoard = solveBoard(pBoard,row + 1, col - 1); }  //SouthWest
                if (col - 1 >= 0 && pBoard[row, col - 1] == ".") { pBoard = solveBoard(pBoard, row, col - 1);}  //West
                if (row - 1 >= 0 && col - 1 >= 0 && pBoard[row - 1, col - 1] == ".") { pBoard = solveBoard(pBoard, row - 1, col - 1);}  //NorthWest
            }
            return pBoard;

        }

        static bool checkForEmpty(string[,] pBoard)
        {
            bool emptyDetected = false;

            for (int row = 0; row < pBoard.GetLength(0); row++)
            {
                for (int col = 0; col < pBoard.GetLength(1); col++)
                {
                    if (pBoard[row, col] == ".")
                    {
                        emptyDetected = true;
                        break;
                    }
                }

                if (emptyDetected)
                {
                    break;
                }
            }

            return emptyDetected;
        }
    }
}
