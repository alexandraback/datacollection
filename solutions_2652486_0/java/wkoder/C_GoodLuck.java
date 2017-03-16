import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class C_GoodLuck {
	
	static final int INF = 1 << 28, MAX = 1000;
	static final double EPS = 1E-9;
	
	static void solve() {
		Scanner scan = new Scanner(in);
		int T = scan.nextInt();
		Random random = new Random(System.currentTimeMillis());
		for (int t = 1; t <= T; t++) {
			out.println("Case #" + t + ":");
			int R = scan.nextInt();
			int N = scan.nextInt();
			int M = scan.nextInt();
			int K = scan.nextInt();
			int[] p = new int[K];
			int[] g = new int[N];
			for (int r = 0; r < R; r++) {
				for (int k = 0; k < K; k++)
					p[k] = scan.nextInt();
				List<Integer> guesses = new ArrayList<Integer>();
				next:
				for (int guess = 0; true; guess++) {
					int temp = guess;
					for (int i = 0; i < N; i++, temp /= (M-1))
						g[i] = (temp % (M-1)) + 2;
					if (temp > 0)
						break;
					
					Arrays.sort(g);
//					for (int i = 0; i < N; i++)
//						temp = temp * (M-1) + g[i] - 2;
//					if (temp != guess) // Not the first one
//						continue;
					
					for (int prod : p) {
						for (int i = N-1; i >= 0; i--)
							if (prod % g[i] == 0)
								prod /= g[i];
						if (prod > 1)
							continue next;
					}
					
					temp = 0;
					for (int i = N-1; i >= 0; i--)
						temp = temp * 10 + g[i];
					guesses.add(temp);
				}
				
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
		String file = "C-small-1";
		in = new BufferedReader( new FileReader(file + ".in") );
		out = new PrintWriter( new FileOutputStream(file + "_" + System.currentTimeMillis() + ".out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}
