using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ {
    class Program {
        static void Main(string[] args) {
            //string fileName = "input";
             string fileName = "B-small-attempt3";
            // string fileName = "A-large";

            string line;

            using (StreamReader inFile = new System.IO.StreamReader(fileName + ".in"))
            using (StreamWriter outFile = new System.IO.StreamWriter(fileName + ".out")) {
                ConsoleFileWriter cfw = new ConsoleFileWriter(outFile);
 
                line = inFile.ReadLine();

                int testcases = int.Parse(line);
                for (int i = 0; i < testcases; i++) {
                    solveSingleTestcase(inFile, cfw, i + 1);
                }

            }

            Console.ReadLine();
        }

        private static void solveSingleTestcase(StreamReader inFile, ConsoleFileWriter cfw, int testcaseNumber) {
            cfw.Write("Case #" + testcaseNumber + ": ");
            
            string line = inFile.ReadLine();
            int N = int.Parse(line);

            line = inFile.ReadLine();
            string[] cars = line.Split();

            char[] first = new char[N]; 
            char[] last = new char[N];

            for (int i = 0; i < N; i++) {
                first[i] = cars[i].ToCharArray()[0];
                last[i] = cars[i].ToCharArray()[cars[i].Length - 1];
            }

            int possibleWays = 1;

            // combine single-letter words
            for (int i = 0; i < 26; i++) {
                char x = (char) ('a' + i);

                List<int> wordsWithOnlyX = new List<int>();

                for (int j = 0; j < N; j++) {
                    if (first[j] == x && last[j] == x) {
                        wordsWithOnlyX.Add(j);
                    }
                }

                if (wordsWithOnlyX.Count > 1) {
                    int factor = 1;
                    for (int z = 1; z <= wordsWithOnlyX.Count; z++)
			{
			 factor = factor * z;
			}
                    possibleWays = possibleWays * factor;
                    for (int j = 1; j < wordsWithOnlyX.Count; j++) {
                  //      possibleWays *= 2;

                        int idx = wordsWithOnlyX.ElementAt(j);
                        for (int k = idx; k < N - 1; k++) {
                            cars[k] = cars[k + 1];
                            first[k] = first[k + 1];
                            last[k] = last[k + 1];
                        }
                        N--;
                    }
                }
            }

            if (N > 52) {
                cfw.WriteLine("0");
                return;
            }

            // find out which cars have "x" in them
            List<int>[] carsWithLetterX = new List<int>[26];
            for (int i = 0; i < 26; i++) {
                carsWithLetterX[i] = new List<int>();

                char x = (char) ('a' + i);

                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < cars[j].Length; k++) {
                        if (cars[j].ToCharArray()[k] == x) {
                            carsWithLetterX[i].Add(j);
                            break;
                        }
                    }
                }
            }

            // every letter can occur in only 3 words now! (e.g. aabb bb bbbbbccc)
            for (int i = 0; i < 26; i++) {
                if (carsWithLetterX[i].Count > 3) {
                    cfw.WriteLine("0");
                    return;
                }
            }

            // can all occurences of character x be connected? if so, in how many ways?
            for (int i = 0; i < 26; i++) {
                if (carsWithLetterX[i].Count == 0) { // 0 
                    continue;
                }

                // check if word is valid on its own
                for (int j = 0; j < carsWithLetterX[i].Count; j++) {
                    bool valid = isWordValidForChar(cars[carsWithLetterX[i].ElementAt(j)], i);
                    if (!valid) {
                        cfw.WriteLine("0");
                        return;
                    }
                }

                if (carsWithLetterX[i].Count == 1) {
                    continue;
                }

                // check if words can be combined
                possibleWays *= combinations(carsWithLetterX[i], first, last, i, cars);
                if (possibleWays == 0) {
                    cfw.WriteLine("0");
                    return;
                }
            }

            // if letters are completely independent of each other, there are multiple ways to place their strings
//            if (testcaseNumber == 5) {
//                Console.WriteLine("breakpoint");
//            }

            int indGroups = independentGroups(cars, N);

            int indGroupsFactor = 1;
            for (int i = 1; i <= indGroups; i++) {
                indGroupsFactor *= i;
            }

            //int indGroupsFactor = (int) Math.Pow(2, indGroups - 1);

            cfw.WriteLine("" + possibleWays * indGroupsFactor);
            return;
        }

        private static int independentGroups(string[] cars, int N) {
            int[] letterGroup = new int[26];

            for (int i = 0; i < 26; i++) {
                letterGroup[i] = -1;
            }

            bool change = true;
            while(change) {
                change = false;
            // look at all words
                for (int i = 0; i < N; i++) {
                    char[] charsInWord = cars[i].ToCharArray();

                    // compare all the individual letters in those words
                    for (int j = 0; j < charsInWord.Length; j++) {
                        for (int k = j; k < charsInWord.Length; k++) {
                            char jChar = charsInWord[j];
                            char kChar = charsInWord[k];

                            int jCharGroup = letterGroup[jChar - 'a'];
                            int kCharGroup = letterGroup[kChar - 'a'];
                            if(kCharGroup == -1) {
                                letterGroup[kChar - 'a'] = kChar - 'a';
                            }
                            kCharGroup = letterGroup[kChar - 'a'];

                            if (jCharGroup == kCharGroup) {
                                continue;
                            } else {
                                letterGroup[jChar - 'a'] = kCharGroup;
                                change = true;
                            }
                        }
                    }
                }
            }

            HashSet<int> groups = new HashSet<int>();
            for (int i = 0; i < 26; i++) {
                if(!groups.Contains(letterGroup[i])) {
                    groups.Add(letterGroup[i]);
                }
            }

            groups.Remove(-1);

            return groups.Count;
        }

        private static int combinations(List<int> wordIdxs, char[] first, char[] last, int i, string[] cars) {
/*            char x = (char)('a' + i);

            int firsts = 0;
            int lasts = 0;

            for (int j = 0; j < wordIdxs.Count; j++) {
                if (first[wordIdxs.ElementAt(j)] == x) {
                    firsts++;
                }
                if (last[wordIdxs.ElementAt(j)] == x) {
                    lasts++;
                }
            }

            if (firsts == 0 || lasts == 0) {
                return 0;
            }*/

            int possibilities = 0;

            if (wordIdxs.Count == 2) {
               /* if (firsts == 2 && lasts == 2) {
                    return 2;
                }

                return 1; */

                string w1 = cars[wordIdxs.ElementAt(0)];
                string w2 = cars[wordIdxs.ElementAt(1)];

                string[] p = new string[2];
                p[0] = w1 + w2;
                p[1] = w2 + w1;

                for (int j = 0; j < 2; j++) {
                    if(isWordValidForChar(p[j], i)) {
                        possibilities++;
                    }
                }

            } else { // Count = 3
                string w1 = cars[wordIdxs.ElementAt(0)];
                string w2 = cars[wordIdxs.ElementAt(1)];
                string w3 = cars[wordIdxs.ElementAt(2)];

                string[] p = new string[6];
                p[0] = w1 + w2 + w3;
                p[1] = w1 + w3 + w2;

                p[2] = w2 + w1 + w3;
                p[3] = w2 + w3 + w1;

                p[4] = w3 + w1 + w2;
                p[5] = w3 + w2 + w1;

                for (int j = 0; j < 6; j++) {
                    if(isWordValidForChar(p[j], i)) {
                        possibilities++;
                    }
                }
            }

            return possibilities;
        }

        private static bool isWordValidForChar(string word, int i) {
            char x = (char)('a' + i);
            char[] chars = word.ToCharArray();

            int occurence = -1;
            for (int j = 0; j < chars.Length; j++) {
                if (chars[j] == x) {
                    if (occurence == -1) {
                        occurence = j;
                    } else {
                        if (occurence == j - 1) {
                            occurence = j;
                        } else {
                            return false;
                        }
                    }
                }
            }

            return true;
        }

    }
}
