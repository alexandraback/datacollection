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
    public class Round1CC : CodeJamProblem<Round1CCTestCase>
    {
        protected override void ParseCase(Round1CCTestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            currentCase.NumTribes = int.Parse(field[0]);
            while (currentCase.Tribes.Count < currentCase.NumTribes)
            {
                currentLine++;
                field = lines[currentLine].Split(_delimiterChars);
                currentCase.Tribes.Add(new Tribe(
                    long.Parse(field[0]), long.Parse(field[1]), long.Parse(field[2]), long.Parse(field[3]), 
                    long.Parse(field[4]), long.Parse(field[5]), long.Parse(field[6]), long.Parse(field[7])));
            }
            currentLine++;
        }
        protected override StringBuilder OutputForEachCase(Round1CCTestCase testCase, StringBuilder currentString)
        {
            currentString.Append(testCase.NumBreaches);
            return currentString;
        }
    }

    public class Tribe
    {
        public long FirstAttackDay { get; set; }
        public long TotalNumAttacks { get; set; }
        public long West { get; set; }
        public long East { get; set; }
        public long Strength { get; set; }
        public long AttackInterval { get; set; }
        public long DeltaDistance { get; set; }
        public long DeltaStrength { get; set; }
        public bool Expired { get; set; }


        public long AttacksSoFar { get; set; }

        public Tribe() { }
        public Tribe(long d, long n, long w, long e, long s, long dd, long dp, long ds)
        {
            FirstAttackDay = d;
            TotalNumAttacks = n;
            West = w * 2;
            East = e * 2;
            Strength = s;
            AttackInterval = dd;
            DeltaDistance = dp * 2;
            DeltaStrength = ds;
        }

        private bool DoesAttackDay(long day)
        {
            return day >= FirstAttackDay && (day % AttackInterval == FirstAttackDay % AttackInterval);
        }

        public int AttackWall(long day, Dictionary<long, long> Wall, Dictionary<long, long> Improvements)
        {
            if (Expired || !DoesAttackDay(day))
                return 0;
            AttacksSoFar++;
            int breach = 0;
            for (long i = West; i <= East; i++)
            {
                if (!Wall.ContainsKey(i))
                    Wall[i] = 0;
                if (Wall[i] < Strength)
                {
                    breach = 1;
                    Improvements[i] = Math.Max(Improvements.ContainsKey(i) ? Improvements[i] : 0, Strength);
                }
            }
            if (AttacksSoFar == TotalNumAttacks)
                Expired = true;

            West += DeltaDistance;
            East += DeltaDistance;
            Strength += DeltaStrength;
            return breach;
        }
    }


    public class Round1CCTestCase : ITestCase
    {
        public List<Tribe> Tribes { get; set; }
        public int NumTribes { get; set; }
        public int NumBreaches { get; set; }
        public Dictionary<long, long> Wall { get; set; }

        public Round1CCTestCase()
        {
            Tribes = new List<Tribe>();
            Wall = new Dictionary<long, long>();
        }

        static Round1CCTestCase()
        {
        }

        public void Solve()
        {
            Dictionary<long, long> Improvements = new Dictionary<long, long>();
            long day = 0;
            while (Tribes.Any(x => !x.Expired))
            {
                foreach (var tribe in Tribes)
                    NumBreaches += tribe.AttackWall(day, Wall, Improvements);
                foreach (var improvement in Improvements)
                    Wall[improvement.Key] = improvement.Value;
                Improvements.Clear();
                day++;
            }
        }
    }
}

