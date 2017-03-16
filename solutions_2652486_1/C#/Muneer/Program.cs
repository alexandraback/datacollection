using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace GoodLuck
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\C-small-1-attempt1.in");
            //StreamWriter sw = new StreamWriter("D:\\C-small-1-attempt1.out");

            StreamReader sr = new StreamReader("D:\\C-small-2-attempt3.in");
            StreamWriter sw = new StreamWriter("D:\\C-small-2-attempt3.out");

            long numTestCases = Convert.ToInt64(sr.ReadLine());


            for (long i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);
                sw.Write("Case #{0}: ", i + 1);
                sw.WriteLine();

                string[] str = sr.ReadLine().Split(' ');

                long numSets = Convert.ToInt64(str[0]);
                long numlongegers = Convert.ToInt64(str[1]);
                long maxlong = Convert.ToInt64(str[2]);
                long numProducts = Convert.ToInt64(str[3]);

                
                

                for (long j = 0; j < numSets; j++)
                {
                    str = sr.ReadLine().Split(' ');

                    long[] products = new long[numProducts];

                    for (long k= 0; k < numProducts; k++)
                    {
                        products[k] = Convert.ToInt64(str[k]);
                    }
                    
                    long[] componentsTotal = new long[10];
                    long[] componentsMax = new long[10];
                    long[] outputComponents = new long[10];

                    for (long k = 0; k < componentsTotal.Length; k++)
                    {
                        componentsTotal[k] = 0;
                        componentsMax[k] = 0;
                        outputComponents[k] = 0;
                    }


                    long[] components = { 2, 3, 4, 5,6,7,8 };

                    for (long k = 0; k < numProducts; k++)
                    {

                        foreach (long factor in new long[] { 2, 3, 4, 5, 6, 7, 8 })
                        {
                            if (factor > maxlong) continue;

                            long product = products[k];

                            long numOcur = 0;
                            while (product % factor == 0)
                            {
                                product /= factor;
                                numOcur++;
                            }
                            componentsTotal[factor] += numOcur;
                            if (numOcur > componentsMax[factor]) componentsMax[factor] = numOcur;

                        }

                    }

                    
                    List<long> output = new List<long>();

                    if (maxlong >= 6 && componentsTotal[6] >= 4)
                    {
                        output.Add(6);
                        output.Add(6);

                        for (long k = 2; k < componentsMax[3] || k < componentsTotal[3] * 2 / numProducts; k++)
                        {
                            output.Add(3);
                        }
                    }
                    if (maxlong >= 6 && componentsTotal[6] >= 2)
                    {
                        output.Add(6);

                        for (long k = 1; k < componentsMax[3] || k < componentsTotal[3] * 2 / numProducts; k++)
                        {
                            output.Add(3);
                        }
                    }
                    else if (maxlong >= 3)
                    {
                        for (long k = 0; k < componentsMax[3] || k < componentsTotal[3] * 2 / numProducts; k++)
                        {
                            output.Add(3);
                        }
                    }

                    if (maxlong >= 5)
                    {
                        for (long k = 0; k < componentsMax[5] || k < componentsTotal[5] * 2 / numProducts; k++)
                        {
                            output.Add(5);
                        }
                    }

                    if (maxlong >= 7)
                    {
                        for (long k = 0; k < componentsMax[7] || k < componentsTotal[7] * 2 / numProducts; k++)
                        {
                            output.Add(7);
                        }
                    }

                    
                    if (maxlong >= 8)
                    {
                        if (componentsTotal[8] >= 2)
                        {
                            output.Add(8);

                            if (componentsTotal[4] >= 4)
                            {
                                output.Add(4);
                            }
                        }
                        else if (componentsTotal[4] >= 2)
                        {
                            output.Add(4);
                        }
                    }
                    else if (maxlong >= 4)
                    {
                        long numTwos = componentsTotal[2] * 2 / (3 * numProducts);
                        long numFours;
                        if (numlongegers - output.Count < componentsMax[2])
                        {
                            long numFoursMin = componentsMax[2] - (numlongegers - output.Count);
                            if (numFoursMin < 0) numFoursMin = 0;
                            for (long k = 0; k < numFoursMin; k++)
                            {
                                output.Add(4);
                            }

                        }
                    }
                    else
                    {
                        for (long k = 0; k < componentsMax[2] || k < componentsTotal[2] * 2 / numProducts; k++)
                        {
                            output.Add(2);
                        }
                    }

                    while (output.Count < numlongegers)
                    {
                        output.Add(2);
                    }

                    for (int k = 0; k < numlongegers; k++)
                    {
                        sw.Write(output[k]);
                    }
                    sw.WriteLine();

                }

                
            }
            sw.Close();
        }
    }
}
