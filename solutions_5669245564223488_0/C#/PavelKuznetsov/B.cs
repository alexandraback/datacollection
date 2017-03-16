
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
		private const bool UseStandardIO = false;
		private const string InputFile = @"B-Small-attempt0.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2014 2C\B-Small.out";

		private int n;
		private string[] s;
		private int ans;

		private const int MOD = 1000000007;

		void ReadData()
		{
			n = NextInt();
			s = new string[n];
			for ( int i = 0; i < n; ++i ) s[i] = NextToken();
		}

		void Solve()
		{
			var p = PermutationUtils.First( n );
			int cnt = 0;
			do
			{
				bool ok = true;

				bool[] was = new bool[26];
				char last = '.';
				for ( int i = 0; ok && i < n; ++i )
				{
					for ( int j = 0; ok && j < s[p[i]].Length; ++j )
					{
						if ( s[p[i]][j] != last )
						{
							last = s[p[i]][j];
							if ( was[last - 'a'] )
							{
								ok = false;
							}
							was[last - 'a'] = true;
						}
					}
				}

				if (ok)
				{
					++cnt;
				}
			} while ( PermutationUtils.Next( p ) );
			ans = cnt;
		}

		void WriteAnswer()
		{
			Out.WriteLine( ( ans % MOD + MOD ) % MOD );
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
				_inputStream = File.OpenText( Path.Combine( Path.Combine( Environment.GetFolderPath( Environment.SpecialFolder.UserProfile ), "Downloads" ), InputFile ) );
				_outputStream = File.CreateText( Path.Combine( new FileInfo( GetType().Assembly.Location ).Directory.Parent.Parent.Parent.FullName, OutputFile ) );
			}

			int testsCount = int.Parse( _inputStream.ReadLine() );
			var solvers = new Solution[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new Solution();
				solvers[i].ReadData();
			}

			int done = 0;
			if ( UseMultiThreading )
			{
				solvers.AsParallel().WithDegreeOfParallelism( Math.Max( Environment.ProcessorCount, 2 ) ).ForAll(
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
			new Thread( new Solution().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}

namespace kp.Algo { }

namespace kp.Algo
{
	static class PermutationUtils
	{
		public static int[] First( int n )
		{
			int[] res = new int[n];
			for ( int i = 0; i < n; ++i ) res[i] = i;
			return res;
		}
		public static bool Next( int[] p )
		{
			if ( p.Length == 1 ) return false;
			int i = 0;
			++i;
			if ( i == p.Length ) return false;
			i = p.Length;
			--i;

			for ( ; ; )
			{
				int ii = i;
				--i;
				if ( p[i].CompareTo( p[ii] ) < 0 )
				{
					int j = p.Length;
					do
					{
						--j;
					} while ( p[i].CompareTo( p[j] ) >= 0 );
					int tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
					int l = ii, r = p.Length - 1;
					while ( l < r )
					{
						tmp = p[l];
						p[l] = p[r];
						p[r] = tmp;
						++l;
						--r;
					}
					return true;
				}
				if ( i == 0 )
				{
					int l = 0, r = p.Length - 1;
					while ( l < r )
					{
						int tmp = p[l];
						p[l] = p[r];
						p[r] = tmp;
						++l;
						--r;
					}
					return false;
				}
			}
		}
	}
}
