using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows;

namespace GoogleCodeJamCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inputStream = new StreamReader("input.txt");
            StreamWriter outputStream = new StreamWriter("output.txt", false);

            int caseNumber = 1, totalTestCases;

            bool possible = true;
            long minimumGenerations, P, Q;
            double genPercentageElf = 0;

            List<double> factors = new List<double>();
            for (int x = 1; x <= 40; x++)
            {
                factors.Add(1d / Math.Pow(2d, (double)x));
            }

            try
            {
                totalTestCases = Convert.ToInt32(inputStream.ReadLine());

                for (int a = 0; a < totalTestCases; a++)
                {
                    minimumGenerations = 0;

                    string[] parts = inputStream.ReadLine().Split('/');

                    P = Convert.ToInt64(parts[0]);
                    Q = Convert.ToInt64(parts[1]);

                    genPercentageElf = (double)P / (double)Q;

                    //check if possible by comparing fraction to the list of factors
                    possible = false;
                    for (int b = 0; b < factors.Count; b++)
                    {
                        //check if cleanly divisible by factor with no remainder. If yes then set possible to true and break
                        //really bad idea doing this using doubles / floats!

                        if (genPercentageElf % factors[b] == 0)
                        {
                            possible = true;
                            break;
                        }
                    }

                    if (possible)
                    {
                        minimumGenerations = 1;

                        if (genPercentageElf < 0.5d) //if >= 50% then it is always 1 generation
                        {
                            //determine how many times it needs to be doubled to reach >= 50% == minimum generations
                            while (genPercentageElf < 0.5d)
                            {
                                genPercentageElf *= 2;
                                minimumGenerations++;
                            }
                        }
                    
                        outputStream.WriteLine("Case #" + caseNumber.ToString() + ": " + minimumGenerations.ToString());
                    }
                    else
                    {
                        outputStream.WriteLine("Case #" + caseNumber.ToString() + ": impossible");
                    }

                    minimumGenerations = 0;
                    possible = true;
                    caseNumber++;
                }
            }
            finally
            {
                inputStream.Close();
                outputStream.Close();
            }
        }
    }
}
