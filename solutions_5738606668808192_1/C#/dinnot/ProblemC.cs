using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace CodeJam
{
    class ProblemC
    {
        static string problem = "C";

        static string[] lines = System.IO.File.ReadAllLines("E:\\dev\\codejam\\2015\\CodeJam\\CodeJam\\io\\" + problem + ".in");
        static List<string> output = new List<string>();
        static int line_no = 0;

        static void WriteOutput()
        {
            System.IO.File.WriteAllLines("E:\\dev\\codejam\\2015\\CodeJam\\CodeJam\\io\\" + problem + ".out", output);
        }

        static void Write<T>(T data)
        {
            output.Add(data.ToString());
        }

        static bool hasNextLine()
        {
            return line_no < lines.Length;
        }

        static string nextLine()
        {
            return lines[line_no++];
        }

        static int nextLineAsInt()
        {
            return int.Parse(nextLine());
        }

        static long nextLineAsLong()
        {
            return long.Parse(nextLine());
        }

        static string[] nextLineSeparated()
        {
            return nextLine().Split(' ');
        }

        static int[] nextLineSeparatedAsInt()
        {
            return nextLineSeparated().Select(t => int.Parse(t)).ToArray();
        }

        static long[] nextLineSeparatedAsLong()
        {
            return nextLineSeparated().Select(t => long.Parse(t)).ToArray();
        }

        static void Main(string[] args)
        {
            int T = nextLineAsInt();
            for (int i = 0; i < T; i++)
            {
                solve(i + 1);
            }
            WriteOutput();
        }

        static void solve(int caseNo)
        {
            int[] data = nextLineSeparatedAsInt();
            int n = data[0];
            int j = data[1];
            long diff = (long)Math.Pow(2, n - 1) + 1;
            long max = (long)Math.Pow(2, n - 2);
            List<BigInteger> primes = computePrimesWithSieve((long)Math.Pow(2, 20)).Select(t => new BigInteger(t)).ToList();
            List<BigInteger> basesList = new List<BigInteger>();
            for(int i = 2; i <= 10; i++)
            {
                basesList.Add(new BigInteger(i));
            }
            BigInteger[] bases = basesList.ToArray();
            Write(string.Format("Case #{0}:", caseNo));
            for (long i = 0; i < max && j > 0; i++)
            {
                long nr = (i << 2) + diff;
                var result = isCoinJam(nr, bases, primes);
                if(result != null)
                {
                    j--;
                    string line = LongToB2String(nr);
                    foreach(var r in result)
                    {
                        line += " " + r.ToString();
                    }
                    Write(line);
                }
            }
        }

        static BigInteger[] isCoinJam(long x, BigInteger[] bases, List<BigInteger> primes)
        {
            BigInteger[] result = new BigInteger[bases.Length];

            bool[] bx = LongToBoolArray(x);
            for(int i = 0; i < bases.Length; i++)
            {
                result[i] = getDivisorInBase(bx, bases[i], primes, new BigInteger(x));
                if(result[i].IsZero)
                {
                    return null;
                }
            }
            return result;

        }

        static BigInteger getDivisorInBase(bool[] x, BigInteger b, List<BigInteger> primes, BigInteger max)
        {
            foreach(var prime in primes)
            {
                if (prime.CompareTo(max) >= 0) return BigInteger.Zero;
                if (isDivisibleBy(x, b, prime))
                {
                    return prime;
                }
            }
            return BigInteger.Zero;
        }

        static bool[] LongToBoolArray(long x)
        {
            List<bool> xIn2 = new List<bool>();
            while (x > 0)
            {
                xIn2.Add(x % 2 == 1);
                x = x >> 1;
            }
            return xIn2.ToArray();
        }

        static string BoolArrayToString(bool[] b)
        {
            return string.Join("", b.Reverse().Select(t => t ? '1' : '0'));
        }

        static string LongToB2String(long x)
        {
            return BoolArrayToString(LongToBoolArray(x));
        }

        static bool isDivisibleBy(bool[] x, BigInteger b, BigInteger prime)
        {
            BigInteger rem = BigInteger.Zero;
            for (int i = 0; i < x.Length; i++)
            {
                if (x[i])
                {
                    rem = BigInteger.Add(rem, BigInteger.ModPow(b, i, prime));
                }
            }
            return BigInteger.Remainder(rem, prime).IsZero;
        }

        static List<long> computePrimesWithSieve(long max)
        {
            var primes = new List<long>();
            bool[] isNotPrime = new bool[max + 1];
            isNotPrime[0] = isNotPrime[1] = true;
            for(long i = 2; i <= max/2; i++)
            {
                if (!isNotPrime[i])
                {
                    long x = i * 2;
                    while(x <= max)
                    {
                        isNotPrime[x] = true;
                        x += i;
                    }
                }
            }
            for(long i = 2; i <= max; i++)
            {
                if (!isNotPrime[i]) primes.Add(i);
            }
            return primes;
        }
    }
}
