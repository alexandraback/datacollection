using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace _2_CookieClicker
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fsInput = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(fsInput);
            FileStream fsOutput = new FileStream(args[0] + ".out", FileMode.Create, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fsOutput);


            string sCases = reader.ReadLine();

            int iCases = int.Parse(sCases);

            for (int i = 0; i < iCases; i++)
            {
                string[] line = reader.ReadLine().Split(' ');
                double C = double.Parse(line[0]);
                double F = double.Parse(line[1]);
                double X = double.Parse(line[2]);

                double time = 0;
                double cps = 2;
                while (true)
                {
                    double time_to_farm = C / cps;
                    double time_to_farm_and_win = time_to_farm + X / (cps + F);
                    double time_to_win = X / cps;

                    if (time_to_win <= time_to_farm_and_win)
                    {
                        time += time_to_win;
                        break;
                    }
                    
                    time += time_to_farm;
                    cps += F;
                }
                    
                writer.WriteLine("Case #{0}: {1}", i + 1, time.ToString("F7"));
            }

            reader.Close();
            writer.Close();

        }
    }
}
