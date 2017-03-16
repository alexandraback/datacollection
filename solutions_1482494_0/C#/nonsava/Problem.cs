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
		int N;
		class S {
			public int a;
			public int b;
		}
		List<S> s = new List<S>();
//		int[] a;
//		int[] b;
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
			N = int.Parse( line );
//			a = new int[N];
//			b = new int[N];

			for( int i = 0; i < N; i++ ) {
				line = reader.ReadLine();
				string[] strs = line.Split( new char[] { ' ' } );
//				a[i] = int.Parse(strs[0]);
//				b[i] = int.Parse(strs[1]);
				S ss = new S();
				ss.a = int.Parse(strs[0]);
				ss.b = int.Parse(strs[1]);
				s.Add(ss);
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0}", N );
			for( int i = 0; i < N; i++ ) {
//				Console.WriteLine( " {0} {1}", a[i], b[i] );
				Console.WriteLine( " {0} {1}", s[i].a, s[i].b );
			}
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 1;
		static bool BEEP = false;

//		static string CASEFILE = @"..\..\..\B-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\B-small-attempt1.in";
		static string CASEFILE = @"..\..\..\B-small-attempt2.in";
//		static string CASEFILE = @"..\..\..\B-large.in";

//		static string CASEFILE = @"..\..\..\__in_sample.txt";
//		static string CASEFILE = @"..\..\..\__in_large.txt";
		////////////////////////////////



		private void Solv()
		{
			////////////////////////////////
			int stars = 0;
			int t = 0;

			s.Sort( delegate( S s1, S s2 ) { return s2.b.CompareTo( s1.b ); } );
			for( int i = 0; i < N; i++ ) {
				Console.WriteLine( "----- {0} {1}", s[i].a, s[i].b );
			}

			while( 0 < s.Count ) {
				bool found = false;
				for( int i = 0; i < s.Count; i++ ) {
					if( s[i].b <= stars ) {
						if( s[i].a == 999999999 ) stars += 1;
						else stars += 2;
						s.RemoveAt(i);
						t++;
						found = true;
						break;
					}
				}
				if( !found ) {
					for( int i = 0; i < s.Count; i++ ) {
						if( s[i].a <= stars ) {
							stars += 1;
							s[i].a = 999999999;
							t++;
							found = true;
							break;
						}
					}
					if( !found ) {
						t = -1;
						break;
					}
				}
			}

			Result = 0<=t? t.ToString(): "Too Bad";
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
