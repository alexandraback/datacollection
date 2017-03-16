import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * User: Fred
 * Date: 13.04.2013
 * Time: 13:16:26
 */
public class GCJ2013R1CA {

	public static void main(String[] args) throws Exception {
		new GCJ2013R1CA("A-small-attempt0.in.txt", "A-small-attempt0.out.txt").run();
		System.exit(0);
	}

	private BufferedReader reader;
	private PrintWriter writer;

	protected GCJ2013R1CA(String inFileName, String outFileName) throws Exception {
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
		String nextLine = getNextLine();
		int i = nextLine.indexOf(' ');
		String name = nextLine.substring(0, i).toLowerCase();
		int n = Integer.parseInt(nextLine.substring(i + 1));
		int result = 0;

		for (int j = 0; j < name.length() - n + 1; j++) {
			for (int k = j; k <= name.length(); k++) {
				String s = name.substring(j, k);
				int consCount = 0;
				for (int l = 0; l < s.length(); l++) {
					if (CONSONANTS.contains(s.substring(l, l + 1))) {
						consCount++;
						if (consCount >= n) {
							// System.out.println(s);
							result ++;
							break;
						}
					} else {
						consCount = 0;
					}
				}
			}
		}
		sb.append(result);
		return sb.toString();
	}

}
