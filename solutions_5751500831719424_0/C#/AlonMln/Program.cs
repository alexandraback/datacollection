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
        public static string FileName = "A-small-attempt0";
        //public static string FileName = "TestInput";

        static void Main(string[] args)
        {



            CodeJamIO cj = new CodeJamIO();
            for (int p = 0; p < cj.casesCount; p++)
            {
                int numberOfWords = cj.NextLineInt();
                string[] words = new string[numberOfWords];
                for (int i = 0; i < numberOfWords; i++)
                {
                    words[i] = cj.NextLine();
                }
                char[] first = letterorder(words[0]);
                bool good = true;
                for (int i = 0; i < words.Length; i++)
                {
                    string word = words[i];
                    if (CompareArrays(letterorder(word), first) == false)
                        good = false;
                }
                if (good)
                {
                    int changes = 0;
                    List<int[]> on = new List<int[]>();
                    foreach (string word in words)
                    {
                        on.Add(OnlyCount(word));
                    }
                    for (int i = 0; i < first.Length; i++)
                    {
                        List<int> nums = new List<int>();
                        foreach (int[] a in on)
                        {
                            nums.Add(a[i]);
                        }
                        nums.Sort();
                        if (nums.Count % 2 == 1)
                        {
                            int hetzion = nums[(nums.Count - 1) / 2];
                            foreach (int n in nums)
                            {
                                changes += Math.Abs(hetzion - n);
                            }
                        }
                        else
                        {
                            int hetzion1 = nums[nums.Count / 2];
                            int hetzion2 = nums[(nums.Count / 2)-1];

                            int c1 = 0;
                            int c2 = 0;
                            foreach (int n in nums)
                            {
                                c1 += Math.Abs(hetzion1 - n);
                                c2 += Math.Abs(hetzion2 - n);
                            }
                            changes += Math.Min(c1, c2);
                        }
                    }
                    cj.InsertValue(changes);
                }
                else
                    cj.InsertValue("Fegla Won");

            }
            cj.Dispose();

        }

        #region A

       /* static int MinChanges(int [] got,int i, int [] wanted)
        {
          if(CompareArrays(got,wanted))
              return 0;
            int skip = MinChanges(got,i+1,wanted);

        }*/

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

