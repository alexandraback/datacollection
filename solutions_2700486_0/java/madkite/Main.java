import java.io.*;
import java.util.concurrent.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class Main extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(new SolutionFactory<Object>() {
			public Callable<Object> read(BufferedReader br) throws IOException {
				String[] ss = br.readLine().split(" ");
				assert ss.length == 3;
				int n = Integer.parseInt(ss[0]);
				int x = Integer.parseInt(ss[1]);
				int y = Integer.parseInt(ss[2]);
				return new Main(n, x, y);
			}
		}, "google/src/gcj2013r1b/" + "B-small-attempt5.in");
	}
	private final int n, x, y;
	public Main(int n, int x, int y) {
		this.n = n;
		this.x = x;
		this.y = y;
	}
	public String call() throws Exception {
		return Double.toString(solve());
	}
	private double solve() {
		int s = Math.abs(x) + y;
		int max = ((s + 1) * (s + 1) + (s + 1)) / 2;
		int min = ((s - 1) * (s - 1) + (s - 1)) / 2;
		//System.out.println(n + "/" + x + "/" + y + ": " + max + "/" + min + " (" + s + ")");
		if(n >= max)
			return 1.;
		if(n <= min || x == 0)
			return 0.;
		int c = n - min;
		if(c >= s + y + 1)
			return 1.;
		long d = 0;
		for(int i = y + 1; i <= n - min; i++)
			d += Utils.c(n - min, i);
		//System.out.println(d + "/" + Math.pow(2, n - min));
		return d / Math.pow(2, n - min);
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
abstract class Utils {

	public static long c(int n, int k) {
		if(k > n)
			return 0;
		k = Math.max(k, n - k);
		long r = 1, max = Long.MAX_VALUE / n;
		for(int i = k + 1; i <= n; i++) {
			if((r *= i) > max)
				return c(n - 1, k) + c(n - 1, k - 1);
		}
		for(int i = n - k; i > 1; i--)
			r /= i;
		return r;
	}
}
