package khelman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Rush {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\rush.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter f0 = new FileWriter("d:\\rush.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {
			System.out.println();

			line = br.readLine();
			String[] elems = line.split(" ");

			int n = Integer.parseInt(elems[0]);

			int[] a = new int[n];
			int[] b = new int[n];
			boolean[] usedA = new boolean[n];
			boolean[] usedB = new boolean[n];

			for (int j = 0; j < n; j++) {
				line = br.readLine();
				elems = line.split(" ");

				a[j] = Integer.parseInt(elems[0]);
				b[j] = Integer.parseInt(elems[1]);

				usedA[j] = false;
				usedB[j] = false;
			}

			int ret = 0;
			int stars = 0;

			while (stars < 2 * n && ret >= 0) {
				ret++;
				int cand1 = -1;
				int cand2 = -1;

				for (int j = 0; j < n; j++) {
					if (!usedA[j]
							&& a[j] <= stars
							&& (cand1 == -1 || (!usedA[cand1] && b[cand1] < b[j]))) {
						cand1 = j;
					}

					if (usedA[j] && !usedB[j] && b[j] <= stars) {
						cand1 = j;
					}

					if (!usedA[j] && !usedB[j] && b[j] <= stars) {
						cand2 = j;
					}
				}

				if (cand1 == -1 && cand2 == -1) {
					ret = -1;
				} else if (cand2 != -1) {
					stars += 2;
					usedA[cand2] = true;
					usedB[cand2] = true;
				} else {
					stars += 1;
					if (usedA[cand1]) {
						usedB[cand1] = true;
					} else {
						usedA[cand1] = true;
					}
				}
			}

			if (ret < 0) {
				f0.write("Case #" + c + ": Too Bad\r\n");
			} else {
				f0.write("Case #" + c + ": " + ret + "\r\n");
			}
		}

		fr.close();
		f0.close();

	}

}
