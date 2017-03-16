using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj14qr
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\D-large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\D-large.out");
            for (int a = 0; a < t; a++)
            {
                int num = int.Parse(lines[idx++]);
                string[] line= lines[idx++].Split(' ');
                List<double> nam = line.ToList().ConvertAll(x => double.Parse(x));
                string[] line2 = lines[idx++].Split(' ');
                List<double> ken = line2.ToList().ConvertAll(x => double.Parse(x));
                nam.Sort();
                ken.Sort();
                tw.WriteLine("Case #{0}: {1} {2}", a + 1, WinCount(ken, nam), num - WinCount(nam,ken));
            }
            tw.Close();
        }

        public static int WinCount(List<double> one, List<double> two)
        {
            int i1 = 0;
            int i2 = 0;
            int winCount = 0;
            while (i1 < one.Count)
            {
                while (i2 < two.Count && two[i2] < one[i1])
                {
                    i2++;
                }
                if (i2 == two.Count)
                {
                    break;
                }
                winCount++;
                i2++;
                i1++;
            }
            return winCount;
        }
    }
}
