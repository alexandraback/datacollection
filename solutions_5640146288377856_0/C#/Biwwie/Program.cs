using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    class Program
    {
        public const string INPUTFILENAME = "A-small-attempt3.in";
        public const string RESULTFORMAT = "Case #{0}: {1}";
        public const string FOLDERPATH = @"C:\Users\Billy\Desktop\Working\CodeJam\InputOutput\{0}";

        static void Main(string[] args)
        {
            string OUTPUTFILENAME = INPUTFILENAME.Split('.')[0] + ".txt";
            string inputFilePath = string.Format(FOLDERPATH, INPUTFILENAME); // the full file path used
            string outputFilePath = string.Format(FOLDERPATH, OUTPUTFILENAME); // the full file path used

            if (!File.Exists(inputFilePath))
                throw new Exception("Input file does not exist!");

            using (StreamReader inputFile = new StreamReader(inputFilePath))
            using (StreamWriter outputFile = new StreamWriter(outputFilePath))
            {

                #region Problem Meta Data
                int TT; // Total Tests
                if (!int.TryParse(inputFile.ReadLine(), out TT))
                    throw new Exception("Missing first line?");

                // Additional Data

                Console.WriteLine("Total Test Cases: " + TT);
                #endregion

                // Compute each test case
                for (int t = 1; t <= TT; t++) 
                {
                    #region Test Data
                    int[] myInts = Array.ConvertAll(inputFile.ReadLine().Split(' '), s => int.Parse(s));
                    int R = myInts[0];
                    int C = myInts[1];
                    int W = myInts[2];

                    #endregion
                    #region Do Work
                    string result = string.Empty;
                    
                    if (W == 1)
                        result = (R * C).ToString();
                    else if (W == C)
                        result = (C + (R - 1)).ToString();
                    else
                    {
                        // test for each row
                        int tests = C / W;
                        int remainder = C % W;
                        int lastRow = (tests + (W - 1));
                        if (remainder > 0)
                            lastRow++;
                        int otherRows = (tests * (R - 1));
                        result = (otherRows + lastRow).ToString();
                    }

                    // result = ?

                    #endregion
                    result = string.Format(RESULTFORMAT, t, result);
                    outputFile.WriteLine(result);
                    Console.WriteLine(result);
                }
            }
        }
    }
}
