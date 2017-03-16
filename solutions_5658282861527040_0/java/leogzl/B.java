import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	public final static String IN_FILE = "B.in";
	public final static String OUT_FILE = "B.out";

	private static Scanner IN;

	public static void main(String[] args) throws Exception {
		InputStream in = new FileInputStream(IN_FILE);
		PrintWriter out = new PrintWriter(new FileWriter(OUT_FILE));
		IN = new Scanner(in);

		int T = IN.nextInt();
		IN.nextLine();
		for (int t = 1; t <= T; t++) {
			int A = IN.nextInt();
			int B = IN.nextInt();
			int K = IN.nextInt();

			int tt = 0;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < B; j++) {
					int M = i & j;
					if (M < K) {
						tt++;
					}
				}
			}

			out.println("Case #" + t + ": " + tt);
		}

		out.flush();
		out.close();
		in.close();
	}
}
