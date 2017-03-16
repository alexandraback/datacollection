using System;
using System.IO;
using GCJ_base;

namespace GCJ_QD
{
    class Program
    {
        static void Main()
        {
            new GcjQD().Run();
        }
    }

    class GcjQD : Gcj
    {
        public GcjQD()
        {
            Problem = 'D';
            Small = false;
        }

        protected override string ComputeCase(TextReader reader)
        {
            var numbers = ReadIntLine(reader);

            int x = numbers[0];
            int r = numbers[1];
            int c = numbers[2];

            bool willWin = WillWin(r, c, x);

            if (willWin)
                return "GABRIEL";
            else
                return "RICHARD";
        }

        private static bool WillWin(int r, int c, int x)
        {
            if (x >= 7)
                return false;

            if ((r * c) % x != 0)
                return false;

            var smaller = r < c ? r : c;

            switch (x)
            {
            case 1:
                return true;
            case 2:
                return true;
            case 3:
                return smaller >= 2;
            case 4:
                return smaller >= 3;
            case 5:
                return smaller >= 4;
            case 6:
                return smaller >= 4;
            }

            throw new Exception("impossible");
        }
    }
}
