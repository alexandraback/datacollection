namespace TrainCars
{
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var inStream = File.OpenText("B-small-attempt0.in");
            var outStream = new StreamWriter("B-small-attempt0.out") { AutoFlush = true };
            Console.SetIn(inStream);
            Console.SetOut(outStream);

            int cases = int.Parse(Console.ReadLine());

            for (int t = 1; t <= cases; t++)
            {
                int s = int.Parse(Console.ReadLine());
                var sets = Console.ReadLine().Split(' ').ToList();
                
                long ways = Count(sets);
                Console.WriteLine("Case #{0}: {1}", t, ways);
            }
            
            inStream.Close();
            outStream.Close();
            //string expected = File.ReadAllText("TestResult.txt");
            //string actual = File.ReadAllText("Out.txt");
            //if (expected != actual) throw new Exception();
        }               

        private static long Count(List<string> sets)
        {
            if (sets.Count == 1) return 1;           

            var lefts = new Dictionary<char, string>();
            var rights = new Dictionary<char, string>();            
            var intern = new HashSet<char>();
            var trans = new Dictionary<char, int>();

            foreach (string s in sets)
            {
                string trim = s.TrimStart(s[0]).TrimEnd(s[s.Length - 1]);                                

                if (s[0] == s[s.Length - 1] && string.IsNullOrWhiteSpace(trim))
                {
                    Dadd(trans, s[0]);
                }
                else
                {
                    if (rights.ContainsKey(s[0])) return 0;
                    rights.Add(s[0], s);

                    if (lefts.ContainsKey(s[s.Length - 1])) return 0;
                    lefts.Add(s[s.Length - 1], s);

                    for (int i = 0; i < trim.Length; )
                    {
                        if (intern.Contains(trim[i]) || lefts.ContainsKey(trim[i]) || rights.ContainsKey(trim[i])) return 0;
                        intern.Add(trim[i]);
                        int j = i;
                        while (i < trim.Length && trim[i] == trim[j]) i++;
                    }
                }
            }

            char best = '0';
            foreach (var c in lefts.Keys)
            {
                if (rights.ContainsKey(c) || trans.ContainsKey(c))
                {
                    best = c;
                    break;
                }
            }

            if (best == '0')
            {
                foreach (var c in rights.Keys)
                {
                    if (trans.ContainsKey(c))
                    {
                        best = c;
                        break;
                    }
                }
            }

            if (best == '0')
            {
                foreach (var c in trans.Keys)
                {
                    if (trans[c] > 1)
                    {
                        best = c;
                        break;
                    }
                }
            }

            if (best == '0') return Factorial(sets.Count);

            var newSets = new List<string>();
            for (int i = 0; i < sets.Count; i++)
            {
                if (lefts.ContainsKey(best) && sets[i] == lefts[best]
                    || rights.ContainsKey(best) && sets[i] == rights[best] || sets[i].All(c => c == best))
                {
                }
                else
                {
                    newSets.Add(sets[i]);
                }
            }

            string newstr = lefts.ContainsKey(best) ? lefts[best] : best.ToString(CultureInfo.InvariantCulture);
            newstr += rights.ContainsKey(best) ? rights[best] : string.Empty;
            newSets.Add(newstr);

            long res = Factorial(trans.ContainsKey(best) ? trans[best] : 0);
            return res * Count(newSets) % 1000000007;
        }

        private static long Factorial(long x)
        {
            long result = 1;

            for (long i = 2; i <= x; i++)
            {
                result = result * i % 1000000007;
            }

            return result;
        }

        private static void Dadd(Dictionary<char, int> d, char a)
        {
            if (d.ContainsKey(a))
            {
                d[a] = d[a] + 1;
            }
            else
            {
                d.Add(a, 1);
            }
        }
    }
}
