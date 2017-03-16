using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamRound1A
{
    public class ProblemA
    {
        public void Execute(string[] args)
        {

            using (StreamReader read = new StreamReader(File.OpenRead(args[0])))
            {
                int numCases = int.Parse(read.ReadLine());

                for (int i = 0; i < numCases; i++)
                {
                    string[] lengthInfo = read.ReadLine().Split(' ');
                    int alreadyTyped = int.Parse(lengthInfo[0]);
                    int totalChars = int.Parse(lengthInfo[1]);

                    string[] probabilities = read.ReadLine().Split(' ');
                    List<double> doubleProbs = new List<double>();

                    foreach (string strprob in probabilities)
                    {
                        doubleProbs.Add(double.Parse(strprob));
                    }

                    double answer = Solve(alreadyTyped, totalChars, doubleProbs.ToArray());

                    Console.WriteLine("Case #" + (i + 1) + ": " + answer);


                }


            }
            
        }

        public double Solve(int charCount, int totalChars, double[] charProbabilities)
        {

            List<double> expectedKeys = new List<double>();

            int charsLeft = totalChars - charCount;

            for (int backspaces = 0; backspaces <= charCount; backspaces++)
            {

                if (backspaces == charCount)
                {
                    expectedKeys.Add(backspaces + totalChars + 1);
                }
                else
                {
                    double probabilityCorrect = charProbabilities.Take(charCount - backspaces).Aggregate((product, next) => product * next);
                    double probabilityIncorrect = 1 - probabilityCorrect;

                    double keysIfCorrect = probabilityCorrect * (charsLeft + (backspaces * 2) + 1);
                    double keysIfIncorrect = probabilityIncorrect * (charsLeft + (backspaces *2) + 1 + totalChars + 1);

                    double expected = keysIfCorrect + keysIfIncorrect;
                    expectedKeys.Add(expected);

                }

                expectedKeys.Add(2 + totalChars);

            }

            return expectedKeys.Min();
        }
    }
}
