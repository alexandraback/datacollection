using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemA
{
    class Program
    {
        private static readonly StreamWriter StreamWriter =
            new StreamWriter(@"C:\codejam\2014-round1C\in-out\A-large.out");

        private const string InputFile = @"C:\codejam\2014-round1C\in-out\A-large.in";

        private static void Main()
        {
            string[] input = File.ReadAllLines(InputFile);

            int line = 0;
            int t = int.Parse(input[line++]);

            for (int i = 0; i < t; i++)
            {
                string[] values = input[line++].Split('/');

                long p, q;
                p = long.Parse(values[0]);
                q = long.Parse(values[1]);

                long powQ = 0;
                while (q % 2 == 0)
                {
                    q /= 2;
                    powQ++;
                }

                if(p % q == 0)
                {
                    p /= q;
                    q = 1;
                }

                long powP = 0;
                while (p > 1)
                {
                    p /= 2;
                    powP++;
                }

                if (q != 1)
                {
                    StreamWriter.Write("Case #{0}: {1}", i + 1, "impossible");
                }
                else
                {
                    StreamWriter.Write("Case #{0}: {1}", i + 1, powQ-powP);
                }
                StreamWriter.WriteLine();
            }
            StreamWriter.Close();
        }
    }
}
