using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2012
{
    class Program
    {
        const string ConstFileNewlineFormat = "\n";
        const string ConstFilename = "C-small-attempt0";

        /// <summary>
        /// Main entry point. 
        /// </summary>
        /// <param name="args">The args.</param>
        static void Main(string[] args)
        {
            SolveC();
        }

        /// <summary>
        /// Solves the C problem.
        /// </summary>
        public static void SolveC()
        {
            var dataStringInput = ReadFile("c:\\temp\\" + ConstFilename + ".in");
            StringBuilder dataStringOutput = new StringBuilder();

            var data = dataStringInput.Split(new string[] { ConstFileNewlineFormat }, System.StringSplitOptions.None);

            // variable declaration
            int casesT = 0;
            string[] numbers;

            // data reading into variables and solving cases
            int elem = 0;
            casesT = Convert.ToInt32(data[elem]);
            elem++;

            for (int n = 0; n < casesT; n++)
            {
                numbers = data[elem].Split(new char[] { ' ' }).ToArray();
                elem++;

                // -------------------------------------------------------------------------
                int pairsCount = 0;

                int num1 = Convert.ToInt32(numbers[0]);
                int num2 = Convert.ToInt32(numbers[1]);

                Dictionary<string, int> values = new Dictionary<string, int>();
                string currentNumberStr;
                string recicleRezStr;
                int recicleRezInt;
                string key;


                for (int currentNumberInt = num1; currentNumberInt <= num2; currentNumberInt++)
                {
                    currentNumberStr = currentNumberInt.ToString();

                    // using variable count of digits...
                    for (int splitPos = 1; splitPos < currentNumberStr.Length; splitPos++)
                    {
                        // skip transferring to front '0'
                        if (currentNumberStr[splitPos] == '0')
                            continue;

                        recicleRezStr = currentNumberStr.Substring(splitPos) + currentNumberStr.Substring(0, splitPos);
                        recicleRezInt = Convert.ToInt32(recicleRezStr);

                        if (recicleRezInt > currentNumberInt && recicleRezInt <= num2)
                        {
                            key = currentNumberStr + "_" + recicleRezStr;

                            if (!values.ContainsKey(key))
                                values.Add(key, recicleRezInt);
                        }
                    }
                }

                pairsCount = values.Count;

                // formatting output
                dataStringOutput.Append("Case #");
                dataStringOutput.Append(n + 1);
                dataStringOutput.Append(": ");
                dataStringOutput.AppendLine(pairsCount.ToString());
            }

            // -------------------------------------
            // all cases solved, writing output file
            WriteFile("C:\\temp\\" + ConstFilename + ".out", dataStringOutput.ToString());
        }

        /// <summary>
        /// Reads the file.
        /// </summary>
        /// <param name="filePath">The file path.</param>
        /// <returns>Contents of the file.</returns>
        public static string ReadFile(string filePath)
        {
            string rez = string.Empty;

            using (StreamReader sr = new StreamReader(filePath))
            {
                rez = sr.ReadToEnd();
            }

            return rez;
        }

        /// <summary>
        /// Writes the content to the file.
        /// </summary>
        /// <param name="filePath">The file path.</param>
        /// <param name="content">The content.</param>
        public static void WriteFile(string filePath, string content)
        {
            using (StreamWriter sr = new StreamWriter(filePath))
            {
                sr.Write(content);
            }
        }
    }
}
