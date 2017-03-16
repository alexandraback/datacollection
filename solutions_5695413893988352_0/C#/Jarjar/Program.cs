using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2
{
    class Program
    {
        static readonly string small = "small.txt";
        static readonly string large = "large.txt";
        static void Main(string[] args)
        {
            Problem(small);
        }

        static void Problem(string file)
        {
            using (var fsi = new FileStream(file, FileMode.Open))
            {
                using (var sr = new StreamReader(fsi))
                {
                    var fspl = file.Split('.');
                    using (var fso = new FileStream(fspl[0] + "-output." + fspl[1], FileMode.Create))
                    {
                        using (var sw = new StreamWriter(fso))
                        {
                            int T = int.Parse(sr.ReadLine());
                            for (int i = 1; i <= T; i++) {
                                var line = sr.ReadLine().Split(' ');
                                sw.WriteLine("Case #{0}: {1}", i, findsmall(line[0], line[1]));
                                    }
                        }
                    }
                }
            }
        }

        static string findsmall(string c, string j)
        {
            string nc, nj;
            List<int> possC = new List<int>();
            List<int> possJ = new List<int>();
            int max = 1;
            for (int i = 0; i < c.Length; i++) max *= 10;
            for (int i = 0; i < max; i++)
            {
                string comp = string.Format(i.ToString("D" + c.Length));
                if (match(comp, c)) possC.Add(i);
                if (match(comp, j)) possJ.Add(i);
            }
            int maxi = 3 * max;
            int minC = 3 * max;
            int minJ = 3 * max;

            foreach ( int i1 in possC)
            {
                foreach (int i2 in possJ)
                {
                    int diff = i1 > i2 ? i1 - i2 : i2 - i1;
                    if (diff < maxi)
                    {
                        maxi = diff;
                        minC = i1;
                        minJ = i2;
                        continue;
                    }
                    if (diff == maxi && i1 < minC)
                    {
                        minC = i1;
                        minJ = i2;
                        continue;
                    }
                    if (diff == maxi && i1 == minC && i2 < minJ)
                    {
                        minJ = i2;
                    }
                }
            }
            nc = minC.ToString("D" + c.Length);
            nj = minJ.ToString("D" + c.Length);
            return string.Format("{0} {1}", nc, nj);
        }
        static bool match(string a, string b)
        {
            bool isMatch = true;
            for (int i = 0; i < a.Length; i++)
            {
                if (a[i] == '?' || b[i] == '?') continue;
                if (a[i] == b[i]) continue;
                isMatch = false;
                break;
            }
            return isMatch;
        }

        static string find (string c, string j)
        {
            int i = 0;
            bool start = true;
            while (i < c.Length && c[i] == '?' && j[i] == '?')
            {
                i++;
            }
            if (i == c.Length)
            {
                c = c.Replace('?', '0');
                j = j.Replace('?', '0');
                return string.Format("{0} {1}", c, j);
            }
            if (i > 0)
            {

            }

            return string.Format("{0} {1}",c, j);
        }
    }
}
