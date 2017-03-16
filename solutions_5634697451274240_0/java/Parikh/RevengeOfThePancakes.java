package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class RevengeOfThePancakes {
	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/B-small-attempt0.in");
		BufferedReader obj = new BufferedReader(fileReader);
		String l = obj.readLine();
		int t = Integer.parseInt(l);
		System.out.println(t);
		PrintWriter write = new PrintWriter(new File("/home/parikh/output.txt"));
		for (int k = 1; k <= t; k++) {
			String s = obj.readLine();
			int n = s.length();
			int arr[] = new int[n];
			int ans = 0;

			for (int i = 0; i < n; i++) {
				if (s.charAt(i) == '+')
					arr[i] = 1;
			}
//			System.out.println("case " + k);
			while (true) {

				int st = -1;
				for (int i = n - 1; i >= 0; i--) {
					if (arr[i] == 0) {
						st = i;
						break;
					}
				}

				if (st == -1) {
					ans += 0;
					break;
				}

				int end = -1;
				for (int i = st; i >= 0; i--) {
					if (arr[i] == 1) {
						end = i;
						break;
					}
				}

				if (end == -1) {
					ans += 1;
					break;
				}
				if (arr[0] == 1) {
					int end2 = -1;
					for (int i = 1; i < n; i++) {
						if (arr[i] == 0) {
							end2 = i - 1;
							break;
						}

					}
					flip(arr, 0, end2);
					ans++;
//					print(arr);
				}

				flip(arr, 0, st);
				ans++;
//				print(arr);
				// break;

			}
			write.println("Case #" + k + ": " + ans);
//			System.out.println(ans);

		}
		obj.close();
		write.close();

	}

	public static void flip(int arr[], int l, int r) {
		while (l < r) {
			int val = arr[l];
			arr[l] = arr[r] ^ 1;
			arr[r] = val ^ 1;
			l++;
			r--;
		}
		if ((r - l + 1) % 2 == 1)
			arr[l] = arr[l] ^ 1;
	}

	public static void print(int arr[]) {
		for (int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

}
