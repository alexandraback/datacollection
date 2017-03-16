using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1
{
    public class Q3
    {
        public int N, M;
        public List<Tuple<long, long>> box;
        public List<Tuple<long, long>> toy;

        public void boxes(List<long> b)
        {
            box = new List<Tuple<long, long>>();
            for (int i = 0; i < N; i++)
                box.Add(new Tuple<long, long>(b[2 * i], b[2 * i + 1]));
        }

        public void toys(List<long> t)
        {
            toy = new List<Tuple<long, long>>();
            for (int i = 0; i < M; i++)
                toy.Add(new Tuple<long, long>(t[2 * i], t[2 * i + 1]));
        }

        public Q3()
        {
        }

        long result(int b, long mb, int t, long mt)
        {
            if (b == box.Count) return 0;
            if (t == toy.Count) return 0;

            if(box[b].Item2 == toy[t].Item2)
            {
                if (box[b].Item1 - mb > toy[t].Item1 - mt)
                    return toy[t].Item1 - mt + result(b, mb + toy[t].Item1 - mt, t + 1, 0);
                else
                    return box[b].Item1 - mb + result(b + 1, 0, t, mt + box[b].Item1 - mb);
            }

            long r1 = result(b + 1, 0, t, mt);
            long r2 = result(b, mb, t + 1, 0);
            return r1 > r2 ? r1 : r2;
        }

        public long Answer()
        {
            return result(0, 0, 0, 0);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var q = new Q3();
                var h = (from x in Console.ReadLine().Split(' ') select int.Parse(x)).ToList();
                q.N = h[0];
                q.M = h[1];
                q.boxes((from x in Console.ReadLine().Split(' ') select long.Parse(x)).ToList());
                q.toys((from x in Console.ReadLine().Split(' ') select long.Parse(x)).ToList());
                Console.WriteLine(string.Format("Case #{0}: {1}", t + 1, q.Answer()));
            }
        }
    }
}
