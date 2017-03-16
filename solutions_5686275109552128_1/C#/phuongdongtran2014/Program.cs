using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Linq;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            Exercise2();

            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }

        static void Exercise1()
        {
            List<string> lines = Utils.GetStringList("input.txt");
            int numofCases = Convert.ToInt32(lines[0]);

            List<string> outputs = new List<string>();

            for (int i = 1; i <= numofCases; i++)
            {
                string[] arr = lines[i].Split(null);
                int maxShynessLevel = Convert.ToInt32(arr[0]);
                string last = arr[1];

                bool flag = false;
                int totalAudience = 0;
                int added = 0;
                for (int j = 0; j < maxShynessLevel + 1; j++)
                {
                    char cNumofAudience = last[j];
                    int numofAudiene = Int32.Parse(cNumofAudience.ToString());
                    if (numofAudiene == 0)
                    {
                        flag = true;
                    }
                    else
                    {
                        if (flag == true)
                        {
                            added += Math.Max(0, j - totalAudience);
                            totalAudience += added;
                        }
                        totalAudience += numofAudiene;
                        flag = false;
                    }
                }

                outputs.Add("Case #"+ i +": " + added);
            }

            Utils.WriteFile(outputs, "output.txt");
        }


        static void Exercise2()
        {
            List<string> lines = Utils.GetStringList("B-large.in");
            //List<string> lines = Utils.GetStringList("input.txt");
            int numofCases = Convert.ToInt32(lines[0]);

            List<string> outputs = new List<string>();

            for (int i = 0; i < numofCases; i++)
            {
                int D = Int32.Parse(lines[2 * i + 1]);
                string[] arr = (lines[2 * i + 2]).Split(null);
                int[] arrInt = Array.ConvertAll(arr, s => int.Parse(s));

                List<int> myInts = new List<int>(arrInt);
                int minMinutes = 1000;
                int maxInt = myInts.Max();
                for (int j = 1; j <= maxInt; j++)
                {
                    int numofDivided = 0;
                    for (int k = 0; k < myInts.Count; k++)
                    {
                        int element = myInts[k];
                        if (element > j)
                        {
                            numofDivided += (int)Math.Ceiling(element / (float) j) - 1;
                        }
                    }

                    if (numofDivided + j < minMinutes)
                    {
                        minMinutes = numofDivided + j;
                    }
                }

                outputs.Add("Case #" + (i + 1) + ": " + minMinutes);
                Console.WriteLine("Testcase:" + (i + 1));
            }

            Utils.WriteFile(outputs, "2-output-2.txt");
        }


        static void Exercise3()
        {
            //List<string> lines = Utils.GetStringList("B-small-attempt0.in");
            List<string> lines = Utils.GetStringList("input.txt");
            int numofCases = Convert.ToInt32(lines[0]);

            List<string> outputs = new List<string>();

            for (int i = 0; i < numofCases; i++)
            {
                int D = Int32.Parse(lines[2 * i + 1]);
                string[] arr =  (lines[2 * i + 2]).Split(null);
                int[] arrInt = Array.ConvertAll(arr, s => int.Parse(s));

                List<int> myInts = new List<int>(arrInt);
                myInts.Sort();

                int minPick = myInts[myInts.Count - 1];
                int numofMinutes = 0;
                while (true)
                {
                    int len = myInts.Count;
                    int sqrtLast = (int)Math.Ceiling(Math.Sqrt(myInts[len - 1]));
                    List<int> added = new List<int>();
                    for (int j = len - 1; j >= 0; j--)
                    {
                        if (sqrtLast < myInts[j])
                        {
                            numofMinutes += ProcessElement(sqrtLast, myInts[j], added);
                            myInts[j] = sqrtLast;
                        }

                        int maxArr = myInts.Max();
                        if (numofMinutes + maxArr < minPick)
                        {
                            minPick = numofMinutes + maxArr;
                        }
                    }

                    myInts.AddRange(added);
                    myInts.Sort();

                    if (numofMinutes + myInts[myInts.Count - 1] < minPick)
                    {
                        minPick = numofMinutes + myInts[myInts.Count - 1];
                    }
                    else
                    {
                        break;
                    }
                }

                outputs.Add("Case #" + (i + 1) + ": " + minPick);
                Console.WriteLine("Testcase:" + (i + 1));
            }

            Utils.WriteFile(outputs, "2-output-2.txt");
        }

        private static int ProcessElement(int sqrtLast, int element, List<int> added)
        {
            int origin = element;
            while (true)
            {
                if (element - sqrtLast >= 0)
                {
                    added.Add(sqrtLast);
                    element -= sqrtLast;
                }
                else
                {
                    if (element > 0 ) added.Add(element);
                    break;
                }
            }
            return (int)Math.Ceiling(origin / (float)sqrtLast) - 1;
        }
    }
}
