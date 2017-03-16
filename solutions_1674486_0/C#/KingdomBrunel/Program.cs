using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1CProbA
{
    class Program
    {

        static int numClasses;
        static int[,] classLinks;
        static int[] classSize;
        static int[] targets;

        static int route(int i, int j)
        {
            int count = 0;
            if (i != j)
            {
                for (int k = 0; k < classSize[i]; k++)
                {
                    count += route(classLinks[i, k], j);
                }
            }
            else
            {
                count++;
            }
            //Console.WriteLine("I = {0:d}, J = {0:d}, count = {0:d}", i, j, count);
            return count;
        }

        static void Main(string[] args)
        {
            int numTestCases = Convert.ToInt32(Console.ReadLine());

            for (int testCases = 0; testCases < numTestCases; testCases++)
            {
                numClasses = Convert.ToInt32(Console.ReadLine());
                //Console.WriteLine("{0:d}", numClasses);
                classLinks = new int[numClasses,numClasses];
                classSize = new int[numClasses];
                targets = new int[numClasses];

                for (int i = 0; i < numClasses; i++)
                {
                    string items = Console.ReadLine();
                    string[] itemsStr_a = items.Split(' ');
                    
                    classSize[i] = Convert.ToInt32(itemsStr_a[0]);
                    for (int j = 0; j < classSize[i]; j++)
                    {
                        int val = Convert.ToInt32(itemsStr_a[j+1])-1;
                        classLinks[i, j] = val;
                        targets[val]++;
                    }
                }
                int count = 0;
                for (int i = 0; (i < numClasses) && (count < 2); i++)
                {
                    if (classSize[i] > 1)
                    {
                        for (int j = 0; ((j < numClasses) && (count < 2)); j++)
                        {
                            count = route(i,j);
                        }
                    }
                }

                if (count > 1)
                {
                    Console.WriteLine("Case #{0:d}: Yes", testCases + 1);
                }
                else
                {
                    Console.WriteLine("Case #{0:d}: No", testCases + 1);
                }
            }
        }
    }
}
