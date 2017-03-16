using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{


    class Program
    {
        static void Main(string[] args)
        {
            thisIsWar war = new thisIsWar();
            war.solve();
        }
    }

    class thisIsWar
    {
        public void solve()
        {
            string result = string.Empty;
            string inputFile = @"C:\Users\dante\Desktop\Google CodeJam 2014\QualificationRound\QualificationRound\input.txt";


            string[] lines = File.ReadAllLines(inputFile);
            int totalRowCounter = 0;

            int testCases = Int32.Parse(lines[totalRowCounter++]);

            for (int i = 0; i < testCases; i++)
            {

                int numberOfBlocks = Int32.Parse(lines[totalRowCounter++]);

                List<double> naomisBlocksWar = lines[totalRowCounter].Split(' ').Select(double.Parse).ToList();
                List<double> naomisBlocksDeceit = lines[totalRowCounter++].Split(' ').Select(double.Parse).ToList();
                List<double> kensBlocksWar = lines[totalRowCounter].Split(' ').Select(double.Parse).ToList();
                List<double> kensBlocksDeceit = lines[totalRowCounter++].Split(' ').Select(double.Parse).ToList();

                naomisBlocksWar.Sort(); kensBlocksWar.Sort();
                naomisBlocksDeceit.Sort(); kensBlocksDeceit.Sort();


                int warScore = 0;
                int deceitWarScore = 0;

                for (int j = 0; j < numberOfBlocks; j++)
                {
                    if (naomisBlocksWar.Last() > kensBlocksWar.Last())
                    {
                        warScore++;
                        naomisBlocksWar.Remove(naomisBlocksWar.Last());
                        kensBlocksWar.Remove(0);
                    }
                    else
                    {
                        kensBlocksWar.Remove(kensBlocksWar.First(x => x > naomisBlocksWar.Last()));
                        naomisBlocksWar.Remove(naomisBlocksWar.Last());
                    }

                    if (naomisBlocksDeceit.Last() < kensBlocksDeceit.Last())
                    {
                        naomisBlocksDeceit.Remove(0);
                        kensBlocksDeceit.Remove(kensBlocksDeceit.Last());
                    }
                    else
                    {
                        deceitWarScore++;
                        naomisBlocksDeceit.Remove(naomisBlocksDeceit.Last());
                        kensBlocksDeceit.Remove(kensBlocksDeceit.Last());
                    }

                }


                result += String.Format("Case #{0}: {1} {2}\n", i + 1, deceitWarScore, warScore);
            }


            string outputFile = @"C:\Users\dante\Desktop\Google CodeJam 2014\QualificationRound\QualificationRound\output.txt";
            File.WriteAllText(outputFile, result);

            Console.WriteLine("Success!");
            Console.Read();
        }

    }
}
