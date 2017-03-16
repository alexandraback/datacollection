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
            int x = int.Parse(arr_str[0]);
            int y = int.Parse(arr_str[1]);
            string result = "";

            string temp = (x < 0 ? "EW" : "WE");
            x = Math.Abs(x);
            for (int i = 0; i < x; ++i)
            {
                result += temp;
            }

            temp = (y < 0 ? "NS" : "SN");
            y = Math.Abs(y);
            for (int i = 0; i < y; ++i)
            {
                result += temp;
            }

            Console.WriteLine("Case #" + j + ": " + result);
        }
    }
}