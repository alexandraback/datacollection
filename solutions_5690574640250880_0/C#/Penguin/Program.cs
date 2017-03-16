using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace DeceitfulWar
{
    class Program
    {
     
        static void Main(string[] args)
        {
            Minesweeper(@"C:\Users\Yulin\Downloads\C-small-attempt3.in", @"C:\Users\Yulin\Downloads\C-small-attempt3.out");
        }

        private static void Minesweeper(string inputName, string outputName)
        {
            using (StreamReader sr = File.OpenText(inputName))
            {
                using (StreamWriter sw = new StreamWriter(File.OpenWrite(outputName)))
                {
                    int T = int.Parse(sr.ReadLine());

                    for (int i = 0; i < T; i++)
                    {

                        string line = sr.ReadLine();
                        string[] items = line.Split(new char[] { ' ' });
                        int R = int.Parse(items[0]);
                        int C = int.Parse(items[1]);
                        int M = int.Parse(items[2]);

                        Solve(R, C, M , sw , i+1);
                        //Solve(2, 2, 3, sw, i + 1);

                    }

                }
            }
        }

        private static void Solve(int R, int C, int M , StreamWriter sw , int num)
        {
            int[,] map = new int[R,C];

            if (Solve(map, 0, 0, M))
            {
                sw.WriteLine(String.Format("Case #{0}:", num));
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        if (i == startr && j == startc) sw.Write("c");
                        else
                        {
                            if (map[i, j] == 0) sw.Write(".");
                            if (map[i, j] == 1) sw.Write("*");
                        }
                    }
                    sw.WriteLine();
                }
            }
            else
            {
                sw.WriteLine(String.Format("Case #{0}:", num));
                sw.WriteLine(String.Format("Impossible"));
                
            }

        }

        private static bool Solve(int[,] map, int last, int placed , int total)
        {
            if (last >= map.GetLength (1) * map.GetLength(0)) return false;
            if (placed == total)
            {
                return GoodSolution(map , total);
            }

            int c = last / map.GetLength(0);
            int r = last % map.GetLength(0);

            map[r , c] = 1;
            if (Solve(map, last + 1, placed + 1, total))
                return true;

            map[r, c] = 0;
            return Solve(map, last + 1, placed, total);
        }

        private static int startr;
        private static int startc;


        private static bool GoodSolution(int[,] map , int total)
        {
            if (total >= map.GetLength(0) * map.GetLength(1) - 1)
            {
                if (total >= map.GetLength(0) * map.GetLength(1))
                {
                    startr = -1;
                    startc = -1;
                }
                else
                {
                    for (int i = 0; i < map.GetLength(0); i++)
                    {
                        for (int j = 0; j < map.GetLength(1); j++)
                        {
                            if (map[i, j] == 0)
                            {
                                startr = i;
                                startc = j;
                                return true;
                            }
                        }
                    }
                }
                return true;
            }

            for (int i = 0; i < map.GetLength(0); i++)
            {
                for (int j = 0; j < map.GetLength(1); j++)
                {
                    if (map[i, j] == 0)
                    {
                        if (IsGOodPoint(map, i, j))
                        {
                            int c = GetTotalPoint(map, i, j);
                            if (c == total)
                            {
                                startr = i;
                                startc = j;
                                return true;
                            }
                        }
                    }

                }
            }
            
            return false;
        }

        private static int[] dc = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 };
        private static int[] dr = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 };

        private static int GetTotalPoint(int[,] map, int i, int j)
        {
            int total = map.GetLength(0) * map.GetLength(1);
            int[,] map2 = new int[map.GetLength(0), map.GetLength(1)];
            Queue<int> row = new Queue<int>();
            Queue<int> col = new Queue<int>();
            row.Enqueue(i);
            col.Enqueue(j);
            map2[i, j] = 2;


            while (row.Count != 0)
            {
                int r = row.Dequeue();
                int c = col.Dequeue();
                total--;
                if (IsGOodPoint(map, r, c))
                {
                    for (int n = 0; n < 8; n++)
                    {
                        int nr = r + dr[n];
                        int nc = c + dc[n];
                        if (nr >= 0 && nr < map.GetLength(0) && nc >= 0 && nc < map.GetLength(1))
                        {
                            if (map2[nr, nc] == 0)
                            {
                                map2[nr, nc] = 2;
                                row.Enqueue(nr);
                                col.Enqueue(nc);
                            }
                        }
                    }
                }
            }
            return total;

        }

        private static bool IsGOodPoint(int[,] map, int i, int j)
        {
            for (int n = 0; n < 8; n++)
            {
                int nx = i + dr[n];
                int ny = j + dc[n];
                if (nx < 0 || ny < 0 || nx >= map.GetLength(0) || ny >= map.GetLength(1)) continue;
                if (map[nx, ny] == 0) continue;
                return false;
            }
            return true;
        }

        
    }
}
