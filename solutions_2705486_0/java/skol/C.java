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


public class C {

	static String[] dict = new String[521196];
	static {
		try {
			Scanner sc = new Scanner(new File("garbled_email_dictionary.txt"));
			int i = 0;
			while (sc.hasNext())
				dict[i++] = sc.next();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static class State implements Comparable<State> {
		int pos;
		int prev;
		int n;
		
		public State(int pos, int prev, int n) {
			super();
			this.pos = pos;
			this.n = n;
			if (prev < -5)
				prev = -5;
			this.prev = prev;
		}

		@Override
		public int compareTo(State o) {
			if (n != o.n)
				return n - o.n;
			return o.pos - pos;
		}
	}
	
	int[] diff(String a, String b, int prev) {
		if (a.length() != b.length()) throw new RuntimeException();
		int cnt = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a.charAt(i) != b.charAt(i)) {
				if (i - prev < 5)
					return null;
				prev = i;
				cnt++;
			}
		}
		return new int[] {cnt, - a.length() + prev};
	}
	
	Object solve() {
		String S = sc.next();
		
		PriorityQueue<State> q = new PriorityQueue<C.State>();
		boolean[][] vis = new boolean[5000][7];
		q.add(new State(0, -6, 0));
		
		while (!q.isEmpty()) {
			State s = q.poll();
			if (s.pos > S.length()) continue;
			if (s.pos == S.length()) return s.n;
//			System.out.println(s.pos + " " + s.prev);
			if (vis[s.pos][-s.prev])
				continue;
			vis[s.pos][-s.prev] = true;
			
			for (String w : dict) {
				if (s.pos + w.length() <= S.length()) {
					int[] dist = diff(w, S.substring(s.pos, s.pos + w.length()), s.prev);
					if (dist != null)
						q.add(new State(s.pos + w.length(), dist[1], s.n + dist[0]));
				}
			}
		}
		
		return -1;
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
//		inFile = "C-small-attempt0.in";
//		inFile = "C-large.in";
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
			Object res = new C().solve();
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
