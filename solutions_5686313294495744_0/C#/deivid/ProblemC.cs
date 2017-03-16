using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;

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
            int N = ReadInt();
            var topics = new Dictionary<string, List<string>>();
            for (int i = 0; i < N; i++)
            {
                var topic = ReadString();
                topics.Add(topic, topic.Split().ToList());
            }

            int fakes = 0;
            foreach (var topic in topics)
            {
                var words = topic.Value.ToList();
                foreach (var topic2 in topics)
                {
                    if (topic.Key != topic2.Key)
                    {
                        foreach (var word in words)
                        {
                            if (topic2.Value.Contains(word))
                            {
                                words.Remove(word);
                                break;
                            }
                        }
                    }
                    if (words.Count == 0)
                    {
                        fakes++;
                        break;
                    }
                }
            }
            return fakes.ToString();
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
