using System;
using System.Collections.Generic;
using System.IO;

namespace Google
{
    class Program
    {
        static void Main(string[] args)
        {
            #region IO
            TextReader reader;
            if (args.Length > 0)
            {
                reader = new StreamReader(args[0]);
            }
            else
            {
                reader = Console.In;
            }

            TextWriter writer;
            if (args.Length > 1)
            {
                writer = new StreamWriter(args[1]);
            }
            else
            {
                writer = Console.Out;
            }
            #endregion

            string str = reader.ReadLine();
            int cases;
            if (int.TryParse(str.Trim(), out cases))
            {
                if (cases <= 0)
                {
                    throw new ApplicationException("Invalid number of cases!!!");
                }

                List<string> caseOutputs = new List<string>(cases);
                for (int i = 0; i < cases; i++)
                {
                    str = reader.ReadLine();
                    string[] paras = str.Split(' ');

                    int typedLetter = 0;
                    int totalLetter = 0;
                    int.TryParse(paras[0], out typedLetter);
                    int.TryParse(paras[1], out totalLetter);

                    if (typedLetter <= 0 || totalLetter < 0)
                    {
                        caseOutputs.Add(string.Format("Case #{0}: {1}", i + 1, "Invalid input"));
                        continue;
                    }

                    str = reader.ReadLine();
                    paras = str.Split(' ');

                    List<decimal> probabilityLetter = new List<decimal>(typedLetter);
                    for (int j = 0; j < typedLetter; j++)
                    {
                        decimal d = decimal.Parse(paras[j]);
                        probabilityLetter.Add(d);
                    }

                    int remainKS = totalLetter - typedLetter + 1;
                    int retryKS = totalLetter + 1;

                    // case: retry straight
                    decimal minKS = 1 + retryKS;

                    // case: keep typing
                    decimal probability = GetProbability(probabilityLetter, 0, probabilityLetter.Count, 1);
                    decimal avgKS = CalcAvgKS(probability, remainKS, remainKS + retryKS);
                    if (avgKS < minKS)
                    {
                        minKS = avgKS;
                    }

                    int backKS = 0;
                    for (int x = 1; x <= typedLetter; x++)
                    {
                        backKS = 2 * x;
                        probability = GetProbability(probabilityLetter, 0, typedLetter - x, 1);
                        avgKS = CalcAvgKS(probability, remainKS + backKS, remainKS + backKS + retryKS);
                        if (avgKS < minKS)
                        {
                            minKS = avgKS;
                        }
                    }

                    caseOutputs.Add(string.Format("Case #{0}: {1}", i + 1, minKS.ToString("F6")));
                }

                foreach (string s in caseOutputs)
                {
                    writer.WriteLine(s);
                }

                writer.Flush();
            }
            else
            {
                throw new ApplicationException("Invalid number of cases!!!");
            }
        }

        private static decimal CalcAvgKS(decimal probability, int successKS, int failKS)
        {
            return probability * successKS + (1 - probability) * failKS;
        }

        private static decimal GetProbability(List<decimal> probabilityLetter,int idxFrom, int count, decimal accumulateProbability)
        {
            while(count-- > 0)
            {
                accumulateProbability *= probabilityLetter[idxFrom];
                idxFrom++;
            }

            return accumulateProbability;
        }

        private decimal RemainingKeyStroke(List<decimal> correctLetterJ, int idx, decimal accumulateProbability)
        {
            decimal minKeyStroke = decimal.MaxValue;

            if (idx >= correctLetterJ.Count)
            {
                return 0;
            }
            return 0;

            // if correct letter
            decimal currentProbability = correctLetterJ[idx];
            decimal probability = accumulateProbability * currentProbability;

            // if wrong letter
            currentProbability = 1 - currentProbability;
            probability = accumulateProbability * currentProbability;
        }
    }
}
