using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class C
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case {0}", CASE);
            string[] parts = Console.ReadLine().Split();
            int A = int.Parse(parts[0]);
            int B = int.Parse(parts[1]);
            int pow = 1;
            while (pow <= A) pow *= 10;
            HashSet<Pair<int, int>> done = new HashSet<Pair<int, int>>(new Pair<int, int>(0, 0));
            for (int i = A; i <= B; i++)
            {
                for (int pow1 = 10; pow1 < pow; pow1 *= 10)
                {
                    int pow2 = pow / pow1;
                    int lastpart = i % pow1;
                    int firstpart = i / pow1;
                    int num = lastpart * pow2 + firstpart;
                    if (num < A || num > B || num == i) continue;
                    Pair<int, int> newNum = new Pair<int, int>(Math.Min(i, num), Math.Max(i, num));
                    done.Add(newNum);
                }
            }
            Console.WriteLine("Case #{0}: {1}", CASE, done.Count);
        }
    }

    public class Pair<A, B> : IEqualityComparer<Pair<A, B>>
    {
        public A Fst;
        public B Snd;

        public Pair(A fst, B snd)
        {
            Fst = fst; Snd = snd;
        }

        public override string ToString()
        {
            return Fst.ToString() + " " + Snd.ToString();
        }

        public bool Equals(Pair<A, B> x, Pair<A, B> y)
        {
            return x.Fst.Equals(y.Fst) && x.Snd.Equals(y.Snd);
        }

        public int GetHashCode(Pair<A, B> obj)
        {
            return Fst.GetHashCode() * 1000000009 ^ Snd.GetHashCode();
        }
    }
}
