
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.HashMap;
import java.util.Locale;

/**
 *
 * @author edemairy
 */
public class Main {

	private int nbTC;
	private StringBuilder result = new StringBuilder();

	private static class EndException extends RuntimeException {
	}

	public void run() throws IOException {
		//        Scanner scanner = new Scanner(System.in);
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		nbTC = readInt(reader);
//         nbTC = Integer.MAX_VALUE;
//        scanner.nextLine();
		try {
			for (int tc = 1; tc <= nbTC; ++tc) {
				result.append("Case #").append(tc).append(": ");
				result.append(oneTestCase(reader));
			}
		} catch (EndException e) {
		}
		System.out.print(result);
	}

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) throws IOException {
		Main main = new Main();
		main.run();
	}

	private class Triple {

		private final int j;
		private final int p;
		private final int s;

		public Triple(int j, int p, int k) {
			this.j = j+1;
			this.p = p+1;
			this.s = k+1;
		}

		public int val() {
			return j * 100 + p * 10 + s;
		}

		public int val1() {
			return p * 10 + s;
		}

		public int val2() {
			return j * 100 + s;
		}

		public int val3() {
			return j * 100 + p * 10;
		}
		@Override
		public String toString() {
			return (j)+" "+(p)+" "+(s)+"\n";
		}
	}

	private StringBuilder oneTestCase(BufferedReader reader) throws IOException {
		Formatter formatter = new Formatter(Locale.ENGLISH);
		StringBuilder output = new StringBuilder();
//        for (int i = 0; i < 5; ++i) {
//            formatter.format("%3d", n[i]);
//        }
		String[] parts = reader.readLine().split(" ");
		int j = Integer.parseInt(parts[0]);
		int p = Integer.parseInt(parts[1]);
		int s = Integer.parseInt(parts[2]);
		int k = Integer.parseInt(parts[3]);
		ArrayList<Triple> ar = new ArrayList<Triple>();
		for (int cj = 0; cj < j; cj++) {
			for (int cp = 0; cp < p; cp++) {
				for (int cs = 0; cs < s; cs++) {
					ar.add(new Triple(cj, cp, cs));
				}
			}
		}
		ArrayList<Triple> taken = new ArrayList<Triple>();
		HashMap<Integer, Integer> count = new HashMap<Integer, Integer>();
		for (int i=0; i<1000; i++) {
			count.put(i, 0);
		}
		for (int i = 0; i < ar.size(); i++) {
			Triple ctriple = ar.get(i);
			if (count.get(ctriple.val1()) >= k || count.get(ctriple.val2()) >= k || count.get(ctriple.val3()) >= k) {
				continue;
			} else {
				count.put(ctriple.val1(), count.get(ctriple.val1())+1);
				count.put(ctriple.val2(), count.get(ctriple.val2())+1);
				count.put(ctriple.val3(), count.get(ctriple.val3())+1);
				taken.add(ctriple);
			}
		}
		formatter.format("%d\n", taken.size());
		for (int i=0; i<taken.size(); i++) {
			formatter.format("%s", taken.get(i));
		}
		output.append(formatter.out());
		return output;
	}

	private int readInt(BufferedReader reader) throws IOException {
		int r = 0;
		boolean positive = true;
		char currentChar = (char) reader.read();

		while ((currentChar == ' ') || (currentChar == '\n')) {
			currentChar = (char) reader.read();
		}
		if (currentChar == (char) -1) {
			throw new IOException("end of stream");
		}
		if (currentChar == '-') {
			positive = false;
			currentChar = (char) reader.read();
		}
		while ((currentChar >= '0') && (currentChar <= '9')) {
			r = r * 10 + currentChar - '0';
			currentChar = (char) reader.read();
		}
		if (positive) {
			return r;
		} else {
			return -r;
		}
	}

	private char readChar(BufferedReader reader) throws IOException {
		return (char) reader.read();
	}
}
