import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Dancing {

	private static BufferedReader bufferedReader = new BufferedReader(
			new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		String line = bufferedReader.readLine();
		int cases = Integer.parseInt(line);

		for (int i = 1; i <= cases; i++) {
			line = bufferedReader.readLine();
			String[] split = line.split(" ");

			int googlers = Integer.parseInt(split[0]);
			int surprises = Integer.parseInt(split[1]);
			int p = Integer.parseInt(split[2]);

			int[] totals = new int[googlers];
			for (int j = 0; j < googlers; j++) {
				totals[j] = Integer.parseInt(split[3 + j]);
			}

			Arrays.sort(totals);

			int answer = 0;
			int usedSurprises = 0;

			for (int j = 0; j < googlers; j++) {
				if (p == 0) {
					answer++;
				} else if (totals[j] >= p + 2 * (p - 1) && p >= 1) {
					answer++;
				} else if (usedSurprises < surprises) {
					if (totals[j] >= p + 2 * (p - 2) && p >= 2) {
						answer++;
						usedSurprises++;
					}
				}
			}

			System.out.println("Case #" + i + ": " + answer);
		}
	}

}
