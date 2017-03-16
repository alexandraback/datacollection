using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam
{
    class Program
    {
        //I'm not seeing the trick to this, so I'll give up after a few primes to reduce computational time. I pray these are enough.
        static uint[] _checkPrimes = new uint[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
            31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
            73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
            127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
            179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
            233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 
            283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 
            353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 
            419, 421, 431, 433, 439, 443, 449, 457, 461, 463 };

        static void Main(string[] args)
        {
            //string outputFrame = "Case #{0}: {1}";
            string outputFrame = "Case #{0}:";

            int caseCount = int.Parse(Console.ReadLine());
            for (int caseIdx = 1; caseIdx <= caseCount; caseIdx++)
            {
                string[] testLineSegments = Console.ReadLine().Split(' ');
                int jamLength = int.Parse(testLineSegments[0]);
                int jamCount = int.Parse(testLineSegments[1]);

                Console.WriteLine(String.Format(outputFrame, caseIdx));
                MakeJams(jamLength, jamCount);
            }
        }

        static String JamCoinToBinaryString(uint jamCoin, int jamLength)
        {
            String result = "";
            for (int digit = 0; digit < jamLength; digit++)
            {
                result = ((jamCoin & (1U << digit)) > 0 ? "1" : "0") + result;
            }
            return result;
        }

        static void MakeJams(int jamLength, int jamCount)
        {
            uint jamBase = 1U + (1U << (jamLength - 1));

            uint successCount = 0;
            uint fillerMaxCount = 2U << jamLength - 2;
            for (uint fillIndex = 0; fillIndex < fillerMaxCount; fillIndex++)
            {
                uint jamCandidate = jamBase | (fillIndex << 1);

                uint[] divisors;
                if (TestJamCandidate(jamCandidate, jamLength, out divisors))
                {
                    Console.WriteLine(JamCoinToBinaryString(jamCandidate, jamLength) + " " + String.Join(" ", divisors));

                    successCount++;
                    if (successCount == jamCount)
                        break;
                }
            }
        }

        static ulong MakeBase(uint jamCandidate, uint jamBase, int jamLength)
        {
            if (jamBase == 2)
                return jamCandidate;

            ulong basedNumber = 0;
            ulong basedMultiplier = 1;
            for (int i = 0; i < jamLength; i++)
            {
                if ((jamCandidate & (1UL << i)) > 0)
                {
                    basedNumber += basedMultiplier;
                }

                basedMultiplier *= jamBase;
            }

            return basedNumber;
        }

        static bool TestJamCandidate(uint jamCandidate, int jamLength, out uint[] divisors)
        {
            divisors = new uint[9];

            for (uint jamBase = 2; jamBase <= 10; jamBase ++)
            {
                bool foundDivisor = false;

                ulong basedNumber = MakeBase(jamCandidate, jamBase, jamLength);                
                foreach (uint divisor in _checkPrimes)
                {
                    if (basedNumber % divisor == 0)
                    {
                        divisors[jamBase - 2] = divisor;
                        foundDivisor = true;
                        break;
                    }
                }

                if (!foundDivisor)
                    return false;
            }

            return true;
        }
    }
}
