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
		long A;
		long B;
		////////////////////////////////


		static long AA = 1;
		static long BB = 100000000000000;
		static List<long> p = new List<long>();

		private static void Initialize()
		{
			////////////////////////////////
			long aa = Math.Max(1,(long)Math.Log10(Math.Sqrt(AA)));
			long bb = Math.Max(1,(long)Math.Log10(Math.Sqrt(BB)))+1;
			for(long i = aa; i <= bb; i++) {
				checkcheck(0, 0, i, 0);
			}
			Console.WriteLine( "***********  {0}", p.Count );
			////////////////////////////////
		}
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			A = long.Parse( strs[0] );
			B = long.Parse( strs[1] );
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1}", A, B );
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 8;
		static bool BEEP = true;

//		static string CASEFILE = @"..\..\..\C-small-attempt0.in";
		static string CASEFILE = @"..\..\..\C-large-1.in";

//		static string CASEFILE = @"..\..\..\__in_sample.txt";
		////////////////////////////////


		private static bool check(long x) {
			string s = x.ToString();
			int a = 0;
			int b = s.Length - 1;
			for(int i = 0; i < s.Length/2; i++) {
				if(s[a++] != s[b--])
					return false;				
			}
			return true;
		}

		private static void checkcheck(long pre, long post, long n, long count)
		{
			long q = 1;
			for(int i = 0; i < count; i++)
				q *= 10;
			long s = count==0? 1: 0;

			if(n == 1) {
				long x = pre * q * 10 + post;

				for(long i = s; i < 10; i++) {
					long xx = x + i * q;
//					Console.WriteLine( "  {0}", xx );

					long xxxx = xx*xx;
					if(xxxx > BB)
						break;
					if(xxxx >= AA && check(xxxx)) {
						p.Add(xxxx);
						Console.WriteLine( "  {0}", xxxx );
					}
				}
			} else if(n == 2) {
				long x = pre * q * 100 + post;

				for(long i = s; i < 10; i++) {
					long xx = x + (i*10+i) * q;
//					Console.WriteLine( "  {0}", xx );

					long xxxx = xx*xx;
					if(xxxx > BB)
						break;
					if(xxxx >= AA && check(xxxx)) {
						p.Add(xxxx);
						Console.WriteLine( "  {0}", xxxx );
					}
				}
			} else {
				for(long i = s; i < 10; i++) {
					checkcheck(pre*10+i, i*q+post, n-2, count+1);
				}
			}
		}



		private void Solv()
		{
			////////////////////////////////
			long c = 0;

			foreach(long pp in p) {
				if(pp > B)
					break;
				if(pp >= A)
					c++;
			}

			Result = c.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}
/*
		private void Solv()
		{
			////////////////////////////////
			long c = 0;

			long aa = (long)Math.Sqrt(A);
			long bb = (long)Math.Sqrt(B) + 1;
			for(long i = aa; i <= bb; i++) {
				if(!check(i))
					continue;

				long ii = i*i;
				if(ii > B)
					break;
				if(ii >= A && check(ii))
					c++;
			}

			Result = c.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}
*/
	}
}
