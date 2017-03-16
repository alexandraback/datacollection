import java.io.File;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

public class C {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input"));
		 System.setOut(new PrintStream("output"));

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			System.out.print("Case #" + t + ": ");
			int a = in.nextInt(), b = in.nextInt();
			int count = 0;
			for (int i = a; i <= b; i++) {
				HashSet<Integer> set = new HashSet<Integer>();
				char[] x = String.valueOf(i).toCharArray();
				int n = x.length;
				char[] y = new char[n];
				for (int j = 0; j < n; j++)
					if (x[j] != '0') {
						for (int k = 0; k < n; k++)
							y[k] = x[(j + k) % n];
						int k = Integer.parseInt(String.valueOf(y));
						if (set.contains(k))
							continue;
						set.add(k);
						if (k != i && a <= k && k <= b)
							count++;
					}
			}
			System.out.println(count/2);
		}
	}
}
