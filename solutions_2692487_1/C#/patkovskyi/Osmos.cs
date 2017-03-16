namespace Osmos
{
    using System;
    using System.IO;
    using System.Linq;

    class Osmos
    {
        static void Main(string[] args)
        {
            var inStream = File.OpenText("A-large.in");
            var outStream = new StreamWriter("A-large.out") { AutoFlush = true };            
            Console.SetIn(inStream);
            Console.SetOut(outStream);

            int t = int.Parse(Console.ReadLine());

            for (int tt = 1; tt <= t; tt++)
            {
                string[] an = Console.ReadLine().Split(' ');
                int a = int.Parse(an[0]);
                int n = int.Parse(an[1]);
                int[] m = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

                Array.Sort(m);
                long r = Mote(a, m, 0);
                Console.WriteLine("Case #{0}: {1}", tt, r);
            }

            inStream.Close();
            outStream.Close();

            string expected = File.ReadAllText("TestResult.txt");
            string actual = File.ReadAllText("Out.txt");
            
            if (expected != actual) throw new Exception();
        }

        private static long Mote(long s, int[] m, int from)
        {                        
            for (int i = from; i < m.Length; i++)
            {
                if (s <= m[i])
                {
                    long rem = 1 + Mote(s, m, i + 1);
                    long add = long.MaxValue;
                    if (s > 1)
                    {
                        long r = 0;
                        while (s <= m[i])
                        {
                            ++r;
                            s += (s - 1);
                        }
                        add = r + Mote(s + m[i], m, i + 1);
                    }
                    return Math.Min(add, rem);
                }

                s += m[i];
            }

            return 0;
        }
    }
}
