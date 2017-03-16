using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Qualification
{
    public class SpeakingInTongues
    {
        [STAThread]
        public static void Main(string[] args)
        {
            string bigStr = "We have come up with the best possible language here at Google called Googlerese To translate text into Googlerese we take any message and replace each English letter with another English letter This mapping is onetoone and onto which means that the same input letter always gets replaced with the same output letter and different input letters always get replaced with different output letters A letter may be replaced by itself Spaces are left asis For example and here is a hint our awesome translation algorithm includes the following three mappings a  and zq This means that a zoo will become y qeeooglerese is based on the best possible replacement mapping and we will never change it It will always be the same In every test case We will not tell you the rest of our mapping because that would make the problem too easy but there are a few examples below that may helpGiven some text in Googlerese can you translate it to back to normal textSolving this problemUsually Google Code Jam problems have  Small input and  Large input This problem has only  Small input Once you have solved the Small input you have finished solving this problemInputThe first line of the input gives the number of test cases T T test cases follow one per lineEach line consists of a string G in Googlerese made up of one or more words containing the letters a z There will be exactly one space character between consecutive words and no spaces at the beginning or at the end of any lineutputor each test case output one line containing Case X S where X is the case number and S is the string that becomes G in Googlerese";
            bigStr = bigStr + "The experience for division 1 and division 2 coders these two problems is very similar. In fact, division 1 coders basically have to solve SkewedPerspectives (The division 2 version of this problem) as a sub-problem of the larger one. Go read the explanation for that problem. Once you find and understand the rules surrounding that problem, you can try to solve this version that is about counting the valid views rather than just verifying if the given ones are compliant or notnce we understand the division 2 version, we can use some of its bag of tricks. It is still helpful to begin to consider all cubes as the same color. But we need a method to calculate, for each view we find that has a total of viewCubes cubes, the number of ordered ways to pick viewCubes cubes from the overall allowed cubes of each color. This problem can be solved using dynamic programming with the aid of combinatorics: Let f(x, n) be the number of ordered ways to pick x cubes out of the available cubes of the first n colors. We can pick any number of cubes of color (n-1) between 0 and min(x, cubes[n-1]). If we pick y cubes of the (n-1)-th, then there are f(x-y, n-1) ordered ways to pick the remaining cubes. In order to combine the y picked cubes with the (x-y) cubes of the remaining colors, we need to pick y positions out of x positions : Binomial(x, y).It is time to count the total number of views. This is yet another dynamic programming problem. The basic idea is to move from bottom to top of the squares visible in the view and pick for each position whether it will have a cube or a prism. We need to be careful not to create the same view twice. For this, we need to consider that groups of black squares are different if they are even or not.he state: From the division 2 version we can see that there are many variables needed for the state. But you should also notice that the constraints are very low, so a high dimension may be necessary. The current number of cubes in the view. totalCubes. We need this for many reasons, but for example, to be able to count the number of ways to pick colors for the current view we picked.he current number of times we used a pair of black squares. The current number of times we placed a prism in the view. We will call it used2. This is needed to, for example, know the number of remaining prisms.The current number of times we used a single black square, that is the number of times we changed to the next column and placed a prism as close to the bottom as possible. used1. This variable is equivalent to the current width minus 1. Thanks to it we do not need to include the current width.Note that the three last variables determine the current height of the view. totalCubes + 2*used2 + used1.Remember from the division 2 explanation that whenever we move to a new column to place a prism, it creates empty space that must be filled. The empty space will be composed of two parts: fill1: This is the number of places that forcefully need cubes (remember that this happens when the empty space in a column is odd). We need it to know the number of remaining cubes. fill2: The number of spaces of size 1x2. Which we can eventually replace with a prism or 2 cubes each.The algorithm will decide for each position in the view, the color of the position of the view. This yields a complication though. If we want to process each state in O(1) time, we have to be careful about not counting some sequences twice. Note that in order to make a group of an odd number of black squares, we need to make only one move to the next column and then all the remaining squares in the group are single prisms. This allows us to combine the creation of even and odd-numbered groups by just deciding when to use a single square to turn the sequence even. In order to avoid repeating a sequence and also to follow the rule we found in the division 2 version about always placing the column-changing prism as low as possible, we need to make the decision whether we are making an even or odd group at the beginning of it. In other words, we should never place a 1x1 black square (and change column) after we placed a complete prism. But we can place complete prisms after each other or after a single 1x1 black square. This leads to the addition of a new variable to the state: lastBlack which tells us if the last square we placed in the view was black (1) or not (0).That previous rule was very nice, but remember this image:";
            bigStr = bigStr + "Even number of wordse want the final palindrome string to have an even number of words. It is useful to look at the examples and notice that each word has a pair word that will be placed at the opposite side of the final string. For ABC its pair is CBA. For TTTT it is TTTT. It is also easy to note that the pair of a word is its reverse. Note also, that the input may contain the same word multiple times, this also means that there may be multiple pairs of a word and its reverse in the input (For example, the third palindrome in the examples above). Note that choosing to add the pair ABC, CBA to the final string will not make us unable to choose DEF. We can tell that a given word is only dependent on the availability of its reverse. Because of this reason, we can treat each word and its reverse separately when picking the combination that maximizes the score. Maximizing the score is easy once we know we can do it separately for each word. Let us try the first example: ABC-DEF-FED-CBA, we will treat ABC and CBA without considering the other words: Imagine there was one ABC word and two CBA words: We can pick at most one ABC-CBA pair and since we want to maximize the score, we should pick the CBA card that has the best score and ignore the other. A similar logic can be used when there are x ABC cards and y CBA cards: If x is larger than y, we can pick all CBA cards and then pick the y ABC cards that yield the maximum score sum - which translates into picking the cards with the y largest scores. A similar scenario happens if y is larger than x: Pick the x CBA cards with the largest scores and all the x ABC cards available. We can generalize this idea to any word and its given reverse.The strategy varies when the word is equal to its reverse (For example, XYYX). In this case, the word is not dependent on a different word to be paired with. So we just need to pick an even amount of such cards. If the number of available cards is x, and x is even, then we should pick all the cards, because we want to maximize the score. If x was odd, then we must pick all cards but one. In order to maximize the score, the card that gets picked should be the one with the lowest score.It is possible to implement this algorithm in O(n*n*log(n)). For each of the n words in the input, use a O(n) loop to find all of the instances of the word and its reverse in order to create a list of card scores availalbe for the word and the reverse. Then it is necessary to sort the scores to finally pick the best scores using the logic described in the two previous paragraphs.An odd number of wordsIf we want to pick an odd number to form the final string, the one thing that changes is that there is now a palindrome word that should be placed in the middle. In the previous examples:ABCBAAT-GH-AA-HG-TAAABB-XYYX-BBAAIf we simply removed the middle words, the results would be , AT-GH-HG-TA and AABB-BBAA. Those are, once again, cases with an even number of words. If we want an odd number of words, we may simply pick a palindrome to use in the middle, and then follow the strategy that was used for an even number of words - ignoring the word that was picked for the middle - . There are at most n words we can pick for the middle position, and we have solved the even case in O(n*n*log(n)), adding a new n factor is not going to make the algorithm very slow. So we may simply try all possible middle words (including no middle word at all, because the best result may use an even amount of cards) and use the one that yields the largest maximum score. The following is a c++ implementation of the ideas discussed here:";
            bigStr = bigStr.ToLower();
            var defWordCount = new SortedDictionary<char, int>();
            foreach (char ch in bigStr)
            {
                if (ch < 'a' || ch > 'z') continue;
                if (!defWordCount.ContainsKey(ch)) defWordCount[ch] = 0;
                defWordCount[ch]++;
            }

            var dic = new SortedDictionary<char, char>();
            dic[' '] = ' ';

            dic['q'] = 'z';
            dic['z'] = 'q';

            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var srd = new StreamDataRead(sr);

            int tc = Convert.ToInt32(srd.GetNext());
            srd.GetNextLine();

            var defLines = new string[3];
            defLines[0] = "our language is impossible to understand";
            defLines[1] = "there are twenty six factorial possibilities";
            defLines[2] = "so it is okay if you want to just give up";

            var wordCount = new SortedDictionary<char, int>();
            var lines = new string[tc];
            var newlines = new string[tc];
            for (int i = 0; i < tc; i++)
            {
                lines[i] = srd.GetNextLine().ToString();
                for (int j = 0; j < lines[i].Length; j++)
                {
                    char ch = lines[i][j];
                    if (!wordCount.ContainsKey(ch)) wordCount[ch] = 0;
                    wordCount[ch]++;

                    if (i < 3) dic[lines[i][j]] = defLines[i][j];
                }
            }

            foreach (var d in dic)
            {
                defWordCount.Remove(d.Value);
                wordCount.Remove(d.Key);
            }

            while (wordCount.Count != 0)
            {
                char wC = ' ';
                int max = wordCount.Values.Max();
                foreach (var ww in wordCount)
                    if (ww.Value == max)
                    {
                        wC = ww.Key;
                        break;
                    }
                wordCount.Remove(wC);

                char dWC = ' ';
                max = defWordCount.Values.Max();
                foreach (var ww in defWordCount)
                    if (ww.Value == max)
                    {
                        dWC = ww.Key;
                        break;
                    }

                defWordCount.Remove(dWC);
                dic[wC] = dWC;
            }

            int ii = 1;
            foreach (string line in lines)
            {
                sw.Write(String.Format("Case #{0:G}: ", ii++));
                foreach (char ch in line)
                    sw.Write(dic[ch]);
                sw.Write('\n');
            }

            sr.Close();
            sw.Close();
        }
    }
}