

package codejam2016;

import java.io.File;
import java.util.Scanner;


public class Rank {

	private static boolean DEBUG = false;


	private int[][] convert(int N, String[] list) {

		int n2 = list.length;
		int[][] data = new int[n2][N];


		for (int i = 0; i < n2; i++) {
			String s = list[i];

			String[] tmp = s.split(" ");

			for (int j = 0; j < tmp.length; j++)
				data[i][j] = Integer.parseInt(tmp[j]);
		}

		return data;
	}


	private String solve(int N, String[] list) {

		int[][] data = convert(N, list);

		int[] counter = new int[2501];

		int n2 = list.length;
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < N; j++) {

				int x = data[i][j];
				counter[x]++;
			}
		}

		String ans = "";
		for (int i = 1; i < counter.length; i++) {
			if (counter[i] % 2 == 1) {
				ans = ans + " " + i;
			}
		}

		return ans.trim();
	}

	private void solve(Scanner sc) {
		int T = sc.nextInt();

		for (int i = 0; i < T; i++) {
			int N = sc.nextInt();
			sc.nextLine();

			int n2 = N*2 - 1;

			String[] list = new String[n2];

			for (int j = 0; j < n2; j++) {
				String r = sc.nextLine();

				if (DEBUG)
					System.out.format(" data: %s\n", r);

				list[j] = r;
			}

			String ans = solve(N, list);
			System.out.format("Case #%d: %s\n", i+1, ans);
		}
	}

	public static void main(String[] args) throws Exception {

		Scanner sc = null;

		Rank rank = new Rank();

		if (args.length == 1) {
			sc = new Scanner(new File(args[0]));

			//DEBUG = false;

			rank.solve(sc);
		}
	}
}
