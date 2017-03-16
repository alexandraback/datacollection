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

        static void ReadTuple(out int A, out int B, out int K, string[] Input, int Line)
        {
            string[] Numbers = Input[Line].Split('/');
            A = int.Parse(Numbers[0]);
            B = int.Parse(Numbers[1]);
            K = int.Parse(Numbers[2]);
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
                    int A, B;
                    A = int.Parse(Numbers[0]);
                    B = int.Parse(Numbers[1]);              
                    

                    if (B % 2 != 0)
                    {
                        
                    }

                    int B2 = B;
                    int A2 = A;
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
                        // Output.WriteLine("Case #" + (i + 1) + ": " + Result + "," + A2 + "," + B2);
                        Output.WriteLine("Case #" + (i + 1) + ": " + Result);
                    }
                    else
                    {
                        Output.WriteLine("Case #" + (i + 1) + ": impossible");
                    }
                    /*
                    try
                    {
                        if (A > B / 2)
                        {
                            A = A - (B / 2);
                            OverHalf = true;
                        }
                        
                        {
                            Result = Math.Log(B / A, 2);
                        }
                        
                        if (Math.Floor(Result) != Math.Ceiling(Result))
                        {
                            Output.WriteLine("Case #" + (i + 1) + ": impossible");
                            continue;
                        }
                    }
                    catch
                    {
                        Output.WriteLine("Case #" + (i + 1) + ": impossible");
                        continue;
                    }

                    
                    {
                        if (OverHalf)
                            Result = 1;
                        Output.WriteLine("Case #" + (i + 1) + ": " + ((int)Result));
                    }
                     * */
                }
            }
        }
    }
}
