using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class B
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);

            string[] ps = Console.ReadLine().Split();

            int bestC = -1;
            int bestJ = -1;
            int bestD = int.MaxValue;
            foreach(int c in allNums(ps[0], 0))
            {
                foreach(int j in allNums(ps[1], 0))
                {
                    int diff = Math.Abs(c - j);
                    if(diff < bestD || (diff == bestD && (c < bestC || (c == bestC && j < bestJ))))
                    {
                        bestD = diff;
                        bestJ = j;
                        bestC = c;
                    }
                }
            }
            Console.WriteLine("Case #" + CASE + ": " + formatL(bestC, ps[0].Length) + " " + formatL(bestJ, ps[1].Length));
        }
    }

    public static string formatL(int x, int len)
    {
        string s = x.ToString();
        while (s.Length < len)
            s = "0" + s;
        return s;
    }

    public static IEnumerable<int> allNums(string s, int i)
    {
        if (i == s.Length)
        {
            yield return 0;
            yield break;
        }

        foreach (int num in allNums(s, i + 1))
        {
            if (s[s.Length - i - 1] == '?')
            {
                for (int x = 0; x < 10; x++)
                {
                    yield return num * 10 + x;
                }
            } else
            {
                yield return num * 10 + s[s.Length - i - 1] - '0';
            }
        }
    }
}
