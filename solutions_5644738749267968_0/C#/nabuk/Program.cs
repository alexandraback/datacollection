using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ConsoleApplication1
{
    public class Program
    {
        private static Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        private static void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        private static string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        private static int ri() { return int.Parse(rc()); }
        private static double rd() { return double.Parse(rc(), CultureInfo.InvariantCulture); }
        private static string rl() { return string.Join(" ", chunks.Dequeue()); }
        private static void swap<T>(ref T a, ref T b) { var x = a; a = b; b = x; }

        public static void Main()
        {
            using (var sr = new StreamReader("D-small-attempt0.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var t = ri();

                for (var ti = 1; ti <= t; ++ti)
                {
                    int N = ri();

                    var naomi = Enumerable.Range(0, N).Select(i => rd()).OrderBy(x => x).ToList();
                    var ken = Enumerable.Range(0, N).Select(i => rd()).OrderBy(x => x).ToList();


                    sw.WriteLine("Case #{0}: {1} {2}", ti, DecWar(naomi, ken), War(naomi, ken));
                }
            }
        }

        public static int DecWar(List<double> naomi, List<double> ken)
        {
            naomi = naomi.ToList();
            ken = ken.ToList();

            int score = 0;

            while (ken.Count > 0)
            {
                var greater = ~naomi.BinarySearch(ken[0]);
                if (greater == naomi.Count)
                    return score;

                ken.RemoveAt(0);
                naomi.RemoveAt(greater);
                ++score;
            }

            return score;
        }

        public static int War(List<double> naomi, List<double> ken)
        {
            naomi = naomi.ToList();
            ken = ken.ToList();

            int score = 0;

            for (int i = naomi.Count - 1; i >= 0; i--)
            {
                var naomiChosen = naomi[i];

                var kenChosenIndex = ~ken.BinarySearch(naomiChosen);

                if (kenChosenIndex == ken.Count)
                {
                    ken.RemoveAt(0);
                    ++score;
                }
                else
                {
                    ken.RemoveAt(kenChosenIndex);
                }
            }

            return score;
        }

        
    }
}