package code12.qualification;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class B {
	public static String solve(int N, int S, int p, int[] t) {
		
		// 3a 		-> (a, a, a), *(a - 1, a, a + 1)
		// 3a + 1	-> (a, a, a + 1), *(a - 1, a + 1, a + 1)
		// 3a + 2	-> (a, a + 1, a + 1), *(a, a, a + 2)
		
		int numPNoS = 0;
		int numPWithS = 0;
		
		for (int i = 0; i < N; i++) {
			int a = (int)Math.floor(t[i] / 3);
			int r = t[i] % 3;
			
			switch (r) {
			case 0:
				if (a >= p) {
					numPNoS++;
				} else if (a + 1 >= p && a - 1 >= 0) {
					numPWithS++;
				}
				break;
			case 1:
				if (a >= p || a + 1 >= p) {
					numPNoS++;
				}
				break;
			case 2:
				if (a >= p || a + 1 >= p) {
					numPNoS++;
				} else if (a + 2 >= p) {
					numPWithS++;
				}
				break;
			}
		}
		
		return "" + (numPNoS + Math.min(S, numPWithS));
	}

	public static void main(String[] args) throws Exception {
		// file name
		//String fileName = "Sample";
		//String fileName = "B-small";
		String fileName = "B-large";
		
		// file variable
		File inputFile = new File(fileName + ".in");
		File outputFile = new File(fileName + ".out");
		Scanner scanner = new Scanner(inputFile);
		FileWriter writer = new FileWriter(outputFile);

		// problem variable
		int totalCase;
		int N, S, p;
		int[] t;

		// get total case
		totalCase = scanner.nextInt();

		for (int caseIndex = 1; caseIndex <= totalCase; caseIndex++) {
			// get input
			N = scanner.nextInt();
			S = scanner.nextInt();
			p = scanner.nextInt();
			t = new int[N];
			
			for (int i = 0; i < N; i++) {
				t[i] = scanner.nextInt();
			}
			
			String output = "Case #" + caseIndex + ": " + solve(N, S, p, t);
			System.out.println(output);
			writer.write(output + "\n");
		}
		scanner.close();
		writer.close();
	}
}
