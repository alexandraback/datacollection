using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace CodeJam_2016_Q_3_C_Sharp
{
    class Program
    {
        private static String GenerateString(Int64 current, Int32 num)
        {
            var sb = new StringBuilder("1");
            while (current > 0) {
                Int64 b = current % 2;
                current = current / 2;
                sb.Append(b);
            }
            while (sb.Length < num - 1)
            {
                sb.Append("0");
            }
            sb.Append("1");
            return sb.ToString();
        }

        private static Int64 ParseNumber(String str, Int64 baseValue) {
            Int64 result = 0;
            Int64 mult = 1;
            for (Int32 i = str.Length - 1; i >= 0; i--) {
                Int64 v = Int64.Parse(str[i].ToString());
                result += v * mult;
                mult *= baseValue;
            }
            return result;
        }

        private static Int64 FindDivisor(Int64 num) {
            Int64 max = Math.Min((Int64)Math.Sqrt(num)+2, num-1);
            foreach (var d in divisors){
                if (d > max) return 0;
                if (num % d == 0) return d;
            }
            return 0;
        }

        private static String CheckString(String current)
        {
            var res = new List<Int64>();
            for (Int64 i = 2; i <= 10; i++) {
                Int64 div = FindDivisor(ParseNumber(current, i));
                if (div == 0) return null;
                res.Add(div);
            }
            return String.Join(" ", res.ToArray());
        }

        private static List<Int64> divisors = new List<Int64>();
        private static void FillDivisors()
        {
            divisors.Add(2);
            divisors.Add(3);
            for (Int64 i = 5; i<3333333333333333; i += 2){
                Boolean found = false;
                foreach(Int64 d in divisors)
                {
                    if (i%d == 0) { found = true; break; }
                }
                if (!found) divisors.Add(i);
                if (divisors.Count == 10000) return;
            }
        }



        private static String[] Solve(String str)
        {
            Int32[] v = str.Split(new char[] { ' ' }).Select(Int32.Parse).ToArray();
            Int32 n = v[0];
            Int32 j = v[1];

            List<String> results = new List<String>();
            Int64 current = 0;
            while (results.Count < j)
            {
                String s = GenerateString(current, n);
                String res = CheckString(s);
                if (res != null) results.Add(s + " " + res);
                current++;
            }

            return results.ToArray();
        }

        private static void Main(string[] args)
        {
            FillDivisors();
            string[] lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2016\Qualification\Task3_input\large.txt");
            Int32 count = Int32.Parse(lines[0].Trim());
            for (Int32 i = 0; i < count; i++)
            {
                Console.WriteLine("Case #{0}:", i + 1);
                String[] res = Solve(lines[i + 1]);
                foreach(String str in res)
                {
                    Console.WriteLine(str);
                }
            }
        }
    }

}
