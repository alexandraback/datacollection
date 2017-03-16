using System;
using System.Numerics;
using System.Collections.Generic;
using System.Text;
using System.Globalization;

namespace CoinJam
{
    class Program
    {
        static Random rnd;
        static void Main(string[] args)
        {
            rnd = new Random();
            int numberOfSamples = int.Parse(Console.ReadLine());
            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample
                string[] values = Console.ReadLine().Split(' ');
                int coinLength = int.Parse(values[0]);
                int quantity = int.Parse(values[1]);

                SolveTheProblem(sp + 1, coinLength, quantity);
            }
        }

        //static string GenerateNewCoin(int coinLength)
        //{
        //    StringBuilder sb = new StringBuilder();

        //    sb.Append("1");
        //    for (int i = 0; i < coinLength - 2; i++)
        //    {
        //        sb.Append(rnd.Next(2));
        //    }
        //    sb.Append("1");
        //    return sb.ToString();
        //}

        static long ParseBigInt(string coin, int numBase)
        {
            long number = 0;
            for (int i = 0; i < coin.Length; i++)
            {
                number = number * numBase + (coin[i] - '0');
            }
            return number;
        }

        static bool CheckValid(string coin, out string outValues)
        {
            StringBuilder sb = new StringBuilder();
            long[] proofs = new long[9];
            
            for (int numBase =  2; numBase <= 10; numBase++)
            {
                long number = ParseBigInt(coin, numBase);

                // Check elementary
                proofs[numBase - 2] = 0;
                long lim = (long)Math.Sqrt(number);
                for (long i = 2; i <= lim; i++)
                {
                    if (number % i == 0)
                    {
                        proofs[numBase - 2] = i;
                        sb.Append(" ");
                        sb.Append(i);
                        break;
                    }
                }

                if (proofs[numBase - 2] == 0) // is prime!!!
                {
                    outValues = "";
                    return false;
                }
            }

            outValues = sb.ToString();
            return true;
        }

        static void SolveTheProblem(int sp, int coinLength, int quantity)
        {
            List<string> coins = new List<string>();
            string[] outValues = new string[quantity];

            // TODO: solve it
            long seed = (1 << coinLength - 1) + 1;
            for (int i = 0; i < quantity; i++)
            {
                while (true)
                {
                    string newCoin = Convert.ToString(seed, 2); 
                    if (!coins.Contains(newCoin) &&
                        CheckValid(newCoin, out outValues[i]))
                    {
                        coins.Add(newCoin);
                        break;
                    }
                    seed += 2;
                }
            }

            // Print results
            Console.WriteLine("Case #{0}:", sp);

            for (int i = 0; i < quantity; i++)
            {
                Console.WriteLine("{0}{1}", coins[i], outValues[i]);
            }
        }
    }
}
