using System.Collections.Generic;
using System.IO;
using System.Text;

namespace RecycledNumbers
{
    internal class Program
    {
        private static void Main()
        {
            string[] text = File.ReadAllLines(@"d:\a.txt");
            for (int i = 1; i < text.Length; i++)
            {
                string[] numbers = text[i].Split(' ');
                if (numbers[0].Length == 1 || numbers[0].Length != numbers[1].Length)
                {
                    File.AppendAllText(@"d:\out.txt", string.Format("Case #{0}: {1}\n", i, 0));
                    continue;
                }
                int a = int.Parse(numbers[0]);
                int b = int.Parse(numbers[1]);

                int n = a.ToString().Length;

                int temp = a;

                int result = 0;

                while (temp < b)
                {
                    var set = new HashSet<int>();
                    for (int j = 1; j < n; j++)
                    {
                        if (IsEqualOrSmaller(temp.ToString(), j, n, b.ToString()))
                        {
                            if (IsGreater(temp.ToString(), j, n, temp.ToString()))
                            {
                                int number = int.Parse(GetNumber(temp.ToString(), j, n));
                                if(!set.Contains(number))
                                {
                                    set.Add(number);
                                    ++result;
                                }
                            }
                        }
                    }

                    ++temp;
                }
                File.AppendAllText(@"d:\out.txt", string.Format("Case #{0}: {1}\n", i, result));
            }
        }

        public static bool IsEqualOrSmaller(string first, int i, int n, string second)
        {
            for (int j = 0; j < second.Length; j++)
            {
                if (first[(i + j)%n] > second[j])
                {
                    return false;
                }
                if (first[(i + j)%n] < second[j])
                {
                    return true;
                }
            }
            return true;
        }

        public static bool IsGreater(string first, int i, int n, string second)
        {
            for (int j = 0; j < second.Length; j++)
            {
                if (first[(i + j)%n] > second[j])
                {
                    return true;
                }
                if (first[(i + j)%n] < second[j])
                {
                    return false;
                }
            }
            return false;
        }

        public static string GetNumber(string s, int i, int n)
        {
            var stringBuilder = new StringBuilder();
            for(int j = 0; j < n; j++)
            {
                stringBuilder.Append(s[(i + j)%n]);
            }
            return stringBuilder.ToString();
        }
    }
}