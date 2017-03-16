using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BoxFactory
{
    class Program
    {
        static void Main(string[] args)
        {
            var cases = int.Parse(Console.ReadLine());

            for (int i = 1; i <= cases; i++)
            {
                var counts = Console.ReadLine(); //I ignore this
                var toys = new Seq(Console.ReadLine());
                var boxes = new Seq(Console.ReadLine());
                var result = LCS(toys, boxes);

                Console.WriteLine("Case #{0}: {1}", i, result);
            }
        }



        //This is basically just the longest-common-subsequence problem
        // except the strings are potentially *very* long

        //We can repurpose the general LCS algorithm by operating on groups
        // of identical characters rather than just individual chars
        static long LCS(Seq X, Seq Y)
        {
            if (X.IsEmpty() || Y.IsEmpty())
            {
                return 0;
            }

            if (X.Last().Item2 == Y.Last().Item2)
            {
                //chop off the common tail, check from there
                long commonLength = Math.Min(X.Last().Item1, Y.Last().Item1);
                X = X.RemoveLast(commonLength);
                Y = Y.RemoveLast(commonLength);

                return LCS(X, Y) + commonLength;
            }

            //chop off either one or the other until it changes, then choose the highest
            //should consider memoizing this in the dynamic programming fashion, but CBF
            var X1 = X.RemoveLast(X.Last().Item1);
            var Y1 = Y.RemoveLast(Y.Last().Item1);

            return Math.Max(
                LCS(X1, Y),
                LCS(X, Y1));
        }
    }

    class Seq
    {
        List<Tuple<long, long>> elements;

        public Seq(String line)
        {
            var tokes = line.Split(' ');
            elements = new List<Tuple<long, long>>(tokes.Length / 2);
            for (int i = 0; i < (tokes.Length / 2); i++)
            {
                elements.Add(new Tuple<long,long>(long.Parse(tokes[2 * i]), long.Parse(tokes[2 * i + 1])));
            }
        }

        private Seq(Seq s)
        {
            elements = s.elements.ToList();
        }

        public bool IsEmpty()
        {
            return !elements.Any();
        }

        public long Length()
        {
            return elements.Select(t => t.Item1).Aggregate((a, b) => a + b);
        }

        public Tuple<long, long> Last()
        {
            return elements[elements.Count - 1];
        }

        public Seq RemoveLast(long n)
        {
            Seq result = new Seq(this);
            var last = elements[elements.Count - 1];
            result.elements[elements.Count - 1] = new Tuple<long, long>(last.Item1 - n, last.Item2);
            if (result.elements[elements.Count - 1].Item1 == 0)
            {
                result.elements.RemoveAt(elements.Count - 1);
            }
            return result;
        }
    }
}
