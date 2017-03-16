import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Pogo {

	static Scanner scanner;
	
	public static void main(String[] args) throws FileNotFoundException {
		scanner = new Scanner(new File("B-small-attempt0.in"));
		
		int caseCount = scanner.nextInt();
		for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
			String result = solve();
			System.out.format("Case #%d: %s%n", caseNumber, result);
		}
	}

	static String solve() {
		
		// init
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		
		// find path
		StringBuilder result = new StringBuilder();
		if (x > 0) {
			// go east
			for (int i = 0; i < x; i++) {
				result.append("WE");
			}
		} else {
			// go west
			for (int i = 0; i > x; i--) {
				result.append("EW");
			}
		}
		if (y > 0) {
			// go north
			for (int i = 0; i < y; i++) {
				result.append("SN");
			}
		} else {
			// go south
			for (int i = 0; i > y; i--) {
				result.append("NS");
			}
		}

		return result.toString();
	}
}
