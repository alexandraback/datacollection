package qualifiers2014;

import java.io.*;
import java.util.*;
import java.math.*;


public class DeceitfulWar {
	public static void main(String args[]) throws Exception {
		BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader in = new BufferedReader(new FileReader(new File("src/qualifiers2014/"
				+ fin.readLine())));
		FileWriter out = new FileWriter(new File("src/qualifiers2014/DeceitfulWar.out"));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			int N = Integer.parseInt(in.readLine());
			double[] naomi = new double[N], ken = new double[N];
			StringTokenizer st = new StringTokenizer(in.readLine());
			StringTokenizer st2 = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				naomi[i] = Double.parseDouble(st.nextToken());
				ken[i] = Double.parseDouble(st2.nextToken());
			}
			Arrays.sort(naomi);
			Arrays.sort(ken);
			
			for (int i = 0; i < N; i++) {
				System.out.print(naomi[i] + " ");
			}
			System.out.println();
			for (int i = 0; i < N; i++) {
				System.out.print(ken[i] + " ");
			}
			System.out.println();
			
			int y = 0;
			int i = 0;
			while (i+y < N) {
				if (ken[i] < naomi[i+y]) i++;
				else y++;
			}
			y = N-y;
			
			int z = 0;
			int max = 0;
			i = 0;
			int j = 0;
			while (i < N || j < N) {
				if (i >= N) {
					break;
				} else if (j >= N) {
					break;
				} else {
					if (ken[j] < naomi[i]) {
						j++;
						z++;
						max = Math.max(z, max);
					} else {
						i++;
						z--;
					}
				}
			}
			z = max;
			
			int z2 = 0;
			i = 0;
			while (i+z2 < N) {
				if (ken[i+z2] > naomi[i]) i++;
				else z2++;
			}
			
			System.out.println(String.format("%d %d", y, z));
			if (z2 != z) {
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.println("ERROR");
				System.out.printf("z = %d, z2 = %d\n", z, z2);
			}

			out.write(String.format("Case #%d: ", t));
			out.write(String.format("%d %d", y, z));
			out.write("\n");
		}

		fin.close();
		in.close();
		out.close();
	}
}
