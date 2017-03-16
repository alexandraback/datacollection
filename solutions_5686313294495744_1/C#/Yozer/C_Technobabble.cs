using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Combinatorics.Collections;

namespace GoogleJam2016.Practice._2016._1B
{
    class C_Technobabble : IGoogleCodeJam
    {
        class Pair : IEquatable<Pair>, IComparable<Pair>
        {
            public string A;
            public string B;
            public int res = 0;
            public Pair(string readLine)
            {
                string[] x = readLine.Split(' ');
                A = x[0];
                B = x[1];
            }

            public bool Equals(Pair other)
            {
                return Equals(other);
            }

            public int CompareTo(Pair other)
            {
                return ToString().CompareTo(other.ToString());
            }

            public override string ToString()
            {
                return A + " " + B;
            }

            public override bool Equals(object obj)
            {
                var x = obj as Pair;
                return x.A == A && x.B == B;
            }
        }

        class Item
        {
            public Pair pair;
            public int counter;
        }
        public override void Compute(StreamReader reader, StreamWriter writer)
        {
            int t = Convert.ToInt32(reader.ReadLine());
            var d = new SortedDictionary<int, string>();
            var tasks = new List<Task>();
            for (int i = 1; i <= t; i++)
            {
                int n = Convert.ToInt32(reader.ReadLine());
                var l = new List<Pair>(n);
                for (int j = 0; j < n; j++)
                {
                    l.Add(new Pair(reader.ReadLine()));
                }
                int x = i;
                var task = Task.Run(() =>
                {
                    var res = Solve(l);
                    Console.WriteLine(x);
                    lock (d) d.Add(x, res);
                });

                tasks.Add(task);

            }
            Task.WaitAll(tasks.ToArray());

            foreach (KeyValuePair<int, string> k in d)
            {
                writer.WriteLine($"Case #{k.Key}: {k.Value}");

            }

            writer.Flush();
        }

        private string SolveBrut(List<Pair> l)
        {
            var permutations = new Permutations<Pair>(l, GenerateOption.WithoutRepetition);
            int bestCost = 0;
            List<Pair> bestList = null;

            foreach (var permutation in permutations)
            {
                int cost = GetCost(permutation);
                if (cost > bestCost)
                {
                    bestCost = cost;
                    bestList = permutation.ToList();
                }    
            }

            return bestCost.ToString();
        }

        private int GetCost(IList<Pair> list)
        {
            int result = 0;
            var setA = new HashSet<string>();
            var setB = new HashSet<string>();

            foreach (Pair pair in list)
            {
                if (setA.Contains(pair.A) && setB.Contains(pair.B)) result++;
                setA.Add(pair.A);
                setB.Add(pair.B);
            }

            return result;
        }

        private string Solve(List<Pair> list)
        {
            //var dicA = new Dictionary<string, Item>();
            //var dicB = new Dictionary<string, Item>();

            //foreach (Pair pair in list)
            //{
            //    if(!dicA.ContainsKey(pair.A)) dicA.Add(pair.A, new Item {pair = pair, counter = 0});
            //    dicA[pair.A].counter++;

            //    if (!dicB.ContainsKey(pair.B)) dicB.Add(pair.B, new Item { pair = pair, counter = 0 });
            //    dicB[pair.B].counter++;
            //}

            //foreach (var pair in list)
            //{
            //    pair.res += dicA[pair.A].counter;
            //    pair.res += dicB[pair.B].counter;
            //}

            //list = list.OrderBy(t => t.res).ThenBy(t => t.A).ThenBy(t => t.B).ToList();

            int best = 0;
            for (int i = 0; i < 100000; i++)
            {
                list.Shuffle();
                int cost = GetCost(list);
                if (cost > best)
                {
                    best = cost;
                }
            }

            return best.ToString();
        }
    }

    public static class ThreadSafeRandom
    {
        [ThreadStatic]
        private static Random Local;

        public static Random ThisThreadsRandom => Local ?? (Local = new Random(unchecked(Environment.TickCount * 31 + Thread.CurrentThread.ManagedThreadId)));
    }

    static class MyExtensions
    {
        public static void Shuffle<T>(this IList<T> list)
        {
            int n = list.Count;
            while (n > 1)
            {
                n--;
                int k = ThreadSafeRandom.ThisThreadsRandom.Next(n + 1);
                T value = list[k];
                list[k] = list[n];
                list[n] = value;
            }
        }
    }
}