using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\Zlatko\Desktop\CLarge.in");

            int T = int.Parse(lines[0]);
            for (int i = 0; i < T; i++)
            {

                bool u = true;
                using (StreamWriter file = new StreamWriter(@"C:\Users\Zlatko\Desktop\OutputCLarge.txt", true))
                {
                    file.WriteLine("Case #" + (i + 1) + ":\n");
                }

                string[] inputs = lines[i + 1].Split();
                int R = int.Parse(inputs[0]),
                    C = int.Parse(inputs[1]),
                    M = int.Parse(inputs[2]);

                char[,] grid = new char[R, C];

                for (int j = 0; j < R; j++)
                    for (int k = 0; k < C; k++)
                        grid[j, k] = '.';

                grid[0, 0] = 'c';

                if (M == 0)
                { }

                else if (R * C - M == 1)
                {
                    for (int j = 0; j < R; j++)
                        for (int k = 0; k < C; k++)
                            grid[j, k] = '*';
                    grid[0, 0] = 'c';
                }
                else
                {

                    int rows = R,
                        columns = C;

                    if (R == 1 && C == 1)
                        u = false;

                    else if (R == 1 || C == 1)
                    {
                        if (R == 1)
                        {
                            if (C == 2)
                                u = false;
                            else
                            {
                                if (M > C - 2)
                                    u = false;
                                else
                                    for (int t = 0; t < M; t++)
                                        grid[0, C - 1 - t] = '*';
                            }
                        }
                        else
                        {
                            if (R == 2)
                                u = false;
                            else
                            {
                                if (M > R - 2)
                                    u = false;
                                else
                                    for (int t = 0; t < M; t++)
                                        grid[R - 1 - t, 0] = '*';
                            }
                        }
                    }

                    else
                    {
                        if (M > (R * C - 4))
                            u = false;

                        else
                        {

                            int counterR = rows - 1;
                            int counterC = columns - 1;

                            while (M > 0)
                            {

                                if (rows > columns)
                                {
                                    if (counterC == 1 && M == 1)
                                    {
                                        rows--;
                                        grid[rows - 1, columns - 1] = '*';
                                        if (rows == 2 || columns == 2)
                                            u = false;
                                        M--;
                                    }

                                    else
                                    {
                                        grid[counterR, counterC] = '*';
                                        counterC--;

                                        if (counterC < 0)
                                        {
                                            counterR--;
                                            counterC = columns - 1;
                                            rows--;
                                        }

                                        M--;
                                    }
                                }

                                else
                                {
                                    if (counterR == 1 && M == 1)
                                    {
                                        columns--;
                                        grid[rows - 1, columns - 1] = '*';
                                        if (rows == 2 || columns == 2)
                                            u = false;
                                        M--;
                                    }

                                    else
                                    {
                                        grid[counterR, counterC] = '*';
                                        counterR--;

                                        if (counterR < 0)
                                        {
                                            counterC--;
                                            counterR = rows - 1;
                                            columns--;
                                        }

                                        M--;
                                    }

                                }

                            }
                        }
                    }

                }


                if (u)
                {

                    for (int j = 0; j < R; j++)
                    {
                        for (int k = 0; k < C; k++)
                            using (StreamWriter file = new StreamWriter(@"C:\Users\Zlatko\Desktop\OutputCLarge.txt", true))
                            {
                                file.Write(grid[j, k]);
                            }

                        using (StreamWriter file = new StreamWriter(@"C:\Users\Zlatko\Desktop\OutputCLarge.txt", true))
                        {
                            file.WriteLine("\n");
                        }

                    }
                }

                else
                    using (StreamWriter file = new StreamWriter(@"C:\Users\Zlatko\Desktop\OutputCLarge.txt", true))
                    {
                        file.WriteLine("Impossible\n");
                    }

            }

        }
    }
}
