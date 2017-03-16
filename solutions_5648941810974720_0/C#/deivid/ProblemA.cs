using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    public class ProblemA
    {
        StreamReader _reader;
        StreamWriter _writer;

        public static void Main()
        {
            var sw = Stopwatch.StartNew();
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            var problem = new ProblemA(@"..\..\_data\A-small-attempt1.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }

        public ProblemA(string fileName)
        {
            _reader = File.OpenText(fileName);
            _writer = File.CreateText(Path.Combine(Path.GetDirectoryName(fileName), Path.GetFileNameWithoutExtension(fileName) + ".out"));
        }

        public void Solve()
        {
            int T = ReadInt();
            for (int testCase = 1; testCase <= T; testCase++)
            {
                WriteCaseResult(testCase, SolveCase());
            }
            ProduceOutput();
        }

        private string SolveCase()
        {
            string S = ReadString();
            var letters = S.ToCharArray().GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count());
            var numbers = new Dictionary<string, char>
            {
                { "ZERO", '0' },
                { "TWO", '2' },
                { "EIGHT", '8' },
                { "THREE", '3' },
                { "SIX", '6' },
                { "FOUR", '4' },
                { "FIVE", '5' },
                { "SEVEN", '7' },
                { "NINE", '9' },
                { "ONE", '1' }
            };
            var phoneNumber = new StringBuilder();
            foreach (var number in numbers)
            {
                int count = CountNumber(number.Key, letters);
                if (count > 0)
                    phoneNumber.Append(new string(number.Value, count));
            }
            return new string(phoneNumber.ToString().ToCharArray().OrderBy(c => c).ToArray());
        }

        private int CountNumber(string number, Dictionary<char, int> letters)
        {
            var chars = number.ToCharArray().GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count());
            int min = int.MaxValue;
            foreach (var c in chars)
            {
                if (letters.ContainsKey(c.Key))
                    min = Math.Min(min, letters[c.Key] / c.Value);
                else
                    return 0;
            }
            foreach (var c in chars)
            {
                letters[c.Key] = letters[c.Key] - (min * c.Value);
            }
            return min;
        }

        private void WriteCaseResult(int caseNumber, string result)
        {
            _writer.Write("Case #");
            _writer.Write(caseNumber);
            _writer.Write(": ");
            _writer.WriteLine(result);
        }

        private void ProduceOutput()
        {
            _writer.Flush();
            _writer.Close();
            _writer.Dispose();
            _reader.Close();
            _reader.Dispose();
        }

        private int ReadInt() => int.Parse(_reader.ReadLine());

        private string ReadString() => _reader.ReadLine();

        private string[] ReadStringArray() => ReadString().Split();

        private IEnumerable<int> ReadIntIEnumerable() => ReadStringArray().Select(s => int.Parse(s));
    }
}
