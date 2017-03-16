using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace DancingGooglers
{
    class Program
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="br">best result</param>
        /// <param name="ll">lower limit (possible with suprise)</param>
        /// <param name="ul">upper limit (possible without suprise)</param>
        public static void GetLimits(int br, out int ll, out int ul)
        {
            if (br == 0)
            {
                ll = 0;
                ul = 0;
            }
            else if (br == 1)
            {
                ll = 1;
                ul = 1;
            }
            else
            {
                ul = 3 * br - 2;
                ll = 3 * br - 4;
            }
        }

        static void Main(string[] args)
        {
            using (var sr = new StreamReader("input.txt"))
            using (var sw = new StreamWriter("output.txt"))
            {
                var T = int.Parse(sr.ReadLine());
                for (int i = 1; i <= T; i++)
                {
                    var result = string.Empty;

                    var parts = sr.ReadLine().Split(' ');
                    var N = int.Parse(parts[0]);
                    var S = int.Parse(parts[1]);
                    var p = int.Parse(parts[2]);
                    var t = parts.Skip(3).Select(ti => int.Parse(ti)).ToArray();

                    int ul, ll;
                    var count = 0;
                    GetLimits(p, out ll, out ul);
                    foreach (var ti in t)
                    {
                        if (ti >= ul)
                            count++;
                        else if (ti >= ll && S > 0)
                        {
                            count++;
                            S--;
                        }
                    }

                    result = count.ToString();

                    sw.WriteLine("Case #{0}: {1}", i, result);
                }
            }

        }
    }
}
