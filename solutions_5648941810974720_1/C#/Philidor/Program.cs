using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

//C:\Projects\CSharpContestProject\Prod\Program.cs
namespace GoogleJam
{
    internal class Program
    {
        //"C:\Projects\GoogleJam\Prod\Program.cs"
        private static void Main(string[] args)
        {
            checked
            {
                const string inputFileName = @"C:\GoogleJam\A-large.in";
                var allTestInputs = new List<string>(File.ReadAllLines(inputFileName));
                allTestInputs.RemoveAll(string.IsNullOrEmpty);
                allTestInputs.RemoveAt(0);
                var sb = new StringBuilder();
                int testIndex = 1;
                for (int i = 0; i < allTestInputs.Count;)
                {
                    var currentTestInput = new List<string>();
                    //int N = int.Parse(allTestInputs[i]);
                    int nbLinesInCurrentTest = 1;
                    for (int j = i; j < (i + nbLinesInCurrentTest); ++j)
                        currentTestInput.Add(allTestInputs[j]);
                    string testResult = "Case #" + (testIndex) + ": " + Process(currentTestInput);
                    Console.WriteLine(testResult);
                    if (i != 0)
                        sb.Append(Environment.NewLine);
                    sb.Append(testResult);
                    ++testIndex;
                    i += nbLinesInCurrentTest;
                }
                File.WriteAllText(inputFileName+".out", sb.ToString());
            }
        }


        private static string[] data = new string[]
                                           {
                                               "ZERO",
                                               "TWO",
                                               "SIX",
                                               "EIGHT",
                                               "FOUR",
                                               "SEVEN",
                                               "ONE",
                                               "THREE",
                                               "FIVE",
                                               "NINE"
                                           };



        private static string Process(List<string> inputs)
        {
            //int N = int.Parse(inputs[0]);
            IDictionary<char, int> count = new Dictionary<char, int>();

            foreach(var c in inputs[0])
            {
                if (count.ContainsKey(c))
                    ++count[c];
                else
                    count.Add(c,1);
            }

            List<int> digits = new List<int>();

            while (count.ContainsKey('Z')&&(count['Z']>=1))
            {
                --count['Z'];
                --count['E'];
                --count['R'];
                --count['O'];
                digits.Add(0);
            }
            while (count.ContainsKey('W') && (count['W'] >= 1))
            {
                --count['T'];
                --count['W'];
                --count['O'];
                digits.Add(2);
            }
            while (count.ContainsKey('X') && (count['X'] >= 1))
            {
                --count['S'];
                --count['I'];
                --count['X'];
                digits.Add(6);
            }
            while (count.ContainsKey('G') && (count['G'] >= 1))
            {
                --count['E'];
                --count['I'];
                --count['G'];
                --count['H'];
                --count['T'];
                digits.Add(8);
            }
            while (count.ContainsKey('U') && (count['U'] >= 1))
            {
                --count['F'];
                --count['O'];
                --count['U'];
                --count['R'];
                digits.Add(4);
            }
            while (count.ContainsKey('S') && (count['S'] >= 1))
            {
                --count['S'];
                --count['E'];
                --count['V'];
                --count['E'];
                --count['N'];
                digits.Add(7);
            }
            while (count.ContainsKey('O') && (count['O'] >= 1))
            {
                --count['O'];
                --count['N'];
                --count['E'];
                digits.Add(1);
            }
            while (count.ContainsKey('R') && (count['R'] >= 1))
            {
                --count['T'];
                --count['H'];
                --count['R'];
                --count['E'];
                --count['E'];
                digits.Add(3);
            }
            while (count.ContainsKey('V') && (count['V'] >= 1))
            {
                --count['F'];
                --count['I'];
                --count['V'];
                --count['E'];
                digits.Add(5);
            }
            while (count.ContainsKey('N') && (count['N'] >= 1))
            {
                --count['N'];
                --count['I'];
                --count['N'];
                --count['E'];
                digits.Add(9);
            }


            digits.Sort();

            return Join("", digits);
        }
        public static string Join<T>(string separator, IEnumerable<T> data)
        {
            if (data == null)
                return "";
            string result = "";
            int count = 0;
            foreach (var t in data)
            {
                if (count != 0)
                    result += separator;
                result += t.ToString();
                ++count;
            }
            return result;
        }
    }
}