namespace ZTGCJ2014.Round_1C
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class Enclosure : SolverBase
    {
        public Enclosure()
            //: base(@"Round 1C\C-large")
            : base(@"Round 1C\C-small-attempt0")
            //: base(@"Round 1C\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            int N = input.ReadInt(), M = input.ReadInt(), K = input.ReadInt();
            int r = K;
            if (K <= N || K <= M) r = K;
            if (K <= 2 * N || K <= 2 * M) r = K;
            for (int a = 3; a <= N; ++a)
                for (int b = 3; b <= M; ++b)
                {
                    int c = a * b - 4;
                    if (c >= K)
                    {
                        int d = Math.Max(0, a - 2) * Math.Max(0, b - 2);
                        r = Math.Min(r, c - d);
                    }
                }
            this.SetResult(r);
        }
    }
}
