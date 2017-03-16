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

            RunProgram2A(testCases);
            
        }

        private static void RunProgram2A(string[] testcases)
        {
            /*Given the points contestants got from judges, your job is to find out, 
             * for each contestant, the minimum percentage of audience votes he/she must 
             * receive in order for him/her to be guaranteed not to be eliminated, no matter 
             * how the rest of the audience's votes are distributed. 
             */
            for (int i = 0; i < testcases.Length; i++)
            {
                string[] fields = testcases[i].Split(new char[] { ' ' });

                double N = Convert.ToDouble(fields[0]); //number of contestants
                List<double> judgeScoresPerContestant = new List<double>();
                for (int j = 1; j < fields.Length; j++)
                {
                    judgeScoresPerContestant.Add(Convert.ToDouble(fields[j]));
                }

                Dictionary<int, double> audienceScorePerContestantNeeded = GetAudienceScores(judgeScoresPerContestant);

                //now if anyone is negative, we remove their scores and try again
                double sumOfRemovedJudgeScores = 0.0;
                double numRemoved = 0.0;
                double sumOfAllJudgeSCores = judgeScoresPerContestant.Sum();
                while (audienceScorePerContestantNeeded.Values.Min() < 0)
                {
                    IEnumerable<int> contestantsWithLowScoresEnumerable = audienceScorePerContestantNeeded.Keys.Where(k => audienceScorePerContestantNeeded[k] < 0);

                    int[] contestantsWithLowScores = contestantsWithLowScoresEnumerable.ToArray();
                    
                    foreach (int contestant in contestantsWithLowScores)
                    {
                        audienceScorePerContestantNeeded[contestant] = 0.0;
                        sumOfRemovedJudgeScores += judgeScoresPerContestant[contestant];
                    }
                    
                    numRemoved += contestantsWithLowScores.Count();
                    for (int j = 0; j < N; j++)
                    {
                        if (!contestantsWithLowScores.Contains(j))
                        {

                            double fractionOfTotal = ((2.0 * sumOfAllJudgeSCores) - sumOfRemovedJudgeScores) / (N - numRemoved);
                            double answer = (fractionOfTotal - judgeScoresPerContestant[j]) / sumOfAllJudgeSCores;
                            audienceScorePerContestantNeeded[j] = answer;
                        }
                    }
                }

                List<string> answers = new List<string>();
                for (int j = 0; j < N; j++)
                {
                    answers.Add(String.Format("{0:00.000000}", audienceScorePerContestantNeeded[j] * 100));
                }
                string result = String.Join(" ", answers);

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
            }

        }

        private static Dictionary<int, double> GetAudienceScores(List<double> judgeScoresPerContestant)
        {
            double sumOfJudgesScore = judgeScoresPerContestant.Sum();

            Dictionary<int, double> audienceScorePerContestantNeeded = new Dictionary<int, double>();

            double N = judgeScoresPerContestant.Count;
            for (int j = 0; j < N; j++)
            {
                double fractionOfJudgeScore = judgeScoresPerContestant[j] / sumOfJudgesScore;
                double fraction = (2.0) / (1.0 * N);
                audienceScorePerContestantNeeded[j] = ((2 / N) - fractionOfJudgeScore);
            }

            return audienceScorePerContestantNeeded;
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