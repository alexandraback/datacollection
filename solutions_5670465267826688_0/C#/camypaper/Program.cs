using System;
using System.Linq;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using System.Threading.Tasks;
namespace Program
{
    public class Solver
    {
        int[] Length;
        int[] K;
        string[] S;
        public void Solve()
        {
            var T = sc.Integer();
            Length = new int[T];
            K = new int[T];
            S = new string[T];
            for (int _ = 0; _ < T; _++)
            {
                Length[_] = sc.Integer();
                K[_] = sc.Integer();
                S[_] = sc.Char(Length[_]).AsString();
            }
            Parallel.For(0, T, F);
            ans.Sort((l, r) => l.Key.CompareTo(r.Key));
            var yesno = new string[] { "YES", "NO" };
            foreach (var res in ans)
                IO.Printer.Out.WriteLine("Case #{0}: {1}", res.Key + 1, yesno[res.Value]);
        }
        List<KeyValuePair<int, int>> ans = new List<KeyValuePair<int,int>>();
        public void F(int id)
        {
            var len = Length[id];
            var k = K[id];
            var s = S[id];
            var sb = new StringBuilder();
            for (int i = 0; i < k; i++)
                sb.Append(s);
            var str = sb.ToString();
            var states = Enumerate(len * k, x => new State(str[x]));
            var tree = new SegmentTree(len * k, states);
            for (int i = 0; i < len * k; i++)
            {
                var p = tree.Query(0, i + 1);
                if (p.Value != 2)
                    continue;
                for (int j = i + 1; j < len * k; j++)
                {
                    var q = tree.Query(i + 1, j + 1);
                    if (q.Value != 3)
                        continue;
                    var r = tree.Query(j + 1, len * k);
                    if (r.Value != 4)
                        continue;
                    ans.Add(new KeyValuePair<int, int>(id, 0));
                    return;
                }
            }
            ans.Add(new KeyValuePair<int, int>(id, 1));
        }
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());
        static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }
    }
}

#region Ex
namespace Program.IO
{
    using System.IO;
    using System.Text;
    using System.Globalization;
    public class Printer : StreamWriter
    {
        static Printer() { Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false }; }
        public static Printer Out { get; set; }
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(System.IO.Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
        public Printer(System.IO.Stream stream, Encoding encoding) : base(stream, encoding) { }
        public void Write<T>(string format, IEnumerable<T> source) { base.Write(format, source.OfType<object>().ToArray()); }
        public void WriteLine<T>(string format, IEnumerable<T> source) { base.WriteLine(format, source.OfType<object>().ToArray()); }
    }
    public class StreamScanner
    {
        public StreamScanner(Stream stream) { str = stream; }
        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }
        private byte read()
        {
            if (isEof) return 0;
            if (ptr >= len) { ptr = 0; if ((len = str.Read(buf, 0, 1024)) <= 0) { isEof = true; return 0; } }
            return buf[ptr++];
        }
        public char Char() { byte b = 0; do b = read(); while (b < 33 || 126 < b); return (char)b; }

        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                sb.Append(b);
            return sb.ToString();
        }
        public long Long()
        {
            if (isEof) return long.MinValue;
            long ret = 0; byte b = 0; var ng = false;
            do b = read();
            while (b != '-' && (b < '0' || '9' < b));
            if (b == '-') { ng = true; b = read(); }
            for (; true; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                else ret = ret * 10 + b - '0';
            }
        }
        public int Integer() { return (isEof) ? int.MinValue : (int)Long(); }
        public double Double() { return double.Parse(Scan(), CultureInfo.InvariantCulture); }
        private T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n) { return enumerate(n, Char); }
        public string[] Scan(int n) { return enumerate(n, Scan); }
        public double[] Double(int n) { return enumerate(n, Double); }
        public int[] Integer(int n) { return enumerate(n, Integer); }
        public long[] Long(int n) { return enumerate(n, Long); }
    }
}
static class Ex
{
    static public string AsString(this IEnumerable<char> ie) { return new string(System.Linq.Enumerable.ToArray(ie)); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") { return string.Join(st, ie); }
    static public void Main()
    {
        var solver = new Program.Solver();
        solver.Solve();
        Program.IO.Printer.Out.Flush();
    }
}
#endregion
public struct State
{
    int sign;
    int value;
    public int Value { get { return sign * value; } }
    public State(int s, int v)
    {
        sign = s;
        value = v;
    }
    public State(char c)
    {
        sign = 1;
        if (c == 'i')
            value = 2;
        else if (c == 'j')
            value = 3;
        else if (c == 'k') value = 4;
        else throw new Exception();
    }
    public static State operator *(State l, State r)
    {
        switch (l.value)
        {
            case 1:
                return new State(l.sign * r.sign, r.value);
            case 2:
                switch (r.value)
                {
                    case 1:
                        return new State(l.sign * r.sign, l.value);
                    case 2:
                        return new State(l.sign * r.sign * -1, 1);
                    case 3:
                        return new State(l.sign * r.sign, 4);
                    case 4:
                        return new State(l.sign * r.sign * -1, 3);
                    default: throw new Exception();
                }
            case 3:
                switch (r.value)
                {
                    case 1:
                        return new State(l.sign * r.sign, l.value);
                    case 2:
                        return new State(l.sign * r.sign * -1, 4);
                    case 3:
                        return new State(l.sign * r.sign * -1, 1);
                    case 4:
                        return new State(l.sign * r.sign, 2);
                    default: throw new Exception();
                }
            case 4:
                switch (r.value)
                {
                    case 1:
                        return new State(l.sign * r.sign, l.value);
                    case 2:
                        return new State(l.sign * r.sign, 3);
                    case 3:
                        return new State(l.sign * r.sign * -1, 2);
                    case 4:
                        return new State(l.sign * r.sign * -1, 1);
                    default: throw new Exception();
                }
            default: throw new Exception();
        }

    }
}

#region SegTree
[System.Diagnostics.DebuggerDisplay("Data={ToString()}")]
public class SegmentTree
{
    int n;
    State[] data;
    public SegmentTree(int size, State[] a)
    {
        n = 1;
        while (n < size)
            n <<= 1;
        data = new State[n << 1];
        for (int i = 0; i < size; i++)
            data[n + i] = a[i];
        for (int i = n + size; i < data.Length; i++)
            data[i] = new State(1, 1);
        for (int i = n - 1; i > 0; i--)
        {
            data[i] = data[i << 1] * data[(i << 1) + 1];
        }
    }
    public State Query(int a, int b) { return Query(a, b, 1, 0, n); }
    private State Query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return new State(1, 1);
        if (a <= l && r <= b)
            return data[k];
        else
        {
            var vl = Query(a, b, k << 1, l, (l + r) >> 1);
            var vr = Query(a, b, (k << 1) + 1, (l + r) >> 1, r);
            return vl * vr;
        }
    }

}
#endregion
