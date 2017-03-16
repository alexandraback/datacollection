using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Marius.CodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            using (var input = new StreamReader(@"..\..\input.txt"))
            using (var output = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(input.ReadLine());
                for (var currentCase = 1; currentCase <= caseCount; currentCase++)
                {
                    var result = "RICHARD";
                    var parts = input.ReadLine().Split().Select(s => int.Parse(s)).ToArray();

                    var X = parts[0];
                    var R = parts[1];
                    var C = parts[2];

                    if (R > C)
                    {
                        R = parts[2];
                        C = parts[1];
                    }

                    if (X == 1)
                    {
                        result = "GABRIEL";
                    }
                    else if ((R * C) % X == 0)
                    {
                        switch (X)
                        {
                            case 2:
                                result = "GABRIEL";
                                break;
                            case 3:
                                if (R > 1 && C > 1) 
                                    result = "GABRIEL";
                                break;
                            case 4:
                                if (R > 2 && C > 2)
                                    result = "GABRIEL";
                                break;
                            case 5:
                            case 6:
                                break;
                        }
                    }

                    output.WriteLine("Case #{0}: {1}", currentCase, result);
                }
            }
        }

        private static string[] _names = new[] { "\0", "1", "i", "j", "k" };

        private static int[][] _table = new int[][]
        {
            //      1   i   j   k
            new[] { 1,  2,  3,  4 }, // 1
            new[] { 2, -1,  4, -3 }, // i
            new[] { 3, -4, -1,  2 }, // j
            new[] { 4,  3, -2, -1 }  // k
        };

        private static int Product(int left, int right)
        {
            var sign = 1;
            if (left < 0)
            {
                left = -left;
                sign = sign * -1;
            }

            if (right < 0)
            {
                right = -right;
                sign = sign * -1;
            }

            return sign * _table[left - 1][right - 1];
        }

        private static int ToQuat(char c)
        {
            switch (c)
            {
                case 'i':
                    return 2;
                case 'j':
                    return 3;
                case 'k':
                    return 4;
            }

            throw new ArgumentOutOfRangeException();
        }

        public class ReverseComparer : IComparer<int>
        {
            public int Compare(int x, int y)
            {
                return y - x;
            }
        }
    }
}
