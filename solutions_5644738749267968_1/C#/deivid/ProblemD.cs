using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    public class ProblemD : ProblemBase
    {
        public ProblemD(string fileName)
            : base(fileName)
        {
        }

        protected override string SolveCase()
        {
            int N = ReadInt();
            var naomi = ReadIntList();
            var ken = ReadIntList();

            int deceitfulWar = DeceitfulWar(naomi.ToList(), ken.ToList());
            int war = War(naomi, ken);
            return string.Format("{0} {1}", deceitfulWar, war);
        }

        private int DeceitfulWar(List<int> naomi, List<int> ken)
        {
            int result = 0;
            while (naomi.Any())
            {
                int n = naomi.Max();
                int k = ken.Max();
                if (n > k)
                    result++;
                else
                {
                    n = naomi.Min();
                    k = ken.Max();
                    if (n > k)
                    {
                        result += naomi.Count;
                        break;
                    }
                }
                naomi.Remove(n);
                ken.Remove(k);
            }

            return result;
        }

        private int War(List<int> naomi, List<int> ken)
        {
            int result = 0;
            while (naomi.Any())
            {
                int n = naomi.Max();
                int k;
                if (ken.Where(b => b > n).Any())
                    k = ken.Where(b => b > n).Min();
                else
                    k = ken.Min();
                if (n > k)
                    result++;
                naomi.Remove(n);
                ken.Remove(k);
            }

            return result;
        }
    }
}
