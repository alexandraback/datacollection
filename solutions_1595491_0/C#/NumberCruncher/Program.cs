using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dancing
{
    class B
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("c:\\codejam\\2012\\qual\\B-small-attempt0.in");
            StreamWriter sw = new StreamWriter("c:\\codejam\\2012\\qual\\B-small.out");

            Stopwatch watch = new Stopwatch();
            watch.Start();

            int T = Int32.Parse(sr.ReadLine());
            foreach (int caseN in Enumerable.Range(1, T))
            {
                int[] tmp = sr.ReadLine().Split(' ').Select(int.Parse).ToArray();
                int N = tmp[0];
                int S = tmp[1];
                int p = tmp[2];

                int[] scores = tmp.Skip(3).ToArray();

                int minNS = Math.Max(3 * p - 2,0);
                int minS = Math.Max(3*p - 4,2);

                int n = scores.Count(sc => sc >= minNS);
                int nS = scores.Count(sc => sc >= minS && sc < minNS);

                int ans = Math.Min(N - n, Math.Min(nS,S)) + n;

                sw.WriteLine(String.Format("Case #{0}: {1}", caseN, ans));

                Console.WriteLine(String.Format("Case #{0}: {1}ms", caseN, watch.ElapsedMilliseconds));

                sw.Flush();
            }

            sr.Close();
            sw.Close();
        }
    }
}
