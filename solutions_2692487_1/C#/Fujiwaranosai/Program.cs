using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1B_A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader infile = new StreamReader("input.txt");
            StreamWriter outfile = new StreamWriter("output.txt");
            string line = infile.ReadLine();
            int T = int.Parse(line); // case num
            for (int i = 0; i < T; i++)
            {
                if (i == 21)
                {
                    int v = 0;
                    v++;
                }
                line = infile.ReadLine();
                ulong a;
                int n;
                string[] arr = line.Split(' ');
                a = ulong.Parse(arr[0]);
                n = int.Parse(arr[1]);
                line = infile.ReadLine();
                arr = line.Split(' ');
                List<ulong> motes = new List<ulong>();
                for (int j = 0; j < n; j++)
                {
                    motes.Add(ulong.Parse(arr[j]));
                }
                int result = solve(a, motes);
                outfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
            }
            infile.Close();
            outfile.Close();
        }

        static int solve(ulong a, List<ulong> motes)
        {
            ulong sum = a;
            int count = motes.Count;
            bool flag = false;
            do
            {
                flag = false;
                for (int i = motes.Count - 1; i >= 0; i--)
                {
                    if (sum > motes[i])
                    {
                        sum += motes[i];
                        motes.RemoveAt(i);
                        flag = true;
                    }
                }
            } while (flag);
            if (motes.Count == 0)
                return 0;
            if (motes.Count == 1)
                return 1;
            count = motes.Count;
            if (sum == 1)
                return count;
            int result = solve(sum + sum - 1, motes);
            if (result >= count)
                return count;
            return result + 1;
        }
    }
}