package roundc;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Consonants {

	/**
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception {

		// Open the file that is the first
		// command line parameter

		// FileInputStream fstream = new FileInputStream(args[0]);
		FileInputStream fstream = new FileInputStream("c:\\Jam\\2013-1c\\A-small-attempt0 (2).in");

		// Get the object of DataInputStream
		DataInputStream in = new DataInputStream(fstream);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		String strLine;

		FileWriter outFile = new FileWriter("c:\\Jam\\2013-1c\\output.txt");
		PrintWriter out = new PrintWriter(outFile);

		long t = new Long(br.readLine());

		for (int i = 0; i < t; i++) {
			strLine = br.readLine();
			StringTokenizer token = new StringTokenizer(strLine);

			String str = token.nextToken();
			int n = new Integer(token.nextToken());

			long numOfOperations = handleCase(str, n);

			long index = i + 1;

			String strToPrint = "Case #" + index + ": " + numOfOperations;
			out.println(strToPrint);
			System.out.println(strToPrint);
		}

		in.close();
		out.close();
	}

	private static long handleCase(String str, int n) {

		int hits = 0;
		int count = 0;

		Set<Pair> pairs = new HashSet<>();

		int l = str.length();

		for (int i = 0; i < l; i++) {

			char c = str.charAt(i);

			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == ' ') {

				count = 0;

			} else {

				count++;

				if (count >= n) {
					hits++;

					createPairs(pairs, i - n + 1, str, n);
				}
			}
		}

		System.out.println("hits = " + hits);
		
		System.out.println("pairs = " + pairs);

		return pairs.size();
	}

	public static void createPairs(Set<Pair> pairs, int x, String str, int n) {
		int l = str.length();

		for (int i = 0; i <= x; i++) {
			for (int j = x + n - 1; j < l; j++) {
				Pair pair = new Pair(i, j);
				pairs.add(pair);
			}
		}
	}

}
