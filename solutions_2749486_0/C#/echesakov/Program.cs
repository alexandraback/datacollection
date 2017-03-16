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
        //#region Problem A. Consonants
        //static bool IsVowel(char c)
        //{
        //    switch (c)
        //    {
        //        case 'a':
        //        case 'e':
        //        case 'i':
        //        case 'o':
        //        case 'u':
        //            return true;
        //        default:
        //            return false;
        //    }
        //}

        //static int NValue(string s, int n)
        //{
        //    int L = s.Length;
        //    int[] isCons = new int[L];

        //    for (int i = 0; i < L; i++)
        //    {
        //        if (IsVowel(s[i]))
        //        {
        //            isCons[i] = 0;
        //        }
        //        else
        //        {
        //            if (i > 0)
        //            {
        //                isCons[i] = isCons[i - 1] + 1;
        //            }
        //            else
        //            {
        //                isCons[i] = 1;
        //            }
        //        }
        //    }

        //    int begin = 0;
        //    int end = n;

        //    int nVal = 0;
        //    while (begin != end)
        //    {
        //        for (int i = begin + n - 1; i < end; i++)
        //        {
        //            if (isCons[i] >= n)
        //            {
        //                nVal += 1;
        //                //Debug.WriteLine(s.Substring(begin, end - begin));
        //                break;
        //            }
        //        }

        //        if (end == L)
        //        {
        //            begin = Math.Min(begin + 1, L);
        //            end = Math.Min(begin + n, L);
        //        }
        //        else
        //        {
        //            end = Math.Min(end + 1, L);
        //        }
        //    }

        //    return nVal;
        //}

        //static void Main(string[] args)
        //{
        //    string inputFileName = "A-large.in";
        //    string outputFileName = "A-large.out";

        //    var input = File.ReadAllLines(inputFileName);
        //    int T;

        //    if (!Int32.TryParse(input[0], out T)) return;
        //    var output = new List<string>();
        //    for (int nCase = 1; nCase <= T; nCase++)
        //    {
        //        var ss = input[nCase].Split();
        //        var answer = NValue(ss[0], Int32.Parse(ss[1]));
        //        output.Add(string.Format("Case #{0}: {1}", nCase, answer));
        //    }

        //    File.WriteAllLines(outputFileName, output);
        //}
        //#endregion

        #region Problem B. Pogo

        const char N = 'N';
        const char S = 'S';
        const char W = 'W';
        const char E = 'E';

        static string Moves(int X, int Y)
        {
            var retVal = new List<char>();

            int absX = Math.Abs(X);
            int absY = Math.Abs(Y);

            while (absX + absY > 0)
            {
                if (absX > absY)
                {
                    if (X > 0)
                    {
                        X -= 1;
                        retVal.Add(W);
                        retVal.Add(E);
                    }
                    else
                    {
                        X += 1;
                        retVal.Add(E);
                        retVal.Add(W);
                    }
                }
                else
                {
                    if (Y > 0)
                    {
                        Y -= 1;
                        retVal.Add(S);
                        retVal.Add(N);
                    }
                    else
                    {
                        Y += 1;
                        retVal.Add(N);
                        retVal.Add(S);
                    }
                }

                absX = Math.Abs(X);
                absY = Math.Abs(Y);
            }

            //Debug.WriteLine(retVal.Count);
            return new string(retVal.ToArray());
        }

        static void Main(string[] args)
        {
            string inputFileName = "B-small-attempt1.in";
            string outputFileName = "B-small-attempt1.out";

            var input = File.ReadAllLines(inputFileName);
            int T;

            if (!Int32.TryParse(input[0], out T)) return;
            var output = new List<string>();
            for (int nCase = 1; nCase <= T; nCase++)
            {
                var coord = input[nCase].Split().Select(s => Int32.Parse(s)).ToArray();
                int X = coord[0]; int Y = coord[1];

                string answer = Moves(X, Y);
                output.Add(string.Format("Case #{0}: {1}", nCase, answer));
            }

            File.WriteAllLines(outputFileName, output);
        }
        #endregion
    }
}
