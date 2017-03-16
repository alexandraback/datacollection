package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class B_1C {

	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/B-small-attempt1(1)C.in");
		BufferedReader obj = new BufferedReader(fileReader);
		PrintWriter write = new PrintWriter(new File("/home/parikh/output.txt"));
		String l = obj.readLine();
		int t = Integer.parseInt(l);
		for (int k = 1; k <= t; k++) {
			System.out.println("k  " + k );

			String inp = obj.readLine();
			String str[] = inp.split(" ");
			int b = Integer.parseInt(str[0]);
			long m = Integer.parseInt(str[1]);
			System.out.println(" b " + b +" m  " +m);
			long arr[] = new long[b + 1];
			int ans[][] = new int[b + 1][b + 1];
			if (b == 2) {
				if (m != 1)
					write.println("Case #" + k + ": " + "IMPOSSIBLE");
				else {
					write.println("Case #" + k + ": " + "POSSIBLE");
					write.println("0 1");
					write.println("0 0");

				}
				continue;
			}
			arr[b - 1] = 1;
			for (int i = b - 2; i >= 2; i--) {
				arr[i] = 2 * arr[i + 1];
				System.out.println(i + " " + arr[i]);
			}

			long v = 2 * arr[2];
			System.out.println(v);
			if (m > v) {
				write.println("Case #" + k + ": " + "IMPOSSIBLE");
				continue;
			}

			if (v == m) {
				for (int i = 1; i <= b; i++) {
					for (int j = i + 1; j <= b; j++)
						ans[i][j] = 1;

				}
			} else {
				int a[] = new int[b + 1];
				v = v / 2;
				System.out.println(v);
				for (int i = 2; i <= b - 1; i++) {
					if (arr[i] <= m) {
						a[i] = 1;
						m -= arr[i];
					}
				}
				for (int i = 1; i <= b; i++)
					System.out.print(a[i] + " ");
				System.out.println();
				int min = -1;
				for (int i = 2; i <= b - 1; i++) {
					if (a[i] == 1) {
						min = i;
						break;
					}

				}

				for (int i = min; i <= b; i++) {
					if (a[i] == 1)
						ans[1][i] = 1;
				}

				for (int i = min; i <= b; i++) {
					for (int j = i + 1; j <= b; j++)
						ans[i][j] = 1;
				}

			}

			write.println("Case #" + k + ": " + "POSSIBLE");
			for (int i = 1; i <= b; i++) {
				for (int j = 1; j <= b; j++) {
					write.print(ans[i][j] + " ");
				}
				write.println();
			}

		}
		write.close();
	}

}
