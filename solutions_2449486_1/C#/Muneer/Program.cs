using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace LawnMower
{
    class Program
    {
        static void Main(string[] args)
        {

            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\B-small-attempt0.in");
            //StreamWriter sw = new StreamWriter("D:\\B-small-attempt0.out");

            StreamReader sr = new StreamReader("D:\\B-large.in");
            StreamWriter sw = new StreamWriter("D:\\B-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());


            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int length = Convert.ToInt32(str[0]);//top to bottom
                int width = Convert.ToInt32(str[1]);

                int[,] heights = new int[length, width];

                for (int j = 0; j < length; j++)
                {
                    string[] str1 = sr.ReadLine().Split(' ');

                    for (int k = 0; k < width; k++)
                    {
                        heights[j, k] = Convert.ToInt32(str1[k]);
                    }
                }

                int[] rowMax = new int[length];
                int[] columnMax = new int[width];

                for (int j = 0; j < length; j++)
                {
                    rowMax[j] = 0;
                    for (int k = 0; k < width; k++)
                    {
                        if (heights[j, k] > rowMax[j])
                        {
                            rowMax[j] = heights[j, k];
                        }
                    }
                }

                for (int j = 0; j < width; j++)
                {
                    columnMax[j] = 0;
                    for (int k = 0; k < length; k++)
                    {
                        if (heights[k, j] > columnMax[j])
                        {
                            columnMax[j] = heights[k, j];
                        }
                    }
                }


                bool possible = true;

                for (int j = 0; j < length; j++)
                {
                    for (int k = 0; k < width; k++)
                    {
                        if (heights[j, k] < rowMax[j] && heights[j, k] < columnMax[k])
                        {
                            possible = false;
                            break;
                        }
                    }
                    if (possible == false) break;
                }

                sw.Write("Case #{0}: ", i + 1);
                sw.Write(possible ? "YES" : "NO");
                sw.WriteLine();

            }
            sw.Close();
        }

    }
}
