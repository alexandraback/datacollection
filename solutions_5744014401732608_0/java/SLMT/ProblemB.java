package round1c;

import java.util.Scanner;

public class ProblemB {
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		// Get the number of test cases
		int b;
		long m;
		int totalCases = input.nextInt();
		for (int caseId = 1; caseId <= totalCases; caseId++) {
			// Read numbers
			b = input.nextInt();
			m = input.nextLong();
			
			int[][] slides = getSlides(b, m);
			
			// Print the result
			StringBuilder out = new StringBuilder();
			out.append("Case #" + caseId + ": ");
			if (slides == null)
				out.append("IMPOSSIBLE\n");
			else {
				out.append("POSSIBLE\n");
				for (int i = 0; i < b; i++) {
					for (int j = 0; j < b; j++)
						out.append(slides[i][j]);
					out.append('\n');
				}
			}
			System.out.print(out);
		}
		
		input.close();
	}
	
	private static int[][] getSlides(int b, long m) {
		if (b == 2) {
			if (m > 1)
				return null;
			else {
				return new int[][] {{0, 1}, {0, 0}};
			}
		}
			
		
		// Possible check
		int total = (int) Math.round(Math.pow(2, b - 2));
		if (m - 1 > total)
			return null;
		
		// Possible
		
		// Init
		int[][] slides = new int[b][b];
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < b; j++) {
				if (i > 0 && i < j)
					slides[i][j] = 1;
				else
					slides[i][j] = 0;
			}
		}
		slides[0][b - 1] = 1;
		
		// Translate to binary
		m--;
		long mod;
		int level = 1;
		while (m != 0) {
			mod = m % 2;
			m = m / 2;
			
			if (mod == 1)
				slides[0][level] = 1;
			level++;
		}
		
		return slides;
	}
}
