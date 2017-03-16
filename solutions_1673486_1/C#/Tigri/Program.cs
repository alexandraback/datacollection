using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace Pass
{
    class Program
    {
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
                        double result = p.Solve();
                        Console.WriteLine("Case #{0}: {1}", i, result.ToString("F6", CultureInfo.InvariantCulture));
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
        internal static int[] ReadIntArray(StreamReader r)
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

        internal static double[] ReadDoubleArray(StreamReader r)
        {
            var line = r.ReadLine();
            if (line == null)
                return null;
            var sa = line.Split(' ');
            var ia = new double[sa.Length];
            for (int i = 0; i < sa.Length; i++)
                ia[i] =  double.Parse(sa[i], CultureInfo.InvariantCulture);
            return ia;

        }

        private int _a;
        private int _b;
        double[] _p;

        public Problem(StreamReader r)
        {
            var l1 = ReadIntArray(r);
            _a = l1[0];
            _b = l1[1];
            _p = ReadDoubleArray(r);
        }

        public double Solve()
        {
            var ea = new double[_a + 2];
            int i;
            ea[_a] = _a + _b + 1;
            ea[_a + 1] = 2 + _b;
            var pck = new double[_a];

            pck[0] = _p[0];

            for (i = 1; i < _a; i++)
            {
                pck[i] = _p[i]*pck[i - 1];
            }

            for (i = 0; i < _a; i++)
            {
                int c = 2*i + _b - _a + 1;
                int w = c + _b + 1;
                double pc = pck[_a - i - 1];
                double pw = 1.0 - pc;
                ea[i] = c*pc + w*pw;

            }
            return ea.Min();
        }
    }
}
