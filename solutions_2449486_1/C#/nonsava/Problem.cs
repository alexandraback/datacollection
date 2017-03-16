	using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;


namespace nonsava.GoogleCodeJamJapan2011
{
	class Problem
	{
		#region Main

		static string RESULTFILE = @"..\..\..\__out.txt";

		static void Main( string[] args )
		{
			if( 0 < args.Length ) {
				CASEFILE = args[0];
			} else if( 1 < args.Length ) {
				MAXTHREADS = int.Parse( args[1] );
			}

			DateTime startTime = DateTime.Now;

			int count;
			Problem[] testcases;

			using( TextReader reader = new StreamReader( CASEFILE ) ) {
				string line = reader.ReadLine();
				count = int.Parse( line );
				testcases = new Problem[count];

				for( int i = 0; i < count; i++ )
					testcases[i] = new Problem( reader );
			}

			Initialize();

			Thread[] threadPool = new Thread[MAXTHREADS];
			for( int t = 0; t < MAXTHREADS; t++ )
				threadPool[t] = null;

			for( int next = 0;; ) {
				if( count <= next ) {
					bool finished = true;
					for( int t = 0; t < MAXTHREADS; t++ )
						if( threadPool[t] != null && threadPool[t].IsAlive ) {
							finished = false;
							break;
						}
					if( finished )
						break;
				}

				for( int t = 0; t < MAXTHREADS; t++ ) {
					if( threadPool[t] != null && !threadPool[t].IsAlive )
						threadPool[t] = null;

					if( threadPool[t] == null && next < count ) {
						Console.WriteLine( "----------------------------------------------------- {0}/{1} ({2:F3}[sec])", next + 1, count, ( DateTime.Now - startTime ).TotalSeconds );
						testcases[next].WriteParams();

						threadPool[t] = new Thread( new ThreadStart( testcases[next++].Solv ) );
						threadPool[t].Start();
					}
				}

				Thread.Sleep( 100 );
			}

			Console.WriteLine( "\n#############################################################################\n" );
			using( TextWriter writer = new StreamWriter( RESULTFILE ) ) {
				for( int i = 0; i < count; i++ )
					testcases[i].WriteResult( writer, i + 1 );
			}

			TimeSpan span = DateTime.Now - startTime;
			Console.WriteLine( "\n#############################################################################\n" );
			Console.WriteLine( "{0:F3}[sec] = {1:F3}[min]", span.TotalSeconds, span.TotalMinutes );
			if( BEEP )
				Console.Beep( 1000, 5000 );
			Console.ReadKey();
		}


		string Result;

		private void WriteResult( TextWriter writer, int number )
		{
			writer.WriteLine( "Case #{0}: {1}", number, Result );
			Console.WriteLine( "Case #{0}: {1}", number, Result );
		}

		#endregion


		////////////////////////////////
		long N;
		long M;
		long[,] A;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			N = long.Parse( strs[0] );
			M = long.Parse( strs[1] );
			A = new long[M, N];

			for( int i = 0; i < N; i++ ) {
				line = reader.ReadLine();
				strs = line.Split( new char[] { ' ' } );
				for (int j = 0; j < M; j++) {
					A[j, i] = long.Parse(strs[j]);
				}
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1}", N, M );
			for( int i = 0; i < N; i++ ) {
				for( int j = 0; j < M; j++ )
					Console.Write( " {0}", A[j,i] );
				Console.WriteLine();
			}
			Console.WriteLine();
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 1;
		static bool BEEP = false;

//		static string CASEFILE = @"..\..\..\A-small-practice.in";
//		static string CASEFILE = @"..\..\..\A-large-practice.in";

//		static string CASEFILE = @"..\..\..\B-small-attempt0.in";
		static string CASEFILE = @"..\..\..\B-large.in";

//		static string CASEFILE = @"..\..\..\C-small-practice.in";
//		static string CASEFILE = @"..\..\..\C-large-practice.in";

//		static string CASEFILE = @"..\..\..\D-small-practice.in";
//		static string CASEFILE = @"..\..\..\D-large-practice.in";

//		static string CASEFILE = @"..\..\..\__in_sample.txt";
//		static string CASEFILE = @"..\..\..\__in_large.txt";
		////////////////////////////////



		private bool check_column(int xx, int yy) {
			for (int y = 0; y < N; y++) {
				if (y != yy) {
					if(A[xx,yy] < A[xx,y])
						return false;
				}
			}
			return true;
		}


		private void Solv()
		{
			////////////////////////////////
			bool result = true;

			for(int y = 0; y < N; y++) {
				long hh = 0;
				for(int x = 0; x < M; x++) {
					if(A[x, y] > hh) {
						hh = A[x,y];
					}
				}
				
				for(int x = 0; x < M; x++) {
					if(A[x, y] < hh) {
						if(!check_column(x,y)) {
							result = false;
							break;
						}
					}
				}
				if(!result) {
					break;
				}				
			}

			Result = result? "YES": "NO";
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
