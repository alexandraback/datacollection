import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int nTests = nextInt();
		for (int test = 1; test <= nTests; test++) {
			int height = nextInt();
			int width = nextInt();
			int[][] a = new int[height][width];
			for (int r = 0; r < height; r++) {
				for (int c = 0; c < width; c++) {
					a[r][c] = nextInt();
				}
			}
			boolean can = solve(a, height, width);
			out.println("Case #" + test + ": " + (can ? "YES" : "NO"));
		}
	}

	private boolean solve(int[][] a, int height, int width) {
		int max = 0;
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				max = Math.max(max, a[r][c]);
			}
		}
		int[][] h = new int[height][width];
		for (int[] arr : h) {
			Arrays.fill(arr, 100);
		}
		for (int i = Math.min(max, 100); i >= 1; i--) {
			for (int r = 0; r < height; r++) {
				boolean can = true;
				for (int c = 0; c < width; c++) {
					if (a[r][c] > i) {
						can = false;
					}
				}
				if (!can) continue;
				for (int c = 0; c < width; c++) {
					h[r][c] = Math.min(h[r][c], i);
				}
			}

			for (int c = 0; c < width; c++) {			
				boolean can = true;
				for (int r = 0; r < height; r++) {
					if (a[r][c] > i) {
						can = false;
					}
				}
				if (!can) continue;
				for (int r = 0; r < height; r++) {
					h[r][c] = Math.min(h[r][c], i);
				}
			}
		}	
		return Arrays.deepEquals(a, h);
	}



	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter(new FileWriter("B-large.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
