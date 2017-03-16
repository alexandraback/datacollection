using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Dancing
{
    class Program
    {
        static int[] ReadIntArray(StreamReader r)
        {
            var line = r.ReadLine();
            if (line == null)
                return null;
            var sa = line.Split(' ');
            var ia = new int[sa.Length];
            for (int i = 0; i < sa.Length; i++)
                ia[i] = int.Parse(sa[i]);
            return ia;

        }

        static int Main(string[] args)
        {
            try
            {
                using (var r = new StreamReader(args[0]))
                {
                    int t = int.Parse(r.ReadLine());
                    for (int i = 1; i <= t; i++)
                    {
                        var p = new Problem(r);
                        int result = p.Solve();
                        Console.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception");
                Console.WriteLine(ex);
                return -1;
            }
            return 0;
        }
    }

    internal class Problem
    {
        private int _n;
        private int _s;
        private int _p;
        private int[] _t;

        public Problem(StreamReader r)
        {
            var line = r.ReadLine();
            if (line == null)
                return;
            
            string[] sa = line.Split(' ');
            _n = int.Parse(sa[0]);
            _s = int.Parse(sa[1]);
            _p = int.Parse(sa[2]);
            
            _t = new int[_n];
            for (int i = 0; i < _n; i++)
                _t[i] = int.Parse(sa[3 + i]);
        }

        public int Solve()
        {
            int max = 0;
            int left = _s;
            for (int i = 0; i < _n; i++)
            {
                int t = _t[i];
                int b = (t + 2)/3;
                int bs = ((t >= 2) && (t <= 28) && ((t % 3) != 1)) ? (b + 1) : b;
                if (b >= _p)
                {
                    max++;
                }
                else if ((bs >= _p) && (left > 0))
                {
                    max++;
                    left--;
                }
            }

            return max;
        }
    }
}
