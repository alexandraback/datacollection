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
//		static string CASEFILE = @"..\..\..\__in_sample.txt";

		static string CASEFILE = @"..\..\..\B-small-attempt4.in";
//		static string CASEFILE = @"..\..\..\B-large.in";

		static int MAXTHREADS = 8;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		long E;
		long R;
		long N;
		List<long> v = new List<long>();
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			E = long.Parse( strs[0] );
			R = long.Parse( strs[1] );
			N = long.Parse( strs[2] );

			line = reader.ReadLine();
			strs = line.Split( new char[] { ' ' } );
			for( int i = 0; i < N; i++ ) {
				v.Add(long.Parse(strs[i]));
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1} {2}", E, R, N );
			for( int i = 0; i < N; i++ )
				Console.Write( " {0}", v[i] );
			Console.WriteLine();
			////////////////////////////////
		}


		long ss = 0;

		void proc(int n, long e, long s)
		{
			if(n>=N) {
				if(s > ss)
					ss = s;
				return;
			}

			//// 最小投入
			//long ee = 0;
			//if(e+R > E) {
			//    ee = e - (E-R);
			//} else {
			//    ee = 1;
			//}
			//proc(n+1, e - ee + R, s + ee * v[n]);

			//// 最大投入
			//proc(n+1, R, s + e * v[n]);

			//long es;
			//if(e+R > E) {
			//    es = e - (E-R);
			//} else {
			//    es = 1;
			//}
			//for(long ee = es; ee<=e; ee++) {
			for(long ee = 0; ee<=e; ee++) {
				proc(n+1, Math.Min(E, e - ee + R), s + ee * v[n]);
			}
		}


		private void Solv()
		{
			////////////////////////////////
			proc(0, E, 0);

			Result = ss.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
