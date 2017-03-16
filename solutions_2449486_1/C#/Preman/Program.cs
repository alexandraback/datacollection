using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lawnmower
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "D:\\Data\\CodeJam\\1_2\\B-large.in";
            string output = "D:\\Data\\CodeJam\\1_2\\B-large.out";

            StreamReader sr = new StreamReader(input);
            int T = int.Parse(sr.ReadLine());
            int[][,] matrix = new int[T][,];
            string line;
            for (int k = 0; k < T; k++)
            {
                line = sr.ReadLine();
                string[] part = line.Split(' ');
                int N = int.Parse(part[0]);
                int M = int.Parse(part[1]);
                matrix[k] = new int[N, M];
                for (int i = 0; i < N; i++)
                {
                    line = sr.ReadLine();
                    part = line.Split(' ');
                    for (int j = 0; j < M; j++)
                    {
                        matrix[k][i, j] = int.Parse(part[j]);
                    }
                }
            }

            sr.Close();

            StreamWriter sw = new StreamWriter(output);
            for (int k = 0; k < T; k++)
            {
                bool result = GetResult(matrix[k]);
                if (result == true)
                    sw.WriteLine("Case #{0}: YES", k + 1);
                else
                    sw.WriteLine("Case #{0}: NO", k + 1);
            }
            sw.Close();
        }

        static bool GetResult(int[,] lawn)
        {
            int N = lawn.GetLength(0);
            int M = lawn.GetLength(1);
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                {
                    if (!isMaxInCol(lawn, j, i, N, M) && !isMaxInRow(lawn, j, i, N, M))
                    {
                        return false;
                    }
                }
            return true;
        }

        static bool isMaxInRow(int[,] lawn, int x, int y, int N, int M)
        {
            for (int i = 0; i < M; i++)
            {
                if (lawn[y, x] < lawn[y, i])
                    return false;
            }
            return true;
        }

        static bool isMaxInCol(int[,] lawn, int x, int y, int N, int M)
        {
            for (int i = 0; i < N; i++)
            {
                if (lawn[y, x] < lawn[i, x])
                    return false;
            }
            return true;
        }
    }
}
