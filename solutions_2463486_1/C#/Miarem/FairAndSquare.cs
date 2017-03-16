using System;
using System.IO;
using System.Collections.Generic;
using System.Numerics;

class FairAndSquare
{
    static List<BigInteger> fairAndSquareList = new List<BigInteger>();
    public static void Solve()
    {
        StreamReader input = new StreamReader("C-small-attempt0.in");
        StreamWriter output = new StreamWriter("C-small-attempt0.out");
        char[] separators = { ' ', '\t', '\n' };
        int T = int.Parse(input.ReadLine());
        for (int t = 0; t < T; t++)
        {
            string[] splitLine = input.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries);
            string A = splitLine[0];
            string B = splitLine[1];
            Generate();
            int result = Find(B) - Find(A);
            if (fairAndSquareList.Contains(BigInteger.Parse(A)))
                result++;
            output.WriteLine("Case #{0}: {1}", t + 1, result);
        }
        input.Close();
        output.Close();
    }

    public static int Find(string strValue)
    {
        BigInteger value = BigInteger.Parse(strValue);
        int minIndex = 0;
        int maxIndex = fairAndSquareList.Count;

        while (maxIndex - minIndex > 1)
        {
            int midIndex = (minIndex + maxIndex) / 2;
            if (fairAndSquareList[midIndex] == value)
                return midIndex;
            if (fairAndSquareList[midIndex] > value)
                maxIndex = midIndex;
            else
                minIndex = midIndex;
        }
        if (fairAndSquareList[maxIndex] < value)
            return maxIndex;
        return minIndex;
    }

    public static void Generate()
    {
        fairAndSquareList.Add(BigInteger.Parse("1"));
        fairAndSquareList.Add(BigInteger.Parse("4"));
        fairAndSquareList.Add(BigInteger.Parse("9"));
        for (int i = 1; i < 27; i++)
        {
            GenerateEven(i);
            GenerateOdd(i);
        }
    }

    public static void GenerateEven(int halfLength)
    {
        List<string> palindromeList = new List<string>();
        char[] leftTemplate = new char[halfLength];
        char[] rightTemplate = new char[halfLength];
        for (int i = 0; i < halfLength; i++)
            rightTemplate[i] = leftTemplate[i] = '0';
        rightTemplate[halfLength - 1] = leftTemplate[0] = '1';
        palindromeList.Add(new string(leftTemplate) + new string(rightTemplate));

        for (int i = 1; i < halfLength; i++)
        {
            rightTemplate[halfLength - 1 - i] = leftTemplate[i] = '1';
            palindromeList.Add(new string(leftTemplate) + new string(rightTemplate));
            for (int j = i + 1; j < halfLength; j++)
            {
                rightTemplate[halfLength - 1 - j] = leftTemplate[j] = '1';
                palindromeList.Add(new string(leftTemplate) + new string(rightTemplate));
                for (int k = j + 1; k < halfLength; k++)
                {
                    rightTemplate[halfLength - 1 - k] = leftTemplate[k] = '1';
                    palindromeList.Add(new string(leftTemplate) + new string(rightTemplate));
                    rightTemplate[halfLength - 1 - k] = leftTemplate[k] = '0';
                }
                rightTemplate[halfLength - 1 - j] = leftTemplate[j] = '0';
            }
            rightTemplate[halfLength - 1 - i] = leftTemplate[i] = '0';
        }
        rightTemplate[halfLength - 1] = leftTemplate[0] = '2';
        palindromeList.Add(new string(leftTemplate) + new string(rightTemplate));
        palindromeList.Sort();

        foreach (string palindrome in palindromeList)
        {
            BigInteger rootPalindrome = BigInteger.Parse(palindrome);
            fairAndSquareList.Add(rootPalindrome * rootPalindrome);
        }
    }

    public static void GenerateOdd(int halfLength)
    {
        List<string> palindromeList = new List<string>();
        char[] leftTemplate = new char[halfLength];
        char[] rightTemplate = new char[halfLength];
        for (int i = 0; i < halfLength; i++)
            rightTemplate[i] = leftTemplate[i] = '0';
        rightTemplate[halfLength - 1] = leftTemplate[0] = '1';
        palindromeList.Add(new string(leftTemplate) + "0" + new string(rightTemplate));
        palindromeList.Add(new string(leftTemplate) + "1" + new string(rightTemplate));
        palindromeList.Add(new string(leftTemplate) + "2" + new string(rightTemplate));

        for (int i = 1; i < halfLength; i++)
        {
            rightTemplate[halfLength - 1 - i] = leftTemplate[i] = '1';
            palindromeList.Add(new string(leftTemplate) + "0" + new string(rightTemplate));
            palindromeList.Add(new string(leftTemplate) + "1" + new string(rightTemplate));
            palindromeList.Add(new string(leftTemplate) + "2" + new string(rightTemplate));
            for (int j = i + 1; j < halfLength; j++)
            {
                rightTemplate[halfLength - 1 - j] = leftTemplate[j] = '1';
                palindromeList.Add(new string(leftTemplate) + "0" + new string(rightTemplate));
                palindromeList.Add(new string(leftTemplate) + "1" + new string(rightTemplate));
                for (int k = j + 1; k < halfLength; k++)
                {
                    rightTemplate[halfLength - 1 - k] = leftTemplate[k] = '1';
                    palindromeList.Add(new string(leftTemplate) + "0" + new string(rightTemplate));
                    palindromeList.Add(new string(leftTemplate) + "1" + new string(rightTemplate));
                    rightTemplate[halfLength - 1 - k] = leftTemplate[k] = '0';
                }
                rightTemplate[halfLength - 1 - j] = leftTemplate[j] = '0';
            }
            rightTemplate[halfLength - 1 - i] = leftTemplate[i] = '0';
        }
        rightTemplate[halfLength - 1] = leftTemplate[0] = '2';
        palindromeList.Add(new string(leftTemplate) + "0" + new string(rightTemplate));
        palindromeList.Add(new string(leftTemplate) + "1" + new string(rightTemplate));
        palindromeList.Sort();

        foreach (string palindrome in palindromeList)
        {
            BigInteger rootPalindrome = BigInteger.Parse(palindrome);
            fairAndSquareList.Add(rootPalindrome * rootPalindrome);
        }
    }
}