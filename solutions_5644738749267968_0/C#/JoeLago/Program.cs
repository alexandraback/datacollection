using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Template
{
    class Program
    {
        static String runCase(StreamReader inputReader)
        {
            int cardCount = Int32.Parse(inputReader.ReadLine());
            double[] player1CardsArray = inputReader.ReadLine().Split(' ').Select(n => Convert.ToDouble(n)).ToArray();
            double[] player2CardsArray = inputReader.ReadLine().Split(' ').Select(n => Convert.ToDouble(n)).ToArray();

            Array.Sort(player1CardsArray);
            Array.Sort(player2CardsArray);
            List<double> p1cardsDeceit = new List<double>(player1CardsArray);
            List<double> p2cardsDeceit = new List<double>(player2CardsArray);

            List<double> p1cardsReg = new List<double>(player1CardsArray);
            List<double> p2cardsReg = new List<double>(player2CardsArray);

            int p1WinsDeceitOptimal = 0;
            for (int i = 0; i < cardCount; i++)
            {
                if (p1cardsDeceit[0] > p2cardsDeceit[0])
                {
                    p1WinsDeceitOptimal++;
                    p1cardsDeceit.RemoveAt(0);
                    p2cardsDeceit.RemoveAt(0);
                }
                else
                {
                    p1cardsDeceit.RemoveAt(0);
                    p2cardsDeceit.RemoveAt(p2cardsDeceit.Count - 1);
                }
            }

            int p1WinsOptimal = cardCount;
            for (int i = 0; i < cardCount; i++)
            {
                double p1Value = p1cardsReg[0];
                p1cardsReg.RemoveAt(0);

                int p2CardIndex = 0;
                for (int j = 0; j < p2cardsReg.Count; j++)
                {
                    if (p2cardsReg[j] > p1Value)
                    {
                        p2CardIndex = j;
                        p1WinsOptimal--;
                        break;
                    }
                }

                p2cardsReg.RemoveAt(p2CardIndex);
            }

            return "" + p1WinsDeceitOptimal + " " + p1WinsOptimal;
        }

        static String fileName = "D-small-attempt0";
        static String folderName = "2014QD";

        static String pathToFiles = "../../../../io/";
        static String inputFileName = pathToFiles + "\\" + folderName + "\\" + fileName + ".in";
        static String outputFileName = pathToFiles + "\\" + folderName + "\\" + fileName + ".out";

        static void Main(string[] args)
        {
            File.WriteAllText(outputFileName, string.Empty);
            using (StreamWriter outputFile = new StreamWriter(outputFileName))
            {
                using (StreamReader inputReader = new StreamReader(inputFileName))
                {
                    int testCaseCount = Int32.Parse(inputReader.ReadLine());
                    for (int caseIterator = 0; caseIterator < testCaseCount; caseIterator++)
                    {
                        String caseResult = runCase(inputReader);
                        String caseOutput = "Case #" + (caseIterator + 1) + ": " + caseResult;
                        outputFile.WriteLine(caseOutput);
                        Console.Out.WriteLine(caseOutput);
                    }
                }
            }

            Console.Read();
        }
    }
}
