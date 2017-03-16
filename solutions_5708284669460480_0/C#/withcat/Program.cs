using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    private static long Combination(long n, long k)
    {
        if (k > n - k) k = n - k;
        long result = 1;
        for (long i = 1; i <= k; ++i)
        {
            result *= n - k + i;
            result /= i;
        }
        return result;
    }

    static void Main(string[] args)
    {
        var T = int.Parse(Console.ReadLine());
        for (var t = 0; t < T; t++)
        {
            var r1 = Console.ReadLine().Trim().Split().Select(int.Parse).ToArray();
            var K = r1[0];
            var L = r1[1];
            var S = r1[2];

            var KB = Console.ReadLine();
            var Word = Console.ReadLine();

            var kProb = KB.GroupBy(v => v).ToDictionary(v => v.Key, v => 1.0d * v.Count() / KB.Length);

            // AABA
            // AA
            int norepeatL = Word.Length;
            for (int i = 1; i < Word.Length ; i++)
            {
                bool pass = true;
                for (int j = 0; j+i < Word.Length ; j++)
                {
                    if (Word[j] != Word[j + i])
                    {
                        pass = false;
                        break;
                    }
                }
                if (pass)
                {
                    norepeatL = i;
                    break;
                }
            }

            double prob = 1.0;
            foreach (char c in Word)
            {
                double singleProb = 0;
                if (kProb.ContainsKey(c)) singleProb = kProb[c];
                prob *= singleProb;
            }

            var max = S - norepeatL + 1;
            if (prob == 0) max = 0;

            Console.WriteLine("Case #{0}: {1:f}", t + 1, max - prob * max);
        }
    }
}
