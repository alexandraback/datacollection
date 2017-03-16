import java.io.*;
import java.util.*;

public class RecycledNumbers {
	
	static int A, B;

	public static void main(String[] args) throws IOException {
		Kattio io = new Kattio(System.in, new FileOutputStream("recycle.out"));
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			A = io.getInt();
			B = io.getInt();
			int res = 0;
			for (int i = A; i <= B; i++) {
				res += recycle(i);
			}
			io.println("Case #"+test+": "+res);
		}
		io.close();
	}
	
	static int recycle(int num) {
		int start = num;
		if (num/10 == 0) return 0;
		int m = 1;
		while (m <= num) {
			m*= 10;
		}
		m/= 10;
		int d = num/m;
		int res = 0;
		while (true) {
			num %= m;
			num *= 10;
			num += d;
			d = num/m;
			if (d != 0 && num > start && num <= B) res++;
			if (num == start) return res;
		}
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