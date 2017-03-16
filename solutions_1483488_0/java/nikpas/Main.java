import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */

	static boolean isRecycled(String s1, String s2) {
		if (s1.length() != s2.length())
			return false;

		if (s1.compareTo(s2) == 0)
			return true;

		for (int i = 0; i < s1.length(); i++) {
			char c = s1.charAt(0);
			s1 = s1.substring(1);
			s1 += c;

			if (s1.compareTo(s2) == 0)
				return true;
		}

		return false;
	}

	static int solve(int A, int B) {

		int count = 0;
		for (int i = A; i <= B; i++)
			for (int j = i + 1; j <= B; j++) {
				if (isRecycled(Integer.toString(i), Integer.toString(j)))
					count++;
				// System.out.println();
			}
		return count;

	}

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));

		int N = scanner.nextInt();
		for (int i = 1; i <= N; i++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			int res = solve(A,B);
			writer.append("Case #" + i + ": " + res);
			writer.newLine();
		}
		writer.close();
		scanner.close();

	}

}
