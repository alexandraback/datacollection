namespace ZTGCJ2014.Qualification_Round
{
    using System.Collections.Generic;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class CookieClickerAlpha : SolverBase
    {
        public CookieClickerAlpha()
            : base(@"Qualification Round\B-small-attempt0")
        {
        }

        public override void Solve(InputHelper input)
        {
            var C = input.ReadDouble();
            var F = input.ReadDouble();
            var X = input.ReadDouble();

            var s = 2.0;
            var res = X / 2.0;

            if (X > C)
            {
                var pre = C / s;

                while (true)
                {
                    s += F;
                    var cur = pre + X / s;

                    if (cur > res) break;

                    res = cur;
                    pre += C / s;
                }
            }

            this.SetResult(string.Format("{0:F7}", res));
        }
    }
}
