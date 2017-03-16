import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public class C {

	//	final static String FILE_NAME = "C-test";
	final static String FILE_NAME = "C-small-attempt1";
//	final static String FILE_NAME = "C-large";

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
		Map<String, Integer> a = new HashMap<>();
		Map<String, Integer> b = new HashMap<>();
		List<String> la = new ArrayList<>();
		List<String> lb = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			String x = in.next();
			if (!a.containsKey(x)) {
				a.put(x, 0);
			} else {
				a.put(x, a.get(x) + 1);
			}
			la.add(x);

			String y = in.next();
			if (!b.containsKey(y)) {
				b.put(y, 0);
			} else {
				b.put(y, b.get(y) + 1);
			}
			lb.add(y);
		}

		int res = 0;

		for (int i = 0; i < n; i++) {
			String sa = la.get(i);
			String sb = lb.get(i);
			int ca = a.get(sa);
			int cb = b.get(sb);
			if (ca > 0 && cb > 0) {
				res++;
				a.put(sa, ca - 1);
				b.put(sb, cb - 1);
			}
		}
		out.format("Case #%d: %s\n", tc, res);
		System.out.format("Case #%d: %s\n", tc, res);
	}
}
