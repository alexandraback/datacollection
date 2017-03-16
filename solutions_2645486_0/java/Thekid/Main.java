import java.io.*;
import java.util.*;

public class Main {
	private static boolean _WRITE_TO_FILE = true;
	private static String _INPUT_FILE = "B-small-attempt0.in";
	private static String _OUTPUT_FILE = "out.txt";
	private static Scanner in;
	private static void core() {
		int ntest = in.nextInt();
		for (int test = 0; test < ntest; test++) {
			writeCase(test);
			int maxEnergy = in.nextInt();
			int regainEnergy = in.nextInt();
			int n = in.nextInt();
			int[] value = new int[n];
			for (int i = 0; i < value.length; i++) {
				value[i] = in.nextInt();
			}
			regainEnergy = Math.min(regainEnergy, maxEnergy);
			long res = solve(maxEnergy, regainEnergy, value);
			System.out.println(res);
			System.out.flush();
		}
	}
	private static long solve(int maxEnergy, int regainEnergy, int[] value) {
		long[][] best = new long[value.length + 1][maxEnergy + 1];
		for (int i = 0; i < value.length; i++) {
			for (int energy = 0; energy < best[i].length; energy++) {
				for (int spent = 0; spent <= energy; spent++) {
					long now = best[i][energy] + spent * (long) value[i];
					int nextEnergy = (energy - spent) + regainEnergy;
					nextEnergy = Math.min(maxEnergy, nextEnergy);
					best[i + 1][nextEnergy] = Math.max(best[i + 1][nextEnergy], now);
				}
			}
		}
		long max = 0;
		for (int i = 0; i < best[value.length].length; i++) {
			max = Math.max(max, best[value.length][i]);
		}
		return best[value.length][regainEnergy];
	}
	private static void writeCase(int test) {
		System.out.printf("Case #%d: ", test+1);
	}
	static void debug(Object...os) {
		System.out.println(Arrays.deepToString(os));
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(_INPUT_FILE));
		if (_WRITE_TO_FILE) 
			System.setOut(new PrintStream(new BufferedOutputStream(
					new FileOutputStream(_OUTPUT_FILE))));
		in = new Scanner(System.in);
		core();
		System.out.close();
	}
	static class Scanner {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public Scanner(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
			tokenizer = new StringTokenizer("");
		}
		public String next() {
			try {
				while(!tokenizer.hasMoreElements())
					tokenizer = new StringTokenizer(reader.readLine());
				return tokenizer.nextToken();
			} catch (Exception e) {
				e.printStackTrace();
				throw new RuntimeException(e);
			}
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
