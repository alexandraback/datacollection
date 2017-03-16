using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace Codejam_2012_1B_1
{
    class Program
    {
        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int t = int.Parse(sr.ReadLine());
            for (int test = 1; test <= t; test++)
            {
                sw.Write("Case #" + test + ": ");
    
                double ans =0;
                string[] temp = sr.ReadLine().Split();
                int n=int.Parse(temp[0]);
                double sum = 0,count=0,nsum=0;
                for (int i = 1; i <= n; i++)
                {                    
                        sum+= int.Parse(temp[i]);
                }
                double avg=sum/n;
                for (int i = 1; i <= n; i++)
                {
                    if (int.Parse(temp[i]) <= (avg * 2))
                    {
                        count++;
                        nsum += int.Parse(temp[i]);
                    }

                }
                double navg = (nsum + sum) / count;
                for (int i = 1; i <= n; i++)
                {
                    if (int.Parse(temp[i]) <= (avg * 2))
                    {
                        ans = 100*(navg-int.Parse(temp[i])) / sum;
                    }
                    else
                        ans = 0;
                    Console.Write(ans+" ");
                    sw.Write(ans + " ");

                }
                Console.WriteLine();
                sw.WriteLine();
                       }
            sw.Close();
        }

    }
}