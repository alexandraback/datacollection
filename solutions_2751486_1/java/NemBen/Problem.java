import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class Problem {

	public static long calc(boolean[] consonant, int N) {
		long sum = 0;

		long[] calc = new long[consonant.length];

		long last = 0;
		calc[0] = consonant[0] ? 1 : 0;
		if (calc[0] >= N) { // => N = 1
			sum += consonant.length;
			last = 1;
		}
		for (int i = 1; i < consonant.length; ++i) {
			calc[i] = consonant[i] ? calc[i - 1] + 1 : 0;
			if (calc[i] >= N) {
				sum += (consonant.length - (i + 1) + 1) * ((i + 1) - N + 1 - last);
				last = i - N + 2;
			}
		}

		return sum;
	}

	public static void solve(String file) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("./" + file + ".in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("./" + file + ".out"), false));

		try {
			int num = Integer.parseInt(reader.readLine());

			String[] cols;
			for (int n = 1; n <= num; ++n) {
				cols = reader.readLine().split("\\s");
				char[] chars = cols[0].toCharArray();
				int N = Integer.parseInt(cols[1]);

				boolean[] consonant = new boolean[chars.length];
				for (int i = 0; i < chars.length; ++i) {
					consonant[i] = !(chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u');
				}

				writer.write("Case #" + n + ": " + calc(consonant, N));
				writer.newLine();

			}
		} finally {
			writer.close();
			reader.close();
		}
	}

	public static void main(String[] args) throws Exception {
		solve("A-large");
	}

}
