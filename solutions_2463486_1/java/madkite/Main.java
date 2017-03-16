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
		}, "google/src/gcj2013qr/" + "C-large-1.in");
	}
	private final long lo, hi;
	public Main(long lo, long hi) {
		this.lo = lo;
		this.hi = hi;
	}
	public String call() throws Exception {
		int result = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] >= lo && a[i] <= hi)
				result++;
		}
		return Long.toString(result);
	}
	private static byte[] temp = new byte[100];
	public static boolean isPalindrome(long n, boolean s) {
		int i;
		for(i = 0; n > 0; i++) {
			byte digit = (byte)(n % 10);
			if(s && digit > 2)
				return false;
			temp[i] = digit;
			n /= 10;
		}
		for(int j = 0; j < i / 2; j++)
			if(temp[j] != temp[i - j - 1])
				return false;
		return true;
	}
	private static long a[] = new long[100];
	private static int n = 0;
	static {
		for(long i = 1;; i++) {
			long i2 = i * i;
			if(i2 > 1e14)
				break;
			if(i2 < 1e13) {
				if(!isPalindrome(i, false))
					continue;
			} else {
				if(!isPalindrome(i, true))
					continue;
			}
			if(!isPalindrome(i2, false))
				continue;
			a[n++] = i2;
			//System.out.println(n + ": " + i + " / " + i2);
		}
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
