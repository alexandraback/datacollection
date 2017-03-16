using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading;

using static System.Linq.Enumerable;
using static System.Console;
using static LanguageExt.Prelude;
using static GCJ2016.Loop;

namespace GCJ2016
{
    class ProgramC
    {
        private static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
            var io = new Io(args);

            var T = io.Read<int>();
            T.Times((C) =>
            {
                WriteLine($"Case #{C+1}:");
                var L = io.ReadArray<int>();
                int N = L[0], J = L[1];

                int ij = 0, found = 0;
                while (found < J)
                {
                    var jc = string.Concat('1', Convert.ToString(ij++, 2).PadLeft(N - 2, '0'), '1');
                    var bases = SetBases(jc);

                    var outt = new List<int>();
                    foreach (var bi in bases)
                    {
                        int d = 1;
                        while (++d < 100) if (bi%d == 0)
                        {
                            outt.Add(d);
                            break;
                        }
                    }
                    if (outt.Length() == 9)
                    {
                        WriteLine($"{jc} "+string.Join(" ", outt));
                        ++found;
                    }
                }
            });
        }

        public static BigInteger[] SetBases(string jamcoin)
        {
            var coins = new BigInteger[9];
            for (int i = 0; i < coins.Length - 1; i++)
            {
                coins[i] = (BigInteger)jamcoin.ToCharArray()
                    .Select(x => x == '1' ? 1 : 0)
                    .Reverse()
                    .Select((x, n) => Math.Pow(i + 2, n) * x)
                    .Sum();
            }
            coins[8] = BigInteger.Parse(jamcoin);
            return coins;
        }
    }
}
