using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader("B-large.in");
            var sw = new StreamWriter("output.txt");

            int T = int.Parse(sr.ReadLine());

            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(sr.ReadLine());
                int col = 2 * N -1;
                Dictionary<int, int> intDIct = new Dictionary<int, int>();
                List<int> oddIntList = new List<int>();

                List<int> intList = new List<int>();

                for (int i = 0; i < col; i++)
                {
                    var splits = sr.ReadLine().Split(' ').ToList();
                    foreach (var str in splits)
                    {
                        int val = int.Parse(str);
                        if (!intDIct.ContainsKey(val))
                            intDIct.Add(val, 0);
                        intDIct[val]++;
                    }
                }
                string output = "";
                foreach (var kv in intDIct.OrderBy(x => x.Key))
                {
                    if (kv.Value % 2 == 1)
                        output += kv.Key.ToString() + " ";
                }
                
                sw.WriteLine("Case #" + t.ToString() + ": " + output.Trim());
            }
            sr.Close();
            sw.Close();
        }
    }
}
