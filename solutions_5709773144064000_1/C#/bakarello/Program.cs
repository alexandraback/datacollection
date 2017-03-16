using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Google_Jam_Q2
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter sw = new StreamWriter(new FileStream("output.txt", FileMode.Create));
            StreamReader sr = new StreamReader(new FileStream("input", FileMode.Open));

            int count = int.Parse(sr.ReadLine());

            for (int i = 0; i < count; i++)
            {
                double farmCost;
                double addIncome;
                double winCost;
                
                string[] param = sr.ReadLine().Split(' ');
                farmCost = double.Parse(param[0], CultureInfo.InvariantCulture);
                addIncome = double.Parse(param[1], CultureInfo.InvariantCulture);
                winCost = double.Parse(param[2], CultureInfo.InvariantCulture);
                double curInc = 2d;
                double time = 0d;

                while (ShouldBuyFarm(curInc, addIncome, farmCost, winCost) == -1)
                {
                    time += farmCost / curInc;
                    curInc += addIncome;
                }

                time += ShouldBuyFarm(curInc, addIncome, farmCost, winCost);
                string output = string.Format("Case #{0}: {1:0.0000000}", i + 1, time);
                sw.WriteLine(output);
            }
            sw.Dispose();
            sr.Dispose();
        }

        static double ShouldBuyFarm(double cIncome, double addInc, double fCost, double wCost)
        {
            if ((fCost / cIncome) + (wCost / (cIncome + addInc) ) >= wCost / cIncome)
                return wCost / cIncome;
            return -1;
        }
    }
}
