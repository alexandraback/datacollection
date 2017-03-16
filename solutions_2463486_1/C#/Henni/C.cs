using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Numerics;

public class C : X
{
    static List<long> x;

    public override bool solve()
    {
        string s1 = ReadString();
        string s2 = ReadStringLine();

        long A = long.Parse(s1);
        long B = long.Parse(s2);
        if (x == null)
        {
            var l = SolveLong(1, 100000L * 100000L * 10000L);
            x = l.Keys.ToList();
        }
        int f=-1;
        int g=-1;
        for (int i = 0; i < x.Count; i++)
        {
            if ((f < 0) && (x[i] >= A)) f=i;
            if ((g < 0) && (x[i] > B)) { g = i; break; };
        }
        if ((f >= 0) && (g < 0)) g = x.Count;
        int c = g - f;
        c = c.Max(0);
        //BigInteger A = BigInteger.Parse(s1);
        //BigInteger B = BigInteger.Parse(s2);
        //var l = SolveBig(A, B);
        //long C = l.Count;

        WriteCaseLine("{0}", c);
        return false;
    }

    private Dictionary<long, long> SolveLong(long A, long B)
    {
        Dictionary<long,long> l = new Dictionary<long,long>();
        long Q1 = (long)Math.Ceiling(Math.Sqrt((double)A));
        long Q2 = (long)Math.Floor(Math.Sqrt((double)B));
        long Q;
        for (long i = Q1; i <= Q2; i++)
        {
            if (isPalindrome(i))
            {
                Q = i * i;
                if (isPalindrome(Q))
                    l.Add(Q, i);
            }
        }
        return l;
    }
    public bool isPalindrome(long p)
    {
        string s = p.ToString().Trim();
        bool r = true;
        int l=s.Length;
        for (int i = 0; i < l/2; i++)
        {
            if (s[i] != s[l - 1 - i])
            {
                r = false;
                break;
            }
        }
        return r;
    }
    //private Dictionary<BigInteger, BigInteger> SolveBig(BigInteger A, BigInteger B)
    //{
    //    Dictionary<BigInteger, BigInteger> l = new Dictionary<BigInteger, BigInteger>();
    //    BigInteger Q1 = 1;
    //    BigInteger Q2 = BigInteger.Pow((BigInteger)Math.Ceiling((BigInteger.Log10(B) / 2)), 10);
    //    BigInteger Q;
    //    for (BigInteger i = Q1; i <= Q2; i++)
    //    {
    //        if (isPalindrome(i))
    //        {
    //            Q = i * i;
    //            if (isPalindrome(Q))
    //                l.Add(Q, i);
    //        }
    //    }
    //    return l;
    //}
    //public bool isPalindrome(BigInteger p)
    //{
    //    string s = p.ToString().Trim();
    //    bool r = true;
    //    int l = s.Length;
    //    for (int i = 0; i < l / 2; i++)
    //    {
    //        if (s[i] != s[l - 1 - i])
    //        {
    //            r = false;
    //            break;
    //        }
    //    }
    //    return r;
    //}
}