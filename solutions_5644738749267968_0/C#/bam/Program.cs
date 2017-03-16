using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualif4
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\forth2.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\forthOut2.txt");
            var total = long.Parse(file.ReadLine());
            for (long t = 1; t <= total; t++)
            {
                var nBlocks = int.Parse(file.ReadLine());
                var naomisBlocks = file.ReadLine().Split(' ').Select(x=>double.Parse(x)).ToList();
                naomisBlocks.Sort();

                var kensBlocks = file.ReadLine().Split(' ').Select(x => double.Parse(x)).ToList();
                kensBlocks.Sort();

                int naomiWarPoints = 0;

                var kensBlocksWar = new List<double>(kensBlocks);
                var naomisBlocksWar = new List<double>(naomisBlocks);
                for (int i = 0; i < nBlocks; i++ )
                {
                    double naomiChoise = naomisBlocksWar.Max();
                    var kenMaxBlocks = kensBlocksWar.Where(x => x > naomiChoise);
                    double kenChoise = kenMaxBlocks.Any() ? kenMaxBlocks.Min() : kensBlocksWar.Min();
                    if (!kenMaxBlocks.Any())
                        naomiWarPoints++;
                    naomisBlocksWar.Remove(naomiChoise);
                    kensBlocksWar.Remove(kenChoise);
                }

                int naomiDWarPoints = 0;
                for (int i = 0; i < nBlocks; i++)
                {
                    double kensChoise = kensBlocks.Min();
                    var naomiGoodBlocks = naomisBlocks.Where(x=>x>kensChoise);
                    double naomisChoise;
                    if (naomiGoodBlocks.Any())
                    {
                        naomiDWarPoints++;
                        naomisChoise = naomiGoodBlocks.Min();
                    }
                    else
                    {
                        naomisChoise = naomisBlocks.Min();
                    }
                    
                    naomisBlocks.Remove(naomisChoise);
                    kensBlocks.Remove(kensChoise);
                }

                outFile.WriteLine(string.Format("Case #{0}: {1} {2}", t, naomiDWarPoints, naomiWarPoints));
            }

            file.Close();
            outFile.Close();
        }
    }
}
