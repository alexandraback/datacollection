using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace GoogleCodeJam2013_Round1A_B_Energy
{
    class Program
    {
        static void Main(string[] args)
        {
            var outFn = "output.out";
            ProvideEmptyFile(outFn);
            Action<string> wl = line =>
            {
                //Console.WriteLine(line);
                File.AppendAllLines(outFn, new[] { line });
            };

            var inLines = File.ReadAllLines("input.txt");
            var testCaseCount = int.Parse(inLines[0]);
            for (int iCase = 1; iCase <= testCaseCount; iCase++)
            {
                var E = long.Parse(inLines[(iCase - 1) * 2 + 1].Split(' ')[0]);
                var R = long.Parse(inLines[(iCase - 1) * 2 + 1].Split(' ')[1]);
                var N = long.Parse(inLines[(iCase - 1) * 2 + 1].Split(' ')[2]);
                var values = inLines[(iCase - 1) * 2 + 2].Split(' ').Select(long.Parse).ToArray();
                
                var counts = new long[N];
                var energies = new long[N + 1];
                //for (int i = 0; i < N; i++)
                //    energies[i] = E;
                energies[0] = E;

                for (int i = 0; i < N; i++)
                {
                    var maxRefill = E - energies[i];

                    if (maxRefill > 0)
                    {
                        for (int j = i - 1; j >= 0; j--)
                        {
                            if (values[j] < values[i])
                            {
                                var refill = Math.Min(maxRefill, counts[j]);
                                counts[j] -= refill;

                                for (int x = j + 1; x <= i; x++)
                                    energies[x] = Math.Min(energies[x] + refill, E);
                            }

                            maxRefill = Math.Min(maxRefill, E - energies[j]);
                            if (maxRefill == 0)
                                break;
                        }                        
                    }

                    counts[i] = energies[i];
                    energies[i + 1] = R;
                }

                var result = Enumerable.Range(0, (int)N).Select(x => values[x] * counts[x]).Sum();

                wl(String.Format("Case #{0}: {1}", iCase, result));
            }
        }

        static void ProvideEmptyFile(string fn)
        {
            if (!File.Exists(fn)) return;

            for (int i = 1; i < 100; i++)
            {
                var bakFn = fn + "_bak_" + i;
                if (File.Exists(bakFn)) continue;
                File.Move(fn, bakFn);
                break;
            }
        }

    }

    public static class Ext
    {
        public static BigInteger Sqrt(this BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength / 2);

                while (!isSqrt(n, root))
                {
                    root += n / root;
                    root /= 2;
                }

                return root;
            }

            throw new ArithmeticException("NaN");
        }

        private static Boolean isSqrt(BigInteger n, BigInteger root)
        {
            BigInteger lowerBound = root * root;
            BigInteger upperBound = (root + 1) * (root + 1);

            return (n >= lowerBound && n < upperBound);
        }
    }

}
