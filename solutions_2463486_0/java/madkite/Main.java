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
				assert ss.length == 2;
				return new Main(Long.parseLong(ss[0]), Long.parseLong(ss[1]));
			}
		}, "google/src/gcj2013qr/" + "C-small-attempt0.in");
	}
	private final long lo, hi;
	public Main(long lo, long hi) {
		this.lo = lo;
		this.hi = hi;
	}
	public String call() throws Exception {
		long result = 0;

		for(long i = 0;; i++) {
			long i2 = i * i;
			if(i2 > hi)
				break;
			if(!isPalindrome(i))
				continue;
			if(!isPalindrome(i2))
				continue;
			if(i2 >= lo && i2 <= hi)
				result++;
		}
		return Long.toString(result);
	}
	private byte[] a = new byte[100];
	public boolean isPalindrome(long n) {
		int i;
		for(i = 0; n > 0; i++) {
			a[i] = (byte)(n % 10);
			n /= 10;
		}
		for(int j = 0; j < i / 2; j++)
			if(a[j] != a[i - j - 1])
				return false;
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
