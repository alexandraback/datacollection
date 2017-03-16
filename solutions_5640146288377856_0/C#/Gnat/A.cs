using System;
using System.IO;
using System.Linq;

namespace _2015
{
    internal class Program
    {
        private static void Solve(int caseNo, StreamReader sr, StreamWriter sw)
        {
            var m = Array.ConvertAll(sr.ReadLine().Split(' '), int.Parse);
            var rows = m[0];
            var col = m[1];
            var w = m[2];

            Console.WriteLine("Case #{0}: {1}", caseNo, col/w * rows + (w - 1) + (col % w != 0 ? 1 : 0));
            sw.WriteLine("Case #{0}: {1}", caseNo, col / w * rows + (w - 1) + (col % w != 0 ? 1 : 0));
        }

        private static void Main(string[] args)
        {
            var file = args[0];
            var sr = new StreamReader(new FileStream(file + ".in", FileMode.Open, FileAccess.Read));
            var sw = new StreamWriter(new FileStream(file + ".out", FileMode.OpenOrCreate, FileAccess.Write));
            var maxCase = Convert.ToInt32(sr.ReadLine());

            var caseNo = 1;
            while (caseNo <= maxCase)
            {
                Solve(caseNo, sr, sw);
                caseNo++;
            }

            sr.Close();
            sw.Close();
        }
    }
}
