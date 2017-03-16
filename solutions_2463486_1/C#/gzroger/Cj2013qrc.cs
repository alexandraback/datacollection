using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Cj2013qrc
{
    class Program
    {
        private static void Main(string[] args)
        {
            var fn = "C-large-1.in";
            HashSet<BigInteger> hlmBiSqFa = HlmSqFaGenerate();
            using (var strIn = File.OpenText("c:\\Users\\zoli\\Downloads\\cj2013\\" + fn))
            using (var strOut = new StreamWriter("c:\\Users\\zoli\\Downloads\\cj2013\\" + fn + ".out"))
            {
                var cCase = int.Parse(strIn.ReadLine());
                for (int iCase = 0; iCase < cCase; iCase++)
                {
                    var rgstLine = new string[4];
                    var rgstAB = strIn.ReadLine().Split(' ');
                    var numA = BigInteger.Parse(rgstAB[0]);
                    var numB = BigInteger.Parse(rgstAB[1]);
                    var numOfSqFa = numSqFaBtw(hlmBiSqFa, numA, numB);

                    Console.WriteLine("Case #{0}: {1}", iCase + 1, numOfSqFa);
                    strOut.WriteLine("Case #{0}: {1}", iCase + 1, numOfSqFa);
                }
            }
            Console.ReadLine();
        }

        public static long numSqFaBtw(HashSet<BigInteger> hlmBiSqFa, BigInteger biA, BigInteger biB)
        {
            return hlmBiSqFa.Count(bi=>biA<=bi && bi<=biB);
        }

        public static HashSet<BigInteger> HlmSqFaGenerate()
        {
            var hlmBiSqFa = new HashSet<BigInteger>();
            for (var nDigit = 1; nDigit <= 5; nDigit++)
            {
                foreach (var rgbiPal in enbiPalGet(nDigit))
                {
                    CSqFa(rgbiPal, hlmBiSqFa);
                    //                    Console.WriteLine("palindromes: {0}", string.Join("", rgbiPal));
                    //                    System.Threading.Thread.Sleep(100);
                }
            }
            return hlmBiSqFa;
        }

        static void MainOld(string[] args)
        {
            long cSqFa = 0;
            for (var nDigit = 1; nDigit <= 25; nDigit++)
            {
                foreach (var rgbiPal in enbiPalGet(nDigit))
                {
                    CSqFa(rgbiPal, new HashSet<BigInteger>());
//                    Console.WriteLine("palindromes: {0}", string.Join("", rgbiPal));
//                    System.Threading.Thread.Sleep(100);
                } 
            }
            Console.WriteLine("All sqfa {0}", cSqFa);
            Console.ReadLine();
        }

        private static IEnumerable<int[]> enbiPalGet(int nDigit)
        {
            return enbiPalGetI(nDigit, 0, new int[0]);
        }
        private static IEnumerable<int[]> enbiPalGetI(int nDigit, int iDigit, int[] rgstate)
        {
            if (iDigit == nDigit)
                yield return rgstate;
            else 
                for (int digit = 0; digit < 10; digit++)
                {
                    if (!((iDigit == (nDigit - 1)) && (digit == 0)))
                    {
                        if (iDigit == 0)
                        {
                            var rgstate1 = new int[] {digit};
                            foreach (var intse in enbiPalGetI(nDigit, iDigit + 1, rgstate1))
                            {
                                yield return intse;
                            }
                        }
                        var rgstateNew = new int[rgstate.Length + 2];
                        Array.Copy(rgstate, 0, rgstateNew, 1, rgstate.Length);
                        rgstateNew[0] = digit;
                        rgstateNew[rgstateNew.Length - 1] = digit;
                        foreach (var intse in enbiPalGetI(nDigit, iDigit + 1, rgstateNew))
                        {
                            yield return intse;
                        }
                    }
                }
        }

        private static void CSqFa(int[] rgdecBipal1, HashSet<BigInteger> hlmBiSqFa)
        {
            var biPal1 = rgdecBipal1.Aggregate<int, BigInteger>(0, (current, dec) => current*10 + dec);
            var biPal1Sq = biPal1*biPal1;
            if (fFair(biPal1Sq))
            {
//                Console.WriteLine("sq&f: {0}, sq of {1}", biPal1Sq, biPal1);
                hlmBiSqFa.Add(biPal1Sq);
            }
        }

        private static bool fFair(BigInteger bi)
        {
            var rgDigits = new List<int>();
            while (bi > 0)
            {
                rgDigits.Add((int) (bi%10));
                bi = bi/10;
            }
            for (int iDigit = 0; iDigit < rgDigits.Count / 2; iDigit++)
                if (rgDigits[iDigit] != rgDigits[rgDigits.Count - iDigit - 1])
                    return false;

            return true;
        }
    }
}
