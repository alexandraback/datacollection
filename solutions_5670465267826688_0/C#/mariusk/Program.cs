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
                    var parts = input.ReadLine().Split().Select(s => long.Parse(s)).ToArray();
                    var L = parts[0];
                    var X = parts[1];

                    var data = input.ReadLine().Trim();
                    var max = 8L;
                    if (max > X)
                        max = X;

                    max = max * L;

                    var iset = new SortedSet<long>();
                    var kset = new SortedSet<long>();

                    var cycle = 0L;
                    var prod = 1;
                    var arr = new int[max];
                    var index = 0;
                    for (var i = 0L; i < max; i++)
                    {
                        prod = Product(prod, ToQuat(data[index]));
                        arr[i] = prod;

                        if (prod == 2)
                            iset.Add(i);

                        if (prod == 4)
                            kset.Add(i);

                        index++;
                        if (index == data.Length)
                        {
                            if (cycle == 0 && prod == 1)
                            {
                                cycle = i + 1;
                                break;
                            }
                            index = 0;
                        }
                    }

                    var result = "NO";
                    if (cycle == 0)
                    {
                        if (arr[arr.Length - 1] == -1)
                        {
                            foreach (var iindex in iset)
                                foreach (var kindex in kset)
                                {
                                    if (kindex > iindex)
                                    {
                                        result = "YES";
                                        break;
                                    }
                                }
                        }
                    }
                    else
                    {
                        var total = X * L;
                        var rem = (total % cycle) - 1;
                        if (rem < 0)
                            rem = cycle - 1;
                        var f1 = arr[rem];

                        if (f1 == -1)
                        {
                            foreach (var iindex in iset)
                            {
                                foreach (var kindex in kset)
                                {
                                    if (kindex < iindex)
                                    {
                                        // ..., k, ..., i, ...
                                        if (kindex < rem)
                                        {
                                            result = "YES";
                                            break;
                                        }
                                        else if (cycle + kindex < total)
                                        {
                                            result = "YES";
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        result = "YES";
                                        break;
                                    }
                                }
                            }
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
