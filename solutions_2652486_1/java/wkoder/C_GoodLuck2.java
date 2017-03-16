import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class C_GoodLuck2 {
	
	static final int INF = 1 << 28, MAX = 1000;
	static final double EPS = 1E-9;
	
	static List<Long> guesses = new ArrayList<Long>();
	static int R, N, M, K;
	static int[] p, g;
	
	static void go(int pos, int lastM) {
		if (pos == N) {
			for (int prod : p) {
				for (int i = N-1; i >= 0; i--)
					if (prod % g[i] == 0)
						prod /= g[i];
				if (prod > 1)
					return;
			}
			
			long temp = 0;
			for (int i = N-1; i >= 0; i--)
				temp = temp * 10 + g[i];
			guesses.add(temp);
			
			return;
		}
		
		for (int m = lastM; m <= M; m++) {
			g[pos] = m;
			go(pos+1, m);
		}
	}
	
	static void solve() {
		Scanner scan = new Scanner(in);
		int T = scan.nextInt();
		Random random = new Random(System.currentTimeMillis());
		for (int t = 1; t <= T; t++) {
			out.println("Case #" + t + ":");
			R = scan.nextInt();
			N = scan.nextInt();
			M = scan.nextInt();
			K = scan.nextInt();
			p = new int[K];
			g = new int[N];
			for (int r = 0; r < R; r++) {
				guesses.clear();
				for (int k = 0; k < K; k++)
					p[k] = scan.nextInt();
				go(0, 2);
				
//				System.out.println(guesses);
				if (guesses.isEmpty()) { // Default
					for (int i = 0; i < N; i++)
						out.print(2);
					out.println();
				} else {
					out.println(guesses.get(random.nextInt(guesses.size())));
				}
			}
		}
	}
	
	static String read() {
		try { return in.readLine(); } catch (IOException e) { return null; }
	}
	public static void main(String[] args) throws IOException {
//		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(new BufferedOutputStream(System.out));
		String file = "C-small-2";
		in = new BufferedReader( new FileReader(file + ".in") );
		out = new PrintWriter( new FileOutputStream(file + "_" + System.currentTimeMillis() + ".out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}
