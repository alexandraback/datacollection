using System;
using System.IO;

namespace CodeJamB
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(new FileStream("B-large.in", FileMode.Open));
            StreamWriter sw = new StreamWriter(new FileStream("B_large.out", FileMode.Create));
            string temp = sr.ReadLine();

            int test_num = int.Parse(temp);

            for (int i = 1; i < test_num + 1; i++)
            {
                temp = sr.ReadLine();
                int D = int.Parse(temp);

                temp = sr.ReadLine();
                string[] words = temp.Split(' ');
                int[] people_dish = new int[D];
                int max_pancake = 0;

                for (int j = 0; j < D; j++)
                {
                    int pancake = int.Parse(words[j]);
                    people_dish[j] = pancake;
                    if (max_pancake < pancake)
                        max_pancake = pancake;
                }

                int cur_min_time = max_pancake;
                int temp_time = 0;
                int int_temp;

                for (int j = 2; j < max_pancake; j++)
                {
                    temp_time = j;
                    for (int k = 0; k < D; k++)
                    {
                        int_temp = people_dish[k] / j;
                        temp_time += (people_dish[k] % j) == 0 ? int_temp-1 : int_temp;
                        if (cur_min_time < temp_time)
                            break;
                    }
                    if (cur_min_time > temp_time)
                        cur_min_time = temp_time;
                }

                sw.WriteLine("Case #{0}: {1}", i, cur_min_time);
            }

            sr.Close();
            sw.Close();
        }
    }
}
