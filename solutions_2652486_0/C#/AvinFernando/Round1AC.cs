using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace GoogleCodeJam
{
    /// <summary>
    /// CodeJamProblem contains a collection of TestCases which are created by parsing the input file.
    /// The Solve method is called for each Test Case, then The output file is generated.
    /// </summary>
    public class Round1AC: CodeJamProblem<Round1ACTestCase>
    {
        protected override void ParseCase(Round1ACTestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            currentCase.R = int.Parse(field[0]);
            currentCase.N = int.Parse(field[1]);
            currentCase.M = int.Parse(field[2]);
            currentCase.K = int.Parse(field[3]);
            currentLine++;
            for (; currentLine < currentCase.R + 2; currentLine++)
            {
                var trick = new IndividualTrick();
                trick.N = currentCase.N;
                field = lines[currentLine].Split(_delimiterChars);
                foreach (var num in field)
                    trick.Products.Add(int.Parse(num));
                currentCase.Tricks.Add(trick);
            }

        }
        protected override StringBuilder OutputForEachCase(Round1ACTestCase testCase, StringBuilder currentString)
        {
            foreach (var trick in testCase.Tricks)
            {
                currentString.AppendLine().Append(trick.Guesses.Aggregate("", (str, x) => str + x.ToString()));
                    
            }
            return currentString;
        }
    }

    public class IndividualTrick
    {
        public int N { get; set; }
        private void DivideAllProdsBy(int n)
        {
            Guesses.Add(n);
            for (int i = 0; i < Products.Count; i++)
                if (Products[i] % n == 0)
                    Products[i] /= n;
        }
        public List<int> Products { get; set; }
        public IndividualTrick()
        {
            Products = new List<int>();
            Guesses = new List<int>();
        }
        public List<int> Guesses { get; set; }
        public void Solve()
        {
            while (Products.Any(x => x % 5 == 0))
                DivideAllProdsBy(5);
            while (Products.Any(x => x % 3 == 0))
                DivideAllProdsBy(3);
            while (Products.Any(x => x % 4 == 0))
                DivideAllProdsBy(4);
            while (Guesses.Count < N)
                Guesses.Add(2);
        }
    }

    public class Round1ACTestCase : ITestCase
    {
        public int N { get; set; }
        public int M { get; set; }
        public int K { get; set; }
        public int R { get; set; }

        public List<IndividualTrick> Tricks { get; set; }
        public Round1ACTestCase()
        {
            Tricks = new List<IndividualTrick>();
        }

        static Round1ACTestCase()
        {
        }

        public void Solve()
        {
            foreach (var trick in Tricks)
                trick.Solve();
        }
    }
}
