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

		static string CASEFILE = @"..\..\..\C-small-attempt2.in";
//		static string CASEFILE = @"..\..\..\C-large.in";

		static int MAXTHREADS = 1;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		int J;
		int P;
		int S;
		int K;
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			J = int.Parse( strs[0] );
			P = int.Parse( strs[1] );
			S = int.Parse( strs[2] );
			K = int.Parse( strs[3] );
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1} {2} {3}", J,P,S,K );
			////////////////////////////////
		}


		List<string> r = new List<string>();

		List<int> U = new List<int>();
		List<int> UMAX = new List<int>();
		int max = 0;
int q = 0;

		bool eval() {
			bool over = false;
			Dictionary<int, int> kk = new Dictionary<int, int>();
			List<int> UU = new List<int>();
			int kmax = 0;
			for (int i = 0; i < U.Count; i++) {
				int u = U[i];
				for (int j = 0; j < UU.Count; j++) {
					int uu = UU[j];
					if (r[u][0] == r[uu][0] && r[u][2] == r[uu][2]) {
						int key = (int)(r[u][0] - '0') * 100 + (int)(r[u][2] - '0') * 10;
						if (kk.ContainsKey(key)) {
							kk[key] = kk[key] + 1;
						} else {
							kk[key] = 1;
						}
						if (kmax < kk[key]) {
							kmax = kk[key];
						}
					}
					if (r[u][0] == r[uu][0] && r[u][4] == r[uu][4]) {
						int key = (int)(r[u][0] - '0') * 100 + (int)(r[u][4] - '0');
						if (kk.ContainsKey(key)) {
							kk[key] = kk[key] + 1;
						} else {
							kk[key] = 1;
						}
						if (kmax < kk[key]) {
							kmax = kk[key];
						}
					}
					if (r[u][2] == r[uu][2] && r[u][4] == r[uu][4]) {
						int key = (int)(r[u][2] - '0') * 10 + (int)(r[u][4] - '0');
						if (kk.ContainsKey(key)) {
							kk[key] = kk[key] + 1;
						} else {
							kk[key] = 1;
						}
						if (kmax < kk[key]) {
							kmax = kk[key];
						}
					}
				}
				if (kmax < K) {
					UU.Add(u);
				} else {
					over = true;
					break;
				}
			}
			q++;
			if (max < UU.Count) {
				max = UU.Count;
				UMAX.Clear();
				for(int i = 0;i < UU.Count; i++) {
					UMAX.Add(UU[i]);
				}
				Console.WriteLine("**** max = " + max.ToString());
				q = 0;
			}
			return !over && q < 10000;
		}

		void calc() {
			if (U.Count < r.Count) {
				for (int i = 0; i < r.Count; i++) {
					if (!U.Contains(i)) {
						U.Add(i);
						//int lastmax = max;
						if (eval()) {
							calc();
						}
						U.RemoveAt(U.Count-1);
					}
				}
				return;
			}

			eval();
		}

		private void Solv()
		{
			////////////////////////////////
			string s;
			for (int i = 0; i < J; i++) {
			    s = (i+1).ToString() + " ";
			    for (int j = 0; j < P; j++) {
			        string ss = s + (j+1).ToString() + " ";
			        for (int k = 0; k < S; k++) {
			            string sss = ss + (k+1).ToString();
			            r.Add(sss);
			            Console.WriteLine("***** " + sss);
			        }
			    }
			}
			//for (int i = 0; i < S; i++) {
			//    s = " " + (i+1).ToString();
			//    for (int j = 0; j < P; j++) {
			//        string ss = " " + (j+1).ToString() + s;
			//        for (int k = 0; k < J; k++) {
			//            string sss = (k+1).ToString() + ss;
			//            r.Add(sss);
			//            Console.WriteLine("***** " + sss);
			//        }
			//    }
			//}

			U.Add(0);
			calc();
			
			Result = max.ToString();
			for (int i = 0; i < UMAX.Count; i++) {
				Result += "\n";
				Result += r[UMAX[i]];
			}
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
