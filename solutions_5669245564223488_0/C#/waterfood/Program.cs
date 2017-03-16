using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace waterfood.CodeJam
{
    class Program
    {
        public const long Mod = 1000000007L;

        static void Main(string[] args)
        {
            var inputs = new Queue<string>(File.ReadAllLines(@"../../B-small-attempt0.in"));
            var outputs = new StringBuilder();

            int T = int.Parse(inputs.Dequeue());
            for (int x = 0; x < T; x++)
            {
                int N = int.Parse(inputs.Dequeue());
                var strings = inputs.Dequeue().Split(' ');
                long ans = -1;

                try
                {
                    var trains = strings.Select(s => new Train(s)).ToList();
                    var trainSingle = trains.Where(t => t.Single).ToList();
                    trains = trains.Where(t => !t.Single).ToList();

                    // combine singles
                    trainSingle.Sort(Train.Compare);
                    var groups = trainSingle.GroupBy(t => t.Head);
                    foreach (var g in groups)
                    {
                        var item = g.First();
                        item.Count = Permute(g.Count());
                        trains.Add(item);
                    }

                    // combine all
                    for (int i = 0; i < trains.Count; i++)
                    {
                        for (int j = 0; j < trains.Count; j++)
                        {
                            if (j != i)
                            {
                                if (trains[i].Tail == trains[j].Head)
                                {
                                    var item = Train.Combine(trains[i], trains[j]);
                                    trains[i] = item;
                                    trains.RemoveAt(j);
                                    if (i > j)
                                    {
                                        i--;
                                    }
                                    j--;
                                }
                            }
                        }
                    }

                    // final check
                    var total = trains.Select(t =>
                        {
                            if (t.Single)
                            {
                                return new[] { t.Head };
                            }
                            else
                            {
                                return t.Internals.Concat(new[] { t.Head, t.Tail });
                            }
                        }).Aggregate((l, r) => l.Concat(r)).ToList();
                    if (total.Distinct().Count() != total.Count)
                    {
                        throw new InvalidOperationException();
                    }

                    // permute
                    ans = Permute(trains.Count);
                    foreach (var t in trains)
                    {
                        ans = (ans * t.Count) % Mod;
                    }
                }
                catch (InvalidOperationException)
                {
                    ans = 0;
                }

                outputs.AppendLine(string.Format("Case #{0}: {1}", x + 1, ans));
            }

            File.WriteAllText(@"../../B-small-attempt0.out", outputs.ToString());
        }

        static long Permute(int n)
        {
            long r = 1;
            for (int i = 1; i <= n; i++)
            {
                r = (r * i) % Program.Mod;
            }
            return r;
        }
    }

    public class Train
    {
        public char Head;
        public char Tail;
        public List<char> Internals;
        public bool Single;
        public long Count;

        public static string Reduce(string s)
        {
            if (s.Length >= 2)
            {
                var l = new StringBuilder();
                l.Append(s[0]);
                for (int i = 1; i < s.Length; i++)
                {
                    if (s[i] != s[i - 1])
                    {
                        l.Append(s[i]);
                    }
                }
                return l.ToString();
            }
            else
            {
                return s;
            }
        }

        public Train(string s)
        {
            s = Reduce(s);
            Head = s[0];
            Tail = s.Last();
            if (s.Length > 2)
            {
                Internals = s.Substring(1, s.Length - 2).ToList();
                if (Internals.Distinct().Count() != Internals.Count)
                {
                    throw new InvalidOperationException();
                }
            }
            else
            {
                Internals = new List<char>();
            }
            Single = (s.Length == 1);
            Count = 1;
        }

        // l and r should not equal
        public static Train Combine(Train l, Train r)
        {
            var s = l.Head.ToString() + r.Tail.ToString();
            var t = new Train(s);
            t.Internals = l.Internals.Concat(r.Internals).ToList();
            if (!l.Single && !r.Single)
            {
                t.Internals.Add(l.Tail);
            }
            if (t.Internals.Distinct().Count() != t.Internals.Count)
            {
                throw new InvalidOperationException();
            }
            t.Single = false;
            t.Count = (l.Count * r.Count) % Program.Mod;
            return t;
        }

        public static int Compare(Train l, Train r)
        {
            return l.Head - r.Head;
        }
    }
}
