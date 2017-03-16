using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code
{
    class Program
    {
        static void Main(string[] args)
        {
            double c = 0;
            double f = 0;
            double x = 0;
            double answer = 0;

            var reader = new StreamReader(@"B:\Users\Justin\Desktop\Temp\Google Code\Google Code\in.txt");
            var writer = new StreamWriter(@"B:\Users\Justin\Desktop\Temp\Google Code\Google Code\out.txt", false);

            int numCases = int.Parse(reader.ReadLine());
            for (int cc = 1; cc <= numCases; cc++)
            {
                double[] line = reader.ReadLine().Split(' ').Select(p => double.Parse(p)).ToArray();
                c = line[0];
                f = line[1];
                x = line[2];
                double time = Calc(c, f, x);
                writer.WriteLine(string.Format("Case #{0}: {1}", cc, Math.Round(time, 7)));
                Console.WriteLine(string.Format("Case #{0}: {1}", cc, Math.Round(time, 7)));
            }
            writer.Flush();
            writer.Close();
            Console.ReadKey();
        }


        private static double Calc(double c, double f, double x)
        {
            double seconds = 0;
            double total = 0;
            int farms = 0;
            double r = 2;

            while (true)
            {
                double dt = 0;
                
                double drt = (x-total) / r; // time to finish
                
                dt = (c-total) / r; // time to buy a factory

                if (drt <= dt)
                {
                    return (seconds + drt);
                }

                seconds += dt;
                
                // accumalate first
                total = total + r * dt;

                

                double breakEvenTime = (c / f);
                if ((total + breakEvenTime * r) < x)
                {
                    // buy a farm.
                    farms++;
                    r += f;
                    total -= c;
                }
                else
                {
                    return (seconds + drt - dt);
                }

            }

        }


    }
}
