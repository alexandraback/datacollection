import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public abstract class CodeJamProblem {
	public static void main(String[] inOut) throws InstantiationException,
			IllegalAccessException, ClassNotFoundException, FileNotFoundException {
		Scanner inScan = new Scanner(System.in);
		CodeJamProblem prob = Class.forName(inScan.nextLine()).asSubclass(
				CodeJamProblem.class).newInstance();
		Scanner scan = inOut.length == 0 ? inScan : new Scanner(
				new FileInputStream(inOut[0]));
		int trials = scan.nextInt();
		PrintStream pw;
		pw = new PrintStream(inOut.length == 0 ? System.out
				: new FileOutputStream(inOut[1]));
		for (int trial = 1; trial <= trials; trial++) {
			pw.println("Case #" + trial + ": " + prob.run(scan));
		}
		pw.close();
	}

	protected abstract Object run(Scanner scan);
}
