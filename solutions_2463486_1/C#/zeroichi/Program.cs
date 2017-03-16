using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2013
{
    class Program
    {
        static bool isPalindrome(long n)
        {
            string s = n.ToString();
            return s.Equals(new string(s.Reverse().ToArray()));
        }

        static void Main(string[] args)
        {
            var table = new List<long>();
            for (int i = 1; i < 100000; ++i)
            {
                //if (i % 10 == 0) continue;
                string s = i.ToString();
                string srev = new string(s.Reverse().ToArray());
                long a1 = long.Parse(s + srev);
                if (isPalindrome(a1 * a1)) table.Add(a1 * a1);
                long a2 = long.Parse(s + srev.Remove(0, 1));
                if (isPalindrome(a2 * a2)) table.Add(a2 * a2);
                //Console.WriteLine(string.Format("{0} {1}", a1, a2));
            }
            long A, B;
            int cases;
            table.Sort();
            //foreach (var x in table) Console.WriteLine(x);
            using (StreamReader sr = new StreamReader(args[0]))
            {
                cases = int.Parse(sr.ReadLine());
                //A = new int[cases]; B = new int[cases];
                for (int i = 0; i < cases; ++i)
                {
                    string[] s = sr.ReadLine().Split(' ');
                    System.Diagnostics.Debug.Assert(s.Length == 2);
                    A = long.Parse(s[0]);
                    B = long.Parse(s[1]);
                    int Ai = table.BinarySearch(A);
                    if (Ai < 0) Ai = ~Ai;
                    int Bi = table.BinarySearch(B);
                    if (Bi >= 0) Bi++;
                    if (Bi < 0) Bi = ~Bi;
                    //Console.WriteLine(string.Format("[{2},{3}] {0} {1}", Ai, Bi,A,B));
                    Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, Bi - Ai));
                }
            }

        }
    }
}
