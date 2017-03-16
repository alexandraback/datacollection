namespace PartElf
{
    using System;
    using System.Globalization;
    using System.IO;

    class Program
    {
        private static int GetParent(long p, long q, int depth)
        {
            if (depth > 40) return -1;
            if (p == q) return depth;
            if (q % 2 != 0) return -1;            
            if (p + p <= q)
            {
                return GetParent(p, q / 2, depth + 1);
            }
            
            int other = GetParent(p + p - q, q, depth + 1);
            if (other == -1) return -1;
            return depth + 1;
        }

        static void Main(string[] args)
        {
            var inStream = File.OpenText("A-large.in");
            var outStream = new StreamWriter("A-large.out") { AutoFlush = true };
            Console.SetIn(inStream);
            Console.SetOut(outStream);

            int cases = int.Parse(Console.ReadLine());

            for (int t = 1; t <= cases; t++)
            {
                string[] pq = Console.ReadLine().Split('/');
                long p = long.Parse(pq[0]);
                long q = long.Parse(pq[1]);

                int par = GetParent(p, q, 0);
                Console.WriteLine("Case #{0}: {1}", t, par < 0 ? "impossible" : par.ToString(CultureInfo.InvariantCulture));
            }
            
            inStream.Close();
            outStream.Close();
            // string expected = File.ReadAllText("TestResult.txt");
            // string actual = File.ReadAllText("Out.txt");
            // if (expected != actual) throw new Exception();
        }
    }
}
