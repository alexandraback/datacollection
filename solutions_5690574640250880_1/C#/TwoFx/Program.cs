using System;
using System.Linq;
using System.IO;
using System.Text;

namespace _20140_Minesweeper_Master
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {
            Console.WriteLine(solveCase(() => "4 5 16"));
        }

        static string solveCase(Func<string> readLine)
        {
            int[] rcm = readLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            char[][] field = new char[rcm[0]][];

            for (int i = 0; i < rcm[0]; i++)
            {
                field[i] = new char[rcm[1]];
                for (int j = 0; j < rcm[1]; j++)
                {
                    field[i][j] = '.';
                }
            }
            int rows = rcm[0];
            int cols = rcm[1];
            int rM = rcm[2];
            int orm;

            do
            {
                orm = rM;
               if (rows > cols)
                {
                    rows -= removeRows(field, rows, cols, ref rM, true);
                    cols -= removeCols(field, rows, cols, ref rM, false);
                }
                else
                {
                    cols -= removeCols(field, rows, cols, ref rM, true);
                    rows -= removeRows(field, rows, cols, ref rM, false);
                }
            } while (rM < orm);
            if (rM == rows * cols - 1)
            {
                for (int x = 0; x < rows; x++)
                {
                    for (int y = 0; y < cols; y++)
                    {
                        field[x][y] = '*';
                    }
                }
                field[0][0] = 'c';
                return makeResult(field);
            }
            do
            {
                orm = rM;
                for (int x = rows - 1; x >= 0; x--)
                {
                    for (int y = cols - 1; y >= 0; y--)
                    {
                        if (rM > 0 && validatePosition(field, x, y))
                        {
                            Console.WriteLine("Succeeded {0} {1}", x, y);
                            field[x][y] = '*';
                            rM--;
                        }
                        else
                        {
                            Console.WriteLine("Failed {0} {1}", x, y);
                        }
                    }
                }
            } while (rM < orm && rM > 0);
            if (rM == 0)
            {
                bool b = false;
                for (int x = rows - 1; x >= 0; x--)
                {
                    for (int y = cols - 1; y >= 0; y--)
                    {
                        if (countNeighbourMines(field, x, y) == 0)
                        {
                            char[][] cfield = field.Select(c => (char[])c.Clone()).ToArray();
                            if (resolveRecursive(cfield, x, y).Any(l => l.Contains('.')))
                            {
                                Console.WriteLine(makeResult(cfield));
                                return Environment.NewLine + "Impossible";
                            }
                            field[x][y] = 'c';
                            b = true;
                            break;
                        }
                    }
                    if (b) break;
                }
                Console.WriteLine(rM);
                if (b)
                {
                    return makeResult(field);
                }
                else return Environment.NewLine + "Impossible";
            }
            else
            {
                return Environment.NewLine + "Impossible";
            }
        }

        static bool validatePosition(char[][] field, int x, int y)
        {
            if (field[x][y] == '*') return false;
            int[][] dir = new[] { new[] { 0, -1 }, new[] { 0, 1 }, new[] { -1, 0 }, new[] { 1, 0 } };
            for (int d = 0; d < 4; d++)
            {
                if (!bad(field, x + dir[d][0], y + dir[d][1]) && bad(field, x + 2 * dir[d][0], y + 2 * dir[d][1]))
                {
                    return false;
                }
            }
            //for (int ox = -1; ox <= 1; x += 2)
            //{
            //    for (int oy = -1; oy <= 1; y += 2)
            //    {
            //        if (bad(field, x + ox, y + oy))
            //        {
            //            return false;
            //        }
            //    }
            //}
                return true;
        }

        static bool bad(char[][] field, int x, int y)
        {
            return isout(field, x, y) || mine(field, x, y);
        }

        static bool isout(char[][] field, int x, int y)
        {
            return x < 0 || y < 0 || x >= field.Length || y >= field[0].Length;
        }

        static bool mine(char[][] field, int x, int y)
        {
            return field[x][y] == '*';
        }

        static char[][] resolveRecursive(char[][] field, int cx, int cy)
        {
            field[cx][cy] = 'r';

            if (countNeighbourMines(field, cx, cy) == 0)
            {
                for (int ox = cx - 1; ox <= cx + 1; ox++)
                {
                    for (int oy = cy - 1; oy <= cy + 1; oy++)
                    {
                        if (ox >= 0 && ox < field.Length && oy >= 0 && oy < field[0].Length && field[ox][oy] != 'r') field = resolveRecursive(field, ox, oy);              
                    }
                }
            }
            return field;
        }

        static int countNeighbourMines(char[][] field, int x, int y)
        {
            int count = 0;
            for (int ox = x - 1; ox <= x + 1; ox++)
            {
                for (int oy = y - 1; oy <= y + 1; oy++)
                {
                    if (ox >= 0 && ox < field.Length && oy >= 0 && oy < field[0].Length && field[ox][oy] == '*') count++;
                }
            }
            return count;
        }

        static int removeRows(char[][] field, int rNum, int cNum, ref int rM, bool first)
        {
            int num = Math.Min(Math.Max(0, rNum - 2), rM / cNum);
            bool willBeClean = false;
            if (first)
            {
                int predRM = rM - (cNum * num);
                int newNum = Math.Min(Math.Max(0, cNum - 2), rM / (rNum - num));
                willBeClean = predRM - newNum * (rNum - num) * num == 0;
            }
            else
            {
                willBeClean = rM - (cNum * num) == 0;
            }
            if (num == rNum - 2 && !willBeClean && num > 0) num--;
            for (int r = rNum - 1; r >= rNum - num; r--)
            {
                for (int c = 0; c < cNum; c++)
                {
                    field[r][c] = '*';
                }
            }
            rM -= cNum * num;
            return num;
        }

        static int removeCols(char[][] field, int rNum, int cNum, ref int rM, bool first)
        {
            int num = Math.Min(Math.Max(0, cNum - 2), rM / rNum);
            bool willBeClean = false;
            if (first)
            {
                int predRM = rM - (rNum * num);
                int newNum = Math.Min(Math.Max(0, rNum - 2), rM / (cNum - num));
                willBeClean = predRM - newNum * (cNum - num) * num == 0;
            }
            else
            {
                willBeClean = rM - (rNum * num) == 0;
            }
            if (num == cNum - 2 && !willBeClean && num > 0) num--;
            for (int r = 0; r < rNum; r++)
            {
                for (int c = cNum - 1; c >= cNum - num; c--)
                {
                    field[r][c] = '*';
                }
            }
            rM -= rNum * num;
            return num;
        }

        static string makeResult(char[][] inp)
        {
            StringBuilder sb = new StringBuilder();
            foreach (char[] line in inp)
            {
                sb.Append(Environment.NewLine);
                sb.Append(new string(line));
            }
            return sb.ToString();
        }

        static void Main(string[] args)
       {
            Console.BufferHeight = 10000;
            if (DEBUG)
            {
                debug();
            }
            else
            {
                GCJ.Initialize();
                GCJ.SolveAll(solveCase);
            }
            Console.ReadKey();
        }
    }

    static class GCJ
    {
        private static StreamReader inf;
        private static StreamWriter outf;

        private delegate void o(string format, params object[] args);
        private static o Output;

        public static void Initialize()
        {
            Console.Write("Input file: ");
            inf = new StreamReader(Console.ReadLine());
            Console.Write("Output file: ");
            outf = new StreamWriter(Console.ReadLine());
            Output = Console.WriteLine;
            Output += outf.WriteLine;
        }

        public static void SolveAll(Func<Func<string>, string> calc)
        {
            int cases = int.Parse(inf.ReadLine());
            for (int @case = 1; @case <= cases; @case++)
            {
                Output("Case #{0}: {1}", @case, calc(inf.ReadLine));
            }
            inf.Close();
            outf.Close();
            Console.WriteLine("Eureka!");
        }
    }
}
