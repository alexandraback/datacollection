using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Googlerese
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
                        string result = p.Solve();
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
        private static readonly Dictionary<char, char> Tran = InitTran();

        private static Dictionary<char, char> InitTran()
        {
            var sample = new Dictionary<string, string>
                             {
                                 {"a zoo", "y qee"},
                                 {"our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi"},
                                 {"there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"},
                                 {"so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv"},
                             };
            var fl = new Dictionary<char, bool>();
            var tl = new Dictionary<char, bool>();

            for (char c = 'a'; c <= 'z'; c++)
            {
                fl[c] = false;
                tl[c] = false;
            }

            var tran = new Dictionary<char, char>();

            foreach (var s in sample)
            {
                var f = s.Key;
                var t = s.Value;
                var l = f.Length;
                for (int i = 0; i < l; i++)
                {
                    var fc = f[i];
                    var tc = t[i];
                    if (!tran.ContainsKey(tc))
                    {
                        tran[tc] = fc;
                        fl[fc] = true;
                        tl[tc] = true;
                    }
                }
            }
            var mf = fl.Where(m => !m.Value).Select(m => m.Key).ToArray();
            var mt = tl.Where(m => !m.Value).Select(m => m.Key).ToArray();
            if (mf.Length > 1)
                throw new Exception("Too many missing letters: " + string.Join(",", mf));
            if (mf.Length == 1)
                tran[mt[0]] = mf[0];
            return tran;
        }

        private readonly string _input;

        public Problem(StreamReader r)
        {
            _input = r.ReadLine();
        }

        public string Solve()
        {
            return _input.ToCharArray().Aggregate(new StringBuilder(_input.Length), (tr, c) => tr.Append(Tran[c])).ToString();
        }
    }
}
