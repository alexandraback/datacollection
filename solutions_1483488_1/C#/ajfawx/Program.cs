using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace RecycledNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            // File IO
            StreamReader input = new StreamReader(@"..\input.in");
            StringBuilder result = new StringBuilder();

            // Number of cases
            byte numCases = Convert.ToByte(input.ReadLine());
            // Loop through each case
            for (byte T = 0; T < numCases; T++)
            {
                // Read parameters
                string[] param = input.ReadLine().Split(new char[] { ' ' });
                int A = Convert.ToInt32(param[0]);
                int B = Convert.ToInt32(param[1]);
                int numDigits = param[0].Length;

                List<RecycledPair> recycledPairs = new List<RecycledPair>();

                for (int n = A; n <= B; n++)
                {
                    for (int i = 1; i < numDigits; i++)
                    {
                        string N = n.ToString();
                        string p = N.Substring(i);
                        string q = N.Substring(0, i);
                        int m = Convert.ToInt32(p + q);

                        if (B >= m && m > n)
                            recycledPairs.Add(new RecycledPair() { n = n, m = m });
                    }
                }
                // Store result
                result.AppendLine(String.Format("Case #{0}: {1}", T + 1, recycledPairs.Distinct().Count()));
            }

            // Print result
            Console.Write(result.ToString());

            File.WriteAllText(@"..\output.txt", result.ToString());
        }
    }

    struct RecycledPair
    {
        public int n;
        public int m;
    }
}
