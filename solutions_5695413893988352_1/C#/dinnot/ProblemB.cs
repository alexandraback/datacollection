using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Cache;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam._2016r1b
{
    class ProblemB : IProblemSolver
    {
        public bool UsedBruteForce
        {
            get
            {
                return false;
            }
        }

        public void Seed()
        {

        }

        private string left;
        private string right;

        public void ProcessInput()
        {
            string[] data = GCJ.io.nextLineSeparated();
            left = data[0];
            right = data[1];

        }

        public string BruteForce(int caseNo)
        {
            string minLeft, minRight;
            GetMinScores(left, right, out minLeft, out minRight);
            string result = $"Case #{caseNo}: {minLeft} {minRight}";
            return result;
        }

        private ulong GetMinScores(string left, string right, out string minLeft, out string minRight)
        {
            int pLeft = left.IndexOf('?');
            if (pLeft < 0)
            {
                int pRight = right.IndexOf('?');
                if (pRight < 0)
                {
                    ulong iLeft = ulong.Parse(left);
                    ulong iRight = ulong.Parse(right);
                    ulong score = (iLeft > iRight) ? (iLeft - iRight) : (iRight - iLeft);
                    minLeft = left;
                    minRight = right;
                    return score;
                }
                var rArr = right.ToCharArray();
                ulong min = ulong.MaxValue;
                minLeft = ulong.MaxValue.ToString();
                minRight = ulong.MaxValue.ToString();
                for (int i = 0; i < 10; i++)
                {
                    rArr[pRight] = (char)('0' + i);
                    string l, r;
                    ulong score = GetMinScores(left, new string(rArr), out l, out r);
                    if (score < min)
                    {
                        min = score;
                        minLeft = l;
                        minRight = r;
                    }
                    else if (score == min)
                    {
                        if (ulong.Parse(l) < ulong.Parse(minLeft))
                        {
                            min = score;
                            minLeft = l;
                            minRight = r;
                        }
                        else if (ulong.Parse(minLeft) == ulong.Parse(l))
                        {
                            if (ulong.Parse(r) <= ulong.Parse(minRight))
                            {
                                min = score;
                                minLeft = l;
                                minRight = r;
                            }
                        }
                    }
                }
                return min;
            }
            else
            {
                var lArr = left.ToCharArray();
                ulong min = ulong.MaxValue;
                minLeft = ulong.MaxValue.ToString();
                minRight = ulong.MaxValue.ToString();
                for (int i = 0; i < 10; i++)
                {
                    lArr[pLeft] = (char)('0' + i);
                    string l, r;
                    ulong score = GetMinScores(new string(lArr), right, out l, out r);
                    if (score < min)
                    {
                        min = score;
                        minLeft = l;
                        minRight = r;
                    }
                    else if (score == min)
                    {
                        if (ulong.Parse(l) < ulong.Parse(minLeft))
                        {
                            min = score;
                            minLeft = l;
                            minRight = r;
                        }
                        else if (ulong.Parse(l) == ulong.Parse(minLeft))
                        {
                            if (ulong.Parse(r) <= ulong.Parse(minRight))
                            {
                                min = score;
                                minLeft = l;
                                minRight = r;
                            }
                        }
                    }
                }
                return min;
            }
        }

        public string Solve(int caseNo)
        {
            var result = $"Case #{caseNo}: {SolveScore(left, right, 0, 0, "", "").Value}";
            GCJ.io.Write(result);
            return result;
        }

        public KeyValuePair<ulong, string> SolveScore(string left, string right, ulong l, ulong r, string sl, string sr)
        {
            if (left.Length == 0)
            {
                return new KeyValuePair<ulong, string>(l > r ? l - r : r - l, sl + " " + sr);
            }
            if (left[0] != '?' && right[0] != '?')
            {
                return SolveScore(left.Substring(1), right.Substring(1), l*10 + left[0] - '0', r*10 + right[0] - '0',
                    sl + left[0], sr + right[0]);
            }
            if (left[0] == '?' && right[0] == '?')
            {
                if (l < r)
                {
                    return SolveScore(left.Substring(1), right.Substring(1), l*10 + 9, r*10 + 0, sl + "9", sr + "0");
                }
                if (l > r)
                {
                    return SolveScore(left.Substring(1), right.Substring(1), l*10 + 0, r*10 + 9, sl + "0", sr + "9");
                }
                var r00 = SolveScore(left.Substring(1), right.Substring(1), l*10 + 0, r*10 + 0, sl + "0", sr + "0");
                var r01 = SolveScore(left.Substring(1), right.Substring(1), l*10 + 0, r*10 + 1, sl + "0", sr + "1");
                var r10 = SolveScore(left.Substring(1), right.Substring(1), l*10 + 1, r*10 + 0, sl + "1", sr + "0");
                var min = r00.Key;
                var minS = r00.Value;
                if ((r01.Key < min) || (r01.Key == min && r01.Value.CompareTo(minS) < 0))
                {
                    min = r01.Key;
                    minS = r01.Value;
                }
                if ((r10.Key < min) || (r10.Key == min && r10.Value.CompareTo(minS) < 0))
                {
                    min = r10.Key;
                    minS = r10.Value;
                }
                return new KeyValuePair<ulong, string>(min, minS);
            }
            else if (left[0] == '?' && right[0] != '?')
            {
                ulong rval = (ulong) (right[0] - '0');
                if (l < r)
                {
                    return SolveScore(left.Substring(1), right.Substring(1), l*10 + 9, r*10 + rval, sl + "9",
                        sr + rval.ToString());
                }
                if (l > r)
                {
                    return SolveScore(left.Substring(1), right.Substring(1), l*10 + 0, r*10 + rval, sl + "0",
                        sr + rval.ToString());
                }
                var re = SolveScore(left.Substring(1), right.Substring(1), l*10 + rval, r*10 + rval,
                    sl + rval.ToString(), sr + rval.ToString());
                var min = re.Key;
                var minS = re.Value;
                if (rval < 9)
                {
                    var ri = SolveScore(left.Substring(1), right.Substring(1), l*10 + rval + 1, r*10 + rval,
                        sl + (rval + 1).ToString(), sr + rval.ToString());
                    if ((ri.Key < min) || (ri.Key == min && ri.Value.CompareTo(minS) < 0))
                    {
                        min = ri.Key;
                        minS = ri.Value;
                    }
                }
                if (rval > 0)
                {
                    var ri = SolveScore(left.Substring(1), right.Substring(1), l*10 + rval - 1, r*10 + rval,
                        sl + (rval - 1).ToString(), sr + rval.ToString());
                    if ((ri.Key < min) || (ri.Key == min && ri.Value.CompareTo(minS) < 0))
                    {
                        min = ri.Key;
                        minS = ri.Value;
                    }
                }
                return new KeyValuePair<ulong, string>(min, minS);
            }
            else
            {
                ulong lval = (ulong)(left[0] - '0');
                if (l > r)
                {
                    return SolveScore(left.Substring(1), right.Substring(1), l * 10 + lval, r * 10 + 9, sl + lval.ToString(), sr + "9");
                }
                if (l < r)
                {
                    return SolveScore(left.Substring(1), right.Substring(1), l * 10 + lval, r * 10 + 0, sl + lval.ToString(), sr + "0");
                }
                var re = SolveScore(left.Substring(1), right.Substring(1), l * 10 + lval, r * 10 + lval, sl + lval.ToString(), sr + lval.ToString());
                var min = re.Key;
                var minS = re.Value;
                if (lval < 9)
                {
                    var ri = SolveScore(left.Substring(1), right.Substring(1), l * 10 + lval, r * 10 + lval + 1, sl + lval.ToString(), sr + (lval+1).ToString());
                    if ((ri.Key < min) || (ri.Key == min && ri.Value.CompareTo(minS) < 0))
                    {
                        min = ri.Key;
                        minS = ri.Value;
                    }
                }
                if (lval > 0)
                {
                    var ri = SolveScore(left.Substring(1), right.Substring(1), l * 10 + lval, r * 10 + lval-1, sl + lval.ToString(), sr + (lval-1).ToString());
                    if ((ri.Key < min) || (ri.Key == min && ri.Value.CompareTo(minS) < 0))
                    {
                        min = ri.Key;
                        minS = ri.Value;
                    }
                }
                return new KeyValuePair<ulong, string>(min, minS);
            }
        }
    }
}
