using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ2015_1C_Denominations
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
            int newDenominations = 0;

            string[] parameters = Console.ReadLine().Split(' ');
            int C = int.Parse(parameters[0]);
            int D = int.Parse(parameters[1]);
            int V = int.Parse(parameters[2]);

            List<int> existingDenominations = Console.ReadLine().Split(' ').Select(i => int.Parse(i)).ToList();
            existingDenominations.Sort();

            for (int targetValue = 1; targetValue <= V; ++targetValue)
            {
                if (!CanValueBeComposed(existingDenominations, targetValue))
                {
                    existingDenominations.Add(targetValue);
                    existingDenominations.Sort();
                    newDenominations++;
                }
            }

            return newDenominations;
        }

        static bool CanValueBeComposed(List<int> existingDenominations, int targetSum)
        {
            if (existingDenominations.Count == 0)
            {
                return false;
            }

            List<int> tList = new List<int>(existingDenominations);

            foreach (var n in existingDenominations)
            {
                if (n == targetSum)
                {
                    return true;
                }

                tList.Remove(n);

                if (CanValueBeComposed(tList, targetSum - n))
                {
                    return true;
                }

                tList.Add(n);
            }

            return false;
        }
    }
}
