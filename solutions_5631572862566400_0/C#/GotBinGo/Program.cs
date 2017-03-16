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
            var ki = new List<int>();
            g = g.Skip(1).ToList();

            for (var i = 0; i < tn; i++)
            {
                var tt = int.Parse(g.First());
                var ttt = g.Skip(1).Take(1);
                List<int> tttt = ttt.Select(x => x.Split().Select(y => int.Parse(y)).ToList()).ToList().SelectMany(x => x).ToList();
                t.Add(tttt);
                g = g.Skip(2).ToList();
            }

            for (var i = 0; i < tn; i++)
            {
                //var r = t[i].Select((x, k) => new { x = k+1, y = x }).ToList();
                var r = t[i];
                int a = 0, curr = 0;
                int cyc = 0;
                

                while (r.Where(x => x!=-1).Count() > 0)
                {
                    int cf = 0;
                    int looflag = 0;
                    int j;
                    for (j = 0; t[i][j] == -1; j++)
                    { }
                   
                   curr = j;

                    while (r.Count() > 0)
                    {
                        var n = r[curr];
                        if (n > 0)
                        {
                            if (r[r[curr] - 1] != -1)
                            {
                                a++;
                                cf = 1;
                            }
                            else
                                looflag = 1;
                         
                            r[curr] = -1;
                            curr = n - 1;
                        }
                        else
                            break;

                    }
                    if(cf == 1)
                        cyc++;

                    if (cyc == 1 && looflag == 1 && cf == 1)
                        a++;
                }
                if (cyc > 1)
                    a--;
                
                ki.Add(a);
            
            }
            
            File.WriteAllLines("a_ki.txt", ki.Select((x, i) => "Case #"+(i+1)+": " + String.Join(" ", x)).ToArray());

        }
    }
}

