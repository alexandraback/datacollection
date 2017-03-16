using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Round1BProblemA : Problem
    {
        protected override string SolveCase()
        {
            long totalCounts = 0;
            string target = ReadNextLineAsString();
            long targetNumber = Convert.ToInt64(target);
            if (target[target.Length - 1] == '0')
            {
                targetNumber--;
                target = targetNumber.ToString();
                totalCounts += 1;
            }
            int numberOfDigits = target.Length;
            totalCounts += CountUpToPowerTen(numberOfDigits - 1);
            string firstHalf = target.Substring(0, numberOfDigits / 2);
            string lastHalf = target.Substring(numberOfDigits / 2);
            if (targetNumber > 1)
            {
                totalCounts += Convert.ToInt64(lastHalf);
            }
            long firstHalfReversed = Convert.ToInt64("0" + String.Join("", firstHalf.ToCharArray().Reverse().ToArray()));
            if (firstHalfReversed > 1)
            {
                totalCounts += Convert.ToInt64(firstHalfReversed);
            }
            return totalCounts.ToString();
        }

        private long CountUpToPowerTen(int power)
        {
            if (power == 0)
            {
                return 1;
            }
            if (power == 1)
            {
                return 10;
            }
            return CountUpToPowerTen(power - 1) - 1
                + Convert.ToInt64(Math.Pow(10, power / 2))
                + Convert.ToInt64(Math.Pow(10, (power + 1) / 2));
        }
    }
}
