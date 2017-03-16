
import java.io.*;
import java.util.*;

public class A {
	int getInt(BufferedReader in) throws IOException {
		return Integer.parseInt(in.readLine());
	}   
	long getLong(BufferedReader in) throws IOException {
		return Long.parseLong(in.readLine());
	}   
	long rev(long n) {
		long r = 0;
		while (n > 0) {
			r = 10 * r + (n % 10);
			n /= 10;
		}
		return r;
	}

	long pow(long a, long b) {
		long r = 1;
		while (b > 0) {
			if ((b&1) == 1) r *= a;
			a = a * a;
			b >>= 1;
		}
		return r;
	}

	long fast(long N) {
		if (N < 20) return N;
		long r = 10;
		for (int p = 2 ;; p++) {
			if (pow(10, p) <= N) {
				long med = pow(10, p-1) + pow(10, (p+1)/2)-1;
				r += med - pow(10, p-1) + 1;
				r += pow(10, p) - rev(med);
			} else {
				long best = r + N - pow(10, p-1);
				for (int c = 1 ; c < p ; c++) {
					long med = pow(10, p-1) + rev(N) % pow(10, c);
					if (med > N) break;
					long val = r + med - pow(10, p-1) + 1 + N - rev(med);
					best = Math.min(best, val);
				}
				return best;
			}
		}
	}

	void run(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
		    PrintStream out = new PrintStream(args[0] + ".out");
			int CASES = getInt(in);
			for (int CASE = 1 ; CASE <= CASES ; CASE++) {
				long N = getLong(in);
				out.printf("Case #%d: %d\n", CASE, fast(N));
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public static void main (String[] args) {
		new A().run(args);
	}
}
