using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJMinesweeper
{
    class Program
    {
        private static class InputParser
        {
            private static string ReadLine()
            {
                var lineStr = Console.ReadLine();
                if (string.IsNullOrEmpty(lineStr))
                    throw new Exception("Missing line");
                return lineStr;
            }

            private static int ParseIntFromStr(string str)
            {
                int result;
                if (!int.TryParse(str, out result))
                    throw new Exception(string.Format("Invalid str: {0}", str));
                return result;
            }

            public static int ReadLineInt()
            {
                var lineStr = ReadLine();

                return ParseIntFromStr(lineStr);
            }

            private static IEnumerable<string> ReadLineFragments()
            {
                return ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }

            public static IEnumerable<int> ReadLineInts()
            {
                return ReadLineFragments().Select(ParseIntFromStr);
            }
        }


        static void Main(string[] args)
        {
            var testCases = InputParser.ReadLineInt();

            for (var test = 1; test <= testCases; ++test)
            {
                var input = InputParser.ReadLineInts().ToArray();
                if (input.Length != 3)
                    throw new Exception("Input length: " + input.Length);
                var map = Solve(input[0], input[1], input[2]);
                Console.WriteLine("Case #{0}:", test);
                if (map == null)
                    Console.WriteLine("Impossible");
                else
                    Print(map);
            }
        }

        private static void Print(char[,] map)
        {
            for (var r = 0; r < map.GetLength(0); ++r)
            {
                for (var c = 0; c < map.GetLength(1); ++c)
                {
                    Console.Write(map[r,c]);
                }
                Console.WriteLine();
            }
        }

        private static bool PlaceMines(char[,] map, int fromR, int fromC, int M)
        {
            if (M == 0)
                return true;

            if (map.GetLength(0) - fromR > map.GetLength(1) - fromC)
            {
                for (var c = fromC; c < map.GetLength(1); ++c)
                {
                    if (M == 1 && c + 2 == map.GetLength(1) && fromR + 1 < map.GetLength(0))
                    {
                        map[fromR + 1, fromC] = '*';
                        return true;
                    }

                    map[fromR, c] = '*';
                    --M;
                    if (M == 0)
                        return true;
                }
                fromR++;
            }
            else
            {
                for (var r = fromR; r < map.GetLength(0); ++r)
                {
                    if (M == 1 && r + 2 == map.GetLength(0) && fromC + 1 < map.GetLength(1))
                    {
                        map[fromR, fromC + 1] = '*';
                        return true;
                    }

                    map[r, fromC] = '*';
                    --M;
                    if (M == 0)
                        return true;
                }
                fromC++;
            }

            return PlaceMines(map, fromR, fromC, M);
        }


        private static char[,] Solve(int R, int C, int M)
        {
            var map = new char[R, C];
            for (var r = 0; r < R; ++r)
                for (var c = 0; c < C; ++c)
                    map[r, c] = '.';

            if (!PlaceMines(map, 0, 0, M))
                return null;

            for (var r = 0; r < R; ++r)
            {
                for (var c = 0; c < C; ++c)
                {
                    if (map[r, c] == '.')
                    {
                        var clone = (char[,]) map.Clone();

                        if (StartAt(clone, r, c) + M == R*C)
                        {
                            map[r, c] = 'c';
                            return map;
                        }
                    }
                }
            }
            return null;
        }

        private static int StartAt(char[,] map, int startR, int startC)
        {
            map[startR, startC] = '#';

            var cnt = CountMinesAround(map, startR, startC);
            if (cnt > 0)
                return 1;

            var total = 1;

            for (var dr = -1; dr <= 1; ++dr)
            {
                for (var dc = -1; dc <= 1; ++dc)
                {
                    if (dc == 0 && dr == 0)
                        continue;

                    var r = startR + dr;
                    var c = startC + dc;

                    if (r >= 0 && r < map.GetLength(0) && c >= 0 && c < map.GetLength(1))
                    {
                        if (map[r, c] == '.')
                        {
                            total += StartAt(map, r, c);
                        }
                    }
                }
            }
            return total;
        }

        private static int CountMinesAround(char[,] map, int currR, int currC)
        {
            var cnt = 0;

            for (var dr = -1; dr <= 1; ++dr)
            {
                for (var dc = -1; dc <= 1; ++dc)
                {
                    if (dc == 0 && dr == 0)
                        continue;

                    var r = currR + dr;
                    var c = currC + dc;

                    if (r >= 0 && r < map.GetLength(0) && c >= 0 && c < map.GetLength(1))
                    {
                        if (map[r, c] == '*')
                        {
                            cnt++;
                        }
                    }
                }
            }
            return cnt;
        }
    }
}
