using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace C_GoodLuck
{
    class Program
    {
        static void Main(string[] args)
        {
            Stream result = new FileStream("output.txt", FileMode.Create);
            StreamWriter writer = new StreamWriter(result);
            writer.AutoFlush = true;

            Stream file = new FileStream("input.txt", FileMode.Open);
            StreamReader reader = new StreamReader(file);
            int count = int.Parse(reader.ReadLine());
            List<List<object>> cases = ParseCases(count, reader);

            int counter = 1;
            string caseResult;

            writer.WriteLine("Case #1:");

            foreach (List<object> caseData in cases)
            {
                caseResult = ProcessCase(caseData, writer);



                counter++;
            }
            Console.ReadLine();
        }

        static List<List<object>> ParseCases(int count, StreamReader r)
        {
            List<List<object>> result = new List<List<object>>();
            for (int i = 0; i < count; i++)
            {
                List<object> caseData = new List<object>();
                string row = r.ReadLine();
                string[] rowData = row.Split(' ');
                int caseCount = int.Parse(rowData[0]);
                int digitCount = int.Parse(rowData[1]);
                int max = int.Parse(rowData[2]);
                int productCount = int.Parse(rowData[3]);
                List<List<int>> cases = new List<List<int>>();
                for (int j = 0; j < caseCount; j++)
                {
                    List<int> products = new List<int>();
                    row = r.ReadLine();
                    rowData = row.Split(' ');
                    foreach (string s in rowData)
                    {
                        products.Add(int.Parse(s));
                    }
                    cases.Add(products.OrderByDescending(c => c).ToList<int>());
                }
                caseData.Add(caseCount);
                caseData.Add(digitCount);
                caseData.Add(max);
                caseData.Add(productCount);
                caseData.Add(cases);

                result.Add(caseData);
            }

            return result;
        }

        static string ProcessCase(List<object> data, StreamWriter writer)
        {
            int caseCount = (int)data[0];
            int digitCount = (int)data[1];
            int max = (int)data[2];
            int productCount = (int)data[3];
            List<List<int>> cases = (List<List<int>>)data[4];

            foreach (List<int> caseData in cases)
            {
                caseData.RemoveAll(f => f == 1);
                if (caseData.Count == 0)
                {
                    writer.WriteLine("222");
                    Console.WriteLine("222");
                    continue;
                }
                bool wrote = false;
                int i = caseData[0];
                List<int> factors = Factor(i);
                factors.RemoveAll(f => f > max);
                factors.Remove(1);
                List<int> facts = new List<int>();
                for (int j = 0; j < digitCount; j++)
                {
                    facts.AddRange(factors);
                }
                List<int[]> subsets = Combinations(facts, digitCount).ToList();
                List<List<int>> goodSubs = new List<List<int>>();
                foreach (int[] subsetA in subsets)
                {
                    List<int> subset = new List<int>(subsetA);
                    subset.Sort();
                    if (subset.Aggregate((a, b) => a * b) == i)
                    {
                        goodSubs.Add(subset);
                    }
                }
                goodSubs = goodSubs.Distinct(new SEComparer()).ToList();
                foreach (List<int> sub in goodSubs)
                {
                    bool good = false;
                    foreach (int check in caseData)
                    {
                        List<int[]> combs = new List<int[]>();
                        for (int l = 1; l <= digitCount; l++)
                        {
                            combs.AddRange(Combinations(sub, l).ToList());
                        }
                        foreach (int[] comb in combs)
                        {
                            int prod = comb.Aggregate((a, b) => a * b);
                            if (prod == check)
                            {
                                good = true;
                                break;
                            }
                        }
                    }
                    if (good)
                    {
                        wrote = true;
                        writer.WriteLine(string.Join("", sub));
                        Console.WriteLine(string.Join("", sub));
                        break;
                    }
                }

                if (!wrote)
                {
                    writer.WriteLine("222");
                    Console.WriteLine("222");
                    continue;
                }
            }
            return "";
        }

        public static List<int> Factor(int number)
        {
            List<int> factors = new List<int>();
            int max = (int)Math.Sqrt(number);
            for (int factor = 1; factor <= max; ++factor)
            {
                if (number % factor == 0)
                {
                    factors.Add(factor);
                    if (factor != number / factor)
                    {
                        factors.Add(number / factor);
                    }
                }
            }
            return factors;
        }

        public static IEnumerable<T[]> Combinations<T>(IList<T> argList, int argSetSize)
        {
            if (argList == null) throw new ArgumentNullException("argList");
            if (argSetSize <= 0) throw new ArgumentException("argSetSize Must be greater than 0", "argSetSize");
            return combinationsImpl(argList, 0, argSetSize - 1);
        }

        private static IEnumerable<T[]> combinationsImpl<T>(IList<T> argList, int argStart, int argIteration, List<int> argIndicies = null)
        {
            argIndicies = argIndicies ?? new List<int>();
            for (int i = argStart; i < argList.Count; i++)
            {
                argIndicies.Add(i);
                if (argIteration > 0)
                {
                    foreach (var array in combinationsImpl(argList, i + 1, argIteration - 1, argIndicies))
                    {
                        yield return array;
                    }
                }
                else
                {
                    var array = new T[argIndicies.Count];
                    for (int j = 0; j < argIndicies.Count; j++)
                    {
                        array[j] = argList[argIndicies[j]];
                    }

                    yield return array;
                }
                argIndicies.RemoveAt(argIndicies.Count - 1);
            }
        }

        public class SEComparer : IEqualityComparer<List<int>>
        {
            public bool Equals(List<int> x, List<int> y)
            {
                return x.SequenceEqual(y);
            }

            public int GetHashCode(List<int> obj)
            {
                int hashCode = 0;

                for (var index = 0; index < obj.Count; index++)
                {
                    hashCode ^= new { Index = index, Item = obj[index] }.GetHashCode();
                }

                return hashCode;
            }
        }
    }

}


