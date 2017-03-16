using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QualificationRound
{
    public class Dijkstra
    {
        //status: [0]=1, [1]=i, [2]=j, [3]=k, [4]=-1, [5]=-i, [6]=-j, [7]=-k;
        public readonly int[,] Multiply = new int[8, 8];
        //
        public readonly int i = 1;
        public readonly int ij = 3;  //ij = k;
        public readonly int ijk = 4; //-1;

        public Dijkstra()
        {
            //1,i,j,k, -1,-i,-j,-k: 0-7.
            int[,] table = new int[4, 4] { { 0, 1, 2, 3 }, { 1, 4, 3, 6 }, { 2, 7, 4, 1 }, { 3, 2, 5, 4 } };
            //
            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    int sign = ((i < 4) ? 1 : -1) * ((j < 4) ? 1 : -1);
                    this.Multiply[i, j] = (table[(i & 0x3), (j & 0x3)] + ((sign < 0) ? 4 : 0)) & 0x7;
                }
            }
            return;
        }

        public string Run(string inputText)
        {
            string[] lines = inputText.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
            int N = lines.Length;

            String answer = "";
            for (int i = 1; i < N; i += 2)
            {
                string line1 = lines[i];
                string line2 = lines[i + 1];

                long X = long.Parse(line1.Split(' ')[1]);
                string S = line2;

                bool possible = this.Solve(S, X);

                answer += string.Format("Case #{0}: {1}", (i / 2) + 1, (possible ? "YES" : "NO"));
                answer += Environment.NewLine;
            }

            return answer;
        }

        public bool Solve(string S, long X)
        {
            int L = S.Length;
            int[] status0 = new int[L];
            List<int[]> statusSet = new List<int[]>(65);

            // status: 1=i, 2=j, 3=k.
            status0[0] = (S[0] - 'i' + 1);

            for (int n = 1; n < L; ++n)
            {
                int x = status0[n - 1];
                int y = (S[n] - 'i' + 1);
                status0[n] = this.Multiply[x, y];
            }

            //statusSet[0] = status0.
            statusSet.Add(status0);

            //find loop.
            int loopStartIndex = -1;
            //
            List<int> endings = new List<int>(65);
            endings.Add(status0[L - 1]);
            //
            for (long i = 1; i < X; ++i)
            {
                int lastEnd = statusSet[(int)i - 1][L - 1];
                int nextEnd = this.Multiply[lastEnd, status0[L - 1]];
                loopStartIndex = endings.IndexOf(nextEnd);
                if (loopStartIndex >= 0) { break; }
                endings.Add(nextEnd);
                //
                int[] statusN = new int[L];
                for (int n = 0; n < L; ++n)
                {
                    statusN[n] = this.Multiply[lastEnd, status0[n]];
                }
                statusSet.Add(statusN);
            }
            //
            int initCount = (loopStartIndex >= 0) ? loopStartIndex : endings.Count;
            int loopCount = statusSet.Count - initCount;
            long loopNum = (loopCount > 0) ? ((X - (long)initCount) / (long)loopCount) : 0;
            int lastCount = (int)(X - initCount - loopNum * loopCount);

            //find i=1, ij=3, ijk=4:end.

            //check if full multiply is ijk(4) or not.
            int lastIndex = initCount + ((lastCount > 0) ? lastCount : loopCount) - 1;
            int lastValue = statusSet[lastIndex][L - 1];
            if (lastValue != 4)
            {
                return false;
            }

            //find first 1, second 3
            bool findI = false;
            bool findIJ = false;
            for (int i = 0; i < initCount; ++i)
            {
                this.checkFunc(statusSet[i], ref findI, ref findIJ);
            }
            for (long j = 0; j < Math.Min(loopNum, 2); ++j)
            {
                for (int i = initCount; i < (initCount + loopCount); ++i)
                {
                    this.checkFunc(statusSet[i], ref findI, ref findIJ);
                }
            }
            for (int i = initCount; i < (initCount + lastCount); ++i)
            {
                this.checkFunc(statusSet[i], ref findI, ref findIJ);
            }

            return (findI && findIJ);
        }

        private void checkFunc(int[] status, ref bool findI, ref bool findIJ)
        {
            foreach (int x in status)
            {
                if (findI == false)
                {
                    findI = (x == 1);
                }
                else if (findIJ == false)
                {
                    findIJ = (x == 3);
                }
            }
            return;
        }

    }
}
