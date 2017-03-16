using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string filenName = @"A-small-attempt0.in";
            char[] delimiters = new char[] { ' ' };
            using (StreamReader sr = new StreamReader(filenName))
            {
                while (sr.Peek() >= 0)
                {
                    int numberOfTestCases = Convert.ToInt32(sr.ReadLine());

                    for (int i = 0; i < numberOfTestCases; i++)
                    {
                        string line = sr.ReadLine();
                        string[] fields = line.Split(delimiters);

                        string tribeMemberName = fields[0];
                        int length = Convert.ToInt32(fields[1]);

                        Console.WriteLine("Case #{0}: {1}", i + 1, GetNumberOfSubstrings(tribeMemberName, length));
                    }
                }
            }
        }

        public static Int64 GetNumberOfSubstrings(string name, int length)
        {
            Int64 numberOfSubstrings = 0;
            int locationOfConsonsantString = FindFirstConsonsantString(name, length);

            while (locationOfConsonsantString >= 0)
            {
                numberOfSubstrings += (locationOfConsonsantString + 1) * (name.Length - (locationOfConsonsantString + length) + 1);

                name = name.Substring(locationOfConsonsantString + 1);
                locationOfConsonsantString = FindFirstConsonsantString(name, length);
            }

            return numberOfSubstrings;
        }

        private static int FindFirstConsonsantString(string name, int length)
        {
            int index = 0;
            int substringLength = 0;
            while (index < name.Length)
            {
                char c = name[index];
                if (!isConsonant(c))
                {
                    index++;
                    continue;
                }
                bool foundSubstring = true;
                while (substringLength < length && (index+substringLength)<name.Length)
                {
                    if (!isConsonant(name[index + substringLength]))
                    {
                        foundSubstring = false;
                        break;
                    }
                    substringLength++;
                }
                if (substringLength == length && foundSubstring)
                {
                    return index;
                }

                substringLength = 0;
                index++;
            }

            return -1;
        }

        private static bool isConsonant(char c)
        {
            return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
        }
    }
}