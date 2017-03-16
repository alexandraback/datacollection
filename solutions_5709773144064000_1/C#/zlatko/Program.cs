using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\Zlatko\Desktop\BLarge.in");

            int T = int.Parse(lines[0]);
            for (int i = 0; i < T; i++)
            {

                double counter = 0,
                       rate = 2;


                string[] inputs = lines[i + 1].Split();
                double C = double.Parse(inputs[0]),
                       F = double.Parse(inputs[1]),
                       X = double.Parse(inputs[2]);

                while (X != 0)
                {
                    if ((X-C)/rate < X / (rate + F))
                    {
                        counter += X / rate;
                        X = 0;
                    }

                    else
                    {
                        counter += C / rate;
                        rate += F;
                    }
                }

                using (StreamWriter file = new StreamWriter(@"C:\Users\Zlatko\Desktop\OutputBLarge.txt", true))
                {
                    file.WriteLine("Case #" + (i + 1) + ": " + counter);
                }
            
            
            } 
            
        }
    }
}
