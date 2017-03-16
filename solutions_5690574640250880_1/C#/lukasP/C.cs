using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;

class Problem
{
    private static StreamReader reader;

    static string Solve()
    {
        string[] ss = reader.ReadLine().Split();
        int r = int.Parse(ss[0]);
        int c = int.Parse(ss[1]);
        int m = int.Parse(ss[2]);

        bool flipped = false;
        if (r > c)
        {
            flipped = true;
            int t = c;
            c = r;
            r = t;
        }

        int rest = r * c - m;
        if (rest > 1 && ((rest < 4 && r > 1) || (rest % 2 == 1 && r == 2) || (rest == 5 && r > 1)))
            return "Impossible";

        int dr = r;
        if (r * r >= rest)
            dr = (int)Math.Ceiling(Math.Sqrt(rest));
        int dc = rest / dr, rem = rest % dr;

        char[, ] res = new char[r, c];
        foreach (int i in Enumerable.Range(0, r))
            foreach (int j in Enumerable.Range(0, c))
            {
                if ((i < dr && j < dc) || (i < rem && j == dc))
                    res[i, j] = '.';
                else
                    res[i, j] = '*';
            }

        if (rest > 1 && rem == 1)
        {
            if (dc == 2)
                return "Impossible";
            res[1, dc] = '.';
            res[dr - 1, dc - 1] = '*';
        }

        if (flipped)
        {
            char[,] tmp = new char[c, r];
            foreach (int i in Enumerable.Range(0, r))
                foreach (int j in Enumerable.Range(0, c))
                    tmp[j, i] = res[i, j];
            int t = c;
            c = r;
            r = t;
            res = tmp;
        }
        res[0, 0] = 'c';

        var rows = Enumerable.Range(0, r)
            .Select(x => new string(Enumerable.Range(0, c).Select(y => res[x, y]).ToArray()));
        return string.Join("\n", rows);
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        reader = new StreamReader(bs);

        foreach (int i in Enumerable.Range(1, int.Parse(reader.ReadLine())))
            Console.WriteLine("Case #{0}:\n{1}", i, Solve());
    }
}
