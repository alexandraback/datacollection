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

		static string CASEFILE = @"..\..\..\D-small-attempt1.in";
//		static string CASEFILE = @"..\..\..\D-large.in";

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
		List<float> A = new List<float>();
		List<float> B = new List<float>();
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			N = long.Parse( line );
			line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			string line2 = reader.ReadLine();
			string[] strs2 = line2.Split( new char[] { ' ' } );
			for (int i=0;i<N;i++) {
				A.Add(float.Parse( strs[i] ));
				B.Add(float.Parse( strs2[i] ));
			}
			A.Sort();
			B.Sort();
			A.Reverse();
			B.Reverse();
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0}", N );
			for( int i = 0; i < N; i++ )
				Console.Write( " {0}", A[i] );
			Console.WriteLine();
			for( int i = 0; i < N; i++ )
				Console.Write( " {0}", B[i] );
			Console.WriteLine();
			////////////////////////////////
		}


		private void Solv()
		{
			////////////////////////////////
			int c1 = 0;
			int c2 = 0;

			List<float> b = new List<float>(B.AsEnumerable());
			for(int i=0;i<N;i++) {
				if(A[i] > b[0]) {
					c2++;
					b.RemoveAt(b.Count-1);
				} else {
					b.RemoveAt(0);
				}
			}

			int x = A.Count-1;
			for(int i=0;i<N;i++) {
			    float bb = B[B.Count-1-i];
			    bool found = false;
			    for (int j=x;j>=0;j--) {
			        if(A[j]>bb) {
			            found = true;
			            x=j-1;
			            c1++;
			            break;
			        }
			    }
			    if(!found||x<0) {
			        break;
			    }
			}

			Result = string.Format("{0} {1}", c1, c2);
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
