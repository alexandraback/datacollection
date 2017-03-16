using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace C_CoinJam
{


    public static class PrimeNumber
    {


        static PrimeNumber()
        {
            if (File.Exists("cache.txt"))
            {
                _cache = new SortedSet<BigInteger>(File.ReadAllLines("cache.txt").Select(BigInteger.Parse));
                _verificado = BigInteger.Parse(File.ReadAllText("cache2.txt"));
            }
            else
            {
                _cache = new SortedSet<BigInteger> {2, 3, 5, 7, 11};
                _verificado = 11;
            }
        }

        private static BigInteger _verificado = 11;
        private static SortedSet<BigInteger> _cache;

        public static BigInteger IntegerSquareRoot(BigInteger value)
        {
            if (value > 0)
            {
                int bitLength = value.ToByteArray().Length * 8;
                BigInteger root = BigInteger.One << (bitLength / 2);
                while (!IsSquareRoot(value, root))
                {
                    root += value / root;
                    root /= 2;
                }
                return root;
            }
            return 0;
        }

        private static bool IsSquareRoot(BigInteger n, BigInteger root)
        {
            BigInteger lowerBound = root * root;
            BigInteger upperBound = (root + 1) * (root + 1);
            return (n >= lowerBound && n < upperBound);
        }


        public static bool EhPrimo(BigInteger value)
        {
            if (value == 1)
                return false;
            if (_cache.Contains(value))
                return true;
            if (_verificado >= value)
                return false;

            var sqrt = IntegerSquareRoot(value);
            if (_verificado < sqrt)
                ConstruirCache(sqrt);

            foreach (var atual in _cache)
            {
                if (atual > sqrt)
                    break;
                if (value % atual == 0)
                    return false;
            }
            _cache.Add(value);
            return true;
        }

        private static void ConstruirCache(BigInteger sqrt)
        {
            for (BigInteger x = _verificado + 1; x <= sqrt; x++)
            {
                if (EhPrimo(x))
                    _cache.Add(x);
            }
            _verificado = sqrt;
        }

        public static BigInteger? ObterDivisor(BigInteger pNumero, long pLimite)
        {
            if (_cache.Contains(pNumero))
                return null;
            foreach (var divisor in _cache)
            {
                if (divisor > pLimite)
                    return null;
                if(pNumero % divisor == 0)
                    return divisor;
            }
            return null;
        }


        public static void Persistir()
        {
            File.WriteAllText("cache2.txt", _verificado.ToString());
            File.WriteAllLines("cache.txt", _cache.Select(pX => pX.ToString()).ToArray());
        }

    }
}
