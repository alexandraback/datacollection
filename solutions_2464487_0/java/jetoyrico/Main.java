import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tc/input.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tc/output.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
	    long r = in.nextLong();
	    long t = in.nextLong();
	    long start = r * 2 + 1;
	    long low = 0, high = (long) 1e18;
	    for (int loop = 0; loop < 1000; ++loop) {
		    long mid = (low + high) / 2;
		    double sum = 1.0 * mid * (2.0 * start + (mid - 1) * 4.0) / 2.0;
		    if (sum < t) low = mid;
		    else high = mid;
	    }
	    for (long n = high; n >= 1; --n) {
		    if (n * (2 * start + (n - 1) * 4) / 2 <= t) {
	            out.print(String.format("Case #%d: %d\n", testNumber, n));
			    break;
		    }
	    }
    }
}

