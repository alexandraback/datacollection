using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string filenName = @"B-small-attempt0.in";
            char[] delimiters = new char[] { ' ' };
            using (StreamReader sr = new StreamReader(filenName))
            {
                while (sr.Peek() >= 0)
                {
                    int numberOfTestCases = Convert.ToInt32(sr.ReadLine());

                    for (int i = 0; i < numberOfTestCases; i++)
                    {
                        string line = sr.ReadLine();
                        string[] fields = line.Split(delimiters);

                        int xCoordinate = Convert.ToInt32(fields[0]);
                        int yCoordinate = Convert.ToInt32(fields[1]);

                        Console.WriteLine("Case #{0}: {1}", i + 1, GetPogoDirections(xCoordinate, yCoordinate));
                    }
                }
            }
        }

        private static string GetPogoDirections(int xCoordinate, int yCoordinate)
        {
            StringBuilder sb = new StringBuilder();
            string xStep = "WE";
            if(xCoordinate < 0)
            {
                xCoordinate = xCoordinate * -1;
                xStep = "EW";
            }

            for (int i = 0; i < xCoordinate; i++)
            {
                sb.Append(xStep);
            }

            string yStep = "SN";
            if (yCoordinate < 0)
            {
                yCoordinate = yCoordinate * -1;
                yStep = "NS";
            }

            for (int i = 0; i < yCoordinate; i++)
            {
                sb.Append(yStep);
            }

            return sb.ToString();
        }
    }
}