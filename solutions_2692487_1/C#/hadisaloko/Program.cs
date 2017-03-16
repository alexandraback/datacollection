using System;
using System.Collections.Generic;

class hadi
{
    static int rec(int A, int[] arr, int index)
    {
        if(index>=arr.Length)return 0;

        int result = arr.Length;
        if (A > arr[index])
        {
            result = rec(A + arr[index], arr, index + 1);
        }
        else
        {
            if (A != 1)
            {
                result = 1 + rec(2 * A - 1, arr, index);
            }

            if (result > (arr.Length - index))
            {
                result = (arr.Length - index);
            }
        }
        return result;
    }

    static void Main()
    {
        int T = int.Parse(Console.ReadLine());
        for (int j = 0; j < T; ++j)
        {
            string[] s = Console.ReadLine().Split(new char[] { ' ' });
            int A = int.Parse(s[0]);
            int N = int.Parse(s[1]);
            int[] arr = new int[N];
            s = Console.ReadLine().Split(new char[] { ' ' });
            for (int i = 0; i < N; ++i)
            {
                arr[i] = int.Parse(s[i]);
            }
            Array.Sort(arr);
            Console.WriteLine("Case #" + (j + 1) + ": " + rec(A, arr, 0));
        }
        Console.ReadLine();
    }
}
