import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Problem3 {
	public static void main(String[] args) throws FileNotFoundException {

		String inputFile = "C-small-attempt0.in";
		Scanner inputScanner = new Scanner(new FileInputStream("d:\\input\\"
				+ inputFile));
		PrintStream ps = new PrintStream(new FileOutputStream(
				"d:\\output\\pro3.txt"));
		int totalCaseNum = inputScanner.nextInt();
		inputScanner.nextLine();
		// -----------------------------------------------

		// -----------------------------------------------
		for (int caseNum = 1; caseNum <= totalCaseNum; caseNum++) {
			String line = inputScanner.nextLine();
			String prefix = "Case #" + caseNum + ": ";
			StringBuilder output = new StringBuilder(prefix);
			// -----------------------------------------------
			Scanner sc = new Scanner(line);
			String A = sc.next();
			String B = sc.next();
			int len = A.length();
			int count = 0;

			int numA = Integer.parseInt(A);
			int numB = Integer.parseInt(B);
			for (int n = numA; n <= numB; n++) {
				String sn = String.valueOf(n);
				StringBuilder sb = new StringBuilder();
				for (int j = 0; j < len - sn.length(); j++) {
					sb.append('0');
				}
				sb.append(sn);
				Set<Integer> recycle = new HashSet<Integer>();
				for (int j = 1; j < len; j++) {
					int m = genRecycleNum(sb, j);
					if (n < m && m <= numB) {
						recycle.add(m);
					}
				}
				count += recycle.size();
			}
			output.append(count);
			// -----------------------------------------------
			System.out.println(output);
			ps.println(output);
		}
	}

	private static int genRecycleNum(StringBuilder sb, int j) {
		String sm = sb.substring(j, sb.length()) + sb.substring(0, j);
//		System.out.println(sb +"::"+sm);
		return Integer.parseInt(sm);
	}
}
