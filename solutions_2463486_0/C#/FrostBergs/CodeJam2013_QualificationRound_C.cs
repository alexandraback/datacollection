using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Linq;
using System.Windows.Forms;
using CodeJam.ExtentionMethods;

namespace CodeJam.Problems
{
    public class CodeJam2013_QualificationRound_C : BaseProblem
    {
        protected override object SolveCase(StreamReader reader)
        {
            ulong max = 10000000;
            
            if (!dataFilled)
            {
                for (ulong i = 1; i < max; i++)
                {
                    if (IsPalindrome(i) && IsPalindrome(i * i))
                        results.Add(i * i, i * i);
                }

                dataFilled = true;
            }

            ulong[] inputs = reader.ReadLine().ConvertInputToULongArray();

            ulong A = inputs[0];
            ulong B = inputs[1];

            int startIndex, endIndex;
            bool addedA = false;

            if (results.ContainsKey(A))
                startIndex = results.IndexOfKey(A);
            else
            {
                results.Add(A, A);
                startIndex = results.IndexOfKey(A) + 1;
                addedA = true;
            }

            if (results.ContainsKey(B))
                endIndex = results.IndexOfKey(B);
            else
            {
                results.Add(B, B);
                endIndex = results.IndexOfKey(B) - 1;
                results.Remove(B);
            }

            if (addedA)
                results.Remove(A);

            return endIndex + 1 - startIndex;


            //ulong sqA_Ceil = Convert.ToUInt64(Math.Ceiling(Math.Sqrt(Convert.ToDouble(A))));
            //ulong sqB_Floor = Convert.ToUInt64(Math.Floor(Math.Sqrt(Convert.ToDouble(B))));

            //List<ulong> results = new List<ulong>();

            //for (ulong i = sqA_Ceil; i <= sqB_Floor; i++)
            //{
            //    if (IsPalindrome(i) && IsPalindrome(i * i))
            //        results.Add(i * i);
            //}

            //return results.Count + " : " + String.Join(",", results.ConvertAll<string>(x => x.ToString()).ToArray());
        }

        private bool IsPalindrome(ulong n)
        {
            string nStr = n.ToString();
            for (int i = 0; i < nStr.Length / 2; i++)
                if (nStr[i] != nStr[nStr.Length - 1 - i])
                    return false;
            return true;
        }

        static SortedList<ulong,ulong> results = new SortedList<ulong,ulong>();
        static bool dataFilled = false;
    }
}