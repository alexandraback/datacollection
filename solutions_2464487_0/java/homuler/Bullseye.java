package gcj_2014_r1A;
import java.util.*;
import java.io.*;

public class Bullseye {
	public long calc(long r, long t){
		long lb = 0;
		long ub = 1000000000L;
		while( ub-lb > 1 ){
			long mid = (ub+lb)/2;
			long v = mid*(2*mid+2*r-1)-t;
			if( v <= 0 ){
				lb = mid;
			} else {
				ub = mid-1;
			}
	//		writer.println(ub + " " + lb + " " + v + " " + mid);
		}
		if( ub*(2*ub+2*r-1)-t <= 0 ){
			return ub;
		}
		return lb;
	}
	public void solve() throws IOException {
		int T = nextInt();
		for(int i = 0; i < T; i++){
			long r = nextLong();
			long t = nextLong();
			writer.println("Case #" + (i+1) + ": " + calc(r, t));
		}
		writer.flush();
	}

	public static void main(String[] args) throws IOException {
		new Bullseye().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() throws IOException {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
} 
