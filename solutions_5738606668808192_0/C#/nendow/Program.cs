using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace GCJ2016Q
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            var ar = Console.ReadLine().Split(' ');
            var N = int.Parse(ar[0]);
            var J = int.Parse(ar[1]);
            var start = (1L << N - 1) + 1;
            var end = 1L << N;
            Console.WriteLine("Case #1:");
            for (var i = start; J > 0 && i < end; i += 2)
            {
                var flag = true;
                for (int j = 2; j <= 10; j++)
                {
                    var b = BigInteger.Zero;
                    var t = i;
                    while (t > 0)
                    {
                        b *= j;
                        b += (t & 1);
                        t >>= 1;
                    }
                    if (IsPrime(b))
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    var s = "";
                    for (int j = 2; flag && j <= 10; j++)
                    {
                        var b = BigInteger.Zero;
                        var t = i;
                        var n = -1;
                        while (t > 0)
                        {
                            b *= j;
                            b += (t & 1);
                            t >>= 1;
                        }
                        for (int k = 0; k < primes.Length; k++)
                        {
                            if (b % primes[k] == 0)
                            {
                                n = primes[k];
                                break;
                            }
                        }
                        if (n == -1)
                        {
                            flag = false;
                            break;
                        }
                        s += " " + n;
                    }
                    if (flag)
                    {
                        s = String.Concat(Convert.ToString(i, 2).Reverse()) + s;
                        Console.WriteLine(s);
                        J--;
                    }
                }
            }
        }

        static int[] primes = new[]
        {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
            109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
            233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359,
            367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491,
            499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641,
            643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787,
            797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
            947, 953, 967, 971, 977, 983, 991, 997
        };

        static bool IsPrime(BigInteger n)
        {
            if (n < 2) return false;
            if (n == 2) return true;
            if ((n & 1) == 0) return false;
            var d = n - 1;
            var s = 0;
            while ((d & 1) == 0)
            {
                s++;
                d >>= 1;
            }
            var ls = new[] { 2, 3, 5, 7, 11, 13 };
            foreach (var a in ls.Where(x => x < n))
            {
                var m = BigInteger.ModPow(a, d, n);
                if (m == 1)
                    continue;
                var flag = true;
                for (int i = 0; flag && i < s; i++)
                {
                    if (m == n - 1)
                        flag = false;
                    else
                        m = m * m % n;
                }
                if (true)
                    return false;
            }
            return true;
        }
    }
}

