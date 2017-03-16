import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class C {
	// public final static String IN_FILE = "C.in";
	// public final static String OUT_FILE = "C.out";

	public final static String IN_FILE = "C-small-attempt1.in";
	public final static String OUT_FILE = "C-small-attempt1.out";

	private static Scanner IN;

	public static void main(String[] args) throws Exception {
		InputStream in = new FileInputStream(IN_FILE);
		PrintWriter out = new PrintWriter(new FileWriter(OUT_FILE));
		IN = new Scanner(in);

		int T = IN.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = IN.nextInt();
			int m = IN.nextInt();

			int l = 0;
			int k = 1;
			while (k <= n) {
				k *= 10;
				l++;
			}
			k /= 10;

			int c = 0;
			for (int i = n; i <= m; i++) {
				Set<Integer> p = new TreeSet<Integer>();
				int s = i;
				for (int j = 0; j < l; j++) {
					int r = s / 10 + (s % 10) * k;
					if (r > i && r <= m) {
						p.add(r);
					}
					s = r;
				}
				c += p.size();
			}
			out.println("Case #" + t + ": " + c);
		}

		out.flush();
		out.close();
		in.close();
	}
}
