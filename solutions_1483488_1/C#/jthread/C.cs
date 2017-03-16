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
            HashSet<long> done = new HashSet<long>();
            for (int i = A; i <= B; i++)
            {
                for (int pow1 = 10; pow1 < pow; pow1 *= 10)
                {
                    int pow2 = pow / pow1;
                    int lastpart = i % pow1;
                    int firstpart = i / pow1;
                    int num = lastpart * pow2 + firstpart;
                    if (num < A || num > B || num == i) continue;
                    long test = Math.Min(i, num);
                    test *= pow;
                    test += Math.Max(i, num);
                    done.Add(test);
                }
            }
            Console.WriteLine("Case #{0}: {1}", CASE, done.Count);
        }
    }
}
