using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader SReader = new StreamReader("A-small-attempt2.in");
            StreamWriter SWriter = new StreamWriter("A-small-attempt2.out");
            string[] s;
            s = SReader.ReadLine().Split(' ');
            int numberOfCases = Convert.ToInt32(s[0]);
            
            for (int i = 0; i < numberOfCases; i++)
            {
                s = SReader.ReadLine().Split(' ');
                int numberOfContestants = Convert.ToInt32(s[0]);
                
                int[] points = new int[numberOfContestants];
                int sum = 0;
               
                for (int j = 0; j < numberOfContestants; j++)
                {
                    points[j] = Convert.ToInt32(s[j + 1]);
                    sum += points[j];
                }

                float[] percentages = new float[numberOfContestants];
                bool[] passed = new bool[numberOfContestants];

                for (int j = 0; j < numberOfContestants; j++)
                {
                    passed[j] = false;
                }

                int numberOfContestantsNotPassed = numberOfContestants;
                int sumExceptPeoplePassed = sum;

                bool existPasses = true;

                //while (existPasses)
                {
                    existPasses = false;
                    for (int j = 0; j < numberOfContestants; j++)
                    {
                        if (!passed[j])
                        {
                            if (points[j] > 2f * sumExceptPeoplePassed / numberOfContestantsNotPassed)
                            {
                                numberOfContestantsNotPassed--;
                                sumExceptPeoplePassed -= points[j];
                                passed[j] = true;
                                existPasses = true;
                            }
                        }
                    }
                }
                for (int j = 0; j < numberOfContestants; j++)
                {
                    if (passed[j])
                    {
                        percentages[j] = 0;
                    }
                    else
                    {
                        percentages[j] = (100f / sum) * ((float)(sumExceptPeoplePassed + sum) / numberOfContestantsNotPassed - points[j]);
                    }
                }

                SWriter.Write("Case #" + (i + 1).ToString() + ":");
                for (int j = 0; j < numberOfContestants; j++)
                {
                    SWriter.Write(" " + percentages[j].ToString());
                }
                SWriter.WriteLine();
            }

            SReader.Close();
            SWriter.Close();
        }
    }
}
