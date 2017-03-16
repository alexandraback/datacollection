import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemB {
	public static void main(String[] args) throws Exception {

		Scanner in = new Scanner(
		// System.in
		// new FileInputStream("b-small.in")
				new FileInputStream("b-large.in"));
		PrintStream out = new PrintStream(
		// System.out
		// new FileOutputStream("b-small.out")
				new FileOutputStream("b-large.out"));
		int T = in.nextInt();
		in.nextLine();

		for (int i = 1; i <= T; i++) {
			int res = 0;
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();
			int[] ts = new int[N];
			for (int j = 0; j < N; j++)
				ts[j] = in.nextInt();
			in.nextLine();
			Arrays.sort(ts);

			int nscore = Math.max(p * 3 - 2, p);
			int sscore = Math.max(p * 3 - 4, p);

			for (int j = N; --j >= 0;) {
				if (ts[j] >= nscore)
					res++;
				else if (ts[j] >= sscore && S-- > 0)
					res++;
				else
					break;
			}
			out.println("Case #" + i + ": " + res);
		}
	}
}
