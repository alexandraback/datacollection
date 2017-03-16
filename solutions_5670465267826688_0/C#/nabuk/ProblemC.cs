using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ProblemC
{
    public class ProblemC
    {
        Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        int ri() { return int.Parse(rc()); }
        long rlong() { return long.Parse(rc()); }

        static void Main(string[] args) { new ProblemC().Run(); }

        void Run()
        {
            using (var sr = new StreamReader("C-small-attempt0.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var tCase = ri();

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    sw.WriteLine("Case #{0}: {1}", tiCase, Solve());
                }
            }
        }

        private int[,] M = new int[4, 4]
        {
            {0, 1, 2, 3},
            {1, 0+4, 3, 2+4},
            {2, 3+4, 0+4, 1},
            {3, 2, 1+4, 0+4}
        };

        private int Mult(int a, int b)
        {
            var s = (a & 4) ^ (b & 4);
            a &= 3;
            b &= 3;
            return M[a, b] ^ s;
        }

        private string Solve()
        {
            long L = rlong(), X = rlong();

            var line = rc().Select(c => c - 'i' + 1).ToArray();
            
            var input = Enumerable.Range(1, (int) X).SelectMany(x => line).ToArray();

            int iindex;
            int kindex;
            int product;

            for (iindex = 0, product = 0; iindex < input.Length; iindex++)
            {
                product = Mult(product, input[iindex]);
                if (product == 1)
                    break;
            }
            if (iindex == input.Length)
                return "NO";

            for (kindex = input.Length-1, product = 0; kindex >= 0; kindex--)
            {
                product = Mult(input[kindex], product);
                if (product == 3)
                    break;
            }
            if (kindex == -1)
                return "NO";

            for (product = 0, iindex++;iindex < kindex;iindex++)
            {
                product = Mult(product, input[iindex]);
            }

            return product == 2 ? "YES" : "NO";
        }
    }
}
