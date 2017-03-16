using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    static bool IsMatch(int n, string s, string fmt) {

        var t = n.ToString(fmt);
        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '?') continue;
            if (s[i] != t[i]) return false;
        }
        return true;
    }

    static void Calc(string a, string b) {
        var fmt = string.Join("", Enumerable.Repeat("0", a.Length));
        int n = (int)Math.Pow(10, a.Length);

        int abs = (int)1e9;
        int ansA = 0, ansB = 0;
        for (int i = 0; i < n; i++) {
            if (!IsMatch(i, a, fmt)) continue;

            for (int j = 0; j < n; j++) {
                if (IsMatch(j, b, fmt)) {
                    if (abs > Math.Abs(i - j)) {
                        abs = Math.Abs(i - j);
                        ansA = i;
                        ansB = j;
                    }
                }
            }
        }
        Console.WriteLine("{0} {1}", ansA.ToString(fmt), ansB.ToString(fmt));
    }

    static void Main() {
        int t = ReadInt();
        for (int i = 0; i < t; i++) {
            var ss = ReadStrings();
            var a = ss[0];
            var b = ss[1];
//             Console.WriteLine("a:{0} b:{1}", a, b);
            Console.Write("Case #{0}: ", i+1);
            Calc(a, b);
        }
    }
}
