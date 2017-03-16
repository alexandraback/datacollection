using System;
using System.Collections;
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
                const string inputFileName = @"C:\GoogleJam\C-small-attempt1.in";
                var allTestInputs = new List<string>(File.ReadAllLines(inputFileName));
                allTestInputs.RemoveAll(string.IsNullOrEmpty);
                allTestInputs.RemoveAt(0);
                var sb = new StringBuilder();
                int testIndex = 1;
                for (int i = 0; i < allTestInputs.Count;)
                {
                    var currentTestInput = new List<string>();
                    int N = int.Parse(allTestInputs[i]);
                    int nbLinesInCurrentTest = 1+N;
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

        private static string Process(List<string> inputs)
        {
            inputs.RemoveAt(0);

            IDictionary<string, int> leftCount = new Dictionary<string, int>();
            IDictionary<string, int> rightCount = new Dictionary<string, int>();

            var lines = new List<KeyValuePair<string, string>>();
            foreach(var c in inputs)
            {
                var leftWord = c.Split(' ')[0];
                var rightWord = c.Split(' ')[1];
                if (!leftCount.ContainsKey(leftWord))
                    leftCount.Add(leftWord, 0);
                ++leftCount[leftWord];
                if (!rightCount.ContainsKey(rightWord))
                    rightCount.Add(rightWord, 0);
                ++rightCount[rightWord];
                lines.Add(new KeyValuePair<string, string>(leftWord, rightWord));
            }

            int minimalScore = Dynamic(lines, lines.Count-1, leftCount, rightCount);

            return ""+(lines.Count-minimalScore);
        }

        private static int Dynamic(List<KeyValuePair<string, string>> lines, int maxAllowedIndex, IDictionary<string, int> leftCount, IDictionary<string, int> rightCount)
        {
            string leftWord = lines[maxAllowedIndex].Key;
            string rightWord = lines[maxAllowedIndex].Value;
            if (maxAllowedIndex == 0)
            {
                if ((leftCount[leftWord] >= 2) && (rightCount[rightWord] >= 2))
                    return 0;
                return 1;
            }


            int currentScore = int.MaxValue;

            if ((leftCount[leftWord]>=2)&&(rightCount[rightWord]>=2))
            {
                //we can try to remove it
                --leftCount[leftWord];
                --rightCount[rightWord];
                currentScore = Dynamic(lines, maxAllowedIndex - 1, leftCount, rightCount);
                ++leftCount[leftWord];
                ++rightCount[rightWord];
            }

            currentScore = Math.Min(currentScore, 1+Dynamic(lines, maxAllowedIndex - 1, leftCount, rightCount));
            return currentScore;
        }

        private static string Process2(List<string> inputs)
        {
            //int N = int.Parse(inputs[0]);
            IDictionary<char, int> count = new Dictionary<char, int>();

            var C = inputs[0].Split(' ')[0];
            var J = inputs[0].Split(' ')[1];

            List<char> C0 = new List<char>();
            foreach (var c in C)
                C0.Add(c);
            List<char> J0 = new List<char>();
            foreach (var j in J)
                J0.Add(j);


            var possibleC = AllPossibles(C0);
            var possibleJ = AllPossibles(J0);

            int currentBestC = possibleC[0];
            int currentBestJ = possibleJ[0];

            for(int c=0;c<possibleC.Count;++c)
                for(int j=0;j<possibleJ.Count;++j)
                {
                    if ((c == 0) && (j == 0))
                        continue;
                    TryToImprove2(possibleC[c], possibleJ[j], ref currentBestC, ref currentBestJ);
                }

            string strC = currentBestC + "";
            string strJ = currentBestJ + "";
            while (strC.Length<C0.Count)
                strC = "0" + strC;
            while (strJ.Length<J0.Count)
                strJ = "0" + strJ;


            return strC + " " + strJ;


            /*


            List<int> possibleStartC = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            if (C0[0] != '?')
                possibleStartC = new List<int> { C0[0] - '0' };

            List<int> possibleStartJ = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            if (J0[0] != '?')
                possibleStartJ = new List<int> { J0[0]-'0' };


            List<int> currentBestC = null;
            List<int> currentBestJ = null;


            for (int c = 0; c < possibleStartC.Count; ++c)
                for (int j = 0; j < possibleStartJ.Count; ++j)
                {

                    TryToImprove(C0, J0, possibleStartC[c], possibleStartJ[j], currentBestC, currentBestJ);
                }


                foreach (var c in inputs[0])
                {
                    if (count.ContainsKey(c))
                        ++count[c];
                    else
                        count.Add(c, 1);
                }

         */
        }

        private static void TryToImprove2(int c, int j, ref int currentBestC, ref int currentBestJ)
        {
            int diff = Math.Abs(c - j);
            int diffBest = Math.Abs(currentBestC - currentBestJ);

            if (diff != diffBest)
            {
                if (diff > diffBest)
                    return;
                currentBestC = c;
                currentBestJ = j;
                return;
            }

            if (c > currentBestC)
                return;
            if (c<currentBestC)
            {
                currentBestC = c;
                currentBestJ = j;
                return;
            }
            if (j < currentBestJ)
            {
                currentBestC = c;
                currentBestJ = j;
                return;
            }
        }

        private static  List<int> AllPossibles(List<char> C0)
        {
            List<List<int>> result = new List<List<int>>();

            foreach (var c in C0)
            {
                if (c == '?')
                    result.Add(new List<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
                else
                    result.Add(new List<int> {c - '0'});
            }
            List<int> final = new List<int>();

            foreach(var c in AllCombinations(result))
                final.Add(int.Parse(Join("", c)));
            final.Sort();
            return final;
        }

        public static IEnumerable<List<T>>  AllCombinations<T>(List<List<T>> allItems)
        {
            if ((allItems == null)||(allItems.Count == 0))
                yield break;
            foreach (var possibleAtIndex in allItems)
                if ((possibleAtIndex == null) || (0 == possibleAtIndex.Count))
                    yield break;

            var currentIndexes = new int[allItems.Count];
            for (;;)
            {
                var currentResult = new List<T>(allItems.Count);
                for (int i = 0; i < currentIndexes.Length; ++i)
                    currentResult.Add(allItems[i][currentIndexes[i]]);
                yield return currentResult;

                bool found = false;
                for(int i=0;i<allItems.Count;++i)
                {
                    if (currentIndexes[i]< (allItems[i].Count-1) )
                    {
                        ++currentIndexes[i];
                        found = true;
                        break;
                    }
                    currentIndexes[i] = 0;
                }
                if (!found)
                    yield break;
            }
        }

        private static void TryToImprove(List<char> C0, List<char> J0, int startC, int startJ, List<int> currentBestC, List<int> currentBestJ)
        {
            List<int> currentC = new List<int>();
            currentC.Add(startC);
            List<int> currentJ = new List<int>();
            currentJ.Add(startJ);

            //int i = Compare(currentC, currentJ);
            for(int i=1;i<C0.Count;++i)
            {
                int C_i = (C0[i] == '?') ? -1 : (C0[i] - '0');
                int J_i = (J0[i] == '?') ? -1 : (J0[i] - '0');
                if ((C_i!=-1)&&(J_i!=-1))
                {
                    currentC.Add(C_i);
                    currentJ.Add(C_i);
                }

            }

        }

        private static int Compare(List<int> currentC, List<int> currentJ)
        {
            for (int i = 0; i < currentC.Count;++i )
            {
                if (currentC[i] != currentJ[i])
                    return currentC[i] - currentJ[i];
            }
            return 0;
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