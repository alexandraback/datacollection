using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class First
    {
        static StreamWriter so;
        static void Main(string[] args)
        {

            string inputFile = @"c:\A-small-attempt0.in";
            so = new StreamWriter(inputFile + ".out", false);
            StreamReader sr = new StreamReader(inputFile);

            int numCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numCases; i++)
            {
                string output = "";

                string[] line = sr.ReadLine().Split(' ');

                int currentTyped = Convert.ToInt32(line[0]);
                int totalLetters = Convert.ToInt32(line[1]);

                line = sr.ReadLine().Split(' ');

                double[] probability = new double[currentTyped];

                double[] probabilityCorrectAtPoint = new double[currentTyped];

                for (int k = 0; k < currentTyped; k++)
                {
                    probability[k] = Convert.ToDouble(line[k]);
                    probabilityCorrectAtPoint[k] = probability[k];
                    for (int j = 0; j < k; j++)
                    {
                        probabilityCorrectAtPoint[k] = probabilityCorrectAtPoint[k] * probability[j];
                    }

                }

                // first determine if Enter pressed
                double enterOK = probabilityCorrectAtPoint[currentTyped - 1] * (totalLetters - currentTyped + 1);
                double enterNotOk = (1 - probabilityCorrectAtPoint[currentTyped - 1]) * ((totalLetters - currentTyped + 1) + totalLetters + 1);

                double first = enterOK + enterNotOk;
                

                //if i enter right away

                double rightAway = 2 + totalLetters;
                if (rightAway < first)
                {
                    first = rightAway;
                }


                // if backspace pressed a number of times
                for (int k = currentTyped; k > 0; k--)
                {
                    int keyPresses = k + 1 + totalLetters - (currentTyped - k);

                    int totalKeyPresses = keyPresses + totalLetters + 1;
                    // now calculate probability of correct.
                    double probabilityOfCorrect = 0;


                    if (k == currentTyped)
                    {
                        probabilityOfCorrect = 1;
                    }
                    else
                    {
                        probabilityOfCorrect = probabilityCorrectAtPoint[currentTyped - (k+1)];
                    }
                     

                    double ok = probabilityOfCorrect * keyPresses + ((1 - probabilityOfCorrect) * totalKeyPresses);

                    if (ok < first)
                    {
                        first = ok;
                    }
                    
                }

                WriteLine(string.Format("Case #{0}: {1}", i + 1, String.Format("{0:0.000000}", first)));

            }

            so.Close();
            sr.Close();
            Console.WriteLine("done");
            Console.ReadLine();
        }

        static void WriteLine(string message)
        {
            so.WriteLine(message);
            Console.WriteLine(message);

        }
    
    }
}
