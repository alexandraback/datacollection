using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code
{
    class Program
    {
        const string root = @"B:\Users\Justin\Desktop\Temp\Google Code\Problem 3\";
        static void Main(string[] args)
        {
            var reader = new StreamReader(root + "in.txt");
            var writer = new StreamWriter(root + "out.txt", false);

            int numCases = int.Parse(reader.ReadLine());
            for (int cc = 1; cc <= numCases; cc++)
            {
                int[] inputs = reader.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
                string result = Board(inputs[0], inputs[1], inputs[2]);

                Console.WriteLine(string.Format("Case #{0}:", cc));
                Console.Write(result);
                
                writer.WriteLine(string.Format("Case #{0}:", cc));
                writer.Write(result);
            }

            writer.Flush();
            writer.Close();
            Console.ReadKey();
        }

        static string Board(int rows, int columns, int mines)
        {
            int totalBoxes = rows * columns;
            int neededSpaces = totalBoxes - mines;            


            int[][] board = new int[rows][];            

            for (int ay = 0; ay < rows; ay++)
            {
                board[ay] = new int[columns];
            }

            if (neededSpaces == 1)
            {
                board[0][0] = 1;
                return board.ToStr();
            }


            int y = 0;
            int x = 0;
            int bindingX = 0;
            int bindingY = 0;
            int openSpaces = 0;
            bool anyPlaceToMove = true;
            while (anyPlaceToMove)
            {
                int bx, by;

                // start with the right most and move down
                bx = bindingX;
                for (by = 0; by < bindingY; by++)
                {
                    openSpaces += board.Mark(bx, by, rows, columns, true);
                    //board.Display();

                    if (neededSpaces - openSpaces < 0)
                    {
                        return "Impossible" + Environment.NewLine;
                    }
                    else if (neededSpaces - openSpaces == 0)
                        return board.ToStr();
                    else if (neededSpaces - openSpaces == 2)
                    {
                        bool found = Mark2Pointer(board);
                        if (found)
                            return board.ToStr();
                    }
                }

                // go all the way across on the bottom
                by = bindingY;
                for (bx = 0; bx <= bindingX; bx++)
                {
                    openSpaces += board.Mark(bx, by, rows, columns, true);
                    //board.Display();

                    if (neededSpaces - openSpaces < 0)
                    {
                        return "Impossible" + Environment.NewLine;
                    }
                    else if (neededSpaces - openSpaces == 0)
                        return board.ToStr();
                    else if (neededSpaces - openSpaces == 2)
                    {
                        bool found = Mark2Pointer(board);
                        if (found)
                            return board.ToStr();
                    }
                }

                anyPlaceToMove = false;
                if (bindingX < columns - 2)
                {
                    anyPlaceToMove = true;
                    bindingX++;
                }

                if (bindingY < rows - 2)
                {
                    anyPlaceToMove = true;
                    bindingY++;
                }

            }
            Console.ReadLine();
            return "a";
        }

        static bool Mark2Pointer(int[][] board)
        {
            for (int y = 0; y < board.Length; y++)
            {
                for (int x = 0; x < board[y].Length; x++)
                {
                    if (board[y][x] == 1)
                    {
                        int numChecked = board.Mark(x, y, board.Length, board[y].Length, false);
                        if (numChecked == 2)
                        {
                            board.Mark(x, y, board.Length, board[y].Length, true);
                            return true;
                        }

                    }
                }
            }
            return false;
        }

    }

    public static class A
    {
        public static void Display(this int[][] board)
        {
            int numOpen = 0;
            for (int y = 0; y < board.Length; y++)
            {
                for (int x = 0; x < board[y].Length; x++)
                {
                    if (board[y][x] == 1)
                    {
                        if (y == 0 && x == 0)
                            Console.Write('c');
                        else
                            Console.Write('.');
                        numOpen++;
                    }
                    else if (board[y][x] == 0)
                        Console.Write('*');
                }
                Console.WriteLine();
            }
            Console.WriteLine("Num Open: " + numOpen);
            Console.WriteLine();
        }

        public static string ToStr(this int[][] board)
        {
            StringBuilder builder = new StringBuilder();
            for (int y = 0; y < board.Length; y++)
            {
                for (int x = 0; x < board[y].Length; x++)
                {
                    if (board[y][x] == 1)
                    {
                        if (y == 0 && x == 0)
                            builder.Append('c');
                        else
                            builder.Append('.');
                    }
                    else if (board[y][x] == 0)
                        builder.Append('*');
                }
                builder.AppendLine();
            }
            return builder.ToString();
        }


        public static int Mark(this int[][] board, int cx, int cy, int rows, int columns, bool mark)
        {
            int numMarked = 0;
            for (int x = cx - 1; x < cx + 2; x++)
            {
                for (int y = cy - 1; y < cy + 2; y++)
                {
                    if (x >= 0 && x < columns && y >= 0 && y < rows)
                    {
                        if (board[y][x] == 0)
                        {
                            if (mark)
                                board[y][x] = 1;
                            numMarked++;
                        }
                    }

                }
            }
            return numMarked;
        }
    }
}
