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
    public class ProblemC
    {
        StreamReader _reader;
        StreamWriter _writer;

        public static void Main()
        {
            var sw = Stopwatch.StartNew();
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            var problem = new ProblemC(@"..\..\_data\C-small-attempt1.in");
            problem.Solve();

            sw.Stop();
            Console.WriteLine("Done in {0}", sw.Elapsed);
            Console.ReadKey();
        }

        public ProblemC(string fileName)
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
            int C = info[0];
            int D = info[1];
            int V = info[2];
            var denominations = ReadIntIEnumerable().ToList();

            int newDenominations = 0;
            while (true)
            {
                int res = IsPossible(V, denominations);
                if (res == 0)
                    break;
                denominations.Add(res);

                denominations = denominations.OrderBy(i => i).ToList();
                newDenominations++;
            }

            return newDenominations.ToString();
        }

        private int IsPossible(int V, List<int> denominations)
        {
            for (int i = 1; i <= V; i++)
            {
                if (!IsPossibleValue(i, denominations.Where(d => d <= i).ToList()))
                    return i;
            }
            return 0;
        }

        private bool IsPossibleValue(int n, List<int> denominations)
        {
            if (denominations.Contains(n))
                return true;
            if (!denominations.Any())
                return false;
            var first = denominations[0];
            denominations = denominations.Skip(1).ToList();
            return IsPossibleValue(n - first, denominations) || IsPossibleValue(n, denominations);
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
