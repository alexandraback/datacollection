using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

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
                var outputPath = @"C:\Users\Alexander\Documents\CodeJam2016Q3TestSmall.txt";

                var input = File.ReadAllLines(inputPath);
                var output = new List<string>();
                var nlines = int.Parse(input[0]);

                for (int i = 1; i <= nlines; i++)
                {
                    int step = 0;
                    var values = input[i].Split(new[] { ' ' });

                    byte N = byte.Parse(values[0]);
                    int J = int.Parse(values[1]);
                    BigInteger minValue = 1;
                    minValue <<= N - 1;
                    minValue += 1;

                    BigInteger maxValue = StringParseBaseN(new string('1', N), 2);
                    
                    int haveResults = 0;
                    output.Add(string.Format("Case #{0}:", i));
                    for (BigInteger j = minValue; j <= maxValue; j += 2)
                    {
                        var resValues = new List<ulong>(9);
                        var binaryString = UlongToBase2String(j);
                        for (byte baseN = 2; baseN <= 10; baseN++)
                        {
                            ulong devisor = GetDivisor(StringParseBaseN(binaryString, baseN));
                            if (devisor == 0)
                            {
                                break;
                            }
                            resValues.Add(devisor);
                        }
                        if (resValues.Count == 9)
                        {
                            Console.WriteLine(binaryString);
                            output.Add(string.Format("{0} {1}", binaryString, string.Join(" ", resValues)));
                            haveResults += 1;
                            if (haveResults == J)
                                break;
                        }
                    }

                }

                File.WriteAllLines(outputPath, output);
            }
        }

        public static BigInteger StringParseBaseN(string str, byte baseN)
        {
            BigInteger result = 0;
            foreach(char c in str)
            {
                result *= baseN;
                if (c == '1')
                    result += 1;
            }

            return result;
        }

        public static string UlongToBase2String(BigInteger val)
        {
            var sb = new StringBuilder();
            while(val != 0)
            {
                sb.Insert(0, (val % 2).ToString());
                val /= 2;
            }
            
            return sb.ToString();
        }

        private static ulong GetDivisor(BigInteger num)
        {
            for (ulong i = 2; i < Math.Min((ulong)num, 1000000); i++)
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
