using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Task_B
{
    class Solution
    {
        static void Main()
        {
            StreamReader input = new StreamReader("input");
            StreamWriter output = new StreamWriter("output");

            int TestsAmount = int.Parse(input.ReadLine());
            for (int currentTest = 1; currentTest <= TestsAmount; currentTest++)
            {
                string[] data = input.ReadLine().Split(' ');
                int K = int.Parse(data[0]);
                int L = int.Parse(data[1]);
                int S = int.Parse(data[2]);
                string kb = input.ReadLine();
                string tg = input.ReadLine();

                output.WriteLine("Case #{0}: {1}", currentTest, Solve(K, L, S, kb, tg));
                //output.Write("Case #{0}: ", currentTest);
                //output.WriteLine("{0:#.#######}", Solve(K, L, S, kb, tg));
            }

            input.Close();
            output.Close();
        }

        static double Solve(int keysNum, int targetNum, int resNum, string keys, string target)
        {
            int maxResultsOnce;
            string currentResult = "";
            //StrWrap sw = new StrWrap(currentResult);
            int caseCount;
            int res = Search(currentResult, keysNum, targetNum, resNum, keys, target, out caseCount, out maxResultsOnce);
            return (double)maxResultsOnce - ((double)res / (double)caseCount);

        }

        static int Search(string currentState, int keysNum, int targetNum, int resNum, string keys, string target, out int caseCount,
            out int maxResultsOnce)
        {
            maxResultsOnce = 0;
            int result = 0;
            caseCount = 0;
            Queue<string> queue = new Queue<string>();
            queue.Enqueue(currentState);
            while (queue.Count > 0)
            {
                string current = queue.Dequeue();
                if (current.Length != resNum)
                {
                    for (int keyCount = 0; keyCount < keysNum; keyCount++)
                    {
                        string newStr = string.Copy(current);
                        newStr = newStr + keys[keyCount];
                        queue.Enqueue(newStr);
                    }
                }
                else
                {
                    caseCount++;
                    int mr = 0;
                    for (int count = 0; count <= resNum - targetNum; count++)
                    {
                        
                        if (current.Substring(count, targetNum) == target) { result++; mr++; }
                        
                    }
                    if (mr > maxResultsOnce) maxResultsOnce = mr;
                }
            }
            return result;
        }

        //    static int MaxResultsOnce(int keysNum, int targetNum, int resNum, string keys, string target)
        //    {
        //        for (int i = 1; i < targetNum; i++)
        //        {
        //            int len=targetNum-i;
        //            string str1 = target.Substring(i, len);
        //            string str2 = target.Substring(0, len);
        //            if (str1 == str2) targetNum = i;
        //        }
        //        return resNum / targetNum;
        //    }
        //}
    }

    //class StrWrap
    //{
    //    public string s;
    //    public StrWrap(string s) { this.s = s; }
    //}

}
