package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;

public class FashionPolice {
	private static class Outfit {
		int j, p, s;

		Outfit(int j, int p, int s) {
			this.j = j;
			this.p = p;
			this.s = s;
		}
		Outfit(String S) {
			String[] s = S.split(" ");
			this.j = Integer.parseInt(s[0]);
			this.p = Integer.parseInt(s[1]);
			this.s = Integer.parseInt(s[2]);
		}

		@Override
		public String toString() {
			return j + " " + p + " " + s;
		}
	}

	static String PATH = "/Downloads/";
	static int MAXS = 3;

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(PATH + "C-small-attempt2.in"));
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(PATH + "C-small.out")));
		/* ----------------------------------------- */
		/* codes */
		int T = Integer.parseInt(reader.readLine());
		for (int t = 0; t < T; t++) {
			String line = reader.readLine();
			String[] nums = line.split(" ");
			int J = Integer.parseInt(nums[0]);
			int P = Integer.parseInt(nums[1]);
			int S = Integer.parseInt(nums[2]);
			int K = Integer.parseInt(nums[3]);
			int N = J * P * S;
			int count = 0;
			List<Outfit> res = new ArrayList<Outfit>();
			if (J == 3 && P == 3 && S == 3) {
				if (K >= 3) {
					K = 3;
					for (int k = 1; k <= K; k++) {
						for (int p = 1; p <= P; p++)
							for (int s = 1; s <= S; s++) {
								res.add(new Outfit(k, p, s));
							}
					}
				} else if (K == 2) {
					String[] SS = "1 1 1,1 1 3,1 2 1,1 2 2,1 3 2,1 3 3,2 1 1,2 1 2,2 2 2,2 2 3,2 3 1,2 3 3,3 1 2,3 1 3,3 2 1,3 2 3,3 3 1,3 3 2".split(",");
					for (String s : SS) {
						res.add(new Outfit(s));
					}
				} else {
					String[] SS = "1 1 2,1 2 1,1 3 3,2 1 1,2 2 3,2 3 2,3 1 3,3 2 2,3 3 1".split(",");
					for (String s : SS) {
						res.add(new Outfit(s));
					}
				}
				count = res.size();
			} else {
				outerLoop: for (int i = 0; i < (1 << N); i++) {
					int n = i;
					int[][] JP = (int[][]) Array.newInstance(int.class, J, P);
					int[][] PS = (int[][]) Array.newInstance(int.class, P, S);
					int[][] JS = (int[][]) Array.newInstance(int.class, J, S);
					List<Outfit> list = new ArrayList<Outfit>();
					// System.out.println("\nnum:" + i);
					for (int j = 0; j < J; j++)
						for (int p = 0; p < P; p++)
							for (int s = 0; s < S; s++) {
								if ((n & 1) > 0) {
									list.add(new Outfit(j + 1, p + 1, s + 1));
									// System.out.print(j +","+ p +","+ s);
									JP[j][p]++;
									PS[p][s]++;
									JS[j][s]++;
									if (JP[j][p] > K || PS[p][s] > K || JS[j][s] > K)
										continue outerLoop;
								}
								n >>= 1;
							}
					if (count < list.size()) {
						count = list.size();
						res = list;
					}
				}
			}
			System.out.println("t" + t + "," + K + "," + count + ":" + res.toString());
			writer.printf("Case #%d: %d\n", t + 1, count);
			for (Outfit o : res)
				writer.println(o.toString());
		}
		reader.close();
		writer.flush();
		writer.close();
	}
}
