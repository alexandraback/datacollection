import java.util.*;

public class dlarge {

	final public static String[] NAMES = {"RICHARD","GABRIEL"};

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		// Go through all cases.
		for (int loop=1; loop<=numCases; loop++) {

			int size = stdin.nextInt();
			int[] dim = new int[2];
			dim[0] = stdin.nextInt();
			dim[1] = stdin.nextInt();
			Arrays.sort(dim);

			// This is our answer.
			System.out.println("Case #"+loop+": "+solve(size, dim));
		}
	}

	public static String solve(int size, int[] dim) {

		int sq = dim[0]*dim[1];

		if (sq%size != 0 || dim[1] < size || size >= 7) return NAMES[0];
		if (size < 3) return NAMES[1];

		if (size == 3) {
			if (dim[0] >= 2) return NAMES[1];
			else			 return NAMES[0];
		}

		if (size == 4) {
			if (dim[0] >= 3) return NAMES[1];
			else			 return NAMES[0];
		}

		if (size == 6) {
			if (dim[0] >= 4) return NAMES[1];
			else			 return NAMES[0];
		}


		if (dim[0] > 3) return NAMES[1];
		if (dim[0] < 3) return NAMES[0];

		if (dim[1] >= 10) return NAMES[1];
		else			  return NAMES[0];


	}
}