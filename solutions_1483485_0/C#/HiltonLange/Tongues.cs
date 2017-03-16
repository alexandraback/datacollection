using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Tongues : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                string ret = translate(s);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string translate(string s)
        {
            //string googlet = "abcdefghijklmnopqrstuvwxyz";
            string engllet = "yhesocvxduiglbkrztnwjpfmaq";
            char[] ret = new char[s.Length];
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == ' ')
                {
                    ret[i] = ' ';
                }
                else
                {
                    ret[i] = engllet[s[i] - 'a'];
                }
            }
            return new string(ret);
        }

    }
}
