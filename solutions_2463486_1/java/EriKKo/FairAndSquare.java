import java.math.*;
import java.util.*;
import java.io.*;

public class FairAndSquare {
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			BigInteger A = new BigInteger(io.getWord()).subtract(BigInteger.ONE);
			BigInteger B = new BigInteger(io.getWord());
			int res = getFairAndSquares(B.toString().toCharArray());
			res -= getFairAndSquares(A.toString().toCharArray());
			io.println("Case #" + test + ": " + res);
		}
		
		io.close();
	}
	
	static int getFairAndSquares(char[] MAX) {
		int len = 1;
		int res = 0;
		while (true) {
			int newFound = rec(new char[len], 0, 0, MAX);
			if (newFound == 0) break;
			res += newFound;
			len++;
		}
		return res;
	}
	
	static int rec(char[] n, int pos, int sum, char[] MAX) {
		int res = 0;
		if (2*pos < n.length) {
			if (pos > 0) {
				n[pos] = n[n.length - 1 - pos] = '0';
				res += rec(n, pos + 1, sum, MAX);
			}
			for (int i = 1; i < 4; i++) {
				int newSum = sum + i*i;
				if (2*pos != n.length - 1) newSum += i*i; // Not in the middle
				if (newSum < 10) {
					n[pos] = n[n.length - 1 - pos] = (char)('0' + i);
					res += rec(n, pos + 1, newSum, MAX);
				}
			}
		} else {
			if (leq(sq(n), MAX)) return 1;
			return 0;
		}
		return res;
	}
	
	static char[] sq(char[] n) {
		int l = n.length*2 - 1;
		char[] res = new char[l];
		Arrays.fill(res, '0');
		for (int i = 0; i < n.length; i++) {
			for (int j = 0; j < n.length; j++) {
				res[i + j] += (n[i] - '0') * (n[j] - '0');
			}
		}
		return res;
	}
	
	static boolean leq(char[] n1, char[] n2) {
		if (n1.length > n2.length) return false;
		if (n1.length < n2.length) return true;
		for (int i = 0; i < n1.length; i++) {
			char c1 = n1[i], c2 = n2[i];
			if (c1 < c2) return true;
			if (c1 > c2) return false;
		}
		return true;
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
