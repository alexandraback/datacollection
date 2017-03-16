using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication3
{
    class Program
    {
        static double minTime(double cps, double C, double F, double X)
        {
                double numOfSecondsTillFarm = C / cps;
                double numOfSecondsTillOver = X / cps;

                if (numOfSecondsTillOver < numOfSecondsTillFarm)
                    return numOfSecondsTillOver;

                return Math.Min(numOfSecondsTillOver, numOfSecondsTillFarm + minTime(cps + F, C, F, X));
        }

        static void Main(string[] args)
        {
            string fileName = "B-small-attempt0";

            StreamReader reader = new StreamReader(@"c:\users\alon\gcj\" + fileName + ".in");
            StreamWriter writer = new StreamWriter(@"c:\users\alon\gcj\" + fileName + ".out");


            int T = int.Parse(reader.ReadLine());

            for (int i = 1; i <= T; i++)
            {

                string[] values = reader.ReadLine().Split(' ');

                double C = double.Parse(values[0]);
                double F = double.Parse(values[1]);

                double X = double.Parse(values[2]);

                double cps = 2;

                double totalTime = 0;
                
                double numOfSecondsTillOverFarm = C / cps + (X / (cps+F));
                double numOfSecondsTillOver = X / cps;

                while (numOfSecondsTillOverFarm < numOfSecondsTillOver)
                {
                    totalTime += C / cps;
                    cps += F;

                    numOfSecondsTillOverFarm = C / cps + (X / (cps + F));
                    numOfSecondsTillOver = X / cps;
                }

                writer.Write("Case #{0}: ", i);

                writer.WriteLine(totalTime + numOfSecondsTillOver);

            }

            writer.Close();
        }
    }
}
