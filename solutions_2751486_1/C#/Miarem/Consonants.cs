using System;
using System.IO;
using System.Collections.Generic;

class Consonants
{
    public static void Solve()
    {
        StreamReader input = new StreamReader("A-small-attempt0.in");
        StreamWriter output = new StreamWriter("A-small-attempt0.out");
        char[] separators = { ' ', '\t', '\n' };
        int T = int.Parse(input.ReadLine());
        for (int t = 0; t < T; t++)
        {
            string[] splitLine = input.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries);
            string name = splitLine[0];
            int n = int.Parse(splitLine[1]);
            char[] vowels = { 'a', 'e', 'i', 'o', 'u' };
            List<int> start = new List<int>();
            List<int> end = new List<int>();

            int curConsLength = 0;
            for (int i = 0; i < name.Length; i++)
            {
                bool isVowel = false;
                for (int j = 0; j < vowels.Length; j++)
                    if (name[i] == vowels[j]) isVowel = true;
                if (isVowel)
                {
                    if (curConsLength >= n)
                    {
                        start.Add(i - curConsLength);
                        end.Add(i - 1);
                    }
                    curConsLength = 0;
                }
                else
                {
                    curConsLength++;
                }
            }
            if (curConsLength >= n)
            {
                start.Add(name.Length - curConsLength);
                end.Add(name.Length - 1);
            }
            int result = 0;
            int index = 0;
            for (int i = 0; i < name.Length && index < start.Count; i++)
            {
                if (i < start[index])
                    result += (name.Length - start[index] - n) + 1;
                else
                    result += (name.Length - i - n) + 1;
                if (i + n > end[index])
                    index++;
            }
            output.Write("Case #{0}: {1}\n", t + 1, result);
        }

        input.Close();
        output.Close();
    }
}