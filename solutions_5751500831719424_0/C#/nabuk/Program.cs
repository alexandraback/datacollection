using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;

namespace ConsoleApplication1
{
    public static class _
    {
        public static T[] Times<T>(this int count, Func<T> f) { return Enumerable.Repeat(0, count).Select(x => f()).ToArray(); }
    }

    public class Program
    {
        Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        int ri() { return int.Parse(rc()); }
        double rd() { return double.Parse(rc(), CultureInfo.InvariantCulture); }
        string rl() { return string.Join(" ", chunks.Dequeue()); }
        void swap<T>(ref T a, ref T b) { var x = a; a = b; b = x; }

        public static void Main() { new Program().Solve(); }
        void Solve()
        {
            using (var sr = new StreamReader("A-small-attempt0.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var tCase = ri();

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    int N = ri();

                    var s = N.Times(rl);

                    string pattern;
                    int[] count;
                    bool notPossible = false;

                    List<int[]> allSizes = new List<int[]>();

                    fragm(s[0], out pattern, out count);
                    allSizes.Add(count);

                    for (int i = 1; i < N; ++i)
                    {
                        string cPattern;
                        fragm(s[i], out cPattern, out count);

                        if (cPattern != pattern)
                        {
                            notPossible = true;
                            break;
                        }

                        allSizes.Add(count);
                    }

                    if (notPossible)
                    {
                        sw.WriteLine("Case #{0}: Fegla Won", tiCase);
                        continue;
                    }

                    int sum = 0;
                    for (int i = 0; i < pattern.Length; ++i)
                    {
                        int subSum = int.MaxValue;
                        int max = allSizes.Max(x => x[i]);

                        for (int k = 1; k <= max; ++k) 
                        {
                            int check = 0;
                            for (int j = 0; j < N; ++j)
                            {
                                check += Math.Abs(allSizes[j][i] - k);
                            }
                            subSum = Math.Min(subSum, check);
                        }

                        sum += subSum;
                    }


                    sw.WriteLine("Case #{0}: {1}", tiCase, sum);
                }
            }
        }

        void fragm(string s, out string pattern, out int[] count)
        {
            List<int> countList = new List<int>();
            countList.Add(1);
            List<char> solutionList = new List<char>();
            solutionList.Add(s[0]);

            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] != s[i - 1])
                {
                    solutionList.Add(s[i]);
                    countList.Add(1);
                }
                else
                {
                    countList[countList.Count - 1]++;
                }
            }

            pattern = new string(solutionList.ToArray());
            count = countList.ToArray();
        }
    }
}