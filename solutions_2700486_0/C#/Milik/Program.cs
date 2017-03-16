using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _2013R1P2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(DateTime.Now);

            String[] input = File.ReadAllText("..\\..\\input.txt").Split('\n');
            String output = "";

            int l = 0;
            int T = int.Parse(input[l]);
            l++;
            for (int c = 0; c < T; c++)
            {
                int Num = int.Parse(input[l].Split(' ')[0]);
                int XC = Math.Abs(int.Parse(input[l].Split(' ')[1]));
                int YC = Math.Abs(int.Parse(input[l].Split(' ')[2]));
                l++;

                decimal ret = 0;
                int Next = 1;
                int iter = 0;

                while (Num >= Next)
                {
                    Num -= Next;
                    iter++;
                    Next += 4;
                }

                if ((XC + YC)%2 >0 )
                {
                    ret = 0;
                }
                else if ((iter - 1) * 2 >= XC + YC)
                {
                    ret = 1;
                }
                else if (iter * 2 < (XC + YC))
                {
                    ret = 0;
                }
                else
                {
                    if (XC == 0)
                    {
                        ret = 0;
                    }
                    else
                    {
                        int size = 1+iter * 2;
                        decimal[] result = new decimal[size];
                        bool first = true;
                        result[size - 1] = 0.5m;
                        for (int i = 1; i < Num; i++)
                        {
                            if (i < size-1)
                            {
                                for (int u = 0; u < result.Length; u++)
                                {
                                    if (u < (-1 + result.Length))
                                    {
                                        result[u] = result[u + 1] / 2;
                                    }
                                    else
                                    {
                                        result[u] = result[u] + (1-result[u]) / 2;
                                    }
                                }
                            }
                            else
                            {
                                if (first)
                                {

                                    result[size - 1] = 1;
                                    for (int u = 1; u < result.Length; u++)
                                    {
                                        result[size - 1 - u] = result[size - u] / 2;
                                    }
                                }
                                else
                                {
                                    for (int u = 0; u < result.Length; u++)
                                    {
                                        if (u < (-1 + result.Length))
                                        {
                                            result[u] = result[u + 1];
                                        }
                                        else
                                        {
                                            result[u] = 1;
                                        }
                                    }
                                }
                            }
                        }
                        ret = result[XC];
                    }
                }

                output += "Case #" + (c + 1).ToString() + ": " + ret.ToString() + "\n";
                Console.WriteLine("Case #" + (c + 1).ToString() + ": " + ret.ToString());
            }

            File.WriteAllText("..\\..\\output.txt", output.Trim());
            Console.ReadLine();
        }
    }
}
