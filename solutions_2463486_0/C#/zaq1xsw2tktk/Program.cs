using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
namespace GCJ
{
    class Program
    {

        class Solver
        {
            List<BigInteger> res = new List<BigInteger>();
            BigInteger tobig(string s)
            {
                BigInteger R = BigInteger.Zero;
                for (int i = 0; i < s.Length; i++)
                {
                    R = R * 10 + s[i] - '0';
                }
                return R;
            }
            bool check(string s)
            {
                int[] p = new int[100];
                for (int i = 0; i < s.Length; i++) for (int j = 0; j < s.Length; j++)
                    {
                        p[i + j] += (s[i] - '0') * (s[j] - '0');
                    }
                for (int i = 0; i < 50; i++) if (p[i] >= 10) return false;
                return true;

            }
            void solve(string s)
            {
                BigInteger n = tobig(s);
                if (s.Length == 10) return;
                int[] p = new int[50];
                for (int i = 0; i < s.Length; i++) for (int j = 0; j < s.Length; j++)
                    {
                        p[i + j] += (s[i] - '0') * (s[j] - '0');
                    }
                for (int i = 0; i < 50; i++) if (p[i] >= 10) return;
                StringBuilder sb1 = new StringBuilder(), sb2 = new StringBuilder();
                for (int i = 0; i < s.Length; i++) sb1.Append(s[i]);
                for (int i = 0; i < s.Length; i++) sb2.Append(s[i]);
                for (int i = s.Length - 1; i >= 0; i--) sb1.Append(s[i]);
                for (int i = s.Length - 2; i >= 0; i--) sb2.Append(s[i]);
                if (check(sb1.ToString()))
                {
                    BigInteger b1 = tobig(sb1.ToString());
                    b1 = b1 * b1;
                    res.Add(b1);
                }
                if (check(sb2.ToString()))
                {
                    BigInteger b1 = tobig(sb2.ToString());
                    b1 = b1 * b1;
                    res.Add(b1);
                }
                solve(s + "0");
                solve(s+"1");
                solve(s + "2");
                solve(s + "3");


            }
            public void Solve()
            {
                solve("1");
                solve("2");
                solve("3");
            }
            public string Solve(MyIO io)
            {
                string a = io.NextString,b = io.NextString;
                BigInteger A = tobig(a), B = tobig(b);
                int cnt = 0;
                foreach (var x in res)
                {
                    if (x >= A && x <= B)
                    {
                        cnt++;
                    }
                }
                return cnt.ToString() + "\n";
            }
        }
        static void Main(string[] args)
        {
            MyIO io = new MyIO(new StreamReader("in.txt"));
            int caseCount = io.NextInt;
            Solver solve = new Solver();
            solve.Solve();
            for (int i = 0; i < caseCount; i++)
            {
                string res = solve.Solve(io);
                io.Write("Case #{0}: {1}", i + 1, res);
            }
            io.Flush();
        }
        class MyIO
        {
            TextReader reader;
            TextWriter writer = new StreamWriter("out.txt");
            string[] tokens;
            int pointer;
            public MyIO(TextReader rd)
            {
                reader = rd;
            }
            public string NextLine()
            {
                try
                {
                    return reader.ReadLine();
                }
                catch (IOException)
                {
                    return null;
                }
            }
            public string NextString
            {
                get
                {
                    try
                    {
                        while (tokens == null || pointer >= tokens.Length)
                        {
                            tokens = NextLine().Split(new char[] { ' ' }, System.StringSplitOptions.RemoveEmptyEntries);
                            pointer = 0;
                        }
                        return tokens[pointer++];
                    }
                    catch (IOException)
                    {
                        return null;
                    }
                }
            }
            public int NextInt
            {
                get { return int.Parse(NextString); }
            }
            public long NextLong
            {
                get { return long.Parse(NextString); }
            }
            public double NextDouble
            {
                get { return double.Parse(NextString); }
            }
            public bool Write(string format, params object[] args)
            {
                writer.Write(format, args);
                return true;
            }
            public void WriteLine(string format, params object[] args)
            {
                writer.WriteLine(format, args);
            }
            public void WriteLine(object obj)
            {
                writer.WriteLine("{0}", obj);
            }
            public void WriteLine()
            {
                writer.WriteLine();
            }
            public void Write(object obj)
            {
                writer.Write("{0}", obj);
            }
            public void Flush()
            {
                writer.Flush();
            }
        }
    }
}
