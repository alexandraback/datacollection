using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace CodeJam
{
    class Program
    {
        static string[] data;
        static int index = 0;
        static string Next()
        {
            return data[index++];
        }

        static int NextInt()
        {
            return int.Parse(Next());
        }

        static int E, R, N;
        static int[] v;
        static BigInteger[,] cache;

        static void Main(string[] args)
        {
            string fn = args.Length > 0 ? args[0] : "C:\\temp\\unittest.in";
            data = File.ReadAllText(fn).Replace('\r', ' ').Replace('\n', ' ').Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            StringBuilder output = new StringBuilder(5000);

            int caseCount = NextInt();
            for (int cas = 0; cas < caseCount; cas++)
            {
                //set up test case
                E = NextInt();
                R = NextInt();
                N = NextInt();
                cache = new BigInteger[N + 1, E + 1];
                v = new int[N];
                for (int i = 0; i < N; i++)
                    v[i] = NextInt();

                //output
                Console.WriteLine("Done case #" + (cas + 1));
                output.AppendLine(string.Format("Case #{0}: {1}", cas + 1, Solve()));
            }

            File.WriteAllText(fn + ".out", output.ToString());
        }

        static BigInteger Solve()
        {
            return Search(N - 1, 0);
        }

        static BigInteger Search(int K, int leftE)
        {
            if (K == 0)
            {
                return (E - leftE) * v[0];
            }

            if (cache[K, leftE] != 0) return cache[K, leftE];

            BigInteger max = -1;
            for (int i = 0; i <= E; i++)
            {
                BigInteger prev = Search(K - 1, i);
                if (prev < 0) continue;
                BigInteger e2 = i + R;
                if (e2 > E) e2 = E;
                if (e2 < leftE) continue;

                BigInteger now = prev + (e2 - leftE) * v[K];
                if (now > max) max = now;
            }

            cache[K, leftE] = max;
            return max;
        }
    }
}
