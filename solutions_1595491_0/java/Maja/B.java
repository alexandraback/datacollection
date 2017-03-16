package y2012.quals;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B.in"));
		PrintWriter out = new PrintWriter(new File("B.out"));
		int nTestCase = in.nextInt();
		for (int testCase = 0; testCase < nTestCase; testCase++) {
			int n = in.nextInt();
			int s = in.nextInt();
			int p = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = in.nextInt();
			int res = 0;
			int rl = p + p - 1 + p - 1, sl = p + p - 2 + p - 2;
			if (p == 0) {
				rl = 0;
				sl = 0;
			} else if (p == 1)
				sl = 1;
			for (int i = 0; i < n; i++)
				if (a[i] >= rl)
					res++;
				else if (a[i] >= sl && s > 0) {
					res++;
					s--;
				}

			out.println("Case #" + (testCase + 1) + ": " + res);
		}
		in.close();
		out.close();
	}
}
