using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication4
{
    class Program
    {

        static bool putMines2(char[][] board, int R, int C, int M)
        {
            /*bool rotated = false;
            if (C > R)
            {
                board = RotateMatrix(board, R, C);
                rotated = true;

                int temp = C;
                C = R;
                R = temp;
            }
            */
            for (int i = 0; i < R - 2 && M > 0; i++)
            {
                for (int j = 0; j < C - 2 && M > 0; j++)
                {
                    board[i][j] = '*';
                    M--;
                }

                if (M > 1 && C >= 2)
                {
                    board[i][C - 2] = board[i][C - 1] = '*';
                    M -= 2;
                }
                else if (C == 1 && M > 0)
                {
                    board[i][0] = '*';
                    M--;
                }


            }

            if (M > 0)
            {
                if (C == 1)
                    for (int i = R - 2; i < R && M > 0; i++)
                    {
                        board[i][0] = '*';
                        M--;
                    }

                else if (R == 1)
                    for (int i = 0; i < C && M > 0; i++)
                    {
                        board[0][i] = '*';
                        M--;
                    }

                else if (M % 2 == 0 || M == C * 2 - 1 || M == C * 2 - 3)
                {
                    int rPlace = 0; 

                    for (int i = 0; i < C && M >= 2; i++)
                    {
                        board[R - 2][i] = '*';
                        board[R - 1][i] = '*';
                        M -= 2;
                        rPlace = i; 
                    }

                    if (M == 1)
                    {
                        board[R - 2][rPlace] = '*';
                        M--;
                    }

                }


            }
            return M == 0;
        }

        static char[][] RotateMatrix(char[][] matrix, int R, int C)
        {
            char[][] ret = new char[C][];

            for (int i = 0; i < C; i++)
            {
                ret[i] = new char[R];
                for (int j = 0; j < R; ++j)
                {
                    ret[i][j] = matrix[R - j - 1][i];
                }
            }

            return ret;
        }

        static char[][] RotateBackMatrix(char[][] matrix, int R, int C)
        {

            char[][] ret = new char[R][];

            for (int i = 0; i < R; i++)
            {
                ret[i] = new char[C];
                for (int j = 0; j < C; ++j)
                {
                    ret[i][j] = matrix[C - j - 1][i];
                }
            }

            return ret;
        }

        static bool putMines(char[][] board, int i, int j, int R, int C, int M)
        {
            if (M == 0)
                return true;

            if (C < 0 || R < 0)
                return false;


            if (C <= R)
            {
                for (int k = 0; k < C - 2 && M > 0; k++)
                {
                    board[i][j + k] = '*';
                    M--;
                }

                
                if (M >= 2 && C >= 2)
                {
                    if (R == 2 && M <C*2-1)
                        return false;

                    board[i][j + C - 1] = board[i][j + C - 2] = '*';
                    M -= 2;
                }
                else if ( M > 0)
                {
                    if (C == 1)
                    {
                        board[i][j] = '*';
                        M--;
                    }
                    else if (C == 2)
                    {
                        return false;
                    }
                }
            

                return putMines(board, i + 1, j, R - 1, C, M);
            }

            else
            {
                for (int k = 0; k < R - 2 && M > 0; k++)
                {
                    board[i+k][j] = '*';
                    M--;
                }

                if (M >=2  && R >= 2)
                {
                    if (C == 2 && M<R*2-1)
                        return false;

                    board[i+R-1][j] = board[i+R-2][j] = '*';
                    M -= 2;
                }
                else if (M >= 1)
                {
                    if (R == 1)
                    {
                        board[i][j] = '*';
                        M--;
                    }
                    else if (C == 2)
                    {
                        return false;
                    }
                }

                return putMines(board, i, j + 1, R, C - 1, M);
            }
        }

        static void printBoard(StreamWriter writer, char[][] board)
        {
            for (int i = 0; i < board.Length; i++)
            {
                for (int j = 0; j < board[i].Length; j++)
                    writer.Write(board[i][j]);
                writer.WriteLine();
            }
        }

        static void validate(string origin, string solution) {


            StreamReader originReader = new StreamReader(@"c:\users\alon\gcj\" + origin);
            StreamReader solutionReader = new StreamReader(@"c:\users\alon\gcj\" + solution);

            StreamWriter writer = new StreamWriter(@"c:\users\alon\gcj\" + solution + ".checked");


            int T = int.Parse(originReader.ReadLine());

            for (int i = 1; i <= T; i++)
            {

                solutionReader.ReadLine();
                string[] values = originReader.ReadLine().Split(' ');

                int R = int.Parse(values[0]);
                int C = int.Parse(values[1]);
                int M = int.Parse(values[2]);

                char[][] board = new char[R][];

                bool impossible = false;

                for (int j = 0; j < board.Length && ! impossible; j++)
                {
                    string line = solutionReader.ReadLine();

                    if (line.Contains("Imp")) 
                        impossible = true;

                    board[j] = line.ToCharArray();
                }


                

                writer.WriteLine("Case #{0}: ", i);

                if (!impossible)
                {
                    bool ok = checkBoard(board, R, C);
                    writer.WriteLine(ok ? "ok" : "baddd!!!!");
                }
                else
                    writer.WriteLine("impossible? {0}x{1}, {2}", R, C, M);

            }

            writer.Close();
        }

        static bool checkBoard(char[][] board, int R, int C)
        {
            markBoard(board, R, C, R - 1, C - 1);
            for(int i=0;i<R; i++)
                for(int j=0;j<C; j++)
                    if(board[i][j]=='.')
                        return false;
            return true;

        }

        static void markBoard(char[][] board, int R, int C, int i, int j)
        {
            if (i < 0 || j < 0 || i == R || j == C)
                return;

            if (board[i][j] != '.' && board[i][j] != 'c')
                return;

            int total =
                check(board, R, C, i - 1, j - 1) +
                check(board, R, C, i - 1, j) +
                check(board, R, C, i - 1, j + 1) +

                check(board, R, C, i, j - 1) +
                check(board, R, C, i, j + 1) +

                check(board, R, C, i + 1, j - 1) +
                check(board, R, C, i + 1, j) +
                check(board, R, C, i + 1, j + 1);

            board[i][j] = (char)('0' + total);

            if (total == 0)
            {
                markBoard(board, R, C, i - 1, j - 1);
                markBoard(board, R, C, i - 1, j);
                markBoard(board, R, C, i - 1, j + 1);
                markBoard(board, R, C, i, j - 1);
                markBoard(board, R, C, i, j + 1);
                markBoard(board, R, C, i + 1, j - 1);
                markBoard(board, R, C, i + 1, j);
                markBoard(board, R, C, i + 1, j + 1);
            }
        }

        static int check(char[][] board, int R, int C, int i, int j)
        {
            if (i < 0 || j < 0 || i == R || j == C)
                return 0;

            return (board[i][j] == '*') ? 1 : 0;
        }
        
        static void Main(string[] args)
        {
            string fileName = "C-small-attempt6";
            //validate(fileName + ".in", fileName + ".out");
            
            StreamReader reader = new StreamReader(@"c:\users\alon\gcj\" + fileName + ".in");
            StreamWriter writer = new StreamWriter(@"c:\users\alon\gcj\" + fileName + ".out");


            int T = int.Parse(reader.ReadLine());

            for (int i = 1; i <= T; i++)
            {

                string[] values = reader.ReadLine().Split(' ');

                int R = int.Parse(values[0]);
                int C = int.Parse(values[1]);
                int M = int.Parse(values[2]);

                char[][] board = new char[R][];

                for (int j = 0; j < board.Length; j++)
                {
                    board[j] = new char[C];

                    for (int k = 0; k < C; k++)
                        board[j][k] = '.';
                }



                writer.WriteLine("Case #{0}: ", i);

                try
                {


                    if (putMines(board, 0, 0, R, C, M))
                    {
                        board[R - 1][C - 1] = 'c';

                        printBoard(writer, board);
                    }
                    else writer.WriteLine("Impossible");

                }
                catch (Exception e)
                {
                    Console.WriteLine(i + " " + e.Message);
                }


            }

            writer.Close();
        }
    }
}
