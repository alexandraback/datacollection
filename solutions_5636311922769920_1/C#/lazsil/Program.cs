using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace codejam_d_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            int num_of_testcases = int.Parse(Console.ReadLine());
            for (int t = 1; t <= num_of_testcases; ++t)
            {
                int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                int k = arr[0], c=arr[1], s=arr[2];
                Console.Write("Case #" + t + ": ");

                if (s * c < k)
                {
                    Console.Write("IMPOSSIBLE");
                }
                else if (k == s)
                {
                    BigInteger mul = BigInteger.Pow(k, (int)(c - 1));
                    for (BigInteger i = 0; i < k; i++)
                    {
                        Console.Write((i * mul + 1) + " ");
                    }
                }
                else if (k <= c)
                {
                    long c1 = Math.Min(c, k);
                    BigInteger pos = 0;
                    for (int i = 1; i < k; i++)
                    {
                        pos += BigInteger.Pow(k, (int)(c1 - i)) * i;
                    }
                    Console.Write(pos);
                }
                else
                {
                    int num = (int)Math.Ceiling((double)k / c);

                    int[,] coeff = new int[num, c];
                    int index = 0;

                    for (int i = 0; i < num; i++)
                    {
                        for (int j = 0; j < c; j++)
                        {
                            coeff[i, j] = index;
                            if (index < k - 1)
                                index++;
                        }
                    }

                    for (int i = 0; i < num; i++)
                    {
                        BigInteger tot = 0;
                        for (int j = c - 1; j >= 0; j--)
                        {
                            tot += BigInteger.Pow(k, j) * coeff[i, j];
                            index++;
                        }
                        Console.Write(tot + " ");
                    }
                }

                Console.WriteLine();
            }
        }
    }
}
