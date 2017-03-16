
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;
import java.util.TreeSet;

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
				result.append("Case #" + tc + ": ");
				result.append(oneTestCase(reader));
				result.append('\n');
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

	private StringBuilder oneTestCase(BufferedReader reader) throws IOException {
		Formatter formatter = new Formatter(Locale.ENGLISH);
		StringBuilder output = new StringBuilder();
		String[] score = reader.readLine().split(" ");

		int n = score[0].length();
		TreeSet<Integer> v0 = new TreeSet<Integer>();
		v0.add(0);
		TreeSet<Integer> v1 = new TreeSet<Integer>();
		v1.add(0);
		for (int i = 0; i < n; i++) {
			TreeSet<Integer> newv0 = new TreeSet<Integer>();
			if (isMark(score[0].charAt(i))) {
				for (int s0 : v0) {
					for (int j = 0; j < 10; j++) {
						newv0.add(s0 * 10 + j);
					}
				}
			} else {
				for (int s0 : v0) {
					newv0.add(s0*10 + (score[0].charAt(i)-'0'));
				}
			}
			v0 = newv0;
		}
		for (int i = 0; i < n; i++) {
			TreeSet<Integer> newv1 = new TreeSet<Integer>();
			if (isMark(score[1].charAt(i))) {
				for (int s1 : v1) {
					for (int j = 0; j < 10; j++) {
						newv1.add(s1 * 10 + j);
					}
				}
			} else {
				for (int s1 : v1) {
					newv1.add(s1*10 + (score[1].charAt(i)-'0'));
				}
			}
			v1 = newv1;
		}
		int ms = Integer.MAX_VALUE;
		int bs0 = -1;
		int bs1 = -1;
		for (int s0: v0) {
			for (int s1: v1) {
				if (Math.abs(s0-s1)<ms) {
					bs0 = s0;
					bs1 = s1;
					ms = Math.abs(s0 - s1);
				}		
			} 
		}

		output.append(String.format("%0"+n+"d", bs0));
		output.append(' ');
		output.append(String.format("%0"+n+"d", bs1));
		output.append(formatter.out());
		return output;
	}

	private boolean isMark(char c) {
		return c == '?';
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
