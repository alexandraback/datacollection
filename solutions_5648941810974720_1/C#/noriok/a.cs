using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    static void Calc_1(char c, string s, int digit, int[] freq, int[] ans) {
        while (freq[c] > 0) {
            ans[digit]++;
            foreach (char c2 in s) {
                if (freq[c2] <= 0) throw new Exception();
                freq[c2]--;
            }
        }
    }

    static string Calc(string s) {
        int[] freq = new int[256];
        foreach (char c in s) {
            freq[c]++;
        }

        int[] ans = new int[10];

        Calc_1('Z', "ZERO", 0, freq, ans);
        Calc_1('W', "TWO", 2, freq, ans);
        Calc_1('U', "FOUR", 4, freq, ans);
        Calc_1('X', "SIX", 6, freq, ans);
        Calc_1('G', "EIGHT", 8, freq, ans);
        Calc_1('O', "ONE", 1, freq, ans);
        Calc_1('S', "SEVEN", 7, freq, ans);
        Calc_1('H', "THREE", 3, freq, ans);
        Calc_1('V', "FIVE", 5, freq, ans);
        Calc_1('N', "NINE", 9, freq, ans);

        var cs = new List<string>();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < ans[i]; j++) {
                cs.Add(i.ToString());
            }
        }
        return string.Join("", cs);
    }

    static void Main() {
        int t = ReadInt();
        for (int i = 0; i < t; i++) {
            var s = ReadLine();
            Console.WriteLine("Case #{0}: {1}", i+1, Calc(s));
        }
    }
}
