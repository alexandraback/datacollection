using System;
using System.Collections.Generic;
using System.IO;

namespace ProblemC1
{
    class Program
    {
        static bool[] visited;
        static bool[] marked;
        static int[][] inherit;

        static void Main(string[] args)
        {
            int counter = 1;
            StreamReader file = new StreamReader("a.txt");
            counter = int.Parse(file.ReadLine());
            for (int i = 1; i <= counter; i++)
            {
                Console.Write(string.Format("Case #{0}:", i));
                int n = int.Parse(file.ReadLine());
                visited = new bool[n + 1];
                marked = new bool[n + 1];
                for (int j = 0; j < n + 1; j++)
                {
                    visited[j] = false;
                    marked[j] = false;
                }

                inherit = new int[n+1][];
                for (int jj = 0; jj < n; jj++)
                {
                    string[] line = file.ReadLine().Split();
                    int m = int.Parse(line[0]);
                    inherit[jj + 1] = new int[m];
                    for (int k = 0; k < m; k++)
                    {
                        inherit[jj + 1][k] = int.Parse(line[k + 1]);
                    }
                }

                bool result = true;
                for (int kk = 0; kk < n; kk++)
                {
                    for (int j = 0; j < n + 1; j++)
                    {
                        marked[j] = false;
                        visited[j] = false;
                    }
                    result = visit(kk + 1);
                    if (!result)
                        break;
                }

                if (result)
                {
                    Console.WriteLine(" No");
                }
                else
                {
                    Console.WriteLine(" Yes");
                }
            }
        }

        static bool visit(int start)
        {
            if (start == 0) return true;
            if (marked[start])
                return false;
            marked[start] = true;
            if (visited[start])
                return true;

            for (int i = 0; i < inherit[start].Length; i++)
            {
                int current = inherit[start][i];
                if (!visit(current))
                {
                    return false;
                }
            }

            visited[start] = true;
            return true;
        }
    }
}
