using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _1C_Problem1
{
    class Program
    {
        static int ReadInt(string[] Input, int Line)
        {
            return int.Parse(Input[Line]);
        }

        static long GCD(long a, long b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }

        static void Main(string[] args)
        {
            string[] Lines = File.ReadAllLines("input.txt");
            using (StreamWriter Output = new StreamWriter("output.txt"))
            {
                int CurrentLine = 0;
                int ProblemSize = ReadInt(Lines, CurrentLine++);
                for (int i = 0; i < ProblemSize; i++)
                {
                    string[] Numbers = Lines[CurrentLine++].Split('/');
                    long A, B;
                    A = long.Parse(Numbers[0]);
                    B = long.Parse(Numbers[1]);


                    long C = GCD(A, B);
                    A = A / C;
                    B = B / C;

                    long B2 = B;
                    long A2 = A;
                    int Generation = 1;
                    int Result = int.MaxValue;
                    do
                    {
                        if (B2 % 2 == 0)
                        {
                            B2 = B2 / 2;
                        }
                        else
                        {
                            Result = int.MaxValue;
                            break;
                        }

                        if (A2 >= B2)
                        {
                            if (Generation < Result)
                            {
                                Result = Generation;
                            }
                        }
                        while (A2 > B2)
                        {
                            A2 = A2 - B2;
                        }
                        Generation++;
                    } while (B2 > 1);
                    if (Result != int.MaxValue)
                    {
                        Output.WriteLine("Case #" + (i + 1) + ": " + Result);
                    }
                    else
                    {
                        Output.WriteLine("Case #" + (i + 1) + ": impossible");
                    }
                    
                }
            }
        }
    }
}
