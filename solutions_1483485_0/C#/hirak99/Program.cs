using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace GCJ2012QA {
    class Program {
        string[] known = {"a zoo","y qee",
                         "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                         "our language is impossible to understand",
                         "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                         "there are twenty six factorial possibilities",
                         "de kr kd eoya kw aej tysr re ujdr lkgc jv",
                         "so it is okay if you want to just give up"};
        int[] mapping = new int[26];
        void decode() {
            for (int i = 0; i < mapping.Length; ++i) mapping[i] = -1;
            for (int j = 0; j < known.Length; j += 2) {
                string s = known[j], c = known[j + 1];
                for (int i = 0; i < s.Length; ++i) {
                    int ch1 = s[i]-'a', ch2=c[i]-'a';
                    if (ch1 < 26 && ch1>=0) mapping[ch1] = ch2;
                }
            }
            int s1=0,s2=0,unknown=0,unindex=-1;
            for (int i = 0; i < mapping.Length; ++i) {
                s1 += i;
                if (mapping[i] != -1) s2 += mapping[i];
                else {unknown++; unindex=i;}
            }
            Debug.Assert(unknown <= 1);
            if (unknown == 1) mapping[unindex] = s1 - s2;
            /*
            for (int i = 0; i < 26; ++i)
                Console.WriteLine("{0}: {1}", i + 1, ((char)(mapping[i] + 'a')).ToString());
            */
        }
        String convert(string input) {
            string output="";
            foreach (char c in input) {
                if (c >= 'a' && c <= 'z') output += ((char)(mapping[c - 'a'] + 'a')).ToString();
                else output += c.ToString();
            }
            return output;
        }
        Program() {
            decode();
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; ++i) {
                string line = Console.ReadLine();
                Console.WriteLine("Case #{0}: {1}", i + 1, convert(line));
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
