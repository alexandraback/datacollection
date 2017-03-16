using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"C:\Users\Tyler\Desktop\GoogleCodeJam2012\ProblemC\Input\C-large.in";
            const string outputFile = @"C:\Users\Tyler\Desktop\GoogleCodeJam2012\ProblemC\Output\Large.txt";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for(int i=1; i<=testCases; i++)
            {
                var testCase = RecycledNumbers.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class RecycledNumbers
    {
        public int A { get; set; }
        public int B { get; set; }

        public int TotalDigits { get; set; }

        public List<int> Alist { get; set; }
        public List<int> Blist { get; set; }

        public static RecycledNumbers ParseCase(StreamReader sr)
        {
            var parameters =
                sr.ReadLine()
                .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                .Select(s => int.Parse(s));

            var a = parameters.First();
            var b = parameters.Last();

            return new RecycledNumbers {A = a, B = b};
        }

        public String SolveCase()
        {
            Alist = MakeList(A);
            Blist = MakeList(B);
            TotalDigits = Alist.Count();

            HashSet<String> recycled = new HashSet<string>();
            for(int i=1; i<TotalDigits; i++)
            {
                Solve(new List<int>(), i, recycled);
            }
            return recycled.Count.ToString();
        }

        List<int> MakeList(int number)
        {
            List<int> result = new List<int>();
            while (number > 0)
            {
                int next = number%10;
                result.Add(next);
                number /= 10;
            }
            result.Reverse();
            return result;
        }

        public void Solve(List<int> n, int mPosition, HashSet<String> recycled)
        {
            if(!CmpA(n) || !CmpB(n)) return;

            var m = ShiftList(n, mPosition);

            if (!CmpA(m) || !CmpB(m)) return;
            
            if (!CmpNM(n, m)) return;

            var digits = n.Count();
            if(digits == TotalDigits)
            {
                var key = String.Join("", n.Select(d => d.ToString())) + "-" + String.Join("", ShiftList(n, mPosition).Select(d => d.ToString()));
                recycled.Add(key);
                return;
            }

            for(int i=0; i<10; i++)
            {
                Solve(n.Concat(new List<int>(){i}).ToList(), mPosition, recycled);
            }
        }

        public int Compare(List<int> a, List<int> b)
        {
            int cnt = Math.Min(a.Count(), b.Count());
            for(int i=0; i<cnt; i++)
            {
                if (a[i] > b[i])
                    return 1;
                if (a[i] < b[i])
                    return -1;
            }
            return 0;
        }

        public bool CmpA(List<int> morn)
        {
            int cmp = Compare(morn, Alist);
            switch (cmp)
            {
                case 0:
                    return true;
                case 1:
                    return true;
                case -1:
                    return false;
                default:
                    throw new Exception("blam");
            }
        }

        public bool CmpB(List<int> morn)
        {
            int cmp = Compare(morn, Blist);
            switch (cmp)
            {
                case 0:
                    return true;
                case 1:
                    return false;
                case -1:
                    return true;
                default:
                    throw new Exception("blam");
            }
        }

        public bool CmpNM(List<int> n, List<int> m)
        {
            int cmp = Compare(n, m);
            switch (cmp)
            {
                case 0:
                    if (n.Count == TotalDigits) return false;
                    return true;
                case 1:
                    return false;
                case -1:
                    return true;
                default:
                    throw new Exception("blam");
            }
        }

        public List<int> ShiftList(List<int> n, int m)
        {
            List<int> result = new List<int>();
            for(int i=0; i<n.Count; i++)
            {
                int im = (i + m)%TotalDigits;
                if (n.Count <= im)
                    return result;
                result.Add(n[im]);
            }
            return result;
        }

    }
}
