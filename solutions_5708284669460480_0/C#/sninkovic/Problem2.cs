using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam
{
    class Problem2
    {
        public static void Main(string[] varg)
        {
            int T = int.Parse(Console.ReadLine());

            for (int t=1;t<=T;t++)
            {
                string[] tok = Console.ReadLine().Split(new char[] { ' ' });

                int K = int.Parse(tok[0]);
                int L = int.Parse(tok[1]);
                int S = int.Parse(tok[2]);

                string keyboard = Console.ReadLine();
                string targetWord = Console.ReadLine();

                int[] brojaci = new int[S];
                int setSize = K;
                int rv = 0;
                int total = 0;
                total = 0;
               // rv += GetBNumber(keyboard, targetWord);
                int maxBananas = 0;
                do
                {
                    StringBuilder a = new StringBuilder();
                    foreach (var bb in brojaci)
                        a.Append(keyboard[bb]);
                    int k = GetBNumber(a.ToString(), targetWord);
                    if (k > maxBananas)
                    {
                        maxBananas = k;
                      
                    }
                    rv += k;
                    total++;
                } while (GetNextPermutation(null, brojaci, setSize));

                Console.WriteLine("Case #{0}: {1}", t, ((double)maxBananas-(double)rv / total));
            }
        }

        public static bool GetNextPermutation(string input, int[] brojaci, int setSize)
        {
            int lbrojac = brojaci.Length-1;
          
            while(lbrojac>=0)
            {
                
                if (brojaci[lbrojac]<setSize-1)
                {
                    brojaci[lbrojac]++;
                    for (int i=lbrojac+1;i<brojaci.Length;i++)
                    {
                        brojaci[i] = 0;
                    }
                    return true;
                }
                lbrojac--;
            }
            return false;

        }

        static int GetBNumber(string word, string target)
        {
            int i = 0;
            int rv = 0;
            while (true)
            {
                if (i >= word.Length) return rv;
                i = word.IndexOf(target, i);
                if (i >= 0)
                {
                    rv++;
                    i++;
                }
                else
                    return rv;
            }
        }
    }
}
