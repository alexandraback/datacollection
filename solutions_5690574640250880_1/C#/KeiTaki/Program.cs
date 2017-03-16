using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static string _folderPath = Directory.GetCurrentDirectory() + @"/../../Questions/";
        static string _question = "MinesweeperMaster";
        static string _dataSize = "L";   // T, S or L q

        static void Main(string[] args)
        {
            var data = File.ReadAllLines(_folderPath + _question + "_" + _dataSize + ".in");

            using (var outFile = File.CreateText(_folderPath + _question + "_" + _dataSize + ".out"))
            {
                Action<string> dualWriter = line =>
                {
                    Console.WriteLine(line);
                    outFile.WriteLine(line);
                };

                solve(data, dualWriter);
            }

            Console.WriteLine("Done!");
            Console.Read();
        }

        static void solve(IList<string> lines, Action<string> writeLine)
        {
            int numQs = int.Parse(lines[0]);

            int at = 1;

            for (int q = 0; q < numQs; q++)
            {
                // parse data here
                var seq = lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s)).ToList();

                writeLine(string.Format("Case #{0}:", q + 1));
                solve1(seq[0], seq[1], seq[2], writeLine);
            }
        }

        private static void solve1(int r, int c, int m, Action<string> writeLine)
        {
            bool flip = false;
            if (c < r)
            {
                var t = c;
                c = r;
                r = t;
                flip = true;
            }

            var grid = new List<List<char>>();
            for (int i = 0; i < r; i++)
            {
                grid.Add(new List<char>(Enumerable.Repeat('*', c)));
            }

            bool canDo = true;
            int noMine = r * c - m;

            if (noMine != 1)
            {
                if (r == 1)
                {
                    for (int j = 0; j < c - m; j++)
                    {
                        grid[0][j] = '.';
                    }
                }
                else if (r == 2)
                {
                    if (noMine >= 4 && m % 2 == 0)
                    {
                        for (int j = 0; j < (c - m / 2); j++)
                        {
                            grid[0][j] = '.';
                            grid[1][j] = '.';
                        }
                    }
                    else
                    {
                        canDo = false;
                    }
                }
                else
                {
                    if (noMine < 4 || noMine == 5 || noMine == 7)
                    {
                        canDo = false;
                    }
                    else
                    {
                        grid[0][0] = grid[0][1] = grid[1][0] = grid[1][1] = '.';
                        noMine -= 4;

                        if (noMine > 0)
                        {
                            grid[0][2] = grid[1][2] = '.';
                            noMine -= 2;

                            if (noMine > 0)
                            {
                                grid[2][0] = grid[2][1] = '.';
                                noMine -= 2;

                                if (noMine > 0)
                                {
                                    int rr = 3;
                                    int cc = 3;

                                    int rrr = 2;
                                    int ccc = 2;

                                    while (noMine > 0)
                                    {
                                        if ((rr == r && cc == c) || noMine == 1)
                                        {
                                            grid[rrr][ccc] = '.';
                                            noMine--;

                                            if (ccc == c - 1)
                                            {
                                                rrr++;
                                                ccc = 2;
                                            }
                                            else
                                            {
                                                ccc++;
                                            }
                                        }
                                        else
                                        {
                                            if (cc == c)
                                            {
                                                grid[rr][0] = grid[rr][1] = '.';
                                                rr++;
                                            }
                                            else
                                            {
                                                grid[0][cc] = grid[1][cc] = '.';
                                                cc++;
                                            }

                                            noMine -= 2;
                                        }
                                    }
                                }
                            }
                        }
                    }                    
                }
            }

            grid[0][0] = 'c';


            if (canDo)
            {
                if (flip)
                {
                    var grid2 = new List<List<char>>();
                    for (int i = 0; i < c; i++)
                    {
                        var row = new List<char>();
                        grid2.Add(row);
                        for (int j = 0; j < r; j++)
                        {
                            row.Add(grid[j][i]);
                        }
                    }

                    grid = grid2;
                }

                foreach (var row in grid)
                {
                    var sb = new StringBuilder();
                    foreach (var ch in row)
                    {
                        sb.Append(ch);
                    }

                    writeLine(sb.ToString());
                }
            }
            else
            {
                writeLine("Impossible");
            }
        }
    }
}


// var seq = lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => double.Parse(s)).ToList();