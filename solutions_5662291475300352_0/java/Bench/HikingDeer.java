import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class HikingDeer {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Couldn't open input file.\n" + e.getMessage());
			e.printStackTrace();
		}
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e) {
			System.out.println("Couldn't open/make output file."
					+ e.getMessage());
			e.printStackTrace();
		}

		int numTrials = scanner.nextInt();
		for (int trial = 1; trial <= numTrials; trial++) {
			try {
				writer.write("Case #" + trial + ": ");
				solveTrial(scanner, writer);
				writer.write("\n");
			} catch (IOException e) {
				System.out.println("Error on trial #" + trial + "\n"
						+ e.getMessage());
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
		System.out.println("Completed Trials!");
	}

	static int distance(int a, int b) {
		if (a <= b)
			return b - a;
		else
			return 360 - a + b;
	}

	static double timeToMove(int X, double speed) {
		return X / speed;
	}

	static double timeTo360(int pos, long period) {
		return ((360 - pos) / 360.0) * period;
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int numHikers = 0;
		int[] hikerPos = new int[2];
		long[] hikerPeriod = new long[2];
		int N = scanner.nextInt();
		for (int i = 0; i < N; i++) {
			int D = scanner.nextInt();
			int H = scanner.nextInt();
			long M = scanner.nextLong();
			for (int j = 0; j < H; j++) {
				hikerPos[numHikers] = D;
				hikerPeriod[numHikers] = M + 1;
				numHikers++;
			}
		}
		if (numHikers < 2 || hikerPeriod[0] == hikerPeriod[1]) {
			writer.write(0 + "");
			return;
		}
		long slow = hikerPeriod[0];
		long fast = hikerPeriod[1];
		int slowPos = hikerPos[0];
		int fastPos = hikerPos[1];
		if (hikerPeriod[0] < hikerPeriod[1]) { // if first is slower than first
			slow = hikerPeriod[1];
			fast = hikerPeriod[0];
			slowPos = hikerPos[1];
			fastPos = hikerPos[0];
		}
		if (slowPos < fastPos) {
			if ((timeToMove(distance(fastPos, slowPos), 360.0 / fast - 360.0
					/ slow) - timeTo360(slowPos, slow)) <= 0.000001) {
				// if they will overlap b4 the slowest one passes 0
				writer.write(1 + "");
			} else
				writer.write(0 + "");
			return;
		} else {
			if (timeToMove(distance(fastPos, slowPos) + 360, 360.0 / fast - 360.0
					/ slow) < timeTo360(slowPos, slow)) {
				// if they will overlap b4 the slowest one passes 0
				writer.write(1 + "");
			} else
				writer.write(0 + "");
			return;
		}
	}
}
