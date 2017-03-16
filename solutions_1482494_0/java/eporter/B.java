

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

//Using the Google Collections library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-small-attempt1.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int c = 1; c <= cases; c++) {
			int n = in.nextInt();
			int [][] levels = new int [n][2];
			for (int i = 0; i < n; i++) {
				levels[i][0] = in.nextInt();
				levels[i][1] = in.nextInt();
			}
			int [] cur = new int[n];
			int stars = 0;
			int completed = 0;
			outer:
			while (stars < 2 * n) {
				int bestDif = 0;
				int bestLevel = -1;
				int largestSecondLevel = -1;
				for (int i = 0; i < n; i++) {
					if (levels[i][0] <= stars && cur[i] == 0 && bestDif <= 1) {
						if (levels[i][1] > largestSecondLevel) {
							bestDif = 1;
							bestLevel = i;
							largestSecondLevel = levels[i][1];
						}
					}
					// prioritize finishing a level
					if (levels[i][1] <= stars && cur[i] < 2) {
						bestDif = 2 - cur[i];
						bestLevel = i;
						largestSecondLevel = Integer.MAX_VALUE;
						if (bestDif == 2) {
							cur[i] = 2;
							stars += 2;
//							System.out.println("adding 2 to " + bestLevel);
							completed++;
							continue outer;
						}
						break;
					}
				}
				if (bestLevel < 0)
					break;
				stars += bestDif;
				cur[bestLevel] += bestDif;
//				System.out.println("adding 1 to " + bestLevel);
				completed++;
			}
//			System.out.println(stars);
			String ans = "Too Bad";
			if (stars == 2 * n)
				ans = String.valueOf(completed);
			out.print("Case #"+c+": " + ans);
			out.println();
		}
		out.close();
	}
}
