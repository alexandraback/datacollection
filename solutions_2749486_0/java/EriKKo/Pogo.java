import java.util.*;
import java.io.*;

public class Pogo {
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			int X = io.getInt(), Y = io.getInt();
			int tot = Math.abs(X) + Math.abs(Y);
			int n = 0, sum = 0;
			while (sum < tot) {
				n++;
				sum += n;
			}
			int neg = -1;
			if (sum > tot) {
				while ((sum - tot)%2 == 1) {
					n++;
					sum += n;
				}
				neg = (sum - tot)/2;
			}
			boolean[] use = createSum(Math.abs(X), n, neg);
			if (use == null) {
				use = createSum(Math.abs(Y), n, neg);
				for (int i = 1; i <= n; i++) use[i] = !use[i];
			}
			StringBuilder sb = new StringBuilder();
			char[][] s = {"WE".toCharArray(), "SN".toCharArray()};
			for (int i = 1; i <= n; i++) {
				int dir;
				int sign;
				if (use[i]) { // west east
					dir = 0;
					if (X < 0) sign = -1;
					else sign = 1;
				} else { // South north
					dir = 1;
					if (Y < 0) sign = -1;
					else sign = 1;
				}
				if (i == neg) sign = -sign;
				int index = sign < 0 ? 0 : 1;
				sb.append(s[dir][index]);
			}
			io.println("Case #" + test + ": " + sb);
		}
		
		io.close();
	}
	
	static boolean[] createSum(int sum, int n, int neg) {
		boolean[] res = new boolean[n + 1];
		for (int i = n; i > 0 && sum > 0; i--) {
			if (i == neg) continue;
			if (i <= sum) {
				sum -= i;
				res[i] = true;
			}
		}
		return sum == 0 ? res : null;
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
