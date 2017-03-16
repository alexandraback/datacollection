using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= numberOfCases; currentCase++)
            {
                string[] numbers = input.ReadLine().Split(' ');
                int first = int.Parse(numbers[0]);
                int second = int.Parse(numbers[1]);

                byte[] minimumBytes = ASCIIEncoding.ASCII.GetBytes(first.ToString());
                int minimum = DecodeDecimal(minimumBytes, 0, minimumBytes.Length);
                
                byte[] maximumBytes = ASCIIEncoding.ASCII.GetBytes(second.ToString());
                int maximum = DecodeDecimal(maximumBytes, 0, maximumBytes.Length);

                bool[] accountedFor = new bool[2000001];
                const int multiplySize = 8;
                int[] multiply = new int[multiplySize];
                multiply[0] = 0;
                for (int index = 1; index < multiplySize; index++)
                {
                    multiply[index] = multiply[index - 1] + index;
                }
                int count = 0;
                for (int position = first; position <= second; position++)
                {
                    if (!accountedFor[position])
                    {
                        List<int> convolutions = FindPermutations(position, minimum, maximum);
                        foreach (int value in convolutions)
                        {
                            accountedFor[value] = true;
                        }
                        count += multiply[convolutions.Count - 1];
                    }
                }
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, count));
            }
        }

        private static int DecodeDecimal(byte[] bytes, int startPosition, int length)
        {
            int result = 0;
            for (int index = startPosition; index < startPosition + length; index++)
            {
                result = (result * 10) + (bytes[index] - (byte)'0');
            }
            return result;
        }

        private static List<int> FindPermutations(int position, int minimum, int maximum)
        {
            string converted = position.ToString();

            byte[] posBytes = ASCIIEncoding.ASCII.GetBytes(converted + converted);
            List<int> results = new List<int>();
            for (int checkDigit = 0; checkDigit < converted.Length; checkDigit++)
            {
                int value = DecodeDecimal(posBytes, checkDigit, converted.Length);
                if (value >= minimum && value <= maximum)
                {
                    if (!results.Contains(value))
                    {
                        results.Add(value);
                    }
                }
            }
            return results;
        }
    }
}
