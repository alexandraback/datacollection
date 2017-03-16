using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;


namespace qr2014ProgD
{
    class qrProgD
    {
        public const string cInputFile = "C:\\Dev\\2014\\qrD\\D-large.in";
        public const string cOutputFile = "C:\\Dev\\2014\\qrD\\out.txt";
        public const string cExampleAnswerFile = "C:\\Dev\\2014\\qrD\\ea.txt";

        static void Main(string[] args)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(cOutputFile))
                {
                    using (StreamReader reader = new StreamReader(cInputFile))
                    {
                        int numberOfTestCases = int.Parse(reader.ReadLine());

                        for (int testCaseNum = 0; testCaseNum < numberOfTestCases; testCaseNum++)
                        {
                            int numberOfWeights = int.Parse(reader.ReadLine());
                            string[] naomiParms = reader.ReadLine().Split(' ');
                            string[] kenPamrs   = reader.ReadLine().Split(' ');

                            double[] naomiWeights = Array.ConvertAll(naomiParms, Double.Parse);
                            double[] kenWeights = Array.ConvertAll(kenPamrs, Double.Parse);

                            int regularScore = solveForRegularWar(naomiWeights, kenWeights);
                            int deceitfulScore = solveForDeceitfulWar(naomiWeights, kenWeights);

                            //Output testcase 
                            string outputLine = "Case #" + (testCaseNum + 1).ToString() + ": " + deceitfulScore.ToString() + " " + regularScore.ToString();

                            Console.WriteLine(outputLine);
                            writer.WriteLine(outputLine);
                        }
                    }
                }
            }
            catch (Exception exc)
            {
                Console.WriteLine(exc);
            }
            ///CompareResultWithExample();
        }

        static int solveForDeceitfulWar(double[] pNaomiWight, double[] pKenWeight)
        {
            int score = 0;

            List<double> naomiOrderByAsc = (from w in pNaomiWight orderby w ascending select w).ToList<double>();
            List<double> kenOrderByAsc = (from w in pKenWeight orderby w ascending select w).ToList<double>();

            int index = 0;
            while(naomiOrderByAsc.Count != 0 && index < naomiOrderByAsc.Count)
            {

                //niaomi's wieght is less then kens  weight
                if (naomiOrderByAsc[index] < kenOrderByAsc[index])
                {
                    //find kens largest wight
                    double kensLargestWeight = kenOrderByAsc.Last();

                    //pretend naomi's log is just less then ken's largest log
                    //ken will get the point but it elimiates a high ranking weight for ken
                    kenOrderByAsc.RemoveAt(kenOrderByAsc.Count - 1);
                    naomiOrderByAsc.RemoveAt(index);
                    index = 0;
                }
                else
                {
                    index++;
                }
            }
            score = naomiOrderByAsc.Count();
            return score;
        }

        static int solveForRegularWar(double[] pNaomiWight, double[] pKenWeight)
        {
            int score = 0;

            List<double> naomiOrderByAsc = (from w in pNaomiWight orderby w ascending select w).ToList<double>();
            List<double> kenOrderByAsc = (from w in pKenWeight orderby w ascending select w).ToList<double>();

            foreach (double naomiWeight in naomiOrderByAsc)
            {
                bool weightFoundForKen = false;

                //find the first  entry in kens weights larger then naomi's
                for(int i = 0; i < kenOrderByAsc.Count; i++)
                {
                    if (kenOrderByAsc[i] > naomiWeight)
                    {
                        kenOrderByAsc.RemoveAt(i);
                        weightFoundForKen = true;
                        break;
                    }
                }

                //No weight found Naomi gets the point
                //remove smallest entry in kens list.
                if (!weightFoundForKen)
                {
                    score++;
                    kenOrderByAsc.RemoveAt(0);
                }
            }


            return score;
        }
    }
}
