using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FacebookHackerCup2012
{
    class PasswordProblem
    {
        public PasswordProblem()
        {

            int cases;
            string line,line2;

            // Read the file and display it line by line.
            StreamReader file = new StreamReader("passwordproblem.txt");
            StreamWriter output = new StreamWriter("passwordproblemoutput.txt");
            cases = Convert.ToInt32(file.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                line = file.ReadLine();
                line2 = file.ReadLine();
                String[] lineparts = line.Split(' ');
                int a = Convert.ToInt32(lineparts[0]);
                int b = Convert.ToInt32(lineparts[1]);
                lineparts = line2.Split(' ');
                double[] chances = new double[a];
                double[] backspace = new double[a];
                double[] accChances = new double[a+1];
                double correctChance;
                for (int j = 0; j < a; j++)
                {
                    chances[j] = Convert.ToDouble(lineparts[j].Replace(".",","));
                }
                correctChance = chances[0];
                accChances[0] = 0;
                accChances[1] = chances[0];
                for (int j = 1; j < a; j++)
                {
                    accChances[j+1] = accChances[j] * chances[j];
                    correctChance *= chances[j];
                }
                //enter straight away
                int enter = b + 2;
                double keepTyping = (correctChance * ((b - a) + 1)) + ((1 - correctChance) * ((b - a) + b + 2));
                for (int j = 0; j < a; j++)
                {
                    if (j != a - 1) backspace[j] = (accChances[a - (1 + j)] * ((j + 1) * 2 + (b - a) + 1)) + ((1 - accChances[a - (1 + j)]) * ((1 + j) * 2 + (b - a) + b + 2));
                    else backspace[j] = (j + 1) + b + 1;
                }
                double absoluteMin = Math.Min(Math.Min(backspace.Min(),enter),keepTyping);
                output.WriteLine("Case #"+(i+1)+": "+String.Format("{0:F6}", absoluteMin).Replace(",","."));
            }

            file.Close();
            output.Close();

        }

        public static void Main(string[] args)
        {
            PasswordProblem p = new PasswordProblem();
        }
    }
}
