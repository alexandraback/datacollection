using System;
using System.Collections.Generic;
using System.IO;

class Round1C_A
{
    static String input = "A-small-attempt0.in";
    static String output = "A-small-attempt0.out";

    // static String input = "a-large.in";
    // static String output = "a-large.out";

    static void Main(string[] args)
    {
        StreamReader reader = new StreamReader(input);
        StreamWriter writter = new StreamWriter(output);

        int T = int.Parse(reader.ReadLine());
        for (int index = 1; index <= T; index++)
        {
            int N = int.Parse(reader.ReadLine());            
            int[,] a = new int[N, 15];           
           
            for (int i = 0; i < N; i++)
            {
                String[] lineArray = reader.ReadLine().Split(' ');               
                for (int j = 0; j < lineArray.Length; j++) a[i, j] = int.Parse(lineArray[j]) - 1;
                a[i, 0]++;
            }
                       
            int[] b;
            String ans = "No";

            for (int k = 0; k < N; k++)
            {
                b = new int[N];
                //start from k;
                b[k] = 1;
                Queue<int> q = new Queue<int>();
                q.Enqueue(k);
                while (q.Count > 0)
                {
                    int h = q.Dequeue();
                    for (int i = 1; i <= a[h, 0]; i++)
                        if (b[a[h, i]] == 0)
                        {
                            b[a[h, i]]++;
                            q.Enqueue(a[h, i]);
                        }
                        else
                        {
                            ans = "Yes";
                            break;
                        }
                    if (ans.Equals("Yes")) break;
                }
                if (ans.Equals("Yes")) break;
            }
                
            writter.WriteLine("Case #" + index + ": " + ans);           
        }

        reader.Close();
        writter.Close();
    }
}

