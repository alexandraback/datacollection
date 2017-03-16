
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;
using kp.Algo;

namespace CodeJam
{
    class Solution
    {
        private const bool UseMultiThreading = false;
        private const bool IsTestingRun = false;
        private const string InputFile = @"C:\Users\kp\Downloads\C-Large.in";
        private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2016 Qual\C-large.out";

        int n, j;
        HashSet<string> nums;
        List<int> primes;

        void ReadData()
        {
            n = NextInt();
            j = NextInt();
        }

        void Solve()
        {
            primes = new List<int>();
            var isp = NumTheoryUtils.Sieve(1000000);
            for (int i = 2; i < isp.Length && primes.Count < 10; i++)
            {
                if (!isp[i] && i > 10)
                    primes.Add(i);
            }

            nums = new HashSet<string>();
            var divs = new int[11];
            var a = new int[n];
            a[0] = a[n - 1] = 1;
            var rnd = new Random(123);
            while (nums.Count < j)
            {
                for (int i = 1; i < n - 1; i++)
                {
                    a[i] = rnd.Next(2);
                }
                if (IsOk(a, ref divs))
                {
                    var s = "";
                    for (int i = 0; i < a.Length; i++)
                    {
                        s += a[i].ToString();
                    }
                    for (int i = 2; i < 11; ++i) s += " " + divs[i];
                    nums.Add(s);
                }
            }
        }

        bool IsOk(int[] a, ref int[] divs)
        {
            for (int d = 2; d < 11; d++)
            {
                int div = -1;
                foreach (var p in primes)
                {
                    int m = 0;
                    for (int i = 0; i < a.Length; i++)
                    {
                        m = (m * d + a[i]) % p;
                    }
                    if (m == 0)
                    {
                        div = p;
                        break;
                    }
                }
                if (div == -1)
                    return false;
                divs[d] = div;
            }
            return true;
        }

        void WriteAnswer()
        {
            Out.WriteLine();
            foreach (var s in nums)
            {
                Out.WriteLine(s);
            }
        }

        #region ...

        void run()
        {
            if (IsTestingRun)
            {
                _inputStream = File.OpenText("input.txt");
                _outputStream = Console.Out;
            }
            else
            {
                _inputStream = File.OpenText(Path.Combine(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), "Downloads"), InputFile));
                _outputStream = File.CreateText(Path.Combine(new FileInfo(GetType().Assembly.Location).Directory.Parent.Parent.Parent.FullName, OutputFile));
            }

            int testsCount = int.Parse(_inputStream.ReadLine());
            var solvers = new Solution[testsCount];
            for (int i = 0; i < testsCount; ++i)
            {
                solvers[i] = new Solution();
                solvers[i].ReadData();
            }

            int done = 0;
            if (UseMultiThreading)
            {
                solvers.AsParallel().WithDegreeOfParallelism(Math.Max(Environment.ProcessorCount, 2)).ForAll(
                    solver => { solver.Solve(); Console.Title = (++done).ToString() + " of " + testsCount; });
            }
            else
            {
                for (int i = 0; i < testsCount; ++i)
                {
                    solvers[i].Solve();
                    Console.Title = (++done).ToString() + " of " + testsCount;
                }
            }
            for (int i = 0; i < testsCount; ++i)
            {
                Out.Write(string.Format("Case #{0}: ", i + 1));
                solvers[i].WriteAnswer();
            }
            Out.Flush();
            Out.Close();
            if (IsTestingRun)
            {
                Console.WriteLine("ALL DONE!");
                Console.ReadLine();
            }
        }

        static TextWriter Out { get { return _outputStream; } }

        private static TextReader _inputStream;
        private static TextWriter _outputStream;

        public BigInteger NextBigInteger()
        {
            var token = NextToken();
            if (string.IsNullOrEmpty(token)) throw new ApplicationException("Input data missing");
            return BigInteger.Parse(token);
        }

        public double NextDouble()
        {
            var token = NextToken();
            if (string.IsNullOrEmpty(token)) throw new ApplicationException("Input data missing");
            return double.Parse(token, CultureInfo.InvariantCulture);
        }

        public long NextLong()
        {
            var token = NextToken();
            if (string.IsNullOrEmpty(token)) throw new ApplicationException("Input data missing");
            return long.Parse(token);
        }

        public int NextInt()
        {
            var token = NextToken();
            if (string.IsNullOrEmpty(token)) throw new ApplicationException("Input data missing");
            return int.Parse(token);
        }

        private static readonly Queue<string> Tokens = new Queue<string>();
        public string NextToken()
        {
            if (Tokens.Count > 0)
            {
                return Tokens.Dequeue();
            }
            while (Tokens.Count == 0)
            {
                var line = _inputStream.ReadLine();
                if (line == null) return null;
                foreach (var token in line.Split(_whiteSpaces, StringSplitOptions.RemoveEmptyEntries))
                {
                    Tokens.Enqueue(token);
                }
            }
            return Tokens.Count == 0 ? null : Tokens.Dequeue();
        }

        private readonly char[] _whiteSpaces = { ' ', '\r', '\n', '\t' };

        static void Main()
        {
            new Thread(new Solution().run, 64 * 1024 * 1024).Start();
        }

        #endregion
    }
}

namespace kp.Algo { }

namespace kp.Algo
{
	static class NumTheoryUtils
	{
		public static bool[] Sieve( int n )
		{
			bool[] res = new bool[n];
			if ( n > 0 ) res[0] = true;
			if ( n > 1 ) res[1] = true;
			for ( int i = 2; i * i < n; ++i )
				if ( !res[i] )
					for ( int j = i * i; j < n; j += i )
						res[j] = true;
			return res;
		}
	}
}
