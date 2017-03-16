using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"D:\Projects\C#\GoogleCodeJam\2016\Round1B\CodeJam\CodeJam\A-large.in";
            const string outputFile = @"D:\Projects\C#\GoogleCodeJam\2016\Round1B\CodeJam\CodeJam\A-large.out";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for (int i = 1; i <= testCases; i++)
            {
                var testCase = ProblemA.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class ProblemA
    {
        public string PhoneNumber { get; set; }
        
        public static ProblemA ParseCase(StreamReader sr)
        {
            var phonenumber = sr.ReadLine();
            
            return new ProblemA { PhoneNumber = phonenumber };
        }

        public String SolveCase()
        {
            Dictionary<char, int> lettercount = new Dictionary<char, int>();
            var len = PhoneNumber.Length;
            foreach(char c in PhoneNumber.ToList())
            {
                if (!lettercount.ContainsKey(c))
                    lettercount[c] = 0;
                lettercount[c]++;
            }


            /*
           0 = Z
           2 = W
           6 = X
           8 = G
           3 = T
           4 = U
           5 = F
           7 = V
           1 = O
           9 = N
        */

            var numbers = new List<int>();
            while(len != 0)
            {
                string number = "";
                if (lettercount.ContainsKey('Z'))
                {
                    numbers.Add(0);
                    number = "ZERO";
                }
                else if (lettercount.ContainsKey('W'))
                {
                    numbers.Add(2);
                    number = "TWO";
                }
                else if (lettercount.ContainsKey('X'))
                {
                    numbers.Add(6);
                    number = "SIX";
                }
                else if (lettercount.ContainsKey('G'))
                {
                    numbers.Add(8);
                    number = "EIGHT";
                }
                else if (lettercount.ContainsKey('T'))
                {
                    numbers.Add(3);
                    number = "THREE";
                }
                else if (lettercount.ContainsKey('U'))
                {
                    numbers.Add(4);
                    number = "FOUR";
                }
                else if (lettercount.ContainsKey('F'))
                {
                    numbers.Add(5);
                    number = "FIVE";
                }
                else if (lettercount.ContainsKey('V'))
                {
                    numbers.Add(7);
                    number = "SEVEN";
                }
                else if (lettercount.ContainsKey('O'))
                {
                    numbers.Add(1);
                    number = "ONE";
                }
                else if (lettercount.ContainsKey('N'))
                {
                    numbers.Add(9);
                    number = "NINE";
                }

                foreach (var l in number.ToList())
                {
                    lettercount[l]--;
                    if (lettercount[l] == 0)
                        lettercount.Remove(l);
                    len--;
                }
            }
            return String.Join("", numbers.OrderBy(i => i).Select(i => i.ToString()).ToList());
        }
    }
}
