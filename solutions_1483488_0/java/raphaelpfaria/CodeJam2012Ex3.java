import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class CodeJam2012Ex3 {
	public static void main(String arg[]) throws FileNotFoundException {
		File file = new File("C-small-attempt1.in");
		String output;
		Scanner scanner = new Scanner(file);
		int numTestCases = scanner.nextInt();

		for (int i = 0; i < numTestCases; i++) {
			StringBuffer buffer = new StringBuffer("Case #" + (i + 1) + ": ");
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			buffer.append(CodeJam2012Ex3.countPairs(A, B));
			if (i != numTestCases - 1) {
				buffer.append("\n");
			}
			output = buffer.toString();

			System.out.print(output);
		}

	}

	public static int countPairs(int A, int B) {
		int pairs = 0;
		HashMap<String, Boolean> map = new HashMap<String, Boolean>();

		for (int i = A; i <= B; i++) {

			String n = i + "";

			int len = n.length();
			for (int j = 1; j < len; j++) {
				String m = n.substring(len - j) + n.substring(0, len - j);
				int nNum = Integer.parseInt(n);
				int mNum = Integer.parseInt(m);
				if (nNum < mNum && n.length() == (mNum + "").length()
				&& mNum <= B && !map.containsKey((n + m))) {
					map.put(n + m, (Boolean) true);
					pairs++;
				}
			}
		}
		return pairs;

	}
}
