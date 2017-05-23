using Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace _2016_round_1B
{
    public class Close_Match_BruteForce : ICase
    {
        private string m_FirstWord;
        private string m_SecondWord;

        private string m_MinimumFirstString;
        private string m_MinimumSecondString;
        private long m_MinimumFirst = long.MaxValue;
        private long m_MinimumSecond = long.MaxValue;
        private long m_MinimumDiffernce = long.MaxValue;

        private List<string> allPossibleFirst = new List<string>();
        private List<string> allPossibleSecond = new List<string>();

        public void DoAction()
        {
            RECURSIVE(m_FirstWord, allPossibleFirst);
            RECURSIVE(m_SecondWord, allPossibleSecond);

            foreach (string firstString in allPossibleFirst)
            {
                long firstNumber = long.Parse(firstString);
                foreach (string secondString in allPossibleSecond)
                {
                    long secondNumber = long.Parse(secondString);

                    if (Math.Abs(firstNumber - secondNumber) > m_MinimumDiffernce)
                    {
                        continue;
                    }

                    if (Math.Abs(firstNumber - secondNumber) < m_MinimumDiffernce)
                    {
                        m_MinimumFirstString = firstString;
                        m_MinimumSecondString = secondString;
                        m_MinimumFirst = firstNumber;
                        m_MinimumSecond = secondNumber;
                        m_MinimumDiffernce = Math.Abs(firstNumber - secondNumber);
                    }

                    if (firstNumber > m_MinimumFirst)
                    {
                        continue;
                    }

                    if (firstNumber < m_MinimumFirst)
                    {
                        m_MinimumFirstString = firstString;
                        m_MinimumSecondString = secondString;
                        m_MinimumFirst = firstNumber;
                        m_MinimumSecond = secondNumber;
                        m_MinimumDiffernce = Math.Abs(firstNumber - secondNumber);
                    }

                    if (secondNumber > m_MinimumSecond)
                    {
                        continue;
                    }

                    m_MinimumFirstString = firstString;
                    m_MinimumSecondString = secondString;
                    m_MinimumFirst = firstNumber;
                    m_MinimumSecond = secondNumber;
                    m_MinimumDiffernce = Math.Abs(firstNumber - secondNumber);
                }
            }
        }

        private void RECURSIVE(string word, List<string> list)
        {
            int index = word.IndexOf('?');
            if (index == -1)
            {
                list.Add(word.Clone() as string);
                return;
            }

            RECURSIVE(word.ReplaceAt(index, '0'), list);
            RECURSIVE(word.ReplaceAt(index, '1'), list);
            RECURSIVE(word.ReplaceAt(index, '2'), list);
            RECURSIVE(word.ReplaceAt(index, '3'), list);
            RECURSIVE(word.ReplaceAt(index, '4'), list);
            RECURSIVE(word.ReplaceAt(index, '5'), list);
            RECURSIVE(word.ReplaceAt(index, '6'), list);
            RECURSIVE(word.ReplaceAt(index, '7'), list);
            RECURSIVE(word.ReplaceAt(index, '8'), list);
            RECURSIVE(word.ReplaceAt(index, '9'), list);
        }

        public string GetPrintString()
        {
            return m_MinimumFirstString + " " + m_MinimumSecondString;
        }

        public void ReadDataFromFile(StreamReader reader)
        {
            string line = reader.ReadLine();
            string[] words = line.Split(' ');
            m_FirstWord = words[0];
            m_SecondWord = words[1];
        }
    }

    public static class StringUtils
    {
        public static string ReplaceAt(this string input, int index, char newChar)
        {
            if (input == null)
            {
                throw new ArgumentNullException("input");
            }

            char[] chars = input.ToCharArray();
            chars[index] = newChar;
            return new string(chars);
        }
    }
}
