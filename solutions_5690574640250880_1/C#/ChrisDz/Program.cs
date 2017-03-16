using System;
using System.Data;
using System.IO;
using System.Linq;
using System.Text;

namespace Google.CodeJam
{
    class Program
    {
        private static string BoardToString(char[][] board)
        {
            var stringBuilder = new StringBuilder();
            foreach (var row in board)
            {
                foreach (var ch in row)
                {
                    stringBuilder.Append(ch);
                }
                stringBuilder.AppendLine();
            }
            return stringBuilder.ToString().TrimEnd('\r', '\n');
        }

        private static char[][] GetBlankBoard(int r, int c)
        {
            var board = new char[r][];
            for (int i = 0; i < r; i++)
            {
                board[i] = Enumerable.Repeat('.', c).ToArray();
            }
            return board;
        }

        private static void Solve(int id, TextReader reader, TextWriter writer)
        {
            var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int r = line[0], c = line[1], m = line[2];

            var board = GetBlankBoard(r, c);

            board[0][0] = 'c';

            // Fill all but the top two rows
            for (int row = r - 1; row > 1 && m > 0; row--)
            {
                if (m < c)
                {
                    int n = Math.Min(m, c - 2);
                    board[row] = Enumerable.Repeat('.', c - n).Concat(Enumerable.Repeat('*', n)).ToArray();
                    m -= n;
                }
                else
                {
                    board[row] = Enumerable.Repeat('*', c).ToArray();
                    m -= c;
                }
            }

            // Fill the top two rows if possible
            if (r > 1)
            {
                for (int col = c - 1; col > 1 && m > 1; col--)
                {
                    board[0][col] = '*';
                    board[1][col] = '*';
                    m -= 2;
                }

                if (m == 3 && c > 1)
                {
                    board[0][1] = '*';
                    board[1][0] = '*';
                    board[1][1] = '*';
                    m -= 3;
                }
            }

            // Steal from the third row to fill the top row if possible and necessary
            if (r > 2 && m == 1)
            {
                int colToPut = board[1].Count(ch => ch == '.') - 1;
                int colToTake = board[2].Count(ch => ch == '.');

                if (colToTake != 0 && colToTake < colToPut)
                {
                    board[2][colToTake] = '.';
                    board[0][colToPut] = '*';
                    board[1][colToPut] = '*';
                    m -= 1;
                }
                else if (colToTake + 3 <= colToPut - 1)
                {
                    board[2][colToTake] = '.';
                    board[2][colToTake + 1] = '.';
                    board[2][colToTake + 2] = '.';
                    board[0][colToPut - 1] = '*';
                    board[1][colToPut - 1] = '*';
                    board[0][colToPut] = '*';
                    board[1][colToPut] = '*';
                    m -= 1;
                }
            }

            // Handle the one-row case
            if (r == 1)
            {
                int n = Math.Min(m, c - 1);
                board[0] = Enumerable.Repeat('c', 1).Concat(Enumerable.Repeat('.', c - n - 1)).Concat(Enumerable.Repeat('*', n)).ToArray();
                m -= n;
            }

            // Handle the one-column case
            if (c == 1 && r > 1 && m == 1 && board[1][0] == '.')
            {
                board[1][0] = '*';
                m -= 1;
            }

            if (m == 0)
            {
                writer.WriteLine("Case #{0}:\r\n{1}", id, BoardToString(board));
            }
            else
            {
                writer.WriteLine("Case #{0}:\r\n{1}", id, "Impossible");
            }
        }

        private static void Main(string[] args)
        {
            try
            {
                var inputPath = args[0];
                var outputPath = args[1];

                using (var reader = new StreamReader(inputPath))
                using (var writer = new StreamWriter(outputPath))
                {
                    int count = int.Parse(reader.ReadLine());
                    for (int i = 0; i < count; i++)
                        Solve(i + 1, reader, writer);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
