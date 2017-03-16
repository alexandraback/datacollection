package cj2012.OneB;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws Exception {
		String fileName = "C-small-attempt0";
		Scanner scan = new Scanner(new File("in/" + fileName + ".in"));
		int T = scan.nextInt(); scan.nextLine();
		PrintWriter out = new PrintWriter(new File("out/" + fileName + ".txt"));
		for (int z = 1; z <= T; z++) {
			int N = scan.nextInt();
			int[] a = new int[N];
			for (int i = 0; i < N; i++)
				a[i] = scan.nextInt();
			int[] map = new int[20 * 100 * 1000 + 5];
			Arrays.fill(map, -1);
			out.println("Case #" + z + ":");
			for (int i = 0; i < (1<<20); i++) {
				int sum = 0;
				for (int j = 0; j < 20; j++)
					if ((i & (1 << j)) > 0)
						sum += a[j];
				if (map[sum] != -1) {
					for (int j = 0, k = 0; j < 20; j++) {
						if ((map[sum] & (1 << j)) > 0)
							out.print((k++ > 0? " " : "") + a[j]);
					}
					out.println();
					for (int j = 0, k = 0; j < 20; j++) {
						if ((i & (1 << j)) > 0)
							out.print((k++ > 0? " " : "") + a[j]);
					}
					out.println();
					N = 0;
					break;
				}
				map[sum] = i;
			}
			if (N > 0)
				out.println("Impossible");
		}
		out.close();
	}
}
