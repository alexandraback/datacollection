using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace CodeJamB
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Filename:");
            string filename = Console.ReadLine();
            string[] linesArray = File.ReadAllLines(@"F:\DL\" + filename);

            List<string> linesList = linesArray.ToList();

            int testCases = Int32.Parse(linesList[0]);
            using (StreamWriter file = new StreamWriter(@"F:\DL\SolveB.txt"))
            {
                for (int i = 1; i <= testCases; i++)
                {
                    string testCase = linesList[i];
                    List<string> numbers = testCase.Split(' ').ToList();
                    Double C = Double.Parse(numbers[0], CultureInfo.InvariantCulture);
                    Double F = Double.Parse(numbers[1], CultureInfo.InvariantCulture);
                    Double X = Double.Parse(numbers[2], CultureInfo.InvariantCulture);
                    file.WriteLine("Case #" + i.ToString() + ": " + SolveTest(C, F, X));
                }
            }
        }

        private static string SolveTest(double C, double F, double X)
        {
            //double current = X / 2.0;
            //double decisionpoint = C / 2.0;
            //double next = decisionpoint + (X / (2.0 + F));
            //int i = 1;
            //while (current >= next)
            //{
            //    current = next;
            //    decisionpoint += C / (2.0 + ((double)i * F));
            //    next = decisionpoint + (X / (2.0 + ((double)(i + 1) * F)));
            //    i++;
            //}
            //return current.ToString();

            int i = 0;
            double current = X / 2.0;
            double next = (C / 2.0) + (X / (2.0 + F));
            while (current > next)
            {
                i++;
                current = X / (2.0 + (i * F));
                next = (C / (2.0 + (i * F))) + (X / (2.0 + ((i + 1) * F)));
            }
            //if(i>0) i--;
            double result = 0.0;
            for (int j = 0; j < i; j++)
            {
                result += C / (2.0 + (j * F));
            }
            result += X / (2.0 + (i * F));
            return result.ToString().Replace(',', '.');
        }
    }
}
