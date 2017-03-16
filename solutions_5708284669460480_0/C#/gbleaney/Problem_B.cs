using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam___Round_1C
{
    class Problem_B
    {
        private static decimal numKeys;
        private static decimal lettersInWord;
        private static int totalOutput;
        private static string keys;
        private static string target;
        private static Dictionary<char, decimal> keyCount;
        private static Dictionary<char, decimal> targetCount; 

        public static void Run()
        {
            List<string> problemOutput = new List<string>();

            // Open the file to read from. 
            using (StreamReader sr = File.OpenText(@"E:\Documents\Google Drive\Coding\Google Code Jam - Round 1C\Google Code Jam - Round 1C\B-small-attempt0.in"))
            {
                int testCases = Int32.Parse(sr.ReadLine());
                for (int caseNum = 0; caseNum < testCases; caseNum++)
                {
                    string[] testCase = sr.ReadLine().Split(' ');
                    numKeys = decimal.Parse(testCase[0]);
                    lettersInWord = decimal.Parse(testCase[1]);
                    totalOutput = int.Parse(testCase[2]);

                    keys = sr.ReadLine();
                    target = sr.ReadLine();

                    keyCount = new Dictionary<char, decimal>();

                    foreach (var key in keys)
                    {
                        if (keyCount.ContainsKey(key))
                        {
                            keyCount[key]++;
                        }
                        else
                        {
                            keyCount.Add(key, 1);
                        }
                    }

                    targetCount = new Dictionary<char, decimal>();

                    foreach (var letter in target)
                    {
                        if (targetCount.ContainsKey(letter))
                        {
                            targetCount[letter]++;
                        }
                        else
                        {
                            targetCount.Add(letter, 1);
                        }
                    }

                    IEnumerable<string> possibleCombinations = AllPosibilities(totalOutput);

                    decimal expectedValue = 0;

                    int maxBananas = 0;

                    foreach (string possibleCombination in possibleCombinations)
                    {
                        int numOccurances = CountOccurancesOfTarget(possibleCombination);
                        maxBananas = Math.Max(maxBananas, numOccurances);
                        expectedValue += GetProbability(possibleCombination) * numOccurances;
                    }
                        
                        //= GetOverlaps("ABABA");




                    problemOutput.Add(String.Format("Case #{0}: {1}", caseNum + 1, maxBananas - expectedValue));
                }
            }


            using (StreamWriter sw = File.CreateText(@"E:\Documents\Google Drive\Coding\Google Code Jam - Round 1C\Google Code Jam - Round 1C\B-small-attempt0.out"))
            {
                foreach (var line in problemOutput)
                {
                    sw.WriteLine(line);
                }
            }


        }

        private static int CountOccurancesOfTarget(string s)
        {
            int occurancees = 0;
            for (int i = 0; i <= s.Length - target.Length; i++)
            {
                if (s.Substring(i, target.Length) == target)
                {
                    occurancees++;
                }
            }
            return occurancees;
        }

        private static IEnumerable<string> AllPosibilities(int length)
        {
            if (length == 1)
            {
                foreach (KeyValuePair<char, decimal> keyValuePair in keyCount)
                {
                    yield return char.ToString(keyValuePair.Key);
                }
                
            }

            else
            {
                foreach (string posibility in AllPosibilities(length - 1))
                {
                    foreach (KeyValuePair<char, decimal> keyValuePair in keyCount)
                    {
                        yield return posibility + char.ToString(keyValuePair.Key);
                    }
                }
                
            }
        }

        public static decimal GetProbability(string str)
        {

            if (target.Any(c => !keyCount.ContainsKey(c)))
            {
                return 0.0m;
            }
            decimal prob = 1.0m;
            foreach (var c in str)
            {
                prob *= keyCount[c] / keys.Length;
            }

            return prob;
        }

        //private static HashSet<string> GetOverlaps(string str)
        //{
        //    HashSet<string> possibleOverlaps = new HashSet<string>();
        //    for (int i = 1; i <= str.Length; i++)
        //    {
        //        if (str.Substring(str.Length - i) == str.Substring(0, i))
        //        {
        //            string overlap = str + str.Substring(i);
        //            if (!possibleOverlaps.Contains(overlap) && overlap.Length <= totalOutput)
        //            {
        //                possibleOverlaps.Add(str + str.Substring(i));
        //            }
        //        }
        //    }
        //    return possibleOverlaps;
        //} 
    }
}
