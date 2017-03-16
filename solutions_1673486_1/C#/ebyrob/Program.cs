using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace PasswordProblem
{
    class Program
    {
        protected static string CalculateSlow(decimal []probabilities, int B)
        {
            decimal keystrokes = 0;

            //enter now to cancel
            keystrokes = 2 + B;

            //backspace N times then continue:
            // 0 - probabilities.Length
            for (int numBackspaces = 0; numBackspaces <= probabilities.Length; ++numBackspaces)
            {
                decimal probSuccess = 1;
                for (int i = 0; i < probabilities.Length - numBackspaces; ++i)
                {
                    probSuccess *= probabilities[i];
                }
                decimal successLength = 1 + B - probabilities.Length + 2 * numBackspaces;
                decimal failLength = successLength + 1 + B;
                decimal length = successLength * probSuccess + failLength * (1 - probSuccess);
                if (length < keystrokes)
                    keystrokes = length;
            }

            return string.Format("{0:0.000000}", keystrokes);
        }

        protected static string Calculate(decimal[] probabilities, int B)
        {
            decimal keystrokes = 0;

            //enter now to cancel
            keystrokes = 2 + B;

            //backspace N times then continue:
            // 0 - probabilities.Length
            decimal probSuccess = 1;
            for (int i = 0; i < probabilities.Length; ++i)
            {
                probSuccess *= probabilities[i];

                decimal successLength = 1 + B - probabilities.Length + 2 * (probabilities.Length-i-1);
                decimal failLength = successLength + 1 + B;
                decimal length = successLength * probSuccess + failLength * (1 - probSuccess);
                if (length < keystrokes)
                    keystrokes = length;
            }

            return string.Format("{0:0.000000}", keystrokes);
        }

        static void Main(string[] args)
        {
            string inFileName = args[0];
            string outFileName = inFileName.Split('.')[0] + ".out";
            StreamReader inFile = new StreamReader(inFileName);
            StreamWriter outFile = new StreamWriter(outFileName);

            DateTime start = DateTime.Now;

            List<string> lines = new List<string>();
            int nCases = int.Parse(inFile.ReadLine());
            for (int iCase = 0; iCase < nCases; ++iCase)
            {
                string []line = inFile.ReadLine().Split(' ');
                int A = int.Parse(line[0]);
                int B = int.Parse(line[1]);

                line = inFile.ReadLine().Split(' ');
                decimal[] probabilities = new decimal[A];
                for (int i = 0; i < A; ++i)
                {
                    probabilities[i] = decimal.Parse(line[i]);
                }

                string result = Calculate(probabilities, B);

                outFile.WriteLine("Case #{0}: {1}", iCase + 1, result);
                outFile.Flush();
            }
            inFile.Close();
            outFile.Close();

            Console.WriteLine("Elapsed Time: {0:t}", DateTime.Now - start);
        }
    }
}
