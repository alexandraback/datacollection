using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace _1C_A
{
    class Program
    {
        static void Main(string[] args)
        {
            String location = @"D:\Programming\Google Code Jam 2015\Round 1C Inputs\";
            String fileName = "A-small-attempt1";
            String ext = ".in";
            String outputExt = "-ANS.txt";

            String[] lines = File.ReadAllLines(location + fileName + ext);
            int cursor = 1;
            int curCase = 1;
            int numCase = Convert.ToInt16(lines[0]);


            using (StreamWriter f = new StreamWriter(location + fileName + outputExt))
            {
                while (cursor < lines.Length)
                {
                    int R = Convert.ToInt32(lines[cursor].Split(' ')[0]);
                    int C = Convert.ToInt32(lines[cursor].Split(' ')[1]);
                    int W = Convert.ToInt32(lines[cursor].Split(' ')[2]);
                    cursor++;

                    int Solve = -1;
                    if (W == 1)
                        Solve = R * C;
                    else
                    {
                        // Solve
                        int[,] RC = new int[R, C];

                        bool isFound = false;
                        int aimR = 1;
                        int aimC = W;
                        int shots = 0;

                        while (!isFound)
                        {
                            if (aimC < C)
                            {
                                RC[aimR - 1, aimC - 1] = 1;
                                shots++;
                                aimC += W;
                            }
                            else if (aimC == C)
                            {
                                shots += W;
                                isFound = true;
                            }
                            else
                            {
                                if ((C - aimC) < W)
                                    shots += W;
                                else
                                    shots += W + 1;
                                isFound = true;
                            }
                        }

                        Solve = shots;
                    }

                    f.WriteLine("Case #" + curCase + ": " + Solve);
                    Console.WriteLine("Case #" + curCase + ": " + Solve);
                    curCase++;
                }
            }

            Console.ReadKey();
        }
    }
}
