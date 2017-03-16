using System;
using System.Collections.Generic;
using System.IO;

namespace goo2013 {
    class Program {
        static void Main(string[] args) {
            string path = @"C:\goo\C-large-1.in";
            var reader = new StreamReader(path);
            var writer = new StreamWriter(@"C:\goo\out.txt");
            var p = new HashSet<long>();
            for (long i = 1; i <= 10000000; ++i) {
                long m = i * i;
                if (IsPalindrom(i)) {
                    if (IsPalindrom(m)) {
                        p.Add(m);
                        //writer.WriteLine(m);
                    }
                }
            }
            int N = int.Parse(reader.ReadLine());
            string s;
            int j = 0;
            while ((s = reader.ReadLine()) != null) {
                j++;
                long palindroms = 0;
                var interval = s.Split(' ');
                long start = long.Parse(interval[0]);
                long end = long.Parse(interval[1]);
                foreach (long l in p) {
                    if (InInterval(l, start, end)) {
                        palindroms++;
                    }
                }
                writer.WriteLine("Case #" + j + ": " + palindroms);
            }
            writer.Close();
        }

        private static bool IsPalindrom(long l) {
            string s = l.ToString();
            for (int i = 0; i < s.Length/2; ++i) {
                if (s[i] != s[s.Length - i - 1]) {
                    return false;
                }
            }
            return true;
        }

        private static bool InInterval(long x, long start, long end) {
            return x <= end && x >= start;

        }
    }
}
