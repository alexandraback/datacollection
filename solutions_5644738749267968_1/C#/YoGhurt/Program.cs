using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace CodeJamD
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
            using (StreamWriter file = new StreamWriter(@"F:\DL\SolveDLarge.txt"))
            {
                for (int i = 1; i <= testCases; i++)
                {
                    List<string> testCase = new List<string>();
                    testCase.Add(linesList[((i - 1) * 3) + 1]);
                    testCase.Add(linesList[((i - 1) * 3) + 2]);
                    testCase.Add(linesList[((i - 1) * 3) + 3]);
                    file.WriteLine("Case #" + i.ToString() + ": " + SolveTest(testCase));
                }
            }
        }

        private static string SolveTest(List<string> testCase)
        {
            List<string> naomi = testCase[1].Split(' ').ToList();
            List<string> ken = testCase[2].Split(' ').ToList();
            List<double> naomiD = new List<double>();
            List<double> kenD = new List<double>();
            for (int i = 0; i < naomi.Count; i++)
            {
                naomiD.Add(Double.Parse(naomi[i], CultureInfo.InvariantCulture));
                kenD.Add(Double.Parse(ken[i], CultureInfo.InvariantCulture));
            }
            naomiD.Sort();
            kenD.Sort();
            int deceitful = 0;
            int normal = 0;
            int j = 0;
            for (int i = 0; i < naomiD.Count; i++)
            {
                if (naomiD[i] > kenD[j])
                {
                    deceitful++;
                    j++;
                }
            }
            j = 0;
            for (int i = 0; i < kenD.Count; i++)
            {
                if (kenD[i] < naomiD[j]) normal++;
                else j++;
            }
            return deceitful.ToString() + " " +normal.ToString() ;
        }
    }
}
