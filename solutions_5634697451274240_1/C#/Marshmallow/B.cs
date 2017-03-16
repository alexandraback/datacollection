using System;
using System.IO;

class B
{

    public void Solve()
    {
        StreamReader reader = new StreamReader("B_in.txt");
        StreamWriter writer = new StreamWriter("B_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            string stack = reader.ReadLine();
            int flips = 0;

            // Start at the top, look for a boundary. If we find one, perform a flip
            char current = stack[0];

            for (int i = 1; i < stack.Length; i++)
            {
                if (stack[i] != current)
                {
                    flips += 1;
                    current = Flip(current);
                }
            }

            // See if we need a final flip
            if (current == '-') flips += 1;

            writer.WriteLine("Case #{0}: {1}", (t + 1), flips);
            Console.WriteLine("Case #{0}: {1}", (t + 1), flips);

        }

        reader.Close();
        writer.Close();
    }

    char Flip(char c)
    {
        if (c == '-') return '+';
        else return '-';
    }


}