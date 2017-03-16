using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class Block
    {
        public bool naomi = false;
        public double weight = 0.0;
        public bool avail = true;
    }

    class Program
    {

        static void Main(string[] args)
        {

            var root = @"D:\gcj\p4\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            int numCases = Int32.Parse(input[0]);

            double[] data = input.Reverse().Take(input.Length - 1).Reverse().SelectMany(x => x.Split(' ').Select(y => Double.Parse(y))).ToArray();
            IEnumerator<double> scanner = data.AsEnumerable<double>().GetEnumerator();
            scanner.MoveNext();

            double[] Naomi = new double[10000];
            double[] Ken = new double[10000];
            for (int nc = 0; nc < numCases; ++nc)
            {
                int N = (int)scanner.Current;
                scanner.MoveNext();
                List<Block> blocks = new List<Block>();
                for (int i = 0; i < N; ++i) { blocks.Add(new Block() { naomi = true, weight = scanner.Current }); scanner.MoveNext(); };
                for (int i = 0; i < N; ++i) { blocks.Add(new Block() { naomi = false, weight = scanner.Current }); scanner.MoveNext(); };

                blocks = blocks.OrderBy(x => x.weight).ToList();

                // War
                int warPoints = 0;
                for (int i = 0; i < blocks.Count; ++i)
                {
                    if (blocks[i].naomi)
                    {
                        blocks[i].avail = false;
                        bool found = false;
                        for (int j = i + 1; j < blocks.Count; ++j)
                        {
                            if (blocks[j].avail && !blocks[j].naomi) { blocks[j].avail = false; found = true;  break; }
                        }
                        if (!found)
                        {
                            warPoints++;
                        }
                    }
                }

                // DeceitfulWar
                int dwarPoints = 0;
                blocks.ForEach(x => x.avail = true);
                for (int i = 0; i < blocks.Count; ++i)
                {
                    if (blocks[i].naomi)
                    {
                        bool found = false;
                        for (int j = i - 1; j >= 0; --j)
                        {
                            if (blocks[j].avail && !blocks[j].naomi) { blocks[j].avail = false; found = true; break; }
                        }

                        if (found)
                        {
                            dwarPoints++;
                        }
                        else
                        {
                            for (int j = blocks.Count - 1; j > i; --j)
                            {
                                if (blocks[j].avail && !blocks[j].naomi) { blocks[j].avail = false; found = true; break; }
                            }
                            if (!found)
                            {
                                dwarPoints++;
                            }
                        }
                    }
                }

                output.WriteLine("Case #{0}: {1} {2}", nc + 1, dwarPoints, warPoints);

            }

            output.Close();

            Console.WriteLine(File.ReadAllText(root + "out.txt"));


            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }
    }
}
