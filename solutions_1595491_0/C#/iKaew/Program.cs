using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace GoogleJam3
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] inputs = System.IO.File.ReadAllLines(@"D:\GoogleJam\3\input.txt");

            using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"D:\GoogleJam\3\output.txt"))
            {

                for (int i = 1; i < inputs.Length; i++)
                {
                    string[] glist = inputs[i].Split(' ');
                    List<int> numlist = new List<int>();
                    for (int k = 3; k < glist.Length; k++)
                        numlist.Add(Convert.ToInt32(glist[k]));
                    numlist.Sort();
                    int leastpoint = Convert.ToInt32(glist[2]);
                    int pointdiff = Convert.ToInt32(glist[1]);
                    int sum = 0;
                    for (int j = numlist.Count -1 ; j >= 0; j--)
                    {
                        //Console.Write(numlist[j] + ' ');
                        int num = Convert.ToInt32(numlist[j]);
                        if (num / 3 >= leastpoint)
                        {
                            //Console.Write("true");
                            sum++;
                        }
                        else if ((num / 3 == leastpoint - 1) && (num % 3 > 0))
                        {
                            //Console.Write("true");
                            sum++;
                        }
                        else if (pointdiff > 0 && (num / 3) + 2 >= leastpoint && (num % 3 ) == 2 && num > 0)
                        {
                            
                            
                            //Console.Write("true");
                            sum++;
                            pointdiff--;
                            

                        }
                        else if (pointdiff > 0 && (num / 3) + 1 >= leastpoint && (num % 3) == 0 && num > 0)
                        {
                            //Console.Write("true");
                            sum++;
                            pointdiff--;
                        }


                    }
                    Console.WriteLine("Case #{0}: {1}", i, sum);
                    file.WriteLine("Case #{0}: {1}", i, sum);
                }
            }
            Console.ReadKey();
        }
    }
}
