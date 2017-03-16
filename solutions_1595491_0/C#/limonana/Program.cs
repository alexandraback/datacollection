using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace template
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = File.OpenText("A-small-practice.in");
            StreamWriter writer = new StreamWriter("small_out.txt");            
            int T = int.Parse(reader.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                IEnumerable<int> data = reader.ReadLine().Split(' ').Select(x => int.Parse(x));
                int N = data.ElementAt(0);
                int S = data.ElementAt(1); //suprising triplets
                int P = data.ElementAt(2);
                List<int> score = new List<int>(N);
                for (int i = 1; i <= N; i++)
			    {
			        score.Add(data.ElementAt(2+i));
			    }                
                int answer=solve(score,S,P); 
                writer.WriteLine(String.Format("Case #{0}: {1}", t, answer));
            }
            writer.Flush();
            writer.Close();
            reader.Close();
        }

        private static int solve(List<int> scores, int S, int p)
        {
            int limitSuprise = 3 * p - 4;
            int limitNOTSuprise = 3 * p - 2;
            int count = 0;
            foreach (var score in scores)
            {
                if (score == 0)
                {
                    if (p == 0)
                        ++count;
                    continue;
                }
                if (limitNOTSuprise<= score)
                {
                    ++count;
                    continue;
                }
                if (S > 0 && limitSuprise <=score)
                {
                    --S;
                    ++count;
                    continue;
                }

            }
            return count;
        }
    }
}
