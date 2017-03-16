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
        static string inputFile = @"C:\Users\a.gilotte\Downloads\B-small-attempt3.in";
        //static string inputFile = @"C:\Users\a.gilotte\Downloads\A-large.in";

        public static void Main()
        {
            AJam jamClass = new JamExoB();
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

    class JamExoB : AJam
    {
        public override IEnumerable<TestCase> EnumerateTests(IList<string> lines)
        {
            //return JamUtils.SplitCases(lines);
            return JamUtils.SplitCases(lines, 1);
        }
        public override string Solve(TestCase test)
        {
            var tokens = test.Header.Split(' ');
            var Coders = tokens[0];
            var Jammers = tokens[1];

            string c2 ;
            string j2;
            Solve(Coders,Jammers, out c2,out  j2);
            return "" + c2 + " " + j2;
        }

        void Solve(string c, string j, out string c2, out string j2)
        {
            var index = FirstUnknowsIndex(c, j);
            if (index == -1)
            {
                c2 = c;
                j2 = j;
                return;
            }
            var comp = CompareHeads(c, j, index);
            if (comp == 1)
            { 
            // c > j
                c2 = CompleteMin(c);
                j2 = CompleteMax(j);
                return;
            }
            if (comp == -1)
            {
                // c < j
                c2 = CompleteMax(c);
                j2 = CompleteMin(j);
                return;
            }
            // heads are the same
            if ((c[index] == j[index]))
                if (index == c.Length - 1) // last
                {
                    c2 = CompleteMin(c);
                    j2 = CompleteMin(j);
                    return;
                }
            var head = c.Substring(0, index);
            c = c.Substring(index);
            j = j.Substring(index);

            if (c[0] == j[0])
            {
                if (c[1] == '?' && j[1] == '?')
                {
                    c = "0" + c.Substring(1);
                    j = "0" + j.Substring(1);

                    Solve(c, j, out c2, out j2);
                    c2 = head + c2;
                    j2 = head + j2;
                    return;
                }
                // complete with 0 0
                c = "0" + c.Substring(1);
                j = "0" + j.Substring(1);
                Solve(c, j, out c2, out j2);
                var diff = GetDiff(c2, j2);

                c = "0" + c.Substring(1);
                j = "1" + j.Substring(1);
                string subsolC2, subsolJ2;
                Solve(c, j, out subsolC2, out subsolJ2);
                var diff2 = GetDiff(subsolC2, subsolJ2);
                if (diff2 < diff)
                {
                    c2 = subsolC2;
                    j2 = subsolJ2;
                    diff = diff2;
                }

                c = "1" + c.Substring(1);
                j = "0" + j.Substring(1);
                Solve(c, j, out subsolC2, out subsolJ2);
                diff2 = GetDiff(subsolC2, subsolJ2);
                if (diff2 < diff)
                {
                    c2 = subsolC2;
                    j2 = subsolJ2;
                    diff = diff2;
                }

                c2 = head + c2;
                j2 = head + j2;
                return;
            }

            if (c[0] == '?')
            {
                var charsToTry = CharsToTry(j[0]);
                c = charsToTry[0] + c.Substring(1);
                Solve(c, j, out c2, out j2);
                var diff = GetDiff(c2, j2);

                foreach (var cToTry in charsToTry.Skip(1))
                {
                    string subsolC2, subsolJ2;
                    c = cToTry + c.Substring(1);
                    Solve(c, j, out subsolC2, out subsolJ2);
                    var diff2 = GetDiff(subsolC2, subsolJ2);
                    if (diff2 < diff)
                    {
                        c2 = subsolC2;
                        j2 = subsolJ2;
                        diff = diff2;
                    }
                }
                c2 = head + c2;
                j2 = head + j2;
                return;
            }
            else
            {
                var charsToTry = CharsToTry(c[0]);
                j = charsToTry[0] + j.Substring(1);
                Solve(c, j, out c2, out j2);
                var diff = GetDiff(c2, j2);

                foreach (var cToTry in charsToTry.Skip(1))
                {
                    string subsolC2, subsolJ2;
                    j = cToTry + j.Substring(1);
                    Solve(c, j, out subsolC2, out subsolJ2);
                    var diff2 = GetDiff(subsolC2, subsolJ2);
                    if (diff2 < diff)
                    {
                        c2 = subsolC2;
                        j2 = subsolJ2;
                        diff = diff2;
                    }
                }
                c2 = head + c2;
                j2 = head + j2;
                return;
            }
       }

        List<char> CharsToTry(char c)
        {
            var list = new List<char>();

            if (c != '0')
                list.Add( (char)(((int) c) - 1)) ;
            list.Add(c);
            if (c != '9')
                list.Add((char)(((int)c) + 1));
            return list;
        }

        int CompareHeads(string a, string b, int headIndex)
        {
            for (int i = 0; i < headIndex; i++)
            {
                char ai = a[i];
                char bi = b[i];
                if ( ai> bi)
                    return 1;
                if (ai < bi)
                    return -1;
            }
            return 0;
        }

        int FirstUnknowsIndex(string a, string b)
        {
            int n = a.Length;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == '?' ||  b[i]  == '?' )
                    return i;
            }
            return -1;
        }


        int? FirstDiffIndex(string a, string b)
        {
            int n = a.Length;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != b[i])
                    return i;
            }
            return null;
        }


        BigInteger GetDiff(string s1, string s2)
        {

            var diff = GetValue(s1) - GetValue(s2);
            if (diff < 0)
                diff = -diff;
            return diff;
        }

        BigInteger GetValue(string s)
        {
            BigInteger v = 0;
            foreach (var c in s)
            {
                v *= 10;
                v += int.Parse(""+c);
            }
            return v;
        }

        string CompleteMax(string s)
        {
            return s.Replace("?", "9");
        }
        string CompleteMin(string s)
        {
            return s.Replace("?", "0");
        }






        public override void Test()
        { }
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
