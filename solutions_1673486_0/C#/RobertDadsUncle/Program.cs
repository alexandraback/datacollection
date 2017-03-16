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
        private readonly int m_A;
        private readonly int m_B;
        private readonly decimal[] m_ProbabilityCorrectlyTypedPassword;
        
        public CaseData(int a, int b, List<decimal> probabilities)
        {
            m_A = a;
            m_B = b;
            m_ProbabilityCorrectlyTypedPassword = probabilities.ToArray();
        }


        public int A
        {
            get { return m_A; }
        }

        public int B
        {
            get { return m_B; }
        }

        public decimal[] ProbabilityCorrectlyTypedPassword
        {
            get { return m_ProbabilityCorrectlyTypedPassword; }
        }
    }
    class Program
    {
        const string INPUT_FILE = "A-small-attempt0.in";
        const string OUTPUT_FILE = "A-small-attempt0.out";

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
                    var tokens = caseData.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var token in tokens)
                    {
                        ints.Add(int.Parse(token));
                    }
                }
                Debug.Assert(ints.Count == 2);
                var a = ints[0];
                var b = ints[1];

                var probabilitiesString = lines[currentLineNumber];
                var decimals = new List<decimal>();
                currentLineNumber++;
                {
                    var tokens = probabilitiesString.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var token in tokens)
                    {
                        decimals.Add(decimal.Parse(token));
                    }
                }

                Debug.Assert(decimals.Count == a);

                cases.Add(new CaseData(a, b, decimals));
            }

            for (int i = 0; i < cases.Count; i++)
            {
                Console.WriteLine("*** Case " + (i + 1));
                var caseData = cases[i];
                var output = "Case #" + (i + 1) + ": " + GetExpectedKeyStrokes(caseData);
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
        
        private static decimal GetExpectedKeyStrokes(CaseData caseData)
        {
            decimal bestExpected = decimal.MaxValue;
            { // keep typing
                decimal probability = 1;
                foreach(var prob in caseData.ProbabilityCorrectlyTypedPassword)
                {
                    probability *= prob;
                }
                int bestCase = caseData.B - caseData.A + 1;
                int worstCase = bestCase + caseData.B + 1;

                bestExpected = (probability * bestCase) + ((1 - probability) * worstCase);
            }

            { // enter straight away
                decimal expected = caseData.B + 2;
                if(expected < bestExpected)
                {
                    bestExpected = expected;
                }
            }

            for(var i=1;i<=caseData.A;i++)
            { // backspace * i cases
                int bestCase = caseData.B - caseData.A + 1 + (i*2);
                int worstCase = bestCase + caseData.B + 1;

                decimal bestCaseProbability = 1;
                for(int j=0;j<caseData.A-i;j++)
                {
                    bestCaseProbability *= caseData.ProbabilityCorrectlyTypedPassword[j];
                }
                decimal expected = (bestCaseProbability * bestCase) + ((1 - bestCaseProbability) * worstCase);
                if (expected < bestExpected)
                {
                    bestExpected = expected;
                }
            }
            return bestExpected;
        }
    }
}
