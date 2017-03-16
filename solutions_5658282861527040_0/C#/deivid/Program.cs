using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = Stopwatch.StartNew();

            var problem = new ProblemA(@"..\..\_data\B-small-attempt0.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }
    }

    public class ProblemA
    {
        StreamReader _reader;
        StreamWriter _writer;

        public ProblemA(string fileName)
        {
            _reader = System.IO.File.OpenText(fileName);
            _writer = System.IO.File.CreateText(Path.Combine(Path.GetDirectoryName(fileName), Path.GetFileNameWithoutExtension(fileName) + ".out"));
        }


        public void Solve()
        {
            int N = ReadInt();
            for (int testCase = 1; testCase <= N; testCase++)
            {
                WriteCaseResult(testCase, SolveCase());
            }
            ProduceOutput();
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

        private string SolveCase()
        {
            var info = ReadIntIEnumerable().ToArray();
            int A = info[0];
            int B = info[1];
            int K = info[2];
            int win = 0;
            for (int i = 0; i < A; i++)
            {
                for (int j = 0; j < B; j++)
                {
                    if ((i & j) < K)
                        win++;
                }
            }
            return win.ToString();
        }
    }
}
