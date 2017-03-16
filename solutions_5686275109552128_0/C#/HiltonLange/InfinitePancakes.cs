// -----------------------------------------------------------------------
// <copyright file="InfinitePancakes.cs" company="">
// TODO: Update copyright text.
// </copyright>
// -----------------------------------------------------------------------

namespace GCJ
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;

    /// <summary>
    /// TODO: Update summary.
    /// </summary>
    public class InfinitePancakes : GCJBase
    {
        public override void Solve()
        {
            //int[] pa = new int[] { 120, 80, 50, 50, 50, 50, 50,50,50,50,50,50,50,50,50,50,50,50,50,50 };
            //long ret2 = minTryAll(pa);

            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                string[] s2 = Console.ReadLine().Split(' ');
                int[] pancakes = new int[s2.Length];
                for (int i = 0; i < s2.Length; i++)
                {
                    pancakes[i] = int.Parse(s2[i]);
                }
                long ret = BfsStates(pancakes);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        Dictionary<string, long> minTurns = new Dictionary<string, long>();

        private long BfsStates(int[] pancakesArray)
        {
            List<int> p = new List<int>(pancakesArray);
            p.Sort();
            long ret = solve(p, p[p.Count - 1]);
            return ret;
        }

        private long solve(List<int> p, int maxSteps)
        {
            p.Sort();
            int pmax = p[p.Count - 1];
            if (maxSteps < 3) return pmax;
            if (pmax <= 3)
            {
                return pmax;
            }

            char[] c = new char[p.Count + 1];
            for (int i = 0; i < p.Count; i++)
            {
                c[i] = (char)('0' + p[i]);
            }
            c[p.Count] = (char)('a' + maxSteps);

            string hash = new string(c);
            if (minTurns.ContainsKey(hash)) return minTurns[hash];

            long best = pmax;
            // Eat
            List<int> p2 = new List<int>(p);
            for (int i = 0; i < p2.Count; i++)
            {
                p2[i]--;
            }
            while (p2[0] == 0) p2.RemoveAt(0);
            best = Math.Min(best, solve(p2, maxSteps - 1) + 1);

            // Move X pancakes off largest stack
            for (int x = 1; 2 * x <= p[p.Count - 1]; x++)
            {
                p2 = new List<int>(p);
                p2[p.Count - 1] -= x;
                p2.Add(x);

                best = Math.Min(best, solve(p2, maxSteps - 1) + 1);
            }

            minTurns[hash] = best;
            return best;
        }

        private long minTryAll(int[] pancakesArray)
        {
            Array.Sort(pancakesArray);
            int maxStack = pancakesArray[pancakesArray.Length - 1];
            long best = minTime(pancakesArray);
            for (int i = 1; i <= maxStack; i++)
            {
                for (int j = 0; j < pancakesArray.Length - 1; j++)
                {
                    int[] pa2 = new int[pancakesArray.Length];
                    Array.Copy(pancakesArray, pa2, pa2.Length);
                    pa2[j] += i;
                    pa2[pa2.Length - 1] -= i;
                    long ret = minTime(pa2) + 1;
                    if (ret < best)
                    {
                        throw new Exception("wtf");
                    }
                }
            }
            return best;
        }

        private long minTime(int[] pancakesArray)
        {
            List<int> pancakes = new List<int>(pancakesArray);
            pancakes.Sort();
            int best = pancakes[pancakes.Count - 1];
            int spec = 0;
            do
            {
                int last = pancakes[pancakes.Count - 1];
                if (last < 4)
                {
                    break;
                }

                bool improvement = false;
                if (last >= pancakes.Count) improvement = true;
                for (int i = pancakes.Count - 2; i >= 0; i--)
                {
                    if (pancakes[i] < last - (pancakes.Count - 1 - i))
                    {
                        improvement = true;
                        break;
                    }
                }

                if (!improvement)
                {
                    break;
                }

                int rem = (last + 1) / 2;
                pancakes[pancakes.Count - 1] /= 2;
                pancakes.Add(rem);
                pancakes.Sort();
                spec++;
                best = Math.Min(best, spec + pancakes[pancakes.Count - 1]);
            } while (true);

            return best;
        }
    }
}
