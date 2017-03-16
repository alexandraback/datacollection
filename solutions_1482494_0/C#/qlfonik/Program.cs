using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileName = "input.in";
            using (var reader = new StreamReader(fileName))
            {
                int cases = int.Parse(reader.ReadLine().Trim());
                using (var writer = new StreamWriter("output.out"))
                {
                    for (int i = 0; i < cases; i++)
                    {
                        var line = reader.ReadLine();
                        int levels = int.Parse(line.Trim());
                        List<Score> scores = new List<Score>(levels * 2);
                        for (int l = 0; l < levels; l++)
                        {
                            line = reader.ReadLine();
                            var lineValues = line.Split(' ');
                            int oneStarScore = int.Parse(lineValues[0]);
                            int twoStarsScore = int.Parse(lineValues[1]);
                            var oneStar = new Score() { Price = oneStarScore, InitialValue = 1, BigBrotherScore = twoStarsScore };
                            scores.Add(oneStar);
                            scores.Add(new Score() { Price = twoStarsScore, InitialValue = 2, OneStarBrother = oneStar, BigBrotherScore = 0 });
                        }

                        int result = 0;
                        int gainedStars = 0;

                        while (gainedStars < levels * 2 || scores.Any(s => s.OneStarBrother != null && !s.Played))
                        {
                            var sorted = scores.Where(s => !s.Played && s.Price <= gainedStars).OrderByDescending(s => s.Value).ThenByDescending(s => s.InitialValue).ThenByDescending(s => s.BigBrotherScore).ToArray();
                            if (sorted.Length == 0)
                                break;
                            gainedStars += sorted[0].Value;
                            sorted[0].Play();
                            result++;
                        }

                        writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, (gainedStars < levels * 2) ? "Too Bad" : result.ToString()));
                    }
                }
            }
        }


        public class Score
        {
            public int InitialValue;
            public int BigBrotherScore;
            public int Value
            {
                get
                {
                    return (OneStarBrother == null) ? 1 : ((OneStarBrother.Played) ? 1 : 2);
                }
            }
            public int Price;
            public Score OneStarBrother = null;

            private bool played = false;
            public bool Played
            {
                get
                {
                    return played;
                }
            }

            public void Play()
            {
                played = true;
                if (OneStarBrother != null)
                    OneStarBrother.Play();
            }
        }

    }
}
