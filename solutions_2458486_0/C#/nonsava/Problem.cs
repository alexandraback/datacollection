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
		int K;
		int N;
		Box[] boxes;
		List<int> keys = new List<int>();
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
			K = int.Parse( strs[0] );
			N = int.Parse( strs[1] );

			line = reader.ReadLine();
			strs = line.Split( new char[] { ' ' } );
			for( int i = 0; i < K; i++ ) {
				keys.Add(int.Parse( strs[i] ));
			}
			
			boxes = new Box[N];
			for( int i = 0; i < N; i++ ) {
				line = reader.ReadLine();
				strs = line.Split( new char[] { ' ' } );
				boxes[i] = new Box();
				boxes[i].n = i+1;
				boxes[i].lck = int.Parse( strs[0] );
				for(int j=0; j < int.Parse( strs[1] ); j++) {
					boxes[i].keys.Add( int.Parse( strs[2+j] ) );
				}
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1}", K, N );
			for( int i = 0; i < K; i++ )
				Console.Write( " {0}", keys[i] );
			Console.WriteLine();

			for( int i = 0; i < N; i++ ) {
				Console.Write( "  [{0}]: {1}: ", boxes[i].n, boxes[i].lck );
				foreach(int k in boxes[i].keys) {
					Console.Write( " {0}", k );
				}
				Console.WriteLine();
			}
			Console.WriteLine();
			////////////////////////////////
		}



		////////////////////////////////
		static int MAXTHREADS = 1;
		static bool BEEP = false;

//		static string CASEFILE = @"..\..\..\D-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\D-small-attempt1.in";
		static string CASEFILE = @"..\..\..\D-small-attempt2.in";
//		static string CASEFILE = @"..\..\..\D-large.in";

//		static string CASEFILE = @"..\..\..\__in_sample.txt";
		////////////////////////////////


		class Box {
			public int n;
			public int lck;
			public List<int> keys = new List<int>();
			
			public bool opened = false;
		}


		List<int> results = new List<int>();
		int lack = -1;

		bool tryopen(Box b)
		{
			// try to open
			bool canopen = false;
			for(int i = 0; i < keys.Count; i++) {
				if(b.lck == keys[i]) {
					keys.RemoveAt(i);
					canopen = true;
					break;
				}
			}
			if(!canopen) {
				// if cannot open
				bool f = false;
				foreach(Box box in boxes) {
					if(!box.opened && box.n != b.n) {
						if(box.keys.Contains(b.lck)) {
							f = true;
							break;
						}
					}
				}				
				if(!f)
					lack = b.lck;
				Console.WriteLine( "************************** lack: {0}", lack );
				return false;
			}

			// if can open
			b.opened = true;
			foreach(int k in b.keys) {
				keys.Add(k);
			}
			results.Add(b.n);
foreach(int r in results) {
	Console.Write( " {0}", r );
}
Console.WriteLine();

			// try next
			bool found = false;
			foreach(Box box in boxes) {
				if(!box.opened) {
					found = true;
					if(tryopen(box))
						return true;
					if(lack!=-1) {
						if(lack==b.lck) {
							lack=-1;
						}
						break;
					}
				}
			}
			if(!found)
				return true;

			b.opened = false;
			foreach(int k in b.keys) {
				keys.Remove(k);
			}
			keys.Add(b.lck);
			results.Remove(b.n);

			return false;
		}			


		bool check()
		{
			List<int> ks = new List<int>();
			ks.AddRange(keys);
			foreach(Box b in boxes)
				ks.AddRange(b.keys);

			foreach(Box b in boxes) {
				bool found = false;
				for(int i = 0; i < ks.Count; i++) {
					if(ks[i] == b.lck) {
						found = true;
						ks.RemoveAt(i);
						break;
					}
				}
				if(!found)
					return false;
			}

			return true;
		}


		private void Solv()
		{
			////////////////////////////////
			Result = "";

			if(!check()) {
				Result = "IMPOSSIBLE";
				Console.WriteLine( "Result: {0}", Result );
				return;
			}

			foreach(Box b in boxes) {
				if(tryopen(b)) {
					foreach(int r in results) {
						if(Result.Length > 0)
							Result += " ";
						Result += r;
					}
					break;
				}
			}

			if(Result.Length == 0)
				Result = "IMPOSSIBLE";
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
