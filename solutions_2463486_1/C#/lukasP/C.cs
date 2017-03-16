using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    private static StreamReader reader;
    private static List<long> fairSquare;

    static int Count(long a)
    {
        int res = fairSquare.BinarySearch(a + 1);
        if (res < 0) return ~res;
        return res;
    }

    static bool CheckPalindrome(string s)
    {
        return Enumerable.Range(0, s.Length / 2).All(i => s[i] == s[s.Length - i - 1]);
    }

    static void Initialize()
    {
        fairSquare = new List<long>();

        long m4 = Enumerable.Repeat(10, 4).Aggregate(1L, (long res, int x) => res * x);
        long m7 = Enumerable.Repeat(10, 7).Aggregate(1L, (long res, int x) => res * x);
        for (long i = 1; i <= m4; i++)
        {
            string s = Convert.ToString(i);
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            string rs = new string(charArray);

            for (int k = 0; k < 2; k++)
            {
                string t = s + rs.Substring(k);
                long x = long.Parse(t);
                if (x <= m7 && CheckPalindrome( Convert.ToString(x * x) ))
                    fairSquare.Add(x * x);
            }
        }

        fairSquare.Sort();
    }

    static int Solve()
    {
        string[] ss = reader.ReadLine().Split();
        long a = long.Parse(ss[0]), b = long.Parse(ss[1]);

        return Count(b) - Count(a - 1);
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        reader = new StreamReader(bs);

        Initialize();

        foreach (int i in Enumerable.Range(0, int.Parse(reader.ReadLine())))
            Console.WriteLine("Case #{0}: {1}", i + 1, Solve());
    }
}
