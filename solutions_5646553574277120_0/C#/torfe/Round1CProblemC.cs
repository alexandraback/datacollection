using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Round1CProblemC : Problem
    {
        protected override string SolveCase()
        {
            int[] parameters = ReadNextLineAsInt32Array();
            int numberOfCurrent = parameters[1];
            int maxValue = parameters[2];

            List<int> currentValues = ReadNextLineAsInt32Array().ToList();
            List<int> combinations = AllCombinations(currentValues, maxValue);
            int addedValueCount = 0;
            while (combinations.Count < maxValue + 1)
            {
                addedValueCount++;
                currentValues.Add(SmallestMissingValue(combinations, maxValue));
                combinations = AllCombinations(currentValues, maxValue);
            }
            return addedValueCount.ToString();
        }

        private List<int> AllCombinations(List<int> denominationValues, int maxValue)
        {
            List<int> combinations = new List<int> { 0 };

            foreach (var value in denominationValues)
            {
                combinations = combinations.Union(combinations.Select(i => i + value))
                    .Where(i => i <= maxValue).Distinct().ToList();
            }

            return combinations;
        }

        private int SmallestMissingValue(List<int> combinations, int maxValue)
        {
            combinations = combinations.OrderBy(i => i).ToList();
            for (int i = 1; i <= maxValue; i++)
            {
                if (combinations.Count < i + 1 || combinations[i] != i)
                {
                    return i;
                }
            }
            return 0;
        }
    }
}
