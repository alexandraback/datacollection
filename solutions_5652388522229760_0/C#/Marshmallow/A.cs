using System;
using System.IO;

class A
{
    bool[] hasSeen;

    public void Solve()
    {
        StreamReader reader = new StreamReader("A_in.txt");
        StreamWriter writer = new StreamWriter("A_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            int N = Int32.Parse(reader.ReadLine());
            if (N == 0)
            {
                writer.WriteLine("Case #{0}: INSOMNIA", (t + 1));
                Console.WriteLine("Case #{0}: INSOMNIA", (t + 1));
                continue;
            }


            hasSeen = new bool[10];
            int count = N;
            while (true)
            {
                UpdateArray(count);
                if (AreDone())
                {
                    writer.WriteLine("Case #{0}: {1}", (t + 1), count);
                    Console.WriteLine("Case #{0}: {1}", (t + 1), count);
                    break;
                }
                count += N;
            }

        }

        reader.Close();
        writer.Close();
    }

    void UpdateArray(int x)
    {
        while (x > 0)
        {
            hasSeen[x % 10] = true;
            x /= 10;
        }
    }

    bool AreDone()
    {
        for (int i = 0; i < 10; i++)
        {
            if (hasSeen[i] == false) return false;
        }
        return true;
    }
}
