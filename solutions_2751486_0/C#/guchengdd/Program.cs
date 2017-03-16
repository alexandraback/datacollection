using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.IO;

namespace ProjectA
{


    class Program
    {
        const string Small = "A-small-attempt0.in";
        const string Large = "A-large.in";

        static void Main(string[] args)
        {
            string inFile = Small;
            //string inFile = Large;
            StreamReader readStream = new StreamReader(inFile);
            string outFile = inFile + ".out.txt";
            StreamWriter writer = new StreamWriter(outFile);

            string firstLine = readStream.ReadLine();

            int T = int.Parse(firstLine);
            for (int i = 1; i <= T; i++)
            {
                string line = readStream.ReadLine();
                string[] names = line.Split(' ');
                string name = names[0];
                int n = int.Parse(names[1]);
                string result = solve(name, n);
                writer.WriteLine("Case #" + i + ": " + result);
            }

            readStream.Close();
            writer.Close();
        }

        private static string solve(string name, int n)
        {
            int nValue = 0;
            List<string> substrings = new List<string>();
            
            Dictionary<int, string> strings = new Dictionary<int, string>();
            
            for (int length = n; length <= name.Length; length++)
            {
                // End index is tricky.
                for (int start = 0; start <= name.Length - length; start++)
                {
                    string substring = name.Substring(start, length);
                    substrings.Add(substring);
                    if (HasN(substring, n))
                        nValue++;
                }
            }

            return nValue+"";
        }

        private static bool HasN(string s, int n)
        {
            char[] non = { 'a', 'e', 'i', 'o', 'u' };

            int counter = 0;
            foreach (char c in s)
            {
                if (!non.Contains(c))
                {
                    counter++;
                }
                else
                {
                    counter = 0;
                }
                if (counter >= n)
                    return true;
            }
            return false;

        }
    }
}
