using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            string sInFileName = "c:/in.txt";
            string sOutFileName = "c:/out.txt";

            string sIn = File.ReadAllText(sInFileName);
            StringReader oSR = new StringReader(sIn);

            StringBuilder oAnswer = new StringBuilder();

            // read number of cases
            Int64 T = Int64.Parse(oSR.ReadLine());

            // case by case
            for (Int64 i = 0; i < T; i++)
            {
                string sLine = oSR.ReadLine();
                string[] aLine = sLine.Split(' ');
                Int64 X = Int64.Parse(aLine[1]);
                string sString = oSR.ReadLine();

                bool bResult;
                DNum[] aA = new DNum[sString.Length];
                for (int j = 0; j < aA.Length; j++)
                {
                    aA[j] = new DNum(sString[j]);
                }

                bResult = Solve(aA, X);

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                string sResult = bResult ? "YES" : "NO";
                oAnswer.Append(sResult);
                oAnswer.AppendLine();
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        public static bool Solve(DNum[] aA, Int64 X)
        {
            DNum A = Multiply(aA);
            Int64 L = aA.Length;
            X -= 1;
            Int64 nShifts = 0;

            // find i
            Int64? NNi, kNi, nxi;
            if (!FindNum(DNum.i, A, aA, 0, out NNi, out kNi, out nxi))
                return false;

            Int64 n0 = nxi.Value + 1;
            if(n0 == L)
            {
                n0 = 0;
                nShifts++;
            }

            // find j
            Int64? NNj, kNj, nxj;
            if (!FindNum(DNum.j, A, aA, n0, out NNj, out kNj, out nxj))
                return false;

            n0 = nxj.Value + 1;
            if (n0 == L)
            {
                n0 = 0;
                nShifts++;
            }

            // find k
            Int64? NNk, kNk, nxk;
            if (!FindNum(DNum.k, A, aA, n0, out NNk, out kNk, out nxk))
                return false;

            // any remainder?
            DNum R;
            if (nxk.Value + 1 != L)
            {
                // calc the remainder
                R = Multiply(aA, nxk.Value + 1, L - 1);
            }
            else R = new DNum('1');

            // number of reps possible?
            X -= (nShifts + NNi.Value + NNj.Value + NNk.Value);
            if (X < 0)
                return false;

            if(R != null)
            {
                Int64 nPos, nCLength;
                FindCycle(R, A, out nPos, out nCLength);
                Int64 x;
                if (X > nPos + nCLength)
                {
                    x = X - nPos;
                    x = x % nCLength;
                }
                else x = X;
                while(x > 0)
                {
                    R = R * A;
                    x--;
                }
                // can we arrive at 1?
                if (R.Value != '1' || R.IsNegative)
                    return false;
                X = 0;
            }

            return SolveDEq(X, kNi, kNj, kNk);
        }

        public static bool SolveDEq(Int64 A, Int64? a, Int64? b, Int64? c)
        {
            if(A == 0)
                return true;

            List<Int64> aVars = new List<Int64>();
            if (a.HasValue)
                aVars.Add(a.Value);
            if (b.HasValue && !aVars.Contains(b.Value))
                aVars.Add(b.Value);
            if (c.HasValue && !aVars.Contains(c.Value))
                aVars.Add(c.Value);

            if (aVars.Count == 0)
                return false;

            if(aVars.Count == 1)
            {
                Int64 aa = aVars[0];
                if (A % aa == 0)
                    return true;
                else
                    return false;
            }

            if(aVars.Count == 2)
            {
                return SolveDEq(A, aVars[0], aVars[1]);
            }

            return true;
        }

        public static bool SolveDEq(Int64 A, Int64 a, Int64 b)
        {
            return true;
        }

        public static DNum Multiply(DNum[] a)
        {
            return Multiply(a, 0, a.Length - 1);
        }

        public static Int64? Int64ernalFindNum(DNum x, DNum[] aA, DNum x0, Int64 nStart)
        {
            Int64 L = aA.Length;
            DNum xx = x0;

            for (Int64 i = nStart; i < L; i++)
            {
                if (xx == null)
                    xx = aA[i];
                else
                {
                    xx = xx * aA[i];
                }

                if (x == xx)
                {
                    return i;
                }
            }

            return null;
        }

        public static bool FindNum(DNum x, DNum A, DNum[] aA, Int64 n0, out Int64? NN, out Int64? kN, out Int64? nx)
        {
            Int64 L = aA.Length;

            // try with NN == 0
            Int64? nRes = Int64ernalFindNum(x, aA, null, n0);
            if(nRes.HasValue)
            {
                NN = 0;
                nx = nRes.Value;
                kN = null;
                return true;
            }

            // try with NN > 0, but NN <=9
            DNum xxA = Multiply(aA, n0, L - 1);
            for(Int64 iNN = 1; iNN <=9; iNN++ )
            {
                if (iNN > 1)
                    xxA = xxA * A;

                nRes = Int64ernalFindNum(x, aA, xxA, 0);
                if(nRes.HasValue)
                {
                    NN = iNN;
                    nx = nRes.Value;

                    if(NN == 1)
                    {
                        kN = null;
                    }
                    else
                    {
                        Int64 nPos, nCycle;
                        FindCycle(xxA, A, out nPos, out nCycle);
                        kN = nCycle;
                    }

                    return true;
                }
            }

            NN = null;
            kN = null;
            nx = null;

            return false;
        }

        public static void FindCycle(DNum n0, DNum A, out Int64 nPos, out Int64 nCycleLength)
        {
            Int64 pos = 1;
            DNum x = n0;
            List<DNum> aList8 = new List<DNum>();
            aList8.Add(x);

            do
            {
                x = x * A;
                for (int i = 0; i < aList8.Count; i++)
                {
                    if (aList8[i] == x)
                    {
                        nCycleLength = i + 1;
                        nPos = pos - nCycleLength;
                        return;
                    }
                }
                if (aList8.Count == 8)
                    aList8.RemoveAt(7);
                aList8.Insert(0, x);
                pos++;
            }
            while (true);
        }

        public static DNum Multiply(DNum[] a, Int64 nStart, Int64 nEnd)
        {
            DNum x = a[nStart];
            for (Int64 i = nStart + 1; i <= nEnd; i++)
            {
                x = x * a[i];
            }

            return x;
        }

        public class DNum
        {
            public bool IsNegative;
            public char Value;

            public static DNum i = new DNum('i');
            public static DNum j = new DNum('j');
            public static DNum k = new DNum('k');

            public DNum(bool bNeg, char c)
            {
                IsNegative = bNeg;
                Value = c;
            }

            public DNum(char c)
            {
                Value = c;
            }

            public static bool operator ==(DNum dL, DNum dR)
            {
                if (Object.ReferenceEquals(dL, dR))
                    return true;

                if (Object.ReferenceEquals(dL, null) || Object.ReferenceEquals(dR, null))
                    return false;

                if (dL.IsNegative == dR.IsNegative && dL.Value == dR.Value)
                    return true;
                else return false;
            }

            public override int GetHashCode()
            {
                if (IsNegative)
                    return Value;
                else return -Value;
            }

            public static bool operator !=(DNum dL, DNum dR)
            {
                return !(dL == dR);
            }

            public override string ToString()
            {
                if (IsNegative)
                    return "-" + Value;
                else
                    return Value.ToString();
            }

            public static DNum operator *(DNum dL, DNum dR)
            {
                char cResVal;
                bool bResNeg = dL.IsNegative ^ dR.IsNegative;

                if (dL.Value == '1')
                    cResVal = dR.Value;
                else if (dR.Value == '1')
                    cResVal = dL.Value;
                else if (dL.Value == 'i')
                {
                    if (dR.Value == 'i')
                    {
                        cResVal = '1';
                        bResNeg = !bResNeg;
                    }
                    else if (dR.Value == 'j')
                    {
                        cResVal = 'k';
                    }
                    else if (dR.Value == 'k')
                    {
                        cResVal = 'j';
                        bResNeg = !bResNeg;
                    }
                    else throw new ApplicationException("?");
                }
                else if (dL.Value == 'j')
                {
                    if (dR.Value == 'i')
                    {
                        cResVal = 'k';
                        bResNeg = !bResNeg;
                    }
                    else if (dR.Value == 'j')
                    {
                        cResVal = '1';
                        bResNeg = !bResNeg;
                    }
                    else if (dR.Value == 'k')
                    {
                        cResVal = 'i';
                    }
                    else throw new ApplicationException("?");
                }
                else if (dL.Value == 'k')
                {
                    if (dR.Value == 'i')
                    {
                        cResVal = 'j';
                    }
                    else if (dR.Value == 'j')
                    {
                        cResVal = 'i';
                        bResNeg = !bResNeg;
                    }
                    else if (dR.Value == 'k')
                    {
                        cResVal = '1';
                        bResNeg = !bResNeg;
                    }
                    else throw new ApplicationException("?");
                }
                else throw new ApplicationException("?");

                return new DNum(bResNeg, cResVal);
            }
        }
    }
}
