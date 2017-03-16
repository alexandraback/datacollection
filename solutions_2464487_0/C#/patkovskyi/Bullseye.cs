namespace Bullseye
{
    using System;
    using System.IO;

    class Bullseye
    {        
        private static ulong CountBullseyes(ulong r, ulong t)
        {            
            double a = 2;
            double b = 2 * r - 1;
            double c = -1.0 * t;

            double x = (-b + Math.Sqrt(b * b - 4 * a * c)) / (2 * a);

            return (ulong)Math.Floor(x);
        }

        static void Main(string[] args)
        {
            var inStream = File.OpenText("A-small-attempt0.in");
            var outStream = new StreamWriter("A-small-attempt0.out");
            Console.SetIn(inStream);
            Console.SetOut(outStream);      

            int cases = int.Parse(Console.ReadLine());

            for (int tt = 1; tt <= cases; tt++)
            {
                string[] rt = Console.ReadLine().Split(' ');
                ulong r = ulong.Parse(rt[0]);
                ulong t = ulong.Parse(rt[1]);

                ulong count = CountBullseyes(r, t);
                Console.WriteLine("Case #{0}: {1}", tt, count);
            }

            inStream.Close();
            outStream.Close();

            //string expected = File.ReadAllText("TestResult.txt");
            //string actual = File.ReadAllText("Out.txt");
            //if (expected != actual) throw new Exception();
        }
    }
}
