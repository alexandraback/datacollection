using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cjr1ba1
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputText = File.ReadAllText(args[0]).Replace("\r\n", "\n").Replace("\r", "\n");
            string inputFilename = Path.GetFileNameWithoutExtension(args[0]);
            string[] input = inputText.Split('\n');
            StreamWriter output = new StreamWriter(String.Format("{0}.out", inputFilename));

            int T = Int32.Parse(input[0]);
            for (int t = 1; t <= T; ++t)
            {
                output.WriteLine(ProcessTest(t, input[t]));
                output.Flush();
            }

            output.Close();
        }

        private static string ProcessTest(int t, string p)
        {
            List<int> numbers = p.Trim().Split(' ').Select(s => Int32.Parse(s)).ToList();
            if (numbers[0] + 1 != numbers.Count)
                throw new ApplicationException();
            numbers.RemoveAt(0);
            int sum = numbers.Sum();
            List<decimal> results = numbers
                .Select(n => (decimal)(sum - n)/(decimal)sum/(decimal)(numbers.Count - 1))
                .ToList();
            List<string> formattedResults = results
                .Select(r => (r*100m).ToString("0.000000"))
                .ToList();
            string result = String.Format("Case #{0}: {1}", t, String.Join(" ", formattedResults.ToArray()));
            return result;
        }
    }
}
