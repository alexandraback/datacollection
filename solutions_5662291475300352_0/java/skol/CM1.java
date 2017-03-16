import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class CM1 {
	
	static class Solver extends Thread {
		
		static class HikerGroup implements Comparable<HikerGroup> {
			long d;
			int cnt;
			long min;
			
			public HikerGroup(int d, int cnt, int min) {
				super();
				this.d = d;
				this.cnt = cnt;
				this.min = min;
			}

			@Override
			public int compareTo(HikerGroup o) {
				if (d != o.d)
					return (int)(d - o.d);
				return (int)(min - o.min);
			}
		}
		
		int N;
		List<HikerGroup> hikers;
		
		
		void read(Scanner sc) {
			N = sc.nextInt();
			hikers = new ArrayList<CM1.Solver.HikerGroup>();
			for (int i = 0; i < N; i++) {
				int d = sc.nextInt();
				int h = sc.nextInt();
				int m = sc.nextInt();
				
				hikers.add(new HikerGroup(d, h, m));
			}
		}
		
//		static class State implements Comparable<State> {
//			double pos;
//			double time;
//			int overtaken;
//			public State(double pos, double time, int overtaken) {
//				super();
//				this.pos = pos;
//				this.time = time;
//				this.overtaken = overtaken;
//			}
//			@Override
//			public int compareTo(State o) {
//				return overtaken - o.overtaken;
//			}
//		}
		
		Object solve() {
			if (hikers.size() == 1 && hikers.get(0).cnt == 1)
				return 0;
			
			Collections.sort(hikers);
			
			if (hikers.size() == 1) {
				long d = hikers.get(0).d;
				long m1 = hikers.get(0).min;
				long m2 = m1+1;
				
				if ((360-d)*m2 < (720-d)*m1)
					return 0;
				else
					return 1;
			} else {
				long d1 = hikers.get(0).d;
				long m1 = hikers.get(0).min;

				long d2 = hikers.get(1).d;
				long m2 = hikers.get(1).min;

//				System.out.println(d1 + " " + d2);
//				System.out.println(m1 + " " + m2);
				
				if (d1 == d2) {
					long d = d1;
					if ((360-d)*m2 < (720-d)*m1)
						return 0;
					else
						return 1;
				}
				
				long min = 2;
				{
					//stay behind first
					{
						long t1 = (360-d1)*m1;
						long e = t1/m2;
						long rem = t1*360/m2 - e*360;
						if (rem > (360 - d2))
							e++;
						min = min(e, min);
					}

					//overtake first and stay behind second
					{
						long t2 = (360-d2)*m2;
						long e = t2/m1+1;
						long rem = t2*360/m1 - e*360;
						if (rem > (360 - d1))
							e++;
						min = min(e, min);
					}

					/*
					if (m1 < m2) {
						int t1 = (360-d1)*m1;
						int t2 = (720-d2)*m2;
						if (t1 < t2)
							return 0;
						else
							return 1;
					} else {
						int t1 = (360-d1)*m1;
						int t2 = (360-d2)*m2;
						if (t1 > t2) {
							return 0;
						} else {
							int t1a = (720-d1)*m1;
							if (t2 < t1a)
								return 0;
							else 
								return 1;
						}
					}
					*/
				}
				
				return min;
				
			}
		}

		Object result;
		
		public void run() {
			result = solve();
			synchronized (sync) {
				remaining--; running--;
				startNextCase();
				System.out.println("Remaining: " + remaining + ", Running: " + running);
				if (finished())
					sync.notifyAll();
			}
		}
	}


	private static final int MAX_THREADS = 8;
	private static Object sync = new Object(); static int running, remaining, next; 
	private static ArrayList<Solver> cases = new ArrayList<Solver>(); 

	public static void main(String[] args) throws Exception {
		Scanner sc; PrintWriter fw; 
		String inFile = "input.txt", outFile = "output.txt";
//		inFile = "A-small-attempt0.in";
//		inFile = "A-large.in";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false));
		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			Solver solver = new Solver();
			solver.read(sc);
			remaining++;
			cases.add(solver);
		}
		
		for (int i = 0; i < min(N, MAX_THREADS); i++)
			startNextCase();
		System.out.println("Remaining: " + remaining + ", Running: " + running);
		
		while (!finished()) {
			synchronized (sync) {
				sync.wait(1000);
			}
		}
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
			Object res = cases.get(cas-1).result;
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

	static boolean finished() {
		synchronized (sync) {
			return remaining == 0;
		}
	}
	
	static void startNextCase() {
		synchronized (sync) {
			if (remaining > running) {
				cases.get(next++).start();
				running++;
			}
		}
	}
}
