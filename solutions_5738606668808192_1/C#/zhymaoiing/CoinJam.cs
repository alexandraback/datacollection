namespace ZT.Contests.GCJ2015.Qualification_Round
{
    using System;
    using System.Collections.Concurrent;
    using System.Collections.Generic;
    using System.Linq;
    using System.Numerics;
    using System.Threading.Tasks;
    using ZT.Common;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.Numeric.Extensions;
    using ZT.Common.InputHelper;
    using ZT.Common.Math;

    internal class CoinJam : GcjSolverBase
    {
        private static TimeSpan Timeout = TimeSpan.FromSeconds(60);

        private ConcurrentBag<string> resultBag;

        private ConcurrentQueue<CoinJamNumber> numberSource;

        private int targetResultCount;

        public CoinJam() : base("C", "Qualification Round",null, new[] {"large"}) { }

        public override void Solve(InputHelper input)
        {
            int n = input.ReadInt();
            var validItems = new ConcurrentDictionary<BigInteger, string>();

            this.targetResultCount = input.ReadInt();
            this.resultBag = new ConcurrentBag<string>();
            this.numberSource = new ConcurrentQueue<CoinJamNumber>(FindCoinJam(n).Where(c => validItems.TryAdd(c.Number, null)).Take(this.targetResultCount * 2));

            var tasks = Misc.GetNaturalNumber().Take(32).Select(i => Task.Run(() => this.ScheduleNext()));
            Task.WaitAll(tasks.ToArray());
            this.SetResult(string.Join(string.Empty, resultBag.Take(this.targetResultCount).Select(r => string.Concat(Environment.NewLine, r))));
        }

        private async Task ScheduleNext()
        {
            CoinJamNumber c;
            this.numberSource.TryDequeue(out c);

            var strResult = Task.Run(() => c.ToString());
            if (strResult.Wait(Timeout))
            {
                this.resultBag.Add(strResult.Result);
                Console.WriteLine($"{this.Name} {c.Number} | current result count {resultBag.Count}");
            }
            else
            {
                Console.WriteLine($"{this.Name} killed {c.Number} because it gets timeout");
            }

            if (this.resultBag.Count < this.targetResultCount)
            {
                await Task.Run(() => this.ScheduleNext());
            }
        }

        private static IEnumerable<CoinJamNumber> FindCoinJam(int n)
        {
            var highAndLow = (1L << (n - 1)) + 1;
            return Misc.GetNaturalNumber().Select(d => new CoinJamNumber(d*2 + highAndLow)).Where(c => c.IsValid);
        }

        private class CoinJamNumber
        {
            private static readonly int[] Bases = Misc.GetNaturalNumber().Skip(2).Take(9).ToArray();
            private readonly BigInteger[] numbers;

            public CoinJamNumber(BigInteger number)
            {
                this.numbers = Bases.Select(b => number.GetBits().Reverse().Aggregate(BigInteger.Zero, (r, c) => r * b + c)).ToArray();
            }

            /// <summary>
            /// 10-based coin-jam number.
            /// </summary>
            public BigInteger Number => this.numbers.Last();

            public bool IsValid => Bases.All(b => !MillerRabinPrimeTest.TestPrimality(this.numbers[b - 2]));

            private IEnumerable<BigInteger> GetDivisor(int baseN) => FactorUtility.GetDivisors(this.numbers[baseN - 2]);

            public override string ToString()
            {
                //return string.Join(" ", new[] {this.GetNumber(10)}.Concat(.Concat(Bases.Select(b => this.GetDivisor(b).First()))));
                return string.Join(" ", new[] { this.numbers.Last() }.Concat(Bases.Select(b => this.GetDivisor(b).First())));
                //return string.Join(" ", new[] { this.GetNumber(10) }.Concat(Bases.Select(this.GetNumber)));
            }
        }
    }
}
