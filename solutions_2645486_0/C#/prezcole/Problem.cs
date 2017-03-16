using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;


namespace CodeJam
{
    class Problem
    {
        private const string INPUT_FILE = "B-small-attempt3.in";
        private const string OUTPUT_FILE = "B-small-attempt3.out";

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(INPUT_FILE);
            var output = new List<string>();
            int caseCounter = 0;
            for (int i = 1; i < input.Length; i += 2)
            {
                output.Add("Case #" + ++caseCounter + ": " + Execute(input[i], input[i + 1]));
                Console.WriteLine(caseCounter);
            }
            File.WriteAllLines(OUTPUT_FILE, output);
        }

        private static string Execute(string firstLine, string secondLine)
        {
            string[] firstLineSplit = firstLine.Split();
            int maxEnergy = Convert.ToInt32(firstLineSplit[0]);
            int rechargeEnergy = Convert.ToInt32(firstLineSplit[1]);

            string[] secondLineSplit = secondLine.Split();
            List<int> utility = secondLineSplit.Select(n => Convert.ToInt32(n)).ToList();
            int[] energyToSpend = new int[utility.Count];

            ExecuteRecurse(utility, energyToSpend, 0, utility.Count - 1, maxEnergy, 0, maxEnergy, rechargeEnergy);

            long result = 0;
            for (int i = 0; i < utility.Count; i++)
            {
                result += utility[i] * energyToSpend[i];
            }
            return result.ToString();
        }

        private static void ExecuteRecurse(List<int> utility, int[] energyToSpend, int startIndex, int endIndex, int startEnergy, int endEnergy, int maxEnergy, int rechargeEnergy)
        {
            if(startIndex > endIndex)
            {
                return;
            }

            int highValue = -1, highIndex = -1;
            for (int i = startIndex; i <= endIndex; i++)
            {
                if (utility[i] >= highValue)
                {
                    highValue = utility[i];
                    highIndex = i;
                }
            }

            int availableEnergyAtIndex = Math.Min(maxEnergy, startEnergy + (rechargeEnergy * (highIndex - startIndex)));
            int energyRequiredAfterIndex = Math.Max(endEnergy - (rechargeEnergy * (endIndex - highIndex + 1)), 0);
            int spendAtIndex = availableEnergyAtIndex - energyRequiredAfterIndex;
            energyToSpend[highIndex] = spendAtIndex;
            if (spendAtIndex < 0)
            {
                throw new Exception();
            }

            ExecuteRecurse(utility, energyToSpend, startIndex, highIndex - 1, startEnergy, spendAtIndex + energyRequiredAfterIndex, maxEnergy, rechargeEnergy);
            ExecuteRecurse(utility, energyToSpend, highIndex + 1, endIndex, availableEnergyAtIndex - spendAtIndex + rechargeEnergy, endEnergy, maxEnergy, rechargeEnergy);
        }
    }
}
