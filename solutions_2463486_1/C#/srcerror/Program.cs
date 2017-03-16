using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BaseApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\Current\CodeJam\1\C-large-1.in";
            string output = @"d:\Work\Current\CodeJam\1\C-large-1.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task3(sin);
                        sout.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
        }

        private static List<BigInteger> _allp;
        private static List<BigInteger> T3All {
            get
            {
                if (_allp == null)
                {
                    _allp = AllSquarePalindromes().OrderBy(t => t).ToList();
                }
                return _allp;
            }
        }
        private static string Task3(StreamReader sin)
        {
            string result = "";
            //var x = NumberOfPalindroms().Take(50);

            var nm = sin.ReadLine().Split(' ');
            var N = BigInteger.Parse(nm[0]);
            var M = BigInteger.Parse(nm[1]);
            var x = T3All;

            var r = x.SkipWhile(t => t < N).TakeWhile(t => t <= M).Count();
            return r.ToString();
        }

        private static IEnumerable<long> NumberOfPalindroms()
        {
            int length = 1;
            yield return 3;

            while (true)
            {
                length++;
                
                if (length%2 == 0)
                {
                    //even
                    long count = 0;
                    long k = (length - 2)/2;
                    // 11
                    count += 1;
                    // 121
                    // 212
                    // 22
                    count += 1;
                    // 11211
                    // 111
                    // 1111
                    count += k;
                    // 11111
                    // 111111
                    if (length >= 6)
                        count += (k)*(k - 1)/2;
                    // 1111111
                    // 11111111
                    if (length >= 8)
                        count += (k)*(k - 1)*(k - 2)/6;
                    // 111111111

                    yield return count;
                }
                else
                {
                    //odd
                    long count = 0;
                    long k = (length - 3)/2;
                    // 11
                    count += 1;
                    // 121
                    count += 1;
                    // 202
                    count += 1;
                    // 212
                    count += 1;
                    // 11211
                    if (length >= 5)
                        count += k;
                    // 111
                    count += 1;
                    // 11011
                    if (length >= 5)
                        count += k;
                    // 11111
                    if (length >= 5)
                        count += k;
                    // 1110111
                    if (length >= 7)
                        count += (k) * (k - 1) / 2;
                    // 1111111
                    if (length >= 7)
                        count += (k) * (k - 1) / 2;
                    // 111101111
                    if (length >= 9)
                        count += (k) * (k - 1) * (k - 2) / 6;
                    // 111111111
                    if (length >= 9)
                        count += (k) * (k - 1) * (k - 2) / 6;

                    yield return count;
                }
            }
        }
        private static IEnumerable<BigInteger> AllSquarePalindromes()
        {
            int i = 1;
            while (i <= 110)
            {
                foreach (var pal in SquarePalindroms(i))
                {
                    yield return pal;
                }
                i++;
            }
        }
        private static IEnumerable<BigInteger> SquarePalindroms(int length)
        {
            if (length % 2 == 0) yield break;
            
            int L = (length + 1)/2;
            if (L == 1)
            {
                yield return 1*1;
                yield return 2*2;
                yield return 3*3;
                yield break;
            }

            var sb = new StringBuilder();
            BigInteger b;
            if (L % 2 == 0)
            {
                //even
                // 11
                sb = new StringBuilder();
                sb.AppendFormat("1{0}1", new string('0', L - 2));
                string oneZero = sb.ToString();
                b = BigInteger.Parse(oneZero);
                yield return b*b;
                // 121
                // 22
                sb.Clear();
                sb.AppendFormat("2{0}2", new string('0', L - 2));
                string twoZero = sb.ToString();
                b = BigInteger.Parse(twoZero);
                yield return b * b;
                // 212
                // 11211
                // 111
                // 1111
                // sb is 100..001
                for (int i = 1; i <= (L-2)/2; i++)
                {
                    sb.Clear();
                    sb.Append(oneZero);
                    sb[i] = '1';
                    sb[L - 1 - i] = '1';
                    b = BigInteger.Parse(sb.ToString());
                    yield return b * b;
                }

                // 11111
                // 111111
                if (length >= 6)
                {
                    for (int i = 1; i < (L-2)/2; i++)
                    {
                        for (int j = i + 1; j <= (L - 2) / 2; j++)
                        {
                            sb.Clear();
                            sb.Append(oneZero);
                            sb[i] = '1';
                            sb[L - 1 - i] = '1';
                            sb[j] = '1';
                            sb[L - 1 - j] = '1';
                            b = BigInteger.Parse(sb.ToString());
                            yield return b * b;
                        }
                    }
                    
                }
                // 1111111
                // 11111111
                if (length >= 8)
                {
                    for (int i = 1; i < ((L - 2) / 2) - 1; i++)
                    {
                        for (int j = i + 1; j < (L - 2) / 2; j++)
                        {
                            for (int k = j + 1; k <= (L - 2) / 2; k++)
                            {
                                sb.Clear();
                                sb.Append(oneZero);
                                sb[i] = '1';
                                sb[L - 1 - i] = '1';
                                sb[j] = '1';
                                sb[L - 1 - j] = '1';
                                sb[k] = '1';
                                sb[L - 1 - k] = '1';
                                b = BigInteger.Parse(sb.ToString());
                                yield return b * b;                                
                            }
                        }
                    }

                }
                // 111111111
            }
            else
            {
                //odd
                sb = new StringBuilder();
                string oneZeroOne = string.Format("1{0}1{0}1", new string('0', (L - 3) / 2));
                string oneZeroTwo = string.Format("1{0}2{0}1", new string('0', (L - 3) / 2));
                string oneZero =    string.Format("1{0}0{0}1", new string('0', (L - 3) / 2));
                string twoZeroOne = string.Format("2{0}1{0}2", new string('0', (L - 3) / 2));
                string twoZero =    string.Format("2{0}0{0}2", new string('0', (L - 3) / 2));

                // 11
                b = BigInteger.Parse(oneZero);
                yield return b * b;                
                // 121
                b = BigInteger.Parse(oneZeroTwo);
                yield return b * b; 
                // 212
                b = BigInteger.Parse(twoZeroOne);
                yield return b * b; 
                // 202
                b = BigInteger.Parse(twoZero);
                yield return b * b; 
                // 111
                b = BigInteger.Parse(oneZeroOne);
                yield return b * b;
                // 11011
                // 11111
                // 11211
                if (length >= 5)
                {
                    for (int i = 1; i <= (L - 3) / 2; i++)
                    {
                        sb.Clear();
                        sb.Append(oneZero);
                        sb[i] = '1';
                        sb[L - 1 - i] = '1';
                        b = BigInteger.Parse(sb.ToString());
                        yield return b * b;

                        sb.Clear();
                        sb.Append(oneZeroOne);
                        sb[i] = '1';
                        sb[L - 1 - i] = '1';
                        b = BigInteger.Parse(sb.ToString());
                        yield return b * b;

                        sb.Clear();
                        sb.Append(oneZeroTwo);
                        sb[i] = '1';
                        sb[L - 1 - i] = '1';
                        b = BigInteger.Parse(sb.ToString());
                        yield return b * b;
                    }
                }                
                // 1110111
                // 1111111
                if (length >= 7)
                {
                    for (int i = 1; i < (L - 3) / 2; i++)
                    {
                        for (int j = i + 1; j <= (L - 3) / 2; j++)
                        {
                            sb.Clear();
                            sb.Append(oneZero);
                            sb[i] = '1';
                            sb[L - 1 - i] = '1';
                            sb[j] = '1';
                            sb[L - 1 - j] = '1';
                            b = BigInteger.Parse(sb.ToString());
                            yield return b * b;

                            sb.Clear();
                            sb.Append(oneZeroOne);
                            sb[i] = '1';
                            sb[L - 1 - i] = '1';
                            sb[j] = '1';
                            sb[L - 1 - j] = '1';
                            b = BigInteger.Parse(sb.ToString());
                            yield return b * b;
                        }
                    }

                }
                // 111101111
                // 111111111
                if (length >= 9)
                {
                    for (int i = 1; i < ((L - 3) / 2) - 1; i++)
                    {
                        for (int j = i + 1; j < (L - 3) / 2; j++)
                        {
                            for (int k = j + 1; k <= (L - 3) / 2; k++)
                            {
                                sb.Clear();
                                sb.Append(oneZero);
                                sb[i] = '1';
                                sb[L - 1 - i] = '1';
                                sb[j] = '1';
                                sb[L - 1 - j] = '1';
                                sb[k] = '1';
                                sb[L - 1 - k] = '1';
                                b = BigInteger.Parse(sb.ToString());
                                yield return b * b;

                                sb.Clear();
                                sb.Append(oneZeroOne);
                                sb[i] = '1';
                                sb[L - 1 - i] = '1';
                                sb[j] = '1';
                                sb[L - 1 - j] = '1';
                                sb[k] = '1';
                                sb[L - 1 - k] = '1';
                                b = BigInteger.Parse(sb.ToString());
                                yield return b * b;
                            }
                        }
                    }

                }
            }

        }

        private static string Task2(StreamReader sin)
        {
            string result = "";
            var s = sin.ReadLine();
            var mn = s.Split(' ');
            int N = int.Parse(mn[0]);
            int M = int.Parse(mn[1]);
            int [,] inp = new int[N,M];

            for (int i = 0; i < N; i++)
            {
                var l = sin.ReadLine().Split(' ');
                for (int j = 0; j < M; j++)
                {
                    inp[i, j] = int.Parse(l[j]);
                }
            }

            // check every cell
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    // check [i,j]
                    bool safe = T2CheckVertical(inp, i, j);
                    if (safe) continue;
                    safe = T2CheckHorizontal(inp, i, j);
                    if (!safe) return "NO";
                }
            }

            result = "YES";
            return result;
        }
        private static bool T2CheckVertical(int[,] inp, int i, int j)
        {
            var val = inp[i, j];
            int N = inp.GetUpperBound(0);
            for (int k = 0; k <= N; k++)
            {
                if (val < inp[k, j]) return false;
            }
            return true;
        }
        private static bool T2CheckHorizontal(int[,] inp, int i, int j)
        {
            var val = inp[i, j];
            int M = inp.GetUpperBound(1);
            for (int k = 0; k <= M; k++)
            {
                if (val < inp[i, k]) return false;
            }
            return true;
        }

        private static string Task1(StreamReader sin)
        {
            var r1 = "X won";
            var r2 = "O won";
            var r3 = "Draw";
            var r4 = "Game has not completed";

            string inp;
            var sb = new StringBuilder();
            for (int i = 0; i < 4; i++)
            {
                sb.Append(sin.ReadLine().Substring(0, 4));
            }
            inp = sb.ToString();
            //Console.WriteLine(inp);
            sin.ReadLine();

            // process
            // find winner
            bool hasEmpty = false;
            var combos = new[]
                {
                    new[] { 0, 1, 2, 3 },
                    new[] { 4, 5, 6, 7 },
                    new[] { 8, 9, 10, 11 },
                    new[] { 12, 13, 14, 15 },
                    new[] { 0, 4, 8, 12 },
                    new[] { 1, 5, 9, 13 },
                    new[] { 2, 6, 10, 14 },
                    new[] { 3, 7, 11, 15 },
                    new[] { 0, 5, 10, 15 },
                    new[] { 3, 6, 9, 12 },
                };
            foreach (var combo in combos)
            {
                char? r = CheckCombo(inp, combo);
                if (r.HasValue)
                {
                    if (r == 'O')
                        return r2;
                    if (r == 'X')
                        return r1;
                }
            }
            // no winner
            if (inp.IndexOf('.') >= 0)
                return r4;
            else return r3;
        }
        private static char? CheckCombo(string inp, int[] p)
        {
            int i = 0;
            char x = inp[p[i++]];
            if (x == 'T')
            {
                x = inp[p[i++]];
            }

            while (true)
            {
                if (i > 3) return x;
                char cc = inp[p[i]];
                if (cc == '.') return null;
                if (cc != x && cc != 'T') return null;
                i++;
            }
        }
    }
}
