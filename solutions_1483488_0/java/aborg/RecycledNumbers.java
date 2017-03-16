package googlecodejam2012.qualification.recyclednumbers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

public class RecycledNumbers {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(args[1]): new OutputStreamWriter(System.out));
			try {
				int numLines = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= numLines;++i) {
					String line = br.readLine();
					out.write("Case #" + i + ": "+count(line) + lineSep);
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
	}

	private static int count(String line) {
		String[] parts = line.split("\\s+");
		return count(Integer.parseInt(parts[0]), Integer.parseInt(parts[1]));
	}

	private static int count(int a, int b) {
		if (b < 10) {
			return 0;
		}
		int digits = 1+(int) Math.log10(a);
		int count = 0;
		for (int i = a; i < b; ++i) {
			int[] prevs = new int[digits];
			for (int j = 1; j < digits; ++j) {
				prevs[j - 1] = shift(i, j, digits);
			if (recycled(prevs, i, a, b, j)) {
//				System.out.println(shift(i, j) + " <- " + i);
				++count;
			}
			}
		}
		return count;
	}

	private static boolean recycled(final int[] prevs, final int orig, final int a, final int b, final int j) {
		boolean recycled = recycled(prevs[j - 1], orig, a, b);
		if (recycled) {
			for (int i = 0; i < j - 1; ++i) {
				if (prevs[i] == prevs[j - 1])
					recycled = false;
			}
		}
		return recycled;
	}

	private static boolean recycled(int shifted, int orig, int a, int b) {
		return shifted > orig && shifted >= a && shifted <= b;
	}

	private static final int[] powers = new int[] {1, 10, 100, 1000, 10000, 100000, 1000000};
	
	private static int shift(int num, int shift, int digits) {
		int power = powers[shift];
		int pow2 = powers[digits - shift];
		return num % power * pow2 + num / power;
	}
	private static int shift(int num, int shift) {
		String str = Integer.toString(num);
		return Integer.parseInt(str.substring(shift) + str.substring(0, shift));
	}
}
