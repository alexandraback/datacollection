using System;
using System.Linq;
using System.Collections.Generic;

class hadi
{
    class tupple
    {
        public char c;
        public int count;

        public tupple(char my_c)
        {
            c = my_c;
            count = 1;
        }
    }

    static void Main()
    {
        int T = int.Parse(Console.ReadLine());
        for (int t = 1; t <= T; ++t)
        {
            int N = int.Parse(Console.ReadLine());
            string[] arr_str = new string[N];
            List<List<tupple>> llt = new List<List<tupple>>();
            char temp_c;
            for (int i = 0; i < N; ++i)
            {
                llt.Add(new List<tupple>());
                arr_str[i] = Console.ReadLine();
                temp_c = 'A';
                for (int j = 0; j < arr_str[i].Length; ++j)
                {
                    if (temp_c != arr_str[i][j])
                    {
                        temp_c = arr_str[i][j];
                        llt[i].Add(new tupple(temp_c));
                    }
                    else
                    {
                        llt[i][llt[i].Count - 1].count++;
                    }
                }
            }

            bool flag = true;
            int temp_i = -1;
            for (int i = 0; i < llt.Count; ++i)
            {
                if (temp_i != -1 && temp_i != llt[i].Count)
                {
                    flag = false;
                    break;
                }
                temp_i = llt[i].Count;
            }

            int result = 0;
            for (int i = 0; i < llt[0].Count; ++i)
            {
                temp_c = 'A';
                int min = 1000, max = -1;
                for (int j = 0; j < llt.Count; ++j)
                {
                    if (temp_c != 'A' && temp_c != llt[j][i].c)
                    {
                        flag = false;
                        break;
                    }
                    temp_c = llt[j][i].c;
                    if (min > llt[j][i].count) min = llt[j][i].count;
                    if (max < llt[j][i].count) max = llt[j][i].count;
                }
                if (!flag) break;

                int total;
                int min_total = -1;
                for (int j = min; j <= max; ++j)
                {
                    total = 0;
                    for (int k = 0; k < llt.Count; ++k)
                    {
                        total += Math.Abs(llt[k][i].count - j);
                    }
                    if (min_total == -1 || min_total > total) min_total = total;
                }
                result += min_total;
                //Console.WriteLine(llt[0][i].c + " " + min_total);
            }

            Console.WriteLine("Case #" + t + ": " + (flag ? result + "" : "Fegla Won"));
        }
    }
}