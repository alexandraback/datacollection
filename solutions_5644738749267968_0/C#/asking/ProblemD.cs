using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualRound
{
    class ProblemD
    {
        public static void solve()
        {
            //string inFile = @"..\..\d-sample.in";
            string inFile = @"..\..\D-small-attempt0.in";
            string outFile = inFile.Substring(0, inFile.Length - 2) + "out";

            using (var sr = new StreamReader(inFile))
            using (var sw = new StreamWriter(outFile, false))
            {
                int T = int.Parse(sr.ReadLine());
                for (int casei = 1; casei <= T; casei++)
                {
                    int N = int.Parse(sr.ReadLine());
                    var NaomiBlks = sr.ReadLine()
                        .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                        .Select(x => double.Parse(x))
                        .OrderBy(x => x)
                        .ToArray();
                    var KenBlks = sr.ReadLine()
                        .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                        .Select(x => double.Parse(x))
                        .OrderBy(x => x)
                        .ToArray();

                    Debug.Assert(NaomiBlks.Length == N);
                    Debug.Assert(KenBlks.Length == N);

                    int NaomiWarScore = N - awin(KenBlks, NaomiBlks);
                    int NaomiDeceitWarScore = awin(NaomiBlks, KenBlks);

                    sw.WriteLine("Case #{0}: {1} {2}", casei, NaomiDeceitWarScore, NaomiWarScore);
                }
            }
        }

        public static int awin(double[] a, double[] b)
        {
            int win = 0;
            int i = 0, j = 0;
            while(i < a.Length && j < a.Length)
            {
                if(a[i] > b[j])
                {
                    win++;
                    j++;
                }
                i++;
            }
            return win;
        }
    }
}
