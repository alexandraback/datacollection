using System.IO;
using System.Linq;
using GCJ_base;

namespace GCJ_1BA
{
    class Program
    {
        static void Main()
        {
            new Gcj1BA().Run();
        }
    }

    class Gcj1BA : Gcj
    {
        public Gcj1BA()
        {
            Problem = 'A';
            Small = false;
        }

        protected override string ComputeCase(TextReader reader)
        {
            var line = ReadIntLine(reader);
            int a = line[0];
            int[] motes = ReadIntLine(reader).OrderBy(i => i).ToArray();

            if (a == 1)
                return motes.Length.ToString();

            int[] added = new int[motes.Length];

            for (int i = 0; i < motes.Length; i++)
            {
                while (motes[i] >= a)
                {
                    a += a - 1;
                    added[i]++;
                }
                a += motes[i];
            }

            int total = 0;
            int[] totals = new int[added.Length + 1];
            for (int i = 0; i < added.Length; i++)
            {
                total += added[i];
                totals[i + 1] = total;
            }

            int min = int.MaxValue;

            for (int i = 0; i < totals.Length; i++)
            {
                int remove = totals.Length - i - 1;
                int add = totals[i];

                int operations = add + remove;
                if (operations < min)
                    min = operations;
            }

            return min.ToString();
        }
    }
}