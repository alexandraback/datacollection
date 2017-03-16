using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Google.CodeJam.Y2013.Round1C
{
    class Program
    {
        static TextReader In = Console.In;
        static TextWriter Out = Console.Out;

        static void Main(string[] args)
        {
            //In = new StringReader("7\naaaxxxxxaaaa 3\naaaxxxxxaaaaaaaaaa 3\naaaxxxxxaxxxxxaaaa 3\nquartz 3\nstraight 3\ngcj 2\ntsetse 2");
            
            int t = In.ReadInt32();
            In.ReadLine();
            for( int i=1; i<=t; i++ )
                Out.WriteLine("Case #{0}: {1}", i, DoTestCase());
        }

        private static long DoTestCase()
        {
            var args = In.ReadLine().Split(' ');
            var s = args[0];
            var n = int.Parse(args[1]);
            int l = s.Length;

            var rr = ExtractRegions(s);

            long nvalue = 0;
            int start = 0;
            foreach(var r in rr)
            {
                if (r.Item2 >= n)
                {
                    var upper = l - r.Item1 - n + 1;
                    var lower = l - r.Item1 - r.Item2 + 1;
                    var len = upper - lower;
                    nvalue += upper*(r.Item1 - start + 1) + len*lower + len*(len - 1)/2;
                    start = r.Item1 + r.Item2 - n + 1;
                }
            }

            return nvalue;
        }

        private static IEnumerable<Tuple<int, int>> ExtractRegions(string s)
        {
            var rr = new List<Tuple<int, int>>();

            int rs = -1;
            for (int i = 0, l = s.Length; i < l; i++)
            {
                var c = s[i];
                if("aeiou".Contains(c)) // IsConsonant
                {
                    if (rs >= 0)
                    {
                        rr.Add(new Tuple<int, int>(rs, i-rs));
                        rs = -1;
                    }
                }
                else
                {
                    if( rs < 0 )
                        rs = i;
                }
            }
            if( rs >= 0 )
                rr.Add(new Tuple<int, int>(rs, s.Length-rs));

            return rr;
        }
    }
}
