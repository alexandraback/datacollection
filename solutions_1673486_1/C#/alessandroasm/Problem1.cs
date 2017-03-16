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

        void RunTestCase(int tn)
        {
            int a = ReadInt();
            int b = ReadInt();

            List<decimal> kp = new List<decimal>();
            for (int k = 0; k < a; k++)
            {
                decimal d = ReadDec();
                kp.Add(d);
            }

            //Digitando tudo

            decimal rightChance = 1m;
            decimal min = decimal.MaxValue;
            for (int wrongDig = 0; wrongDig <= a; wrongDig++)
            {
                if (wrongDig > 0)
                    rightChance *= kp[wrongDig - 1];

                decimal avg = ( (a - wrongDig) + b - wrongDig + 1) * rightChance +
                        (((a - wrongDig) + b - wrongDig + 1) + b + 1) * (1m - rightChance);

                if (avg < min)
                    min = avg;
            }

            decimal giveup = 1 + b + 1;
            if (giveup < min)
                min = giveup;

            string mins = string.Format(CultureInfo.InvariantCulture, "{0:N6}", min).Replace(",","") ;
            fout.WriteLine("Case #{0}: {1}", tn + 1, mins);
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
