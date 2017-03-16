using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleJam2016.Practice._2016._1B
{
    class A_GettingTheDigits : IGoogleCodeJam
    {
        public override void Compute(StreamReader reader, StreamWriter writer)
        {
            int t = Convert.ToInt32(reader.ReadLine());

            for (int i = 1; i <= t; i++)
            {
                writer.WriteLine($"Case #{i}: {Solve(reader.ReadLine())}");
            }
        }

        public string Solve(string s)
        {
            var str = new StringBuilder(s);
            var result = new List<int>();

            while (str.Length > 0)
            {
                result.Add(Process(ref str));
            }

            return string.Join("", result.OrderBy(t => t));
        }

        public int Process(ref StringBuilder str)
        {
            if (str.Contains("Z"))
            {
                StringBuilderSearching.Replaceall(ref str, "ZERO");
                return 0;
            }
            else if (str.Contains("W"))
            {
                StringBuilderSearching.Replaceall(ref str, "TWO");
                return 2;
            }
            else if (str.Contains("U"))
            {
                StringBuilderSearching.Replaceall(ref str, "FOUR");
                return 4;
            }
            else if (str.Contains("X"))
            {
                StringBuilderSearching.Replaceall(ref str, "SIX");
                return 6;
            }
            else if (str.Contains("G"))
            {
                StringBuilderSearching.Replaceall(ref str, "EIGHT");
                return 8;
            }
            else if (str.Contains("R"))
            {
                StringBuilderSearching.Replaceall(ref str, "THREE");
                return 3;
            }
            else if (str.Contains("S"))
            {
                StringBuilderSearching.Replaceall(ref str, "SEVEN");
                return 7;
            }
            else if (str.Contains("V"))
            {
                StringBuilderSearching.Replaceall(ref str, "FIVE");
                return 5;
            }
            else if (str.Contains("O"))
            {
                StringBuilderSearching.Replaceall(ref str, "ONE");
                return 1;
            }
            else if (str.Contains("I"))
            {
                StringBuilderSearching.Replaceall(ref str, "NINE");
                return 9;
            }
            return -1;
        }
    }

    public static class StringBuilderSearching
    {
        public static void Replaceall(ref StringBuilder str, string x)
        {
            foreach (char c in x)
            {
                str = str.Replace(c.ToString(), string.Empty, str.IndexOf(c.ToString()), 1);
            }
        }
        public static bool Contains(this StringBuilder haystack, string needle)
        {
            return haystack.IndexOf(needle) != -1;
        }
        public static int IndexOf(this StringBuilder haystack, string needle)
        {
            if (haystack == null || needle == null)
                throw new ArgumentNullException();
            if (needle.Length == 0)
                return 0;//empty strings are everywhere!
            if (needle.Length == 1)//can't beat just spinning through for it
            {
                char c = needle[0];
                for (int idx = 0; idx != haystack.Length; ++idx)
                    if (haystack[idx] == c)
                        return idx;
                return -1;
            }
            int m = 0;
            int i = 0;
            int[] T = KMPTable(needle);
            while (m + i < haystack.Length)
            {
                if (needle[i] == haystack[m + i])
                {
                    if (i == needle.Length - 1)
                        return m == needle.Length ? -1 : m;//match -1 = failure to find conventional in .NET
                    ++i;
                }
                else
                {
                    m = m + i - T[i];
                    i = T[i] > -1 ? T[i] : 0;
                }
            }
            return -1;
        }
        private static int[] KMPTable(string sought)
        {
            int[] table = new int[sought.Length];
            int pos = 2;
            int cnd = 0;
            table[0] = -1;
            table[1] = 0;
            while (pos < table.Length)
                if (sought[pos - 1] == sought[cnd])
                    table[pos++] = ++cnd;
                else if (cnd > 0)
                    cnd = table[cnd];
                else
                    table[pos++] = 0;
            return table;
        }
    }
}
