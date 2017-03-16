using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace round1b_problem1
{
    class Program
    {
        public static string inputFileName = @"..\input.in";
        public static string outputFileName = @"..\output.in";


        static void Main(string[] args)
        {
            try
            {
                ReadInput();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }

            Console.WriteLine("FINISHED!");
            Console.ReadKey();
        }

        private static void ReadInput()
        {            

            using (FileStream input = new FileStream(inputFileName, FileMode.Open, FileAccess.Read))
            {

                using (FileStream output = new FileStream(outputFileName, FileMode.Create, FileAccess.Write))
                {

                    using (StreamReader sr = new StreamReader(input))
                    {

                        using (StreamWriter sw = new StreamWriter(output))
                        {

                            int numberOfCases = int.Parse(sr.ReadLine());

                            double contestants;                            

                            for (int i = 0; i < numberOfCases; i++)
                            {
                                string[] inputs = sr.ReadLine().Split(' ');

                                contestants = Convert.ToDouble(inputs[0]);
                                double[] judgePoints = new Double[Convert.ToInt32(contestants)];
                                double totalJudgePoints = 0;
                                double primarySalvationThreshold = 0;
                                double salvationThreshold = 0;
                                double[] minAudiencePercent = new Double[Convert.ToInt32(contestants)];
                                

                                for (int j = 0; j < contestants; j++)
                                {
                                    judgePoints[j] = Convert.ToDouble(inputs[j + 1]);
                                    totalJudgePoints += judgePoints[j];
                                }

                                primarySalvationThreshold = (totalJudgePoints * 2) / contestants;
                                int savedContestants = 0;
                                double sumNotSaved = 0;

                                for (int j = 0; j < contestants; j++)
                                {
                                    if(judgePoints[j] >= primarySalvationThreshold)
                                    {
                                        savedContestants++;
                                    }
                                    else
                                    {
                                        sumNotSaved += judgePoints[j];
                                    }
                                }

                                salvationThreshold = (totalJudgePoints + sumNotSaved) / (contestants - savedContestants);

                                StringBuilder outputLine = new StringBuilder();

                                for (int j = 0; j < contestants; j++)
                                {
                                    if (judgePoints[j] < primarySalvationThreshold)
                                    {

                                        minAudiencePercent[j] = Math.Round((((salvationThreshold) - judgePoints[j]) / totalJudgePoints) * 100, 7);
                                        outputLine.AppendFormat("{0} ", minAudiencePercent[j].ToString("N6"));
                                    }
                                    else
                                    {
                                        outputLine.AppendFormat("{0} ", 0.ToString("N6"));
                                    }
                                }

                                outputLine = outputLine.Remove(outputLine.Length - 1, 1);

                                sw.WriteLine("Case #{0}: {1}", i + 1, outputLine.ToString().Replace(",", "."));

                            }
                        }
                    }
                }
            }
        }
    }

}
