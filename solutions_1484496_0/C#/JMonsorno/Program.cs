using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cjr1bc1
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputText = File.ReadAllText(args[0]).Replace("\r\n", "\n").Replace("\r", "\n");
            string inputFilename = Path.GetFileNameWithoutExtension(args[0]);
            string[] input = inputText.Split('\n');
            StreamWriter output = new StreamWriter(String.Format("{0}.out", inputFilename));

            int T = Int32.Parse(input[0]);
            for (int t = 1; t <= T; ++t)
            {
                output.WriteLine(ProcessTest(t, input[t]));
                output.Flush();
            }

            output.Close();
        }

        private static string ProcessTest(int t, string p)
        {
            string result = String.Empty;
            List<long> numbers = p.Trim().Split(' ').Select(s => long.Parse(s)).ToList();
            if (numbers[0] + 1 != numbers.Count)
                throw new ApplicationException();
            numbers.RemoveAt(0);
            Dictionary<long, List<long>> sumSets = new Dictionary<long, List<long>>();
            bool solutionFound = false;
            for (int step = 2; step < numbers.Count - 2; ++step)
            {
                for (int i = 0; i < numbers.Count; ++i)
                {
                    long number = numbers[i];
                    if (sumSets.ContainsKey(number))
                    {
                        result = MakeStringResult(sumSets[number], new List<long>() { number });
                        solutionFound = true;
                        break;
                    }
                    if (step == 2)
                    {
                        foreach (long secondNumber in numbers.Skip(i + 1))
                        {
                            long sum = number + secondNumber;
                            List<long> newList = new List<long>() { number, secondNumber };
                            if (sumSets.ContainsKey(sum))
                            {
                                result = MakeStringResult(sumSets[sum], newList);
                                solutionFound = true;
                                break;
                            }
                            sumSets.Add(sum, newList);
                        }
                        if (solutionFound)
                            break;
                        continue;
                    }
                    //else
                    List<List<long>> distinctSets = sumSets.Values
                        //.Where(set => set.Count == step)
                        .Where(set => !set.Contains(number)).ToList();
                    foreach (List<long> setTemp in distinctSets)
                    {
                        List<long> set = new List<long>();
                        set.AddRange(setTemp);
                        if (set.Contains(number))
                            continue; //WTF but it happens
                        set.Add(number);
                        long sum = set.Sum();
                        if (sumSets.ContainsKey(sum))
                        {
                            List<long> repeats = set.Intersect(sumSets[sum]).ToList();
                            if (repeats.Count == set.Count || repeats.Count == sumSets[sum].Count)
                                continue;
                            result = MakeStringResult(sumSets[sum], set);
                            solutionFound = true;
                            break;
                        }
                        sumSets.Add(sum, set);
                    }

                }
                if (solutionFound)
                    break;
            }
            if (solutionFound)
                result = String.Format("Case #{0}:{1}{2}", t, Environment.NewLine, result);
            else
                result = String.Format("Case #{0}:{1}Impossible", t, Environment.NewLine);
            return result;
        }

        private static string MakeStringResult(List<long> set1, List<long> set2)
        {
            List<long> repeats = set1.Intersect(set2).ToList();
            set1 = set1.Except(repeats).ToList();
            set2 = set2.Except(repeats).ToList();
            
            return String.Format("{0}{1}{2}", String.Join(" ", set1.Select(l => l.ToString()).ToArray()), Environment.NewLine, String.Join(" ", set2.Select(l => l.ToString()).ToArray()));
        }
    }
}
