using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    public class ProblemB
    {
        StreamReader _reader;
        StreamWriter _writer;

        public static void Main()
        {
            var sw = Stopwatch.StartNew();
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            var problem = new ProblemB(@"..\..\_data\B-small-attempt2.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }

        public ProblemB(string fileName)
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
            var info = ReadStringArray();
            List<int> C = info[0].ToCharArray().Select(c => c == '?' ? -1 : int.Parse(new string(c, 1))).ToList();
            List<int> J = info[1].ToCharArray().Select(c => c == '?' ? -1 : int.Parse(new string(c, 1))).ToList();

            int missingValues = C.Count(x => x == -1) + J.Count(x => x == -1);

            if (missingValues == 0)
                return string.Join(" ", info);

            string format = new string('0', missingValues);
            int diff = int.MaxValue;
            Tuple<int, int> bestResult = null;
            for (int i = 0; i < Math.Pow(10, missingValues); i++)
            {
                var numbers = i.ToString(format).ToCharArray().Select(c => int.Parse(new string(c, 1))).ToList();
                var result = GetNumbers(C, J, numbers);
                if (Math.Abs(result.Item1 - result.Item2) < diff)
                {
                    diff = Math.Abs(result.Item1 - result.Item2);
                    bestResult = result;
                }
            }
            format = new string('0', C.Count);
            return $"{bestResult.Item1.ToString(format)} {bestResult.Item2.ToString(format)}";
        }

        private Tuple<int, int> GetNumbers(List<int> C, List<int> J, List<int> numbers)
        {
            int n = 0;
            var c = new StringBuilder();
            for (int i = 0; i < C.Count; i++)
            {
                if (C[i] == -1)
                {
                    c.Append(numbers[n]);
                    n++;
                }
                else
                {
                    c.Append(C[i]);
                }
            }
            var j = new StringBuilder();
            for (int i = 0; i < J.Count; i++)
            {
                if (J[i] == -1)
                {
                    j.Append(numbers[n]);
                    n++;
                }
                else
                {
                    j.Append(J[i]);
                }
            }
            return new Tuple<int, int>(int.Parse(c.ToString()), int.Parse(j.ToString()));
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
