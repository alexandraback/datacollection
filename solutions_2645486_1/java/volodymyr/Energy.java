import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Energy {

	private static final String IN_FILE = "B-large.in";
	private static final String OUT_FILE = "out2.txt";

	static private int numCases;
	private static PrintStream out;

	private long r;
	private long e;
	private int n;
	private long[] v;

	public static void main(String[] args) throws Exception {
		File file = new File(OUT_FILE);
		out = new PrintStream(new FileOutputStream(file));

		Scanner scanner = new Scanner(new File(IN_FILE));
		numCases = scanner.nextInt();
		for (int caseNum = 0; caseNum < numCases; caseNum++) {
			printSolution(caseNum + 1, new Energy(scanner).run());
		}

		scanner.close();
		out.close();
	}

	private String run() {

		long[] spend = new long[n];
		spend[0] = e;
		for (int i = 1; i < n; i++) {
			spend[i] = r;
		}

		long gain = spend[0] * v[0];
		for (int i = 1; i < n; i++) {
			long thisE = e - r;
			gain += spend[i] * v[i];
			for (int j = i - 1; j >= 0 && thisE > 0; j--) {
				if (v[j] < v[i]) {
					long amount = Math.min(thisE, spend[j]);
					thisE-=amount;
					spend[j]-=amount;
					spend[i]+=amount;
					gain-=v[j]*amount;
					gain+=v[i]*amount;
					
				}
				thisE-=spend[j];
			}
		}

		return Long.toString(gain);
	}

	private static void printSolution(int caseNum, String solution) {
		out.println("Case #" + caseNum + ": " + solution);
	}

	public Energy(Scanner scanner) {

		e = scanner.nextInt();
		r = scanner.nextInt();
		n = scanner.nextInt();

		v = new long[n];
		for (int i = 0; i < n; i++) {
			v[i] = scanner.nextInt();
		}

	}
}
