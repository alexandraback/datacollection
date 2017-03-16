package khelman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Pass {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\pass.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter f0 = new FileWriter("d:\\pass.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {
			System.out.println();

			line = br.readLine();
			String[] elems = line.split(" ");

			int a = Integer.parseInt(elems[0]);

			int b = Integer.parseInt(elems[1]);

			line = br.readLine();
			elems = line.split(" ");

			double p[] = new double[a];
			double ps[] = new double[a];

			for (int j = 0; j < a; j++) {
				p[j] = Double.parseDouble(elems[j]);
				if (j == 0) {
					ps[0] = p[0];
				} else {
					ps[j] = ps[j - 1] * p[j];
				}
			}

			double ret = b + 2;

			for (int i = 0; i < a; i++) {
				double atempt = ps[i] * (b - i) + (1.0 - ps[i])
						* (2 * b - i + 1) + ((double) (a - i - 1));
				if (atempt < ret) {
					ret = atempt;
				}
			}

			f0.write("Case #" + c + ": " + ret + "\r\n");
		}

		fr.close();
		f0.close();

	}

}
