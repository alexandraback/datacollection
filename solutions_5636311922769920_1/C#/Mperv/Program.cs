using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam_2016_Q_4_C_Sharp
{

    class Program
    {
        static Int64 Power(Int64 v, Int32 q)
        {
            if (q == 0) return 1;
            Int64 res = v;
            while (q > 1)
            {
                res *= v;
                q--;
            }
            return res;
        }


        private static Dictionary<Int64, Int64> cache = new Dictionary<Int64, Int64>();

        private static Int64 MakeKey(Int64 k, Int32 c, Int64 begin) {
            return k * 100000000 + c * 10000 + begin;
        }


        static Int64 Calc(Int64 k, Int32 c, Int64 begin)
        {
            Int64 key = MakeKey(k, c, begin);
            Int64 value;
            if (cache.TryGetValue(key, out value)) return value;


            if (c == 1) return begin % k;
//            if (c == 2) return begin * k + (begin + 1);
//            if (c == 3) return Calc(k, c - 1, begin) * k*k + Calc(k, c - 1, begin + 2);
//            if (c == 4) return Calc(k, c - 1, begin) * k * k * k + Calc(k, c - 1, begin + 4);

            value = Calc(k, c - 1, begin+1) * k + (begin % k);
            cache[key] = value;
            return value;
        }

        static String Solve(String str)
        {
            Int32[] v = str.Split(new char[] { ' ' }).Select(Int32.Parse).ToArray();
            Int32 k = v[0];
            Int32 c = v[1];
            Int32 s = v[2];

            Int64 perOneNumber = c;
            if (s * perOneNumber < k) return "IMPOSSIBLE";
            List<Int64> res = new List<Int64>();
            Int64 beg = 0;
            while (beg<k)
            {
                res.Add(Calc(k, c, beg)+1);
                beg += perOneNumber;
            }
            return String.Join(" ", res.ToArray());
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2016\Qualification\Task4_input\D-large.in");
            Int32 count = Int32.Parse(lines[0].Trim());
            for (Int32 i = 0; i < count; i++)
            {
                String res = Solve(lines[i + 1]);
                Console.WriteLine("Case #{0}: {1}", i + 1, res);
            }
        }
    }

}
