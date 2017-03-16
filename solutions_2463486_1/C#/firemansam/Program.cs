using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace square
{
    class Program
    {
        static bool ispalin(ulong aa)
        {
            char[] tmp = Convert.ToString(aa).ToCharArray();
            for (int i = 0; i < tmp.Length / 2; i++)
            {
                if (tmp[i] != tmp[tmp.Length - 1 - i]) return false;
            }
            return true;
        }
        static void Main(string[] args)
        {
            UInt64 a, b, lb, hb;
            int n, ans;
            bool[] ye = new bool[10000050];
            string tmp = Console.ReadLine();
            n = Convert.ToInt32(tmp);
            for (ulong i = 1; i <= 10000000; i++)
            {
                if (!ispalin(i)) continue;
                if (ispalin(i * i)) ye[i] = true;
            }
            for (int tc = 1; tc <= n; tc++)
            {
                ans = 0;
                string[] nos = Console.ReadLine().Split(new char[] {' '});
                a = Convert.ToUInt64(nos[0]);
                b = Convert.ToUInt64(nos[1]);
                lb = (ulong)Math.Sqrt(a);
                hb = (ulong)Math.Sqrt(b);
                if (a > lb * lb) lb += 1;
                for (ulong i = lb; i <= hb; i++)
                {
                    if (ye[i]) ans++;
                }
                Console.WriteLine("Case #" + tc + ": " + ans);
            }
        }
    }
}
