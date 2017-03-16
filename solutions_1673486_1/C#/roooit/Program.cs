using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace Codejam_2012_1A_1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int t = int.Parse(sr.ReadLine());
            for( int i=1;i<=t;i++)
            {
                double p=1.0;
                string[] tmp1 = sr.ReadLine().Split();
                string[] tmp2 = sr.ReadLine().Split();
                double min=double.Parse(tmp1[1])+2;
                double min1 = min;
                int n=int.Parse(tmp1[0]);
                for (int j = -1; j < n; j++)
                {
                    double ex = p * (n - j - 1 + min1 - 2 - j) + (1 - p) * (n - j - 1 + min1 - 2 - j + min1 - 1);
                  //  Console.Write(ex + " ");
                    if (ex < min)
                        min = ex;
                    if (j < n - 1)
                        p = p * double.Parse(tmp2[j + 1]);
                }
                Console.WriteLine(min);
                sw.WriteLine("Case #" + i + ": " + min);
            }
            sw.Close();
        }
    }
}
