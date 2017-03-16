using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace CodeJamRound1C2013Console
{
    class ProblemA_Consonants
    {

        public static void Run(string fname, string ofname)
        {
            string[] solution = ReadProblemA(fname);

            string[] output = new string[solution.Length];
            for (int i = 0; i < solution.Length; i++)
            {
                output[i] = String.Format("Case #{0}: {1}", i + 1, solution[i]);

                Console.Out.WriteLine(output[i]);

            }
            Helpers.IO.WriteOutput(ofname, output.Length, output);

            //Console.ReadLine();
        }

        public static string[] ReadProblemA(string fname)
        {
            #region example Input
            /*
             *  6
                XXXT
                ....
                OO..
                ....

                XOXT
                XXOO
                OXOX
                XXOO

                XOX.
                OX..
                ....
                ....

                OOXX
                OXXX
                OX.T
                O..O

                XXXO
                ..O.
                .O..
                T...

                OXXX
                XO..
                ..O.
                ...O
             
             */
            #endregion
            string[] outputStr = null;
            int inputlength = 0;
            int count = 0;
            StreamReader fr = new StreamReader("..\\..\\" + fname);
            while (!fr.EndOfStream)
            {
                if (inputlength == 0)
                {
                    string s = fr.ReadLine();
                    inputlength = Convert.ToInt32(s);
                    outputStr = new string[inputlength];
                }
                else
                {
                    ConsonantsCase input = new ConsonantsCase();
                    string[] inputs = fr.ReadLine().Split(' ');//cut empty line
                    input.name = inputs[0];
                    input.n = Convert.ToInt32(inputs[1]);
                    outputStr[count] = AnswerOfCase(input);
                    Console.Out.WriteLine(": " + outputStr[count]);
                    ++count;
                }
            }
            fr.Close();
            return outputStr;
        }

        public class ConsonantsCase
        {
            public string name;
            public int n;
        }

        public string vovewls = "aeiou";

        private static string AnswerOfCase(ConsonantsCase c)
        {
            int count = 0;
            // http://stackoverflow.com/questions/1912122/retrieve-all-possible-substring-matches-with-n-characters-from-a-string
            String input = c.name;
            Regex regex = new Regex(@"[^aeiou]{" + c.n + "}");
            //Console.WriteLine(regex.ToString());
            //int i = 0;
            //
            //while (i < input.Length - c.n + 1)
            //{
            //    Match m = regex.Match(input, i);
            //    if (m.Success)
            //    {
            //        Console.WriteLine(m.Value);
            //        i = m.Index + 1; //just increment one char, instead of length of match string
            //        count++;
            //    }
            //    else break;
            //}

            //http://stackoverflow.com/questions/10712903/how-to-find-all-possible-substrings-in-a-string
            var query =
    from i in Enumerable.Range(0, input.Length)
    from j in Enumerable.Range(0, input.Length - i + 1)
    where j >= c.n
    select input.Substring(i, j);
            foreach (var item in query)
            {
                if (regex.IsMatch(item))
                {
                    //Console.WriteLine(item);
                    count++;
                }
            }

            return count + "";
        }

    }
}
