using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;


namespace nonsava.gcj
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
		//static string CASEFILE = @"..\..\..\__in_sample.txt";

		static string CASEFILE = @"..\..\..\A-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\A-large.in";

		static int MAXTHREADS = 1;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		long N;
		string[] S;
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			N = long.Parse( line );
			S = new string[N];

			for( int i = 0; i < N; i++ ) {
				line = reader.ReadLine();
				S[i] = line;
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			for( int i = 0; i < N; i++ )
				Console.WriteLine( " {0}", S[i] );
			////////////////////////////////
		}



		private void Solv()
		{
			////////////////////////////////
			//List<List<int>> x = new List<List<int>>();
			bool ok = true;
			int q = 0;

			for(;;) {
				bool fin = false;
				for(int i = 0; i < N; i++) {
					if (S[i].Length == 0) {
						fin = true;
						break;
					}
				}
				if(fin)
					break;

				char c = S[0][0];
				int min = int.MaxValue;
				int max = int.MinValue;
				for(int i = 0; i < N; i++) {
					if (S[i].Length == 0) {
						fin = true;
						break;
					} else if (S[i][0] != c) {
						fin = true;
						ok = false;
						break;
					}

					int j = 1;
					for(;S[i].Length > j && S[i][j] == c;j++);
					
					if(j < min)
						min = j;
					if(j > max)
						max = j;
					
					S[i] = S[i].Substring(j);
				}
				if(fin)
					break;

				q += max-min;
			}
			for(int i = 0; i < N; i++) {
				if (S[i].Length != 0) {
					ok = false;
					break;
				}
			}

			Result = ok ? q.ToString(): "Fegla Won";
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
