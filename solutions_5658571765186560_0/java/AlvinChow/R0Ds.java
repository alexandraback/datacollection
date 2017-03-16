import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * java -cp bin R0As R0As\A-small-practice.in
 */
public class R0Ds {

	static class MultipleOutputStream extends OutputStream {

		OutputStream[] oss;

		public MultipleOutputStream(OutputStream... os) {
			this.oss = os;
		}

		@Override
		public void write(int b) throws IOException {
			for (OutputStream os : this.oss)
				os.write(b);
		}
	}

	public static void main(String[] args) throws Exception {
		File inFile = new File(args[0]);
		File outFile = new File(args[0] + ".out");
		System.setOut(new PrintStream(new MultipleOutputStream(System.out, new FileOutputStream(outFile))));
		new R0Ds().allCase(inFile);
	}

	private void allCase(File inFile) throws Exception {
		try (Scanner in = new Scanner(inFile, "UTF-8")) {
			long t = Long.parseLong(in.nextLine().trim());
			init();
			for (long i = 1; i <= t; i++) {
				System.out.print("Case #" + i + ": ");
				singleCase(in);
				System.out.println();
			}
		}
	}

	private void init() {

	}

	private static final String success = "GABRIEL";
	private static final String fail = "RICHARD";

	private void singleCase(Scanner in) {
		int X = in.nextInt();
		int R = in.nextInt();
		int C = in.nextInt();

		if (X == 1) {
			System.out.print(success);
			return;
		}

		if (R * C < X) {
			System.out.print(fail);
			return;
		}

		if (R < X && C < X) {
			System.out.print(fail);
			return;
		}

		if (X > 2 && (R == 1 || C == 1)) {
			System.out.print(fail);
			return;
		}

		if (R * C % X != 0) {
			System.out.print(fail);
			return;
		}

		if (X == 4 && (R == 2 || C == 2)) {
			System.out.print(fail);
			return;
		}

		System.out.print(success);
	}
}
