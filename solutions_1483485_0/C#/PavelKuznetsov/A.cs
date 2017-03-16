using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemA
{
	internal class A
	{
		private const bool UseMultiThreading = false;
		private const bool UseStandardIO = false;
		private const string InputFile = @"C:\Users\Pavel Kuznetsov\Downloads\A-small-attempt0.in";
		private const string OutputFile = @"..\A-Large.out";

		private string[] sampleTexts = 
			{
				"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv",
			};
		private string[] sampleTextsTranslation = 
			{
				"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up",
			};

		private string text;
		private string res;

		void ReadData()
		{
			text = _inputStream.ReadLine();
		}

		void Solve()
		{
			var mapping = new char[26];
			for ( int i = 0; i < sampleTexts.Length; ++i )
				for ( int j = 0; j < sampleTexts[i].Length; ++j )
				{
					var ch = sampleTexts[i][j];
					var chTo = sampleTextsTranslation[i][j];
					if ( ch == ' ' )
					{
						if ( chTo != ' ' )
							throw new ApplicationException( "Wrong mapping" );
						continue;
					}
					ch -= 'a';
					if ( mapping[ch] != 0 && mapping[ch] != chTo )
						throw new ApplicationException( "Wrong mapping" );
					mapping[ch] = chTo;
				}
			mapping[16] = (char)( 'a' + 25 );
			mapping[25] = (char)( 'a' + 16 );

			foreach ( var c in text )
			{
				res += ( c == ' ' ? ' ' : mapping[c - 'a'] );
			}
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
			var solvers = new A[testsCount];
			for ( int i = 0; i < testsCount; ++i )
			{
				solvers[i] = new A();
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
			new Thread( new A().run, 64 * 1024 * 1024 ).Start();
		}

		#endregion
	}
}
