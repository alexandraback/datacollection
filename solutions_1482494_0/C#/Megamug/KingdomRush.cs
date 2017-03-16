using System.Collections.Generic;
using System;

class KingdomRush
{
    FileUtil file;

    public class Level : IComparable<Level>
    {
        public long a;
        public long b;

        public bool completedA = false;

        int IComparable<Level>.CompareTo(Level other)
        {
            if (b == other.b)
            {
                if (a > other.a)
                {
                    return -1;
                }
                else if (a < other.a)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

            if (b < other.b)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }

    public KingdomRush()
    {
        file = new FileUtil("in.txt", "out.txt");
    }

    public void solve()
    {
        int numTests = file.readInt();

        for (int i = 0; i < numTests; i++)
        {
            solveTest(i + 1);
        }

        file.close();
    }

    public void solveTest(int testNumber)
    {
        long N = file.readLong();

        List<Level> levels = new List<Level>();

        for (long n = 0; n < N; n++)
        {
            Level l = new Level();
            l.a = file.readLong();
            l.b = file.readLong();

            levels.Add(l);
        }

        levels.Sort();

        long completedLevels = 0;
        long numStars = 0;
        bool failed = false;

        while (levels.Count > 0)
        {
            int newStars = Next(levels, numStars);

            if (newStars == 0)
            {
                failed = true;
                break;
            }

            numStars += newStars;
            completedLevels++;
        }


        file.writeCase(testNumber);
        if (!failed)
        {
            file.writeLongLine(completedLevels);
        }
        else
        {
            file.writeStringLine("Too Bad");
        }
    }

    public int Next(List<Level> levels, long numStars)
    {
        for (int i = 0; i < levels.Count; i++)
        {
            if (levels[i].b <= numStars)
            {
                int result = 0;
                if (levels[i].completedA)
                {
                    result = 1;
                }
                else
                {
                    result = 2;
                }
                levels.Remove(levels[i]);
                return result;
            }
        }

        for (int i = levels.Count - 1; i >= 0; i--)
        {
            if (!levels[i].completedA && levels[i].a <= numStars)
            {
                levels[i].completedA = true;
                return 1;
            }
        }

        return 0;
    }
}
