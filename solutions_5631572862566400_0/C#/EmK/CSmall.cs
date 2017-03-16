// csc /r:System.Numerics.dll /optimize /checked [This File]

using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

partial class Solver {
    static public int BitCount(ulong x) {
        int bitCount = 0;
        for (; x != 0; x = x & (x - 1)) bitCount++;
        return bitCount;
    }

    static public void Swap<T>(ref T a, ref T b) {
        T t = a;
        a = b;
        b = t;
    }

    static public bool NextPermutation<T>(T[] array) where T : IComparable<T> {
        int n = array.Length;
        for (int i = n - 2; i >= 0; i--) {
            if (array[i].CompareTo(array[i + 1]) < 0) {
                var index = Array.FindLastIndex(array, v => array[i].CompareTo(v) < 0);
                Swap(ref array[i], ref array[index]);
                Array.Reverse(array, i + 1, n - (i + 1));
                return true;
            }
        }
        Array.Reverse(array);
        return false;
    }


    public void Run() {
        var t = ni();
        int caseNo = 1;
        while (t-- > 0) {
            int ans = 2;

            var N = ni();
            var F = ni(N);
            F = F.Select(f => f - 1).ToArray();
            var invF = Enumerable.Range(0, N).Select(_ => new List<int>()).ToArray();
            for (int i = 0; i < N; i++) {
                invF[F[i]].Add(i);
            }

            for (int bit = 0; bit < (1 << N); bit++) {
                if (BitCount((ulong)bit) < ans) continue;
                List<int> cand = new List<int>();
                for (int i = 0; i < N; i++) {
                    if (((1 << i) & bit) != 0) cand.Add(i);
                }
                var perm = cand.ToArray();
                int minValue = perm[0];
                do {
                    if (perm[0] != minValue) continue;
                    bool isOk = true;
                    for (int i = 0; i < perm.Length; i++) {
                        int adj1 = (i + 1) % perm.Length;
                        int adj2 = (i + perm.Length - 1) % perm.Length;
                        if (F[perm[i]] != perm[adj1] && F[perm[i]] != perm[adj2]) {
                            isOk = false;
                            break;
                        }
                    }
                    if (isOk) {
                        ans = Math.Max(ans, perm.Length);
                        break;
                    }
                } while (NextPermutation(perm));
            }

            cout.WriteLine("Case #{0}: {1}", caseNo++, ans);
        }
    }
}

// PREWRITEN CODE BEGINS FROM HERE
partial class Solver : Scanner {
    public static void Main(string[] args) {
        new Solver(Console.In, Console.Out).Run();
    }

    TextReader cin;
    TextWriter cout;

    public Solver(TextReader reader, TextWriter writer)
        : base(reader) {
        this.cin = reader;
        this.cout = writer;
    }
    public Solver(string input, TextWriter writer)
        : this(new StringReader(input), writer) {
    }

    public int ni() { return NextInt(); }
    public int[] ni(int n) { return NextIntArray(n); }
    public long nl() { return NextLong(); }
    public long[] nl(int n) { return NextLongArray(n); }
    public double nd() { return NextDouble(); }
    public string ns() { return Next(); }
}

public class Scanner {
    private TextReader Reader;
    private Queue<String> TokenQueue = new Queue<string>();
    private CultureInfo ci = CultureInfo.InvariantCulture;

    public Scanner()
        : this(Console.In) {
    }

    public Scanner(TextReader reader) {
        this.Reader = reader;
    }

    public int NextInt() { return Int32.Parse(Next(), ci); }
    public long NextLong() { return Int64.Parse(Next(), ci); }
    public double NextDouble() { return double.Parse(Next(), ci); }
    public string[] NextArray(int size) {
        var array = new string[size];
        for (int i = 0; i < size; i++) array[i] = Next();
        return array;
    }
    public int[] NextIntArray(int size) {
        var array = new int[size];
        for (int i = 0; i < size; i++) array[i] = NextInt();
        return array;
    }

    public long[] NextLongArray(int size) {
        var array = new long[size];
        for (int i = 0; i < size; i++) array[i] = NextLong();
        return array;
    }

    public String Next() {
        if (TokenQueue.Count == 0) {
            if (!StockTokens()) throw new InvalidOperationException();
        }
        return TokenQueue.Dequeue();
    }

    public bool HasNext() {
        if (TokenQueue.Count > 0)
            return true;
        return StockTokens();
    }

    private bool StockTokens() {
        while (true) {
            var line = Reader.ReadLine();
            if (line == null) return false;
            var tokens = line.Trim().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            if (tokens.Length == 0) continue;
            foreach (var token in tokens)
                TokenQueue.Enqueue(token);
            return true;
        }
    }
}
