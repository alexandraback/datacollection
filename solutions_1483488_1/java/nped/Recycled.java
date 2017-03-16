import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Recycled {

	private static BufferedReader bufferedReader = new BufferedReader(
			new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		String line = bufferedReader.readLine();
		int cases = Integer.parseInt(line);

		for (int i = 1; i <= cases; i++) {
			line = bufferedReader.readLine();
			String[] split = line.split(" ");

			int A = Integer.parseInt(split[0]);
			int B = Integer.parseInt(split[1]);

			HashSet<String> usedPairs = new HashSet<String>();

			int answer = 0;
			int duplicates = 0;
			if (B > 10) {
				for (int j = A; j < B; j++) {
					String number = "" + j;
					// System.err.println("Current number: " + number);
					for (int k = 0; k < number.length(); k++) {
						String rotated = number.substring(k)
								+ number.substring(0, k);
						// System.err.println("Rotated number: " + rotated);
						int a = Integer.parseInt(number);
						int b = Integer.parseInt(rotated);

						if (Math.min(a, b) >= A && a != b
								&& Math.max(a, b) <= B) {
							String hashKey;
							if (a < b) {
								hashKey = number + rotated;
							} else {
								hashKey = rotated + number;
							}
							if (!usedPairs.contains(hashKey)) {
								answer++;
								usedPairs.add(hashKey);
								// System.err.println("Found a new pair!");
							} else {
								/*
								 * System.err
								 * .println("Found a duplicate: Number - " +
								 * number + ", Rotated: " + rotated);
								 */
								duplicates++;
							}
						}
					}
				}
			}
			// System.err.println("Found " + duplicates + " duplicated pairs");
			System.out.println("Case #" + i + ": " + answer);
		}
	}

}
