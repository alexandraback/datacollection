import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	
	static String filename = "C-small-attempt0";
	
	HashSet<Integer> getCycles(int n) {
		int nc = n;
		int digitcount = 0;
		int pow10 = 1;
		while (nc > 0) {
			digitcount++;
			nc /= 10;
			pow10 *= 10;
		}
		pow10 /= 10;
		HashSet<Integer> answer = new HashSet<Integer>();
		nc = n;
		for (int i = 0; i < digitcount; i++) {
			answer.add(nc);
			int lastdigit = nc % 10;
			nc /= 10;
			nc += pow10 * lastdigit;
		}
		return answer;
	}
	
	public void solve() throws Exception {
		int t = sc.nextInt();
		for (int Case = 1; Case <= t; Case++) {
			int a = sc.nextInt(), b = sc.nextInt();
			boolean[] visited = new boolean[b + 1];
			long answer = 0;
			for (int i = a; i <= b; i++) {
				if (visited[i]) {
					continue;
				}
				HashSet<Integer> cycles = getCycles(i);
				int suitable = 0;
				for (int c : cycles) {
					if (c >= a && c <= b) {
						suitable++;
						visited[c] = true;
						//out.print(c + " ");
					}
				}
				//out.println();
				answer += suitable * (suitable - 1) / 2;
			}
			//out.println();
			out.printf("Case #%d: %d\n", Case, answer);
		}
	}
	
	BufferedReader in;
	PrintWriter out;
	FastScanner sc;
	
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "", 1 << 25).start();
	}
	
	@Override
	public void run() {
		try {
			init();
			solve();
		} catch (Exception e) {
			throw new RuntimeException(e);
		} finally {
			out.close();
		}
	}
	
	void init() throws Exception {
		in = new BufferedReader(new FileReader(filename + ".in"));
		out = new PrintWriter(new FileWriter(filename + ".out"));
		sc = new FastScanner(in);
	}
}

class FastScanner {
	
	BufferedReader reader;
	StringTokenizer strTok;
	
	public FastScanner(BufferedReader reader) {
		this.reader = reader;
	}
	
	public String nextToken() throws IOException {
		while (strTok == null || !strTok.hasMoreTokens()) {
			strTok = new StringTokenizer(reader.readLine());
		}
		
		return strTok.nextToken();
	}
	
	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	public BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}
	
}
