using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

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
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": ");
                ProcessLine(input, output);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            int[] AN = ReadIntsLine(input);
            int currentSize = AN[0];
            int[] motes = ReadIntsLine(input);
            int[] creates = new int[motes.Length];
            Array.Sort(motes);
            int index = 0;
            int operations = 0;
            while (index < motes.Length)
            {
                if (currentSize > motes[index])
                {
                    creates[index] = 0;
                }
                else
                {
                    creates[index] = TryCreate(ref currentSize, motes, index);
                }
                currentSize += motes[index];
                index++;
            }
            int count = 0;
            int created = 0;
            for (index = motes.Length - 1; index > -1; index--)
            {
                count++;
                created += creates[index];
                if (created > count)
                {
                    operations += count;
                    created = count = 0;
                }
            }
            operations += created;
            output.WriteLine(operations.ToString());
        }

        private static int TryCreate(ref int currentSize, int[] motes, int index)
        {
            int result = 0;
            if (currentSize == 1)
            {
                return 100000000;
            }
            while (currentSize <= motes[index])
            {
                currentSize = (currentSize << 1) - 1;
                ++result;
            }
            return result;
        }

        private static int[] ReadIntsLine(TextReader input)
        {
            string[] numbers = input.ReadLine().Split(' ');
            int[] result = new int[numbers.Length];
            for (int index = 0; index < numbers.Length; index++)
            {
                result[index] = int.Parse(numbers[index]);
            }
            return result;
        }
    }
}
