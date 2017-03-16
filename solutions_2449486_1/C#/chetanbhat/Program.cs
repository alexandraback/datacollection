using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lawnmower
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var size = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s)).ToArray();
                var N = size[0];
                var M = size[1];

                var board = new int[N, M];
                for (int i = 0; i < N; i++)
                {
                    var line = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s)).ToArray();
                    for (int j = 0; j < M; j++)
                    {
                        board[i, j] = line[j];
                    }
                }
                var status = GetStatus(board, N, M);
                Console.WriteLine("Case #{0}: {1}", t + 1, status);
            }
        }

        static string GetStatus(int[,] board, int N, int M)
        {
            const string Yes = "YES";
            const string No = "NO";

            var rowMax = Enumerable.Range(0, N)
                            .Select(i => Enumerable.Range(0, M)
                                                    .Select(j => board[i, j])
                                                    .Max()).ToArray();

            var colMax = Enumerable.Range(0, M)
                            .Select(j => Enumerable.Range(0, N)
                                                    .Select(i => board[i, j])
                                                    .Max()).ToArray();

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    var val = board[i, j];
                    if (rowMax[i] != val && colMax[j] != val)
                    {
                        return No;
                    }
                }
            }

            return Yes;
        }
    }
}
