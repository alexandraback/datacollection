import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class ReordringTrainCars {
	static ArrayList<Integer> list[];
	static ArrayList<Integer> rev[];
	static int max;
	static long dp[][];

	public static long go(int map, int i) {
		// System.out.println(map + " " + i);
		if (map == max)
			return 1;
		if (dp[map][i] != -1)
			return dp[map][i];
		long ans = 0;
		boolean found = false;
		for (int next : list[i]) {
			if ((map & (1 << next)) == 0) {
				ans += go((map | (1 << next)), next) % 1000000007;
				found = true;
			}

		}
		if (!found) {

			for (int j = 0; j < list.length; j++) {
				if ((map & (1 << j)) == 0) {
					boolean can = true;
					ArrayList<Integer> li = list[j];
					for (int in : li) {
						if ((map & (1 << in)) != 0) {
							can = false;
							break;
						}
					}
					if (can && !(list[i].size() == 0 && rev[i].size() != 0)) {
						System.out.println(map + " " + i + " " + j);
						ans += go((map | (1 << j)), j) % 1000000007;
					}
				}
			}
		}
		return dp[map][i] = ans % 1000000007;
	}

	static boolean v[];
	static String st[];

	// public static void dfs(String s, int i) {
	// // System.out.println(i + " " + s);
	// if (i == st.length) {
	// System.out.println(s);
	// } else {
	// for (int j = 0; j < st.length; j++)
	// if (!v[j]) {
	// v[j] = true;
	// String ss = s + st[j];
	// dfs(ss, i + 1);
	// v[j] = false;
	// }
	// }
	// }

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		String outfile = "out.txt";
		BufferedReader reader = new BufferedReader(new FileReader("test.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outfile));
		int x = Integer.parseInt(reader.readLine());
		for (int cas = 1; cas <= x; cas++) {
			int n = Integer.parseInt(reader.readLine());
			list = new ArrayList[n];
			rev = new ArrayList[n];
			for (int i = 0; i < list.length; i++) {
				list[i] = new ArrayList<Integer>();
				rev[i] = new ArrayList<Integer>();
			}
			st = reader.readLine().split(" ");
			v = new boolean[st.length];
			int cc[] = new int[512];
			ArrayList<Character> l = new ArrayList<Character>();
			for (int i = 0; i < st.length; i++) {
				for (int j = 0; j < st.length; j++)
					if (i != j) {
						if (st[i].charAt(st[i].length() - 1) == st[j].charAt(0)) {
							list[i].add(j);
							rev[j].add(i);
						}
					}
				if (st[i].length() > 2) {
					for (int k = 1; k < st[i].length() - 1; k++)
						if (st[i].charAt(k) != st[i].charAt(0)
								&& st[i].charAt(k) != st[i].charAt(st[i]
										.length() - 1))
							l.add(st[i].charAt(k));
				}
				for (int k = 0; k < st[i].length(); k++)
					cc[st[i].charAt(k) - 'a']++;
			}
			boolean cont = true;

			for (char c : l) {
				int co = 0;
				for (String s : st)
					if (s.contains(c + "")) {
						co++;
					}
				if (co > 1)
					cont = false;
			}

			long ans = 0;
			if (cont) {
				max = (1 << n) - 1;

				dp = new long[max + 5][n + 5];
				for (int i = 0; i < dp.length; i++)
					Arrays.fill(dp[i], -1);
				System.out.println(list[n - 1].size());
				for (int i = 0; i < n; i++) {
					if (!(list[i].size() == 0 && rev[i].size() != 0))
						// System.out.println(1+" "+(go(((1 << 1)), 1) %
						// 1000000007));
						ans += go(((1 << i)), i) % 1000000007;
				}
			}
			// System.out.println(ans);
			writer.write("Case #" + cas + ": ");
			writer.write(ans + "");
			writer.newLine();
		}
		writer.close();
	}

}
