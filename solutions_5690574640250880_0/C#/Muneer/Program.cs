using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace MinesweeperBruteForce
{
    class Program
    {
        static bool NextCombination(int[] comb,int N)
        {
            for (int i = comb.Length-1; i >=0; i--)
            {
                if (comb[i] + (comb.Length - i) >= N)
                {
                    if (comb[i] + (comb.Length - i) > N) throw new Exception();
                    continue;
                }
                else
                {
                    comb[i]++;
                    for (int j = i + 1; j < comb.Length; j++)
                    {
                        comb[j] = comb[j - 1] + 1;
                    }
                    return true;
                }

            }

            return false;
        }

        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\C-small-attempt1.in");
            StreamWriter sw = new StreamWriter("D:\\C-small-attempt1.out");

            //StreamReader sr = new StreamReader("D:\\C-large.in");
            //StreamWriter sw = new StreamWriter("D:\\C-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());
            
            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int R = Convert.ToInt32(str[0]);
                int C = Convert.ToInt32(str[1]);
                int M = Convert.ToInt32(str[2]);

                char[,] board = null;

                
                board = GetBoard(R, C, M);
                
                sw.Write("Case #{0}: ", i + 1);
                sw.WriteLine();
                if (board == null)
                {
                    sw.Write("Impossible");
                    sw.WriteLine();
                }
                else
                {
                    for (int j = 0; j < R; j++)
                    {
                        for (int k = 0; k < C; k++)
                        {
                            sw.Write(board[j, k]);
                        }
                        sw.WriteLine();
                    }
                }
                sw.Flush();

            }
            sw.Close();
        }

        static char[,] GetBoard(int R, int C, int M)
        {
            int[] comb = new int[M + 1];
            for (int i = 0; i < M + 1; i++)
            {
                comb[i] = i;
            }

            while (true)
            {
                if (comb.Length==4&& comb[0] == 0 && comb[1] == 3 && comb[2] == 4 && comb[3] == 5)
                {
                    int a = 10;
                }
                foreach (int start in comb)
                {
                    char[,] board = new char[R, C];

                    for (int j = 0; j < R; j++)
                    {
                        for (int k = 0; k < C; k++)
                        {
                            board[j, k] = 'd';
                        }
                    }

                    for (int j = 0; j < comb.Length; j++)
                    {
                        board[comb[j] / C, comb[j] % C] = '*';
                    }

                    board[start / C, start % C] = 'd';

                    if (CheckBoard(board, start) == true)
                    {
                        board[start / C, start % C] = 'c';
                        return board;
                    }

                    if (comb.Length == 4 && comb[0] == 0 && comb[1] == 3 && comb[2] == 4 && comb[3] == 5)
                    {
                        int a = 10;
                    }
                }

                if (NextCombination(comb, R * C) == false) break;
            }

            return null;   
        }

        static bool CheckBoard(char[,] board, int start)
        {
            int R = board.GetLength(0);
            int C = board.GetLength(1);

            Open(board, start / C, start % C);

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (board[i, j] == 'd') return false;
                }
            }

            return true;
        }

        static void Open(char[,] board, int r, int c)
        {
            board[r, c] = '.';

            if (r == 1 && c == 5)
            {
                int a = 10;
            }

            int R = board.GetLength(0);
            int C = board.GetLength(1);

            int numMinesNeighbours = 0;
            for (int i = r - 1; i <= r + 1; i++)
            {
                if (i < 0 || i >= R) continue;
                for (int j = c - 1; j <= c + 1; j++)
                {
                    if (j < 0 || j >= C) continue;
                    if (i == r && j == c) continue;

                    if (board[i, j] == '*')
                    {
                        numMinesNeighbours++;
                    }
                }

            }

            if (numMinesNeighbours == 0)
            {
                for (int i = r - 1; i <= r + 1; i++)
                {
                    if (i < 0 || i >= R) continue;
                    for (int j = c - 1; j <= c + 1; j++)
                    {
                        if (j < 0 || j >= C) continue;
                        if (i == r && j == c) continue;

                        if (board[i, j] == 'd')
                        {
                            Open(board, i, j);
                        }
                    }
                }
            }

        }

    }
}
