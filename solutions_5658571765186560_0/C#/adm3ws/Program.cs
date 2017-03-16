using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

// The solution might use the C5 C# library, available at http://www.itu.dk/research/c5/

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {

            var root = @"D:\gcj\p4\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");

            int[] data = input.SelectMany(x => x.Split(' ').Select(y => Int32.Parse(y))).ToArray();
            IEnumerator<int> scanner = data.AsEnumerable<int>().GetEnumerator();
            scanner.MoveNext();
            int numCases = scanner.Current;
            for (int nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                int X = scanner.Current;
                scanner.MoveNext();
                int R = scanner.Current;
                scanner.MoveNext();
                int C = scanner.Current;
                bool bad = false;
                if (X > R && X > C)
                {
                    bad = true;
                }
                if (X > R + 1 || X > C + 1)
                {
                    bad = true;
                }
                if ((X + 1) / 2 > R)
                {
                    bad = true;
                }
                if ((X + 1) / 2 > C)
                {
                    bad = true;
                }
                if ((R * C) % X != 0)
                {
                    bad = true;
                }
                if (X >= 7)
                {
                    bad = true;
                }


               

                output.WriteLine("Case #{0}: {1}", nc + 1, bad ? "RICHARD" : "GABRIEL");
                Console.WriteLine("Case #{0}: {1}", nc + 1, bad ? "RICHARD" : "GABRIEL");
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }
    }
}
