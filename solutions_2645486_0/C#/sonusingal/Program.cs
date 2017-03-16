using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace googleContest2
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader(@"C:\Users\Sonu\Desktop\Contest\Google\2\B-small-attempt1.in");
            var sw = new StreamWriter(@"C:\Users\Sonu\Desktop\Contest\Google\2\B-small-attempt1_output.in", true);
            sw.AutoFlush = true;
            var count = int.Parse(sr.ReadLine().Trim());
            for (var i = 0; i < count; i++)
            {
                var line = sr.ReadLine().Split(' ');
                var line2 = sr.ReadLine().Split(' ');
                var list = new List<int>(line2.Select(x=>int.Parse(x)));
                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, GetMaxGain(int.Parse(line[0]), int.Parse(line[1]), int.Parse(line[2]), list)));
            }
        }

        static int GetMaxGain(int E, int R, int n, List<int> list)
        {
            var ce = E;
            var gain = 0;
            var eList = new List<int>(n);
            list.ForEach(x => eList.Add(0));
            var m = list.Max();
            var index = list.IndexOf(m);
            eList[index] = E;

            for (var i = index-1; i >=0; i--)
            {
                if (eList[i + 1] == E) eList[i] = R;
                else if (i >= 1)
                {
                    if (list[i - 1] > list[i]) eList[i] = R;
                    else eList[i] = E; 
                }
                else eList[i] = E;
            }

            for (var i = index + 1; i < n; i++)
            {
                if (eList[i -1] == E) eList[i] = R;
                else if (i < n-1)
                {
                    if (list[i + 1] > list[i]) eList[i] = R;
                    else eList[i] = E;
                }
                else eList[i] = E;
            }

            for (var i = 0; i < n; i++) gain += list[i] * eList[i];
            return gain;
        }
    }
}
