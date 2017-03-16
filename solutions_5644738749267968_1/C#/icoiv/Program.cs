using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace D
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string inputFilename = "D-large.in"; //args[0];
            string outputFilename = Path.ChangeExtension(inputFilename, "out");

            using (var input = new StreamReader(File.OpenRead(inputFilename)))
            using (var output = new StreamWriter(File.Open(outputFilename, FileMode.Create)))
            {
                int T = int.Parse(input.ReadLine());

                for (int tc = 1; tc <= T; ++tc)
                {
                    int count = int.Parse(input.ReadLine());
                    var naomi = input.ReadLine().Split(' ').Select(double.Parse);
                    var ken = input.ReadLine().Split(' ').Select(double.Parse);

                    var naomiWinsFair = Player2Wins(ken, naomi);
                    var kenWinsFair = Player2Wins(naomi, ken);
                    var naomiWinsFaul = count - kenWinsFair;

                    output.WriteLine("Case #{0}: {1} {2}", tc, naomiWinsFaul, naomiWinsFair);
                }
            }
        }

        private static int Player2Wins(IEnumerable<double> player1, IEnumerable<double> player2)
        {
            List<double> list = player1.OrderBy(x=>x).ToList();
            int player2Wins = 0;

            foreach (double n in player2.OrderBy(x => x))
            {
                int idx = ~list.BinarySearch(n); // all blocks have different weight!
                if (idx < list.Count)
                {
                    list.RemoveAt(idx);
                }
                else
                {
                    list.RemoveAt(0);
                    player2Wins++;
                }
            }
            return player2Wins;
        }
    }
}