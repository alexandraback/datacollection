package googlecodejam2012.qualification.dancinggooglers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

public class DancingGooglers {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
//		System.out.println(hasWithoutSurprise(6, 2));
//		System.out.println(hasWithoutSurprise(5, 2));
//		System.out.println(hasWithoutSurprise(4, 2));
//		System.out.println(hasWithoutSurprise(7, 2));
//		System.out.println(hasWithoutSurprise(8, 2));
//		System.out.println(hasWithoutSurprise(3, 2));
//		System.out.println(hasWithoutSurprise(1, 1));
//		System.out.println(hasWithoutSurprise(0, 1));
//		System.out.println();
//		System.out.println(hasWithSurprise(6, 2));
//		System.out.println(hasWithSurprise(5, 2));
//		System.out.println(hasWithSurprise(4, 2));
//		System.out.println(hasWithSurprise(7, 2));
//		System.out.println(hasWithSurprise(8, 2));
//		System.out.println(hasWithSurprise(3, 2));
//		System.out.println("Should be false: " + hasWithSurprise(2, 3));
//		System.out.println("Should be false: " + hasWithSurprise(3, 3));
//		System.out.println("Should be false: " + hasWithSurprise(4, 3));
//		System.out.println("Should be true: " + hasWithSurprise(5, 3));
//		System.out.println("Should be true: " + hasWithSurprise(6, 3));
//		System.out.println("Should be true: " + hasWithSurprise(7, 3));
//		System.out.println("Should be false: " + hasWithSurprise(0, 1));
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
		String[] parts = line.split(" ");
		int n = Integer.parseInt(parts[0]);
		int s = Integer.parseInt(parts[1]);
		int p = Integer.parseInt(parts[2]);
		int[] sumScores = new int[parts.length - 3];
		for (int i = parts.length; i -->3;) {
			sumScores[i - 3] = Integer.parseInt(parts[i]);
		}
		return count(n, s, p, sumScores);
	}

	private static int count(int n, int s, int p, int[] sumScores) {
		int countWithoutSurprise = 0;
		int countWithPossibleSurprise = 0;
		for (int sumScore : sumScores) {
			if(hasWithoutSurprise(sumScore, p)) {
				countWithoutSurprise++;
			} else if (hasWithSurprise(sumScore, p)) {
				countWithPossibleSurprise++;
			}
		}
		return countWithoutSurprise + Math.min(s, countWithPossibleSurprise);
	}

	private static boolean hasWithSurprise(int sumScore, int p) {
		return sumScore >= p && (sumScore + 4) /3 >= p;
	}

	private static boolean hasWithoutSurprise(int sumScore, int p) {
		return (sumScore + 2) / 3 >= p;
	}
}
