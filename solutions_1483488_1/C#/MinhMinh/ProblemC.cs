using System;
using System.Collections.Generic;
using System.IO;

class ProblemC
{
    static String input = "C-large.in";
    static String output = "C-large.out";

    static void Main(string[] args)
    {
        int numOfCases;
        StreamReader reader = new StreamReader(input);
        StreamWriter writter = new StreamWriter(output);

        numOfCases = int.Parse(reader.ReadLine());
        for (int index = 1; index <= numOfCases; index++)
        {
            String[] sArray = reader.ReadLine().Split(' ');
            int A = int.Parse(sArray[0]);
            int B = int.Parse(sArray[1]);
            int ans = 0;
            int[] c = new int[2000001];
            for (int i = A; i <= B; i++)
            {
                int cnt = 1;
                c[i] = 1;
                String s = i.ToString();   
                int k = s.Length;
                for (int j = 0; j < k - 1; j++)
                {
                    s = s[k - 1] + s.Substring(0, k - 1);
                    int t = int.Parse(s);
                    if (t >= A && t <= B && c[t] == 0)
                    {
                        cnt++;
                        c[t] = 1;
                    }
                }
                ans += cnt * (cnt - 1) / 2;
            }
            writter.WriteLine("Case #" + index + ": " + ans);
        }

        reader.Close();
        writter.Close();
    }
}

