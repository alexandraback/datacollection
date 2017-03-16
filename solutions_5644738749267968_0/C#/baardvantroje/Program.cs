using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeceitfulWar
{
    class Program
    {
        string inFilePath, outFilePath;
        
        static void Main(string[] args)
        {
            Program p;
            DateTime begin;

            p = new Program("C:\\gcj\\D-small-attempt3.in", "C:\\gcj\\D-small-attempt3.out");
            begin = DateTime.Now;
            p.Solve();
            Console.WriteLine("Solved sample input in {0:F4} seconds.", (DateTime.Now - begin).TotalSeconds);

            Console.WriteLine("{0}Press any key to exit.", Environment.NewLine);
            Console.ReadLine();
        }

        public Program (string inFilePath, string outFilePath)
        {
            this.inFilePath = inFilePath;
            this.outFilePath = outFilePath;
        }

        public void Solve()
        {
            using (StreamReader inStream = new StreamReader(inFilePath))
            using (StreamWriter outStream = new StreamWriter(outFilePath))
            {
                int numProblems = int.Parse(inStream.ReadLine());

                for (int i = 0; i < numProblems; i++)
                {
                    var numBlocks = int.Parse(inStream.ReadLine());

                    List<double> blocksNaomiDWar = new List<double>();
                    List<double> blocksNaomiWar = new List<double>();
                    foreach (string s in inStream.ReadLine().Split(' '))
                    {
                        blocksNaomiDWar.Add(double.Parse(s));
                        blocksNaomiWar.Add(double.Parse(s));
                    }

                    List<double> blocksKenDWar = new List<double>();
                    List<double> blocksKenWar = new List<double>();
                    foreach (string s in inStream.ReadLine().Split(' '))
                    {
                        blocksKenDWar.Add(double.Parse(s));
                        blocksKenWar.Add(double.Parse(s));
                    }

                    outStream.WriteLine("Case #{0}: {1} {2}", (i + 1), solveCaseDWar(blocksNaomiDWar, blocksKenDWar),
                        solveCaseWar(blocksNaomiWar, blocksKenWar));
                }
            }
        }

        private int solveCaseDWar(List<double> blocksNaomi, List<double> blocksKen)
        {
            var initLength = blocksNaomi.Count;
            var result = 0;

            for (int i = 0; i < initLength; i++ )
            {
                double blockNaomi = popBlockNaomiDWar(ref blocksNaomi, blocksKen);
                double blockKen = popBlockKen(blockNaomi, ref blocksKen);

                if (blockNaomi > blockKen)
                    result++;
            }

            return result;
        }


        private int solveCaseWar(List<double> blocksNaomi, List<double> blocksKen)
        {
            var initLength = blocksNaomi.Count;
            var result = 0;

            for (int i = 0; i < initLength; i++)
            {
                double blockNaomi = popBlockNaomiWar(ref blocksNaomi);
                double blockKen = popBlockKen(blockNaomi, ref blocksKen);

                if (blockNaomi > blockKen)
                    result++;
            }

            return result;
        }

        private double popBlockNaomiDWar(ref List<double> blocksNaomi, List<double> blocksKen)
        {
            double blockNaomi;
            double demeanorNaomi = 0;
            
            var kensLightest = blocksKen.OrderBy(x => x).First();
            var kensHeaviest = blocksKen.OrderByDescending(x => x).First();

            // find Naomi's lightest block to outweigh Ken's lightest
            // and pretend it to be the heaviest in play
            IEnumerable<double> outweighKensLightest = blocksNaomi.Where(x => x > kensLightest);
            if (outweighKensLightest.Count() != 0)
            {
                blockNaomi = outweighKensLightest.OrderBy(x => x).First();
                demeanorNaomi = kensHeaviest + 0.0000001;
            }

            // otherwise pretend Naomi's lightest to be second only to
            // the (Ken's) heaviest in play
            else
            {
                blockNaomi = blocksNaomi.OrderBy(x => x).First();
                demeanorNaomi = kensHeaviest - 0.0000001;
            }

            blocksNaomi.Remove(blockNaomi);
            return demeanorNaomi;
        }

        private double popBlockNaomiWar(ref List<double> blocksNaomi)
        {
            double blockNaomi = blocksNaomi.OrderBy(x => x).First();
            blocksNaomi.Remove(blockNaomi);
            return blockNaomi;
        }

        private double popBlockKen(double blockNaomi, ref List<double> blocksKen)
        {
            double blockKen;

            if (blockNaomi > blocksKen.Max())
                blockKen = blocksKen.Min();
            else
                blockKen = blocksKen.Where(x => x >= blockNaomi).OrderBy(x => x).First();

            blocksKen.Remove(blockKen);

            return blockKen;
        }
    }
}
