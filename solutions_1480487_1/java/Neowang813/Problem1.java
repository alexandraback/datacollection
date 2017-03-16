import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Problem1 {
	public static void main(String[] args) throws FileNotFoundException {

		String inputFile = "A-small-attempt0";
		String outputFile = "pro1.txt";
		Scanner inputScanner = new Scanner(new FileInputStream("e:\\A-large.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("F:\\output\\"
				+ outputFile));
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
			int N = sc.nextInt();
			List<Integer> sis = new ArrayList<Integer>();
			double sum = 0;
			for (int i = 0; i < N; i++) {
				int si = sc.nextInt();
				sis.add(si);
				sum += si;
			}
			List<Integer> colon = new ArrayList<Integer>(sis);
			Collections.sort(colon);
			Collections.reverse(colon);
			Map<Integer, Float> map = new HashMap<Integer, Float>();
			double n = N;
			double w = sum;
			for (int si : colon) {
				float mi = (float) (1 / n + w / sum / n - si / sum) * 100;
				if (mi < 0) {
					map.put(si, 0f);
					n--;
					w -= si;
				} else {
					map.put(si, mi);
				}

			}
			for (int si : sis) {
				output.append(map.get(si));
				output.append(' ');
			}

			// -----------------------------------------------
			System.out.println(output);
			ps.println(output);
		}
	}

}
