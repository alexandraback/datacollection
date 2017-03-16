using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016Qualification3
{
    class Program
    {
        struct NumberProp
        {
            public bool IsPrime;
            public long Divisor;
        }
        static void Main(string[] args)
        {
            checked
            {
                var inputPath = @"C:\Users\Alexander\Documents\CodeJam2016Q3Test.txt";
                var outputPath = @"C:\Users\Alexander\Documents\CodeJam2016Q3TestOut.txt";

                var input = File.ReadAllLines(inputPath);
                var output = new List<string>();
                var nlines = int.Parse(input[0]);

                for (int i = 1; i <= nlines; i++)
                {
                    int step = 0;
                    var values = input[i].Split(new[] { ' ' });

                    int N = int.Parse(values[0]);
                    int J = int.Parse(values[1]);
                    long minValue = 1;
                    minValue <<= N - 1;
                    minValue += 1;

                    long maxValue = (1 << N) - 1;
                    
                    int haveResults = 0;
                    output.Add(string.Format("Case #{0}:", i));
                    for (long j = minValue; j <= maxValue; j += 2)
                    {
                        var resValues = new List<long>(9);
                        var binaryString = Convert.ToString((int)j, 2);
                        for (byte baseN = 2; baseN <= 10; baseN++)
                        {
                            long devisor = GetDivisor(StringParseBaseN(binaryString, baseN));
                            if (devisor == 0)
                            {
                                break;
                            }
                            resValues.Add(devisor);
                        }
                        if (resValues.Count == 9)
                        {
                            output.Add(string.Format("{0} {1}", Convert.ToString((int)j, 2), string.Join(" ", resValues)));
                            haveResults += 1;
                            if (haveResults == J)
                                break;
                        }
                    }

                }

                File.WriteAllLines(outputPath, output);
            }
        }

        public static long StringParseBaseN(string str, byte baseN)
        {
            long result = 0;
            foreach(char c in str)
            {
                result *= baseN;
                if (c == '1')
                    result += 1;
            }

            return result;
        }

        private static long GetDivisor(long num)
        {
            for (long i = 2; i < Math.Min(10000000, num); i++)
            {
                if (num % i == 0)
                {
                    return i;
                }
            }

            return 0;
        }
    }
}
