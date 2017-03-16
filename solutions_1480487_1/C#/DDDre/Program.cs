using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace jam12_1b_1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader SR = new StreamReader(@"A-large.in");
            StreamWriter SW = new StreamWriter("out.txt");
            var s = SR.ReadLine();
            var n = Int32.Parse(s);
            for (var i = 0; i < n; i++)
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(String.Format("Case #{0}: ", i + 1));
                s = SR.ReadLine();
                var ss = s.Split(' ');
                var N = Int32.Parse(ss[0]);
                int[] e = new int[N];
                int sum = 0;
                for (int j = 0; j < N; j++)
                {
                    e[j] = Int32.Parse(ss[j+1]);
                    sum += e[j];
                }
                bool[] ep = new bool[N];
                
                int sum2 = sum;
                var NN = N;
                bool Flag = false;
                do{
                    Flag = false;
                    for (int j = 0; j < N; j++)
                    {
                        if (ep[j]) continue;

                        double y = 1.0 / NN - ((double)e[j] - (double)sum2 / NN) / sum;
                    
                        if (y > 0)
                        {
                            ep[j] = false;
                            
                        }
                        else
                        {
                            ep[j] = true;
                            sum2 -= e[j];
                            NN--;
                            Flag = true;
                        }

                    }
                } while (Flag);
                for (int j = 0; j < N; j++)
                {
                    if (ep[j])
                        sb.Append("0.000000 ");
                    else
                    {
                        double y = 1.0 / NN - ((double)e[j] - (double)sum2 / NN) / sum;
                        sb.Append(string.Format("{0:0.000000} ", y * 100).Replace(',', '.'));
                    }
                }
                

                SW.WriteLine(sb);
            }
            SW.Close();
            SR.Close();
        }

        

        
    }
}
