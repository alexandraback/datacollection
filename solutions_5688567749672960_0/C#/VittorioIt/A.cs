using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2015Round1B
{
    class A
    {
        static long greedy(long N)
        {
            if (N == 1) return 1;
            if (N == 10) return 10;
            long toret = greedy(N / 10);
            toret += (long)Math.Pow(10, ndigit(N) / 2) - 1;
            long curr = N / 10 + (long)Math.Pow(10, ndigit(N) / 2) - 1;
            toret++;
            toret += N - reverse(curr);
            return toret;
        }
        static long solve(long N)
        {
            long toret = 0;
            int d = ndigit(N);
            toret += greedy((long)Math.Pow(10, (d-1)));
            if (N == (long)Math.Pow(10, (d - 1))) return toret;
            long tail = N % (long)Math.Pow(10, (d + 1) / 2);
            if (tail == 0)
            {
                toret++;
                N--;
                tail = N % (long)Math.Pow(10, (d + 1) / 2);
            }
            for (int i = 0; i < d / 2; i++)
            {
                long pow = (long)Math.Pow(10, d - i - 1);
                long pow2 = (long)Math.Pow(10, i);
                toret += ((N / pow) % 10) * pow2;
            }
            toret += tail - 1;
            if (reverse(N - tail) != 1 && reverse(N - tail) != 0) toret++;
            return toret;
        }
        static int ndigit(long num)
        {
            int toret = 0;
            while (num != 0)
            {
                num /= 10;
                toret++;
            }
            return toret;
        }
        static long reverse(long num)
        {
            long toret = 0;
            while (num != 0)
            {
                toret *= 10;
                toret += num % 10;
                num /= 10;
            }
            return toret;
        }
        static void Main(string[] args)
        {
            TextReader text = File.OpenText("../../input.txt");
            TextWriter outtext = File.CreateText("../../output.txt");
            int T = int.Parse(text.ReadLine());
            for (int n_case = 1; n_case <= T; n_case++)
            {
                long N = long.Parse(text.ReadLine());
                long res = solve(N);
                outtext.WriteLine("Case #" + n_case + ": "+res);
            }
            outtext.Flush();
        }
    }
}
