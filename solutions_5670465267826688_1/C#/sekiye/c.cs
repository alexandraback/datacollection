using System;
using System.Collections.Generic;
using System.Linq;

class Myon
{
  public Myon() { }
  public static void Main()
  {
    new Myon().run2();
  }

  Scanner cin;
  public void run2()
  {
    cin = new Scanner();
    int T = cin.nextInt();
    for (int i = 0; i < T; i++)
    {
      Console.Write("Case #{0}: ", i + 1);

      run();
    }
  }

  int toInt(char a) {
    if (a == '1') {
      return 1;
    } else if (a == 'i') {
      return 2;
    } else if (a == 'j') {
      return 3;
    } else {
      return 4;
    }
  }

  int f(int a, int b) {
    int s = Math.Sign(a) * Math.Sign(b);
    a = Math.Abs(a);
    b = Math.Abs(b);
    if (a == 1) {
      return s * b;
    }
    if (b == 1) {
      return s * a;
    }
    if (a == b) {
      return -s;
    }
    if (a == 2) {
      if (b == 3){
        return s * 4;
      } else {
        return -s * 3;
      }
    } else if (a == 3) {
      if (b == 2) {
        return -s * 4;
      } else {
        return s * 2;
      }
    } else {
      if (b == 2) {
        return s * 3;
      } else {
        return -s * 2;
      }
    }
  }

  void run()
  {
    int l = cin.nextInt();
    long x = cin.nextLong();
    string s = cin.next();

    int all = 1;
    for (int i = 0; i < l; i++) {
      all = f(all, toInt(s[i]));
    }
    int count = 1;
    int cur = all;
    while (cur != 1) {
      cur = f(cur, all);
      count += 1;
    }
    long a = x / count;
    long b = x % count;
    x = b;
    for (int i = 0; i < a; i++) {
      x += count;
      if (x > count * 5) {
        break;
      }
    }
    cur = 1;
    int state = 0;
    for (int i = 0; i < s.Length * x; i++) {
      cur = f(cur, toInt(s[i % s.Length]));
      if (state == 0 && cur == 2) {
        state = 1;
        cur = 1;
      } else if (state == 1 && cur == 3) {
        state = 2;
        cur = 1;
      }
    }
    if (state == 2 && cur == 4) {
      Console.Write("YES\n");
    } else {
      Console.Write("NO\n");
    }
  }
}

  class Scanner
  {
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

                                  public Scanner()
    {
      s = new string[0];
      i = 0;
    }

    public string next()
    {
      if (i < s.Length) return s[i++];
      s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
      i = 0;
      return s[i++];
    }

    public int nextInt()
    {
      return int.Parse(next());
    }

    public long nextLong()
    {
      return long.Parse(next());
    }

    public double nextDouble()
    {
      return double.Parse(next());
    }

  }
