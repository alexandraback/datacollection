namespace ZT.Contests.GCJ2015.Qualification_Round
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using ZT.Common;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.Numeric.Extensions;
    using ZT.Common.InputHelper;
    using ZT.Common.Math;

    internal class CoinJam : GcjSolverBase
    {
        private static readonly PrimeProxy Proxy = new PrimeProxy((int) 1e8);

        public CoinJam() : base("C", "Qualification Round") { }

        public override void Solve(InputHelper input)
        {
            int n = input.ReadInt(), j = input.ReadInt();
            this.SetResult(string.Join(string.Empty, FindCoinJam(n).Take(j).Select(c => string.Concat(Environment.NewLine, c))));
        }

        private static IEnumerable<CoinJamNumber> FindCoinJam(int n)
        {
            var candidates = n <= 22 ? Misc.GetNaturalNumber().Take(1 << (n - 2)) : Misc.GetRandomNumber(1 << (n - 2));
            var highAndLow = (1L << (n - 1)) + 1;
            return candidates.Select(d => new CoinJamNumber(Proxy, d*2 + highAndLow)).Where(c => c.IsValid);
        }

        private class CoinJamNumber
        {
            private static readonly int[] Bases = Misc.GetNaturalNumber().Skip(2).Take(9).ToArray();

            private readonly PrimeProxy primeProxy;

            /// <summary>
            /// 2-based coin-jam number.
            /// </summary>
            private readonly long number;

            public CoinJamNumber(PrimeProxy primeProxy, long number)
            {
                this.primeProxy = primeProxy;
                this.number = number;
            }

            public bool IsValid { get { return Bases.All(b => !this.primeProxy.TestPrimality(this.GetNumber(b))); } }

            public IEnumerable<long> GetDivisor(int baseN) { return this.primeProxy.GetPrimeFactors(this.GetNumber(baseN)); }

            private long GetNumber(int baseN) { return this.number.GetBits().Reverse().Aggregate(0L, (r, c) => r * baseN + c); }

            public override string ToString()
            {
                return string.Join(" ", new[] {this.GetNumber(10)}.Concat(Bases.Select(b => this.GetDivisor(b).First())));
            }
        }
    }
}
