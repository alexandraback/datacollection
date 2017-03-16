using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualif2
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\second3.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\secondOut3.txt");
            var total = long.Parse(file.ReadLine());
            for (long i = 1; i <= total; i++)
            {
                var values = file.ReadLine().Split(' ');
                var c = double.Parse(values[0]);
                var f = double.Parse(values[1]);
                var x = double.Parse(values[2]);
                var currentSpeed = 2.0;
                double extraTime = 0.0;
                double time = x / 2.0;
                double prevTime;
                do
                {
                    prevTime = time;
                    extraTime += c / currentSpeed;
                    currentSpeed += f;
                    time = extraTime + (x / currentSpeed);
                } while (time < prevTime);

                outFile.WriteLine(string.Format("Case #{0}: {1}", i, prevTime.ToString("0.0000000")));
            }

            file.Close();
            outFile.Close();
        }
    }
}
