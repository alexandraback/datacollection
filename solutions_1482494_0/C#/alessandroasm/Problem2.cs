using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Globalization;

namespace CodeJamQ1
{
    class Problem2
    {
        StreamReader fin = new StreamReader("p2.in");
        StreamWriter fout = new StreamWriter("p2.out");

        int[] req1 = new int[1000];
        int[] req2 = new int[1000];
        int[] status;
        int maxReq = -1;
        int Solve(int stars, int left)
        {
            if (left == 0) return 0;
            if (stars >= maxReq) return left;

            int mr = int.MaxValue;
            for (int k = 0; k < status.Length; k++)
            {
                if (status[k] < 2 && stars >= req2[k])
                {
                    var aux = 2 - status[k];
                    status[k] = 2;
                    int r = Solve(stars + aux, left - 1);
                    status[k] = 2 - aux;

                    if (r < mr)
                        mr = r;
                }
                else if (status[k] < 1 && stars >= req1[k])
                {
                    status[k] = 1;
                    int r = Solve(stars + 1, left);
                    status[k] = 0;

                    if (r < mr)
                        mr = r;
                }

            }

            if (mr == int.MaxValue) return int.MaxValue;
            return mr + 1;
        }

        int Solve2(int stars, int n)
        {
            int left = n;
            int cnt = 0;
            while (left > 0)
            {
                //pega máximo com 2
                bool incrIt = false;
                for (int k = n - 1; k >= 0; k--)
                {
                    int idx = k; // toBeSolved[k];
                    if (status[idx] < 2 && stars >= req2[idx])
                    {
                        stars += 2 - status[idx];
                        status[idx] = 2;
                        left--;
                        cnt++;

                        //toBeSolved.RemoveAt(k);

                        incrIt = true;
                    }
                }

                if (left == 0) return cnt;

                if (!incrIt)
                {
                    //pega com 1
                    bool ok = false;
                    for (int k = n - 1; k >= 0; k--)
                    {
                        int idx = k; // toBeSolved[k];
                        if (status[idx] < 1 && stars >= req1[idx])
                        {
                            cnt++;
                            status[idx] = 1;
                            stars++;
                            ok = true;
                            break;
                        }
                    }

                    if (!ok) return int.MaxValue;
                }
            }

            return cnt;
        }

        void RunTestCase(int tn)
        {
            int n = ReadInt();
            status = new int[n];

            maxReq = -1;
            for (int k = 0; k < n; k++)
            {
                req1[k] = ReadInt();
                req2[k] = ReadInt();

                if (req2[k] > maxReq)
                    maxReq = req2[k];

                status[k] = 0;
            }

            int r = int.MaxValue;
            
            //if (maxReq < n * 2)
                r = Solve2(0, n);

            if (r == int.MaxValue)
                fout.WriteLine("Case #{0}: Too Bad", tn + 1);
            else
                fout.WriteLine("Case #{0}: {1}", tn + 1, r);
        }

        void Run()
        {
            int t = ReadInt();

            for (int tn = 0; tn < t; tn++)
            {
                RunTestCase(tn);
            }

            fin.Close();
            fout.Close();
        }

        static void Main(string[] args)
        {
            Problem2 p = new Problem2();
            p.Run();
        }

        #region Input
        string _ln = null;
        int _lnPos = 0;

        string _Next()
        {
            if (_ln == null || _lnPos >= _ln.Length) {
                _ln = fin.ReadLine();
                _lnPos = 0;
            }

            int idx = _ln.IndexOf(' ', _lnPos);
            if (idx < 0)
            {
                string r = _ln.Substring(_lnPos);
                _ln = null;
                return r;
            }

            string ret = _ln.Substring(_lnPos, idx - _lnPos);
            _lnPos = idx + 1;
            return ret;
        }

        string ReadLine()
        {
            _ln = null;
            return fin.ReadLine();
        }

        int ReadInt()
        {
            return int.Parse(_Next());
        }

        decimal ReadDec()
        {
            return decimal.Parse(_Next(), CultureInfo.InvariantCulture);
        }

        string ReadWord()
        {
            return _Next();
        }
        #endregion
    }
}
