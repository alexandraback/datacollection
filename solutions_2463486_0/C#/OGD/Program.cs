using System;
using System.IO;

namespace goo2013 {
    class Program {
        static void Main(string[] args) {
            string path = @"C:\goo\C-small-attempt0.in";
            var reader = new StreamReader(path);
            var writer = new StreamWriter(@"C:\goo\out.txt");
            int N = int.Parse(reader.ReadLine());
            string s;
            int j = 0;
            while ((s = reader.ReadLine()) != null) {
                j++;
                long palindroms = 0;
                var interval = s.Split(' ');
                long start = long.Parse(interval[0]);
                long end = long.Parse(interval[1]);
                long k = (long)Math.Floor(Math.Sqrt(end)) + 1;
                for (long i = 1; i < k; ++i) {
                    long m = i*i;
                    if (IsPalindrom(i) && InInterval(m, start, end)) {
                        if (IsPalindrom(m)) {
                            palindroms++;
                            //writer.WriteLine(m);
                        }
                    }
                }
                writer.WriteLine("Case #"+ j + ": " + palindroms);
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
