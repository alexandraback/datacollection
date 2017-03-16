using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Round1b
    {
        public static void Main(string[] args)
        {
            new Round1b().Run("B-small-attempt0.in");
        }

        private void Generate(string p)
        {
            using (var sw = File.CreateText(p))
            {
                var r = new Random();
                sw.WriteLine(100);
                sw.WriteLine("+++++++++++++++");
                for (int i = 1; i < 100; i++)
                {
                    for (int j = 0; j < 100; j++)
                        sw.Write(r.Next(0, 2) == 0 ? '+' : '-');
                    sw.WriteLine();
                }
            }

        }

        TextWriter sw;
        int caseNo = 1;
        internal void Run(string p)
        {
            using (var sr = File.OpenText(p))
            using (sw = File.CreateText("1b.out"))
            {
                Console.WriteLine(sr.ReadLine());

                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    sw.WriteLine("Case #{0}: {1}", caseNo++, Check(line));
                }
            }
        }

        private object Check(string line)
        {
            var last = line[0];
            int groups = 0;
            foreach (var c in line)
            {
                if (c != last)
                {
                    groups++;
                    last = c;
                }
            }
            if (last == '-') groups++;

            return groups;
        }
    }
}
