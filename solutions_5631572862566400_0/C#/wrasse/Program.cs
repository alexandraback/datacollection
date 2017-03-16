using System;
using System.Collections.Generic;
using System.Linq;

namespace _2016_1A_C
{
    class Program
    {
        static void Main()
        {
            var input = Console.ReadLine();
            var caseCount = int.Parse(input);

            for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                input = Console.ReadLine();
                var kidCount = int.Parse(input);

                input = Console.ReadLine();
                int[] bff = input.Split(' ').Select(n => Convert.ToInt32(n)).ToArray();

                for (int ii = 0; ii < kidCount; ii++)
                {
                    bff[ii]--;
                }

                int largest = 0;
                for (int ii = 0; ii < kidCount; ii++)
                {
                    int count = 1;
                    int firstKid = ii;

                    var dictionary = new Dictionary<int, int>();
                    dictionary.Add(firstKid, bff[firstKid]);

                    int lastKid = ii;
                    int nextKid = bff[ii];
                    while (true)
                    {
                        if (nextKid == firstKid)
                        {
                            break;
                        }
                        else
                        {
                            if (dictionary.ContainsKey(nextKid))
                            {
                                if (dictionary[nextKid] != lastKid)
                                {
                                    bool found2 = false;
                                    for (int jj = 0; jj < kidCount; jj++)
                                    {
                                        if (bff[jj] == firstKid)
                                        {
                                            if (!dictionary.ContainsKey(jj))
                                            {
                                                found2 = true;
                                                nextKid = jj;
                                            }
                                        }
                                    }
                                    if (found2)
                                    {
                                        count++;
                                    }
                                    else
                                    {
                                        count = 0;
                                    }
                                    break;
                                }
                                bool found = false;
                                for (int jj = 0; jj < kidCount; jj++)
                                {
                                    if (bff[jj] == lastKid)
                                    {
                                        if (!dictionary.ContainsKey(jj))
                                        {
                                            found = true;
                                            nextKid = jj;
                                        }
                                    }
                                }
                                if (!found) break;
                            }
                            else
                            {
                                count++;

                                lastKid = nextKid;
                                dictionary.Add(nextKid, bff[nextKid]);
                                nextKid = bff[nextKid];
                            }
                        }
                    }

                    if (count > largest)
                    {
                        largest = count;
                    }
                }

                Console.WriteLine($"Case #{caseNumber}: {largest}");
            }
        }
    }
}
