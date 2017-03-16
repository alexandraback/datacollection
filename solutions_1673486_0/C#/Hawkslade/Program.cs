using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                string[] values = input.ReadLine().Split(' ');
                int charactersTyped = int.Parse(values[0]);
                int passwordLength = int.Parse(values[1]);
                values = input.ReadLine().Split(' ');
                double[] probablility = new double[charactersTyped];
                double[] goodChance = new double[passwordLength];
                for (int index = 0; index < passwordLength; index++)
                {
                    if (index == 0)
                    {
                        probablility[index] = double.Parse(values[index]);
                        goodChance[index] = probablility[index];
                    }
                    else
                    {
                        if (index < charactersTyped)
                        {
                            probablility[index] = double.Parse(values[index]);
                            goodChance[index] = goodChance[index - 1] * probablility[index];
                        }
                        else
                        {
                            goodChance[index] = goodChance[index - 1];
                        }
                    }
                }
                int charactersLeft = passwordLength - charactersTyped + 1;
                int incorrectCharacters = charactersLeft + passwordLength + 1;
                double minimum = (charactersLeft * goodChance[charactersTyped - 1]) + (incorrectCharacters * (1 - goodChance[charactersTyped - 1]));
                for (int delete = 1; delete < charactersTyped; delete++)
                {
                    double chance;
                    if (charactersLeft - delete >= 0)
                    {
                        chance = ((charactersLeft + delete * 2) * goodChance[charactersTyped - delete - 1]) + ((incorrectCharacters + delete * 2) * (1 - goodChance[charactersTyped - delete - 1]));
                    }
                    else
                    {
                        chance = charactersLeft + delete * 2;
                    }
                    if (chance < minimum)
                    {
                        minimum = chance;
                    }

                }
                double enterChance = passwordLength + 2.0;
                if (enterChance < minimum)
                {
                    minimum = enterChance;
                }
                output.WriteLine("Case #" + (currentCase + 1).ToString() + ": " + minimum.ToString("0.000000"));
            }
        }
    }
}
