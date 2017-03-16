using System;
using System.IO;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(new FileStream("C-small-attempt2.in", FileMode.Open));
            StreamWriter sw = new StreamWriter(new FileStream("C-small.out", FileMode.Create));
            string temp = sr.ReadLine();

            int test_num = int.Parse(temp);

            //for (int i = 1; i < 3; i++)
            for (int i = 1; i < test_num + 1; i++)
            {
                temp = sr.ReadLine();
                string[] words = temp.Split(' ');

                int C = int.Parse(words[0]);
                int D = int.Parse(words[1]);
                int V = int.Parse(words[2]);

                temp = sr.ReadLine();
                string[] coinString = temp.Split(' ');
                int[] coins = new int[D];

                Console.WriteLine("Case {0} : D= {2}, V = {1}", i, V, D);
                Console.Write("D: ");

                for (int j = 0; j < D; j++)
                {
                    coins[j] = int.Parse(coinString[j]);
                    Console.Write(coins[j] + " ");
                }
                Console.WriteLine();                    

                int required = 0;
                int required_sum = 0;
                int max_possible = 0;
                int cur = 0;

                for (int k = 1; k <= V; k++)
                {
                    if (max_possible < k && coins[cur] != k)
                    {
                        if (cur+1 < D && coins[cur+1] == k)
                        {
                            max_possible = required_sum;
                            if (cur < D - 1)
                                cur++;
                            for (int j = 0; j <= cur; j++)
                                max_possible += coins[j];

                            k = max_possible + 1;
                        }

                        else
                        {
                            //sw.WriteLine("Case #{0}: add {1}, cur {2}", i, k, coins[cur]);
                            required++;
                            required_sum += k;
                            max_possible = required_sum;
                            for (int j = 0; j <= cur; j++)
                                max_possible += coins[j];
                            k = max_possible + 1;
                            if (cur < D - 1)
                                cur++;
                        }
                    }
                    if (coins[cur] == k)
                    {
                        max_possible = required_sum;
                        if (cur < D - 1)
                            cur++;
                        for (int j = 0; j <= cur; j++)
                            max_possible += coins[j];
                        
                        k = max_possible + 1;
                    }

                }

                    sw.WriteLine("Case #{0}: {1}", i, required);
            }

            sr.Close();
            sw.Close();
        }
    }
}
