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
            int allowedRepeats = parameters[0];
            int numberOfCurrent = parameters[1];
            int maxValue = parameters[2];

            List<long> currentValues = ReadNextLineAsInt64Array().ToList();

            int addedValueCount = 0;
            long value = 1;
            while (value <= maxValue)
            {
                long sum = currentValues.Where(i => i <= value).Sum() * allowedRepeats;
                if (sum < value)
                {
                    addedValueCount++;
                    currentValues.Add(value);
                }
                value = sum + 1;
            }
            return addedValueCount.ToString();
        }
    }
}
