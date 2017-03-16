using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemC
{
	class C
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\kp\Downloads\C-small-attempt0.in";
		private const string OutputFile = @"..\C-Small.out";

		private int n;
		private int[] a;
		private List<int> first, second;

		void ReadData()
		{
			n = NextInt();
			a = new int[n];
			for ( int i = 0; i < n; ++i ) a[i] = NextInt();
		}

		private Dictionary<int, int> h;

		void go( int p, int sum, int mask )
		{
			if ( p == n )
			{
				if ( sum > 0 )
				{
					if ( h.ContainsKey( sum ) )
					{
						first = new List<int>();
						for ( int i = 0; i < n; ++i )
							if ( ( mask & ( 1 << i ) ) != 0 ) first.Add( a[i] );
						mask = h[sum];
						second = new List<int>();
						for ( int i = 0; i < n; ++i )
							if ( ( mask & ( 1 << i ) ) != 0 ) second.Add( a[i] );
					}
					else
					{
						h.Add( sum, mask );
					}
				}
				return;
			}
			go( p + 1, sum, mask );
			if ( first != null ) return;
			go( p + 1, sum + a[p], mask | ( 1 << p ) );
		}

		void Solve()
		{
			h = new Dictionary<int, int>();
			go( 0, 0, 0 );
		}

		void WriteAnswer()
		{
			if ( first == null )
			{
				Out.WriteLine( "Impossible" );
			}
			else
			{
				for ( int i = 0; i < first.Count; ++i )
				{
					if ( i > 0 ) Out.Write( " " );
					Out.Write( first[i] );
				}
				Out.WriteLine();
				for ( int i = 0; i < second.Count; ++i )
				{
					if ( i > 0 ) Out.Write( " " );
					Out.Write( second[i] );
				}
				Out.WriteLine();
			}
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
			var solvers = new C[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new C();
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
				Out.WriteLine( string.Format( "Case #{0}:", i + 1 ) );
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
			new Thread( new C().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}
