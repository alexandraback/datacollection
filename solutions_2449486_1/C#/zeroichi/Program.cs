using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace probB
{
    class Program
    {
        static string Solve(int[,] data)
        {
            int rows = data.GetLength(0);
            int cols = data.GetLength(1);
            int[] hmax = new int[rows];
            int[] vmax = new int[cols];

            for (int i = 0; i < rows; ++i)
            {
                hmax[i] = 0;
                for (int j = 0; j < cols; ++j)
                {
                    if (hmax[i] < data[i, j]) hmax[i] = data[i, j];
                }
            }

            for (int j = 0; j < cols; ++j)
            {
                vmax[j] = 0;
                for (int i = 0; i < rows; ++i)
                {
                    if (vmax[j] < data[i, j]) vmax[j] = data[i, j];
                }
            }

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (data[i, j] != hmax[i] && data[i, j] != vmax[j])
                        return "NO";
                }
            }

            return "YES";
        }

        static void Main(string[] args)
        {
            int cases;
            using (StreamReader sr = new StreamReader(args[0]))
            {
                cases = int.Parse(sr.ReadLine());
                for (int c = 0; c < cases; ++c)
                {
                    int rows, cols;
                    string[] s = sr.ReadLine().Split(' ');
                    rows = int.Parse(s[0]);
                    cols = int.Parse(s[1]);
                    int[,] data = new int[rows, cols];
                    for (int i = 0; i < rows; ++i)
                    {
                        s = sr.ReadLine().Split(' ');
                        for (int j = 0; j < cols; ++j)
                            data[i, j] = int.Parse(s[j]);
                    }
                    System.Console.WriteLine(string.Format("Case #{0}: {1}", c + 1, Solve(data)));
                }
            }
        }
    }
}
