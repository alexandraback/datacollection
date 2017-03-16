package Round1C2015;

import java.io.*;
import java.util.*;

public class TypewriterMonkey {
	public static Scanner in = new Scanner(System.in);
	public static PrintWriter PW = new PrintWriter(System.out);

	public static void main(String[] args) throws IOException {
		int cases = in.nextInt();

		for (int c = 1; c <= cases; c++) {
			double result;
			int K = in.nextInt(), L = in.nextInt(), S = in.nextInt();

			char[] keyboard = in.next().toCharArray();
			char[] target = in.next().toCharArray();
			// don't even bother doing KMP

			int[] letters = new int[26];
			for (int i = 0; i < K; i++)
				letters[keyboard[i] - 'A']++;

			boolean[] starts = new boolean[L];

			for (int i = 0; i < L; i++) {
				boolean matches = true;
				for (int j = i; j < L; j++) {
					matches &= (target[j - i] == target[j]);
				}
				starts[i] = matches;
			}
			// starts[i] says whether an overlapping instance of the target
			// starts in position i

			boolean possible = true;
			for (int i = 0; i < L; i++)
				possible &= (letters[target[i] - 'A'] > 0);
			
			int min = L;
			for(int i = L-1; i>0;i--)
				if(starts[i])
					min = i;
			
			int bananas = (possible?1+(S-L)/min:0);
			//we now have the total number of necessary bananas
			
			double expected = 1;
			for(int i = 0; i<L;i++)
				expected *= ((double) letters[target[i]-'A'])/K;
			expected *= (S-L+1);
			
			result = bananas-expected;
			
			PW.println("Case #" + c + ": " + result);
		}

		PW.close();
	}
}