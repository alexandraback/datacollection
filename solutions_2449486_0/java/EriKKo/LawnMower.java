

import java.util.*;
import java.io.*;

public class LawnMower {
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			int N = io.getInt(), M = io.getInt();
			int[][] lawn = new int[N][M];
			int[] r = new int[N], c = new int[M];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					lawn[i][j] = io.getInt();
					r[i] = Math.max(r[i], lawn[i][j]);
					c[j] = Math.max(c[j], lawn[i][j]);
				}
			}
			boolean good = true;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (lawn[i][j] != Math.min(r[i], c[j])) good = false;
				}
			}
			io.println("Case #" + test + ": " + (good ? "YES" : "NO"));
		}
		
		io.close();
	}
	
	static class Kattio extends PrintWriter {
	    public Kattio(InputStream i) {
		super(new BufferedOutputStream(System.out));
		r = new BufferedReader(new InputStreamReader(i));
	    }
	    public Kattio(InputStream i, OutputStream o) {
		super(new BufferedOutputStream(o));
		r = new BufferedReader(new InputStreamReader(i));
	    }

	    public boolean hasMoreTokens() {
		return peekToken() != null;
	    }

	    public int getInt() {
		return Integer.parseInt(nextToken());
	    }

	    public double getDouble() { 
		return Double.parseDouble(nextToken());
	    }

	    public long getLong() {
		return Long.parseLong(nextToken());
	    }

	    public String getWord() {
		return nextToken();
	    }

	    private BufferedReader r;
	    private String line;
	    private StringTokenizer st;
	    private String token;

	    private String peekToken() {
		if (token == null) 
		    try {
			while (st == null || !st.hasMoreTokens()) {
			    line = r.readLine();
			    if (line == null) return null;
			    st = new StringTokenizer(line);
			}
			token = st.nextToken();
		    } catch (IOException e) { }
		return token;
	    }

	    private String nextToken() {
		String ans = peekToken();
		token = null;
		return ans;
	    }
	}
}
