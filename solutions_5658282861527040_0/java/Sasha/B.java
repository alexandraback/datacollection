import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int k = in.nextInt();

			long count = 0;
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++) {
					if ((i & j) < k)
						count++;
				}

			out.println("Case #" + test + ": " + count);
		}
	}
}
