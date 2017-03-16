using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inFile = new StreamReader("b.in");
            StreamWriter outFile = new StreamWriter("b.out");

            int cCnt = Convert.ToInt32(inFile.ReadLine());
            for (int cId = 1; cId <= cCnt; cId++)
            {
                string[] spt = inFile.ReadLine().Split();
                int s = Convert.ToInt32(spt[1]);
                int p = Convert.ToInt32(spt[2]);
                int ans = 0;
                for (int i = 3; i < spt.Length; i++)
                {
                    int sum = Convert.ToInt32(spt[i]);
                    int nScore = getNScore(sum);
                    int sScore = getSScore(sum);
                    if (nScore >= p)
                    {
                        ans++;
                    }
                    else if (sScore >= p && s > 0)
                    {
                        ans++;
                        s--;
                    }
                }
                outFile.WriteLine("Case #{0}: {1}", cId, ans);
            }

            inFile.Close();
            outFile.Close();
        }

        static int getNScore(int sum)
        {
            if (sum % 3 == 0) return sum / 3;
            return sum / 3 + 1;
        }

        static int getSScore(int sum)
        {
            if (2 <= sum && sum <= 28)
            {
                if (sum % 3 == 0) return (sum - 3) / 3 + 2;
                else if (sum % 3 == 1) return (sum - 4) / 3 + 2;
                else return (sum - 2) / 3 + 2;
            }
            return -1;
        }
    }

    class ScoreNode
    {
        public int sscore;
        public int nscore;

        public ScoreNode(int sum)
        {
            if (sum % 3 == 0) nscore = sum / 3;
            else nscore = sum / 3 + 1;
            sscore = -1;


        }
    }
}
