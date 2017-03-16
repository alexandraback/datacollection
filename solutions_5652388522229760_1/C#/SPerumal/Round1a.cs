using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Round1a
    {
        static void Main(string[] args)
        {
            new Round1a().Run("A-large.in");
        }

        TextWriter sw;
        int caseNo = 1;
        internal void Run(string p)
        {
            using (var sr = File.OpenText(p))
            using (sw = File.CreateText("1a.out"))
            {
                Console.WriteLine(sr.ReadLine());

                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    sw.WriteLine("Case #{0}: {1}", caseNo++, Check(int.Parse(line)));
                }
            }
        }

        private string Check(long p)
        {
            int check = 0;

            var i = p;
            while (true)
            {
                var c = i;
                while (c > 0)
                {
                    check |= 1 << ((int)(c % 10));
                    c /= 10;
                }
                if (check == 0x03ff) return i.ToString();

                i += p;

                if (i == p)
                    return "INSOMNIA";
            }
        }
    }
}
