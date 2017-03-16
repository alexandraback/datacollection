using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2008_1a
{
    class DeceitfulWar
    {
        static void Main(string[] args)
        {
            var me = new Numbers();
            using (var helper = new CodeJamHelper('D', ProblemType.Small, 0))
            {
                var numTestCases = helper.ReadLineInt32();
                foreach (var caseNum in Enumerable.Range(1, numTestCases))
                {
                    var N = helper.ReadLineInt32();
                    var naomi = helper.ReadDoubleArray();
                    var ken = helper.ReadDoubleArray();
                    helper.OutputCase(DeceitfulWarPoints(naomi, ken), WarPoints(naomi, ken));
                }
            }
        }

        static int WarPoints(double[] naomiUnsorted, double[] kenUnsorted)
        {
            var naomi = naomiUnsorted.OrderBy(x => x).ToList();
            var ken = kenUnsorted.OrderBy(x => x).ToList();

            //Naomi's optimal strategy is to play her lighest blocks first, hoping to "promote" her heavier blocks by Ken having inefficient wins.
            int score = 0;
            foreach (double naomiWeight in naomi)
            {
                bool kenWins = false;
                for(int i=0; i < ken.Count; ++i)
                {
                    if(ken[i] > naomiWeight)
                    {
                        ken.RemoveAt(i);
                        kenWins = true;
                        break;
                    }
                }
                //Ken can't win, so he throws away his lightest block.
                if(!kenWins)
                {
                    score += 1;
                    ken.RemoveAt(0);
                }
            }
            return score;
        }

        static int DeceitfulWarPoints(double[] naomiUnsorted, double[] kenUnsorted)
        {
            var naomi = naomiUnsorted.OrderBy(x => x).ToList();
            var ken = kenUnsorted.OrderBy(x => x).ToList();

            int score = 0;
            while (naomi.Count > 0)
            {
                //If Naomi has the heaviest block, then she may as well win with that, she can't deceive Ken anyway.
                if (naomi.Last() > ken.Last())
                {
                    score += 1;
                    naomi.RemoveAt(naomi.Count - 1);
                    ken.RemoveAt(ken.Count - 1);
                }
                else
                {
                    //Otherwise, she plays her lighest block, calling it just lighter than Ken's heaviest block
                    naomi.RemoveAt(0);
                    ken.RemoveAt(ken.Count - 1);
                }
            }
            return score;
        }

    }
}
