// --------------------------------------------------------------------------------------------------------------------
// <copyright file="Program.cs" company="">
//   
// </copyright>
// <summary>
//   The program.
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace CodeJam
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Text;

    /// <summary>
    /// The program.
    /// </summary>
    internal class Program
    {
        #region Constants and Fields

        /// <summary>
        /// The mappings.
        /// </summary>
        private static readonly Dictionary<char, char> Mappings = new Dictionary<char, char> 
        {
                { 'a', 'y' }, 
                { 'b', 'h' }, 
                { 'c', 'e' }, 
                { 'd', 's' }, 
                { 'e', 'o' }, 
                { 'f', 'c' }, 
                { 'g', 'v' }, 
                { 'h', 'x' }, 
                { 'i', 'd' }, 
                { 'j', 'u' }, 
                { 'k', 'i' }, 
                { 'l', 'g' }, 
                { 'm', 'l' }, 
                { 'n', 'b' }, 
                { 'o', 'k' }, 
                { 'p', 'r' }, 
                { 'r', 't' }, 
                { 's', 'n' }, 
                { 't', 'w' }, 
                { 'u', 'j' }, 
                { 'v', 'p' }, 
                { 'w', 'f' }, 
                { 'x', 'm' }, 
                { 'y', 'a' }, 
                { 'z', 'q' }, 
                { 'q', 'z' }
            };

        #endregion

        #region Methods

        /// <summary>
        /// Decode text from Googlerese
        /// </summary>
        /// <param name="text">
        /// The text.
        /// </param>
        /// <returns>
        /// Decoded text.
        /// </returns>
        private static string DecodeGooglerese(string text)
        {
            var resultBuilder = new StringBuilder(text.Length);

            foreach (var character in text)
            {
                resultBuilder.Append(Mappings.ContainsKey(character) ? Mappings[character] : character);
            }

            return resultBuilder.ToString();
        }

        /// <summary>
        /// The main method.
        /// </summary>
        private static void Main()
        {
            using (var inputFileStream = File.Open("A-small.in", FileMode.Open))
            {
                using (var outputFileStream = File.Open("A-small.out", FileMode.Create))
                {
                    using (var outputFileWriter = new StreamWriter(outputFileStream))
                    {
                        using (var inputFileStreamReader = new StreamReader(inputFileStream))
                        {
                            long T = Convert.ToInt64(inputFileStreamReader.ReadLine());

                            for (long i = 0; i < T; i++)
                            {
                                outputFileWriter.WriteLine("Case #{0}: {1}", i + 1, DecodeGooglerese(inputFileStreamReader.ReadLine()));
                            }
                        }
                    }
                }
            }
        }

        #endregion
    }
}