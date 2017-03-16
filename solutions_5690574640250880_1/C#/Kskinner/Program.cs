using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    public class Problem
    {
        int R, C, M;

        static bool random = false;
        static Random rand = new Random();

        public string Solve()
        {
            ReadData();

            Console.WriteLine("R C M = {0} {1} {2}", R, C, M);

            var grid = Grid();
            int startIndex = IsWinnable(grid);                
            if (startIndex != -1)
            {
                //PrintGrid(grid);
                return "\n" + GridString(grid, startIndex);
            }


            return "\nImpossible";
        }

        private void ReadData()
        {
            if (random)
            {
                R = rand.Next(50) + 1;
                C = rand.Next(50) + 1;
                M = rand.Next(R * C);
            }
            else
            {
                var ar = ReadArray<int>();
                R = ar[0];
                C = ar[1];
                M = ar[2];
            }
        }

        private int IsWinnable(int[][] grid)
        {
            if (R * C - M == 1)
            {
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        if (grid[i][j] != -1)
                            return i * C + j;
                    }
                }
                System.Diagnostics.Debug.Fail("BUG");
            }

            // Find a zero
            int a, b;
            if (!FindZero(grid, out a, out b))
                return -1;

            bool[] visited = new bool[R * C];
            var q = new Queue<int>();
            q.Enqueue(a * C + b);

            int numberVisited = 0;

            while (q.Count > 0)
            {
                var cell = q.Dequeue();
                if (visited[cell])
                    continue;
                visited[cell] = true;
                numberVisited++;
                int r = cell / C;
                int c = cell % C;
                if (grid[r][c] == 0)
                {
                    // Add neighbors to queue                
                    for (int k = -1; k <= 1; k++)
                        for (int l = -1; l <= 1; l++)
                        {
                            if (k == 0 && l == 0)
                                continue;
                            int rr = r + k;
                            int cc = c + l;
                            if (rr < 0 || rr >= R || cc < 0 || cc >= C)
                                continue;
                            if (grid[rr][cc] == -1 || visited[rr*C+cc])
                                continue;
                            q.Enqueue(rr * C + cc);
                        }
                }
            }

            if (numberVisited != R * C - M)
                return -1;
            else
                return a * C + b;
        }

        private bool FindZero(int[][] grid, out int a, out int b)
        {            
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (grid[i][j] == 0)
                    {
                        a = i;
                        b = j;
                        return true;
                    }
                }
            }
            a = -1; b = -1;
            return false;
        }        

        private void AddMine(int[][] grid, int r, int c)
        {
            grid[r][c] = -1;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (k == 0 && l == 0)
                        continue;
                    int rr = r + k;
                    int cc = c + l;
                    if (rr < 0 || rr >= R || cc < 0 || cc >= C)
                        continue;
                    if (grid[rr][cc] == -1)
                        continue;
                    grid[rr][cc]++;
                }
            }
        }

        private int[][] Grid()
        {
            var grid = new int[R][];
            for (int i = 0; i < R; i++)
            {
                grid[i] = new int[C];
            }

            if (M > 0)
            {
                int emptySquares = R * C - M;

                int blockLength;
                if (R == 1)
                {
                    blockLength = emptySquares;
                }
                else
                {
                    blockLength = Math.Min(C, emptySquares / 2);
                    if (blockLength * 2 + 1 == emptySquares)
                    {
                        blockLength--;
                    }
                }

                blockLength = Math.Max(1, blockLength);

                int remaining = emptySquares;
                for (int i = 0; i < R; i++)
                {
                    // Adjust blocklength
                    if (i > 1 && blockLength > 1 && blockLength + 1 == remaining)
                    {
                        blockLength--;
                    }

                    if (blockLength > remaining)
                        blockLength = remaining;
                    remaining -= blockLength;

                    // Add mines
                    for (int j = blockLength; j < C; j++)
                    {
                        AddMine(grid, i, j);
                    }
                }                
            }

            return grid;            
        }

        private void PrintGrid(int[][] grid)
        {
            var result = new StringBuilder();
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (grid[i][j] == -1)
                        result.Append('*');
                    else
                        result.Append(grid[i][j]);
                }
                result.AppendLine();
            }
            Console.WriteLine(result.ToString());
        }

        private string GridString(int[][] grid, int start)
        {
            var result = new StringBuilder();            
            for (int i = 0; i < R; i++)
            {
                if (i > 0) result.Append(Environment.NewLine);
                for (int j = 0; j < C; j++)
                {
                    if (grid[i][j] == -1)
                        result.Append('*');
                    else if (i*C+j == start)
                        result.Append('c');
                    else
                    {                        
                        result.Append('.');
                    }
                }                
            }
            return result.ToString();
        }        

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                if (random)
                {
                    T = 140;
                }
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Problem();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }
        }

        #region Readers

        private static string ReadLine()
        {
            return reader.ReadLine();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(ReadLine(), typeof(T));
        }

        private static T[] ReadArray<T>()
        {
            return ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToArray();
        }

        #endregion
    }
}
