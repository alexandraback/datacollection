using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    class ProblemA
    {
        static ulong Rev(ulong val)
        {
            ulong res = 0;
            while (val > 0)
            {
                res = res * 10 + (val % 10);
                val /= 10;
            }
            return res;
        }

        static byte[] ToNums(ulong val)
        {
            return val.ToString("D14").Select(x => (byte)(x - '0')).ToArray();
        }

        static void Main(string[] args)
        {
            var files = new[] { "A-small-attempt0.in", "A-small-attempt1.in", "A-small-attempt2.in" }.Select(x => File.ReadAllLines(x).Skip(1).Select(ulong.Parse).ToArray()).ToArray();
            var edgeCases = files[0].Intersect(files[1]).Intersect(files[2]).OrderBy(x => x).ToArray();
            //File.WriteAllLines("input.txt", new []{ "x" }.Concat(edgeCases.Select(x => x.ToString())));

            var outputLines = new List<string>();
            var inputLines = File.ReadAllLines("input.txt");
            var testCases = inputLines.Skip(1).Select(ulong.Parse).ToArray();

            var testCaseId = 1;
            foreach (var testCase in testCases)
            {
                //var nRev = Rev(testCase);
                //var nLen = testCase.ToString().Length;
                //var maxVal = nLen > 2 ? ulong.Parse(testCase.ToString()[0] + new string('0', nLen - 2) + '1') : 1;

                //var result = 0;
                //for (ulong i = 0; i < testCase; result++)
                //{
                //    var rev = Rev(i);
                //    if (rev > i && (i % 10 == 9 || rev > maxVal) && rev <= testCase)
                //        i = rev;
                //    else
                //        i++;
                //}

                ulong result = 0;
                ulong currVal = testCase;

                Action goTo01 = () =>
                {
                    if (currVal % 10 == 0)
                    {
                        currVal--;
                        result++;
                    }

                    if (currVal <= 9)
                        return;

                    var currValStr = currVal.ToString();
                    var numsToZero = (int)Math.Floor(currValStr.Length / 2.0);
                    var numsToKeep = currValStr.Length - numsToZero;
                    var newNum = ulong.Parse(currValStr.Substring(0, numsToKeep) + new string('0', numsToZero - 1) + '1');
                    if (newNum < currVal)
                    {
                        result += currVal - newNum;
                        currVal = newNum;
                    }
                };

                Action reverse = () =>
                {
                    var newVal = Rev(currVal);
                    if (newVal != currVal)
                    {
                        currVal = newVal;
                        result++;
                    }
                };

                Action lowerIt = () =>
                {
                    var currValStr = currVal.ToString();
                    var numsToZero = (int)Math.Floor(currValStr.Length / 2.0);
                    var numsToKeep = currValStr.Length - numsToZero;
                    var decNum = ulong.Parse(currValStr.Substring(numsToZero)) + 1;
                    result += decNum;
                    currVal -= decNum;
                };

                while (currVal > 9)
                {
                    goTo01();
                    reverse();
                    lowerIt();
                }

                result += currVal;

                outputLines.Add(String.Format("Case #{0}: {1}", testCaseId, result));
                testCaseId++;
            }

            File.WriteAllLines("output.txt", outputLines);
        }
    }
}
