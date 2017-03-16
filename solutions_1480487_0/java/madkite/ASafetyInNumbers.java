package gcj2012r1b;

import java.io.*;
import java.util.concurrent.*;

import com.google.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class ASafetyInNumbers extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(new SolutionFactory<Object>() {
			public Callable<Object> read(BufferedReader br) throws IOException {
				String ss[] = br.readLine().split(" ");
				int n = Integer.parseInt(ss[0]);
				assert ss.length == n + 1;
				int[] a = new int[n];
				for(int i = 0; i < n; i++)
					a[i] = Integer.parseInt(ss[1 + i]);
				return new ASafetyInNumbers(a);
			}
		}, "google/src/gcj2012r1b/" + "A-small-attempt2.in");
	}
	private final int[] a;
	public ASafetyInNumbers(int[] a) {
		this.a = a;
	}
	public String call() throws Exception {
		StringBuilder result = new StringBuilder();
		for(double d : solve())
			result.append(' ').append(d);
		return result.substring(1);
	}
	private double[] solve() {
		double[] result = new double[a.length];
		int sum = 0;
		for(int i = 0; i < a.length; i++)
			sum += a[i];
		int n = a.length, s = sum;
		double m = (double)(sum + s) / n;
		for(int i = 0; i < a.length; i++) {
			if(m - a[i] < 0) {
				n--;
				s -= a[i];
			}
		}
		m = (double)(sum + s) / n;
		for(int i = 0; i < a.length; i++)
			result[i] = Math.max(0, 100. * (m - a[i]) / sum);
		return result;
	}
}
