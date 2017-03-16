using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class Solver {
    static bool Solve(int X, int R, int C) {
        if (R < 0 || C < 0) return false;
        if (R == 0 && C == 0) return true;
        if ((R * C) % X != 0) {
            return false;
        }

        //  *
        // ***
        //  *
        if (X >= 5) return false;

        if (X == 1) return true;
        if (X == 2) return true;
        if (X == 3) {
            if (R % 3 == 0 && Solve(X, R, C - 2)) return true;
            if (R % 2 == 0 && Solve(X, R, C - 3)) return true;
            if (C % 3 == 0 && Solve(X, R - 2, C)) return true;
            if (C % 2 == 0 && Solve(X, R - 3, C)) return true;
            if (R == 3 && C == 3) return true;
        }
        if (X == 4) {
            if (R == 4 && C == 4) return true;
            if (R == 4 && C == 3) return true;
            if (R == 3 && C == 4) return true;
        }

        return false;
    }

    static void Main(string[] args) {
        /*
        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= 4; j++) {
                    if (Solve(k, i, j)) Console.WriteLine(" " + k + " " + i + " " + j);
                }
            }
        }*/

        var scanner = new Scanner();
        var t = scanner.NextInt();
        int caseNo = 1;
        while (t-- > 0) {
            var X = scanner.NextInt();
            var R = scanner.NextInt();
            var C = scanner.NextInt();

            bool win = Solve(X, R, C);

            Console.WriteLine("Case #{0}: {1}", caseNo++, win ? "GABRIEL" : "RICHARD");
        }
    }
}

public class Scanner {
    private TextReader Reader;
    private Queue<String> TokenQueue = new Queue<string>();
    private CultureInfo ci = new CultureInfo("en-US");

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

