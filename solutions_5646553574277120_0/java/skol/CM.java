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


public class CM {
	

		
	static class Solver extends Thread {
	
		public static class State implements Comparable<State> {
			int poss;
			int denom;
			int dist;
			
			@Override
			public int compareTo(State o) {
				return dist - o.dist;
			}

			public State(int poss, int denom, int dist) {
				super();
				this.poss = poss;
				this.denom = denom;
				this.dist = dist;
			}

			@Override
			public int hashCode() {
				final int prime = 31;
				int result = 1;
				result = prime * result + denom;
				result = prime * result + poss;
				return result;
			}

			@Override
			public boolean equals(Object obj) {
				if (this == obj)
					return true;
				if (obj == null)
					return false;
				if (getClass() != obj.getClass())
					return false;
				State other = (State) obj;
				if (denom != other.denom)
					return false;
				if (poss != other.poss)
					return false;
				return true;
			}

			@Override
			public String toString() {
				return "State [poss=" + Integer.toBinaryString(poss) + ", denom=" + Integer.toBinaryString(denom) + ", dist="
						+ dist + "]";
			}
			
		}

		
		void read(Scanner sc) {
			C = sc.nextInt();
			D = sc.nextInt();
			V = sc.nextInt();
			denoms = new int[D];
			for (int i = 0; i < D; i++)
				denoms[i] = sc.nextInt();
		}
		
		
		Object solve() {
			int poss = 1;
			int den = 0;
			for (int i = 0; i < D; i++) {
				den |= (1<<denoms[i]);
				for (int j = 0; j < C; j++) {
					int poss1 = poss;
					for (int k = 0; k <= V; k++) {
						if (((poss>>k)&1) == 1) {
							int k1 = k + denoms[i];
							if (k1 <= V)
								poss1 |= 1<<k1;
						}
					}
					poss = poss1;
				}
			}
			
			PriorityQueue<State> pq = new PriorityQueue<State>();
			pq.add(new State(poss, den, 0));
			
			HashSet<State> vis = new HashSet<CM.Solver.State>();
			
			int goal = (1<<(V+1))-1;
			
			while (!pq.isEmpty()) {
				State st = pq.poll();
				
//				System.out.println(st);
				
				if (st.poss == goal)
					return st.dist;
				
				if (vis.contains(st))
					continue;
				vis.add(st);
				
				for (int i = 1; i <= V; i++) {
					if (((st.denom>>i)&1) == 0) {
						int poss1 = st.poss;
						for (int j = 0; j < C; j++) {
							for (int k = 0; k <= V; k++) {
								if (((st.poss>>k)&1) == 1) {
									int k1 = k + i;
									if (k1 <= V)
										poss1 |= 1<<k1;
								}
							}
						}
						int den1 = st.denom | (1<<i);
						pq.add(new State(poss1, den1, st.dist+1));
					}
				}
			}
			
			return -1;
		}

		Object result;
		private int C;
		private int D;
		private int V;
		private int[] denoms;
		
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


	private static final int MAX_THREADS = 32;
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
