using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJamSolutions
{
    class StandingOvation
    {
        private List<int[]> LoadData()
        {
            var fileName = "A-small-attempt0.in";

            var res = new List<int[]>();
            using(var f = new StreamReader(fileName))
            {
                var testCases = int.Parse(f.ReadLine());
                for(int i = 0; i < testCases; ++i)
                {
                    var curLine = f.ReadLine();
                    var s = curLine.Split(' ');

                    var smax = int.Parse(s[0]);
                    var shy = new int[smax + 1];

                    for(int j = 0; j <= smax; ++j)
                    {
                        shy[j] = s[1][j] - '0';
                    }
                    res.Add(shy);
                }
            }

            return res;
        }

        public void Solve()
        {
            var distribution = LoadData();

            var result = new int[distribution.Count];
            for(int i = 0; i < distribution.Count; ++i)
            {
                var r = SolveConcrete(distribution[i]);
                result[i] = r;
            }

            WriteSolution(result);
        }

        private int SolveConcrete(int[] distr)
        {
            var additionallyInvited = 0;
            var alreadyStanduped = 0;
            for(int i = 0; i < distr.Length; ++i)
            {
                var delta = additionallyInvited + alreadyStanduped - i;
                if(delta >= 0)
                {
                    alreadyStanduped += distr[i];
                    continue;
                }

                additionallyInvited += -delta;
                alreadyStanduped += distr[i];
            }

            return additionallyInvited;
        }

        private void WriteSolution(int[] result)
        { 
            using(var o = new StreamWriter("out.txt"))
            {
                for(int i = 0; i < result.Length; ++i)
                {
                    o.WriteLine("Case #{0}: {1}", i + 1, result[i]);
                }
            }
        }
    }
}
