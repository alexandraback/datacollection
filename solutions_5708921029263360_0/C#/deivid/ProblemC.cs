using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    public class ProblemC
    {
        StreamReader _reader;
        StreamWriter _writer;

        public static void Main()
        {
            var sw = Stopwatch.StartNew();
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            var problem = new ProblemC(@"..\..\_data\C-small-attempt0.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }

        public ProblemC(string fileName)
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
            var info = ReadIntIEnumerable().ToList();
            int J = info[0];
            int P = info[1];
            int S = info[2];
            int K = info[3];
            var JP = new Dictionary<Tuple<int, int>, int>();
            var JS = new Dictionary<Tuple<int, int>, int>();
            var PS = new Dictionary<Tuple<int, int>, int>();

            int y = 0;
            var result = new StringBuilder();
            for (int j = 0; j < J; j++)
            {
                for (int p = 0; p < P; p++)
                {
                    for (int s = 0; s < S; s++)
                    {
                        if (ValidCombination(j, p, s, K, JP,JS,PS))
                        {
                            result.AppendLine();
                            result.Append($"{j + 1} {p + 1} {s + 1}");
                            y++;
                        }
                    }
                }
            }

            return $"{y}{result.ToString()}";
        }

        private bool ValidCombination(int j, int p, int s, int K, Dictionary<Tuple<int, int>, int> JP, Dictionary<Tuple<int, int>, int> JS, Dictionary<Tuple<int, int>, int> PS)
        {
            var keyJP = new Tuple<int, int>(j, p);
            if (!JP.ContainsKey(keyJP))
                JP.Add(keyJP, 0);
            if (JP[keyJP] == K)
                return false;

            var keyJS = new Tuple<int, int>(j, s);
            if (!JS.ContainsKey(keyJS))
                JS.Add(keyJS, 0);
            if (JS[keyJS] == K)
                return false;

            var keyPS = new Tuple<int, int>(p, s);
            if (!PS.ContainsKey(keyPS))
                PS.Add(keyPS, 0);
            if (PS[keyPS] == K)
                return false;

            JP[keyJP]++;
            JS[keyJS]++;
            PS[keyPS]++;
            return true;
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
