namespace ZT.Contests.GCJ2015.Qualification_Round
{
    using System.Collections.Generic;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.Extensions;
    using ZT.Common.InputHelper;
    using ZT.Common.Numeric.Extensions;

    internal class CountingSheep : GcjSolverBase
    {
        public CountingSheep() : base("A", "Qualification Round") { }

        public override void Solve(InputHelper input)
        {
            var n = input.ReadLong();

            if (n == 0)
            {
                this.SetResult("INSOMNIA");
                return;
            }

            var digitSet = new HashSet<int>();
            var cur = 0L;
            while (digitSet.Count < 10) (cur += n).Digits().ForEach(d => digitSet.Add(d));
            this.SetResult(cur);
        }
    }
}
