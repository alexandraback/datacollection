using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Roun1CProblemA
{
    public class Program
    {
        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("A-small-attempt0.in");
            string line = reader.ReadLine();
            TextWriter writer = new StreamWriter("out.in");

            int T = int.Parse(line.Trim());

            for (int i = 1; i <= T; i++)
            {
                line = reader.ReadLine();
                int upper = Int32.Parse(line.Split('/')[0]);
                int lower = Int32.Parse(line.Split('/')[1]);

                if (IsGoodDivision(upper, lower))
                {
                    double division = (float)lower / upper;
                    double roundedDivision = Math.Ceiling(division);
                    double result = Math.Log(roundedDivision, 2);
                    writer.WriteLine("Case #" + i + ": " + Math.Ceiling(result));                    
                }
                else
                {
                    writer.WriteLine("Case #" + i + ": impossible");                    
                }

                writer.Flush();
            }
        }

        public static bool IsGoodDivision(int a, int b)
        {
            while (b % 2 == 0) { b /= 2; }
            while (b % 5 == 0) { b /= 5; }
            return a % b == 0;
        }
        
    }
}
