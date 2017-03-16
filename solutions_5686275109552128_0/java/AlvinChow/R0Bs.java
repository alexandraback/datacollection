import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * java -cp bin R0As R0As\A-small-practice.in
 */
public class R0Bs {

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
		new R0Bs().allCase(inFile);
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
		int D = in.nextInt();
		int[] P = new int[D];
		for (int i = 0; i < D; i++)
			P[i] = in.nextInt();
		Arrays.sort(P);

		for (int i = 0; i <= P[P.length - 1]; i++) {
			if (check(P, i)) {
				System.out.print(i);
				return;
			}
		}

	}

	private boolean check(int[] P, int n) {
		for (int move = 0; move < n; move++) {
			int moved = 0;
			int index = P.length - 1;
			int size = n - move;
			while (moved < move && index >= 0) {
				if (P[index] > size)
					moved += (P[index] - 1) / size;
				else
					break;
				index--;
			}
			if (moved > move)
				continue;
			if (index < 0 || P[index] <= size)
				return true;
		}
		return false;
	}
}
