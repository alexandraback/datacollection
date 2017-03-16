using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace LSCoder.CodeJam.ConsoleApp
{
    /// <summary>
    /// Speaking in Tongues problem
    /// </summary>
    public class Googlerese : GoogleProblem
    {
        #region Fields

        private Dictionary<char, char> _dictionary
            = new Dictionary<char, char>
                  {
                      {'a', 'y'},
                      {'b', 'h'},
                      {'c', 'e'},
                      {'d', 's'},
                      {'e', 'o'},
                      {'f', 'c'},
                      {'g', 'v'},
                      {'h', 'x'},
                      {'i', 'd'},
                      {'j', 'u'},
                      {'k', 'i'},
                      {'l', 'g'},
                      {'m', 'l'},
                      {'n', 'b'},
                      {'o', 'k'},
                      {'p', 'r'},
                      {'q', 'z'},
                      {'r', 't'},
                      {'s', 'n'},
                      {'t', 'w'},
                      {'u', 'j'},
                      {'v', 'p'},
                      {'w', 'f'},
                      {'x', 'm'},
                      {'y', 'a'},
                      {'z', 'q'},
                      {' ', ' '}
                  };

        #endregion

        #region Constructors

        public Googlerese(string fileName)
            : base(fileName)
        {
        }

        #endregion

        #region Private Methods

        private string Decrypt(string line)
        {
            var newLine = new byte[line.Length];

            for (var i = 0; i < newLine.Length; i++)
            {
                newLine[i] = (byte)_dictionary[line[i]];
            }

            return System.Text.Encoding.ASCII.GetString(newLine);
        }

        #endregion

        #region Public Methods

        public override void Execute()
        {
            var testCasesCount = Int32.Parse(GetNextLine());

            for (var i = 0; i < testCasesCount; i++)
            {
                Trace.WriteLine(string.Format("Case #{0}: {1}", (i + 1), Decrypt(GetNextLine())));
            }
        }

        #endregion
    }
}
