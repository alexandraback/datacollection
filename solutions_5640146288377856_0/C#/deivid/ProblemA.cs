using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

            var problem = new ProblemA(@"..\..\_data\A-small-attempt0.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }

        public ProblemA(string fileName)
        {
            _reader = System.IO.File.OpenText(fileName);
            _writer = System.IO.File.CreateText(Path.Combine(Path.GetDirectoryName(fileName), Path.GetFileNameWithoutExtension(fileName) + ".out"));
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
            int R = info[0];
            int C = info[1];
            int W = info[2];

            int score = (R - 1) * (C / W);
            while (C >= W)
            {
                C = C - W;
                score++;
            }
            score = score + (W - 1);
            if (C > 0) score++;

            return score.ToString();
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

        private int ReadInt()
        {
            return int.Parse(_reader.ReadLine());
        }

        private string ReadString()
        {
            return _reader.ReadLine();
        }

        private string[] ReadStringArray()
        {
            return ReadString().Split();
        }

        private IEnumerable<int> ReadIntIEnumerable()
        {
            return ReadStringArray().Select(s => int.Parse(s));
        }
    }
}
