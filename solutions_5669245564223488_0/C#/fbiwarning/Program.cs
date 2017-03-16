using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace R1CProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            String path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().
                GetModules()[0].FullyQualifiedName);

            String inputPath = path + Path.DirectorySeparatorChar + "B-small-attempt0.in";
            String outputPath = path + Path.DirectorySeparatorChar + "B-small-attempt0.in.txt";

            StreamReader reader = new StreamReader(inputPath);
            StreamWriter writer = new StreamWriter(outputPath);

            int caseNumber = 0;
            string line = reader.ReadLine();
            caseNumber = Convert.ToInt32(line);

            for (int i = 0; i < caseNumber; ++i)
            {
                DoOneCase(i + 1, reader, writer);
            }
            reader.Close();
            writer.Close();
        }
        public static long choiceCount = 0;

        public static void DoOneCase(int caseNumber, StreamReader reader, StreamWriter writer)
        {
            //isStringOk("aaaabc");

            // read row1
            string line = reader.ReadLine();

            int trainNum = Convert.ToInt32(line);

            line = reader.ReadLine();
            string[] word = line.Split(new char[] { ' ' });
            bool[] usedWord = new bool[word.Length];
            for (int i = 0; i < usedWord.Length; ++i) 
            {
                usedWord[i] = false;
            }

            choiceCount = 0;
            string newStr = "";
            for (int i = 0; i < word.Length; ++i)
            {
                mergeString(word, newStr, i, usedWord, 1);
            }

            string result = "" + choiceCount;
            writer.WriteLine("Case #" + caseNumber + ": " + result);
        }

        public static void mergeString(string[] word, string curStr, int curIndex, bool[] usedWord, int wordCount)
        {
            // merge str
            string newStr = curStr + word[curIndex];
            usedWord[curIndex] = true;

            // judge str
            //Console.WriteLine(newStr);
            if (isStringOk(newStr)) {
                if (wordCount == word.Length) 
                {
                    choiceCount++;
                    //Console.WriteLine(newStr);
                    usedWord[curIndex] = false;
                    return;
                }
                for (int i = 0; i < word.Length; ++i) 
                {
                    // is used
                    if (!usedWord[i])
                    {
                        mergeString(word, newStr, i, usedWord, wordCount + 1);
                    }
                }
            }
            usedWord[curIndex] = false;
            //Console.WriteLine("not ok");
        }
        

        public static bool isStringOk(String str) 
        {
            List<char> occur = new List<char>();
            char curCh = ' ';
            for (int i = 0; i < str.Length; ++i) {
                char ch = str[i];
                if (ch != curCh)
                {
                    if (occur.Contains(ch))
                    {
                        return false;
                    }
                    else 
                    {
                        curCh = ch;
                        occur.Add(ch);
                    }
                }
            }
            return true;
        }
    }
}
