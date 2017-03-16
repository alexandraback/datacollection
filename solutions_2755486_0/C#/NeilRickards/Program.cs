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
            using (var prob = new CodeJamProblem(@"C:\Users\Neil\Downloads\C-small-attempt0.in"))
            {
                int caseCount = prob.ReadLineInt32();
                for (int t = 0; t < caseCount; ++t)
                {
                    prob.OutputCase(CalcWall(prob));
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

        class Tribe { public int D, N, W, E, S, Dd, Dp, Ds; }
        class Wall { public int W, E, S; }
        static int CalcWall(CodeJamProblem prob)
        {
            int n = prob.ReadLineInt32();
            var tribes = new List<Tribe>(n);
            for (int i = 0; i < n; ++i)
            {
                var p = prob.ReadInt32Array();
                tribes.Add(new Tribe { D = p[0], N = p[1], W = p[2], E = p[3], S = p[4], Dd = p[5], Dp = p[6], Ds = p[7] });
            }
            var walls = new List<Wall>();

            int count = 0;
            while (tribes.Any())
            {
                int day = tribes.Min(t => t.D);
                var newWalls = walls.Select(w => new Wall { W = w.W, E = w.E, S = w.S }).ToList();
                foreach (var t in tribes.Where(t => t.D == day).ToList())
                {
                    if (Breach(walls, t)) ++count;
                    newWalls = AddWalls(newWalls, t).ToList();
                    
                    --t.N;
                    if (t.N == 0) tribes.Remove(t);
                    t.D += t.Dd;
                    t.W += t.Dp;
                    t.E += t.Dp;
                    t.S += t.Ds;
                }
                walls = newWalls;
            }
            return count;
        }

        static bool Breach(List<Wall> walls, Tribe t)
        {
            var p = t.W;
            foreach (var w in walls)
            {
                if (w.E <= p) continue;
                if (w.W > p) return true;
                if (w.S < t.S) return true;
                p = w.E;
                if (p >= t.E) return false;
            }
            return true;
        }

        static IEnumerable<Wall> AddWalls(List<Wall> walls, Tribe t)
        {
            int pw = t.W, pe = t.E;
            foreach (var w in walls)
            {
                if (w.E <= pw) { yield return w; continue; }
                if (w.W >= pe) { yield return w; continue; }

                if (w.S >= t.S)
                {
                    if (w.W > pw)
                    {
                        if (w.W > pe)
                            yield return new Wall { W = pw, E = pe, S = t.S };
                        else
                            yield return new Wall { W = pw, E = w.W, S = t.S };
                    }
                    yield return w; pw = w.E; continue;
                }

                if (w.W < pw)
                {
                    yield return new Wall { W = w.W, E = pw, S = w.S };
                    if (w.E > pe)
                    {
                        yield return new Wall { W = pw, E = pe, S = t.S };
                        yield return new Wall { W = pe, E = w.E, S = w.S };
                    }
                    else
                    {
                        yield return new Wall { W = pw, E = w.E, S = t.S };
                    }
                    pw = w.E;
                    continue;
                }

                yield return new Wall { W = pw, E = pe, S = t.S };
                yield return new Wall { W = pe, E = w.E, S = w.S };
                pw = w.E;
            }

            if (pw < pe) yield return new Wall { W = pw, E = pe, S = t.S };
        }
    }
}
