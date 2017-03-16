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

        static List<int> numsResult;

        private static void solveTestCase()
        {
            int n = readInteger();
            var lines = new List<string>();
            string line = input.ReadLine();
            string baseString = obtainBase(line);
            var nums = new List<List<int>>();
            nums.Add(numsResult);
            for (int i = 1; i < n; ++i)
            {
                line = input.ReadLine();
                if (obtainBase(line) != baseString)
                {
                    output.WriteLine("Fegla Won");
                    return;
                }
                lines.Add(line);
                nums.Add(numsResult);
            }

            int total = 0;
            for (int i = 0; i < baseString.Length; ++i)
            {
                total += calc(nums.Select(a => a[i]).ToArray());
            }

            output.WriteLine(total);
            return;
        }

        private static int calc(int[] ns)
        {
            int max = ns.Max();
            int min = ns.Min();

            int dist = 99999999;

            for (int b = min; b <= max; ++b) {
                int ndist = getDist(b, ns);
                if (ndist < dist) {
                    dist = ndist;
                }
            }

            return dist;
        }

        private static int getDist(int b, int[] ns)
        {
            int total = 0;
            foreach (int n in ns) {
                total += Math.Abs(n - b);
            }
            return total;
        }

        private static string obtainBase(string line) {
            numsResult = new List<int>();
            StringBuilder build = new StringBuilder();
            char prev = '\0';
            int current = 0;
            foreach (char c in line) {
                if (c != prev)
                {
                    if (prev != 0)
                    {
                        numsResult.Add(current);
                    }
                    current = 1;
                    build.Append(c);
                }
                else {
                    ++current;
                }
                prev = c;
            }
            numsResult.Add(current);

            return build.ToString();
        }
   }
}