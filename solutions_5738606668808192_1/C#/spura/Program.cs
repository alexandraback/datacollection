using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace C
{
    class Program
    {
        static BigInteger[,] BasePowers = new BigInteger[11, 33];

        static int MaxPrimes = 30000;
        static long[] Primes = new long[MaxPrimes];

        static bool CheckPrime(long l, int j)
        {
            for(int k=1; k< j; k++) // skip '2'
            {
                if (l % Primes[k] == 0)
                    return false;
            }

            return true;
        }

        static void Main(string[] args)
        {
            // make tables
            for(int b=2; b<=10; b++)
            {
                BigInteger bb = new BigInteger(b);
                BasePowers[b, 0] = new BigInteger(1);
                BasePowers[b, 1] = bb;

                for (int i=2; i<=32; i++)
                {
                    BigInteger bi = BasePowers[b, i - 1];
                    bi *= bb;
                    BasePowers[b, i] = bi;
                }
            }

            // make primes
            int j = 0;
            Primes[j++] = 2;
            long l = 1;
            while(j < MaxPrimes)
            {
                l += 2;

                if(CheckPrime(l, j))
                {
                    Primes[j++] = l;
                }
            }

            string sInFileName = "c:/in.txt";
            string sOutFileName = "c:/out.txt";

            string sIn = File.ReadAllText(sInFileName);
            StringReader oSR = new StringReader(sIn);

            StringBuilder oAnswer = new StringBuilder();

            // read number of cases
            int T = int.Parse(oSR.ReadLine());

            // case by case
            for (int i = 0; i < T; i++)
            {
                string sLine = oSR.ReadLine();
                string[] aLine = sLine.Split(' ');
                int N = int.Parse(aLine[0]);
                int J = int.Parse(aLine[1]);

                string s = Solve(N, J);
                // write answer
                oAnswer.AppendFormat("Case #{0}:\n", i + 1);
                oAnswer.Append(s);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        static string MakeSolLine(bool[] aDigs, int N, BigInteger[] aDivs)
        {
            StringBuilder s = new StringBuilder();
            for(int i=N-1; i>= 0; i--)
            {
                if (aDigs[i])
                    s.Append('1');
                else
                    s.Append('0');
            }
            foreach (BigInteger x in aDivs)
            {
                s.Append(' ');
                s.Append(x.ToString());
            }

            return s.ToString();
        }

        static string Solve(int N, int J)
        {
            StringBuilder sSol = new StringBuilder();
            BigInteger[] aDivs = new BigInteger[9];
            bool[] aDigs = new bool[N];
            aDigs[0] = true;
            aDigs[N - 1] = true;

            while(J > 0)
            {
                if (Check(aDigs, N, aDivs))
                {
                    string s = MakeSolLine(aDigs, N, aDivs);
                    sSol.AppendLine(s);
                    J--;
                    if (J == 0)
                        break;
                }

                Inc(aDigs, N);
            }

            return sSol.ToString();
        }

        static void Inc(bool[] aDigs, int N)
        {
            for(int i=1; i<N-1; i++)
            {
                if (aDigs[i])
                    aDigs[i] = false;
                else
                {
                    aDigs[i] = true;
                    return;
                }
            }

            throw new ApplicationException("Overflow.");
        }

        static bool Check(bool[] aDigs, int N, BigInteger[] aDivs)
        {
            for (int b = 2; b <= 10; b++)
            {
                BigInteger bi = new BigInteger(0);
                for(int i=0; i< N; i++)
                {
                    if (aDigs[i])
                        bi += BasePowers[b, i];
                }

                BigInteger? d = FindDiv(bi);
                if (d.HasValue)
                    aDivs[b - 2] = d.Value;
                else return false;
            }

            return true;
        }

        static BigInteger? FindDiv(BigInteger bi)
        {
            if (bi == 1)
                return null;
            if (bi == 0)
                throw new ApplicationException("?");

            foreach(BigInteger p in Primes)
            {
                if (bi == p)
                    return null;

                BigInteger r = bi % p;
                if (r == 0)
                    return p;
            }

            return null;
        //    throw new ApplicationException("Not enough primes.");
        }
    }
}
