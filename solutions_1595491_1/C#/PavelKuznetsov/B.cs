using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemB
{
	class B
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\B-Large.in";
		private const string OutputFile = @"..\B-Large.out";

		private int n, s, p, res;
		private int[] a;

		void ReadData()
		{
			n = NextInt();
			s = NextInt();
			p = NextInt();
			a = new int[n];
			for ( int i = 0; i < n; ++i ) a[i] = NextInt();
		}

		private const int INF = 1000000;
		private int[,] dp;
		int go( int pos, int surprise )
		{
			if ( surprise < 0 ) return -INF;
			if ( pos == n ) return surprise == 0 ? 0 : -INF;
			if ( dp[pos, surprise] != -1 )
				return dp[pos, surprise];
			dp[pos, surprise] = -INF;
			for ( int i = 0; i <= 10; ++i )
				for ( int j = i; j <= 10 && j - i <= 2; ++j )
					for ( int k = j; k <= 10 && k - i <= 2; ++k )
					{
						if ( i + j + k == a[pos] )
						{
							bool isSurprise = k - i == 2 || k - j == 2 || j - i == 2;
							dp[pos, surprise] = Math.Max( dp[pos, surprise], ( k >= p ? 1 : 0 ) + go( pos + 1, surprise - ( isSurprise ? 1 : 0 ) ) );
						}
					}
			return dp[pos, surprise];
		}

		void Solve()
		{
			dp = new int[n, s + 1];
			for ( int i = 0; i < n; ++i )
				for ( int j = 0; j < s + 1; ++j )
					dp[i, j] = -1;
			res = go( 0, s );
		}

		void WriteAnswer()
		{
			Out.WriteLine( res );
		}

		#region ...

		void run()
		{
			if ( UseStandardIO )
			{
				_inputStream = Console.In;
				_outputStream = Console.Out;
			}
			else
			{
				_inputStream = File.OpenText( InputFile );
				_outputStream = File.CreateText( Path.Combine( new FileInfo( GetType().Assembly.Location ).Directory.Parent.Parent.Parent.FullName, OutputFile ) );
			}

			int testsCount = int.Parse( _inputStream.ReadLine() );
			var solvers = new B[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new B();
				solvers[i].ReadData();
			}

			int done = 0;
			if ( UseMultiThreading )
			{
				solvers.AsParallel().WithDegreeOfParallelism( Math.Max( Environment.ProcessorCount, 2 ) - 1 ).ForAll(
					solver => { solver.Solve(); Console.Title = ( ++done ).ToString() + " of " + testsCount; } );
			}
			else
			{
				for ( int i = 0; i < testsCount; ++i )
				{
					solvers[i].Solve();
					Console.Title = ( ++done ).ToString() + " of " + testsCount;
				}
			}
			for ( int i = 0; i < testsCount; ++i )
			{
				Out.Write( string.Format( "Case #{0}: ", i + 1 ) );
				solvers[i].WriteAnswer();
			}
			Out.Flush();
			if ( UseStandardIO )
			{
				Console.ReadLine();
			}
			else
			{
				Out.Close();
			}
		}

		static TextWriter Out { get { return _outputStream; } }

		private static TextReader _inputStream;
		private static TextWriter _outputStream;

		public BigInteger NextBigInteger()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return BigInteger.Parse( token );
		}

		public double NextDouble()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return double.Parse( token, CultureInfo.InvariantCulture );
		}

		public long NextLong()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return long.Parse( token );
		}

		public int NextInt()
		{
			var token = NextToken();
			if ( string.IsNullOrEmpty( token ) ) throw new ApplicationException( "Input data missing" );
			return int.Parse( token );
		}

		private static readonly Queue<string> Tokens = new Queue<string>();
		public string NextToken()
		{
			if ( Tokens.Count > 0 )
			{
				return Tokens.Dequeue();
			}
			while ( Tokens.Count == 0 )
			{
				var line = _inputStream.ReadLine();
				if ( line == null ) return null;
				foreach ( var token in line.Split( _whiteSpaces, StringSplitOptions.RemoveEmptyEntries ) )
				{
					Tokens.Enqueue( token );
				}
			}
			return Tokens.Count == 0 ? null : Tokens.Dequeue();
		}

		private readonly char[] _whiteSpaces = { ' ', '\r', '\n', '\t' };

		static void Main()
		{
			new Thread( new B().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}
