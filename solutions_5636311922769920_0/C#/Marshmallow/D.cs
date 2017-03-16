using System;
using System.Collections.Generic;
using System.IO;

class D
{

    public void Solve()
    {
        StreamReader reader = new StreamReader("D_in.txt");
        StreamWriter writer = new StreamWriter("D_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            string[] line = reader.ReadLine().Split();
            int K = Int32.Parse(line[0]);
            int C = Int32.Parse(line[1]);
            int S = Int32.Parse(line[2]);

            // Start generating guesses:
            List<ulong> guesses = new List<ulong>();

            ulong guess = 0;
            int components = 0;
            for (int i = 0; i < K; i++)
            {
                //Console.WriteLine("Dealing with position {0}", i);
                guess += (ulong)i * Pow(K, components);
                components += 1;
                //Console.WriteLine("Guess is now {0} with {1} components", guess, components);

                // Are we done for this guess?
                if (components == C)
                {
                    guesses.Add(guess);
                    guess = 0;
                    components = 0;
                }
            }
            // And ship out the last guess
            if (components > 0) guesses.Add(guess);

            int dummy;

            // Do we have enough?
            if (guesses.Count > S)
            {
                writer.WriteLine("Case #{0}: IMPOSSIBLE", (t + 1));
                Console.WriteLine("Case #{0}: IMPOSSIBLE", (t + 1));
                continue;
            }

            string answer = String.Format("Case #{0}:", (t + 1));
            foreach (ulong g in guesses)
            {
                answer += " " + (g + 1);
            }
            writer.WriteLine(answer);
            Console.WriteLine(answer);

        }

        reader.Close();
        writer.Close();
    }

    ulong Pow(int a, int b)
    {
        ulong answer = 1;
        for (int i = 0; i < b; i++)
        {
            answer *= (ulong)a;
        }
        return answer;
    }





}
