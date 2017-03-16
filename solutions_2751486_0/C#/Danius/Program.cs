using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Consonants
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int maxOutputLength = "Case #100: 1000000".Length;

            using (var sr = new StreamReader("in.txt"))
            using (var sw = new StreamWriter("out.txt"))
            {

                int totalCases = Int32.Parse(sr.ReadLine());

                for (int testCaseCounter = 0; testCaseCounter < totalCases; testCaseCounter++)
                {
                    //Read input
                    var line = sr.ReadLineOfTokens();
                    string name = line.ReadString();
                    int n = line.ReadInt();
                    
                    //Solve problem
                    int result = GetNvalue(name, n);
                    
                    //Output result
                    var sb = new StringBuilder(maxOutputLength);
                    sb.AppendFormat("Case #{0}: {1}", (testCaseCounter + 1).ToString(), result.ToString());
                    sw.WriteLine(sb.ToString());
                }
            }
        }

        static int GetNvalue(string name, int n)
        {
            int nValue = 0;

            int nameLength = name.Length;
            int maxStartPos = name.Length - n;
            //for each substring
            for (int startPos = 0; startPos <= maxStartPos; startPos++)
            {
                int maxSubstringLength = nameLength - startPos; 
                for (int subStringLength = n; subStringLength <= maxSubstringLength; subStringLength++)
			    {
                    var subString = name.Substring(startPos, subStringLength);

                    if (ContainsNConsecutiveConsonants(subString, n))
                        nValue++;
			    }                
            }

            //  find at least n consecutive consonants

            return nValue;
        }

        static bool ContainsNConsecutiveConsonants(string s, int n)
        {
            int consecConsonants = 0;
            int sLength = s.Length;

            for (int i = 0; i < sLength; i++)
            {
                if(IsConsonant(s[i]))
                {
                    consecConsonants++;
                }
                else
                {
                    consecConsonants = 0;
                }
                if (consecConsonants >= n)
                    return true;
            }

            return false;
        }

        static bool IsConsonant(char c)
        {
            switch (c)
            {   
                //B, C, D, F, G, H, J, K, L, M, N, P, Q, R, S, T, V, X, Z,
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':                
                    return false;
                default:
                    return true;
            }
        }
    }

    /// <summary>
    /// Represents a line of tokens.
    /// </summary>
    public class LineOfTokens
    {
        string[] _tokens;
        int _nextToken;

        /// <summary>
        /// Initializes a new instance of the <see cref="firsttest.LineOfTokens"/> class.
        /// </summary>
        /// <param name='tokens'>
        /// Tokens.
        /// </param>
        public LineOfTokens(string[] tokens)
        {
            if (tokens == null) throw new ArgumentNullException("tokens");

            _tokens = tokens;
            _nextToken = 0;
        }

        /// <summary>
        /// Reads the next int.
        /// </summary>
        /// <returns>
        /// The int.
        /// </returns>
        public int ReadInt()
        {
            return Int32.Parse(_tokens[_nextToken++]);
        }

        public string ReadString()
        {
            return _tokens[_nextToken++];
        }

        /// <summary>
        /// Reads all tokens as ints.
        /// </summary>
        /// <returns>
        /// The ints.
        /// </returns>
        public IEnumerable<int> ReadAllInts()
        {
            return _tokens.Select(x => Int32.Parse(x));
        }
    }

    /// <summary>
    /// Useful extension methods.
    /// </summary>
    public static class Extensions
    {
        /// <summary>
        /// Reads a line of tokens from a StreamReader.
        /// </summary>
        /// <returns>
        /// The line of tokens.
        /// </returns>
        /// <param name='sr'>
        /// The StreamReader from where to read the line of tokens.
        /// </param>
        public static LineOfTokens ReadLineOfTokens(this StreamReader sr)
        {
            string[] tokens = sr.ReadLine().Split(' ');
            return new LineOfTokens(tokens);
        }        
    }
}
