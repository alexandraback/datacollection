package Round1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;

public class Prob2 {
	private static BufferedReader r;
	private static PrintStream outFile;
	private static PrintStream out = new PrintStream(new OutputStream() {
		@Override
		public void write(int b) throws IOException {
			System.out.write(b);
			outFile.write(b);
		}
	});

	public static void main(String[] args) throws IOException {
		File f = new File("/home/blarson/input");
		r = new BufferedReader(new FileReader(f));
		outFile = new PrintStream(new FileOutputStream(new File(
				"/home/blarson/output")));
		final int numCases = readInt();

		for (int i = 0; i < numCases; i++) {
			out.print("Case #" + (i + 1) + ": ");

			solve();

			out.println();
		}

		out.close();
	}

	private static void solve() throws IOException {
		int[] nums = readIntArray(3);
		int a = nums[0];
		int b = nums[1];
		int c = nums[2];
		
		int winners = 0;
		for(int i = 0; i < a; i++) {
			for(int j = 0; j < b; j++) {
				if((i & j) < c) {
					winners++;
				}
			}
		}
		out.print(winners);
	}

	private static double[] readDoubleArray(int maxItems) throws IOException {
		double[] array = new double[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = Double.parseDouble(data[i]);
		}
		return array;
	}

	private static int[] readIntArray(int maxItems) throws IOException {
		int[] array = new int[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = Integer.parseInt(data[i]);
		}
		return array;
	}

	private static int readInt() throws IOException {
		String line = r.readLine().trim();
		return new Integer(line);
	}
}
