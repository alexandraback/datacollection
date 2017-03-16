package msn;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

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
				final int n = nextInt();

				// do stuff
				HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

				for (int j = 0; j < (n * 2) - 1; j++) {
					String s = br.readLine();
					StringTokenizer st = new StringTokenizer(s, " ");
					while (st.hasMoreTokens()) {
						Integer key = Integer.parseInt(st.nextToken());
						if (map.containsKey(key)) {
							map.put(key, map.get(key) + 1);
						} else {
							map.put(key, 1);
						}
					}
				}

				List<Integer> results = new ArrayList<Integer>();
				for (Integer key : map.keySet()) {
					if (map.get(key) % 2 == 0) {
						continue;
					}
					results.add(key);
				}

				results.sort(new Comparator<Integer>() {

					@Override
					public int compare(Integer o1, Integer o2) {
						return o1.compareTo(o2);
					}
				});

				String result = "";
				for (Integer height : results) {
					result += height + " ";
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
