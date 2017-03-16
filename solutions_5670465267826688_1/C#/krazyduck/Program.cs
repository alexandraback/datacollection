using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        using (FileStream iStream = File.OpenRead(@"C:\Users\James\Downloads\input.in"))
        {
            using (FileStream oStream = File.OpenWrite(@"C:\Users\James\Documents\Visual Studio 2012\Projects\TopCoder\TopCoder\output.out"))
            {
                using (StreamReader sr = new StreamReader(iStream))
                {
                    int t = int.Parse(sr.ReadLine());
                    string o = "Case #{0}: ";

                    int g, ii, ig, ki, kg;
                    long gc;
                    string p;
                    long[] n;
                    string s;
                    
                    Extensions.lookup = new int[4][];
                    Extensions.lookup[0] = new int[4] { 1, 2, 3, 4 };
                    Extensions.lookup[1] = new int[4] { 2, -1, 4, -3 };
                    Extensions.lookup[2] = new int[4] { 3, -4, -1, 2 };
                    Extensions.lookup[3] = new int[4] { 4, 3, -2, -1 };

                    using (StreamWriter sw = new StreamWriter(oStream))
                    {
                        for (int i = 0; i < t; i++)
                        {
                            n = sr.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
                            s = sr.ReadLine();

                            p = "NO";
                            g = s.Aggregate(1, (x, y) => x.Calc(y));

                            if (FindI(s, g, n[1], out ii, out ig))
                            {
                                if (FindK(s, g, n[1], out ki, out kg))
                                {
                                    gc = n[1] - ig - kg;
                                    if (gc > 1 || (gc == 1 && ii < ki - 1))
                                    {
                                        if (IsJ(ii + 1, ki, g, gc, s))
                                            p = "YES";
                                    }
                                }
                            }

                            sw.WriteLine(string.Format(o, i + 1) + p);
                        }
                    }
                }
            }
        }
    }

    private static bool FindI(string t, int g, long gc, out int i, out int ig)
    {
        ig = 0;
        if (IsI(1, t, out i))
        {
            return true;
        }

        if (gc > 1 && IsI(FindGroupValue(g, 1), t, out i))
        {
            ig = 1;
            return true;
        }

        if (gc > 2 && IsI(FindGroupValue(g, 2), t, out i))
        {
            ig = 2;
            return true;
        }

        if (gc > 3 && IsI(FindGroupValue(g, 3), t, out i))
        {
            ig = 3;
            return true;
        }

        return false;
    }

    private static bool IsI(int s, string t, out int i)
    {
        int r = s;
        for (i = 0; i < t.Length; i++)
        {
            r = r.Calc(t[i]);
            if (r.ConvertBack() == 'i')
                return true;
        }

        return false;
    }

    private static bool FindK(string t, int g, long gc, out int i, out int kg)
    {
        kg = 0;
        if (IsK(1, t, out i))
        {
            return true;
        }

        if (gc > 1 && IsK(FindGroupValue(g, 1), t, out i))
        {
            kg = 1;
            return true;
        }

        if (gc > 2 && IsK(FindGroupValue(g, 2), t, out i))
        {
            kg = 2;
            return true;
        }

        if (gc > 3 && IsK(FindGroupValue(g, 3), t, out i))
        {
            kg = 3;
            return true;
        }

        return false;
    }

    private static bool IsK(int s, string t, out int i)
    {
        int r = s;
        for (i = t.Length - 1; i >= 0; i--)
        {
            r = t[i].Calc(r);
            if (r.ConvertBack() == 'k')
                return true;
        }

        return false;
    }

    private static bool IsJ(int s, int e, int g, long gc, string t)
    {
        int r = 1;

        if (gc > 1)
        {
            for (int i = s; i < t.Length; i++)
            {
                r = r.Calc(t[i]);
            }

            if (gc > 2)
                r = r.Calc(FindGroupValue(g, gc - 2));

            for (int i = 0; i < e; i++)
            {
                r = r.Calc(t[i]);
            }
        }
        else
        {
            for (int i = s; i < e; i++)
            {
                r = r.Calc(t[i]);
            }
        }

        return r.ConvertBack() == 'j';
    }

    private static int FindGroupValue(int g, long gc)
    {
        if (g == 1)
            return 1;

        if (g != -1)
        {
            switch (gc % 4)
            {
                case 0:
                    return 1;
                case 2:
                    return -1;
                case 3:
                    return -g;
                default:
                    return g;
            }
        }
        else
        {
            return gc % 2 == 0 ? 1 : -1;
        }
    }
}

public static class Extensions
{
    public static int[][] lookup;

    public static int GetIndex(this int i)
    {
        return Math.Abs(i) - 1;
    }

    public static int Convert(this char c)
    {
        return c - 'g';
    }

    public static char ConvertBack(this int c)
    {
        return (char)(c + 'g');
    }

    public static int Calc(this int i, char c)
    {
        return Calc(i, c.Convert());
    }

    public static int Calc(this char c, int i)
    {
        return Calc(c.Convert(), i);
    }

    public static int Calc(this int i, int c)
    {
        int f = 1;

        if (i < 0)
        {
            f = -f;
        }
        
        if (c < 0)
        {
            f = -f;
        }

        return f * lookup[i.GetIndex()][c.GetIndex()];
    }
}