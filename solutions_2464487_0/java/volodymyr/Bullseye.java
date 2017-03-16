import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Bullseye {

	private static final String IN_FILE = "A-small-attempt0.in";
	private static final String OUT_FILE = "out.txt";

	static private int numCases;
	private static PrintStream out;

	private long r;
	private long t;

	public static void main(String[] args) throws Exception {
		File file = new File(OUT_FILE);
		out = new PrintStream(new FileOutputStream(file));

		Scanner scanner = new Scanner(new File(IN_FILE));
		numCases = scanner.nextInt();
		for (int caseNum = 0; caseNum < numCases; caseNum++) {
			printSolution(caseNum + 1, new Bullseye(scanner).run());
		}

		scanner.close();
		out.close();
	}

	private String run() {

		double total = r * r;
		
		double black = 0;

		int count = 0;
		while (true) {
			black = (r + 1) * (r + 1)- (total);
			
			if ( black <= t) {
				t-=black;
				count++;
			} else
				break;
			total = (r+2) * (r+2);
			r += 2;

		}
		return "" + count;
	}

	private static void printSolution(int caseNum, String solution) {
		out.println("Case #" + caseNum + ": " + solution);
	}

	public Bullseye(Scanner scanner) {

		r = scanner.nextLong();
		t = scanner.nextLong();

	}
}
