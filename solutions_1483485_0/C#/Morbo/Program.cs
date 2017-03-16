using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CodeJam2012
{
    class Program
    {
        const string ConstFileNewlineFormat = "\n";
        const string ConstFilename = "A-small-attempt0";

        /// <summary>
        /// Main entry point. 
        /// </summary>
        /// <param name="args">The args.</param>
        static void Main(string[] args)
        {
            SolveASmall();
        }

        /// <summary>
        /// Solves the A-small.
        /// </summary>
        public static void SolveASmall()
        {
            // constants for current challange
            const string data1In = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
            const string data1Out = "our language is impossible to understand";

            const string data2In = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
            const string data2Out = "there are twenty six factorial possibilities";

            const string data3In = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
            const string data3Out = "so it is okay if you want to just give up";

            const string fullCode = "abcdefghijklmnopqrstuvwxyz";

            Dictionary<char, char> dict = new Dictionary<char, char>();
            // adding hint
            dict.Add('y', 'a');
            dict.Add('e', 'o');
            dict.Add('q', 'z');

            // building dictionary...
            for (int i = 0; i < data1In.Length; i++)
            {
                if (!dict.ContainsKey(data1In[i]))
                    dict.Add(data1In[i], data1Out[i]);
            }

            for (int i = 0; i < data2In.Length; i++)
            {
                if (!dict.ContainsKey(data2In[i]))
                    dict.Add(data2In[i], data2Out[i]);
            }

            for (int i = 0; i < data3In.Length; i++)
            {
                if (!dict.ContainsKey(data3In[i]))
                    dict.Add(data3In[i], data3Out[i]);
            }

            // detecting missing code
            for (int i = 0; i < fullCode.Length; i++)
            {
                if (!dict.ContainsKey(fullCode[i]))
                {
                    for (int j = 0; j < fullCode.Length; j++)
                    {
                        if (!dict.ContainsValue(fullCode[j]))
                        {
                            dict.Add(fullCode[i], fullCode[j]);
                        }
                    }
                }
            }

            var dataStringInput = ReadFile("c:\\temp\\" + ConstFilename + ".in");
            StringBuilder dataStringOutput = new StringBuilder();

            var data = dataStringInput.Split(new string[] { ConstFileNewlineFormat }, System.StringSplitOptions.None);

            // variable declaration
            int casesN = 0;
            string gString;

            // data reading into variables and solving cases
            int elem = 0;
            casesN = Convert.ToInt32(data[elem]);
            elem++;

            for (int n = 0; n < casesN; n++)
            {
                gString = data[elem];
                elem++;


                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < gString.Length; i++)
                {
                    sb.Append(dict[gString[i]]);
                }

                // formatting output
                dataStringOutput.Append("Case #");
                dataStringOutput.Append(n + 1);
                dataStringOutput.Append(": ");
                dataStringOutput.AppendLine(sb.ToString());
            }

            // -------------------------------------
            // all cases solved, writing output file
            WriteFile("C:\\temp\\" + ConstFilename + ".out", dataStringOutput.ToString());
        }

        /// <summary>
        /// Reads the file.
        /// </summary>
        /// <param name="filePath">The file path.</param>
        /// <returns>Contents of the file.</returns>
        public static string ReadFile(string filePath)
        {
            string rez = string.Empty;

            using (StreamReader sr = new StreamReader(filePath))
            {
                rez = sr.ReadToEnd();
            }

            return rez;
        }

        /// <summary>
        /// Writes the content to the file.
        /// </summary>
        /// <param name="filePath">The file path.</param>
        /// <param name="content">The content.</param>
        public static void WriteFile(string filePath, string content)
        {
            using (StreamWriter sr = new StreamWriter(filePath))
            {
                sr.Write(content);
            }
        }
    }
}
