using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace ProblemB
{
    public class ProblemB
    {
        static void Main(string[] args)
        {
            int T = GetInt();
            for (int i = 0; i < T; i++)
            {
                int E;
                int R;
                int N;
                int[] parm = GetInts();
                E = parm[0];
                R = parm[1];
                N = parm[2];
                int[] Vi = GetInts();
                BigInteger result = CalcResult(E, R, N, Vi);
                WriteResult(i, result);
            }
        }

        private static BigInteger CalcResult(int E, int R, int N, int[] Vi)
        {
            int[] num = new int[N];
            //init with def
            int r = R;
            if (E <= R)
                r = E;

            num[0] = E; 
            for (int i = 1; i < Vi.Length; i++)
            {
                num[i] = r;
            }
            for(int i = 0; i < Vi.Length - 1; i++)
            {
                int max = num[i];
                for(int j=i+1; j <Vi.Length; j++)
                {
                    if (Vi[j] > Vi[i])
                    {
                        if (E - num[j] < max)
                            max = E - num[j];
                        break;
                    }
                    else
                    {
                        max = max - R;
                    }
                    if (max <= 0)
                        break;
                }
                if (max > 0)
                {
                    num[i] -= max;
                    num[i + 1] += max;
                }
            }

            BigInteger result = 0;
            for (int i = 0; i < Vi.Length; i++)
            {
                result += new BigInteger(num[i]) * new BigInteger(Vi[i]);
            }
            return result;
        }

        #region Library

        static string GetLine()
        {
            return Console.ReadLine();
        }

        static string[] GetWords()
        {
            return GetLine().Split();
        }

        static int GetInt()
        {
            return int.Parse(GetLine());
        }

        static int[] GetInts()
        {
            return GetWords().Select(x => int.Parse(x)).ToArray();
        }

        private static void WriteResult(int iterator, BigInteger result)
        {
            Console.WriteLine("Case #{0}: {1}", iterator + 1, result.ToString());
        }

        #endregion
    }
}
