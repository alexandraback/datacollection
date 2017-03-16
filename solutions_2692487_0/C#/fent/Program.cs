using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Diagnostics;

namespace _13_2A
{
    class _2A
    {
        static void Main(string[] args)
        {
            int T;

            string str;
            string[] strs;
            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                int A, N;
                str = Console.ReadLine();
                strs = str.Split(' ');
                A = int.Parse(strs[0]);
                N = int.Parse(strs[1]);

                int[] data = new int[N];

                str = Console.ReadLine();
                strs = str.Split(' ');

                for (int i = 0; i < N; i++)
                {
                    data[i] = int.Parse(strs[i]);
                }


                int[] sortedData = data.OrderBy(x => x).ToArray();
                int[] costData = new int[N];


                int maxCost = N;
                int size = A;
                for (int i = 0; i < N; i++)
                {
                    while (!(size > sortedData[i]))
                    {
                        if (maxCost == 0)
                        {
                            break;
                        }
                        maxCost--;
                        size = size * 2 - 1;
                        costData[i]++;
                    }
                    size += sortedData[i];
                }

                int result = 1000;

                for (int i = 0; i <= N; i++)
                {

                    int score = N - i;
                    for (int j = 0; j < i; j++)
                    {
                        score += costData[j];
                    }
                    if (score < result) { result = score; }
                }




                    Console.WriteLine("Case #" + caseNumber + ": " + result);
            }

            Debug.WriteLine("fin");

            //Console.ReadLine();

        }
    }
}
