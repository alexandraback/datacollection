using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace FairAndSquare
{
    class Program
    {
        static int numberOfTestcases = 0;
        static string[] allInputLines, allOutputLines;
        static char[] split = { ' ' };

        static long[] fairAndSquare;
        static int totalFairAndSquare;

        static void Main(string[] args)
        {
            allInputLines = File.ReadAllLines("Input.txt");
            numberOfTestcases = int.Parse(allInputLines[0].Trim());
            allOutputLines = new String[numberOfTestcases];
            GenerateAllFairAndSquareNumber();
            for (int i = 1; i <= numberOfTestcases; i++)
            {
                int output = NumberOfFairAndSquare(i);
                allOutputLines[i - 1] = String.Format("Case #{0}: {1}", i, output);
            }
            File.WriteAllLines("Output.txt", allOutputLines);
        }

        static void GenerateAllFairAndSquareNumber()
        {
            long[] rootPalCandidates = new long[] {1,2,3,11,22,101,111,121,202,212,1001,1111,1221, 2002, 2112,
            10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 20202, 21012, 21212, 100001, 101101, 110011, 111111, 200002, 201102,
            1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 1112111,
            1200021, 1201021, 1210121, 1211121, 1212121, 2000002, 2001002, 2010102, 2012102, 10000001 };

            List<long> fairSquareList = new List<long>();

            foreach (long item in rootPalCandidates)
                if (CheckPalindrome(item * item))
                    fairSquareList.Add(item * item);
            fairAndSquare = fairSquareList.ToArray();
            totalFairAndSquare = fairSquareList.Count;
        }

        static bool CheckPalindrome(long data)
        {
            long save = data;
            long reverse = 0;
            long digit = 0;
            while (data > 0)
            {
                digit = data % 10;
                reverse = reverse * 10 + digit;
                data = data / 10;
            }
            if (save == reverse) return true;
            return false;
        }

        static int NumberOfFairAndSquare(int testCase)
        {
            long A, B;
            string[] inputs = allInputLines[testCase].Split(split);
            A = long.Parse(inputs[0]);
            B = long.Parse(inputs[1]);
            int countOfFandS = 0;
            for (int i = 0; i < totalFairAndSquare; i++)
            {
                if (fairAndSquare[i] < A) continue;
                if (fairAndSquare[i] > B) break;
                countOfFandS++;
            }
            return countOfFandS;
        }
    }
}
