using System;
using System.Collections.Generic;
using System.Net.Configuration;
using System.Numerics;

namespace TestProj
{
    public class Solution
    {
        static void Main(string[] args)
        {
            //solve(16, 50);
            solve(32, 500);
        }

        static string outputResult(uint a)
        {
            string ret = toBinString(a);
            for (int bs = 2; bs <= 10; bs++)
            {
                var v = parse(a, bs);
                string anyDiv = "";
                for (BigInteger i = 2; i*i <= v; i++)
                {
                    if (v%i == 0)
                    {
                        anyDiv = i + "";
                        break;
                    }
                    if (i > 1000000)
                        return "";
                }
                if (anyDiv == "")
                    throw new Exception("No Divisors found");
                ret += " " + anyDiv;
            }
            return ret;
        }

        static bool check(uint a, int n)
        {
            if (MillerRabin.IsPrime(a))
                return false;

            for (int bs = 3; bs <= 10; bs++)
            {
                if (MillerRabin.IsPrime(parse(a, bs)))
                    return false;
            }
            return true;
        }

        static BigInteger parse(uint a, int bs)
        {
            BigInteger val = 0;
            for (int i = 31; i >= 0; i--)
            {
                val *= bs;
                if ((a & 1u << i) != 0)
                {
                    val++;
                }
            }
            return val;
        }

        static void solve(int n, int J)
        {
            uint start = (uint)(((long)1 << (n - 1)) + 1);
            uint end = (uint)(((long)1 << n) - 1);
            Console.WriteLine(toBinString(start));
            Console.WriteLine(toBinString(end));
            Console.WriteLine("-------");

            var result = new List<string>();

            while (J > 0)
            {
                if (check(start, n))
                {
                    var r = outputResult(start);
                    if (r != "")
                    { 
                        Console.WriteLine(r);
                        result.Add(r);
                        J--;
                    }
                    else
                    {
                        Console.WriteLine("Bad try!");
                    }
                }

                if (start == end)
                    break;
                start += 2;
            }
            System.IO.File.WriteAllLines(@"out.txt", result);
        }

        static string toBinString(uint a)
        {
            string res = "";
            while (a > 0)
            {
                if (a%2 == 0)
                    res = "0" + res;
                else
                    res = "1" + res;
                
                a /= 2;
            }
            return res;
        }


        //static bool isPrime(int n)
        //{
        //    if (n < 2)
        //        return false;
        //    for(int i = 2; i*i <= n; i++)
        //        if (n % i == 0)
        //            return false;
        //    return true;
        //}
    }


    class MillerRabin
    {

        private static int[] _primes = {2, 3, 5, 7, 11, 13, 17, 19};
        private static Random _random = new Random();

        private static bool _witness(int a, BigInteger n)
        {
            var u = n - 1;
            var t = 1;
            while ((u & 1) == 0)
            {
                t++;
                u >>= 1;
            }
            var x0 = BigInteger.ModPow(a, u, n);
            for (var i = 0; i < t; i++)
            {
                var x = BigInteger.ModPow(x0, 2, n);
                if (x == 1)
                    return x0 != 1 && x0 != n - 1;
                x0 = x;
            }
            return x0 != 1;
        }


        public static bool IsPrime(BigInteger n, int rounds = 50)
        {
            if (n == 2)
                return true;
            if (n < 2)
                return false;
            foreach (var d in _primes)
                if (n != d && n%d == 0)
                    return false;

            int randMax = 100000;
            if (randMax > n)
                randMax = int.Parse(n + "");
             
            while (rounds-- != 0)
                if (_witness(_random.Next(1, randMax - 1), n))
                    return false;
            return true;
        }
    }
}