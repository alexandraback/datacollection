import java.util.*;
import java.io.*;

public class Consonants {
	
	static final String vowels = "aeiou";
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			String s = io.getWord();
			int n = io.getInt();
			long slen = s.length();
			long res = slen*(slen+1)/2;
			int l = 0, cnt = 0;
			for (int r = 0; r < s.length(); r++) {
				if (!vowels.contains(""+s.charAt(r))) {
					cnt++;
					if (cnt >= n) {
						l = r - n + 2;
					}
				} else {
					cnt = 0;
				}
				res -= r - l + 1;
			}
			io.println("Case #" + test + ": " + res);
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
