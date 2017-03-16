namespace ManageYourEnergy
{
    using System;
    using System.IO;
    using System.Linq;

    class ManageYourEnergy
    {
        private static long GetGain(long e, long r, long[] v, long cur, long i)
        {
            if (i == v.Length - 1)
            {
                return cur * v[i];
            }

            long max = 0;            
            for (int spendOnI = 0; spendOnI <= cur; spendOnI++)
            {
                long gain = spendOnI * v[i] + GetGain(e, r, v, Math.Min(e, cur - spendOnI + r), i + 1);                
                max = Math.Max(gain, max);
            }

            return max;
        }

        private static long GetGain(long e, long r, long[] v)
        {
            return GetGain(e, r, v, e, 0);
        }

        static void Main(string[] args)
        {
            var inStream = File.OpenText("B-small-attempt0.in");
            var outStream = new StreamWriter("B-small-attempt0.out");
            Console.SetIn(inStream);
            Console.SetOut(outStream);

            int cases = int.Parse(Console.ReadLine());

            for (int tt = 1; tt <= cases; tt++)
            {
                string[] ern = Console.ReadLine().Split(' ');
                long e = long.Parse(ern[0]);
                long r = long.Parse(ern[1]);
                long n = long.Parse(ern[1]);
                long[] v = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();

                long gain = GetGain(e, r, v);
                Console.WriteLine("Case #{0}: {1}", tt, gain);
            }

            inStream.Close();
            outStream.Close();

            //string expected = File.ReadAllText("TestResult.txt");
            //string actual = File.ReadAllText("Out.txt");
            //if (expected != actual) throw new Exception();
        }
    }
}
