import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * java -cp bin R0As R0As\A-small-practice.in
 */
public class R0As {

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
		new R0As().allCase(inFile);
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

	private void singleCase(Scanner in) {
		int sMax = in.nextInt();
		String sList = in.nextLine().trim();
		long sTotal = 0;
		long need = 0;
		for (int i = 0; i <= sMax; i++) {
			if (i > sTotal) {
				need += i - sTotal;
				sTotal += i - sTotal;
			}
			int s = Integer.parseInt(sList.charAt(i) + "");
			sTotal += s;
		}
		System.out.print(need);
	}
}
