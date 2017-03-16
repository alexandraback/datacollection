using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace PartElf
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = File.OpenText(@"A-large.in"))
            {
                int total = Convert.ToInt32(reader.ReadLine());
                List<double> list2 = new List<double>();
                double two = 2;
                for (double i1 = 0; i1 <= 42; i1++)
                {
                    list2.Add(Math.Pow(two, i1));
                }

                for (int i = 1; i <= total; i++)
                {
                    string PbyQ = reader.ReadLine();
                    double P = Convert.ToDouble(PbyQ.Split('/')[0]);
                    double Q = Convert.ToDouble(PbyQ.Split('/')[1]);

                    int ans = 0;
                    string answer = "possible";
                    if (Q % 2 != 0)
                    {
                        if (P == Q)
                            ans = 1;
                        else
                            answer = "impossible";
                    }
                    else
                    {
                        int i2=0;
                        while (Q % list2[i2] ==0)
                        {
                            i2++;
                        }
                        i2--;
                        ans = i2;
                        Q = Q / list2[i2];
                        i2 = 0;
                        while (P % list2[i2] == 0)
                        {
                            i2++;
                        }
                        i2--;
                        ans = ans -i2;
                        P = P / list2[i2];

                        if (P % Q != 0)
                            answer = "impossible";
                        else
                            P = P / Q;

                        i2 = 0;
                        while (P >= list2[i2])
                        {
                            i2++;
                        }
                        i2--;
                        ans = ans - i2;
                    }

                    if (answer == "impossible")
                    {
                        Console.WriteLine("Case #{0}: {1}", i, answer);
                    }
                    else
                    {
                        Console.WriteLine("Case #{0}: {1}", i, ans);
                    }
                    using (StreamWriter writer = new StreamWriter("outputfile", true))
                    {
                        if (answer == "impossible")
                        {
                            writer.WriteLine("Case #{0}: {1}", i, answer);
                        }
                        else
                        {
                            writer.WriteLine("Case #{0}: {1}", i, ans);
                        }
                    }
                }
                Console.ReadKey();
            }
        }
    }
}
