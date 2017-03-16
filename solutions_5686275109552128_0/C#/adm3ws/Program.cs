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

            var root = @"D:\gcj\p2\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            
            int[] data = input.SelectMany(x => x.Split(' ').Select(y => Int32.Parse(y))).ToArray();
            IEnumerator<int> scanner = data.AsEnumerable<int>().GetEnumerator();
            scanner.MoveNext();
            int numCases = scanner.Current;
            for (int nc = 0; nc < numCases; ++nc)
            {
                List<int> values = new List<int>();

                scanner.MoveNext();
                int people = scanner.Current;
                for (int i = 0; i < people; ++i)
                {
                    scanner.MoveNext();
                    values.Add(scanner.Current);
                }

                int maxVal = values.Max();

                int minSolutionSeen = maxVal;

                for (int i = 1; i < maxVal; ++i)
                {
                    int extraCost = 0;
                    foreach (var v in values)
                    {
                        extraCost += ((v + i -1) / i - 1);
                    }

                    minSolutionSeen = Math.Min(minSolutionSeen, extraCost + i);
                }


                output.WriteLine("Case #{0}: {1}", nc + 1, minSolutionSeen);
                Console.WriteLine("Case #{0}: {1}", nc + 1, minSolutionSeen);
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
