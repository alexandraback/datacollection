package old;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Consonants {
	private static String PROG_NAME = Consonants.class.getSimpleName();
	private static PrintWriter out;

	public static void main(String[] args) throws Exception {
		main(new FileReader(PROG_NAME + ".small.in"), new FileWriter(PROG_NAME + ".small.out"));
		// main(new FileReader(PROG_NAME + ".large.in"), new
		// FileWriter(PROG_NAME + ".large.out"));
	}

	public static String caseStr(int caseId) {
		return "Case #" + caseId + ":";
	}

	public static void main(FileReader fileReader, FileWriter fileWriter) throws Exception {
		long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(fileReader);
		out = new PrintWriter(new BufferedWriter(fileWriter));
		Integer caseCount = Integer.parseInt(f.readLine());
		for (int caseId = 1; caseId <= caseCount; caseId++) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			char[] charArray = st.nextToken().toCharArray();
			int N = Integer.parseInt(st.nextToken());
			int[] sumArray = new int[charArray.length];

			int consecCount = 0;
			System.out.println(Arrays.toString(charArray));

			for (int i = 0; i < charArray.length; i++) {
				for (int j = i; j < charArray.length; j++) {
					int count = 0;
					for (int k = i; k <= j; k++) {
						if (charArray[k] == 'a' || charArray[k] == 'e' || charArray[k] == 'i' || charArray[k] == 'o'
								|| charArray[k] == 'u') {
							count = 0;
							continue;
						}
						count++;
						if (count >= N) {
							consecCount++;
							break;
						}

					}

				}
			}
			System.out.println(Arrays.toString(sumArray));

			System.out.println(caseStr(caseId) + " " + consecCount);
			out.println(caseStr(caseId) + " " + consecCount);
		}
		System.out.println(System.currentTimeMillis() - start);
		out.close(); // close the output file
	}
}
