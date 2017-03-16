using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Problem_A
{
    class Program
    {

        static void Main(string[] args)
        {
            // Num of cases:
            int T = Int32.Parse(Console.ReadLine());

            for (int caseNum = 1; caseNum <= T; caseNum++)
            {
                string S = Console.ReadLine();

                HandleCase(caseNum, S);
            }
        }

        static void HandleCase(int caseNum, string S)
        {
            Dictionary<int, int> DigitsAppearCount = new Dictionary<int, int>();

            S = HandleDigit(DigitsAppearCount, S, 0, 'Z', "ZERO");
            S = HandleDigit(DigitsAppearCount, S, 2, 'W', "TWO");
            S = HandleDigit(DigitsAppearCount, S, 4, 'U', "FOUR");
            S = HandleDigit(DigitsAppearCount, S, 5, 'F', "FIVE");
            S = HandleDigit(DigitsAppearCount, S, 1, 'O', "ONE");
            S = HandleDigit(DigitsAppearCount, S, 3, 'R', "THREE");
            S = HandleDigit(DigitsAppearCount, S, 6, 'X', "SIX");
            S = HandleDigit(DigitsAppearCount, S, 7, 'S', "SEVEN");
            S = HandleDigit(DigitsAppearCount, S, 8, 'G', "EIGHT");
            S = HandleDigit(DigitsAppearCount, S, 9, 'I', "NINE");

            StringBuilder sb = new StringBuilder();
            for (int digit = 0; digit <= 9; digit++)
            {
                if (DigitsAppearCount.ContainsKey(digit))
                {
                    for (int instance = 0; instance < DigitsAppearCount[digit]; instance++)
                    {
                        sb.Append(digit);
                    }
                }
            }

            Console.WriteLine("Case #" + caseNum.ToString() + ": " + sb.ToString());
        }

        static string HandleDigit(Dictionary<int, int> DigitsAppearCount, string S, int DigitIndex, char SpecialDigitToLookFor, string DigitChars)
        {
            int pos = S.IndexOf(SpecialDigitToLookFor);
            while (pos != -1)
            {
                S = RemoveDigitCharsFromString(S, DigitChars);
                if (DigitsAppearCount.ContainsKey(DigitIndex) == false)
                {
                    DigitsAppearCount[DigitIndex] = 0;
                }
                DigitsAppearCount[DigitIndex]++;

                pos = S.IndexOf(SpecialDigitToLookFor);
            }

            return S;
        }

        static string RemoveDigitCharsFromString(string S, string DigitChars)
        {
            foreach (char DigitChar in DigitChars)
            {
                S = RemoveDigitCharFromString(S, DigitChar);
            }

            return S;
        }

        static string RemoveDigitCharFromString(string S, char DigitChar)
        {
            int pos = S.IndexOf(DigitChar);
            return S.Substring(0, pos) + S.Substring(pos + 1);
        }
    }
}
