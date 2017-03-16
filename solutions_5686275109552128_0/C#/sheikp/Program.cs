using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"D:\Input\B-small-attempt3.in");            
            System.Console.WriteLine("Out put");
            int tc = Convert.ToInt16(lines[0].ToString());
            int result, res1, res2, res3 = 0;
            int D = 0;
            string[] outputlines = new string[tc];
            int tcc = 0; 
            for( int i = 1 ; i< tc*2; i = i+2)
            {
                tcc += 1;
                D = Convert.ToInt16(lines[i].ToString());
                int[] P = new int[D];
                int[] P1 = new int[D];
                string[] C = lines[i+1].ToString().Split(" ".ToCharArray());
                result = 0;                
                int maxC = 0;
                for(int j = 0; j < P.Length; j++)
                {
                    P[j] = Convert.ToInt16(C[j].ToString());
                    P1[j] = Convert.ToInt16(C[j].ToString());                    
                    if(P[j] > maxC)
                        maxC = P[j];
                }
                result = maxC;

                int Z = 2;

                while(Z < result)
                {
                    int sumVal = 0;
                    for (int k = 0; k < P.Length; k++)
                    {
                        sumVal += (P[k] - 1) / Z;
                    }
                    sumVal += Z;
                    if (result > sumVal)
                        result = sumVal;
                    Z += 1;
                }

                Console.WriteLine("Case #" + tcc.ToString() + ": " + result.ToString() );
                outputlines[tcc - 1] = "Case #" + tcc.ToString() + ": " + result.ToString();
            
            }
            // Keep the console window open in debug mode.
            System.IO.File.WriteAllLines(@"D:\Input\B-small-attempt3.out", outputlines);
            Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }


        }
   }   
