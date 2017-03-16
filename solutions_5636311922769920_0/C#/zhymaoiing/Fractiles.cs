namespace ZT.Contests.GCJ2015.Qualification_Round
{
    using System.Linq;
    using ZT.Common;
    using ZT.Common.Contest.GCJ;
    using ZT.Common.InputHelper;

    internal class Fractiles : GcjSolverBase
    {
        public Fractiles() : base("D", "Qualification Round") { }

        public override void Solve(InputHelper input)
        {
            int k = input.ReadInt(), c = input.ReadInt(), s = input.ReadInt();
            this.SetResult(string.Join(" ", Misc.GetNaturalNumber().Skip(1).Take(s)));
        }
    }
}
