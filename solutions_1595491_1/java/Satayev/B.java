import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input"));
		 System.setOut(new PrintStream(new File("output")));

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			System.out.print("Case #" + t + ": ");
			int n = in.nextInt();
			int s = in.nextInt();
			int p = in.nextInt();
			int count = 0;
			for (int i = 0; i < n; i++) {
				int points = in.nextInt();
				 int q = points / 3;
				 int r = points % 3;
				 if (q + (r > 0 ? 1 : 0) >= p) {
				 count++;
				 }
				 else if (q + (r > 0 ? r : q > 0 ? 1 : 0) >= p && s > 0) {
				 s--;
				 count++;
				 }
			}
			System.out.println(count);
		}
	}
}

/*
 * 3 ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym
 * veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv
 * 
 * Case #1: our language is impossible to understand Case #2: there are twenty
 * six factorial possibilities Case #3: so it is okay if you want to just give
 * up
 */
