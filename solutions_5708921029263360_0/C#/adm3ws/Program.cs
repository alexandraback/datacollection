using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TUP = System.Tuple<int, int, int>;
using T2 = System.Tuple<int, int>;


namespace GCJ.P1
{
    class Program
    {
        static int J;
        static int P;
        static int S;
        static int K;

        static int maxSize = 0;

        public static List<TUP> Try(int cj, int cp, int cs, List<TUP> sel)
        {
            if(cj > J - 1 || cp > P - 1 || cs > S - 1)
            {
                Dictionary<T2, int> c1 = new Dictionary<Tuple<int, int>, int>();
                Dictionary<T2, int> c2 = new Dictionary<Tuple<int, int>, int>();
                Dictionary<T2, int> c3 = new Dictionary<Tuple<int, int>, int>();

                foreach(var t in sel)
                {
                    var t1 = Tuple.Create(t.Item1, t.Item2);
                    var t2 = Tuple.Create(t.Item2, t.Item3);
                    var t3 = Tuple.Create(t.Item1, t.Item3);

                    if(!c1.ContainsKey(t1))
                    {
                        c1[t1] = 0;
                    }
                    c1[t1]++;

                    if (!c2.ContainsKey(t2))
                    {
                        c2[t2] = 0;
                    }
                    c2[t2]++;

                    if (!c3.ContainsKey(t3))
                    {
                        c3[t3] = 0;
                    }
                    c3[t3]++;
                }

                if(c1.Any(x => x.Value > K) || c2.Any(x => x.Value > K) && c3.Any(x => x.Value > K))
                {
                    return null;
                }
                return new List<TUP> (sel);
            }

            sel.Add(Tuple.Create(cj, cp, cs));
            if(cj != J - 1)
            {
                cj++;
            }
            else
            {
                cj = 0;
                if (cp != P - 1)
                {
                    cp++;
                }
                else
                {
                    cp = 0;
                    cs++;
                }

            }
            if(sel.Count > P * S * K)
            {
                return null;
            }

            var r1 = Try(cj, cp, cs, sel);
            if(maxSize == J * P * S && r1.Count != null && r1.Count == maxSize)
            {
                return r1;
            }
           /* if(maxSize == J * P * K && r1.Count != null && r1.Count == maxSize)
            {
                return r1;
            }*/

            sel.RemoveAt(sel.Count - 1);
            var r2 = Try(cj, cp, cs, sel);

            if(r1 != null && r1.Count > maxSize)
            {
                maxSize = r1.Count;
            }
            if (r2 != null && r2.Count > maxSize)
            {
                maxSize = r2.Count;
                return r2;
            }

            if(r2 != null && r1 != null && r2.Count > r1.Count)
            {
                return r2;
            }
            if(r1 == null)
            {
                return r2;
            }
            return r1;
        }

        static void Main(string[] args)
        {
            var root = @"C:\projects\comp\gcj\p1\";


            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long[] data = input.SelectMany(x => x.Split(' ').Select(y => Int64.Parse(y))).ToArray();
            IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;

            
            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                J = (int)scanner.Current;
                scanner.MoveNext();
                P = (int)scanner.Current;
                scanner.MoveNext();
                S = (int)scanner.Current;
                scanner.MoveNext();
                K = (int)scanner.Current;
                maxSize = 0;
                var res = Try(0, 0, 0, new List<Tuple<int, int, int>>());
                output.WriteLine("Case #{0}: {1}", nc + 1, maxSize);
                Console.WriteLine("Case #{0}: {1}", nc + 1, maxSize);

                if (res != null)
                {
                    foreach (var of in res)
                    {
                        output.WriteLine("{0} {1} {2}", of.Item1 + 1, of.Item2 + 1, of.Item3 + 1);
                        Console.WriteLine("{0} {1} {2}", of.Item1 + 1, of.Item2 + 1, of.Item3 + 1);
                    }
                }
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

        private static bool dfs(List<List<long>> g, bool[] vis, long i)
        {
            foreach(var v in g[(int)i])
            {
                if(vis[v])
                {
                    return true;
                }
                vis[v] = true;
                if (dfs(g, vis, v))
                {
                    return true;
                }
            }
            return false;
        }
    }
}
