using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Enclosure
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = File.OpenText(@"C-small-attempt2.in"))
            {
                int total = Convert.ToInt32(reader.ReadLine());
                
                for (int i = 1; i <= total; i++)
                {
                    string NMK = reader.ReadLine();
                    int N = Convert.ToInt32(NMK.Split()[0]);
                    int M = Convert.ToInt32(NMK.Split()[1]);
                    int K = Convert.ToInt32(NMK.Split()[2]);

                    int minimum = Math.Min(N, M);
                    int maximum = Math.Max(N, M);
                    int ans = 0;

                    if (minimum==1)
                    {
                        ans = 1;
                    } 
                    else if (minimum==2)
                    {
                        if (K == 1)
                            ans = 1;
                        else
                            ans = 2;
                    }
                    else if (K < 5)
                    {
                        ans = K;
                    }
                    else if (K < 8)
                    {
                        ans = K - 1;
                    }
                    else if (maximum == 3)
                    {
                        ans = K - 1;
                    }
                    else if (minimum == 3)
                    {
                        if (K < 11)
                        {
                            ans = K - 2;
                        }
                        else if (K < 14)
                        {
                            ans = K - 3;
                        }
                        else
                            ans = K - 4;
                    }
                    else
                    {
                        if (K < 10)
                        {
                            ans = K - 2;
                        }
                        else if (K < 12)
                        {
                            ans = K - 3;
                        }
                        else if (K < 14)
                        {
                            ans = K - 4;
                        }
                        else if (K < 16)
                        {
                            ans = K - 5;
                        }
                        else
                            ans = K - 6;
                    }

                    

                    Console.WriteLine("Case #{0}: {1}", i, ans);
                    using (StreamWriter writer = new StreamWriter("outputfile", true))
                    {
                        writer.WriteLine("Case #{0}: {1}", i, ans);
                    }
                }
                Console.ReadKey();
            }
        }
    }
}
