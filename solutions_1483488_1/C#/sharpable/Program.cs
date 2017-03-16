using System;
using System.Collections.Generic;
using System.Text;

namespace Problem_C
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Run();
        }

        private void Run()
        {
            int cases = int.Parse(Console.ReadLine());
            for (int c = 1; c <= cases; c++)
            {
                string[] caseRecord = Console.ReadLine().Split(' ');

                int a = int.Parse(caseRecord[0]);
                int b = int.Parse(caseRecord[1]);

                int result = ProcessCase(a, b);

                Console.WriteLine(String.Format("Case #{0}: {1}", c, result));
            }
        }

        SortedSet<int> Recycled = new SortedSet<int>();

        private int ProcessCase(int a, int b)
        {
            int total = 0;

            int length = b.ToString().Length;

            int lower = (int) Math.Pow(10, length - 1);
            if (lower > a)
            {
                a = lower;
            }

            while (a < b)
            {
                for (int c = 1; c < length; c++)
                {
                    CalculateRecycled(a, b, c);
                }

                total += Recycled.Count;
                Recycled.Clear();
                a++;
            }

            return total;
        }

        private void CalculateRecycled(int a, int b, int c)
        {

            string _a = a.ToString();
            string _r = _a.Substring(c) + _a.Substring(0, c);
            int r = int.Parse(_r);

            if (r > a && r <= b)
            {
                if (!Recycled.Contains(r))
                {
                    Recycled.Add(r);
                }
            }
        }

    }
}
