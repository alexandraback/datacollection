using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Digits
{
    class Program
    {
        private static StreamReader reader = null;
        private static StreamWriter writer = null;

        static void Main()
        {
            reader = new StreamReader("C-small-attempt0.in");
            writer = new StreamWriter("C-small.out");
            //reader = new StreamReader("C-large.in");
            //writer = new StreamWriter("C-large.out");

            using (reader)
            {
                using (writer)
                {
                    int tests = int.Parse(reader.ReadLine());
                    string line = null;
                    string[] data = new string[2];
                    int start = 0;
                    int end = 0;
                    int numbersCount = 0;

                    for (int test = 0; test < tests; test++)
                    {
                        line = reader.ReadLine();
                        data = line.Split(' ');
                        start = int.Parse(data[0]);
                        end = int.Parse(data[1]);
                        numbersCount = 0;

                        GenerateNumbers(start, end, ref numbersCount);

                        writer.WriteLine("Case #{0}: {1}", test + 1, numbersCount);
                    }
                }
            }
        }

        private static void GenerateNumbers(int start, int end, ref int counter)
        {
            for (int i = start; i <= end; i++)
            {
                int length = end.ToString().Length;
                int[] digits = new int[length];
                int multiplier = 10;
                int number = i;
                for (int j = length - 1; j >= 0; j--)
                {
                    digits[j] = number % multiplier;
                    number /= multiplier;
                }

                GenerateRotations(digits, ref counter, start, end);
            }
        }

        private static int ParseArrayToDigit(int[] result)
        {
            int multiplier = 1;
            int toReturn = 0;

            for (int i = result.Length - 1; i >= 0; i--)
            {
                toReturn += result[i] * multiplier;

                multiplier *= 10;
            }

            return toReturn;
        }

        private static void GenerateRotations(int[] result, ref int counter, int start, int end)
        {
            int[] bufferArray = new int[result.Length];
            int index = 0;
            int digit = ParseArrayToDigit(result);
            HashSet<int> usedNumbers = new HashSet<int>();

            int initialDigit = digit;

            for (int i = result.Length - 1; i >= 1; i--)
            {
                index = 0;
                for (int j = i; j < result.Length; j++)
                {
                    bufferArray[index] = result[j];
                    index++;
                }

                for (int k = 0; k < i; k++)
                {
                    bufferArray[index] = result[k];
                    index++;
                }

                digit = ParseArrayToDigit(bufferArray);

                if (digit >= start && initialDigit < digit && digit <= end)
                {
                    if (!usedNumbers.Contains(digit))
                    {
                        counter++;
                        usedNumbers.Add(digit);
                    }
                }
            }

        }
    }
}
