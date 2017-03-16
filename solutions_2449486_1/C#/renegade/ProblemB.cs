using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GCJ
{
    class LawnMower
    {
        public static string Result(StreamReader sr)
        {
            int w, h;
            var fragments = sr.ReadLine().Trim().Split();
            h = Convert.ToInt32(fragments[0]); 
            w = Convert.ToInt32(fragments[1]);

            var g = new int[w, h];
            for (int y = 0; y < h; y++)
            {
                var line = sr.ReadLine().Trim().Split();
                for (int x = 0; x < w; x++)
                {
                    g[x, y] = Convert.ToInt32(line[x]);
                }
            }

            var rowMaxs = new int[h];
            var colMaxs = new int[w];
            for (int y = 0; y < h; y++)
            {
                for (int x = 0; x < w; x++)
                {
                    rowMaxs[y] = Math.Max(rowMaxs[y], g[x, y]);
                    colMaxs[x] = Math.Max(colMaxs[x], g[x, y]);
                }
            }

            for (int y = 0; y < h; y++)
            {
                for (int x = 0; x < w; x++)
                {
                    if (g[x,y] != rowMaxs[y] && g[x,y] != colMaxs[x]) return "NO";
                }
            }

            return "YES";
        }
    }

    class ProblemB
    {
        public ProblemB(StreamReader sr)
        {
            using (StreamWriter sw = new StreamWriter("outputB.txt"))
                Convert.ToInt32(sr.ReadLine().Trim()).Times(i =>
                {
                    var output = String.Format("Case #{0}: {1}", i + 1, LawnMower.Result(sr));
                    Console.Out.WriteLine(output);
                    sw.WriteLine(output);
                });
        }
    }
}
