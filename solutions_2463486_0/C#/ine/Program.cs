using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace fairandsquare
{
  class Program
  {
    static void Main(string[] args)
    {
      SortedSet<BNum> solutions = new SortedSet<BNum>();
      List<List<int>> prefixes = new List<List<int>> { new List<int>() };

      for (int p = 1; p < 52; ++p)
      {
        var sols = new List<BNum>();
        foreach (var pre in prefixes)
        {
          if (p % 2 == 0)
          {
            BNum n = new BNum(pre.Concat(pre.AsEnumerable().Reverse()));
            BNum ns = n * n;
            if (ns.IsPalindrome())
            {
              sols.Add(n);
              solutions.Add(ns);
            }
          }
          else
          {
            for (int d = p == 1 ? 1 : 0; d <= 9; ++d)
            {
              BNum n = new BNum(pre.Concat(new[] { d }).Concat(pre.AsEnumerable().Reverse()));
              BNum ns = n * n;
              if (ns.IsPalindrome())
              {
                sols.Add(n);
                solutions.Add(ns);
              }
            }
          }
        }

        int prefLength = (p + 1) / 2;
        prefixes = sols.Select(s => s.digits.Take(prefLength).ToList()).Distinct(new ListSequenceComparer()).ToList();
      }

      //foreach (var sol in solutions)
      //  Console.WriteLine(sol);

      //Console.WriteLine("Total solutions: " + solutions.Count);

      var lines = File.ReadAllLines(args[0]);
      int T = int.Parse(lines[0]);
      for (int i = 1; i <= T; ++i)
      {
        var ab = lines[i].Split(' ');
        var a = new BNum(ab[0]);
        var b = new BNum(ab[1]);

        int sols = solutions.GetViewBetween(a, b).Count;

        Console.WriteLine("Case #{0}: {1}", i, sols);
      }
    }

    public static long Reverse(long n)
    {
      long rev = 0;
      while (n > 0)
      {
        rev = rev * 10 + n % 10;
        n /= 10;
      }

      return rev;
    }
  }

  class BNum : IComparable<BNum>
  {
    public List<int> digits;
    public int nBase;

    public BNum(string str, int nBase = 10)
    {
      this.nBase = nBase;
      digits = str.Select(x => int.Parse(x.ToString())).Reverse().ToList();
    }

    public BNum(int init = 0, int nBase = 10)
    {
      digits = new List<int> { init };
      this.nBase = nBase;
      NormalizeBase();
    }

    public BNum(BNum n)
    {
      digits = new List<int>(n.digits);
      nBase = n.nBase;
    }

    public BNum(IEnumerable<int> init, int nBase = 10)
    {
      digits = init.ToList();
      this.nBase = nBase;
    }

    public void NormalizeBase()
    {
      for (int i = 0; i < digits.Count; ++i)
        if (digits[i] >= nBase)
        {
          if (i == digits.Count - 1)
            digits.Add(0);

          digits[i + 1] += digits[i] / nBase;
          digits[i] %= nBase;
        }
    }

    public int Count { get { return digits.Count; } }

    public int this[int i] { get { return digits[i]; } set { digits[i] = value; } }

    public void Mult(int n)
    {
      for (int i = 0; i < digits.Count; i++)
        digits[i] *= n;

      NormalizeBase();
    }

    public void Add(BNum n)
    {
      if (n.nBase != nBase)
        throw new ArgumentException("Base not equal");

      while (Count < n.Count)
        digits.Add(0);

      for (int i = 0; i < n.Count; i++)
        digits[i] += n.digits[i];

      NormalizeBase();
    }

    public static BNum operator *(BNum n1, BNum n2)
    {
      if (n1.nBase != n2.nBase)
        throw new ArgumentException("Base not equal");

      BNum res = new BNum(0, n1.nBase);
      for (int p = n2.digits.Count - 1; p >= 0; --p)
      {
        BNum a = new BNum(Enumerable.Repeat(0, p).Concat(n1.digits), n1.nBase);
        a.Mult(n2.digits[p]);
        res.Add(a);
      }

      return res;
    }

    public static bool operator <(BNum n1, BNum n2)
    {
      return n1.CompareTo(n2) < 0;
    }

    public static bool operator >(BNum n1, BNum n2)
    {
      return n1.CompareTo(n2) > 0;
    }

    public static bool operator ==(BNum n1, BNum n2)
    {
      if (n1.nBase != n2.nBase)
        throw new ArgumentException("Base not equal");

      if (n1.digits.Count != n2.digits.Count)
        return false;

      return n1.digits.SequenceEqual(n2.digits);
    }

    public static bool operator !=(BNum n1, BNum n2)
    {
      return !(n1 == n2);
    }

    public override bool Equals(object obj)
    {
      var bn = (BNum)obj;

      return bn != null && bn == this;
    }

    public override int GetHashCode()
    {
      var hash = nBase.GetHashCode();
      for (int i = digits.Count; i >= 0; --i)
        hash = hash * 31 + digits[i];

      return hash;
    }

    public bool IsPalindrome()
    {
      for (int i = 0; i < digits.Count / 2; ++i)
        if (digits[i] != digits[digits.Count - i - 1])
          return false;

      return true;
    }

    public override string ToString()
    {
      return string.Concat(digits.AsEnumerable().Reverse());
    }

    public int CompareTo(BNum other)
    {
      if (nBase != other.nBase)
        throw new ArgumentException("Base not equal");

      int digDiff = digits.Count - other.digits.Count;
      if (digDiff != 0)
        return digDiff;

      for (int i = digits.Count - 1; i >= 0; --i)
      {
        digDiff = digits[i] - other.digits[i];
        if (digDiff != 0)
          return digDiff;
      }

      return 0;      
    }
  }

  class ListSequenceComparer : EqualityComparer<List<int>>
  {
    public override bool Equals(List<int> x, List<int> y)
    {
      return x.SequenceEqual(y);
    }

    public override int GetHashCode(List<int> obj)
    {
      var hash = 1;
      for (int i = obj.Count - 1; i >= 0; --i)
        hash = hash * 31 + obj[i];

      return hash;
    }
  }

}
