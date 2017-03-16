using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Numerics;
using System.Text;

namespace ProblemA
{
    public static class Constants
    {
        public const string INPUT_FILE = "A-large.in";
        public const string OUTPUT_FILE = "A-large.out";
        //public const string INPUT_FILE = "sample.in";
        //public const string OUTPUT_FILE = "sample.out";
    }

    public static class Assertion
    {
        public static void Assert(bool statement, string message)
        {
            if (!statement)
            {
                throw new ApplicationException(message);
            }
        }
    }

    public class Case
    {
        private string m_Source;
        private string m_String;

        private string RemoveOccurences(string source, char toRemove, int countToRemove)
        {
            char[] stringContent = source.ToCharArray();
            for (var i = 0; i < stringContent.Length; i++)
            {
                if (countToRemove > 0)
                {
                    if (stringContent[i] == toRemove)
                    {
                        --countToRemove;
                        stringContent[i] = 'P';
                    }
                }
                else
                {
                    break;
                }
            }
            var result = new string(stringContent);
            return result.Replace("P", "");
        }

        public Case(StreamReader file)
        {
            m_String = file.ReadLine();
            m_Source = m_String;
        }

        public string GetResult()
        {
            var numbers = new List<int>();

            // do the easy ones
            RemoveNumber("Z", new char[]{'E','R','O'}, numbers, 0);
            RemoveNumber("G", new char[] { 'E', 'I', 'H', 'T' }, numbers, 8);
            RemoveNumber("X", new char[] { 'S', 'I'}, numbers, 6);
            RemoveNumber("S", new char[] { 'E', 'V', 'E', 'N' }, numbers, 7);
            RemoveNumber("V", new char[] { 'F', 'I', 'E' }, numbers, 5);
            RemoveNumber("U", new char[] { 'F', 'O', 'R' }, numbers, 4);
            RemoveNumber("W", new char[] { 'T', 'O' }, numbers, 2);
            RemoveNumber("T", new char[] { 'E', 'H','R','E' }, numbers, 3);
            RemoveNumber("I", new char[] { 'N', 'N', 'E' }, numbers, 9);
            RemoveNumber("N", new char[] { 'O', 'E' }, numbers, 1);

            if (m_String.Length > 0)
            {
                throw new Exception("Did not process all numbers");
            }

            numbers.Sort();
            var numbersString = new StringBuilder();
            foreach (var number in numbers)
            {
                numbersString.Append(number.ToString());
            }

            return numbersString.ToString();
        }


        private void RemoveNumber(string target, char[] friends, List<int> numbers, int number)
        {
            if (m_String.Contains(target))
            {
                var zeds = 0;
                for (var i = 0; i < m_String.Length; i++)
                {
                    if (m_String[i] == target[0])
                    {
                        ++zeds;
                        numbers.Add(number);
                    }
                }
                m_String = RemoveOccurences(m_String, target[0], zeds);    
                foreach (var friend in friends)
                {
                    m_String = RemoveOccurences(m_String, friend, zeds);    
                }
            }
        }


    }

    public class Program
    {
        public static void Main()
        {
            var cases = new List<Case>();
            using (var file = new StreamReader(Constants.INPUT_FILE))
            {
                var numCases = int.Parse(file.ReadLine());
                for (var i = 0; i < numCases; i++)
                {
                    cases.Add(new Case(file));
                }
            }
            using (var file = new StreamWriter(Constants.OUTPUT_FILE))
            {
                var caseNumber = 1;
                foreach (var theCase in cases)
                {
                    Console.Write("Starting case " + caseNumber + "...");
                    file.Write("Case #" + caseNumber + ": " + theCase.GetResult() + "\n");
                    Console.WriteLine("FINISHED");
                    ++caseNumber;
                }
            }
        }
    }
}
