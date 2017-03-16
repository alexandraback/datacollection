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


public class A {
	
	static class State implements Comparable<State> {
		long size;
		int mot;
		int n;
		
		public State(long size, int mot, int n) {
			super();
			this.size = size;
			this.mot = mot;
			this.n = n;
		}

		@Override
		public int compareTo(State o) {
			if (o.n != n)
				return n - o.n;
			return mot > o.mot ? -1 : 1;
//			return size > o.size ? -1 : 1;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + mot;
			result = prime * result + (int) (size ^ (size >>> 32));
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
			if (mot != other.mot)
				return false;
			if (size != other.size)
				return false;
			return true;
		}
		
		
		
	}
	
	Object solve() {
		long A = sc.nextInt(); int N = sc.nextInt();
		long[] m = new long[N];
		for (int i = 0; i < N; i++)
			m[i] = sc.nextInt();
		sort(m);
		
		HashSet<State> vis = new HashSet<A.State>();
		PriorityQueue<State> q = new PriorityQueue<State>();
		q.add(new State(A, 0, 0));
		while (!q.isEmpty()) {
			State s = q.poll();
			if (vis.contains(s))
				continue;
			vis.add(s);
			if (s.mot == N) return s.n;
			if (s.size > m[s.mot])
				q.add(new State(s.size + m[s.mot], s.mot+1, s.n));
			else {
				q.add(new State(s.size*2-1, s.mot, s.n+1));
				q.add(new State(s.size, s.mot+1, s.n+1));
			}
		}
		
		return -1;
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
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
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
