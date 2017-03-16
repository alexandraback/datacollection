using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Osmos
{
    public class Solver
    {
        public int GetNumberOfChanges(List<int> motes, int arminsMote)
        {
            if (motes.Count == 0)
                return 0;

            if (arminsMote <= 1)
                return motes.Count();

            List<int> newMotes = new List<int>(motes);
            int moteSize = newMotes[0];

            if (arminsMote > moteSize)
            {
                arminsMote += moteSize;
                newMotes.Remove(moteSize);
                return GetNumberOfChanges(newMotes, arminsMote);
            }
            else
            {
                int addMoteChanges = GetNumberOfChanges(newMotes, arminsMote + arminsMote - 1) + 1;
                int removeMoteChanges = newMotes.Count();
                return Math.Min(addMoteChanges, removeMoteChanges);
            }
        }
    }

    class Program
    {
        static String fileName = "A-large";
        static String roundName = "2013R1B";
        static String inputFileName = "../../../../io/" + roundName + "/" + fileName + ".in";
        static String outputFileName = "../../../../io/" + roundName + "/" + fileName + ".out";


        static void Main(string[] args)
        {
            File.WriteAllText(outputFileName, string.Empty);
            using (StreamWriter outputFile = new StreamWriter(outputFileName))
            {
                using (StreamReader inputFile = new StreamReader(inputFileName))
                {
                    int testCaseCount = Int32.Parse(inputFile.ReadLine());
                    for (int caseIterator = 0; caseIterator < testCaseCount; caseIterator++)
                    {
                        int[] setupNumbers = inputFile.ReadLine().Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
                        int arminsMote = setupNumbers[0];
                        int numberOfMotes = setupNumbers[1];
                        int[] moteSizes = inputFile.ReadLine().Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
                        Array.Sort(moteSizes);

                        List<int> motes = new List<int>(moteSizes);

                        Solver solver = new Solver();
                        int numberOfChanges = solver.GetNumberOfChanges(motes, arminsMote);

                        String caseResult = "" + numberOfChanges;

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
