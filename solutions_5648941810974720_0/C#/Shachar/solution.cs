using Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace _2016_round_1B
{
    public class Getting_the_Digits : ICase
    {
        private string m_Line;
        private int[] m_Numbers = new int[10];

        public void DoAction()
        {
            string copy = m_Line.Clone() as string;
            string copyWithoutZero = RemoveAllZero(copy);
            string copyWithoutFour = RemoveAllFour(copyWithoutZero);
            string copyWithoutsIX = RemoveAllSix(copyWithoutFour);
            string copyWithoutSeven = RemoveAllSeven(copyWithoutsIX);
            string copyWithoutFive = RemoveAllFive(copyWithoutSeven);
            string copyWithouttWO = RemoveAllTwo(copyWithoutFive);
            string copyWithoutThree = RemoveAllThree(copyWithouttWO);
            string copyWithoutEight = RemoveAllEight(copyWithoutThree);
            string copyWithoutOne = RemoveAllOne(copyWithoutEight);
            string copyWithoutNine = RemoveAllNine(copyWithoutOne);

            if (copyWithoutNine != string.Empty)
            {
                throw new Exception("Error");
            }
        }

        public string GetPrintString()
        {
            string printString = string.Empty;

            for (int i = 0; i < 10; i++)
            {
                int count = m_Numbers[i];
                while (count != 0)
                {
                    printString += i.ToString();
                    count--;
                }
            }

            return printString;
        }

        public void ReadDataFromFile(StreamReader reader)
        {
            m_Line = reader.ReadLine();
        }

        private string RemoveAllZero(string line)
        {
            while (line.Contains("Z"))
            {
                m_Numbers[0]++;
                line = line.Remove(line.IndexOf("Z"), 1);
                line = line.Remove(line.IndexOf("E"), 1);
                line = line.Remove(line.IndexOf("R"), 1);
                line = line.Remove(line.IndexOf("O"), 1);
            }

            return line;
        }

        private string RemoveAllFour(string line)
        {
            while (line.Contains("U"))
            {
                m_Numbers[4]++;
                line = line.Remove(line.IndexOf("F"), 1);
                line = line.Remove(line.IndexOf("O"), 1);
                line = line.Remove(line.IndexOf("U"), 1);
                line = line.Remove(line.IndexOf("R"), 1);
            }

            return line;
        }

        private string RemoveAllSix(string line)
        {
            while (line.Contains("X"))
            {
                m_Numbers[6]++;
                line = line.Remove(line.IndexOf("S"), 1);
                line = line.Remove(line.IndexOf("I"), 1);
                line = line.Remove(line.IndexOf("X"), 1);
            }                                       

            return line;
        }

        private string RemoveAllSeven(string line)
        {
            while (line.Contains("S"))
            {
                m_Numbers[7]++;
                line = line.Remove(line.IndexOf("S"), 1);
                line = line.Remove(line.IndexOf("E"), 1);
                line = line.Remove(line.IndexOf("V"), 1);
                line = line.Remove(line.IndexOf("E"), 1);
                line = line.Remove(line.IndexOf("N"), 1);
            }

            return line;
        }

        private string RemoveAllFive(string line)
        {
            while (line.Contains("V"))
            {
                m_Numbers[5]++;
                line = line.Remove(line.IndexOf("F"), 1);
                line = line.Remove(line.IndexOf("I"), 1);
                line = line.Remove(line.IndexOf("V"), 1);
                line = line.Remove(line.IndexOf("E"), 1);
            }

            return line;
        }

        private string RemoveAllTwo(string line)
        {
            while (line.Contains("W"))
            {
                m_Numbers[2]++;
                line = line.Remove(line.IndexOf("T"), 1);
                line = line.Remove(line.IndexOf("W"), 1);
                line = line.Remove(line.IndexOf("O"), 1);
            }                                       

            return line;
        }

        private string RemoveAllThree(string line)
        {
            while (line.Contains("R"))
            {
                m_Numbers[3]++;
                line = line.Remove(line.IndexOf("T"), 1);
                line = line.Remove(line.IndexOf("H"), 1);
                line = line.Remove(line.IndexOf("R"), 1);
                line = line.Remove(line.IndexOf("E"), 1);
                line = line.Remove(line.IndexOf("E"), 1);
            }

            return line;
        }

        private string RemoveAllEight(string line)
        {
            while (line.Contains("H"))
            {
                m_Numbers[8]++;
                line = line.Remove(line.IndexOf("E"), 1);
                line = line.Remove(line.IndexOf("I"), 1);
                line = line.Remove(line.IndexOf("G"), 1);
                line = line.Remove(line.IndexOf("H"), 1);
                line = line.Remove(line.IndexOf("T"), 1);
            }

            return line;
        }

        private string RemoveAllNine(string line)
        {
            while (line.Contains("I"))
            {
                m_Numbers[9]++;
                line = line.Remove(line.IndexOf("N"), 1);
                line = line.Remove(line.IndexOf("I"), 1);
                line = line.Remove(line.IndexOf("N"), 1);
                line = line.Remove(line.IndexOf("E"), 1);
            }

            return line;
        }

        private string RemoveAllOne(string line)
        {
            while (line.Contains("O"))
            {
                m_Numbers[1]++;
                line = line.Remove(line.IndexOf("O"), 1);
                line = line.Remove(line.IndexOf("N"), 1);
                line = line.Remove(line.IndexOf("E"), 1);
            }                                       

            return line;
        }
    }
}
