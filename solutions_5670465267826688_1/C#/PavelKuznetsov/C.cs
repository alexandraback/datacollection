
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
		private const string InputFile = @"C:\Users\kp\Downloads\C-large.in";
		private const string OutputFile = @"D:\docs\Dropbox\Olymp\Sources\_submit\CodeJam 2015 Qual\C-Large.out";

		private int l;
		private string s;
		private long times;
		private bool ans;
		private int[,] mulTable;

		void ReadData()
		{
			l = NextInt();
			times = NextLong();
			s = NextToken();
		}

		void Solve()
		{
			ans = false;
			InitMulTable();

			int val = 3;
			for ( int i = 0; i < l; i++ )
			{
				val = mulTable[val, s[i] - 'i'];
			}

			int cnt = 1, cur = val;
			while ( cur != 3 )
			{
				cur = mulTable[cur, val];
				++cnt;
			}

			int leftTimes = ( times < 20 ? (int)times : 20 );
			while ( leftTimes < times && leftTimes % cnt != times % cnt )
			{
				++leftTimes;
			}

			var finalVal = 3;
			for ( int i = 0; i < leftTimes; i++ )
			{
				finalVal = mulTable[finalVal, val];
			}
			if ( mulTable[0, mulTable[1, 2]] != finalVal ) // val != i*j*k
				return;

			cur = s[0] - 'i';
			cnt = 1;
			int totalLen = l * leftTimes, p = 0;
			while ( cur != 0 && cnt < totalLen )
			{
				if ( ++p == l ) p = 0;
				cur = mulTable[cur, s[p] - 'i'];
				++cnt;
			}
			if ( cur != 0 )
				return;
			int minLeft = cnt;
			cur = s[l - 1] - 'i';
			cnt = 1;
			p = l - 1;
			while ( cur != 2 && cnt < totalLen )
			{
				if ( --p == -1 ) p = l - 1;
				cur = mulTable[s[p] - 'i', cur];
				++cnt;
			}
			if ( cur != 2 )
				return;

			if ( minLeft + cnt < totalLen )
				ans = true;
		}

		private void InitMulTable()
		{
			// i, j, k, 1, -i, -j, -k, -1
			mulTable = new int[8, 8];
			mulTable[0, 0] = 7; mulTable[0, 1] = 2; mulTable[0, 2] = 5; mulTable[0, 3] = 0;
			mulTable[1, 0] = 6; mulTable[1, 1] = 7; mulTable[1, 2] = 0; mulTable[1, 3] = 1;
			mulTable[2, 0] = 1; mulTable[2, 1] = 4; mulTable[2, 2] = 7; mulTable[2, 3] = 2;
			mulTable[3, 0] = 0; mulTable[3, 1] = 1; mulTable[3, 2] = 2; mulTable[3, 3] = 3;
			for ( int i = 0; i < 8; i++ )
			{
				for ( int j = 0; j < 8; j++ )
				{
					if ( i < 4 && j < 4 ) continue;
					if ( i >= 4 && j >= 4 )
					{
						mulTable[i, j] = mulTable[i - 4, j - 4];
					}
					else if ( i >= 4 )
					{
						mulTable[i, j] = ( mulTable[i - 4, j] + 4 ) % 8;
					}
					else
					{
						mulTable[i, j] = ( mulTable[i, j - 4] + 4 ) % 8;
					}
				}
			}
		}

		void WriteAnswer()
		{
			Out.WriteLine( ans ? "YES" : "NO" );
		}

		#region ...

		void run()
		{
			if ( IsTestingRun )
			{
				_inputStream = File.OpenText( "input.txt" );
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
			Out.Close();
			if ( IsTestingRun )
			{
				Console.WriteLine( "ALL DONE!" );
				Console.ReadLine();
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
