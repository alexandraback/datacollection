import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	
	private static final int AMASK = 1;
	private static final int BMASK = 2;
	private static final int KMASK = 4;
	
	private static final int BITCOUNT = 31;
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private long solve(int a, int b, int k) {
		a--;
		b--;
		k--;
		long[][] mem = new long[BITCOUNT + 1][8];
		for (int mask = 0; mask < 8; mask++) {
			mem[0][mask] = 1;
		}
		for (int i = 1; i <= BITCOUNT; i++) {
			int p = i - 1;
			for (int mask = 0; mask < 8; mask++) {
				boolean alimit = (mask & AMASK) != 0;
				boolean blimit = (mask & BMASK) != 0;
				boolean klimit = (mask & KMASK) != 0;
				// 1 & 1 == 1
				boolean afit = !alimit || ((a & (1 << p)) != 0);
				boolean bfit = !blimit || ((b & (1 << p)) != 0);
				boolean kfit = !klimit || ((k & (1 << p)) != 0);
				if (afit && bfit && kfit) {
					boolean anewlim = alimit;
					boolean bnewlim = blimit;
					boolean knewlim = klimit;
					int newmask = (anewlim ? AMASK : 0) | (bnewlim ? BMASK : 0) | (knewlim ? KMASK : 0);
					mem[i][mask] += mem[i - 1][newmask];
				}
				// 1 & 0 == 0
				if (afit) {
					boolean anewlim = alimit;
					boolean bnewlim = blimit && ((b & (1 << p)) == 0);
					boolean knewlim = klimit && ((k & (1 << p)) == 0);
					int newmask = (anewlim ? AMASK : 0) | (bnewlim ? BMASK : 0) | (knewlim ? KMASK : 0);
					mem[i][mask] += mem[i - 1][newmask];
				}
				// 0 & 1 == 0
				if (bfit) {
					boolean anewlim = alimit && ((a & (1 << p)) == 0);
					boolean bnewlim = blimit;
					boolean knewlim = klimit && ((k & (1 << p)) == 0);
					int newmask = (anewlim ? AMASK : 0) | (bnewlim ? BMASK : 0) | (knewlim ? KMASK : 0);
					mem[i][mask] += mem[i - 1][newmask];
				}
				// 0 & 0 == 0
				boolean anewlim = alimit && ((a & (1 << p)) == 0);
				boolean bnewlim = blimit && ((b & (1 << p)) == 0);
				boolean knewlim = klimit && ((k & (1 << p)) == 0);
				int newmask = (anewlim ? AMASK : 0) | (bnewlim ? BMASK : 0) | (knewlim ? KMASK : 0);
				mem[i][mask] += mem[i - 1][newmask];
			}
		}
		return mem[BITCOUNT][AMASK | BMASK | KMASK];
	}
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int a = nextInt();
			int b = nextInt();
			int k = nextInt();
			long answer = solve(a, b, k);
			out.println("Case #" + test + ": " + answer);
		}
	}
	
	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
}
