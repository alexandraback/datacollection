using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;
using System;

namespace P1
{
    class Program
    {
        const string size = "small";

        static void Main()
        {
            using (var streamReader = new StreamReader($"A-{size}.in"))
            using (var streamWriter = new StreamWriter($"output-{size}.txt"))
            {
                int t = int.Parse(streamReader.ReadLine());

                for (int j = 0; j < t; j++)
                {
                    streamWriter.Write($"Case #{j + 1}: ");
                    string s = streamReader.ReadLine();

                    var digits = new List<string> { "ZERO", "ONE", "TWO", "THREE", "FOUR",
                        "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

                    var order = new int[] { 0, 6, 4, 3, 7, 8, 5, 9, 1, 2 };

                    var digitDict = new Dictionary<char, int> [10];

                    for (int q = 0; q < 10; q++)
                    {
                        digitDict[q] = new Dictionary<char, int>();
                        string u = digits[q];
                        for (int k = 0; k < u.Length; k++)
                        {
                            char c = u[k];

                            if (!digitDict[q].ContainsKey(c))
                            {
                                digitDict[q][c] = 1;
                            }
                            else
                            {
                                digitDict[q][c] = digitDict[q][c] + 1;
                            }
                        }
                    }

                    var numberDigits = new List<char>();

                    var counts = new Dictionary<char, int>();

                    for(int k = 0; k < s.Length; k++)
                    {
                        char c = s[k];
                        
                        if(!counts.ContainsKey(c))
                        {
                            counts[c] = 1;
                        }
                        else
                        {
                            counts[c] = counts[c] + 1;
                        }
                    }

                    string result = string.Empty;

                    for(int k = 0; k < 10; k++)
                    {
                        int kk = order[k];
                        bool found;
                        do
                        {
                            string d = digits[kk];

                            found = false;
                            foreach (char c in d)
                            {
                                int count;
                                if (counts.TryGetValue(c, out count) && count >= digitDict[kk][c])
                                {
                                    found = true;
                                }
                                else
                                {
                                    found = false;
                                    break;
                                }
                            }

                            if (found)
                            {
                                foreach (char c in d.Distinct())
                                {
                                    counts[c] = counts[c] - digitDict[kk][c];
                                }

                                result += kk;
                            }
                        } while (found);
                    }

                    if(counts.Any(c => c.Value > 0))
                    {
                        Debug.WriteLine($"There is still a digit remaining! Line {j+2} in the input file.");
                    }

                    var a = result.ToCharArray();
                    Array.Sort(a);

                    streamWriter.WriteLine(a);
                }
            }
        }
    }
}
