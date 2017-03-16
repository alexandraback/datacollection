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

		static string CASEFILE = @"..\..\..\C-small-attempt4.in";
//		static string CASEFILE = @"..\..\..\C-large.in";

		//static string CASEFILE = @"..\..\..\X-small-practice.in";
		//static string CASEFILE = @"..\..\..\X-large-practice.in";

		static int MAXTHREADS = 1;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		int R;
		int C;
		int M;
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			R = int.Parse( strs[0] );
			C = int.Parse( strs[1] );
			M = int.Parse( strs[2] );
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1} {2}", R,C,M );
			////////////////////////////////
		}


		char[,] f;

		bool calc1() {
			f[0,0] = 'c';
			if (C==1) {
				for (int m = 0; m < M; m++) {
					f[0,R-1-m] = '*';
				}
			} else {
				for (int m = 0; m < M; m++) {
					f[C-1-m,0] = '*';
				}
			}
			return true;
		}

		bool calc2() {
			f[0,0] = 'c';
			int q = C*R-M;
			if (q<4 || (M%2)==1)
				return false;
			if (C==2) {
				for (int m = 0; m < M/2; m++) {
					f[0,R-1-m] = '*';
					f[1,R-1-m] = '*';
				}
			} else {
				for (int m = 0; m < M/2; m++) {
					f[C-1-m,0] = '*';
					f[C-1-m,1] = '*';
				}
			}
			return true;
		}

		bool calc3() {
			f[C-1,R-1] = 'c';

			int q = C*R-M;
			if (q<4 || q==5 || q==7)
				return false;

			int m = M;
			if ((C-2)*(R-2) >= M) {
				for (int r = 0; r < R-2; r++) {
					for (int c = 0; c < C-2; c++) {
						if (m==0)
							return true;
						f[c,r] = '*';
						m--;
					}
				}
				return true;
			}
			for (int r = 0; r < R-2; r++) {
				for (int c = 0; c < C-2; c++) {
					f[c,r] = '*';
				}
			}
			f[C-3,R-3]='.';
			m -= (C-2)*(R-2)-1;

			if (C>R) {
				if (2*(R-3) >= m) {
					if (m%2==1) {
						m--;
						f[C-3,R-3]='*';
					}
					for (int r = 0; r < m/2; r++) {
						f[C-1,r] = '*';
						f[C-2,r] = '*';
					}
					return true;
				}
				for (int r = 0; r < R-3; r++) {
					f[C-1,r] = '*';
					f[C-2,r] = '*';
				}
				m -= 2*(R-3);

				if (2*(C-3) >= m) {
					if (m%2==1) {
						m--;
						f[C-3,R-3]='*';
					}
					for (int c = 0; c < m/2; c++) {
						f[c,R-1] = '*';
						f[c,R-2] = '*';
					}
					return true;
				}
				for (int c = 0; c < C-3; c++) {
					f[c,R-1] = '*';
					f[c,R-2] = '*';
				}
				m -= 2*(C-3);
			} else {
				if (2*(C-3) >= m) {
					if (m%2==1) {
						m--;
						f[C-3,R-3]='*';
					}
					for (int c = 0; c < m/2; c++) {
						f[c,R-1] = '*';
						f[c,R-2] = '*';
					}
					return true;
				}
				for (int c = 0; c < C-3; c++) {
					f[c,R-1] = '*';
					f[c,R-2] = '*';
				}
				m -= 2*(C-3);

				if (2*(R-3) >= m) {
					if (m%2==1) {
						m--;
						f[C-3,R-3]='*';
					}
					for (int r = 0; r < m/2; r++) {
						f[C-1,r] = '*';
						f[C-2,r] = '*';
					}
					return true;
				}
				for (int r = 0; r < R-3; r++) {
					f[C-1,r] = '*';
					f[C-2,r] = '*';
				}
				m -= 2*(R-3);
			}
		
			if(m==1) {
				f[C-3,R-3]='*';
				return true;
			} else if(m==3) {
				f[C-3,R-3]='*';
				f[C-2,R-3]='*';
				f[C-1,R-3]='*';
				return true;
			} else if(m==5) {
				f[C-3,R-3]='*';
				f[C-2,R-3]='*';
				f[C-1,R-3]='*';
				f[C-3,R-2]='*';
				f[C-3,R-1]='*';
				return true;
			}
			return false;			
		}


		private void Solv()
		{
			////////////////////////////////
			f = new char[C,R];
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					f[c,r] = '.';
				}
			}

			bool ret;
			if ((C*R-M)==1) {
				for (int r = 0; r < R; r++) {
					for (int c = 0; c < C; c++) {
						f[c,r] = '*';
					}
				}
				f[0,0] = 'c';
				ret = true;
			} else if (C==1 || R==1) {
				ret = calc1();
			} else if (C==2 || R==2) {
				ret = calc2();
			} else {
				ret = calc3();
			}	

			if (ret) {
				for (int r = 0; r < R; r++) {
					Result += "\n";
					for (int c = 0; c < C; c++) {
						Result += f[c,r];
					}
				}
			} else {
				Result = "\nImpossible";
			}
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
