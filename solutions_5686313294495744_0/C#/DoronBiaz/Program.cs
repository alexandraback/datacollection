using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2016
{
    class Program
    {
        #region Qaulification Round
        static Dictionary<string, int> pancakeToPlusDictionary = new Dictionary<string, int>();
        static Dictionary<string, int> pancakeToMinusDictionary = new Dictionary<string, int>(); 
        #endregion



        static void Main(string[] args)
        {
            string inputFilePath = @"C:\Users\Doron\Desktop\Work\GoogleCodeJam\2016\2016\Problem C\C-small-attempt0.in";
            string outputFilePath = @"C:\Users\Doron\Desktop\Work\GoogleCodeJam\2016\2016\Problem C\C-small-attempt0.out";
            using (FileStream outputFile = File.Open(outputFilePath, FileMode.Create, FileAccess.Write))
            {
                StreamWriter sw = new StreamWriter(outputFile);
                string[] inputLines = File.ReadAllLines(inputFilePath);
                //string[] inputLines = GetTestData();
                Init();
                int numOfTestCases = int.Parse(inputLines[0]);
                int testCaseNum = 1;
                int numOfLinesInCase = 1;
                int numRead = 1;
                for (int i = 1; i <= numOfTestCases; i++)
                {
                    numOfLinesInCase = int.Parse(inputLines[numRead]) + 1;
                    List<string> input = new List<string>();
                    for (int j = 0; j < numOfLinesInCase; j++)
                    {
                        input.Add(inputLines[numRead + j]);
                    }
                    numRead += numOfLinesInCase;
                    object answer = SolveProblem(input);
                    sw.WriteLine(string.Format("case #{0}:{1}", testCaseNum, answer));
                    testCaseNum++;
                }
                sw.Flush();
            }
        }

        private static void Init()
        {
            //InitPancakces();
        }

        

        private static string[] GetTestData()
        {
            return TestSheep();
        }

        

        private static object SolveProblem(List<string> p)
        {
            return SolveTopics(p);
        }

        private static object SolveTopics(List<string> p)
        {
            List<string> inputStr1 = new List<string>();
            List<string> inputStr2 = new List<string>();
            for (int i = 1; i < p.Count; i++)
            {
                inputStr1.Add(p.ElementAt(i).Split(' ')[0]);
                inputStr2.Add(p.ElementAt(i).Split(' ')[1]);
            }
            return " " + countFakes(inputStr1, inputStr2, 0).ToString();
        }

        private static int countFakes(List<string> first, List<string> second, int place)
        {
            if (first.Count == 1 || place == first.Count)
                return 0;

            List<string> firstCopy =  first.ToList();
            List<string> secondCopy =  second.ToList();
            string fisrtStr = firstCopy.ElementAt(place);
            string secondStr = secondCopy.ElementAt(place);
            firstCopy.RemoveAt(place);
            secondCopy.RemoveAt(place);
            bool isPossibleFake = firstCopy.Contains(fisrtStr) && secondCopy.Contains(secondStr);
            if (!isPossibleFake)
                return countFakes(first, second, place + 1);
            int ifNotFake = countFakes(first, second, place + 1);
            int ifFake = 1 + countFakes(firstCopy, secondCopy, place);
            return Math.Max(ifFake, ifNotFake);
        }


        private static object SolveGameScore(List<string> p)
        {
            string inputStr = p.ElementAt(0);
            string C = inputStr.Split(' ')[0];
            string J = inputStr.Split(' ')[1];
            int numOfQMarksInC = 0;
            int numOfQMarksInJ = 0;
            for (int i = 0; i < C.Length; i++)
            {
                if(C[i] == '?')
                {
                    numOfQMarksInC++;
                }
            }

            for (int i = 0; i < J.Length; i++)
            {
                if(J[i] == '?')
                {
                    numOfQMarksInJ++;
                }
            }

            double maxCMarksToCheck = Math.Pow(10, numOfQMarksInC);
            double maxJMarksToCheck = Math.Pow(10, numOfQMarksInJ);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < numOfQMarksInC; i++)
            {
                sb.Append("0");
            }
            string numOfCMarkDigits = sb.ToString();
            StringBuilder sb1 = new StringBuilder();
            for (int i = 0; i < numOfQMarksInJ; i++)
            {
                sb1.Append("0");
            }
            string numOfJMarkDigits = sb1.ToString();
            double currCToCheck = 0;
            double currJToCheck = 0;
            string bestCJ = "";
            double minScore = double.MaxValue;
            for (currCToCheck = 0; currCToCheck < maxCMarksToCheck; currCToCheck++)
            {
                for (currJToCheck = 0; currJToCheck < maxJMarksToCheck; currJToCheck++)
                {

                    //create numbers by replacing ?
                    char[] CTemp = C.ToCharArray(); ;
                    string currCSTR = currCToCheck.ToString(numOfCMarkDigits);
                    int i = currCSTR.Length - 1;
                    for (int k = CTemp.Length - 1; k >= 0 && i >= 0; k--)
                    {
                        if (CTemp[k] == '?')
                        {
                            CTemp[k] = currCSTR[i];
                            i--;
                        }
                    }

                    char[] JTemp = J.ToCharArray(); ;
                    string currJSTR = currJToCheck.ToString(numOfJMarkDigits);
                    int j = currJSTR.Length - 1;
                    for (int k = JTemp.Length - 1; k >= 0 && j >= 0; k--)
                    {
                        if (JTemp[k] == '?')
                        {
                            JTemp[k] = currJSTR[j];
                            j--;
                        }
                    }
                    string CTempSTR = new string(CTemp);
                    string JTempSTR = new string(JTemp);
                    double tempSore = Math.Abs(double.Parse(CTempSTR) - double.Parse(JTempSTR));
                    if (tempSore == 0)
                    {
                        return " " + CTempSTR + " " + JTempSTR;
                    }

                    if (tempSore < minScore)
                    {
                        bestCJ = " " + CTempSTR + " " + JTempSTR;
                        minScore = tempSore;
                    }
                }
            }

            return bestCJ;
        }


        private static object SolveDigits(List<string> p)
        {
            StringBuilder sb = new StringBuilder(" ");
            string inputStr = p.ElementAt(0);
            Dictionary<char, int> letters = new Dictionary<char, int>();
            Dictionary<int, int> digits = new Dictionary<int, int>();
            for (int i = 0; i < 10; i++)
			{
			    digits.Add(i,0);
			}
            

            for (int i = 0; i < inputStr.Length; i++)
            {
                if(!letters.ContainsKey(inputStr[i]))
                {
                    letters.Add(inputStr[i], 0);
                }
                letters[inputStr[i]] = letters[inputStr[i]] + 1;
            }

            //zero
            checkDigits(letters, digits, 0,"ZERO", 'Z');

            //two
            checkDigits(letters, digits, 2,"TWO", 'W');

            //four
            checkDigits(letters, digits, 4,"FOUR", 'U');
            
            //six
            checkDigits(letters, digits, 6,"SIX", 'X');
            
            //EIGHT
            checkDigits(letters, digits, 8,"EIGHT", 'G');
            
            //FIVE/NoFour
            checkDigits(letters, digits, 5,"FIVE", 'F');
            
            //SEVEN/noSix
            checkDigits(letters, digits, 7,"SEVEN", 'S');
            
            //NINE/noFiveSixEight
            checkDigits(letters, digits, 9,"NINE", 'I');
            
            //ONE/noTwoFour
            checkDigits(letters, digits, 1,"ONE", 'O');
            
            //THREE/noElse
            checkDigits(letters, digits, 3,"THREE", 'T');
            
            for (int i = 0; i < 10; i++)
			{
                for (int j = 0; j < digits[i]; j++)
			    {
			        sb.Append(i);
			    }
			}
            return sb.ToString();
        }

        private static void checkDigits(Dictionary<char, int> letters, Dictionary<int, int> digits, int digit, string DIGITS, char unique)
        {
            if (letters.ContainsKey(unique))
            {
                while (letters[unique] > 0)
                {
                    digits[digit] = digits[digit] + 1;
                    for (int i = 0; i < DIGITS.Length; i++)
                    {
                        letters[DIGITS[i]] = letters[DIGITS[i]] - 1;
                    }
                }
            }
        }

        #region 1A
        private static object SolveRank(int N, List<string> p)
        {
            List<int[]> intList = new List<int[]>();
            for (int i = 0; i < p.Count; i++)
            {
                string[] tempSTR = p[i].Split(' ');
                int[] tempInt = new int[N];
                for (int j = 0; j < tempSTR.Length; j++)
                {
                    tempInt[j] = int.Parse(tempSTR[j]);
                }
                intList.Add(tempInt);
            }

            int loc = 0;
            int missingloc = -1;
            int[] vect = null;
            var orderedList = intList.OrderBy(x => { return x[loc]; }).ToList();
            for (int i = 0; i < 2 * N - 1; i++)
            {
                if (orderedList.Count == 1)
                {
                    vect = orderedList[0];
                    missingloc = loc;
                    break;
                }
                orderedList = orderedList.OrderBy(x => { return x[loc]; }).ToList();
                if (orderedList[0][loc] == orderedList[1][loc])
                {
                    orderedList.RemoveAt(0);
                    orderedList.RemoveAt(0);
                    i++;
                }
                else
                {
                    vect = orderedList[0];
                    orderedList.RemoveAt(0);
                    missingloc = loc;
                    break;
                }
                loc++;
            }
            StringBuilder sb = new StringBuilder(' ');
            for (int i = 0; i < N; i++)
            {
                intList.Remove(intList.First(x => { return x[missingloc] == vect[i]; }));
            }

            orderedList = intList.OrderBy(x => { return x[missingloc]; }).ToList();

            for (int i = 0; i < N; i++)
            {
                if (i != missingloc)
                {
                    sb.AppendFormat("{0} ", orderedList[i][i]);
                }
                else
                {
                    sb.AppendFormat("{0} ", vect[i]);
                }
            }
            return sb.Remove(sb.Length - 1, 1).ToString();
        }

        private static object SolveLastWord(string p)
        {
            char maxLetter = p[0];
            string word = p[0].ToString();
            for (int i = 1; i < p.Length; i++)
            {
                if (p[i] >= maxLetter)
                {
                    maxLetter = p[i];
                    word = word.PadLeft(word.Length + 1, p[i]);
                }
                else
                {
                    word = word.PadRight(word.Length + 1, p[i]);
                }
            }

            return " " + word;
        }

        #endregion








        #region Qualification
        private static void InitPancakces()
        {
            pancakeToPlusDictionary.Add("-", 1);
            pancakeToPlusDictionary.Add("+", 0);
            pancakeToMinusDictionary.Add("-", 0);
            pancakeToMinusDictionary.Add("+", 1);
        }

        private static string[] TestSheep()
        {
            string[] testArray = new string[1000002];
            testArray[0] = "1000000";
            for (long i = 0; i <= 1000000; i++)
            {
                testArray[i + 1] = i.ToString();
            }
            return testArray;
        }

        private static object SolveFractiles(string p)
        {
            var inputs = p.Split(' ');
            long K = long.Parse(inputs[0]);
            long C = long.Parse(inputs[1]);
            long S = long.Parse(inputs[2]);

            //trivial solutions
            if (K == S)
            {
                StringBuilder sb = new StringBuilder();
                for (int i = 1; i <= K; i++)
                {
                    sb.AppendFormat(" {0}", i);
                }
                return sb.ToString();
            }

            if (C == 1)
            {
                return " IMPOSSIBLE";
            }

            //k is at least 2
            double currentTile = 2;
            double numOfCleanTiles = 0;
            double numOfTiles = Math.Pow(K, C);

            StringBuilder sbNonTrivial = new StringBuilder();
            while (currentTile <= numOfTiles)
            {
                sbNonTrivial.AppendFormat(" {0}", currentTile);
                numOfCleanTiles++;
                S--;
                currentTile = 2 * numOfCleanTiles * Math.Pow(K, C - 1) + 2 * numOfCleanTiles + 1;
            }

            if (S < 0)
            {
                return " IMPOSSIBLE";
            }

            return sbNonTrivial.ToString();
        }

        private static object SolveJamCoins(string p)
        {
            var inputs = p.Split(' ');
            long coinLength = long.Parse(inputs[0]);
            long numOfCoins = long.Parse(inputs[1]);
            Dictionary<double, string> jamCoins = new Dictionary<double, string>();
            Random rand = new Random();
            int[] tempCoin = new int[coinLength];
            tempCoin[0] = 1;
            tempCoin[coinLength - 1] = 1;
            while (numOfCoins != 0)
            {
                //get next coin
                bool coinValid = true;
                StringBuilder sb = new StringBuilder("1");
                for (int j = 1; j < coinLength - 1; j++)
                {
                    tempCoin[j] = rand.Next(2);
                    sb.Append(tempCoin[j]);
                }
                sb.Append("1");
                double base10Coin = -1;
                //check bases for divisor
                for (int bases = 2; bases < 11; bases++)
                {
                    double coinInBase = 0;
                    for (int j = 0; j < coinLength; j++)
                    {
                        coinInBase += tempCoin[j] * Math.Pow(bases, (coinLength - 1 - j));
                    }
                    //only valid in the last iteration- to check for dups
                    base10Coin = coinInBase;
                    //check for divisors 
                    double div = 3;
                    bool foundDiv = false;
                    double searchLimit = Math.Min(coinInBase, 999999);
                    while (div < searchLimit)
                    {
                        if (div != coinInBase && (coinInBase / div) % 1 == 0)
                        {
                            foundDiv = true;
                            break;
                        }
                        div += 2;
                    }

                    if (foundDiv)
                    {
                        sb.Append(' ').Append(div);
                    }
                    else
                    {
                        coinValid = false;
                        break;
                    }
                }

                //check coin valid
                if (coinValid && !jamCoins.ContainsKey(base10Coin))
                {
                    numOfCoins--;
                    jamCoins.Add(base10Coin, sb.ToString());
                }
            }

            StringBuilder answer = new StringBuilder().AppendLine();
            foreach (var item in jamCoins)
            {
                answer.AppendLine(item.Value);
            }

            return answer.Remove(answer.Length - 2, 2).ToString();
        }

        private static object SolveSheep(string p)
        {
            long N = long.Parse(p);
            if (N == 0)
            {
                return "INSOMNIA";
            }
            int count = 10;
            bool[] digits = new bool[] { false, false, false, false, false, false, false, false, false, false };
            int i = 0;
            long currNum = N; ;
            string currNumStr = string.Empty;
            while (count > 0)
            {
                i++;
                currNum = N * i;
                currNumStr = currNum.ToString();
                int tempDigit;
                //check digits of number
                for (int j = 0; j < currNumStr.Length; j++)
                {
                    //if not found digit yet
                    tempDigit = (int)currNumStr[j] - 48;
                    if (!digits[tempDigit])
                    {
                        count--;
                        digits[tempDigit] = true;
                    }
                }
                if (count == 0)
                {
                    break;
                }
            }
            return currNumStr;
        }

        private static int SolvePancakes(string p)
        {
            if (pancakeToPlusDictionary.ContainsKey(p))
            {
                return pancakeToPlusDictionary[p];
            }

            //check bottom of stack
            if (p.Last() == '+')
            {
                pancakeToPlusDictionary.Add(p, SolvePancakes(p.Remove(p.Length - 1)));
            }
            else
            {
                pancakeToPlusDictionary.Add(p, 1 + SolvePancakesToMinus(p.Remove(p.Length - 1)));
            }
            return pancakeToPlusDictionary[p];
        }

        private static int SolvePancakesToMinus(string p)
        {
            if (pancakeToMinusDictionary.ContainsKey(p))
            {
                return pancakeToMinusDictionary[p];
            }

            //check bottom of stack
            if (p.Last() == '-')
            {
                pancakeToMinusDictionary.Add(p, SolvePancakesToMinus(p.Remove(p.Length - 1)));
            }
            else
            {
                pancakeToMinusDictionary.Add(p, 1 + SolvePancakes(p.Remove(p.Length - 1)));
            }
            return pancakeToMinusDictionary[p];
        }
        #endregion
        
    }
}
