package msn;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Driver {
	private static BufferedReader br;
	private static BufferedWriter bw;

	/*
	 * Apache Commons Lang Availble @
	 * https://commons.apache.org/proper/commons-lang/
	 */

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader(new File("input.txt")));
			bw = new BufferedWriter(new FileWriter(new File("output.txt")));

			final long numCases = nextLong();
			for (long i = 1; i <= numCases; i++) {
				// read the inputs
				String input = br.readLine();

				// do stuff
				char[] cs = input.toCharArray();
				String result = "";
				Character start = null;
				for (char c : cs) {
					if (start == null) {
						start = c;
						result = "" + c;
					} else {
						if (c >= start) {
							result = c + result;
							start = c;
						} else {
							result = result + c;
						}
					}

				}

				// write the results
				writeCaseHeaderSingleResult(i, result);
			}
			bw.flush();
			bw.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static long nextLong() throws IOException {
		return Long.parseLong(br.readLine());
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}

	private static double nextDouble() throws IOException {
		return Double.parseDouble(br.readLine());
	}

	private static void writeCaseHeaderSingleResult(long caseNum, String result) throws IOException {
		String caseString = String.format("Case #%s: %s\r\n", caseNum, result);
		write(caseString);
	}

	private static void writeCaseHeaderMultiResult(long caseNum) throws IOException {
		String caseString = String.format("Case #%s:\r\n", caseNum);
		write(caseString);
	}

	private static void write(String toWrite) throws IOException {
		System.out.print(toWrite);
		bw.write(toWrite);
	}

}
