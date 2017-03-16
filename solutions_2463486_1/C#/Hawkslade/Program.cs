using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    class FairAndSquare
    {
        static long[] fairAndSquareNumbers = new long[39] {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 
                400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 
                1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004 };
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
            long numberOfCases = long.Parse(input.ReadLine());
            for (long currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": ");
                ProcessLine(input, output);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            long[] ab = ReadlongsLine(input);
            long from = ab[0];
            long to = ab[1];
            if ((from > to) || (to < 1) || (from > fairAndSquareNumbers[fairAndSquareNumbers.Length - 1]))
            {
                output.WriteLine("0");
                return;
            }
            long fromIndex = 0;
            long toIndex = 0;
            for (long index = 0; index < fairAndSquareNumbers.Length; index++)
            {
                if (fairAndSquareNumbers[index] < from)
                {
                    fromIndex = index + 1;
                }
                if (fairAndSquareNumbers[index] <= to)
                {
                    toIndex = index;
                }
                else
                {
                    break;
                }
            }
            output.WriteLine((toIndex - fromIndex + 1).ToString());
        }

        private static long[] ReadlongsLine(TextReader input)
        {
            string[] numbers = input.ReadLine().Split(' ');
            long[] result = new long[numbers.Length];
            for (long index = 0; index < numbers.Length; index++)
            {
                result[index] = long.Parse(numbers[index]);
            }
            return result;
        }

    }
}
