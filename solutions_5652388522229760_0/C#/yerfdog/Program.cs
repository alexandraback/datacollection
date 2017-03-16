using System;
using System.IO;

namespace gcj16q
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\GCJ\A.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\A.out");
            for (int a = 0; a < t; a++)
            {
                int N = int.Parse(lines[idx++]); 

                tw.WriteLine("Case #{0}: {1}", a + 1, calca(N));
            }
            tw.Close();
        }

        private static string calca(int N)
        {
            if(N == 0)
            {
                return "INSOMNIA";
            }
            int digits = 0;
            int done = (1 << 10) - 1;
            int cur = 0;
            while(done != digits)
            {
                cur += N;
                int curtemp = cur;
                while(curtemp > 0)
                {
                    int dig = curtemp % 10;
                    digits |= 1 << dig;
                    curtemp /= 10;
                }
            }
            return cur.ToString();
        }
    }
}