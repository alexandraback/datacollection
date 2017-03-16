import java.io.*;
import java.util.*;

public class Main {
	static Scanner sc;
	static int N;
	static int[] delta_d;
	static int[] delta_p;
	static int[] delta_s;
	static int[] d;
	static int[] n;
	static int[] w;
	static int[] e;
	static int[] s;
	static int maxD = 110000;
	static int[] h = new int[maxD * 2];
	static boolean[] days = new boolean[1000000];
	static boolean[] free = new boolean[1001];

	static int work() {
		Arrays.fill(h, 0);
		int count = 0;
		int dN = 0;
		while (true) {
			while (dN < days.length && days[dN] == false) {
				++dN;
			} // Find the next attack day
			if (dN == days.length) {
				break;
			}
			Arrays.fill(free, false);
			for (int i = 0; i < N; ++i) {
				if (dN == d[i] && n[i] > 0) {
					for (int j = w[i] + 1; j <= e[i]; ++j) {
						if (s[i] > h[j]) {
							free[i] = true;
							count += 1;
							break;
						}
					}
				}
			}
			for (int i = 0; i < N; ++i) {
				if (free[i]) {

					for (int j = w[i] + 1; j <= e[i]; ++j) {
						if (s[i] > h[j]) {
							h[j] = s[i];
						}
					}
				}
				if (dN == d[i] && n[i] > 0) {
					d[i] += delta_d[i];
					days[d[i]] = true;
					--n[i];
					w[i] += delta_p[i];
					e[i] += delta_p[i];
					s[i] += delta_s[i];
				}
			}
			++dN;
		}
		return count;
	}

	static String solve() {
		N = sc.nextInt();
		d = new int[N];
		n = new int[N];
		w = new int[N];
		e = new int[N];
		s = new int[N];
		delta_d = new int[N];
		delta_p = new int[N];
		delta_s = new int[N];
		Arrays.fill(days, false);
		for (int i = 0; i < N; ++i) {
			d[i] = sc.nextInt();
			days[d[i]] = true;
			n[i] = sc.nextInt();
			w[i] = sc.nextInt() + maxD;
			e[i] = sc.nextInt() + maxD;
			s[i] = sc.nextInt();
			delta_d[i] = sc.nextInt();
			delta_p[i] = sc.nextInt();
			delta_s[i] = sc.nextInt();
		}
		int answer = work();

		return String.valueOf(answer);
	}

	public static void main(String args[]) throws Exception {

		sc = new Scanner(System.in);

		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				new FileOutputStream("output.txt")));
		int k = sc.nextInt();
		for (int i = 0; i < k; i++) {
			String ans = "Case #" + (i + 1) + ": " + solve();
			System.out.println(ans);
			bw.write(ans);
			bw.newLine();
		}
		sc.close();
		bw.close();

	}
}