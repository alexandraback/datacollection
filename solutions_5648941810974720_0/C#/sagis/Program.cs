using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJamRound1B
{
    class Program
    {
        static string INPUT = "input.txt";
        static string OUTPUT = "output.txt";

        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(INPUT))
            using (StreamWriter sw = new StreamWriter(OUTPUT))
            {
                int numberOfCases = int.Parse(sr.ReadLine());
                for (int i = 0; i < numberOfCases; i++)
                {
                    string line = sr.ReadLine();
                    List<int> digits = new List<int>();

                    line = RemoveNumber(line, digits, 0, "Z", "ZERO");
                    line = RemoveNumber(line, digits, 6, "X", "SIX");
                    line = RemoveNumber(line, digits, 2, "W", "TWO");
                    line = RemoveNumber(line, digits, 4, "U", "FOUR");
                    line = RemoveNumber(line, digits, 3, "R", "THREE");
                    line = RemoveNumber(line, digits, 5, "F", "FIVE");
                    line = RemoveNumber(line, digits, 8, "T", "EIGHT");
                    line = RemoveNumber(line, digits, 1, "O", "ONE");
                    line = RemoveNumber(line, digits, 7, "V", "SEVEN");
                    line = RemoveNumber(line, digits, 9, "I", "NINE");

                    if (line.Length > 0)
                        throw new Exception("Line length > 0");

                    StringBuilder sb = new StringBuilder();
                    digits.Sort();
                    foreach (int d in digits)
                        sb.Append(d);

                    sw.WriteLine("Case #{0}: {1}", i + 1, sb.ToString());
                }
            }
        }

        static string RemoveNumber(string s, List<int> digits, int digit, string idChar, string allChars)
        {
            while (s.IndexOf(idChar) >= 0)
            {
                digits.Add(digit);

                foreach (char ch in allChars.ToCharArray())
                {
                    int idx = s.IndexOf(ch);
                    s = s.Remove(idx, 1);
                }
            }

            return s;
        }
    }
}
