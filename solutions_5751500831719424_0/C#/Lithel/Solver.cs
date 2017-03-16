using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJRepeater
{
    class Solver
    {
        static void Main(string[] args)
        {
            FileStream stream = File.OpenRead(args[0]);
            StreamReader reader = new StreamReader(stream);

            string outputFileName = "output" + args[0];
            FileStream outputStream = File.Create(outputFileName);
            StreamWriter writer = new StreamWriter(outputStream);

            string casesLine = reader.ReadLine();
            int numCases = Int32.Parse(casesLine);

            for (int i = 1; i <= numCases; ++i)
            {
                Solver currentCase = new Solver();
                currentCase.Read(reader);
                int fewestMoves = currentCase.CalculateMoves();

                string result;
                if (fewestMoves >= 0)
                {
                    result = String.Format("Case #{0}: {1}", i, fewestMoves);
                }
                else
                {
                    result = String.Format("Case #{0}: Fegla Won", i);
                }

                System.Console.WriteLine(result);
                writer.WriteLine(result);
            }

            writer.Flush();
        }

        class LetterSet
        {
            public char m_character;
            public int m_count;
        }

        class LetterString
        {
            public List<LetterSet> m_sets = new List<LetterSet>();
        }

        List<LetterString> m_strings = new List<LetterString>();
        int m_numSets = 0;

        public Solver()
        {
        }

        public void Read(StreamReader input)
        {
            string numStringsLine = input.ReadLine();
            int numStrings = Int32.Parse(numStringsLine);

            for (int i = 0; i < numStrings; ++i)
            {
                LetterString currentString = new LetterString();
                string currentStringLine = input.ReadLine();

                LetterSet currentSet = null;
                foreach (char c in currentStringLine.ToCharArray())
                {
                    if (currentSet != null)
                    {
                        if (currentSet.m_character == c)
                        {
                            currentSet.m_count++;
                        }
                        else
                        {
                            currentString.m_sets.Add(currentSet);
                            currentSet = new LetterSet();
                            currentSet.m_character = c;
                            currentSet.m_count = 1;
                        }
                    }
                    else
                    {
                        currentSet = new LetterSet();
                        currentSet.m_character = c;
                        currentSet.m_count = 1;
                    }
                }

                if (currentSet != null)
                {
                    currentString.m_sets.Add(currentSet);
                }

                m_strings.Add(currentString);

                if (m_numSets == 0)
                {
                    m_numSets = currentString.m_sets.Count;
                }
                else if (m_numSets != currentString.m_sets.Count)
                {
                    // Unsolvable
                    m_numSets = -1;
                }
            }
        }

        public int CalculateMoves()
        {
            if (m_numSets == -1)
            {
                // Unsolvable
                return -1;
            }

            int fewestMoves = 0;

            for (int i = 0; i < m_numSets; ++i)
            {
                int minLetters = Int32.MaxValue;
                int maxLetters = 0;
                char testChar = m_strings[0].m_sets[i].m_character;
                foreach (LetterString currentString in m_strings)
                {
                    LetterSet activeSet = currentString.m_sets[i];
                    if (activeSet.m_character != testChar)
                    {
                        // Impossible
                        return -1;
                    }

                    if (activeSet.m_count > maxLetters)
                    {
                        maxLetters = activeSet.m_count;
                    }
                    if (activeSet.m_count < minLetters)
                    {
                        minLetters = activeSet.m_count;
                    }
                }

                int minDistanceForSet = Int32.MaxValue;
                for (int testAmount = minLetters; testAmount <= maxLetters; ++testAmount)
                {
                    int currentDistance = 0;
                    foreach (LetterString currentString in m_strings)
                    {
                        LetterSet activeSet = currentString.m_sets[i];
                        if (testAmount > activeSet.m_count)
                        {
                            // Would be adding letters
                            currentDistance += (testAmount - activeSet.m_count);
                        }
                        else
                        {
                            // Removing letters or nothing
                            currentDistance += (activeSet.m_count - testAmount);
                        }
                    }

                    if (currentDistance < minDistanceForSet)
                    {
                        minDistanceForSet = currentDistance;
                    }
                }
                fewestMoves += minDistanceForSet;
            }

            return fewestMoves;
        }
    }
}
