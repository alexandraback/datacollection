import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ProblemA {

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("problemA.in"));
		long testCases = scanner.nextLong();
		List<String> solutions = new ArrayList<String>();		
		
		for (int i = 1; i <= testCases; i++) {
			long R = scanner.nextLong();
			long C = scanner.nextLong();
			long W = scanner.nextLong();
			solutions.add(solve(R, C, W));
		}
		scanner.close();
		
		BufferedWriter fileWriter = new BufferedWriter(new FileWriter(new File("problemA")));
		int i = 1;
		for (String solution: solutions) {
			fileWriter.write("Case #" + i + ": " + solution);
			if (i < solutions.size()) {
				fileWriter.newLine();
			}
			i++;
		}
		fileWriter.close();
	}

	private static String solve(long R, long C, long W) {
		long shots = 0;
		shots += (R - 1) * emptyTheRow(C, W);
		shots += shotsForTheRightRow(C, W);
		return Long.toString(shots);
	}

	private static long shotsForTheRightRow(long C, long W) {
		return emptyTheRow(C, W) + W - (C % W == 0 ? 1 : 0);
	}

	private static long emptyTheRow(long C, long W) {
		return C / W;
	}

	
}
