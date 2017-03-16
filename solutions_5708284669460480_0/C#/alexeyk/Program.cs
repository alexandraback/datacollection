using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("B-small-attempt0.in"))
            {
                using (StreamWriter sw = new StreamWriter("out1.txt"))
                {
                    SolveIt(sr, sw);
                }
            }
        }

        public static bool HasEnoughLetters(string kb, string target)
        {
            HashSet<char> kbLetters = new HashSet<char>();
            foreach (var c in kb)
            {
                kbLetters.Add(c);
            }
            foreach (char c in target)
            {
                if (!kbLetters.Contains(c))
                {
                    return false;
                }
            }

            return true;
        }

        // L == 3, S == 4
        // target == AAA
        public static long GetMaxBananas(int S, int L, string target)
        {
            int t = 0;
            for(int tt = 1; tt < L; tt++){
                if (target.Substring(0, tt) == target.Substring(L - tt))
                {
                    t = tt;
                }
            }

            return 1 + (S - L) / (L - t);
        }

        private static void SolveIt(StreamReader sr, StreamWriter sw)
        {
            int T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var splitted = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                int K = splitted[0];
                int L = splitted[1];
                int S = splitted[2];

                string kb = sr.ReadLine();
                string target = sr.ReadLine();

                if (!HasEnoughLetters(kb, target))
                {
                    sw.WriteLine("Case #{0}: 0.0", (t + 1));
                    continue;
                }

                long brought = GetMaxBananas(S, L, target);

                Console.WriteLine("Brought {0} for {1}", brought, t);

                double exp = ComputeExpected(kb, target, S, L, K);

                sw.WriteLine("Case #{0}: {1:F06}", (t + 1), (double)(brought - exp));
            }
        }

        private static double ComputeExpected(string kb, string target, int S, int L, int K)
        {
            char[] curTarget = new char[S];
            ulong totalCount = 0;
            ulong weight = 0;
            for (ulong i = 0; i < Math.Pow(K, S); i++)
            {
                totalCount++;
                ulong iCopy = i;

                for (int j = 0; j < S; j++)
                {
                    curTarget[j] = kb[(int)(iCopy % (ulong)K)];
                    iCopy = iCopy / (ulong)K;
                }

                weight += CountWord(curTarget, target);
            }

            Console.WriteLine("{0} - {1}", weight, totalCount);

            return (double)weight / (double)totalCount;
        }

        private static ulong CountWord(char[] curTarget, string target)
        {
            ulong res = 0;

            /// curTarget = 3, target = 2
            for (int i = 0; i <= curTarget.Length - target.Length; i++)
            {
                bool isEqual = true;
                for (int j = 0; j < target.Length; j++)
                {
                    if (curTarget[i + j] != target[j])
                    {
                        isEqual = false;
                        break;
                    }
                }

                if (isEqual)
                {
                    res++;
                }
            }

            return res;
        }
    }
}
