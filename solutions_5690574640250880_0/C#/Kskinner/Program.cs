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

        public string Solve()
        {
            var ar = ReadArray<int>();
            R = ar[0];
            C = ar[1];
            M = ar[2];

            foreach (var grid in Grids())
            {
                int startIndex = IsWinnable(grid);
                if (startIndex != -1)
                {
                    //PrintGrid(grid);
                    return "\n" + GridString(grid, startIndex);
                }
            }


            return "\nImpossible";
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

        private IEnumerable<int[][]> Grids()
        {
            var indices = new List<int>();
            for (int i = 0; i < R * C; i++)
            {
                indices.Add(i);
            }

            foreach (var ch in Choose(indices, M))
            {
                var grid = new int[R][];
                for (int i = 0; i < R; i++)
                {
                    grid[i] = new int[C];
                }
                foreach (int index in ch)
                {
                    int r = index / C;
                    int c = index % C;
                    grid[r][c] = -1;
                    for(int k=-1;k<=1;k++)
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
                yield return grid;
            }
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
                result.AppendLine();
            }
            return result.ToString();
        }

        private IEnumerable<List<int>> Choose(List<int> elements, int k)
        {
            System.Diagnostics.Debug.Assert(k <= elements.Count);
            System.Diagnostics.Debug.Assert(k >= 0);

            if (k == 0)
                yield return new List<int>();
            else if (k == elements.Count)
                yield return elements;
            else
            {
                var tail = new List<int>(elements.Skip(1));

                // Choose
                int e = elements[0];
                foreach (var c in Choose(tail, k - 1))
                {
                    var result = new List<int>(c);
                    result.Add(e);
                    yield return result;
                }

                // Don't choose
                foreach (var c in Choose(tail, k))
                {
                    yield return c;
                }
            }
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
