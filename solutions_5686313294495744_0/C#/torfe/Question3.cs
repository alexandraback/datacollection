using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Question3 : Problem
    {
        protected override string SolveCase()
        {
            var number = this.ReadNextLineAsInt32();
            var firstWords = new List<string>();
            var secondWords = new List<string>();
            var matches = new List<Tuple<int, int>>();

            for (int i = 0; i < number; i++)
            {
                var words = this.ReadNextLineAsStringArray();

                int firstIndex = firstWords.IndexOf(words[0]);
                if (firstIndex < 0)
                {
                    firstWords.Add(words[0]);
                    firstIndex = firstWords.Count - 1;
                }

                int secondIndex = secondWords.IndexOf(words[1]);
                if (secondIndex < 0)
                {
                    secondWords.Add(words[1]);
                    secondIndex = secondWords.Count - 1;
                }
                matches.Add(new Tuple<int, int>(firstIndex, secondIndex));
            }
            
            var coveredSeconds = new List<int>();
            for (int i = 0; i < firstWords.Count; i++)
            {
                var results = matches.Where(t => t.Item1 == i && !coveredSeconds.Contains(t.Item2));
                if (results.Any())
                {
                    coveredSeconds.Add(results.First().Item2);
                }
            }

            var reals = firstWords.Count() + secondWords.Count() - coveredSeconds.Count();
            return (number - reals).ToString();
        }
    }
}
