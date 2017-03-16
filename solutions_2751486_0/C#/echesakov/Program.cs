using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1C2013
{
    class Program
    {
        #region Problem A.
        static bool IsVowel(char c)
        {
            switch (c)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    return true;
                default:
                    return false;
            }
        }

        static int NValue(string s, int n)
        {
            int L = s.Length;
            int[] isCons = new int[L];

            for (int i = 0; i < L; i++)
            {
                if (IsVowel(s[i]))
                {
                    isCons[i] = 0;
                }
                else
                {
                    if (i > 0)
                    {
                        isCons[i] = isCons[i - 1] + 1;
                    }
                    else
                    {
                        isCons[i] = 1;
                    }
                }
            }

            int begin = 0;
            int end = n;

            int nVal = 0;
            while (begin != end)
            {
                for (int i = begin + n - 1; i < end; i++)
                {
                    if (isCons[i] >= n)
                    {
                        nVal += 1;
                        Debug.WriteLine(s.Substring(begin, end - begin));
                        break;
                    }
                }

                if (end == L)
                {
                    begin = Math.Min(begin + 1, L);
                    end = Math.Min(begin + n, L);
                }
                else
                {
                    end = Math.Min(end + 1, L);
                }
            }

            return nVal;
        }

        static void Main(string[] args)
        {
            string inputFileName = "A-small-attempt0.in";
            string outputFileName = "A-small-attempt0.out";

            var input = File.ReadAllLines(inputFileName);
            int T;

            if (!Int32.TryParse(input[0], out T)) return;
            var output = new List<string>();
            for (int nCase = 1; nCase <= T; nCase++)
            {
                var ss = input[nCase].Split();
                var answer = NValue(ss[0], Int32.Parse(ss[1]));
                output.Add(string.Format("Case #{0}: {1}", nCase, answer));
            }

            File.WriteAllLines(outputFileName, output);
        }
        #endregion
    }
}
