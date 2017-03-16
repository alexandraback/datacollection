using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Program
    {

        public static void Main(string[] args)
        {
            string[] testCases = null;
            if (!ValidateArgsAndGetCases(args, out testCases))
            {
                Console.WriteLine("could not get test cases");
                return;
            }

            RunProgram1A(testCases);
            
        }

        private static void RunProgram1A(string[] testcases)
        {
            for (int i = 0; i < testcases.Length; i += 2)
            {
                string[] passwordFields = testcases[i].Split(new char[] { ' ' });
                int numCharsSoFar = Convert.ToInt32(passwordFields[0]);
                int lengthOfPassword = Convert.ToInt32(passwordFields[1]);

                string[] probabilityFields = testcases[i + 1].Split(new char[] { ' ' });
                double[] probabilities = GetProbabilityValues(probabilityFields);

                //keep typing
                double option1 = ExpectedValueFromKeepTyping(numCharsSoFar, lengthOfPassword, probabilities);

                double option2 = ExpectedValueFromBackspaces(numCharsSoFar, lengthOfPassword, probabilities);

                double option3 = ExpectedValueFromRestarting(numCharsSoFar, lengthOfPassword, probabilities);

                Console.WriteLine("Case #{0}: {1:0.000000}", (i / 2) + 1, Math.Min(option1, Math.Min(option2, option3)));
            }

        }

        private static double ExpectedValueFromRestarting(int numCharsSoFar, int lengthOfPassword, double[] probabilities)
        {
            //press enter, type the whole password, press enter again
            double expectedValue = 1.0 + lengthOfPassword + 1.0;

            return expectedValue;
        }

        private static double ExpectedValueFromBackspaces(int numCharsSoFar, int lengthOfPassword, double[] probabilities)
        {
            //we can do up to numCharsSoFar backspaces
            //at some point we don't need to compute the rest

            double[] probabilityOfRightSoFar = new double[numCharsSoFar];
            for (int i = 0; i < numCharsSoFar; i++)
            {
                if (i == 0)
                {
                    probabilityOfRightSoFar[i] = probabilities[0];
                }
                else
                {
                    probabilityOfRightSoFar[i] = probabilityOfRightSoFar[i - 1] * probabilities[i];
                }
            }

            double minExpectedValue = Double.MaxValue;
            for (int i = 1; i < numCharsSoFar; i++)
            {
                int numBackSpaces = i;

                //b - a+(a-i)*2) + 1 + (1 - correct_through_i[i]) * (b + 1), 
                //double x = lengthOfPassword - numBackSpaces  + (2*(numCharsSoFar - numBackSpaces)) + 1 + (1 - probabilityOfRightSoFar[i]

                //we have to type the backspaces and whats left and press enter
                int charsLeftOnFirstTry = numBackSpaces + (lengthOfPassword - (numCharsSoFar - numBackSpaces)) + 1;

                double probabilityRemainingCharsAreRight = probabilityOfRightSoFar[(numCharsSoFar - 1) - numBackSpaces];
                double probabilityRemainingCharsAreWrong = 1.0 - probabilityRemainingCharsAreRight;


                //probRight*rest + probWrong(rest+all+1)
                double expectedIfRight = (probabilityRemainingCharsAreRight * charsLeftOnFirstTry);
                double expectedIfWrong = probabilityRemainingCharsAreWrong * ((charsLeftOnFirstTry + (lengthOfPassword + 1)));

                double expectedValue = expectedIfRight + expectedIfWrong;

                if (expectedValue < minExpectedValue)
                {
                    minExpectedValue = expectedValue;
                }
            }

            return minExpectedValue;
        }

        private static double ExpectedValueFromKeepTyping(int numCharsSoFar, int lengthOfPassword, double[] probabilities)
        {
            double everythingRight = 1.0;
            for (int i = 0; i < probabilities.Length; i++)
            {
                everythingRight *= probabilities[i];
            }

            int totalKeyIfRight = ((lengthOfPassword - numCharsSoFar) + 1); //finish typing and press enter
            double expectedKeysIfRight = totalKeyIfRight * everythingRight;

            //finish typing, press enter, type password, press enter
            double expectedKeysIfWrong = ((totalKeyIfRight + lengthOfPassword + 1.0) * (1.0 - everythingRight));

            return expectedKeysIfRight + expectedKeysIfWrong;
        }

        private static double[] GetProbabilityValues(string[] probabilityFields)
        {
            List<double> probabilities = new List<double>();
            for (int i = 0; i < probabilityFields.Length; i++)
            {
                probabilities.Add(Convert.ToDouble(probabilityFields[i]));
            }

            return probabilities.ToArray();
        }


        
        public static bool ValidateArgsAndGetCases(string[] args, out string[] testCases)
        {
            testCases = null;
            if (ValidateArgs(args))
            {
                testCases = GetTestCases(args[0]);
            }

            return (testCases != null);
        }


        public static bool ValidateArgs(string[] args)
        {
            //first read in the test cases
            if (args.Length < 0)
            {
                Console.WriteLine("please specify a file to read from");
            }
            string fileName = args[0];

            if (!File.Exists(fileName))
            {
                Console.WriteLine("file '{0}' does not exist", fileName);
                return false;
            }

            return true;
        }

        public static string[] GetTestCases(string fileName)
        {

            using (StreamReader sr = new StreamReader(fileName))
            {
                string firstLine = sr.ReadLine();
                int numCases = Convert.ToInt32(firstLine);

                List<string> testCases = new List<string>();
                while (sr.Peek() > 0)
                {
                    testCases.Add(sr.ReadLine());
                }
                
                return testCases.ToArray();
            }
        }

    }
}