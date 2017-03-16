package dancing;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Main {

	public static void main(String[] args) throws IOException {
		File file = new File("B-large.in");
		FileReader fr = new FileReader(file);
		BufferedReader in = new BufferedReader(fr);

		String line = in.readLine();
		String[] tokens;
		int num = Integer.parseInt(line);
		int i = 1, N, s, p, t, minAlways, minSurprising, always, surprising, finalCount;
		while (i <= num) {
			line = in.readLine();
			tokens = line.split(" ");
			N = Integer.parseInt(tokens[0]);
			s = Integer.parseInt(tokens[1]);
			p = Integer.parseInt(tokens[2]);
			if (p >= 2) {
				minAlways = 3 * p - 2;
				minSurprising = 3 * p - 4;
			} else {
				minAlways = p;
				minSurprising = 1;
			}

			always = 0;
			surprising = 0;

			for (int j = 0; j < N; j++) {
				t = Integer.parseInt(tokens[3 + j]);
				if (t >= minAlways) {
					always++;
				} else if (t >= minSurprising) {
					surprising++;
				}
			}

			finalCount = always + Math.min(s, surprising);

			System.out.println("Case #" + i + ": " + finalCount);
			i++;
		}
	}

}
