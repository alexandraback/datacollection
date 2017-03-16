using System;
using System.Collections.Generic;
using System.Linq;

namespace qtn1
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCount = int.Parse(Console.ReadLine().Trim());

            for (int i = 0; i < testCount; i++)
                SolveProblem(i + 1);
        }

        private static void SolveProblem(int testNum)
        {
            double result = 0;
            string[] parts = Console.ReadLine().Trim().Split(' ');
            int K = int.Parse(parts[0]);
            int L = int.Parse(parts[1]);
            int S = int.Parse(parts[2]);

            char[] keyBoard = Console.ReadLine().ToCharArray();
            char[] target = Console.ReadLine().ToCharArray();

            Dictionary<char, int> keyboardDic = new Dictionary<char, int>();
            foreach (char ch in keyBoard)
            {
                if (keyboardDic.ContainsKey(ch))
                    keyboardDic[ch] += 1;
                else
                    keyboardDic[ch] = 1;
            }

            Dictionary<char, int> targetDic = new Dictionary<char, int>();
            foreach (char ch in target)
            {
                if (targetDic.ContainsKey(ch))
                    targetDic[ch] += 1;
                else
                    targetDic[ch] = 1;
            }

            //check if keyboard does not contain all the letters of target
            foreach (char ch in targetDic.Keys)
            {
                if (!keyboardDic.Keys.Contains<char>(ch))
                {
                    Console.WriteLine("Case #" + testNum + ": 0.0");
                    return;
                }
            }

            // just small
            // brute force
            // all results and then probabilities 7^7=823543

            List<char[]> list = new List<char[]>();
            int[] factors = new int[S];

            for (int i = 0; i < S; i++)
                factors[i] = 0;

            while (factors[S - 1] < keyBoard.Length)
            {
                char[] val = new char[S];
                // generate word
                for (int i = 0; i < S; i++)
                {
                    val[i] = keyBoard[factors[i]];
                }
                list.Add(val);
                // arrange factors
                int j = 0;
                for (; j < S; j++)
                {
                    if (factors[j] < keyBoard.Length - 1)
                    {
                        factors[j] += 1;
                        for (int k = 0; k < j; k++)
                        {
                            factors[k] = 0;
                        }
                        break;
                    }
                }
                if (j == S)
                    factors[S - 1] = keyBoard.Length;
            }

            // all possibilities are generated
            // calculate the max number of bananas required

            int maxNumOfBananasRequired = 0;
            int numOfTotalBananasGiven = 0;

            string strTarget = new String(target);

            foreach (char[] arr in list)
            {
                string s = new String(arr);
                int localMaxNumOfBananas = 0;
                while (true)
                {
                    int ind = s.IndexOf(strTarget);
                    if (ind < 0)
                    {
                        break;
                    }

                    if (ind == s.Length)
                    {
                        numOfTotalBananasGiven += 1;
                        localMaxNumOfBananas += 1;
                        break;
                    }
                    else
                    {
                        s = s.Substring(ind + 1);
                        numOfTotalBananasGiven += 1;
                        localMaxNumOfBananas += 1;
                    }
                }

                if (localMaxNumOfBananas > maxNumOfBananasRequired)
                    maxNumOfBananasRequired = localMaxNumOfBananas;
            }

            result = maxNumOfBananasRequired - (numOfTotalBananasGiven * 1.0) / list.Count;
            result = Math.Round(result, 7);
            string strResult = result.ToString();
            strResult = strResult.Replace(',', '.');

            if (strResult.Length == 1)
                strResult = strResult + ".0";

            Console.WriteLine("Case #" + testNum + ": " + strResult);
        }
    }
}
