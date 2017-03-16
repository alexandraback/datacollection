using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {

            var root = @"D:\gcj\p3\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");


            int[] data = input.SelectMany(x => x.Split(' ').Select(y => Int32.Parse(y))).ToArray();
            IEnumerator<int> scanner = data.AsEnumerable<int>().GetEnumerator();
            scanner.MoveNext();
            int numCases = scanner.Current;

            char[,] res = new char[50, 50];
            
            for (int nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                int R = scanner.Current;
                scanner.MoveNext();
                int C = scanner.Current;
                scanner.MoveNext();
                int M = scanner.Current;

                Console.WriteLine("Doing {0} {1} {2}", R, C, M);

                int add = R * C - M;
                System.Diagnostics.Debug.Assert(add > 0);

                int finalR = 0;
                int finalC = 0;
                int finalRA = 0;
                int finalCA = 0;
                if (add == 1)
                {
                    finalR = 1;
                    finalC = 1;
                }
                else
                {

                    for (int i = 1; i < 51; ++i)
                    {
                        for (int j = 1; j < 51; ++j)
                        {
                            // Does the rectangle really fit?
                            if (i > R || j > C)
                            {
                                continue;
                            }

                            // Edge cases
                            if ((i == 1 && R != 1) || (j == 1 && C != 1))
                            {
                                continue;
                            }

                            // Perfect rectangle
                            if (i * j == add)
                            {
                                finalR = i;
                                finalC = j;
                                break;
                            }

                            // OPT
                            int left = add - i * j;
                            if (left > i + j || left < 0)
                            {
                                continue;
                            }

                            // Add garbage edges
                            for (int l1 = 0; l1 < j; ++l1)
                            {
                                for (int l2 = 0; l2 < i; ++l2)
                                {
                                    if (l1 + l2 != left)
                                    {
                                        continue;
                                    }

                                    if (l1 > 0 && i == R)
                                    {
                                        continue;
                                    }

                                    if (l2 > 0 && j == C)
                                    {
                                        continue;
                                    }

                                    if (l1 == 1)
                                    {
                                        continue;
                                    }

                                    if (l2 == 1)
                                    {
                                        continue;
                                    }

                                    finalR = i;
                                    finalC = j;
                                    finalRA = l1;
                                    finalCA = l2;
                                    break;
                                }

                                if (finalRA > 0 || finalCA > 0)
                                {
                                    break;
                                }
                            }

                            if (finalRA > 0 || finalCA > 0)
                            {
                                break;
                            }

                        }

                        if (finalR > 0)
                        {
                            break;
                        }
                    }

                }
                output.WriteLine("Case #{0}:", nc + 1);

                if (finalR == 0)
                {
                    output.WriteLine("Impossible");
                }
                else
                {
                    for (int i = 0; i < R; ++i)
                    {
                        for (int j = 0; j < C; ++j)
                        {
                            if (i == 0 && j == 0)
                            {
                                output.Write('c');
                                res[i, j] = 'c';
                            }
                            else if ((i < finalR || (i == finalR && j < finalRA))
                                && (j < finalC || (j == finalC && i < finalCA)))
                            {
                                output.Write('.');
                                res[i, j] = '.';
                            }
                            else
                            {
                                output.Write('*');
                                res[i, j] = '*';
                            }
                        }
                        output.Write("\n");
                    }

                    // Random validation
                    bool[,] zeros = new bool[50, 50];
                    int numMines = 0;

                    for (int i = 0; i < R; ++i)
                    {
                        for (int j = 0; j < C; ++j)
                        {
                            if (res[i, j] == '*') { numMines++; continue; }
                            if (i > 0 && res[i - 1, j] == '*') continue;
                            if (i > 0 && j > 0 &&  res[i - 1, j - 1] == '*') continue;
                            if (i > 0 && j < C - 1 && res[i - 1, j + 1] == '*') continue;
                            if (i < R - 1 && res[i + 1, j] == '*') continue;
                            if (i < R - 1 && j > 0 && res[i + 1, j - 1] == '*') continue;
                            if (i < R - 1 && j < C - 1 && res[i + 1, j + 1] == '*') continue;
                            if (j < C - 1 && res[i, j + 1] == '*') continue;
                            if (j > 0 && res[i, j - 1] == '*') continue;
                            zeros[i, j] = true;
                        }
                    }
                    System.Diagnostics.Debug.Assert(numMines == M);

                    bool[,] vis = new bool[50, 50];
                    Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
                    queue.Enqueue(new Tuple<int, int>(0, 0));
                    vis[0, 0] = true;
                    int numVis = 0;
                    while (queue.Count > 0)
                    {
                        var q = queue.Dequeue();
                        
                        numVis++;
                        bool visNeighbours = true;

                        for (int i = q.Item1 - 1; i <= q.Item1 + 1; ++i)
                        {
                            for (int j = q.Item2 - 1; j <= q.Item2 + 1; ++j)
                            {
                                if (i < 0 || i >= R || j < 0 || j >= C)
                                {
                                    continue;
                                }
                                if (res[i, j] == '*')
                                {
                                    visNeighbours = false;
                                }
                            }
                        }

                        if(visNeighbours)
                        {
                            for (int i = q.Item1 - 1; i <= q.Item1 + 1; ++i)
                            {
                                for (int j = q.Item2 - 1; j <= q.Item2 + 1; ++j)
                                {
                                    if (i < 0 || i >= R || j < 0 || j >= C || vis[i, j] == true || res[i, j] == '*')
                                    {
                                        continue;
                                    }
                                    queue.Enqueue(new Tuple<int, int>(i, j));
                                    vis[i, j] = true;
                                }
                            }
                        }
                    }
                    System.Diagnostics.Debug.Assert(numVis == R*C - M);

                }


            }

            output.Close();

            Console.WriteLine(File.ReadAllText(root + "out.txt"));
        }
    }
}
