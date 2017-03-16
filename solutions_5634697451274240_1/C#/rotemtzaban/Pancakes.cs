using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2106
{
    class Pancakes
    {


        public static void SolveAll()
        {
            using (StreamReader reader = File.OpenText("input.txt"))
            {
                using (StreamWriter writer = File.CreateText("output.txt"))
                {
                    int T = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= T; i++)
                    {
                        string s = reader.ReadLine();
                        int solution = Solve(ToBoolArray(s));
                        writer.WriteLine(string.Format("case #{0}: {1}", i, solution));                    }
                }
            }
        }

        public static bool IsUp(char c)
        {
            if(c == '+')
            {
                return true;
            }
            return false;
        }

        public static bool[] ToBoolArray(string s)
        {
            return s.Select(c => IsUp(c)).ToArray();
        }
        public static int Solve(bool[] arr)
        {
            if(arr.Length == 0)
            {
                return 0;
            }
            int n = arr.Length - 1;
            while(n >= 0 && arr[n])
            {
                n--;
            }
            if(n != arr.Length - 1)
            {
                return Solve(arr.Take(n + 1).ToArray());
            }
            int i = 0;
            while(i < arr.Length && arr[i])
            {
                i++;
            }
            if(i != 0)
            {
                return Solve(arr.Take(i).Reverse().Select(x => !x).Concat(arr.Skip(i)).ToArray()) + 1;
            }
            return Solve(arr.Reverse().Select(x => !x).ToArray()) + 1;

        }
    }
}
