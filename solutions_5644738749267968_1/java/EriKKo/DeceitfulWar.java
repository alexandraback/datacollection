import java.util.*;
import java.io.*;

public class DeceitfulWar {
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int T = io.getInt();
		for (int test = 1; test <= T; test++) {
			int N = io.getInt();
			double[] naomi = readBlocks(N, io);
			double[] ken = readBlocks(N, io);
			Arrays.sort(naomi);
			Arrays.sort(ken);
			int war = play(N, naomi, ken, 0);
			int decWar = N - play(N, ken, naomi, 0);
			
			io.println("Case #" + test + ": " + decWar + " " + war);
		}
		
		io.close();
	}
	
	static int play(int N, double[] naomi, double[] ken, int removed) {
		int ni = removed, ki = 0;
		while (ni < N) {
			while (ki < N - removed && naomi[ni] > ken[ki]) {
				ki++;
			}
			if (ki < N - removed) {
				ni++;
				ki++;
			} else {
				break;
			}
		}
		return N - ni;
	}
	
	static double[] readBlocks(int N, Kattio io) {
		double[] res = new double[N];
		for (int i = 0; i < N; i++) {
			res[i] = io.getDouble();
		}
		return res;
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
