using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace _1C_B
{
    class Program
    {
        static void Main(string[] args)
        {
            String location = @"D:\Programming\Google Code Jam 2015\Round 1C Inputs\";
            String fileName = "C-small-attempt1";
            String ext = ".in";
            String outputExt = "-ANS.txt";

            String[] lines = File.ReadAllLines(location + fileName + ext);
            int cursor = 1;
            int curCase = 1;
            int numCase = Convert.ToInt16(lines[0]);


            using (StreamWriter f = new StreamWriter(location + fileName + outputExt))
            {
                while (cursor < lines.Length)
                {
                    int C = Convert.ToInt32(lines[cursor].Split(' ')[0]);
                    int D = Convert.ToInt32(lines[cursor].Split(' ')[1]);
                    int V = Convert.ToInt32(lines[cursor].Split(' ')[2]);
                    cursor++;

                    string[] data = lines[cursor].Split(' ');
                    List<int> existing = new List<int>();
                    for (int i = 0; i < D; i++)
                    {
                        existing.Add(Convert.ToInt32(data[i]));
                    }
                    cursor++;

                    List<int[]> possibles = new List<int[]>();
                    //for (int i = 0; i < D; i++)
                    //{
                    //    possibles.Add(existing[i]);

                    //    for (int j = 0; j < possibles.Count; j++)
                    //    {

                    //    }

                    //    for (int j = i + 1; j < D; j++)
                    //    {
                    //        possibles.Add(existing[i] + existing[j]);
                    //    }
                    //}
                    possibles = CreateSubsets(existing.ToArray());
                    List<int> posVals = new List<int>();
                    posVals = CreateSum(possibles);

                    List<int> missing = new List<int>();
                    missing = CreateMissing(posVals, V);

                    // Solve
                    int Solve = MinDenom(missing, existing, V);

                    f.WriteLine("Case #" + curCase + ": " + Solve);
                    Console.WriteLine("Case #" + curCase + ": " + Solve);
                    curCase++;
                }
            }

            Console.ReadKey();
        }


        static int MinDenom(List<int> missing, List<int> existing, int V)
        {
            if (missing.Count == 0)
                return 0;

            missing.Sort((a, b) => a.CompareTo(b));

            List<int> tempEx = new List<int>(existing);
            tempEx.Add(missing[0]);

            List<int[]> tempPossibles = new List<int[]>();
            List<int> tempPosVals = new List<int>();
            List<int> tempMissing = new List<int>();

            tempPossibles = CreateSubsets(tempEx.ToArray());
            tempPosVals = CreateSum(tempPossibles);
            tempMissing = CreateMissing(tempPosVals, V);

            int n = MinDenom(tempMissing, tempEx, V) + 1;
            return n;
        }

        static List<T[]> CreateSubsets<T>(T[] originalArray)
        {
            List<T[]> subsets = new List<T[]>();

            for (int i = 0; i < originalArray.Length; i++)
            {
                int subsetCount = subsets.Count;
                subsets.Add(new T[] { originalArray[i] });

                for (int j = 0; j < subsetCount; j++)
                {
                    T[] newSubset = new T[subsets[j].Length + 1];
                    subsets[j].CopyTo(newSubset, 0);
                    newSubset[newSubset.Length - 1] = originalArray[i];
                    subsets.Add(newSubset);
                }
            }

            return subsets;
        }

        static List<int> CreateSum(List<int[]> possibles)
        {
            List<int> posVals = new List<int>();
            foreach (int[] subset in possibles)
            {
                int sum = 0;
                for (int i = 0; i < subset.Length; i++)
                {
                    sum += subset[i];
                }
                posVals.Add(sum);
            }
            return posVals;
        }

        static List<int> CreateMissing(List<int> posVals, int V)
        {
            List<int> missing = new List<int>();
            for (int k = 1; k <= V; k++)
            {
                if (!posVals.Exists(x => x == k))
                {
                    missing.Add(k);
                }
            }
            return missing;
        }
    }
}
