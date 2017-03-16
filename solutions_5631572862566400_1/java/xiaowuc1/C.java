import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static ArrayList<Integer>[] p;
	static boolean[] cycle;
	static int[] distToCycle;
	static int[] to;
	static int[] dp;

	static int[] components;
	static int componentIndex;

	public static void computeComponents() {
		components = new int[p.length];
		Arrays.fill(components, -1);
		componentIndex = 0;
		for(int i = 0; i < components.length; i++) {
			if(components[i] >= 0) continue;
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(i);
			components[i] = componentIndex;
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				if(components[to[curr]] == -1) {
					components[to[curr]] = componentIndex;
					q.add(to[curr]);
				}
				for(int out: p[curr]) {
					if(components[out] == -1) {
						components[out] = componentIndex;
						q.add(out);
					}
				}
			}
			componentIndex++;
		}
	}

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			distToCycle = new int[n];
			Arrays.fill(distToCycle, -1);
			p = new ArrayList[n];
			dp = new int[n];
			Arrays.fill(dp, -1);
			for(int i = 0; i < n; i++) {
				p[i] = new ArrayList<Integer>();
			}
			to = new int[n];
			cycle = new boolean[n];
			int[] cycleSize = new int[n];
			for(int i = 0; i < n; i++) {
				to[i] = readInt()-1;
				p[to[i]].add(i);
			}
			int ret = 0;
			int[] best = new int[n];
			computeComponents();
			for(int i = 0; i < n; i++) {
				int curr = to[i];
				int seen = 1;
				while(seen < n+2 && curr != i) {
					curr = to[curr];
					seen++;
				}
				if(seen <= n) {
					cycleSize[i] = seen;
					cycle[i] = true;
					ret = Math.max(ret, seen);
				}
			}
			int ans = 0;
			for(int i = 0; i < n; i++) {
				if(!cycle[i]) continue;
				if(cycleSize[i] != 2) continue;
				best[components[i]] = Math.max(best[components[i]], solve(i) + solve(to[i]));
			}
			for(int out: best) {
				ans += out;
			}
			pw.println(Math.max(ret, ans));
		}
		pw.close();
	}

	public static int solve(int v) {
		if(dp[v] == -1) {
			dp[v] = 1;
			for(int out: p[v]) {
				if(cycle[out]) continue;
				dp[v] = Math.max(dp[v], 1 + solve(out));
			}
		}
		return dp[v];
	}

	public static int distToCycle(int n) {
		if(cycle[n]) {
			return 0;
		}
		if(distToCycle[n] == -1) {
			distToCycle[n] = 1 + distToCycle(to[n]);
		}
		return distToCycle[n];
	}

	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine());
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
