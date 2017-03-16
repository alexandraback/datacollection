import java.io.*;
import java.util.concurrent.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class Main extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(new SolutionFactory<Object>() {
			public Callable<Object> read(BufferedReader br) throws IOException {
				String[] ss = br.readLine().split("\\s+");
				int n = Integer.parseInt(ss[0]), m = Integer.parseInt(ss[1]);
				int[][] lawn = new int[n][m];
				for(int i = 0; i < n; i++) {
					ss = br.readLine().split("\\s+");
					for(int j = 0; j < m; j++)
						lawn[i][j] = Integer.parseInt(ss[j]);
				}
				return new Main(lawn);
			}
		}, "google/src/gcj2013qr/" + "B-small-attempt0.in");
	}
	private final int[][] lawn;
	public Main(int[][] lawn) {
		this.lawn = lawn;
	}
	public String call() throws Exception {
		return solve() ? "YES" : "NO";
	}
	private boolean solve() {
		int n = lawn.length, m = lawn[0].length;
		int[] maxh = new int[n], maxv = new int[m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				maxh[i] = Math.max(maxh[i], lawn[i][j]);
				maxv[j] = Math.max(maxv[j], lawn[i][j]);
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(lawn[i][j] < maxh[i] && lawn[i][j] < maxv[j])
					return false;
			}
		}
		return true;
	}
}
interface SolutionFactory<V> {
	Callable<V> read(BufferedReader br) throws IOException;
}
abstract class SingleThreadSolution<V> implements Callable<V> {
	protected static void solve(SolutionFactory factory, String input) throws Exception {
		String output = null;
		if(input.endsWith(".in"))
			output = input.substring(0, input.length() - 2) + "out";
		solve(factory, input, output);
	}
	protected static void solve(SolutionFactory factory, String input, String output) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(input));
		if(output != null)
			System.setOut(new PrintStream(output));
		solve(factory, br);
	}
	protected static void solve(SolutionFactory factory, BufferedReader br) throws Exception {
		long time = System.currentTimeMillis();
		int t = Integer.parseInt(br.readLine());
		for(int i = 0; i < t; i++)
			System.out.println("Case #" + (i + 1) + ": " + factory.read(br).call());
		time = System.currentTimeMillis() - time;
		Thread.sleep(100);
		System.err.println(time);
	}
}
