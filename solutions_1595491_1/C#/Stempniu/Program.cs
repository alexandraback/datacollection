using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;

namespace DancingWiththeGooglers
{
    public class Program
    {
        private static void Main()
        {
            string[] text = File.ReadAllLines(@"d:\a.txt");
            for (int i = 1; i < text.Length; i++)
            {
                string[] numbers = text[i].Split(' ');
                int n = int.Parse(numbers[0]);
                int s = int.Parse(numbers[1]);
                int p = int.Parse(numbers[2]);
                var triples = new LinkedList<Triple>();

                for (int j = 0; j < n; j++)
                {
                    int t = int.Parse(numbers[3 + j]);
                    triples.AddLast(new Triple(t));
                }

                int result = 0;
                foreach (Triple triple in triples)
                {
                    if (triple.Contains(p))
                    {
                        ++result;
                        continue;
                    }
                    if (s > 0 && triple.TryToRepair(p))
                    {
                        ++result;
                        --s;
                    }
                }

                File.AppendAllText(@"d:\out.txt", string.Format("Case #{0}: {1}\n", i, result));
            }
        }
    }

    public class Triple
    {
        public Triple(int sum)
        {
            double exact = (double) sum/3;
            int s;
            if (int.TryParse(exact.ToString(CultureInfo.InvariantCulture), out s))
            {
                A = B = C = s;
            }
            else
            {
                s = sum/3;
                var rounded = (int) Math.Round(exact);
                if (rounded > s)
                {
                    B = s + 1;
                }
                else
                {
                    B = s;
                }
                A = s + 1;
                C = s;
            }
        }

        public int A { get; set; }
        public int B { get; set; }
        public int C { get; set; }

        public bool Contains(int p)
        {
            return A >= p || B >= p || C >= p;
        }

        public bool TryToRepair(int p)
        {
            int t = Math.Max(C, B);
            if (t > 0 && A + 1 >= p && A - t == 0)
            {
                return true;
            }
            return false;
        }
    }
}