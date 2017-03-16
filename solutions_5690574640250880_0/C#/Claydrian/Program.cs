using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {

        static char[,] map;
        static void Main(string[] args)
        {
            // Your submission system killed my google chrome.
            // IE 8 was fine!
            string path = "C-small-attempt4.in";
            System.IO.StreamReader reader = new System.IO.StreamReader(path);
            System.IO.StreamWriter output = new System.IO.StreamWriter("output.txt");
            int testCases = int.Parse(reader.ReadLine());
            for (int i = 0; i < testCases; i++)
            {
                output.Write("Case #");
                output.Write(i + 1);
                output.WriteLine(": ");
                var vals = readRow(reader.ReadLine()).ToArray();
                int R = vals[0];
                int C = vals[1];
                int N = vals[2];
                map = new char[C, R];
                if(masterSweepster(R, C, N))
                {
                    for (int y = 0; y < R; y++)
                    {
                        for (int x = 0; x < C; x++)
                        {
                            output.Write(map[x, y]);
                        }
                        output.WriteLine();
                    }
                }
                else
                {
                    output.WriteLine("Impossible");
                }
            }
            output.Close();
            reader.Close();
        }

        static bool masterSweepster(int R, int C, int N)
        {
            if (C == R  && C + R - 1 <= N)
            {
                for (int i = 0; i < C; i++)
                {
                    map[C - 1, i] = map[i, R - 1] = '*';
                }
                return masterSweepster(R - 1, C - 1, N - ( C + R - 1 ));
            }
            else if (C >= R)
            {
                if (R <= N)
                {
                    for (int i = 0; i < R; i++ )
                    {
                        map[C - 1, i] = '*';
                    }
                    return masterSweepster(R, C - 1, N - R);
                }
            }
            else
            {
                if (C <= N)
                {
                    for (int i = 0; i < C; i++)
                    {
                        map[i, R - 1] = '*';
                    }
                    return masterSweepster(R - 1, C, N - C);
                }
            }
            if (C == 1 && R == 1)
            {
                if (N != 0)
                {
                    throw new Exception("ERR");
                }
                map[0, 0] = 'c';
                return true;
            }
            for (int i = 0; i < N; i++)
            {
                if (C > R)
                {
                    if (i % 2 == 0)
                    {
                        map[C - 1, (R - (i / 2)) - 1] = '*';
                    }
                    else
                    {
                        map[(C - 2) - i / 2, R - 1] = '*';
                    }
                }
                else
                {
                    if (i % 2 == 0)
                    {
                        map[(C - 1) - i / 2, R - 1] = '*';
                    }
                    else
                    {
                        map[C - 1, (R - (i / 2)) - 2] = '*';
                    }
                }
            }
            bool hasZero = nonZeroBoxesBoundedByZero(R, C);
            if (hasZero)
            {
                int largestDimension = Math.Max(R, C);
                int smallestDimension = Math.Min(R, C);
                if (smallestDimension == 2 && N == 1)
                {
                    return false;
                }
                if (largestDimension - N == 1 && N > 0 && N < 3)
                {
                    return false;
                }
            }
            return hasZero;
        }

        static bool nonZeroBoxesBoundedByZero(int R, int C)
        {
            bool foundClick = false;
            for (int y = 0; y < R; y++)
            {
                for (int x = 0; x < C; x++)
                {
                    if (map[x, y] != '*')
                    {
                        var result = neighbours(x, y).Count(f => f);
                        if (!foundClick && result == 0)
                        {
                            foundClick = true;
                            map[x, y] = 'c';
                        }
                        else
                        {
                            map[x, y] = '.';
                        }
                    }
                }
            }
            return foundClick;
        }

        static IEnumerable<bool> neighbours(int x, int y)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    bool b = x + dx >= 0 && x + dx < map.GetLength(0) && y + dy >= 0 && y + dy < map.GetLength(1) && map[x + dx, y + dy] == '*';
                    yield return b;
                }
            }
        }

        static IEnumerable<int> readRow(string row)
        {
            return row.Split(' ').Select(s => int.Parse(s));
        }
    }
}
