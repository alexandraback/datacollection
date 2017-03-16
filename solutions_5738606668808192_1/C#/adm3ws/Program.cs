using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

namespace GCJ
{
    class P
    {
        public int EC = 0;
        public int FC = 0;
    }

    class Program
    {
        static List<List<int>> t = new List<List<int>>();
        static List<P> p = new List<P>();
        static int SC = 0;

        static int solve (int ind)
        {
            if(ind == t.Count)
            {
                return SC;
            }
            foreach(var i in t[ind])
            {
                p[i].EC++;
                if(p[i].EC == 1 && p[i].FC > 0)
                {
                    SC++;
                }
            }
            var res1 = solve(ind + 1);
            foreach(var i in t[ind])
            {
                p[i].EC--;
                if(p[i].EC == 0 && p[i].FC > 0)
                {
                    SC--;
                }
            }


            foreach(var i in t[ind])
            {
                p[i].FC++;
                if(p[i].FC == 1 && p[i].EC > 0)
                {
                    SC++;
                }
            }
            var res2 = solve(ind + 1);
                        foreach(var i in t[ind])
            {
                p[i].FC--;
                if(p[i].FC == 0 && p[i].EC > 0)
                {
                    SC--;
                }
            }
            return Math.Min(res1, res2);
        }

        public static Random r = new Random();

        // http://stackoverflow.com/questions/7860802/miller-rabin-primality-test
        public static bool IsPrime(long n, long k)
        {
            if (n < 2)
            {
                return false;
            }
            if (n != 2 && n % 2 == 0)
            {
                return false;
            }
            long s = n - 1;
            while (s % 2 == 0)
            {
                s >>= 1;
            }
            
            for (long i = 0; i < k; i++)
            {
                var a = r.Next((int)n - 1) + 1;
                long temp = s;
                long mod = ModuloPower(a, temp, n);
                while (temp != n - 1 && mod != 1 && mod != n - 1)
                {
                    mod = (mod * mod) % n;
                    temp = temp * 2;
                }
                if (mod != n - 1 && temp % 2 == 0)
                {
                    return false;
                }
            }
            return true;
        }

        static long ModuloPower(long a, long b, long n)
        {
            long res = 1;
            for (long i = 0; i < b; ++i)
                res = (res * a) % n;
            return res;
        }

        // http://stackoverflow.com/questions/7991463/what-is-the-best-most-performant-algorithm-to-find-all-primes-up-to-a-given-num
        public static List<long> GeneratePrimes(long n)
        {
            var primes = new List<long>();
            for (var i = 2; i <= n; i++)
            {
                var ok = true;
                foreach (var prime in primes)
                {
                    if (prime * prime > i)
                        break;
                    if (i % prime == 0)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    primes.Add(i);
            }
            return primes;
        }

        static void Main(string[] args)
        {
            var root = @"C:\projects\comp\gcj\p3\";

            StreamWriter output = new StreamWriter(root + "out.txt");
            output.WriteLine("Case #1:");
            Console.WriteLine("Case #1:");

            int BC = 32;
            List<long> primes = GeneratePrimes(10L * (long) Math.Sqrt(1L << (BC)));
            Console.WriteLine("There are {0} primes...", primes.Count);
            long[] vals = new long[11];
            long[] divs = new long[11];
            int numFound = 0;
            for(long i = 0; i < (1L << (BC-2)); ++i)
            {
                long n = (1L << (BC-1)) + (i << 1) + 1;

                bool allPrime = true;
                for(int b = 2; b <= 10; ++b)
                {
                    long val = 0;
                    for(int j = 0; j < BC; ++j)
                    {
                        if(((1L << j) & n) > 0)
                        {
                            val += (long)Math.Pow(b, j);
                        }
                    }
                    vals[b] = val;
                    /*if(!IsPrime(val, 3))
                    {
                        if (i % 1000 == 0)
                        {
                            Console.WriteLine("{0} is not prime {1}", b, val);
                        }
                        allPrime = false;
                        break;
                    }*/
                }

                if(allPrime)
                {
                    for (int b = 2; b <= 10; ++b)
                    {
                        var val = vals[b];
                        bool found = false;
                        foreach(var p in primes)
                        {
                            if(val % p == 0)
                            {
                                divs[b] = p;
                                found = true;
                                break;
                            }
                        }

                        if(!found)
                        {
                            //Console.WriteLine("BUGBUG: {0} {1} {2}", n, val, b);
                            allPrime = false;
                            break;
                        }
                    }


                    if(allPrime)
                    {
                        for (int bit = 0; bit < BC; ++bit)
                        {
                            if ((n & (1L << (BC - bit - 1))) > 0)
                            {
                                output.Write("1");
                                Console.Write("1");
                            }
                            else
                            {
                                output.Write("0");
                                Console.Write("0");
                            }
                        }
                        for (int b = 2; b <= 10; ++b)
                        {
                            //Console.Write(vals[b] + " " + divs[b] + " ");
                            Console.Write(" " + divs[b]);
                            output.Write(" " + divs[b]);
                        }
                        Console.Write("\n");
                        output.Write("\n");
                        numFound++;
                        if(numFound == 500)
                        {
                            break;
                        }
                    }
                }

            }

            output.Close();
            return;
            /*
            System.Threading.Thread.Sleep(1000000);

                
            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long numCases = long.Parse(input[0]);
            long lineNum = 0;

            for(long nc = 0; nc < numCases; ++nc)
            {
                lineNum++;
                long N = long.Parse(input[lineNum]);
                int nt = 0;
                Dictionary<string ,int> map = new Dictionary<string,int>();
                List<string[]> tokens = new List<string[]>();
                t.Clear();
                for(int i = 0; i < N; ++i)
                {
                    lineNum++;
                    string[] s = input[lineNum].Trim().Split(' ');
                    tokens.Add(s);
                    t.Add(new List<int>());
                    foreach(var ss in s)
                    {
                        if(!map.ContainsKey(ss))
                        {
                            map.Add(ss, nt);
                            nt++;
                        }
                        t.Last().Add(map[ss]);
                    }
                }

                p.Clear();
                for(int i = 0; i < nt; ++i)
                {
                    p.Add(new P());
                }
                SC = 0;

                for(int i = 0; i < 2; ++i)
                {
                    for(int j = 0; j < t[i].Count; ++j)
                    {
                        if(i == 0)
                        {
                            p[t[i][j]].EC++;
                        }
                        else
                        {
                            p[t[i][j]].FC++;
                            if(p[t[i][j]].EC > 0)
                            {
                                SC++;
                            }
                        }
                    }
                }

                int res = solve(2);
                output.WriteLine("Case #{0}: {1}", nc + 1, res);
                Console.WriteLine("Case #{0}: {1}", nc + 1, res);
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }*/
        }
    }
}
