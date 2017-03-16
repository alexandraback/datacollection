using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace a
{
    class Program
    {
        static HashMap<Tuple<int,int>,int> ab, bc, ca;
        static int a, b, c, d;

        static void Main(string[] args)
        {
            using (StreamWriter w = new StreamWriter(@"output-small1.txt"))
            {
                using (StreamReader r = new StreamReader(@"C-small-attempt1.in"))
                {
                    int t = int.Parse(r.ReadLine());
                    for (int i = 0; i < t; i++)
                    {
                        int[] abcd = r.ReadLine().Split().Select(int.Parse).ToArray();
                        a = abcd[0];
                        b = abcd[1];
                        c = abcd[2];
                        d = abcd[3];

                        ab = new HashMap<Tuple<int, int>, int>();
                        bc = new HashMap<Tuple<int, int>, int>();
                        ca = new HashMap<Tuple<int, int>, int>();

                        int ans = 0;
                        List<string> ls = new List<string>();

                        for (int z = 1; z <= c; z++)
                        {
                            for (int y = 1; y <= b; y++)
                            {
                                for (int x = 1; x <= a; x++)
                                {
                                    if (Able(x,y,z))
                                    {
                                        ans++;
                                        ls.Add(string.Join(" ", new int[]{ x,y,z}));
                                    }
                                }
                            }
                        }
                        
                        w.WriteLine("Case #{0}: {1}", i + 1, ans);
                        foreach (var item in ls)
                        {
                            w.WriteLine(item);
                        }
                    }
                }
            }
        }

        static bool Able(int x,int y,int z)
        {
            Tuple<int, int> xy = new Tuple<int, int>(x, y);
            Tuple<int, int> yz = new Tuple<int, int>(y, z);
            Tuple<int, int> zx = new Tuple<int, int>(z, x);
            if(ab[xy] >= d || bc[yz] >= d || ca[zx] >= d)
            {
                return false;
            }
            else
            {
                ab[xy]++;
                bc[yz]++;
                ca[zx]++;
                return true;
            }
        }
    }

    class HashMap<K, V> : Dictionary<K, V>
    {
        new public V this[K i]
        {
            get
            {
                V v;
                return TryGetValue(i, out v) ? v : base[i] = default(V);
            }
            set { base[i] = value; }
        }
    }
}
