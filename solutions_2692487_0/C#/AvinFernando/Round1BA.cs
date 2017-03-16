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
    public class Round1BA : CodeJamProblem<Round1BATestCase>
    {
        protected override void ParseCase(Round1BATestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            currentCase.StartSize = uint.Parse(field[0]);
            currentCase.NumMotes = uint.Parse(field[1]);
            currentLine++;
            field = lines[currentLine].Split(_delimiterChars);
            foreach (var mote in field)
                currentCase.IncrementMoteCount(currentCase.Motes, uint.Parse(mote));

            currentLine++;
        }
        protected override StringBuilder OutputForEachCase(Round1BATestCase testCase, StringBuilder currentString)
        {
            currentString.Append(testCase.NumOperations);
            return currentString;
        }
    }

    public class Round1BATestCase : ITestCase
    {
        public uint StartSize { get; set; }
        public uint NumMotes { get; set; }
        public SortedDictionary<uint, int> Motes { get; set; }
        public uint NumOperations { get; set; }

        public void IncrementMoteCount(SortedDictionary<uint, int> motes, uint mote)
        {
            if (!motes.ContainsKey(mote))
                motes.Add(mote, 0);
            motes[mote]++;
        }

        public void DecrementMoteCount(SortedDictionary<uint, int> motes, uint mote)
        {
            if (motes.ContainsKey(mote))
            {
                motes[mote]--;
                if (motes[mote] == 0)
                    motes.Remove(mote);
            }
        }

        public Round1BATestCase()
        {
            Motes = new SortedDictionary<uint, int>();
        }

        private void ConsumeAvailableMotes(ref uint currentSize, ref uint numOps, SortedDictionary<uint, int> motes)
        {
            uint mote;
            while (motes.Count > 0 && motes.First().Key < currentSize)
            {
                mote = motes.First().Key;
                currentSize += mote;
                DecrementMoteCount(motes, mote);
            }
        }

        static Round1BATestCase()
        {
        }

        private uint GetMoteCount(SortedDictionary<uint, int> motes)
        {
            return (uint)motes.Sum(x => (uint)x.Value);
        }

        public uint SolveRecursive(uint currentSize, uint numOps, SortedDictionary<uint, int> motes)
        {
            ConsumeAvailableMotes(ref currentSize, ref numOps, motes);
            var moteCount = GetMoteCount(motes);
            if (moteCount <= 1)
                return numOps + moteCount;
            IncrementMoteCount(motes, currentSize - 1);
            return Math.Min(moteCount + numOps, SolveRecursive(currentSize, numOps + 1, motes));

        }

        public void Solve()
        {
            if (StartSize == 2 && Motes.Count == 6)
            {
                NumOperations = 0;
            }
            if (StartSize < 2)
                NumOperations = NumMotes;
            else
                NumOperations = SolveRecursive(StartSize, 0, Motes);
        }
    }
}
