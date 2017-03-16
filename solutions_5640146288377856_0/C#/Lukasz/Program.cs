using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ2015_1C_Brattleship
{
    class Program
    {
        const string TestCaseFormatPrefix = "Case #{0}: {1}";

        static void Main(string[] args)
        {
            int numberOfCases = int.Parse(Console.ReadLine());

            for (int caseI = 0; caseI < numberOfCases; ++caseI)
            {
                var result = SolveTestCase();

                Console.WriteLine(TestCaseFormatPrefix, caseI + 1, result);
            }
        }

        private static int SolveTestCase()
        {
            string[] parameters = Console.ReadLine().Split(' ');
            int R = int.Parse(parameters[0]);
            int C = int.Parse(parameters[1]);
            int W = int.Parse(parameters[2]);

            if (W == 1)
            {
                return R * C;
            }

            int numberOfTurnsForFirstHit = (R * C/W);

            if (C % W == 0)
            {
                return numberOfTurnsForFirstHit + W - 1;
            }
            else
            {
                return numberOfTurnsForFirstHit + W;
            }
        }
    }
}
