using System;
using System.Collections.Generic;

class hadi
{
    static void Main()
    {
        int T = int.Parse(Console.ReadLine());
        for (int j = 1; j <= T; ++j)
        {
            string[] arr_str = Console.ReadLine().Split(new char[] { ' ' });
            string s = arr_str[0];
            int L = int.Parse(arr_str[1]);
            int kumulatif = 0;
            List<object> list_int = new List<object>();
            for (int i = 0; i < s.Length; ++i)
            {
                if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
                {
                    kumulatif = 0;
                }
                else
                {
                    ++kumulatif;
                    if (kumulatif >= L)
                    {
                        list_int.Add(i - L + 1);
                    }
                }
            }

            int result = 0;
            object index;
            for (int i = 0; i < s.Length - L + 1; ++i)
            {
                index = list_int.Find(x => ((int)x) >= i);
                if (index != null)
                {
                    result += s.Length - (((int)index) + L + 1) + 2;
                }
            }

            Console.WriteLine("Case #" + j + ": " + result);
        }
    }
}