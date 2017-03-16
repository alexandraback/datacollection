using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int CN = int.Parse(Console.ReadLine());
            for (int cn = 1; cn <= CN; cn++)
            {
                int A, B;
                double[] pA = new double[100000];
                string[] line = Console.ReadLine().Split(' ');
                A = int.Parse(line[0]);
                B = int.Parse(line[1]);
                line = Console.ReadLine().Split(' ');
                for (int r = 0; r < A; r++)
                    pA[r] = double.Parse(line[r]);

                double En = B + 2;

                double PpA = 1;
                for (int r = 0; r < A; r++) PpA *= pA[r];
                double E1 = PpA * (B - A + 1) + (1.0 - PpA) * (B - A + 1 + B + 1);
                if(E1 < En) En = E1;

                E1 = (B - A + A * 2 + 1);
                if (E1 < En) En = E1;

                for (int n = 1; n < A; n++)
                {
                    PpA = 1;
                    for (int r = 0; r < A - n; r++) PpA *= pA[r];
                    E1 = PpA * (B - A + n * 2 + 1) + (1.0 - PpA) * (B - A + n * 2 + B + 2);
                    if (E1 < En) En = E1;
                }

                Console.WriteLine("Case #" + cn + ": " + En);
            }
        }
    }
}
