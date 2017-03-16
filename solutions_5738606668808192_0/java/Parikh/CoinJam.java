package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class CoinJam {
	public static int done = 0;
	public static int num = 0;
	// public static int possible = 0;
	public static long mult[][] = new long[11][16];
	public static String[][] ans = new String[51][10];

	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/C-small-attempt0.in");
		BufferedReader obj = new BufferedReader(fileReader);
		String l = obj.readLine();
		int t = Integer.parseInt(l);
		System.out.println(t);
		PrintWriter write = new PrintWriter(new File("/home/parikh/output.txt"));
		for (int i = 2; i <= 10; i++)
			mult[i][0] = 1;
		for (int i = 2; i <= 10; i++) {
			for (int j = 1; j < mult[0].length; j++) {
				mult[i][j] = mult[i][j - 1] * i;
			}
		}

		for (int k = 1; k <= t; k++) {
			l = obj.readLine();
			String sp[] = l.split(" ");
			int N = Integer.parseInt(sp[0]);
			int J = Integer.parseInt(sp[1]);
			num = J;
			int arr[] = new int[N];
			System.out.println(N + " " + J);
			arr[0] = 1;
			arr[N - 1] = 1;
			rec(arr, 1);
			write.println("Case #" + k + ":");
			for (int i = 1; i < ans.length; i++) {
				for (int j = 0; j < ans[0].length; j++) {
					write.print(ans[i][j] + " ");
				}
				write.println();
			}
		}
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				System.out.print(ans[i][j] + " ");
			}
			// System.out.println(possible);
		}
		obj.close();
		write.close();

	}

	public static void rec(int arr[], int idx) {
		if (done == num)
			return;
		if (idx == arr.length)
			return;
		if (idx == arr.length - 1) {
			// for (int j = 0; j < arr.length; j++) {
			// System.out.print(arr[j] + " ");
			// }
			// System.out.println(idx);
			String s[] = new String[10];
			s[0] = getString(arr);
			boolean val = true;
			for (int i = 2; i <= 10; i++) {
				long v = getValue(arr, i);
				// System.out.println(i+" "+v);
				long divisor = getDivisor(v);
				if (divisor == -1) {
					val = false;
					break;
				}
				s[i - 1] = "" + divisor;

			}

			if (val) {
				done++;
				// possible++;
				// System.out.println(done +" "+ s[0] +" " + getValue(arr, 2));
				// if (done<=num)
				ans[done] = s;
			}
		}

		for (int i = 0; i <= 1; i++) {
			arr[idx] = i;
			rec(arr, idx + 1);
		}
	}

	public static long getDivisor(long num) {
		if (num % 2 == 0)
			return 2;

		for (long i = 3; i * i <= num; i += 2) {
			if (num % i == 0)
				return i;
		}
		return -1l;
	}

	public static long getValue(int arr[], int base) {
		long val = 0;
		int n = arr.length - 1;
		for (int i = 0; i <= n; i++) {
			val += arr[i] * mult[base][n - i];
		}
		return val;
	}

	public static String getString(int arr[]) {
		String s = "";
		int n = arr.length - 1;
		for (int i = 0; i <= n; i++) {
			s += arr[i];
		}
		return s;
	}

}
