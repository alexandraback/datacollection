using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class ScoreBoard
    {
        public ulong c { get; set; }
        public ulong j { get; set; }

        public ScoreBoard(string cString, string jString)
        {
            c = ulong.Parse(cString);
            j = ulong.Parse(jString);
        }

        public ulong Closeness()
        {
            return c > j ? c - j : j - c;
        }

        public bool IsBetterThan(ScoreBoard score)
        {
            if (score == null)
            {
                return true;
            }
            else if (c + j == score.c + score.j)
            {
                if (c == score.c)
                {
                    if (j > score.j)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (c < score.c)
                {
                    return true;
                }
                else
                {
                    return false;
                }

            }
            else if (Closeness() < score.Closeness())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    class Program
    {
        static string ReplaceFirst(string text, string search, string replace)
        {
            int pos = text.IndexOf(search);
            if (pos < 0)
            {
                return text;
            }
            return text.Substring(0, pos) + replace + text.Substring(pos + search.Length);
        }

        static ScoreBoard Best { get; set; }

        static void Brute(string c, string j)
        {
            if (c.Contains('?'))
            {
                for (int i = 0; i <= 9; i++)
                {
                    StringBuilder sb = new StringBuilder(c);
                    sb[c.IndexOf('?')] = i.ToString()[0];
                    Brute(sb.ToString(), j);
                }
            }
            else if (j.Contains('?'))
            {
                for (int i = 0; i <= 9; i++)
                {
                    StringBuilder sb = new StringBuilder(j);
                    sb[j.IndexOf('?')] = i.ToString()[0];

                    Brute(c, sb.ToString());
                }
            }
            else
            {
                ScoreBoard scoreBoard = new ScoreBoard(c, j);
                if (scoreBoard.IsBetterThan(Best))
                {
                    Best = scoreBoard;
                }
            }
        }

        static string RunCase(StreamReader inputReader)
        {
            string[] line = inputReader.ReadLine().Split(' ');
            string c = line[0];
            string j = line[1];

            // optimize by zeroing initial ?'s while characters are equal

            Best = null;
            Brute(c, j);

            int length = c.Length;
            string cString = Best.c.ToString("D" + length);
            string jString = Best.j.ToString("D" + length);

            return cString + " " + jString;
        }

        static String fileName = "B-small-attempt0";
        //static String fileName = "practice";
        static String pathToFiles = "../../" + "/" + fileName;
        static String inputFileName = pathToFiles + ".in";
        static String outputFileName = pathToFiles + ".out";

        static void Main(string[] args)
        {
            using (StreamReader inputReader = new StreamReader(inputFileName))
            {
                File.WriteAllText(outputFileName, string.Empty);
                using (StreamWriter outputFile = new StreamWriter(outputFileName))
                {
                    int testCaseCount = Int32.Parse(inputReader.ReadLine());
                    for (int caseIterator = 0; caseIterator < testCaseCount; caseIterator++)
                    {
                        String caseResult = RunCase(inputReader);
                        String caseOutput = "Case #" + (caseIterator + 1) + ": " + caseResult;
                        outputFile.WriteLine(caseOutput);
                        Console.Out.WriteLine(caseOutput);
                    }
                }
            }

            Console.Read();
        }
    }
}
