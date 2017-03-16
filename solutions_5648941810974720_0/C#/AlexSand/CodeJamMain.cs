using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics; // BigInteger
//using JamMath;

namespace jam
{

    class CodeJamMain
    {
        //static string inputFile = @"C:\Users\a.gilotte\Downloads\test.txt";
        static string inputFile = @"C:\Users\a.gilotte\Downloads\A-small-attempt0.in";
        //static string inputFile = @"C:\Users\a.gilotte\Downloads\A-large.in";

        public static void Main()
        {
            AJam jamClass = new JamExoA();
            jamClass.Test();
            var lines = File.ReadAllLines(inputFile);

            var results = jamClass.GetResults(lines);
            //var results = jamClass.ParallelGetResults(lines);

            //var formated = FormatResultOneLine(results).ToList();
            var formated = AJam.FormatResult(results).ToList();
            var outputFile = inputFile.Replace(".txt", "") + "_output.txt";
            File.WriteAllLines(outputFile, formated);
        }

  
    }


    class JamExoA : AJam
    {
        public override IEnumerable<TestCase> EnumerateTests(IList<string> lines)
        {
            //return JamUtils.SplitCases(lines);
            return JamUtils.SplitCases(lines, 1);
        }
        public override string Solve(TestCase test)
        {
            var dico = new Dictionary<int, string>()
            {
            {0,"ZERO"}, {1,"ONE"}, {2,"TWO"}, {3, "THREE"}, {4, "FOUR"}, {5, "FIVE"}, {6, "SIX"}, {7, "SEVEN"}, {8, "EIGHT"}, {9, "NINE"}
            };

            var letters = dico.Values.SelectMany(s => s).ToList();
            var lettersSet = new HashSet<char>(letters);

            var letterCounts = new Dictionary<char, int>();
            foreach (var letter in lettersSet)
            {
                letterCounts[letter] = test.Header.Count(ch => ch == letter);
            }

            var result = new Dictionary<int, int>();
            int i ;
            char c;

            i = 0;
            c = 'Z';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 2;
            c = 'W';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 6;
            c = 'X';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 4;
            c = 'U';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 5;
            c = 'F';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 7;
            c = 'V';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 8;
            c = 'G';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 3;
            c = 'H';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 1;
            c = 'O';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            i = 9;
            c = 'I';
            result[i] = letterCounts[c];
            RemoveLetter(letterCounts, dico[i], result[i]);

            var str = "";
            for (int j = 0; j <= 9; j++)
            {
                for (int count = 0; count < result[j]; count++)
                {
                    str += j;
                }
            }
                
            return str;
        }

        void RemoveLetter(Dictionary<char, int> letterCounts, string letterStr, int count)
        {
            foreach (var letter in letterStr)
            {
                letterCounts[letter] -= count;
            }
        }

        public override void Test()
        { }
    }


    class JamExoB : AJam
    {
        public override IEnumerable<TestCase> EnumerateTests(IList<string> lines)
        {
            return JamUtils.SplitCases(lines);
            // return JamUtils.SplitCases(lines, 1);
        }
        public override string Solve(TestCase test)
        {
            return "";
        }
        public override void Test()
        { }
    }

    class JamExoC : AJam
    {
        public override IEnumerable<TestCase> EnumerateTests(IList<string> lines)
        {
            return JamUtils.SplitCases(lines);
            // return JamUtils.SplitCases(lines, 1);
        }
        public override string Solve(TestCase test)
        {
            return "";
        }
        public override void Test()
        { }
    }


}
