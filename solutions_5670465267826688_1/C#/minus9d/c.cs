using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace a
{
    class Quaternion
    {
        long sign;  // 1 or -1
        char state;

        public Quaternion()
        {
            this.state = '1';
            this.sign = 1;
        }
        public Quaternion(char ch, long s)
        {
            this.state = ch;
            this.sign = s;
        }

        private Tuple<char, long> MulTable(char ch1, char ch2)
        {
            if (ch1 == '1') return Tuple.Create(ch2, 1L);
            else if (ch1 == 'i')
            {
                var table = new Dictionary<char, Tuple<char, long>>
                {
                    {'1', Tuple.Create('i', 1L)},
                    {'i', Tuple.Create('1', -1L)},
                    {'j', Tuple.Create('k', 1L)},
                    {'k', Tuple.Create('j', -1L)}
                };
                return table[ch2];
            }
            else if (ch1 == 'j')
            {
                var table = new Dictionary<char, Tuple<char, long>>
                {
                    {'1', Tuple.Create('j', 1L)},
                    {'i', Tuple.Create('k', -1L)},
                    {'j', Tuple.Create('1', -1L)},
                    {'k', Tuple.Create('i', 1L)}
                };
                return table[ch2];
            }
            else
            {
                var table = new Dictionary<char, Tuple<char, long>>
                {
                    {'1', Tuple.Create('k', 1L)},
                    {'i', Tuple.Create('j', 1L)},
                    {'j', Tuple.Create('i', -1L)},
                    {'k', Tuple.Create('1', -1L)}
                };
                return table[ch2];
            }
        }

        public void mul(char ch)
        {
            var res = MulTable(this.state, ch);
            this.state = res.Item1;
            this.sign *= res.Item2;
        }

        public void mul_rev(char ch)
        {
            var res = MulTable(ch, this.state);
            this.state = res.Item1;
            this.sign *= res.Item2;
        }

        public Quaternion pow(long n)
        {
            long newsign;
            if (this.sign == 1) newsign = 1;
            else newsign = (n % 2 == 1) ? -1 : 1;

            if (this.state == '1')
            {
                return new Quaternion('1', newsign);
            }

            switch (n % 4)
	        {
                case 0:
                    return new Quaternion('1', newsign);
                case 1:
                    return new Quaternion(this.state, newsign);
                case 2:
                    return new Quaternion('1', -1 * newsign);
                default:
                    return new Quaternion(this.state, -1 * newsign);
	        }
        }

        public bool Same(Quaternion q)
        {
            return this.state == q.state && this.sign == q.sign;
        }

        public void print()
        {
            Console.WriteLine("{0}{1}", (this.sign == 1 ? "" : "-"), this.state);
        }
    }


    class Program
    {
        public static string Reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

        static void Main(string[] args)
        {
            new Program().Run();
        }

        void Run()
        {
            long T = long.Parse(Console.ReadLine());
            for (long t = 0; t < T; ++t)
            {
                Console.WriteLine("Case #{0}: {1}", t + 1, Solve());
            }
        }

        string Solve()
        {
            string[] stringArr = Console.ReadLine().Split(' ');
            long L = long.Parse(stringArr[0]);
            long X = long.Parse(stringArr[1]);

            string str = Console.ReadLine();

            // get value of string L*X
            Quaternion q = new Quaternion();
            foreach (var ch in str)
            {
                q.mul(ch);
                //q.print();
            }
            Quaternion all = q.pow(X);
            Quaternion shouldbe = new Quaternion('1', -1);
            if (!all.Same(shouldbe)) return "NO";

            // check if 'i' appears within first 16 repeat of string L
            Quaternion willGoI = new Quaternion();
            long lenI = 0;
            bool found = false;
            for (long rep = 0; rep < System.Math.Min(16,X) && !found; ++rep)
            {
                foreach (var ch in str)
                {
                    willGoI.mul(ch);
                    ++lenI;
                    if (willGoI.Same(new Quaternion('i', 1)))
                    {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) return "NO";

            // check if 'k' appears within last 16 repeat of string L
            found = false;
            var revStr = str.Reverse();
            Quaternion willGoK = new Quaternion();
            long lenK = 0;
            found = false;
            for (long rep = 0; rep < System.Math.Min(16, X) && !found; ++rep)
            {
                foreach (var ch in revStr)
                {
                    willGoK.mul_rev(ch);
                    ++lenK;
                    if (willGoK.Same(new Quaternion('k', 1)))
                    {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) return "NO";

            if (lenI + lenK < L * X) return "YES";
            else return "NO";
        }
    }
}
