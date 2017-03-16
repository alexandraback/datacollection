using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Consonants
{
    class Program
    {
        static char[] v = { 'a', 'e', 'i', 'o', 'u' };

        static void Main(string[] args)
        {
            StreamReader inp = new StreamReader(Console.ReadLine());
            StreamWriter outp = new StreamWriter(Console.ReadLine());
            int t = Convert.ToInt32(inp.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int e = 0;
                string[] wn = inp.ReadLine().Split(new char[] { ' ' });
                string w = wn[0];
                int n = int.Parse(wn[1]);
                for (int l = 0; l < w.Length; l++)
                {
                    for (int r = w.Length; r > l; r--)
                    {
                        if (r - l >= n)
                        {
                            if (check(w.Substring(l, r - l)) >= n) e++;
                        }
                    }
                }
                outp.WriteLine(String.Format("Case #{0}: {1}", i + 1, e));
                Console.WriteLine(String.Format("Case #{0}: {1}", i + 1, e));
            }
            inp.Close();
            outp.Close();
            Console.ReadLine();
        }

        static int check(string name)
        {
            int res = 0;
            int hres = 0;
            foreach (char letter in name)
            {
                res = v.Contains(letter) ? 0 : res + 1;
                if (hres < res) hres = res;
            }
            return hres;
        }
    }
}
