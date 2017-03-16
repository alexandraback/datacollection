namespace ZTGCJ2014.Round_1C
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class ReorderingTrainCars : SolverBase
    {
        public ReorderingTrainCars()
            //: base(@"Round 1C\B-large")
            : base(@"Round 1C\B-small-attempt0")
            //: base(@"Round 1C\sample")
        {
        }

        public override void Solve(InputHelper input)
        {
            SolveEasy(input);
        }

        private void SolveEasy(InputHelper input)
        {
            int n = input.ReadInt();
            var trains = new List<string>();
            var array = new int[n];
            for (int i = 0; i < n; ++i)
            {
                trains.Add(input.ReadString());
                array[i] = i;
            }
            int cnt = 0;
            var res = new StringBuilder();
            do
            {
                res.Clear();
                array.ForEach(x => res.Append(trains[x]));
                var set = new HashSet<char>();
                char last = ' ';
                bool fail = false;
                foreach (var c in res.ToString())
                {
                    if (c != last)
                    {
                        if (set.Contains(c))
                        {
                            fail = true;
                            break;
                        }
                        else
                        {
                            last = c;
                            set.Add(c);
                        }
                    }
                }
                if (!fail) ++cnt;
            } while (array.NextPermutation());
            this.SetResult(cnt);
        }
    }
}
