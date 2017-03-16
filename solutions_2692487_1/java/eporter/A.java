

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

// Using the Google Guava library.
public class A {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/A-large-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			int a = in.nextInt();
			int n = in.nextInt();
			int [] m = new int[n];
			for (int i = 0; i < n; i++) {
				m[i] = in.nextInt();
			}
			Arrays.sort(m);
			
			int s = a;
			int added = 0;
			int min = n;
			outer:
			for (int i = 0; i < n; i++) {
				while (s <= m[i]) {
					s += s-1;
					added++;
					if (added >= min) {
						break outer;
					}
				}
				s += m[i];
				int curScore = added + n - i - 1;
				min = Math.min(min, curScore);
			}
			String caseAns = "Case #"+cs+": "+min;
			out.println(caseAns);
			System.out.println(caseAns);
		}
		out.close();
	}
}
