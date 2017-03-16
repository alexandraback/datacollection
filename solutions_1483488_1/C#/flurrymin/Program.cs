using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RecycledNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\wangran\Documents\visual studio 11\Projects\GoogleCodeJam\RecycledNumbers\C-large.in.txt");
            for (int i = 1; i < lines.Length; i++)
            {
                int[] numbers = lines[i].Split(' ').Select(s => int.Parse(s)).ToArray();
                int A = numbers[0];
                int B = numbers[1];
                int result = 0;
                for (int n = A; n <= B; n++)
                {
                    string N = n.ToString();
                    List<int> dic = new List<int>();
                    for (int j = 1; j < N.Length; j++)
                    {
                        int newN = int.Parse(N.Substring(j) + N.Substring(0, j));
                        if (newN > int.Parse(N) && newN <= B)
                        {
                            if (!dic.Contains(newN))
                            {
                                dic.Add(newN);
                                result++;
                            }
                        }
                    }
                }
                Console.WriteLine(A + "," + B);
                var resultLine = string.Format("Case #{0}: {1}\n", i, result);
                Console.Write(resultLine);
                File.AppendAllText(@"C:\Users\wangran\Documents\visual studio 11\Projects\GoogleCodeJam\RecycledNumbers\C-large.out.txt", resultLine);
            }

        }
    }
}
