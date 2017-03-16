namespace ZT.Contests.GCJ2015.Qualification_Round
{
    using System.Linq;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.InputHelper;

    internal class RevengeOfThePancakes : GcjSolverBase
    {
        public RevengeOfThePancakes() : base("B", "Qualification Round") { }

        public override void Solve(InputHelper input)
        {
            var pancakes = input.ReadString().TrimEnd('+');

            if (string.IsNullOrEmpty(pancakes))
            {
                this.SetResult(0);
                return;
            }

            var prev = pancakes[0];
            var count = 0;
            foreach (var c in pancakes.Skip(1).Concat(new[] { '+' }))
            {
                if (prev == c) continue;
                if (prev == '-') ++count;
                prev = c;
            }

            this.SetResult(2 * count - 1 + (pancakes[0] == '+' ? 1 : 0));
        }
    }
}
