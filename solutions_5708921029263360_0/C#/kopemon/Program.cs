using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    public static class MyExtensions
    {
        public static bool NextPermutation<T>(this List<T> perm) where T : IComparable
        {
            int end = perm.Count() - 1;
            if (end <= 0) return false;

            int last = end;
            while (true)
            {
                int pos = last--;
                if (perm[last].CompareTo(perm[pos]) < 0)
                {
                    int i = end + 1;
                    while (perm[last].CompareTo(perm[--i]) >= 0) { }
                    var tmp = perm[last]; perm[last] = perm[i]; perm[i] = tmp;
                    perm.Reverse(pos, end - pos + 1);
                    return true;
                }
                if (last == 0)
                {
                    perm.Reverse();
                    return false;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string input = "../../C-small-attempt2.in";

            using (TextReader tr = new StreamReader(input))
            using (TextWriter tw = new StreamWriter(input.Replace(".in", ".out.txt")))
            {
                int T = int.Parse(tr.ReadLine());
                for (int _c = 1; _c <= T; _c++)
                {
                    //TODO
                    var line = tr.ReadLine().Split(' ').Select(int.Parse).ToList();
                    int J = line[0], P = line[1], S = line[2], K = line[3];

                    HashSet<string> all = new HashSet<string>();
                    Dictionary<string, int> jp = new Dictionary<string, int>();
                    Dictionary<string, int> js = new Dictionary<string, int>();
                    Dictionary<string, int> ps = new Dictionary<string, int>();

                    for (int j = 1; j <= J; j++)
                    {
                        for (int p = 1; p <= P; p++)
                        {
                            for (int s = 1; s <= S; s++)
                            {
                                string s_all = $"{j} {p} {s}";
                                string s_jp = $"{j} {p}";
                                string s_js = $"{j} {s}";
                                string s_ps = $"{p} {s}";

                                if (jp.ContainsKey(s_jp))
                                {
                                    if (jp[s_jp] >= K) continue;
                                }

                                if (js.ContainsKey(s_js))
                                {
                                    if (js[s_js] >= K) continue;
                                }

                                if (ps.ContainsKey(s_ps))
                                {
                                    if (ps[s_ps] >= K) continue;
                                }
                                all.Add(s_all);
                                jp[s_jp] = jp.ContainsKey(s_jp) ? jp[s_jp] + 1 : 1;
                                js[s_js] = js.ContainsKey(s_js) ? js[s_js] + 1 : 1;
                                ps[s_ps] = ps.ContainsKey(s_ps) ? ps[s_ps] + 1 : 1;
                            }
                        }
                    }

                    //var ans = all.Count().ToString() + "\r\n" + string.Join("\r\n", all);
                    Console.WriteLine($"Case #{_c}: {all.Count()}");
                    tw.WriteLine($"Case #{_c}: {all.Count()}");
                    foreach(var s in all)
                    {
                        Console.WriteLine(s);
                        tw.WriteLine(s);
                    }
                }
            }
        }
    }
}
