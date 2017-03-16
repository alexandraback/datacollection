using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{
    public class CoinJam : Problem
    {
        private int[] powersOfTwo = new int[] { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192 };

        /// <summary>
        /// Note that 110...011 is divisible by 11 whatever base the number is in.
        /// Thus, adding other multiples of 11 still leaves you with a non-prime.
        /// </summary>
        protected override string SolveCase()
        {
            var parameters = this.ReadNextLineAsInt32Array();
            var n = parameters[0];
            var j = parameters[1];

            this.WriteCaseOutput(1, string.Empty);
            var divisors = string.Join(" ", Enumerable.Range(3, 9));

            for (int i = 0; i < j; i++)
            {
                var coin = this.CreateCoin(n, i);
                // this.ValidateNumber(coin);
                this.WriteLineToFile(string.Format(
                    "{0} {1}",
                    coin,
                    divisors));
            }

            return null;
        }

        private string CreateCoin(int length, int sequence)
        {
            var coin = "11";

            for (int i = 0; i < (length - 4) / 2; i++)
            {
                coin += (sequence & this.powersOfTwo[i]) > 0 ? "11" : "00";
            }

            return coin + "11";
        }

        /// <summary>
        /// Won't work for the large case as 32 digit numbers are beyond long's range
        /// </summary>
        private void ValidateNumber(string number)
        {
            for (int b = 2; b < 10; b++)
            {
                var inBase = this.NumberInBase(
                    number.ToCharArray().Select(c => c == '1' ? 1 : 0).ToArray(), b);
                if (inBase % (b + 1) != 0)
                {
                    throw new ApplicationException("Something's wrong!");
                }
            }
        }

        private long NumberInBase(int[] number, int b)
        {
            long o = 0;
            long power = 1;

            foreach (var i in number)
            {
                o += power * i;
                power *= b;
            }

            return o;
        }
    }
}
