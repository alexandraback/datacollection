using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CountingSheeps
{
    class Program
    {
        static long sheeps = 0;

        static void SetDigits(long value)
        {

            if (value >= 10)
            {
                SetDigits(value / 10);
            }
            sheeps = sheeps | (long)Math.Pow(2, (value % 10));
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines("A-large.in");
            int noOfCases = int.Parse(lines[0]);
            List<string> output = new List<string>();

            for (int i = 1; i <= noOfCases; i++)
            {
                long number = long.Parse(lines[i]);

                if (number == 0)
                {
                    output.Add(String.Format("Case #{0}: {1}", i, "INSOMNIA"));
                }
                else
                {
                    int k = 0;
                    sheeps = 0;
                    while (sheeps != 1023)
                    {
                        k += 1;
                        SetDigits(number * k);
                    }
                    output.Add(String.Format("Case #{0}: {1}", i, number * k));
                }

            }
            File.WriteAllLines("output.out", output);
        }
    }
}
