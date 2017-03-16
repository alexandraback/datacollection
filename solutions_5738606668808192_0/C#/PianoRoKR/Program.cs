using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace CoinJam
{
    class Program
    {

        static void Main(string[] args)
        {
            Console.ReadLine();
            string lTemp = Console.ReadLine();
            int n = int.Parse(lTemp.Split(' ')[0]);
            int j = int.Parse(lTemp.Split(' ')[1]);
            string[][] nums = new string[j][];
            for(int i = 0; i < j; i++)
            {
                nums[i] = new string[10];
            }
            int lCount = 0;
            string lNumString = "1".PadRight(n - 1, '0') + "1";
            bool lSuccess = false;
            while(lCount < j)
            {
                lSuccess = false;
                nums[lCount][0] = lNumString;
                List<BigInteger> test = new List<BigInteger>();
                for(int b = 2; b <= 10; b++)
                {
                    BigInteger lNumInBase = ConvertToBase(lNumString, b);
                    BigInteger lFactor = ReturnFactor(lNumInBase);
                    if (lFactor == 0)
                        break;
                    nums[lCount][b - 1] = lFactor.ToString();
                    if (b == 10)
                        lSuccess = true;
                }
                if (lSuccess)
                {
                    lCount++;
                }

                lNumString = Inc(lNumString);
            }
            Console.WriteLine("Case #1:");
            for (int i = 0; i < j; i++)
            {
                foreach(string lInt in nums[i])
                {
                    Console.Write("{0} ", lInt);
                }
                Console.WriteLine();
            }
        }
        static string Inc(string aVal)
        {
            int lCarry = 0;
            string lNewVal = "";
            List<int> ConvertedNum = aVal.Select(c => (int)(c - '0')).Reverse().ToList();
            ConvertedNum[0] = 1;
            ConvertedNum[1] += 1;
            foreach (int lNum in ConvertedNum)
            {
                if (lNum + lCarry == 2)
                {
                    lCarry = 1;
                    lNewVal = "0" + lNewVal;
                }
                else
                {
                    lNewVal = (lNum + lCarry).ToString() + lNewVal;
                    lCarry = 0;
                }
            }
            return lNewVal;
        }
        static BigInteger ConvertToBase(string lStrVal, int lBase)
        {
            BigInteger lStart = 1;
            BigInteger lNum = 0;
            foreach (char lChar in lStrVal.Reverse())
            {
                if (lChar == '1')
                {
                    lNum += lStart;
                }
                lStart *= lBase;
            }
            return lNum;
        }

        static BigInteger ReturnFactor(BigInteger aVal)
        {
            BigInteger lMaxCheck = (BigInteger)Math.Exp(BigInteger.Log(aVal) / 2);
            if(aVal.IsEven)
                return 2;
            if (lMaxCheck > 100000)
                lMaxCheck = 100000;
            for (ulong i = 3; i < lMaxCheck; i += 2)
            {
                if (aVal % i == 0)
                    return i;
            }
            return 0;
        }
    }
}
