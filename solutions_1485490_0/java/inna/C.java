import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class C {

    final static String PREFIX = "C:\\codejam\\C";
//    final static String FILE_NAME = PREFIX + "-test";
        final static String FILE_NAME = PREFIX + "-small-attempt0";
    //    final static String FILE_NAME = PREFIX + "-large";

    private Scanner in;
    private PrintWriter out;

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        new C().solveAll();
    }

    private void solveAll() throws Exception {
		in = new Scanner(new File(FILE_NAME + ".in"));
		out = new PrintWriter(new File(FILE_NAME + ".out"));
        int tcn = in.nextInt();
        for (int tc = 1; tc <= tcn; tc++) {
            solve(tc);
        }
        out.close();
    }

    private void solve(int tc) {
		int n = in.nextInt();
		int m = in.nextInt();

		long[] boxNo = new long[n];
		long[] boxType = new long[n];
		for (int i = 0; i < n; i++) {
			boxNo[i] = in.nextLong();
			boxType[i] = in.nextLong();
		}

		long[] toyNo = new long[m];
		long[] toyType = new long[m];
		for (int i = 0; i < m; i++) {
			toyNo[i] = in.nextLong();
			toyType[i] = in.nextLong();
		}

		long res = doit(0, 0, boxNo, boxType, toyNo, toyType, 0);

		out.format("Case #%d: %s\n", tc, res);
		System.out.format("Case #%d: %s\n", tc, res);
	}

	private long doit(int bi, int ti, long[] boxNo, long[] boxType, long[] toyNo, long[] toyType, long res) {
		boxNo = Arrays.copyOf(boxNo, boxNo.length);
		toyNo = Arrays.copyOf(toyNo, toyNo.length);
		while (bi < boxNo.length && ti < toyNo.length)
			if (boxType[bi] == toyType[ti]) {
				if (boxNo[bi] < toyNo[ti]) {
					res += boxNo[bi];
					toyNo[ti] -= boxNo[bi];
					boxNo[bi] = 0;
					if (bi < boxNo.length) {
						bi++;
					}
				} else {
					res += toyNo[ti];
					boxNo[bi] -= toyNo[ti];
					toyNo[ti] = 0;
					if (ti < toyNo.length) {
						ti++;
					}
				}
				if (bi == boxNo.length || ti == toyNo.length) {
					return res;
				}
			} else {
				res = Math.max(doit(bi + 1, ti, boxNo, boxType, toyNo, toyType, res),
						doit(bi, ti + 1, boxNo, boxType, toyNo, toyType, res));
				return res;
			}
		return res;
	}
}
