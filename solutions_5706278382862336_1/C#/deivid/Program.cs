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

            var problem = new Problem(@"..\..\_data\A-large.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }
    }

    public class Problem
    {
        StreamReader _reader;
        StreamWriter _writer;

        public Problem(string fileName)
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
            var info = ReadString().Split('/');
            long P = long.Parse(info[0]);
            long Q = long.Parse(info[1]);

            if (Q % 2 != 0)
                return "impossible";

            int generations = -1;
            int totalGenerations = 0;
            while (P != Q && totalGenerations <= 40)
            {
                totalGenerations++;
                P = P * 2;
                if (P >= Q && generations == -1)
                    generations = totalGenerations;
                if (P > Q)
                    P = P - Q;
            }
            if (totalGenerations > 40 || generations == -1)
                return "impossible";
            else
                return generations.ToString();
        }

        private int Solve(int P, int Q)
        {
            int generations = 0;
            while (P < Q && generations <= 40)
            {
                generations++;
                P = P * 2;
            }

            return generations;
        }
    }
}
