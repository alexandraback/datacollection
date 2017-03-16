using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam1cc
{
    class Program
    {
        static readonly string small = "small.txt";
        static readonly string large = "large.txt";
        static void Main(string[] args)
        {
            Problem(small);
        }

        static void Problem(string file)
        {
            using (var fsi = new FileStream(file, FileMode.Open))
            {
                using (var sr = new StreamReader(fsi))
                {
                    var fspl = file.Split('.');
                    using (var fso = new FileStream(fspl[0] + "-output." + fspl[1], FileMode.Create))
                    {
                        using (var sw = new StreamWriter(fso))
                        {
                            int T = int.Parse(sr.ReadLine());
                            for (int i = 1; i <= T; i++)
                            {
                                var line = sr.ReadLine().Split(' ').Select(int.Parse).ToArray<int>();
                                int J = line[0];
                                int P = line[1];
                                int S = line[2];
                                int K = line[3];
                                List<string> list = new List<string>();
                                Dictionary<int, int> jp = new Dictionary<int, int>();
                                Dictionary<int, int> js = new Dictionary<int, int>();
                                Dictionary<int, int> ps = new Dictionary<int, int>();
                                for (int j = 1; j <= J; j++)
                                {
                                    for (int p = 1; p <= P; p++)
                                    {
                                        int keyjp = 100 * j + p;
                                        if (jp.ContainsKey(keyjp) && jp[keyjp] >= K) continue;

                                        for (int s = 1; s<=S; s++)
                                        {
                                            if (jp.ContainsKey(keyjp) && jp[keyjp] >= K) continue;
                                            int keyjs = 100 * j + s;
                                            int keyps = 100 * p + s;
                                            if (js.ContainsKey(keyjs) && js[keyjs] >= K) continue;
                                            if (ps.ContainsKey(keyps) && ps[keyps] >= K) continue;
                                            list.Add(string.Format("{0} {1} {2}", j, p, s));
                                            if (!js.ContainsKey(keyjs)) js[keyjs] = 0;
                                            if (!jp.ContainsKey(keyjp)) jp[keyjp] = 0;
                                            if (!ps.ContainsKey(keyps)) ps[keyps] = 0;
                                            js[keyjs]++;
                                            jp[keyjp]++;
                                            ps[keyps]++;
                                        }
                                    }
                                }
                                sw.WriteLine("Case #{0}: {1}", i, list.Count());
                                for (int l = 0; l < list.Count; l++)
                                {
                                    sw.WriteLine(list[l]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
