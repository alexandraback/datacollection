using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace codejam_c_cs
{
    class Program
    {
        static BigInteger ConvertToBase(BigInteger value, BigInteger b)
        {
            BigInteger rv = new BigInteger(0);
            int i = 0;
            do
            {
                BigInteger rem;
                BigInteger.DivRem(value, 10, out rem);

                rv += rem * BigInteger.Pow(b, i);
                value /= 10;
                i++;
            } while (value > 0);

            return rv;
        }

        static BigInteger Add(int n)
        {
            BigInteger rv = new BigInteger(0);
            BigInteger i = 1;
            while (n > 0)
            {
                rv += i * (n & 1);
                i *= 10;
                n >>= 1;
            }

            return rv * 10;
        }

        static void Main(string[] args)
        {
            int[] prime={ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };

            int num_of_testcases = int.Parse(Console.ReadLine());
            for (int t = 1; t <= num_of_testcases; ++t)
            {
                int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

                int len = arr[0];
                int num_of_jamcoins = arr[1];

                Console.WriteLine("Case #" + t + ":");

                int cnt = 1;

                BigInteger cur = 1 + BigInteger.Pow(10, len - 1);
                BigInteger or = 1 + BigInteger.Pow(10, len - 1);
                while (num_of_jamcoins > 0)
                {
                    int[] dividers = new int[9];
                    bool notprime = true;
                    for (int i = 2; i <= 10; ++i)
                    {
                        var vv = ConvertToBase(cur, i);
                        bool isprime = true;
                        for (int j = 0; j < prime.Length; ++j)
                        {
                            if ((vv % prime[j]) == 0)
                            {
                                dividers[i - 2] = prime[j];
                                isprime = false;
                                break;
                            }
                        }
                        if (isprime)
                        {
                            notprime = false;
                            break;
                        }
                    }

                    if (notprime)
                    {
                        Console.Write(cur + " ");
                        foreach (var v in dividers)
                        {
                            Console.Write(v + " ");
                        }
                        Console.WriteLine();
                        --num_of_jamcoins;
                    }

                    cur = or + Add(cnt);
                    cnt++;
                }
            }
        }
    }
}
