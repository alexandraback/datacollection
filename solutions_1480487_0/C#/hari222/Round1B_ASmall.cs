using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1B
{
    class Round1B_A
    {
        static void Main(string[] args)
        {
            string name = @"C:\Users\P7106325\Desktop\GCJ\Round1B\A-small-attempt0";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] str = sr.ReadLine().Split(' ');
                int n = int.Parse(str[0]);
                int[] points = new int[n];
                int sum = 0;
                for (int j = 0; j <= n - 1; j++)
                {
                    points[j] = int.Parse(str[j+1]);
                    sum += points[j];
                }
                    try
                    {
                        string res = Compute(n, points, sum);
                        sw.WriteLine(string.Format("Case #{0}: {1}", i, res));
                        Console.WriteLine(string.Format("Case #{0}: Done", i));
                    }
                    catch (Exception ex)
                    {

                    }
            }
            sw.Close();
            sr.Close();
        }

        static string Compute(int n, int[] points, int sum)
        {
            StringBuilder res = new StringBuilder();
            int count = n, sumnew = 0;
            bool b = false;
            double avg = (double)(2 * sum) / (double)n;
            double newAvg = 0D;
            for (int i = 0; i < n; i++)
            {
                if (points[i] > avg)
                {
                    count--; b = true;
                }
                else sumnew += points[i];
            }
            newAvg = (double)(sumnew + sum) / (double)count;

            if (b)
            {
                for (int i = 0; i < n; i++)
                {
                    if (points[i] < avg)
                        res.Append((double)(newAvg - points[i]) / (double)sum * (double)100);
                    else
                        res.Append("0");
                    res.Append(" ");
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    res.Append((double)(avg - points[i]) / (double)sum * (double)100);
                    res.Append(" ");
                }
            }
            return res.ToString();
        }
        
    }
}
