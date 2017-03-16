using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam2012
{
    class Program
    {

        private static TextWriter _Output;
        private static TextReader _Input;

        private static Dictionary<char, char> _CharMapping;
        
        static void Main(string[] args)
        {
            _Input = new StreamReader("C:\\temp\\codejam2012\\B-small-attempt0(1).in");
            _Output = new StreamWriter("C:\\temp\\codejam2012\\Output.txt");

            //_QualificationProblemA_Speaking_in_Tongues();
            _QualificationProblemB_Dancing_With_the_Googlers();

            _Input.Close();
            _Output.Close();
        }
        
        static void _QualificationProblemB_Dancing_With_the_Googlers()
        {
            int lines = int.Parse(_Input.ReadLine());
            for (int i = 0; i < lines; i++)
            {
                List<int> line = _Input.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                _Output.Write(String.Format("Case #{0}: {1}", i + 1, GetNumber(line)));
                if (i < lines - 1)
                {
                    _Output.WriteLine();
                }
            }
        }

        static int GetNumber(List<int> line)
        {
            int result = 0;
            int suppriseCount = 0;
            int N = line[0];
            int S = line[1];
            int p = line[2];
            List<int> scores = line.GetRange(3, N);

            int successWithoutSuppriseLimit = p * 3 - 2;
            int successWithSuppriseLimit = p * 3 - 4;

            foreach (int i in scores)
            {
                if (i >= successWithoutSuppriseLimit)
                {
                    result++;
                }
                else if (successWithSuppriseLimit >= 0 && i >= successWithSuppriseLimit && suppriseCount < S)
                {
                    result++;
                    suppriseCount++;
                }
            }
            return result;
        }

        static void _QualificationProblemA_Speaking_in_Tongues() 
        {
            _CharMapping = new Dictionary<char,char>();

            FillDictionary( "qyeejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv",
                "zaoour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"        
                );
            FillLastChar();

            int lines = int.Parse(_Input.ReadLine());
            for (int i = 0; i < lines; i++)
            {
                _Output.Write(String.Format("Case #{0}: {1}", i + 1, Translate(_Input.ReadLine())));
                if (i < lines - 1)
                {
                    _Output.WriteLine();
                }
            }
        }

        static string Translate(string googlish)
        {
            string result = "";

            for (int i = 0; i < googlish.Length; i++)
            {
                result += _CharMapping[googlish[i]];
            }
            return result;
        }

        static void FillDictionary(string googlish, string english)
        {
            for (int i = 0; i < googlish.Length; i++)
            {
                if (!_CharMapping.ContainsKey(googlish[i]))
                {
                    _CharMapping.Add(googlish[i], english[i]);
                }
            }
        }

        static void FillLastChar()
        {
            List<char> googlish = _CharMapping.Keys.ToList();
            List<char> english = _CharMapping.Values.ToList();
            char googlishC = ' ';
            char englishC = ' ';

            for (char c = 'a'; c <= 'z'; c++)
            {
                if (!english.Contains(c))
                {
                    englishC = c;
                }
                if (!googlish.Contains(c))
                {
                    googlishC = c;
                }
            }

            _CharMapping.Add(googlishC, englishC);

        }
    }
}
