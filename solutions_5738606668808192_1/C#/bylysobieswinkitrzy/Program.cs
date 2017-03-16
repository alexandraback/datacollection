using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CoinJam
{
    class Program
    {
        //static int N = 16, J = 50;
        //static int N = 6, J = 3;
         static int N = 32, J = 500;

        public static BigInteger[] SetBases(string jamcoin)
        {
            BigInteger[] jamcoinlong = new BigInteger[9];
            for (int i = 0; i < jamcoinlong.Length - 1; i++)
            {
                jamcoinlong[i] = (BigInteger)jamcoin.ToCharArray().Select(x => x == '1' ? 1 : 0).Reverse().Select((x, n) => Math.Pow(i + 2, n) * x).Sum();
            }
            jamcoinlong[8] = BigInteger.Parse(jamcoin);
            return jamcoinlong;
        }

        static void Main(string[] args)
        {

          //  SortedSet<BigInteger> primes = new SortedSet<BigInteger>(File.ReadAllLines("100M_primes.txt").Select(x => BigInteger.Parse(x)));


            var maxValue = Convert.ToInt32(new String(Enumerable.Repeat('1', N - 2).ToArray()), 2);

            List<string> cool = new List<string>();

            for (long ij = 0; ij <= maxValue; ij++)
            {
                var ndx = 0;
                var jc = String.Concat('1', Convert.ToString(ij, 2).PadLeft(N - 2, '0'), '1');
                var xxx = SetBases(jc);

                var veryCool = true;
                foreach (var pb in xxx)
                {
                 //   if (primes.Contains(pb)) { veryCool = false; break; }
                }
                if (veryCool)
                {
                    string outt = String.Empty;
                    foreach (BigInteger bas in xxx)
                    {
                        for (long i = 2; i < 20; i++)
                        {
                            if ((bas % i == 0))// && !primes.Contains(i))
                            {
                                ndx += 1;
                                outt += (" " + i.ToString());
                                break;
                            }
                        }

                    }
                    if (ndx == 9)
                    {
                        string prn = String.Format("{0}{1}{2}", jc, outt, Environment.NewLine);
                        File.AppendAllText("output_32.out", prn);
                        Console.WriteLine(prn);
                    }
                }
            }
            Console.ReadKey();
        }

        private static List<string> GenerateAllJamCoins(int n)
        {
            int smalln = n - 2;
            var maxValue = Convert.ToInt32(new String(Enumerable.Repeat('1', smalln).ToArray()), 2);
            var range = Enumerable.Range(0, maxValue).Select(x => String.Concat('1', Convert.ToString(x, 2).PadLeft(smalln, '0'), '1')).ToList();
            return range;
        }
    }
}
