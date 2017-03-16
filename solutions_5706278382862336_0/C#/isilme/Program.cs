using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartElf
{
    class Program
    {
        const string INPUT_PATH = "A-small-attempt3.in";
        const string OUTPUT_PATH = "output.dat";


        static void Out(string s)
        {
            Console.WriteLine(s);
            using (var sw = new StreamWriter(OUTPUT_PATH, true))
            {
                sw.WriteLine(s);
            }
        }

        static void ReadRow(StreamReader s, ref int p, ref int q)
        {
            var line = s.ReadLine().Split('/');
            p = int.Parse(line[0]);
            q = int.Parse(line[1]);
           
        }


        static bool CheckValid(int p, int q , int gen)
        {
           if (gen < 0) return false;
            if (p == q) return true;
            if (p == 0) return true;

            if( q % 2 == 0)
            {
                 if(   p <= q/2)
                 {
                    return CheckValid(p,q/2,gen-1);
                 }
                 else
                 {
                     return  CheckValid( 2*p-q,q,gen-1);
                 }
            }
            else
            {
                if (2*p >= q )
                {
                    return CheckValid(2 * p - q, q, gen - 1);
                   
                }
                else
                {
                    return false;
                }
                
            }

        }
        
        static void Main(string[] args)
        {

            if (File.Exists(OUTPUT_PATH))
            {
                File.Delete(OUTPUT_PATH);
            }

            var s = new StreamReader(INPUT_PATH);

            int T = int.Parse(s.ReadLine());

            for (int currentCase = 0; currentCase < T; currentCase++)
            {
                int p = 0;
                int q = 0;

                ReadRow(s, ref p, ref q);

                bool possible = true;
                int generations = 40;
                int result = 0;

                while( generations > 0)
                {
                    int rem = q % 2;
                    if (rem == 0 && (p <= (q/2)))
                    {
                        q /= 2;
                        generations--;
                        result++;
                    }
                    else
                    {
                        if( q == p )
                        {
                            //done
                            Out(String.Format("Case #{0}: {1}", currentCase + 1, result));
                            break;
                        }
                        else
                        {
                            int c = 2*p - q;
                            int d = q;
                            
                            if( (c >= 0) && (c <= d) && CheckValid( c,d, generations))
                            {
                                //done
                                result++;
                                Out(String.Format("Case #{0}: {1}", currentCase + 1, result));
                                break;
                            }
                            else
                            {
                                Out(String.Format("Case #{0}: impossible", currentCase + 1));
                                break;
                            }
                        }
                    }

                }


            }

            s.Close();
        
        }
    }
}
