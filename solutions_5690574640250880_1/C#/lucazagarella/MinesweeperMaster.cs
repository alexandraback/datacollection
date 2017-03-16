using System;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;

namespace GoogleCodeJam2014
{
    public class MinesweeperMaster
    {
        //private const string filename = "C-sample";
        //private const string filename = "C-small";
        private const string filename = "C-large";

        public static void Run()
        {
            var lines = File.ReadAllLines(filename+".in");
            var file = new StreamWriter(filename + ".out");
            var T = int.Parse(lines[0]);

            for (int i = 0; i < T; i++)
            {
                var line = lines[1 + i];
                //line = "2 3 5";
                var values = line.Split(' ').Select(s => int.Parse(s, CultureInfo.InvariantCulture.NumberFormat)).ToArray();
                int R = values[0];
                int C = values[1];
                int M = values[2];
                var g = R * C - M;
                int max = Math.Max(R, C);
                int min = Math.Min(R, C);
                var resX = Result(g, min,max);
                file.WriteLine("Case #" + (i + 1) + ":");
                if (resX == null)
                {
                    file.WriteLine("Impossible");
                    continue;
                }

                var res = (R <= C) ? resX : Rotate(resX, min, max);
                for (int a = 0; a < res.Length; a++)
                {
                    int re = res[a];
                    string row = ((a==0)?"c":"").PadRight(re, '.').PadRight(C, '*');
                    file.WriteLine(row);
                }
            }

            file.Close();
        }

        public static int[] Rotate(int[] val, int min, int max)
        {
            var res = new int[max];
            for (int i = 0; i < max; i++)
            {
                res[i] = val.Count(x => x > i);
            }
            return res;
        }
        
        public static int[] Result(int g, int min, int max)
        {
            
            if (min==1)
            {
                return new[]{g};
            }
            if (g==1)
            {
                var res = new int[min];
                res[0] = 1;
                return res;
            }
            if(g==min*max)
            {
                var res = new int[min];
                for (int i = 0; i < min; i++)
                {
                    res[i] = max;
                }
                return res;

            }
            Debug.Assert(min<=max);
            for (int k = max; k > 1; k--)
            {
                var res = new int[min];
                if (g<k*2 || g>k*min)
                {
                    continue;
                }
                
                int div = g / k;

                for (int i = 0; i < div; i++)
                {
                    res[i] = k;
                }
                int mod = g % k;
                if (mod==1)
                {
                    if(res[div-1]>2 && div>2)
                    {
                        res[div-1]--;
                        mod++;
                    }
                    else
                    {
                     continue;   
                    }

                }

                
                if (mod > 0 && div < min) res[div] = mod;


                return res;
            }
            
            return null;
        }

    }
}
