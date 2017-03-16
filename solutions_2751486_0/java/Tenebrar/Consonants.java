package googlecodejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;

public class Consonants {
	public static void main(String[] args) throws Exception {
		File f = new File("/Users/peter/Downloads/A-small-attempt0.in");
		BufferedReader br = new BufferedReader(new FileReader(f));

		String outputFile = f.getName().substring(0, f.getName().lastIndexOf('.')) + ".out";
		PrintStream ps = new PrintStream(new File(f.getParent(), outputFile));
//		PrintStream ps = System.out;

		int N = Integer.parseInt(br.readLine());

		for (int caseCount = 1; caseCount <= N; caseCount++) {
			String line = br.readLine();

			String name = line.split(" ")[0];
			int n = Integer.valueOf(line.split(" ")[1]);

			long solution = calculateValue(name, n);

			ps.print("Case #" + caseCount + ": ");

			ps.print("" + solution);

			ps.println();
		}

		br.close();
		ps.close();
	}

	private static long calculateValue(String name, int n) {
		boolean[] isConsonant = new boolean[name.length()];
		for (int i = 0; i < isConsonant.length; i++) {
			if (!"aeiou".contains("" + name.charAt(i)))
				isConsonant[i] = true;
		}

		return calculateValue(isConsonant, n);
	}

	private static long calculateValue(boolean[] isConsonant, int n) {
		int length = isConsonant.length;
		long result = 0;
		int lastHit = 0;
		
		int currentLength = 0;
		for(int i = 0; i < isConsonant.length; i++) {
			if(isConsonant[i]) {
				currentLength++;
			} else {
				currentLength = 0;
			}
			
			if(currentLength >= n) {
				int possibleStartIndices = (i - (n - 1) + 1 - lastHit);
				int possibleEndIndices = (length - i);
				
//				System.out.println("adding " + possibleStartIndices + " * " + possibleEndIndices);
				
				result += possibleStartIndices * possibleEndIndices;
				
				lastHit = i - (n - 1) + 1;
			}
		}
		
		return result;
	}
}
