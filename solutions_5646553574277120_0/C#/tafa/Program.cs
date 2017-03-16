using System;
using System.Collections.Generic;
using System.Linq;

namespace qtn1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list = new List<int>() { 1, 2, 5 };


            int testCount = int.Parse(Console.ReadLine().Trim());

            for (int i = 0; i < testCount; i++)
                SolveProblem(i + 1);
        }

        private static void SolveProblem(int testNum)
        {
            int result = 0;

            string[] parts = Console.ReadLine().Trim().Split(' ');
            int C = int.Parse(parts[0]);
            int D = int.Parse(parts[1]);
            int V = int.Parse(parts[2]);

            List<int> list = Console.ReadLine().Trim().Split(' ').Select(x => int.Parse(x)).ToList<int>();

            if (!list.Contains(1))
            {
                result = 1;
                list.Add(1);
            }

            while (true)
            {
                bool flag = false;

                List<int> allPossibilities = GetAllPossibilities(list);

                for (int i = 1; i <= V; i++)
                {
                    if (!allPossibilities.Contains(i))
                    {
                        list.Add(i);
                        result += 1;
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                    break;
            }

            Console.WriteLine("Case #" + testNum + ": " + result);
        }

        private static List<int> GetAllPossibilities(List<int> list)
        {
            List<int> result = new List<int>();

            int upperLimit = (int)(Math.Pow(2, list.Count));

            for (int i = 0; i < upperLimit; i++)
            {
                int localResult = 0;
                for (int j = 0; j < list.Count; j++)
                {
                    int val = (int)(Math.Pow(2, j));

                    if ((val & i) != 0)
                    {
                        localResult += list[j];
                    }
                }
                result.Add(localResult);
            }

            return result;
        }
    }
}
