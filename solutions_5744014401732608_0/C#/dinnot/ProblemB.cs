using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam._2016r1c
{
    class ProblemB : IProblemSolver
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

        ulong b, m;
        bool[,] mat;

        public void ProcessInput()
        {
            ulong[] tdata = GCJ.io.nextLineSeparatedAsULong();
            b = tdata[0];
            m = tdata[1];
            mat = new bool[b, b];
        }

        public void Seed()
        {

        }

        public string Solve(int caseNo)
        {
            ulong max = 1;
            for (ulong i = 0; i < b - 2; i++) max *= 2;
            if(m > max)
            {
                GCJ.io.Write(string.Format("Case #{0}: IMPOSSIBLE", caseNo));
                return "IMPOSSIBLE";
            }
            GCJ.io.Write(string.Format("Case #{0}: POSSIBLE", caseNo));
            //enable all roads up to b-1
            for(ulong i = 1; i < b - 1; i++)
            {
                for(ulong j = 0; j < i; j++)
                {
                    mat[j,i] = true;
                }
            }
            if (m == max) mat[0, b - 1] = true;
            m--;
            ulong idx = 1;
            while(m > 0)
            {
                if(m % 2 == 1)
                {
                    mat[idx, b - 1] = true;
                }
                idx++;
                m /= 2;
            }
            for(ulong i = 0; i < b; i++)
            {
                List<char> res = new List<char>();
                for(ulong j = 0; j < b; j++)
                {
                    res.Add(mat[i, j] ? '1' : '0');
                }
                GCJ.io.Write(new string(res.ToArray()));
            }
            return "POSSIBLE";
        }
    }
}
