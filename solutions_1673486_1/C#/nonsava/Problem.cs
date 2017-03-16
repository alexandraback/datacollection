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
		int A;
		int B;
		double[] p;
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
			A = int.Parse( strs[0] );
			B = int.Parse( strs[1] );
			p = new double[A];

			line = reader.ReadLine();
			strs = line.Split( new char[] { ' ' } );
			for( int i = 0; i < A; i++ ) {
				p[i] = double.Parse( strs[i] );
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1}", A, B );
//			for( int i = 0; i < A; i++ )
//				Console.Write( " {0}", p[i] );
//			Console.WriteLine();
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 5;
		static bool BEEP = false;

//		static string CASEFILE = @"..\..\..\A-small-attempt0.in";
		static string CASEFILE = @"..\..\..\A-large.in";

//		static string CASEFILE = @"..\..\..\B-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\B-large.in";

//		static string CASEFILE = @"..\..\..\C-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\C-large.in";

//		static string CASEFILE = @"..\..\..\D-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\D-large.in";

//		static string CASEFILE = @"..\..\..\__in_sample.txt";
//		static string CASEFILE = @"..\..\..\__in_large.txt";
		////////////////////////////////



		private void Solv()
		{
			////////////////////////////////

			// s1
			double k1 = 0;
			{
				double pp = 1;
				for(int i = 0; i < A; i++)
					pp *= p[i];
				k1 = pp * (B+1) + (1-pp) * (B+1)*2 - A;
			}

			// s2
			double k2 = 0;
			{
				k2 = A + B + 1;
//				Console.WriteLine( "kk2: {0}", k2 );

				double q = 1;
				for( int i = 0; i < A-1; i++ ) {
					q *= p[i];

					double kk2 = q * ((A-i-1)*2 + B-A + 1)   + (1-q) * ((A-i-1)*2 + B-A + 1 + B+1);

//					Console.WriteLine( "kk2: {0}", kk2 );
					k2 = Math.Min(k2,kk2);

				} 
			}
			
			// s3
			double k3 = 0;
			{
				k3 = 1 + B+1;
			}
			Console.WriteLine( "k1: {0}", k1 );
			Console.WriteLine( "k2: {0}", k2 );
			Console.WriteLine( "k3: {0}", k3 );


			double k = Math.Min(k1,Math.Min(k2,k3));

			Result = k.ToString("F6");
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
