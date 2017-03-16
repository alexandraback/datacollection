import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Ovation {

	public static void main(String[] args) throws Exception {
		Ovation object = new Ovation();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			scanner.next();
			
			String input = scanner.next();
			int result = object.solve(input);

			wr.write("Case #" + tc + ": " + result + "\r\n");
		}

		scanner.close();
		wr.close();
	}

	private int solve(String input) throws Exception {

		int output = 0;

		for (int additional = 0;; additional++) {

			if (solved(input, additional)) {
				output = additional;
				break;
			}
		}

		return output;

	}

	private boolean solved(String input, int additional) {

		List<Integer> count = new ArrayList<>();

		for (int i = 0; i < input.length(); i++) {
			count.add(input.charAt(i) - '0');
		}

		count.set(0, count.get(0) + additional);

		int standing = 0;

		for (int i = 0; i < count.size(); i++) {

			int required = i;

			if (standing >= required) {
				// these will stand up as well
				standing += count.get(i);
			} else {

				if (count.get(i) > 0)
					return false;
			}

		}

		return true;
	}
}
