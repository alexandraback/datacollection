using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam._2016r1c
{
    class ProblemC : IProblemSolver
    {
        public bool UsedBruteForce
        {
            get
            {
                return false;
            }
        }

        public string BruteForce(int caseNo)
        {
            throw new NotImplementedException();
        }

        int J, P, S, k;

        public void ProcessInput()
        {
            int[] data = GCJ.io.nextLineSeparatedAsInt();
            J = data[0];
            P = data[1];
            S = data[2];
            k = data[3];
        }

        public void Seed()
        {
            
        }

        private static bool CanWear(Dictionary<string, int> worn, int j, int p, int s, int k)
        {
            var jp = j + "_" + p + "_" + 0;
            var js = j + "_" + 0 + "_" + s;
            var ps = 0 + "_" + p + "_" + s;
            if (!worn.ContainsKey(jp)) worn[jp] = 0;
            if (!worn.ContainsKey(js)) worn[js] = 0;
            if (!worn.ContainsKey(ps)) worn[ps] = 0;
            if(worn[jp] < k && worn[js] < k && worn[ps] < k)
            {
                worn[jp]++;
                worn[js]++;
                worn[ps]++;
                return true;
            }
            return false;
        }

        public string Solve(int caseNo)
        {
            Dictionary<string, int> worn = new Dictionary<string, int>();
            List<string> result = new List<string>();
            for (int j = 1; j <= J; j++)
            {
                for (int p = 1; p <= P; p++)
                {
                    for (int s = 1; s <= S; s++)
                    {
                        if (CanWear(worn, j, p, s, k))
                        {
                            result.Add(j + " " + p + " " + s);
                        }
                    }
                }
            }
            GCJ.io.Write(string.Format("Case #{0}: {1}", caseNo, result.Count));
            foreach(var res in result)
            {
                GCJ.io.Write(res);
            }
            return result.Count.ToString();
        }
    }
}
