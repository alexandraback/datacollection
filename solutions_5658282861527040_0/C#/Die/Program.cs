using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Problem_A
{
    public class Program
    {
        public static String inputFilename = "input.in";
        public static String outputFilename = "output.out";
        private static StreamWriter output;
        private static StreamReader input;

        static void Main(string[] args)
        {
            using (var tempInput = File.OpenText(inputFilename))
            {
                input = tempInput;
                using (var tempOutput = new System.IO.StreamWriter(outputFilename))
                {
                    output = tempOutput;
                    var testCasesCount = int.Parse(input.ReadLine());
                    for (var testCaseNumber = 1; testCaseNumber <= testCasesCount; ++testCaseNumber)
                    {
                        output.Write(String.Format("Case #{0}: ", testCaseNumber));
                        solveTestCase();
                    }
                }
            }
        }

        private static int[] readIntegers()
        {
            return input.ReadLine().Split(' ').Select(piece => int.Parse(piece)).ToArray();
        }

        private static double[] readDoubles()
        {
            return input.ReadLine().Split(' ').Select(piece => double.Parse(piece)).ToArray();
        }

        private static int readInteger()
        {
            return int.Parse(input.ReadLine());
        }

        private static double readDouble()
        {
            return double.Parse(input.ReadLine());
        }

        private static void solveTestCase()
        {
            int[] ints = readIntegers();
            int a = ints[0], b = ints[1], k = ints[2];
            int total = 0;
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j)
                {
                    if ((i & j) < k) {
                        ++total;
                    }
                }
            }
            output.WriteLine(total);
        }
    }
}