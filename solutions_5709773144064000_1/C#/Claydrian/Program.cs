using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            // Your submission system killed my google chrome.
            // IE 8 was fine!
            string path = "B-large.in";
            System.IO.StreamReader reader = new System.IO.StreamReader(path);
            System.IO.StreamWriter output = new System.IO.StreamWriter("output.txt");
            int testCases = int.Parse(reader.ReadLine());
            for (int i = 0; i < testCases; i++)
            {
                output.Write("Case #");
                output.Write(i + 1);
                output.Write(": ");
                var vals = readRow(reader.ReadLine()).ToArray();
                double time = totalTime(vals[0], vals[1], vals[2]);
                output.WriteLine(time);
            }
            output.Close();
            reader.Close();
        }

        static double totalTime(double C, double F, double X)
        {
            int n = 1;
            double totalBuildingTime = 0;
            double finishingTime1 = X / 2.0;
            double finishingTime2;
            do
            {
                double farmTime = 1.0 / (2.0 + (n - 1) * F) * C;
                finishingTime2 = X / (2.0 + n * F);
                if (farmTime + finishingTime2 < finishingTime1)
                {
                    totalBuildingTime += farmTime;
                    finishingTime1 = finishingTime2;
                    n++;
                }
                else
                {
                    break;
                }
            } while (true);
            return totalBuildingTime + finishingTime1;
        }

        static IEnumerable<double> readRow(string row)
        {
            return row.Split(' ').Select(s => double.Parse(s));
        }
    }
}
