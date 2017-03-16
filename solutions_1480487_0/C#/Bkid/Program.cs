using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codeJam
{
    class Program
    {

        static void Main(string[] args)
        {
            int n = System.Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                
                string[] inputStr = Console.ReadLine().Split(' ');
                int N = Convert.ToInt32(inputStr[0]);
                decimal[] pointVals = new decimal[inputStr.Length - 1];
                decimal X = 0;
                decimal K = 0;
                decimal sum = 0;
                Console.Write("Case #" + (i + 1).ToString()+": ");
                for (int j = 0; j < pointVals.Length; j++)
                {
                    pointVals[j] = Convert.ToInt32(inputStr[j+1]);
                    X += pointVals[j];
                }
                sum = 2 * X;
                K = sum / N;
                decimal temp = 0;
                for (int g = 0; g < pointVals.Length; g++)
                {
                    temp = (decimal)((decimal)(K - pointVals[g]) / (decimal)X);
                    if (temp < 0)
                    {
                        temp = 0;
                        N--;
                        sum -= pointVals[g];
                        K = sum / N;
                    }
                }
                for (int g = 0; g < pointVals.Length; g++)
                {
                    temp=(decimal)((decimal)(K - pointVals[g])/(decimal)X);
                    if (temp<0)
                    {
                        temp = 0;
                    }
                    temp *= 100;
                    Console.Write(String.Format("{0:0.000000}", temp));
                    if (g==pointVals.Length-1)
                    {
                        Console.WriteLine();
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
            }
        }
    }
}
