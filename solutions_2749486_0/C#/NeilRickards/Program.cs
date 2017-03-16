using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace CodeJam2
{
    public class CodeJamProblem : IDisposable
    {
        private StreamReader _reader;
        private StreamWriter _writer;

        private bool disposed = false;

        public CodeJamProblem(string path)
        {
            _reader = new StreamReader(path);
            _writer = new StreamWriter(Path.ChangeExtension(path, ".out"));

            CaseNumber = 1;
            StartTime = Environment.TickCount;
        }

        public int StartTime { get; private set; }
        public int ElapsedTime { get; private set; }
        public int CaseNumber { get; private set; }

        public bool InputAvailable
        {
            get { return _reader.Peek() != -1; }
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected void Dispose(bool disposing)
        {
            if (disposed) return;
            if (disposing)
            {
                this.ElapsedTime = Environment.TickCount - this.StartTime;

                _reader.Dispose();
                _writer.Dispose();

                Console.WriteLine("Elapsed time: {0:#,#0}ms", this.ElapsedTime);
                Console.Beep();
                Console.ReadKey(true);
            }

            disposed = true;
        }

        public void OutputCase(params object[] values)
        {
            var parts = new string[values.Length];
            for (int i = 0; i < parts.Length; i++)
                parts[i] = values[i].ToString();
            OutputCase(string.Join(" ", parts));
        }

        public void OutputCase()
        {
            OutputCase((string)null);
        }

        public void OutputCase(string value)
        {
            WriteLine("Case #{0:#0}: {1}", CaseNumber, value);
            ++CaseNumber;
        }

        public void WriteArrays<T>(T[][] entries)
        {
            for (int i = 0; i < entries.Length; i++)
                WriteArray(entries[i]);
        }

        public void WriteArray<T>(T[] values)
        {
            var parts = new string[values.Length];
            for (int i = 0; i < parts.Length; i++)
                parts[i] = values[i].ToString();
            WriteLine(string.Join(" ", parts));
        }

        public void WriteLines(string[] lines)
        {
            for (int i = 0; i < lines.Length; i++)
                WriteLine(lines[i]);
        }

        public void WriteLine(string format, params object[] arg)
        {
            Console.WriteLine(format, arg);
            this._writer.WriteLine(format, arg);
        }

        public void WriteLine(string line)
        {
            Console.WriteLine(line);
            this._writer.WriteLine(line);
        }

        public T[][] ReadArrays<T>(int count, Func<string, T> converter)
        {
            var entries = new T[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadArray(converter);
            return entries;
        }

        public T[] ReadArray<T>(Func<string, T> converter)
        {
            var parts = ReadParts();
            var values = new T[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = converter(parts[i]);
            return values;
        }

        public short[][] ReadInt16Arrays(int count)
        {
            var entries = new short[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt16Array();
            return entries;
        }

        public short[] ReadInt16Array()
        {
            var parts = ReadParts();
            var values = new short[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = short.Parse(parts[i]);
            return values;
        }

        public int[][] ReadInt32Arrays(int count)
        {
            var entries = new int[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt32Array();
            return entries;
        }

        public int[] ReadInt32Array()
        {
            var parts = ReadParts();
            var values = new int[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = int.Parse(parts[i]);
            return values;
        }

        public long[][] ReadInt64Arrays(int count)
        {
            var entries = new long[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadInt64Array();
            return entries;
        }

        public long[] ReadInt64Array()
        {
            var parts = ReadParts();
            var values = new long[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = long.Parse(parts[i]);
            return values;
        }

        public double[][] ReadDoubleArrays(int count)
        {
            var entries = new double[count][];
            for (int i = 0; i < entries.Length; i++)
                entries[i] = ReadDoubleArray();
            return entries;
        }

        public double[] ReadDoubleArray()
        {
            var parts = ReadParts();
            var values = new double[parts.Length];
            for (int i = 0; i < values.Length; i++)
                values[i] = double.Parse(parts[i]);
            return values;
        }

        public string[] ReadParts()
        {
            return ReadLine().Split(' ');
        }

        public string[] ReadLines(int count)
        {
            var lines = new string[count];
            for (int i = 0; i < lines.Length; i++)
                lines[i] = ReadLine();
            return lines;
        }

        public short ReadLineInt16()
        {
            return short.Parse(ReadLine());
        }

        public int ReadLineInt32()
        {
            return int.Parse(ReadLine());
        }

        public long ReadLineInt64()
        {
            return long.Parse(ReadLine());
        }

        public double ReadLineDouble()
        {
            return double.Parse(ReadLine());
        }

        public string ReadLine()
        {
            return _reader.ReadLine();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            using (var prob = new CodeJamProblem(@"C:\Users\Neil\Downloads\B-small-attempt2.in"))
            {
                int caseCount = prob.ReadLineInt32();
                for (int t = 0; t < caseCount; ++t)
                {
                    prob.OutputCase(Pogo(prob));
                }
            }
        }

        static char[] VOWELS = new[] { 'a', 'e', 'i', 'o', 'u' };
        static int Consonants(CodeJamProblem prob)
        {
            string[] parts = prob.ReadParts();
            string word = parts[0];
            int n = int.Parse(parts[1]);

            int count = 0;
            for (int i = 0; i <= word.Length - n; ++i)
                for (int j = i+n; j <= word.Length; ++j)
                    if (ConsecutiveConsanants(word.Substring(i, j-i)).Max() >= n)
                        ++ count;

            return count;
        }
        static IEnumerable<int> ConsecutiveConsanants(IEnumerable<char> input)
        {
            int i = 0;
            foreach (char c in input)
            {
                if (VOWELS.Contains(c))
                {
                    yield return i;
                    i = 0;
                }
                else ++i;
            }
            yield return i;
        }

        struct State
        {
            public int X, Y, I;
            public string Path;
            public State(int x, int y, int i, string path) { X=x; Y=y; I=i; Path=path; }
        }
        static string Pogo(CodeJamProblem prob)
        {
            int[] dest = prob.ReadInt32Array();
            StringBuilder s = new StringBuilder();
            if (dest[0] > 0) for (int i = 0; i < dest[0]; ++i) s.Append("WE");
            if (dest[0] < 0) for (int i = 0; i > dest[0]; --i) s.Append("EW");
            if (dest[1] > 0) for (int i = 0; i < dest[1]; ++i) s.Append("SN");
            if (dest[1] < 0) for (int i = 0; i > dest[1]; --i) s.Append("SN");
            return s.ToString();

/*
            Queue<State> q = new Queue<State>();
            q.Enqueue(new State(0, 0, 1, ""));
            while (true)
            {
                var s = q.Dequeue();
                if (s.X == dest[0] && s.Y == dest[1]) return s.Path;
                q.Enqueue(new State(s.X, s.Y + s.I, s.I + 1, s.Path + "N"));
                q.Enqueue(new State(s.X + s.I, s.Y, s.I + 1, s.Path + "E"));
                q.Enqueue(new State(s.X, s.Y - s.I, s.I + 1, s.Path + "S"));
                q.Enqueue(new State(s.X - s.I, s.Y, s.I + 1, s.Path + "W"));
            }
 */ 
        }
    }
}
