using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj14qr
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\B-large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\B-large.out");
            for (int a = 0; a < t; a++)
            {
                string[] line= lines[idx++].Split(' ');
                double c = double.Parse(line[0]);
                double f = double.Parse(line[1]);
                double x = double.Parse(line[2]);

                double rate = 2;
                double time = 0;
                double timeNoFarm, timeWithFarm;
                do
                {
                    timeNoFarm = time + (x / rate);
                    double timeToBuyFarm = time + (c / rate);
                    timeWithFarm = timeToBuyFarm + (x / (rate + f));
                    rate += f;
                    time = timeToBuyFarm;

                } while (timeNoFarm > timeWithFarm);

                tw.WriteLine("Case #{0}: {1:F7}", a + 1, timeNoFarm);
            }
            tw.Close();
        }
    }
}
