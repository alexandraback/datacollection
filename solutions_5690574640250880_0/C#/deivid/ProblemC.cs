using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    public class ProblemC : ProblemBase
    {
        public ProblemC(string fileName)
            : base(fileName)
        {
        }

        protected override string SolveCase()
        {
            var info = ReadIntArray();
            int R = info[0];
            int C = info[1];
            int M = info[2];

            char[,] board = FillBoard(R, C, M);
            ResolveBoard(board, R, C, R - 1, C - 1);
            board[R - 1, C - 1] = 'c';
            if (VerifyBoard(board, R, C))
                return PrintBoard(board, R, C);
            else
                return "\nImpossible";
        }

        private char[,] FillBoard(int R, int C, int M)
        {
            char[,] board = new char[R, C];
            int row = 0;
            int col = 0;
            while (M > 0)
            {
                if (M >= (R - row) || M >= (C - col))
                {
                    // Fill entire row or colum
                    if (R - row >= C - col)
                    {
                        for (int i = col; i < C; i++)
                            board[row, i] = '*';
                        M -= C - col;
                        row++;
                    }
                    else
                    {
                        for (int i = row; i < R; i++)
                            board[i, col] = '*';
                        M -= R - row;
                        col++;
                    }
                }
                else
                {
                    if (col < C - 2)
                    {
                        for (int i = col; i < C - 2; i++)
                        {
                            board[row, i] = '*';
                            M--;
                            if (M == 0) break;
                        }
                        row++;
                    }
                    if (M > 0)
                    {
                        for (int i = row; i < R; i++)
                        {
                            board[i, col] = '*';
                            M--;
                            if (M == 0) break;
                        }
                    }
                }
            }
            return board;
        }

        private void ResolveBoard(char[,] board, int R, int C, int row, int column)
        {
            int result = ResolveCell(board, R, C, row, column);
            if (result >= 0)
                board[row, column] = result.ToString().ToCharArray()[0];
            if (result == 0)
            {
                ResolveBoard(board, R, C, row - 1, column - 1);
                ResolveBoard(board, R, C, row - 1, column);
                ResolveBoard(board, R, C, row, column - 1);
            }
        }

        private int ResolveCell(char[,] board, int R, int C, int row, int column)
        {
            if (row < 0 || column < 0 || row >= R || column >= C || board[row,column] == '*')
                return -1;

            return IsMine(board, R, C, row - 1, column - 1) + IsMine(board, R, C, row - 1, column) + IsMine(board, R, C, row - 1, column + 1) +
                   IsMine(board, R, C, row, column - 1) + IsMine(board, R, C, row, column + 1) +
                   IsMine(board, R, C, row + 1, column - 1) + IsMine(board, R, C, row + 1, column) + IsMine(board, R, C, row + 1, column + 1);
        }

        private int IsMine(char[,] board, int R, int C, int row, int column)
        {
            if (row >= 0 && row < R && column >= 0 && column < C && board[row, column] == '*')
                return 1;
            else
                return 0;
        }

        private bool VerifyBoard(char[,] board,int R, int C)
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (board[i, j] == 0)
                        return false;
                }
            }
            return true;
        }

        private string PrintBoard(char[,] board, int R, int C)
        {
            var result = new StringBuilder();
            result.AppendLine();
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    char c = board[i,j];
                    result.Append(c == '*' || c == 'c' ? c : '.');
                }
                if (i < R -1) result.AppendLine();
            }
            return result.ToString();
        }
    }
}
