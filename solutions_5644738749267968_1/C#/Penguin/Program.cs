using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace DeceitfulWar
{
    class Program
    {
     
        static void Main(string[] args)
        {
            DeceitfulWar(@"C:\Users\Yulin\Downloads\D-large.in", @"C:\Users\Yulin\Downloads\D-large.out");
        }

        private static void DeceitfulWar(string inputName, string outputName)
        {
            using (StreamReader sr = File.OpenText(inputName))
            {
                using (StreamWriter sw = new StreamWriter(File.OpenWrite(outputName)))
                {
                    int T = int.Parse(sr.ReadLine());

                    for (int i = 0; i < T; i++)
                    {
                        
                        int N = int.Parse(sr.ReadLine());
                        string line1 = sr.ReadLine();
                        string line2 = sr.ReadLine();
                        string[] lines1 = line1.Split(new char[] {' '});
                        string[] lines2 = line2.Split(new char[] {' '});

                        decimal[] weight1 = new decimal[lines1.Length];
                        decimal[] weight2 = new decimal[lines2.Length];

                        for (int j = 0; j < N; j++)
                        {
                            weight1[j] = decimal.Parse(lines1[j]);
                            weight2[j] = decimal.Parse(lines2[j]);
                        }

                        Array.Sort(weight1);
                        Array.Sort(weight2);

                        int n = weight1.Length - 1;
                        int m;
                        int counter= 0;

                        for (m = weight1.Length - 1; m >= 0; m --)
                        {
                            if (weight1[m] > weight2[n])
                                counter++;
                            else
                                n--;
                        }

                        int counter2 = 0;
                        m = 0;
                        n = 0;
                        while (m < weight1.Length && n < weight1.Length)
                        {
                            if (weight2[m] < weight1[n])
                            {
                                counter2++;
                                m++;
                                n++;
                            }
                            else
                            {
                                n++;
                            }

                        }

                        sw.WriteLine(String.Format("Case #{0}: {1} {2}" , i+1 , counter2 , counter));



                    }

                }
            }
        }

        
    }
}
