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
 * @author Prabu
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("IO/B-small-attempt1.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("IO/B-small-attempt1.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		CJ2012QR_Dancing solver = new CJ2012QR_Dancing();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class CJ2012QR_Dancing {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt();
        int S = in.nextInt();
        int p = in.nextInt();
        int ti, base, remainder;
        int result = 0;

        for(int i = 0; i < N; i++) {
            ti = in.nextInt();
            base = ti / 3;
            if(base >= p) {
                result++;
                continue;
            }

            remainder = ti % 3;
            if(remainder > 0 && (base+1) >= p) {
                result++;
                continue;
            }

            remainder = (remainder == 0 && ti != 0)? 1: remainder;
            if(S > 0 && (base+remainder) >= p) {
                S--;
                result++;
                continue;
            }
        }
        out.printf("Case #%d: %d\n", testNumber, result);
	}
}

