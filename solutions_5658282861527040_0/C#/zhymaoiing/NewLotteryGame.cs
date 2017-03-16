namespace ZTGCJ2014.Round_1B
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class NewLotteryGame : SolverBase
    {
        public NewLotteryGame()
            //: base(@"Round 1B\B-large")
            : base(@"Round 1B\B-small-attempt0")
        //: base(@"Round 1B\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            int A = input.ReadInt();
            int B = input.ReadInt();
            int K = input.ReadInt();

            int r = 0;
            for (int i = 0; i < A; ++i)
                for (int j = 0; j < B; ++j)
                    if ((i & j) < K)
                        ++r;
            this.SetResult(r);
        }
    }
}
