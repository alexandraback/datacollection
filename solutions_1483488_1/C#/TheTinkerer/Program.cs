using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace RecycledNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    // read number of test cases
                    int rowCount;
                    int.TryParse(reader.ReadLine(), out rowCount);

                    // read line by line
                    for (int i = 0; i < rowCount; i++)
                    {
                        string[] data = reader.ReadLine().Split(' ');
                        int minValue, maxValue;
                        int.TryParse(data[0], out minValue);
                        int.TryParse(data[1], out maxValue);
                        int distinctRecycledPairs = 0;
                        
                        for (int j = minValue; j <= maxValue; j++)
                        {
                            List<int> recycledValues = new List<int>();
                            string n = j.ToString();

                            if (n.Length < 2)
                            {
                                break;
                            }

                            for (int k = 1; k < n.Length; k++)
                            {
                                if (int.Parse(n[k].ToString()) == 0)
                                {
                                    continue;
                                }

                                StringBuilder temp = new StringBuilder();
                                for (int x = k; x < n.Length; x++)
                                {
                                    temp.Append(n[x]);
                                }

                                for (int y = 0; y < k; y++)
                                {
                                    temp.Append(n[y]);
                                }

                                int m;
                                int.TryParse(temp.ToString(), out m);

                                if (m <= j)
                                {
                                    continue;
                                }

                                if (m > maxValue)
                                {
                                    continue;
                                }

                                if (recycledValues.Contains(m))
                                {
                                    continue;
                                }

                                distinctRecycledPairs++;
                                recycledValues.Add(m);
                            }
                        }

                        writer.WriteLine("Case #{0}: {1}", i + 1, distinctRecycledPairs);
                    }
                }
            }
        }
    }
}
