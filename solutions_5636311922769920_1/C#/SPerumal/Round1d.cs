using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Round1d
    {
        public static void Main(string[] args)
        {
            new Round1d().Run("D-small.in");
        }

        private void Run(string p)
        {
            int caseNo = 1;
            using (var sr = File.OpenText("D-large.in"))
            using (var sw = File.CreateText("d-large.out"))
            {
                var count = sr.ReadLine();
                string line;

                while ((line = sr.ReadLine()) != null)
                {
                    var parts = line.Split(' ').Select(p1 => int.Parse(p1)).ToArray();
                    Console.WriteLine("Case #{0}", caseNo);
                    var tiles = Check(parts[0], parts[1]).ToList();
                    var hs = new HashSet<BigInteger>(tiles);
                    if (tiles.Count != hs.Count) System.Diagnostics.Debugger.Break();
                    if (tiles.Count <= parts[2])
                        sw.WriteLine("Case #{0}: {1}", caseNo++, String.Join(" ", tiles));
                    else sw.WriteLine("Case #{0}: IMPOSSIBLE", caseNo++);
                }
            }
        }

        private IEnumerable<BigInteger> Check(int k, int c)
        {
            Console.WriteLine("{0} {1}", k, c);
            var sets = GetSets(k, c);
            Console.WriteLine(String.Join(";", sets.Select(s1 => String.Join(",", s1))));
            foreach (var set in sets)
            {
                var exp = Math.Min(c - 1, set.Count() - 1);
                BigInteger sum = 0;
                foreach (var i in set)
                {
                    sum += i * (BigInteger)Math.Pow(k, exp);
                    exp--;
                    if (exp < 0) break;

                }
                Console.WriteLine(sum);

                yield return sum+1;
            }
        }

        IEnumerable<IEnumerable<BigInteger>> GetSets(int k, int c)
        {
            var set = new List<BigInteger>();

            for (int ki = 0, ci = c - 1; ki < k; ki++)
            {
                set.Add(ki);
                if (ci > 0)
                    ci--;
                else
                {
                    ci = c - 1;
                    yield return set;
                    set = new List<BigInteger>();
                }
            }

            if (set.Count > 0) yield return set;
        }
    }
}
