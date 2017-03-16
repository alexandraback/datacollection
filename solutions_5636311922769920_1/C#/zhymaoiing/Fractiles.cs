namespace ZT.Contests.GCJ2015.Qualification_Round
{
    using System.Collections.Generic;
    using System.Linq;
    using System.Numerics;
    using ZT.Common;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.InputHelper;

    internal class Fractiles : GcjSolverBase
    {
        public Fractiles() : base("D", "Qualification Round") { }

        public override void Solve(InputHelper input)
        {
            int k = input.ReadInt(), c = input.ReadInt(), s = input.ReadInt();

            if (s*c < k)
            {
                this.SetResult("IMPOSSIBLE");
            }
            else
            {
                var resSequence = new List<BigInteger>();
                for (int i = 0; i < k; i += c)
                {
                    var candidate = i + c > k
                        ? Misc.GetNaturalNumber(i).Take(k - i).Concat(Misc.GetNaturalNumber().Take(c - k + i))
                        : Misc.GetNaturalNumber(i).Take(c);
                    resSequence.Add(candidate.Aggregate(BigInteger.Zero, (r, l) => r * k + l) + 1);
                }
                this.SetResult(string.Join(" ", resSequence));
            }
        }
    }
}
