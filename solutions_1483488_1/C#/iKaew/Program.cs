using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace GoogleJam2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] inputs = System.IO.File.ReadAllLines(@"D:\GoogleJam\2\input.txt");

            string[] lines3 = System.IO.File.ReadAllLines(@"D:\GoogleJam\1\test3.txt");

            using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"D:\GoogleJam\2\output.txt"))
            {
                for (int x = 1; x < inputs.Length; x++)
                {
                    int sum = 0;
                    int start = Convert.ToInt32((inputs[x].Split(' '))[0]);
                    int end = Convert.ToInt32((inputs[x].Split(' '))[1]); ;
                    for (int i = start; i <= end; i++)
                    {
                        //Console.Write(i + " : ");
                        string j = i.ToString();
                        int z = 0;
                        List<Int32> a = new List<int>();
                        for (int l = 0; l < j.Length; l++)
                        {
                            
                            j = j.Substring(1) + j[0];
                            
                            int k = Convert.ToInt32(j);
                            if (!a.Contains(k))
                            {
                                a.Add(k);
                                if (i < k && k <= end && k >= start)
                                {
                                    z++;
                                }
                            }
                        }
                        
                        sum += z;

                    }
                    Console.WriteLine("Case #{0}: {1}" ,x,sum);
                    file.WriteLine("Case #{0}: {1}", x, sum);
                }
            }
            System.Console.ReadKey();
        }
    }
}
