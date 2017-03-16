using System;
using System.IO;
using System.Collections.Generic;

class C
{
    public void Solve()
    {
        StreamReader reader = new StreamReader("C_in.txt");
        StreamWriter writer = new StreamWriter("C_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            string[] line = reader.ReadLine().Split();
            int J = Int32.Parse(line[0]);
            int P = Int32.Parse(line[1]);
            int S = Int32.Parse(line[2]);
            int K = Int32.Parse(line[3]);

            int[,] JPpairs = new int[J, P];
            int[,] JSpairs = new int[J, S];
            int[,] PSpairs = new int[P, S];

            List<string> triples = new List<string>();
            for (int j = 0; j < J; j++)
            {
                for (int p = 0; p < P; p++)
                {
                    for (int s = 0; s < S; s++)
                    {
                        if ((JPpairs[j, p] < K) && (JSpairs[j, s] < K) && (PSpairs[p, s] < K))
                        {
                            triples.Add(String.Format("{0} {1} {2}", j + 1, p + 1, s + 1));
                            JPpairs[j, p] += 1;
                            JSpairs[j, s] += 1;
                            PSpairs[p, s] += 1;
                        }
                    }
                }
            }

            writer.WriteLine("Case #{0}: {1}", (t + 1), triples.Count);
            Console.WriteLine("Case #{0}: {1}", (t + 1), triples.Count);
            foreach (string s in triples)
            {
                writer.WriteLine(s);
                Console.WriteLine(s);
            }
        }

        reader.Close();
        writer.Close();
    }


}
