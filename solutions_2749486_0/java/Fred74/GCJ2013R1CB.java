import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * User: Fred
 * Date: 13.04.2013
 * Time: 13:16:26
 */
public class GCJ2013R1CB {

	public static void main(String[] args) throws Exception {
		new GCJ2013R1CB("B-small-attempt0.in.txt", "B-small-attempt0.out.txt").run();
		System.exit(0);
	}

	private BufferedReader reader;
	private PrintWriter writer;

	protected GCJ2013R1CB(String inFileName, String outFileName) throws Exception {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(inFileName)));
		writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(outFileName)));

	}

	protected void run() throws Exception {
		int numberOfTestCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= numberOfTestCases; i++) {
			System.out.println(String.format("Case #%d", i));
			String result = runTestCase();
			System.out.println(" > " + result);
			writer.println(String.format("Case #%d: %s", i, result));
		}
		reader.close();
		writer.close();
	}

	protected String getNextLine() throws Exception {
		return reader.readLine();
	}

	protected int[] getIntLine() throws Exception {
		String s = getNextLine();
		System.out.println(s);
		StringTokenizer st = new StringTokenizer(s, " ", false);
		List<Integer> lst = new ArrayList<>();
		while (st.hasMoreTokens()) {
			lst.add(Integer.parseInt(st.nextToken()));
		}
		int[] result = new int[lst.size()];
		for (int i = 0; i < lst.size(); i++) {
			result[i] = lst.get(i);
		}
		return result;
	}

	protected BigInteger[] getBigIntegerLine() throws Exception {
		String s = getNextLine();
		StringTokenizer st = new StringTokenizer(s, " ", false);
		List<BigInteger> lst = new ArrayList<>();
		while (st.hasMoreTokens()) {
			lst.add(new BigInteger(st.nextToken()));
		}
		return lst.toArray(new BigInteger[lst.size()]);
	}

	private static final String VOWELS = "aeiou";
	private static final String CONSONANTS = "bcdfghjklmnpqrstvwxyz";

	protected String runTestCase() throws Exception {
		StringBuilder sb = new StringBuilder();
		int[] intLine = getIntLine();
		int targetX = intLine[0];
		int targetY = intLine[1];
		int x = 0;
		int y = 0;

		boolean b = targetX > x;
		while (x != targetX) {
			if (b) {
				sb.append("E");
				x += sb.length();
			} else {
				sb.append("W");
				x -= sb.length();
			}
			b = !b;
		}

		if ((targetY > y) && ((y + sb.length() + 1) > targetY)) {
			sb.append("S");
			y -= sb.length();
			b = true;
		} else if ((targetY < y) && ((y - (sb.length() + 1)) < targetY)) {
			sb.append("N");
			y += sb.length();
			b = false;
		} else {
			b = targetY > y;
		}

		while (y != targetY) {
			if (b) {
				sb.append("N");
				y += sb.length();
			} else {
				sb.append("S");
				y -= sb.length();
			}
			b = !b;
		}

		return sb.toString();
	}

}
