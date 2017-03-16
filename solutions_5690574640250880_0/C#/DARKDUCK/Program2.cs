using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Facet.Combinatorics;
using System.IO;

namespace ex3b
{
    class Game
    {
        static int countMines(int[,] data, int x, int y)
        {
            int nbMines = 0;
            for (int i = x - 1; i < x + 2; i++)
            {
                for (int j = y - 1; j < y + 2; j++)
                {
                    if (i >= 0 && j >= 0 && i < data.GetLength(0) && j < data.GetLength(1) && (i != 0 || j != 0) && data[i, j] == -2)
                    {
                        nbMines++;
                    }
                }
            }
            return nbMines;
        }
        static int[,] solveMine(int[,] data,int x, int y)
        {
            if (x >= data.GetLength(0) || x < 0 || y >= data.GetLength(1) || y < 0 || data[x, y] >= 0) return data;
            int mines = countMines(data, x, y);
            data[x, y] = mines;
            if (mines == 0)
            {
                for (int i = x - 1; i < x + 2; i++)
                {
                    for (int j = y - 1; j < y + 2; j++)
                    {
                        data = solveMine(data, i, j);
                    }
                }
            }
            return data;
        }

        public static int[,] generateFromEmpty(int x, int y, int nbSet)
        {
            List<int> values = new List<int>();
            for (int i = 1; i < x * y; i++)
            {
                values.Add(i);
            }
            Combinations<int> combs = new Combinations<int>(values, nbSet);
            foreach (var t in combs)
            {
                int[,] data = new int[x, y];
                for (int i = 0; i < x; i++)
                {
                    for (int j = 0; j < y; j++)
                    {
                        data[i, j] = -1;
                    }
                }
                foreach (var i in t)
                {
                    data[i % x, i / x] = -2;
                }
                int[,] solved = solveMine(data, 0, 0);
                bool ip = true;
                for (int i = 0; i < solved.GetLength(0) && ip; i++)
                {
                    for (int j = 0; j < solved.GetLength(1) && ip; j++)
                    {
                        if (solved[i, j] == -1)
                        {
                            ip = false;
                        }
                    }
                }
                if (ip) return solved;
            }
            return null;
        }
    }

        
    class Program
    {
        static void printArray(int[,] res)
        {
            for (int j = 0; j < res.GetLength(1); j++)
            {
                for (int i = 0; i < res.GetLength(0); i++)
                {
                    if (res[i, j] == -2) Console.Write('*');
                    else if (res[i,j] == -1) Console.Write('.');
                    else if (res[i,j] == -3) Console.Write('c');
                    else Console.Write(res[i, j]);
                }
                Console.Write('\n');
            }
        }

        static void Main(string[] args)
        {
            FileStream filestream = new FileStream(@"C:\Users\Guillame Leclerc\Documents\codeJam2k14\ex3\output.txt", FileMode.Truncate);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);
            Console.SetError(streamwriter);
            System.IO.StreamReader file = new System.IO.StreamReader(@"C:\Users\Guillame Leclerc\Documents\codeJam2k14\ex3\file.txt");
            int nbTestCases = Int32.Parse(file.ReadLine());
            for (int T = 1; T <= nbTestCases; T++)
            {
                Console.WriteLine("Case #" + T + ":");
                String[] input = file.ReadLine().Split(' ');
                int Y = Int32.Parse(input[0]);
                int X = Int32.Parse(input[1]);
                int N = Int32.Parse(input[2]);
                int[,] res = Game.generateFromEmpty(X, Y, N);
                if (res == null) Console.WriteLine("Impossible");
                else
                {
                    for (int i = 0; i < X; i++)
                    {
                        for (int j = 0; j < Y; j++)
                        {
                            if (res[i, j] != -2) res[i, j] = -1;
                        }
                    }
                    res[0, 0] = -3;
                    printArray(res);
                }


            }
        }
    }
}
