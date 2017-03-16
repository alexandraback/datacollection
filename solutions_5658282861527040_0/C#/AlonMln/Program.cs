using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    static class Program
    {
        public static string FileName = "B-small-attempt0";
        //public static string FileName = "TestInput";

        static void Main(string[] args)
        {
            Console.WriteLine(2&3);
            CodeJamIO cj = new CodeJamIO();
            for (int p = 0; p < cj.casesCount; p++)
            {
                int[] inputs = cj.NextLineIntArray();
                int a = inputs[0];
                int b = inputs[1];
                int k = inputs[2];

                int counter = 0;
                for (int i = 0; i < a; i++)
                {
                    for (int j = 0; j < b; j++)
                    {
                        if ((int)(i & j) < k)
                        {
                            counter++;
                            //Console.WriteLine("("+i.ToString()+","+j.ToString()+") ");
                        }
                    }
                }
                cj.InsertValue(counter);
            }
            cj.Dispose();


        }

        #region A

        static int MinChanges(string word, int i, string wanted)
        {
            if (word == wanted)
                return 0;

            int nothing = MinChanges(word, i + 1, wanted);
            int remove = int.MaxValue;

            if (i + 1 < word.Length)
                if (word[i + 1] == word[i])
                    remove = MinChanges(RemoveAt(word, i), i, wanted);
            int add = MinChanges(AddAt(word, i, word[i]), i + 2, wanted);

            return Math.Min(Math.Min(nothing, remove), add);
        }

        public static string RemoveAt(string s, int i)
        {
            if (i == 0)
                return s.Substring(1);
            if (i == s.Length - 1)
                return s.Substring(0, s.Length - 1);
            return s.Substring(0, i) + s.Substring(i + 1);
        }
        public static string AddAt(string s, int i, char c)
        {
            if (i == 0)
                return (c.ToString() + s);
            if (i == s.Length - 1)
                return (s + c.ToString());
            return (s.Substring(0, i) + c.ToString() + s.Substring(i));
        }

        static int[] OnlyCount(string s)
        {
            List<string> letters = new List<string>();
            List<int> counter = new List<int>();
            letters.Add(s[0].ToString());
            counter.Add(1);
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i].ToString() == letters[letters.Count - 1])
                    counter[counter.Count - 1]++;
                else
                {
                    letters.Add(s[i].ToString());
                    counter.Add(1);
                }
            }

            return counter.ToArray();
        }
        static string[,] lettersAndCount(string s)
        {
            List<string> letters = new List<string>();
            List<int> counter = new List<int>();
            letters.Add(s[0].ToString());
            counter.Add(1);
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i].ToString() == letters[letters.Count - 1])
                    counter[counter.Count - 1]++;
                else
                {
                    letters.Add(s[i].ToString());
                    counter.Add(1);
                }
            }
            string[,] rez = new string[letters.Count, 2];
            for (int i = 0; i < letters.Count; i++)
            {
                rez[i, 0] = letters[i];
                rez[i, 1] = counter[i].ToString();
            }
            return rez;
        }

        static char[] letterorder(string s)
        {
            List<char> c = new List<char>();
            c.Add(s[0]);
            for (int i = 1; i < s.Length; i++)
            {
                if (c[c.Count - 1] != s[i])
                    c.Add(s[i]);
            }
            return c.ToArray();
        }
        static bool CompareArrays(char[] a, char[] b)
        {
            if (a.Length != b.Length)
                return false;
            for (int i = 0; i < a.Length; i++)
            {
                if (a[i] != b[i])
                    return false;
            }
            return true;
        } 
        #endregion


    }


    public class CodeJamIO
    {
        /*
        יוצא מנקודת הנחה שהקלט הראשון הוא מספר המקרים
        */
        string PATH = @"C:\Users\Alon\Desktop\" + Program.FileName + ".in";

        int caseNumber = 1;
        public TextReader Input;
        public TextWriter Output;
        public int casesCount;

        public CodeJamIO()
        {
            Input = new StreamReader(PATH);
            Output = new StreamWriter(@"C:\Users\Alon\Desktop\codejam\output.txt");

            casesCount = NextLineInt();
            /*
            using (StreamReader sr = new StreamReader(PATH))
            {
                inputCount = sr.ReadToEnd().Replace("\r", " ").Split('\n').Length;

            }*/
        }

        public void InsertValue(object o)
        {
            string s = string.Format("Case #{0}: {1}", caseNumber.ToString(), o.ToString());
            caseNumber++;
            Console.WriteLine(s);
            Output.WriteLine(s);

        }

        public string NextLine()
        {
            return Input.ReadLine();
        }

        public string[] NextLineArray()
        {
            return NextLine().Split(' ');
        }


        public int[] NextLineIntArray()
        {

            return NextLine().Trim().Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        public int NextLineInt()
        {
            return int.Parse(Input.ReadLine());
        }

        public string[] ReadAll()
        {
            using (StreamReader sr = new StreamReader(PATH))
            {
                return (sr.ReadToEnd().Replace("\r", " ").Split('\n'));

            }
        }
        public void Dispose()
        {
            Input.Dispose();
            Output.Dispose();
        }

    }
}

/*

        public static BigInteger ToBigInt(this string s)
        {
            return BigInteger.Parse(s, CultureInfo.InvariantCulture);
        }

        public static int[] ToInt(this string[] s)
        {
            return s.Select(ToInt).ToArray();
        }


*/

