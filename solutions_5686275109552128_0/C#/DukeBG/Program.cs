using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam02
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in.txt");
            FileStream fsOut = new FileStream("out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fsOut);
            sw.AutoFlush = true;
            int testCount = int.Parse(sr.ReadLine());
            for (int i = 0; i < testCount; i++)
            {
                sw.Write(string.Format("Case #{0}: ", i + 1));

                int d = int.Parse(sr.ReadLine());
                List<int> p = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();

                int res = getOptimalRounds(p);
                sw.WriteLine(res);
            }
            fsOut.Close();

        }

        static int getOptimalRounds(List<int> p)
        {
            int max = p.Max();
            int waveMax = max;
            for(int i = max / 2; i > 1; i--)
            {
                List<int> pmod = new List<int>(p.Count + 1);
                pmod.AddRange(p);
                pmod.Remove(max);
                pmod.Add(i);
                pmod.Add(max - i);

                int testMax = 1 + getOptimalRounds(pmod);
                if (testMax < waveMax)
                    waveMax = testMax;
                if (testMax > max)
                    break;
            }

            return Math.Min(max, waveMax);
        }
    }
}
