using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader("C:\\Users\\Brenton\\Desktop\\cj\\B-large(1).in"))
            using (var sw = new StreamWriter("C:\\Users\\Brenton\\Desktop\\cj\\B-large(1).out"))
            {
                var lines = Int32.Parse(sr.ReadLine());
                for (int i = 1; i <= lines; i++)
                {
                    var people = Int32.Parse(sr.ReadLine());
                    //var rows = new int[(2 * people) - 1, people];
                    var dict = new Dictionary<int, int>();

                    for (int x = 0; x < (2 * people) - 1; x++)
                    {
                        var p = sr.ReadLine().Split(' ');

                        for (int t = 0; t < p.Length; t++)
                        {
                            var integer = Int32.Parse(p[t]);

                            if (dict.ContainsKey(integer))
                            {
                                dict[integer]++;
                            }
                            else
                            {
                                dict[integer] = 1;
                            }
                        }
                    }

                    var needsVals = dict.Where(d => (d.Value % 2 != 0)).Select(d => d.Key).ToList();
                    needsVals.Sort();

                    sw.WriteLine("Case #" + i + ": " + string.Join(" ", needsVals));
                }
            }
        }
    }
}
