
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Formatter;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

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
//        for (int i = 0; i < 5; ++i) {
//            formatter.format("%3d", n[i]);
//        }
		String line = reader.readLine();
		Map<Character, Integer> count = new HashMap<Character, Integer>();
		for (int i = 0; i < line.length(); i++) {
			char current = line.charAt(i);
			if (!count.containsKey(current)) {
				count.put(current, 1);
			} else {
				count.put(current, count.get(current) + 1);
			}
		}
		int[] nb = new int[10];
		nb[0] = clean('Z', count, "ZERO");
		nb[2] = clean('W', count, "TWO");
		nb[4] = clean('U', count, "FOUR");
		nb[5] = clean('F', count, "FIVE");
		nb[6] = clean('X', count, "SIX");
		nb[7] = clean('S', count, "SEVEN");
		nb[8] = clean('G', count, "EIGHT");
		nb[9] = clean('I', count, "NINE");
		nb[3] = clean('H', count, "THREE");
		nb[1] = clean('N', count, "ONE");
		
		for (char c: count.keySet()) {
			assert(count.get(c) == 0);
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < nb[i]; j++) {
				output.append(i);
			}
		}

		output.append(formatter.out());
		return output;
	}

	private int clean(char c, Map<Character, Integer> count, String w) {
		if (!count.containsKey(c)) {
			return 0;
		}
		int nb = count.get(c);
		if (nb ==0 ) {
			return 0;
		}
		for (char cur : w.toCharArray()) {
			count.put(cur, count.get(cur) - nb);
		}
		return nb;
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
