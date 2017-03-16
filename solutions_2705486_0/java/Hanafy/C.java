import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	static String[] dict;
	static char[] str;
	static int[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(
				new FileReader(
						"L:\\Work Space\\Eclipse WorkSpace\\Code Jam\\src\\garbled_email_dictionary.txt"));
		dict = new String[521196];
		String s;
		int A = 0;
		while ((s = br.readLine()) != null) {
			dict[A++] = s;
		}
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int I = 1; I <= T; I++) {
			str = in.next().toCharArray();
			dp = new int[str.length][str.length + 200];
			for (int i = 0; i < dp.length; i++)
				Arrays.fill(dp[i], -1);

			int min = solve(0, -100);
			System.out.printf("Case #%d: %d\n", I, min);
		}
	}

	private static int solve(int idx, int last) {
		if (idx == str.length)
			return 0;
		if (dp[idx][last + 100] != -1)
			return dp[idx][last + 100];
		else {
			int min = 1 << 25;
			Loop: for (int j = 0; j < dict.length; j++) {
				String s = dict[j];
				if (s.length() + idx <= str.length) {
					int L = last, cnt = 0;
					for (int i = 0; i < s.length(); i++)
						if (s.charAt(i) != str[idx + i]) {
							if ((idx + i) - L < 5)
								continue Loop;
							cnt++;
							L = idx + i;
						}

					min = Math.min(min, cnt + solve(idx + s.length(), L));
				}
			}
			return dp[idx][last + 100] = min;
		}
	}
}
