using System;
using System.Collections.Generic;


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

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

}


class Myon
{
    Scanner cin;
    Myon() { }

    public static void Main()
    {
        new Myon().multi();
    }

    void multi()
    {
        int c;
        cin = new Scanner();
        int T = cin.nextInt();
        for (c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }

    int N;
    void calc()
    {
        Scanner cin = new Scanner();
        N = cin.nextInt();
        int[] pos = new int[N];
        double[] s = new double[N];
        double[] p = new double[N];
        for (int i = 0; i < N; i++)
        {
            pos[i] = getc(cin.next()[0]);
            s[i] = cin.nextDouble();
            p[i] = cin.nextDouble();
        }
        int[] check = new int[N];
        int[] check2 = new int[N];
        for (int i = 0; i < N; i++)
        {
            check[i] = check2[i] = -1;
        }
        List<Data> l = new List<Data>();
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (s[i] != s[j])
                {
                    if (Math.Abs((p[i] + s[i] * 1e-12) - (p[j] + s[j] * 1e-12)) < 5)
                    {
                        if (check2[i] != -1 || check2[j] != -1)
                        {
                            Console.WriteLine(0);
                            return;
                        }
                        if (check[i] != -1) check2[i] = j;
                        else check[i] = j;
                        if (check[j] != -1) check2[j] = i;
                        else check[j] = i;
                    }
                    double timea = (double)(p[i] - p[j] + 5) / (s[j] - s[i]);
                    double timeb = (double)(p[i] - p[j] - 5) / (s[j] - s[i]);
                    if (timea > timeb)
                    {
                        double temp = timea;
                        timea = timeb;
                        timeb = temp;
                    }
                    if (timea > 1e-12)
                    {
                        l.Add(new Data(timea, i, j, 1));
                    }
                    if (timeb > 1e-12)
                    {
                        l.Add(new Data(timeb, i, j, 0));
                    }
                }
                else
                {
                    if (Math.Abs(p[i] - p[j]) < 5)
                    {
                        //Console.Error.WriteLine("stopcheck {0} {1}", i, j);
                        if (check2[i] != -1 || check2[j] != -1)
                        {
                            Console.WriteLine(0);
                            return;
                        }
                        if (check[i] != -1) check2[i] = j;
                        else check[i] = j;
                        if (check[j] != -1) check2[j] = i;
                        else check[j] = i;
                    }
                }
            }
        }
        Data[] ar = l.ToArray();
        for (int i = 0; i < ar.Length; i++)
        {
            for (int j = 0; j < ar.Length - 1; j++)
            {
                if ((ar[j].time > ar[j + 1].time + 1e-12) || (ar[j].time > ar[j + 1].time - 1e-12 && ar[j].type == 1 && ar[j + 1].type == 0))
                {
                    Data temp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (check[i] == -1) pos[i] = 0;
        }
        List<long> nowl = new List<long>();
        List<long> nextl = new List<long>();
        nowl.Add(gethash(pos));
        
        //Console.Error.WriteLine("Data:" + ar.Length);
        for (int i = 0; i < N; i++)
        {
            //Console.Error.Write(i + " pos: " + pos[i] + " check: ");
            //if (check[i] != -1) Console.Error.Write(check[i] + "a ");
            //if (check2[i] != -1) Console.Error.Write(check2[i] + "b ");
            //Console.Error.WriteLine();
        }
         
        foreach (Data d in ar)
        {
            //Console.Error.WriteLine(d.time + " " + nowl.Count);
            //Console.Error.WriteLine(d.a + " " + d.b + " " + d.type);
            int a = d.a;
            int b = d.b;
            int type = d.type;
            if (type == 0)
            {
                if (check[a] == b)
                {
                    check[a] = check2[a];
                }
                else if (check2[a] != b) Console.Error.WriteLine("!?");
                if (check[b] == a)
                {
                    check[b] = check2[b];
                }
                else if (check2[b] != a) Console.Error.WriteLine("!?");
                check2[a] = check2[b] = -1;
            }
            else
            {
                if (check2[a] != -1 || check2[b] != -1)
                {
                    Console.WriteLine(string.Format("{0:0.000000000000}", d.time));
                    return;
                }
                if (check[a] != -1) check2[a] = b;
                else check[a] = b;
                if (check[b] != -1) check2[b] = a;
                else check[b] = a;
            }

            Dictionary<long, bool> dic = new Dictionary<long, bool>();
            foreach (var item in nowl)
            {
                int[] nowpos = getpos(item);
                if (type == 0)
                {
                    if (check[a] == -1) nowpos[a] = 0;
                    if (check[b] == -1) nowpos[b] = 0;
                    long next = gethash(nowpos);
                    if (!dic.ContainsKey(next))
                    {
                        dic[next] = true;
                        nextl.Add(next);
                    }
                }
                else
                {
                    int prea = nowpos[a];
                    int preb = nowpos[b];
                    for (int i = 0; i < 2; i++)
                    {
                        if (check2[a] != -1 && prea != i) continue;
                        for (int j = 0; j < 2; j++)
                        {
                            if (i == j) continue;
                            if (check2[b] != -1 && preb != j) continue;
                            nowpos[a] = i;
                            nowpos[b] = j;
                            long next = gethash(nowpos);
                            if (!dic.ContainsKey(next))
                            {
                                dic[next] = true;
                                nextl.Add(next);
                            }
                        }
                    }
                }
            }
            nowl = new List<long>();
            foreach (var item in nextl)
            {
                nowl.Add(item);
            }
            if (nowl.Count == 0)
            {
                Console.WriteLine(string.Format("{0:0.000000000000}", d.time));
                return;
            }
            nextl = new List<long>();
        }
        Console.WriteLine("Possible");
    }

    long gethash(int[] pos)
    {
        long ret = 0;
        for (int i = 0; i < N; i++)
        {
            if(pos[i]==1) ret += (long)1 << i;
        }
        return ret;
    }

    int[] getpos(long hash)
    {
        int[] ret = new int[N];
        for (int i = 0; i < N; i++)
        {
            ret[i] = (int)(hash & 1);
            hash /= 2;
        }
        return ret;
    }

    int getc(char c)
    {
        if (c == 'L') return 0;
        return 1;
    }

    class Data{
        public Data(double time_, int a_, int b_, int type_)
        {
            time = time_;
            a = a_;
            b = b_;
            type = type_;
        }

        public double time;
        public int a;
        public int b;
        public int type;
    }
}
