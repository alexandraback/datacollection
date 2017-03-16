using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Numerics;
using System.Text;

namespace ProblemB
{
    public static class Constants
    {
        public const string INPUT_FILE = "B-small-attempt2.in";
        public const string OUTPUT_FILE = "B-small-attempt2.out";
        //public const string INPUT_FILE = "sample.in";
        //public const string OUTPUT_FILE = "sample.out";
    }

    public static class Assertion
    {
        public static void Assert(bool statement, string message)
        {
            if (!statement)
            {
                throw new ApplicationException(message);
            }
        }
    }

    public class BestResult
    {
        private readonly BigInteger m_CScore;
        private readonly BigInteger m_JScore;

        public BigInteger AbsDifference()
        {
            var result = m_CScore - m_JScore;
            if (result < 0)
            {
                return -result;
            }
            return result;
        }


        public BigInteger CScore
        {
            get { return m_CScore; }
        }

        public BigInteger JScore
        {
            get { return m_JScore; }
        }


        public BestResult(BigInteger cScore, BigInteger jScore)
        {
            m_CScore = cScore;
            m_JScore = jScore;
        }
        
        public static BestResult ReturnBest(BestResult lhs, BestResult rhs)
        {
            if (lhs.AbsDifference() < rhs.AbsDifference())
            {
                return lhs;
            }
            else if (lhs.AbsDifference() > rhs.AbsDifference())
            {
                return rhs;
            }
            else
            {
                if (lhs.m_CScore < rhs.m_CScore)
                {
                    return lhs;
                }
                else if (lhs.m_CScore > rhs.m_CScore)
                {
                    return rhs;
                }
                else
                {
                    if (lhs.m_JScore < rhs.m_JScore)
                    {
                        return lhs;
                    }
                    else if (lhs.m_JScore > rhs.m_JScore)
                    {
                        return rhs;
                    }
                    else
                    {
                        // they're the same??
                        return lhs;
                    }   
                }
            }
        }
    }

    public class Case
    {
        private readonly string m_C;
        private readonly string m_J;

        public Case(StreamReader file)
        {
            var scores = file.ReadLine().Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
            m_C  = scores[0];
            m_J = scores[1];
        }

        public string GetResult()
        {
            /*
            var textResult = FindBestResult(
               new BestResult(BigInteger.Parse("023"), BigInteger.Parse("023")), 0, m_C.ToCharArray(), m_J.ToCharArray());
             */

            var bestResult = FindBestResult(
                new BestResult(
                    BigInteger.Parse(m_C.Replace("?", "9")),
                    BigInteger.Parse(m_J.Replace("?", "9"))),0, m_C.ToCharArray(), m_J.ToCharArray());

            return bestResult.CScore.ToString().PadLeft(m_C.Length, '0') + " " + bestResult.JScore.ToString().PadLeft(m_C.Length, '0');
        }

        private BestResult FindBestResult(BestResult bestResult, int position, char[] cScore, char[] jScore)
        {
            if (position >= m_C.Length)
            {
                // we're at the end
                return BestResult.ReturnBest(bestResult, new BestResult(BigInteger.Parse(new string(cScore)), BigInteger.Parse(new string(jScore))));
            }
            if (cScore[position] != '?' && jScore[position] != '?')
            {
                return FindBestResult(bestResult, position + 1, cScore, jScore);
            }
            else
            {
                if (cScore[position] == '?')
                {
                    if (jScore[position] != '?')
                    {
                        //var possibles = new char[] {'0','1','9',jScore[position]};
                        var possibles = new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
                        foreach (var possible in possibles)
                        {
                            var newcScore = new char[cScore.Length];
                            Array.Copy(cScore, newcScore, cScore.Length);
                            newcScore[position] = possible;
                            bestResult = FindBestResult(bestResult, position + 1, newcScore, jScore);
                        }   
                    }
                    else
                    {
                        // they're both ?
                        //var possibles = new char[] { '0', '1', '9' };
                        var possibles = new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
                        for (var x = 0; x < possibles.Length; x++)
                        {
                            for (var y = 0; y < possibles.Length; y++ )
                            {
                                var newcScore = new char[cScore.Length];
                                Array.Copy(cScore, newcScore, cScore.Length);
                                newcScore[position] = possibles[x];

                                var newjScore = new char[jScore.Length];
                                Array.Copy(jScore, newjScore, cScore.Length);
                                newjScore[position] = possibles[y];
                                bestResult = FindBestResult(bestResult, position + 1, newcScore, newjScore);
                            }   
                        }
                    }
                }
                else
                {
                    //var possibles = new char[] {'0','1','9',cScore[position]};
                    var possibles = new char[] { '0', '1', '2', '3','4','5','6','7','8','9' };
                    foreach (var possible in possibles)
                    {
                        var newjScore = new char[jScore.Length];
                        Array.Copy(jScore, newjScore, cScore.Length);
                        newjScore[position] = possible;
                        bestResult = FindBestResult(bestResult, position + 1, cScore, newjScore);
                    }
                }
                return bestResult;
            }
        }
    }

    public class Program
    {
        public static void Main()
        {
            var cases = new List<Case>();
            using (var file = new StreamReader(Constants.INPUT_FILE))
            {
                var numCases = int.Parse(file.ReadLine());
                for (var i = 0; i < numCases; i++)
                {
                    cases.Add(new Case(file));
                }
            }
            using (var file = new StreamWriter(Constants.OUTPUT_FILE))
            {
                var caseNumber = 1;
                foreach (var theCase in cases)
                {
                    Console.Write("Starting case " + caseNumber + "...");
                    file.Write("Case #" + caseNumber + ": " + theCase.GetResult() + "\n");
                    Console.WriteLine("FINISHED");
                    ++caseNumber;
                }
            }
        }
    }
}
