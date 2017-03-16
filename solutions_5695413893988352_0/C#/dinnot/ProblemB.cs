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
                return true;
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
            GCJ.io.Write(result);
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
            return "0";
        }
    }
}
