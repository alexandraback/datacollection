package y2012.quals;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter(new File("C.out"));
		int nTestCase = Integer.parseInt(in.nextLine());
		int[] stepeni = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
				100000000 };
		for (int testCase = 0; testCase < nTestCase; testCase++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int res = a - 1;
			int brCif = 0;
			while (res > 0) {
				brCif++;
				res /= 10;
			}
			HashSet<Integer> hs = new HashSet<Integer>();
			for (int i = a; i <= b; i++) {
				if (i == stepeni[brCif])
					brCif++;
				int tmp = i;
				for (int j = 1; j < brCif; j++) {
					tmp = (tmp % 10) * stepeni[brCif - 1] + tmp / 10;
					if (i < tmp && tmp <= b && !hs.contains(tmp)) {
						res++;
						hs.add(tmp);
					}
				}
				hs.clear();
			}
			out.println("Case #" + (testCase + 1) + ": " + res);
		}
		in.close();
		out.close();
	}

}
