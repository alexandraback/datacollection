using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_R1B_C
{
    class Program
    {
        static int[] a;
        static bool[] flags;

        static Dictionary<long, List<List<int>>> sums;

        static int n;

        static bool isFinded;

        static List<int> set1, set2;

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"..\..\input.txt");

            StringBuilder output = new StringBuilder();

            int countOfTests = int.Parse(input[0]);
            for (int i = 0; i < countOfTests; i++)
            {
                string[] test = input[i + 1].Split(' ');

                n = int.Parse(test[0]);

                a = new int[n];
                flags = new bool[n];
                sums = new Dictionary<long, List<List<int>>>();

                for (int j = 0; j < n; j++)
                {
                    a[j] = int.Parse(test[j + 1]);
                }

                isFinded =false;
                Find(0,0, new List<int>());

                output.AppendLine(string.Format("Case #{0}: ", i + 1));
                if (isFinded)
                {
                    output.AppendLine(GetString(set1));
                    output.AppendLine(GetString(set2));
                }
                else
                    output.AppendLine("Impossible");
            }

            File.WriteAllText(@"..\..\output.txt", output.ToString());
        }

        private static string GetString(List<int> set)
        {
            string s = "";
            foreach (var item in set)
                s += item + " ";

            return s.Trim();
        }

        static void Find(int j, long sum, List<int> numbers)
        {
            if (isFinded)
                return;

            if (sums.ContainsKey(sum))
            {
                foreach (var set in sums[sum])
                {
                    bool isDistinct = false;


                    foreach (var item in set)
                        if (!numbers.Contains(item))
                        {
                            isDistinct = true;
                            break;
                        }

                    if (!isDistinct)
                    {
                        foreach (var item in numbers)
                            if (!set.Contains(item))
                            {
                                isDistinct = true;
                                break;
                            }
                    }

                    if (isDistinct)
                    {
                        set1 = set;

                        List<int> list = new List<int>();
                        foreach (var item in numbers)
                            list.Add(item);
                        set2 = list;

                        isFinded = true;
                        return;
                    }
                }
            }
            else
            {
                sums[sum] = new List<List<int>>();

                List<int> list = new List<int>();
                foreach (var item in numbers)
                    list.Add(item);

                sums[sum].Add(list);
            }

            for(int i=j;i<n;i++)
                if (!flags[i])
                {
                    flags[i] = true;

                    numbers.Add(a[i]);
                    
                    Find(i+1, sum + a[i], numbers);

                    numbers.RemoveAt(numbers.Count - 1);

                    flags[i] = false;
                }
        }


    }
}
