using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inFile = new StreamReader("a.in");
            StreamWriter outFile = new StreamWriter("a.out");

            Pt pt;

            int csCnt = Convert.ToInt32(inFile.ReadLine());
            for (int csId = 1; csId <= csCnt; csId++)
            {
                string[] spt = inFile.ReadLine().Split();
                int n = Convert.ToInt32(spt[0]);
                List<Pt> scores = new List<Pt>();
                int sum = 0;
                for (int i = 1; i <= n; i++)
                {
                    pt.score = Convert.ToInt32(spt[i]);
                    pt.index = i - 1;
                    scores.Add(pt);
                    sum += pt.score;
                }
                scores.Sort();

                int m = n - 1;
                int tmpSum = 0;
                while (m >= 0 && scores[m].score * (m + 1) + tmpSum > 2 * sum)
                {
                    tmpSum += scores[m].score;
                    m--;
                }

                int ssmall = 0;
                for (int i = 0; i <= m; i++) ssmall += scores[i].score;

                double avg = (double)(sum + ssmall) / (m + 1);

                double[] ans = new double[n];
                for (int i = 0; i <= m; i++)
                {
                    ans[scores[i].index] = (avg - scores[i].score) / sum * 100;
                }

                outFile.Write("Case #{0}:", csId);
                for (int i = 0; i < n; i++)
                {
                    outFile.Write(" {0}", ans[i]);
                }
                outFile.WriteLine();
            }


            inFile.Close();
            outFile.Close();
        }

    }

    struct Pt : IComparable<Pt>
    {
        public int score, index;

        public int CompareTo(Pt other)
        {
            return this.score - other.score;
        }
    }
}
