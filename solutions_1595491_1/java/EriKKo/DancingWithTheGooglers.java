import java.io.*;
import java.util.*;

public class DancingWithTheGooglers {

	public static void main(String[] args) throws IOException {
		Kattio io = new Kattio(System.in, new FileOutputStream("dance.out"));
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			int N = io.getInt();
			int S = io.getInt();
			int p = io.getInt();
			int res = 0;
			for (int i = 0; i < N; i++) {
				int t = io.getInt();
				int h = t/3;
				boolean surprise = t >= 2 && t <= 28;
				if (t % 3 != 0) h++;
				if (h >= p) {
					res++;
				} else if (surprise && h+1 >= p && S > 0 && t%3 != 1) {
					res++;
					S--;
				}
			}
			io.println("Case #"+test+": "+res);
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