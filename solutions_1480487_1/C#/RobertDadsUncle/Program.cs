using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Round_1A_Problem_A
{
    public class CaseData
    {
        private readonly List<int> m_ContestantScores;
        private readonly List<int> m_ContestantScoresSorted;
        private int m_TotalScores;
        private List<FloatScore> m_ContestantScoresFloat;


        public CaseData(List<int> contestantScores)
        {
            m_ContestantScores = contestantScores;
            m_ContestantScoresSorted = new List<int>(contestantScores);
            m_ContestantScoresSorted.Sort(SortScores);

            m_TotalScores = 0;
            foreach(var score in contestantScores)
            {
                m_TotalScores += score;
            }
            
        }

        private static int SortScores(int lhs, int rhs)
        {
            return lhs - rhs;
        }

        private static int SortFloatScores(FloatScore lhs, FloatScore rhs)
        {
            if(lhs.m_FloatScore - rhs.m_FloatScore < 0.0f)
                return -1;
            else
                return 1;
        }

        public string Solve()
        {
            CreateEventSpread();

            var answers = new decimal[m_ContestantScores.Count];

            foreach(var item in m_ContestantScoresFloat)
            {
                answers[item.m_ScoreIndex] = ((new decimal(item.m_FloatScore-m_ContestantScores[item.m_ScoreIndex])) / new decimal(m_TotalScores)) * 100M;
            }

            var result = new StringBuilder();

            var first = true;
            foreach (var answer in answers)
            {
                if (!first)
                {
                    result.Append(" ");
                }
                result.Append(answer.ToString("0.000000"));
                first = false;
            }

            return result.ToString();
        }

        private int GetScore(int index)
        {
            if(index >= m_ContestantScoresSorted.Count)
            {
                return int.MaxValue;
            }
            return m_ContestantScoresSorted[index];
        }

        private class FloatScore
        {
            public int m_ScoreIndex;
            public float m_FloatScore;
            
            public FloatScore(int scoreIndex, float floatScore)
            {
                m_ScoreIndex = scoreIndex;
                m_FloatScore = floatScore;
            }
        }

        private void CreateEventSpread()
        {
            m_ContestantScoresFloat = new List<FloatScore>();

            for(int i=0;i<m_ContestantScores.Count;i++)
            {
                m_ContestantScoresFloat.Add(new FloatScore(i, (float)m_ContestantScores[i]));
            }
            m_ContestantScoresFloat.Sort(SortFloatScores);

            float scoreLeft = m_TotalScores;

            while(scoreLeft > 0.0000001)
            {
                int numLowest = 1;
                float lowestValue = m_ContestantScoresFloat[0].m_FloatScore;
                float nextLowestValue = m_ContestantScoresFloat[1].m_FloatScore;
                while (lowestValue == nextLowestValue)
                {
                    numLowest++;
                    if(numLowest < m_ContestantScoresFloat.Count)
                    {
                        nextLowestValue = m_ContestantScoresFloat[numLowest].m_FloatScore;
                    }
                    else
                    {
                        break;
                    }
                }
                float differenceBetweenLowestAndNext = nextLowestValue - lowestValue;
                if (differenceBetweenLowestAndNext == 0)
                {
                    differenceBetweenLowestAndNext = float.MaxValue;
                }
                if (differenceBetweenLowestAndNext * numLowest > scoreLeft)
                {
                    differenceBetweenLowestAndNext = scoreLeft / numLowest;
                }
                for (int i = 0; i < numLowest;i++ )
                {
                    m_ContestantScoresFloat[i].m_FloatScore += differenceBetweenLowestAndNext;
                }

                scoreLeft -= differenceBetweenLowestAndNext * numLowest;

                m_ContestantScoresFloat.Sort(SortFloatScores);
            }
        }

        private decimal FindMinScoreNecessary(int scoreIndex)
        {
            var sortedList = new List<int>(m_ContestantScoresSorted);
            var score = sortedList[scoreIndex];
            sortedList.Remove(score);
            
            int scoreAdded = 0;
            int lastTotal = m_TotalScores;

            for(int i=m_TotalScores-1;i>=0;i--)
            {
                scoreAdded += 1;
                sortedList[0] += 1;
                sortedList.Sort(SortScores);

                if (score + (i) < sortedList[0])
                {
                    return (lastTotal/new decimal(m_TotalScores))*100M;
                }
                lastTotal = i;
            }
            return 0;
        }
    }
    class Program
    {
        const string INPUT_FILE = "A-large.in";
        const string OUTPUT_FILE = "A-large.out";

        static void Main(string[] args)
        {
            var lines = new List<string>();
            using (var sr = new StreamReader(INPUT_FILE))
            {
                while (!sr.EndOfStream)
                {
                    lines.Add(sr.ReadLine());
                }
            }

            var numTestCases = int.Parse(lines[0]);

            var outputLines = new List<string>();
            int currentLineNumber = 1;
            var cases = new List<CaseData>();
            for (int i = 0; i < numTestCases; i++)
            {
                var caseData = lines[currentLineNumber];
                currentLineNumber++;

                var ints = new List<int>();
                {
                    var tokens = caseData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var token in tokens)
                    {
                        ints.Add(int.Parse(token));
                    }
                }
                Debug.Assert(ints.Count > 1);
                var numContestants = ints[0];
                var contestantScores = new List<int>(ints);
                contestantScores.RemoveAt(0);
                
                cases.Add(new CaseData(contestantScores));
            }

            for (int i = 0; i < cases.Count; i++)
            {
                Console.WriteLine("*** Case " + (i + 1));
                var caseData = cases[i];
                var output = "Case #" + (i + 1) + ": " + caseData.Solve();
                outputLines.Add(output);
            }

            using (var sw = new StreamWriter(OUTPUT_FILE))
            {
                foreach (var line in outputLines)
                {
                    sw.Write(line + "\n");
                }
            }
        }

    }
}
