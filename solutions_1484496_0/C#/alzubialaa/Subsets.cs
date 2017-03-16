using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Linq;
namespace CodeJamTest
{
    public static class Subsets
    {
        public static string[] GetSubSets(string[] inputLines)
        {
            int testCases = int.Parse(inputLines[0]);
            List<string> output = new List<string>();
            for (int index = 1; index <= testCases; index++)
            {
                List<int[]> equalSums = GetSubsets(inputLines[index]);
                if (equalSums == null)
                {
                    output.Add("Case #" + (index).ToString() + ": Impossible \n");
                }
                else
                {

                    output.Add("Case #" + (index).ToString() + ": \n");
                    output.Add(getArrayString(equalSums[0]) + " \n");
                    output.Add(getArrayString(equalSums[1]) + " \n");
                }
            }

            return output.ToArray();

        }
        private static string getArrayString(int[] arr)
        {
            string str = string.Empty;

            foreach(int num in arr)
            {
                str += num + " ";
            }
            return str.Trim();
        }
        private static List<int[]> GetSubsets(string row)
        {
            string subset = string.Empty;
           
            int[] set = (from number in  row.Split(' ')
                         select int.Parse(number)).ToArray();
            int[] setNumbers = new int[set.Length-1];
            Array.Copy(set,1,setNumbers,0,setNumbers.Length);
            List<int[]> subsets = CreateSubsets(setNumbers);
            foreach (int[] objSubset in subsets)
            {
                int sum = objSubset.Sum();
                List<int[]> equalSums = (from objsubsetItem in subsets
                                         where objsubsetItem.Sum() == sum
                                         select objsubsetItem).ToList<int[]>();

                if (equalSums.Count >= 2)
                {
                    return equalSums;
                }
            }
            return null;
        }

        private static List<int[]> CreateSubsets(int[] originalArray)
        {
            List<int[]> subsets = new List<int[]>();

            for (int i = 0; i < originalArray.Length; i++)
            {
                int subsetCount = subsets.Count;
                subsets.Add(new int[] { originalArray[i] });

                for (int j = 0; j < subsetCount; j++)
                {
                    int[] newSubset = new int[subsets[j].Length + 1];
                    subsets[j].CopyTo(newSubset, 0);
                    newSubset[newSubset.Length - 1] = originalArray[i];
                    subsets.Add(newSubset);
                }
            }

            return subsets;
        }
    }
}
