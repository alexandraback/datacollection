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
        long[] K;
        string[] S;
        public void Solve()
        {
            var T = sc.Integer();
            Length = new int[T];
            K = new long[T];
            S = new string[T];
            for (int _ = 0; _ < T; _++)
            {
                Length[_] = sc.Integer();
                K[_] = sc.Long();
                S[_] = sc.Char(Length[_]).AsString();
            }
            for (int i = 0; i < T; i++)
            {
                F(i);
            }
            ans.Sort((l, r) => l.Key.CompareTo(r.Key));
            var yesno = new string[] { "YES", "NO" };
            foreach (var res in ans)
                IO.Printer.Out.WriteLine("Case #{0}: {1}", res.Key + 1, yesno[res.Value]);
        }
        List<KeyValuePair<int, int>> ans = new List<KeyValuePair<int, int>>(1000);
        public void F(int id)
        {
            var len = Length[id];
            var k = K[id];
            var s = S[id];
            var states = Enumerate(len, x => new State(s[x]));
            var table = Enumerate(len + 1, x => new State[len]);
            for (int i = 0; i < len; i++)
            {
                table[i][i] = states[i];
                for (int j = i + 1; j < len; j++)
                    table[i][j] = table[i][j - 1] * states[j];
            }
            table[len][len - 1] = new State(1, 1);
            var flag = new State[4];
            flag[0] = new State(1, 1);
            for (int i = 1; i < 4; i++)
                flag[i] = flag[i - 1] * table[0][len - 1];
            if (flag[k % 4].Value != -1)
            {
                ans.Add(new KeyValuePair<int, int>(id, 1));
                return;
            }
            for (int skip = 0; skip < 4; skip++)
            {
                if (skip >= k)
                    continue;
                for (int i = 0; i < len; i++)
                {
                    var p = table[0][i];
                    if ((flag[skip] * p).Value != 2)
                        continue;
                    for (int j = i + 1; j < len; j++)
                    {
                        var q = table[i + 1][j];
                        if (q.Value != 3)
                            continue;
                        ans.Add(new KeyValuePair<int, int>(id, 0));
                        return;
                    }
                    for (int skipskip = 0; skipskip < 4; skipskip++)
                    {
                        if (skip + 1 + skipskip >= k)
                            continue;
                        var r = table[i + 1][len - 1] * flag[skipskip];
                        for (int j = 0; j < len; j++)
                        {
                            if ((r * table[0][j]).Value != 3)
                                continue;
                            ans.Add(new KeyValuePair<int, int>(id, 0));
                            return;
                        }
                    }
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

