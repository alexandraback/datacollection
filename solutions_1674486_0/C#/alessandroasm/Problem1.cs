using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Globalization;

namespace CodeJamQ1
{
    class Problem1
    {
        StreamReader fin = new StreamReader("p1.in");
        StreamWriter fout = new StreamWriter("p1.out");

        int[,] data = new int[1000,1001];
        bool[] calc = new bool[1000];
        bool Recurse(int k)
        {
            if (calc[k]) return false;
            calc[k] = true;

            int max = data[k, 0];
            for (int j = 1; j <= max; j++)
            {
                int i = data[k, j];
                if (!calc[i])
                    if (Recurse(i)) return true;

                for (int x = 1; x <= data[i, 0]; x++)
                {
                    //se já no array então achou
                    for (int y = 1; y <= data[k, 0]; y++) {
                        if (data[i, x] == data[k, y])
                            return true;
                    }
                    
                    int ind = ++data[k, 0];
                    data[k, ind] = data[i, x];
                }
            }

            return false;
        }

        void RunTestCase(int tn)
        {
            int n = ReadInt();
            for (int k = 0; k < n; k++)
            {
                int m = ReadInt();

//                for (int j = 0; j < 1000; j++)
//                    data[k, j] = 0;
                data[k, 0] = m;
                calc[k] = false;

                for (int j = 0; j < m; j++)
                {
                    int from = ReadInt() - 1;
                    data[k, j + 1] = from;
                }
            }

            for (int k = 0; k < n; k++)
            {
                if (Recurse(k))
                {
                    fout.WriteLine("Case #{0}: Yes", tn + 1);
                    return;
                }
            }
            fout.WriteLine("Case #{0}: No", tn + 1);
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
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            Problem1 p = new Problem1();
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
