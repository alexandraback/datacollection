using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2015Qualification
{
    public class Dijkstra
    {
        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText("..\\..\\CodeJam\\2015Qualification\\inC.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var number = 0;
                    var p = textReader.ReadLine().Split(' ').Select(long.Parse).ToArray();
                    var X = p[1];
                    var str = textReader.ReadLine();

                    result.AppendLine(string.Format("Case #{0}: {1}", t, IsPossible(X, str) ? "YES" : "NO"));
                }
            }
            using (var textWriter = File.CreateText("..\\..\\CodeJam\\2015Qualification\\outC.txt"))
            {
                textWriter.Write(result.ToString());
            }
        }

        private bool IsPossible(long X, string str)
        {
            bool strPositive;

            var cStr = Compute(str, out strPositive);
            var iList = new List<int>();
            var kList = new List<int>();

            var builder = new StringBuilder();
            var n = X;
            if (n > 12)
                n = 12 + (n - 12)%4;

            for (int j = 0; j < n; ++j)
                builder.Append(str);
            var str1 = builder.ToString();
            
            if (cStr == '1' && strPositive)
                str1 = str;

            var positivei = true;
            var positivek = true;
            var ci = '1';
            var ck = '1';
            for (var j = 0; j < str1.Length; ++j)
            {
                bool positiveTmpi;
                ci = Compute(ci, str1[j], out positiveTmpi);
                positivei = positivei == positiveTmpi;
                if (ci == 'i' && positivei)
                    iList.Add(j);

                bool positiveTmpk;
                ck = Compute(str1[str1.Length - j - 1], ck, out positiveTmpk);
                positivek = positivek == positiveTmpk;
                if (ck == 'k' && positivek)
                    kList.Add(str1.Length - j - 1);
            }
            kList.Sort();

            var i = 0;
            var k = 0;
            while (i < iList.Count && k < kList.Count)
            {
                if (iList[i] > kList[k])
                {
                    k++;
                    continue;
                }

                bool isPositive;
                if (Compute(str1, iList[i] + 1, kList[k], out isPositive) == 'j' && isPositive)
                {
                    return true;
                }
                i++;
            }
            return false;
        }

        private char Compute(string str, int start, int end, out bool isPositive)
        {
            var i = start;
            var result = '1';
            isPositive = true;
            while (i < end)
            {
                bool positive;
                result = Compute(result, str[i], out positive);
                isPositive = (positive == isPositive);
                ++i;
            }
            return result;
        }

        private char Compute(string str, out bool isPositive)
        {
            return Compute(str, 0, str.Length, out isPositive);
        }

        private char Compute(char cl, char cr, out bool isPositive)
        {
            isPositive = true; // > 0
            if (cl == '1')
                return cr;

            if (cr == '1')
                return cl;

            if (cl == cr)
            {
                isPositive = false;
                return '1';
            }

            if (cl == 'i')
            {
                if (cr == 'j')
                    return 'k';
                if (cr == 'k')
                {
                    isPositive = false;
                    return 'j';
                }
            }

            if (cl == 'j')
            {
                if (cr == 'i')
                {
                    isPositive = false;
                    return 'k';
                }
                if (cr == 'k')
                {
                    return 'i';
                }
            }
            if (cl == 'k')
            {
                if (cr == 'i')
                {
                    return 'j';
                }
                if (cr == 'j')
                {
                    isPositive = false;
                    return 'i';
                }
            }
            return '1';
        }
    }
}