package org.cj.tso.y2013.r1B;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class A {
	
	private static int findSteps(int A, int motes[], int i) {
		if(i == motes.length) {
			return 0;
		}
		if(motes[i] >= A) {
			int stepsRemove = 0;
			int stepsAdd = 0;
			int addA = A;
			while(addA <= motes[i] && (addA - 1) > 0) {
				addA += addA - 1;
				++stepsAdd;
			}
			if(addA > motes[i]) {
				stepsAdd += findSteps(addA + motes[i], motes, i + 1);
			} else {
				stepsAdd = Integer.MAX_VALUE;
			}
			stepsRemove += 1 + findSteps(A, motes, i + 1);
			return Math.min(stepsAdd, stepsRemove);
		}
		return findSteps(A + motes[i], motes, ++i);
	}
	
	private static void solve(Scanner input, PrintWriter output) {
		int T = input.nextInt();
		for(int i = 1; i <= T; ++i) {
			int A = input.nextInt();
			int N = input.nextInt();
			int motes[] = new int[N];
			for(int n = 0; n < N; ++n) {
				motes[n] = input.nextInt();
			}
			Arrays.sort(motes);
			output.println(String.format(Locale.US, "Case #%d: %d", i, findSteps(A, motes, 0)));
		}
	}

	public static void main(String[] args) throws IOException {
		Scanner input = null;
		PrintWriter output = null;
		try {
			input = new Scanner(new FileReader(args[0]));
			input.useLocale(Locale.US);
			output = new PrintWriter(args[1]);
			solve(input, output);
		} finally {
			if(input != null) {
				input.close();
			}
			if(output != null) {
				output.close();
			}
		}
	}
}
