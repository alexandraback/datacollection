/* C# Program
 * Google Code Jam 2012
 * Round 1A
 * Problem A. Password Problem
 * 
 * Copyright Craig A Maher - 2012
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJamR1A
{
    class Program
    {
        static void Main(string[] args)
        {
            Do("A-large", false);

            Console.ReadLine();
        }

        static void Do(string FileName, bool comp)
        {
            Console.WriteLine("Doing: " + FileName);
            StreamReader input;
            StreamWriter output;
            input = new StreamReader(FileName + ".in");
            output = new StreamWriter(FileName + ".out");

            StreamReader compare = null;
            if (comp)
            {
                compare = new StreamReader(FileName + ".compare");
            }

            //if it fails porgram needs to exit anyway
            int TestCases = int.Parse(input.ReadLine());
            string outString;
            for (int i = 1; i <= TestCases; ++i)
            {
                outString = Process(input);
                outString = string.Format("Case #{0}: {1}", i, outString);
                output.WriteLine(outString);

                if (!comp || outString != compare.ReadLine())
                {
                    Console.WriteLine(outString);
                }
            }
            Console.WriteLine("Fin");
            if (comp)
            {
                compare.Close();
            }
            input.Close();
            output.Close();
        }

        private static string Process(StreamReader input)
        {
            string line1 = input.ReadLine();
            string line2 = input.ReadLine();
            string[] AandB = line1.Split(' ');
            string[] Percentages = line2.Split(' ');
            int A = int.Parse(AandB[0]);//number of characters that I have already typed
            int B = int.Parse(AandB[1]);//total number of characters in my password
            double[] probabilities = new double[A];//probability that I correctly typed the ith letter in my password
            for (int i = 0; i < probabilities.Length; ++i)
            {
                probabilities[i] = double.Parse(Percentages[i]);
            }

            double MinimalAvergeKeyStrokes;

            //Keystrokes if I press enter right away
            MinimalAvergeKeyStrokes = 1 + B + 1;

            //Keystrokes if I keep typing
            int KeystorkesIfRight = 1 + (B-A);
            int KeystrokesIfWrong = KeystorkesIfRight + B + 1;
            double chanceRight = 1;
            for (int i = 0; i < probabilities.Length; ++i)
            {
                chanceRight *= probabilities[i];
            }
            //double Avergae = Math.Pow(A, 2);
            double KeyStrokes = chanceRight * KeystorkesIfRight + (1 - chanceRight) * KeystrokesIfWrong;

            if (KeyStrokes < MinimalAvergeKeyStrokes)
            {
                MinimalAvergeKeyStrokes = KeyStrokes;
            }

            //Keystrokes if I press backspace multi
            for (int i = 1; i <= A; ++i)
            {
                KeyStrokes = i;
                //Keystrokes if I keep typing
                KeystorkesIfRight = 1 + (B - A)+i;
                KeystrokesIfWrong = KeystorkesIfRight + B + 1;
                chanceRight = 1;
                for (int j = 0; j < probabilities.Length-i; ++j)
                {
                    chanceRight *= probabilities[j];
                }
                //double Avergae = Math.Pow(A, 2);
                KeyStrokes += chanceRight * KeystorkesIfRight + (1 - chanceRight) * KeystrokesIfWrong;

                if (KeyStrokes < MinimalAvergeKeyStrokes)
                {
                    MinimalAvergeKeyStrokes = KeyStrokes;
                }
            }

            	
            
            

            
            return MinimalAvergeKeyStrokes.ToString();
        }
    }
}
