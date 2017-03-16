using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejama
{
    class Program
    {
        static void Main(string[] args)
        {
            var g = File.ReadAllLines("a.txt").ToList();
            var tn = int.Parse(g.First());
            var t = new List<List<int>>();
            var ki = new List<List<int>>();
            g = g.Skip(1).ToList();

            for (var i = 0; i < tn; i++)
            {
                var tt = int.Parse(g.First());
                var ttt = g.Skip(1).Take(tt * 2 - 1);
                List<int> tttt = ttt.Select(x => x.Split().Select(y => int.Parse(y)).ToList()).ToList().SelectMany(x => x).ToList();
                t.Add(tttt);
                 g = g.Skip(tt*2).ToList();
            }

            for (var i = 0; i < tn; i++)
            {
                var r = t[i].GroupBy(x => x).Select(x => new {n = x.Count(), k = x.Key }).Where(x=>x.n % 2 == 1).Select(x=>x.k).OrderBy(x=>x).ToList();
                ki.Add(r);

            }
            
            File.WriteAllLines("a_ki.txt", ki.Select((x, i) => "Case #"+(i+1)+": " + String.Join(" ", x)).ToArray());

        }
    }
}

