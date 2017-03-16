using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Minesweeper_Master
{
    class Program
    {
        static List<char[,]> boards = new List<char[,]>();
        static Dictionary<int, char[,]> dictionary = new Dictionary<int, char[,]>();

        static bool foundAnswer;
        static bool firstClick;

        static void Main(string[] args)
        {
            int T, numMines, rows, columns;
            char[,] board;

            int.TryParse(Console.ReadLine(), out T);

            for (int i = 0; i < T; i++)
            {
                // Setup
                boards.Clear();
                dictionary.Clear();
                int blankSpaces;
                foundAnswer = false;

                string[] tokens = Console.ReadLine().Split();

                int.TryParse(tokens[0], out rows);
                int.TryParse(tokens[1], out columns);
                int.TryParse(tokens[2], out numMines);

                board = new char[rows, columns];

                // Fill in the board with all unclicked spaces
                for (int j = 0; j < rows; j++)
                {
                    for (int k = 0; k < columns; k++)
                    {
                        board[j, k] = '.';
                    }
                }

                // Get goal num
                blankSpaces = rows * columns - numMines;

                if (blankSpaces == 1)
                {
                    Console.WriteLine("Case #" + (i + 1) + ":");

                    for (int j = 0; j < board.GetLength(0); j++)
                    {
                        for (int k = 0; k < board.GetLength(1); k++)
                        {
                            if (j == 0 && k == 0)
                                Console.Write('c');
                            else
                                Console.Write('*');
                        }
                        Console.WriteLine();
                    }
                }
                else
                {
                    // Begin to try all possible clicks
                    for (int j = 0; j < rows; j++)
                    {
                        for (int k = 0; k < columns; k++)
                        {
                            firstClick = true;
                            Click(j, k, board, blankSpaces);
                        }
                    }

                    Console.WriteLine("Case #" + (i + 1) + ":");
                    bool gotStart = false;

                    if (dictionary.Count != 0)
                    {
                        char[,] solution = dictionary[blankSpaces];

                        for (int j = 0; j < solution.GetLength(0); j++)
                        {
                            for (int k = 0; k < solution.GetLength(1); k++)
                            {
                                if (solution[j, k] == '.')
                                    Console.Write('*');
                                else if (solution[j, k] == 'x' && !gotStart)
                                {
                                    Console.Write('c');
                                    gotStart = true;
                                }
                                else
                                    Console.Write('.');
                            }
                            Console.WriteLine();
                        }
                    }
                    else
                        Console.WriteLine("Impossible");
                }
            }
        }

        /************
         *  Click will place a zero at position (r,c) in the board.
         *  
         *  Then click will recursively call itself on each of the 
         *  surrounding nodes, effectively zeroing out the entire board.
         *  
         *  At each iteration, Click will store the count of clicked tiles
         *  in the static list.
         *  
         *  If the total number of tiles on the board minus the number of mines
         *  is equal to any of the logged counts, we know a solution exists
         * 
         * ***********/

        static void Click (int r, int c, char[,] board, int goalNum)
        {
            if (foundAnswer)
                return;

            if (firstClick)
            {
                board[r, c] = 'x';
                firstClick = false;
            }
            else
                board[r, c] = 'c';

            // Add all unclicked adjacent tiles to the open list
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if (r + x >= 0 && r + x < board.GetLength(0) && c + y >= 0 && c + y < board.GetLength(1))
                    {
                        if (board[r+x, c+y] == '.')
                            board[r+x, c+y] = 'o';
                    }

                }
            }

            int count = 0;

            // Get the count of c's in the array
            for (int i = 0; i < board.GetLength(0); i++)
            {
                for (int j = 0; j < board.GetLength(1); j++)
                {
                    if (board[i, j] == 'o' || board[i,j] == 'c' || board[i,j] == 'x')
                        count++;
                }
            }

            // Map this count of clicked squares to the current board
            if (count == goalNum)
            {
                dictionary.Add(count, board);
                foundAnswer = true;
                return;
            }
            else if (count > goalNum)
            {
                boards.Add(board);
                return;
            }

            // Check if current board is in boards List

            bool hasBeenChecked = false;

            for (int i = 0; i < boards.Count(); i++)
            {
                bool isThisOne = true;
                char[,] oldBoard = boards[i];

                for (int j = 0; j < board.GetLength(0); j++)
                {

                    for (int k = 0; k < board.GetLength(1); k++)
                    {
                        if (oldBoard[j, k] != board[j, k])
                        {
                            isThisOne = false;
                            break;
                        }

                    }

                    if (!isThisOne)
                        break;
                }

                if (isThisOne)
                {
                    hasBeenChecked = true;
                    break;
                }
            }

            if (hasBeenChecked)
            {
                return;
            }

            boards.Add(board);

            // Call click on all 'o's in the array
            for (int i = 0; i < board.GetLength(0); i++)
            {
                for (int j = 0; j < board.GetLength(1); j++)
                {
                    if (board[i, j] == 'o')
                        Click(i, j, (char[,])board.Clone(), goalNum);
                }
            }
        }
    }
}
