using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Program
    {
        static Dictionary<int, int> dictNorm = new Dictionary<int, int>();
        static Dictionary<int, int> dictSurp = new Dictionary<int, int>();

        public class Line
        {
            public int cnt;
            public int p;
            public int jokers;
            public int[] scores;

            public Line(string line)
            {
                var arr = line.Split(' ');
                cnt = int.Parse(arr[0]);
                jokers = int.Parse(arr[1]);
                p = int.Parse(arr[2]);
                scores = new int[cnt];
                for (int i = 0; i < cnt; i++)
                {
                    scores[i] = int.Parse( arr[3 + i] );
                }
            }
        }

        static void Main(string[] args)
        {
            BuildDicts();

            int N = int.Parse(Console.ReadLine());

            for (int i = 1; i <= N; i++)
            {
                var line = new Line(Console.ReadLine());
                int ans = 0;

                for (int j = 0; j < line.cnt; j++)
                {
                    int score = line.scores[j];
                    if (dictNorm[score] >= line.p)
                        ans++;
                    else if (line.jokers >0 && dictSurp.ContainsKey(score) && dictSurp[score] >= line.p)
                    {
                        line.jokers--;
                        ans++;
                    }
                }

                Console.WriteLine("Case #" + i + ": " + ans);
            }
        }

        public static void BuildDicts()
        {
            for (int i = 0; i <= 10 ; i++)
            {
                for (int j = i; j < i + 3; j++)
                {
                    for (int k = i; k < i + 3; k++)
                    {
                        if(j > 10 || k > 10)
                            break;

                        bool surp = false;
                        if (j == i + 2 || k == i + 2)
                            surp = true;

                        int max = Math.Max(i, Math.Max(j,k));
                        int key = i + j + k;

                        if (surp)
                            dictSurp[key] = max;
                        else
                            dictNorm[key] = max;
                    }
                }
            }
        }
    
    }


}
