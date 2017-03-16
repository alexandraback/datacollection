import java.util.*;

public class a {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		// Go through all cases.
		for (int loop=1; loop<=numCases; loop++) {

			int n = stdin.nextInt();
			int[] vals = new int[n+1];
			String s = stdin.next();

			// Convert to a frequency array.
			for (int i=0; i<s.length(); i++)
				vals[i] = s.charAt(i) - '0';

			// Simulate - at each step, see how many extras would
			// need to stand up at that time to get these people to
			// stand up.
			int curUp = vals[0], res = 0;
			for (int i=1; i<vals.length; i++) {
				res = Math.max(res, i-curUp);
				curUp += vals[i];
			}

			// This is our answer.
			System.out.println("Case #"+loop+": "+res);
		}
	}
}