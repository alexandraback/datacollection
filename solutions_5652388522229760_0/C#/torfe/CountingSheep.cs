using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{
    public class CountingSheep : Problem
    {
        private int[] powersOfTwo = new int[] { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
        private int allDigitsSeen = 1023;
        private int digitsSeen = 0;

        protected override string SolveCase()
        {
            this.digitsSeen = 0;
            var n = this.ReadNextLineAsInt32();

            if (n == 0)
            {
                return "INSOMNIA";
            }

            var multiple = 0;

            while (this.digitsSeen != this.allDigitsSeen)
            {
                multiple += n;
                this.RecordDigitsSeen(multiple);
            }

            return multiple.ToString();
        }

        private void RecordDigitsSeen(int number)
        {
            var digits = number.ToString().ToCharArray().Select(c => Convert.ToInt32(c.ToString()));
            foreach (var d in digits)
            {
                this.digitsSeen |= this.powersOfTwo[d];
            }
        }
    }
}
