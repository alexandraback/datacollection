import java.util.*;

public class dlarge {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {
			int k = stdin.nextInt();
			int c = stdin.nextInt();
			int s = stdin.nextInt();

			if (s < k-c+1)
				System.out.println("Case #"+loop+": IMPOSSIBLE");

			// regular case
			else {

				long curSize = k;

				// Initial valid solution.
				ArrayList<Long> res = new ArrayList<Long>();
				for (int i=0; i<k; i++)
					res.add((long)i);


				// Run each round.
				for (int i=0; i<c-1; i++) {

					// No point in going any further.
					if (res.size() <= s) break;

					// Reduce by 1...
					res = iter(res, curSize, k);
					curSize *= k;
				}

				// Print result.
				System.out.print("Case #"+loop+":");
				for (int i=0; i<res.size(); i++)
					System.out.print(" "+(res.get(i)+1));
				System.out.println();
			}
		}
	}

	public static ArrayList<Long> iter(ArrayList<Long> list, long n, int k) {

		long start = list.get(0)*k;

		ArrayList<Long> res = new ArrayList<Long>();
		for (int i=1; i<list.size(); i++)
			res.add(start+list.get(i));

		return res;
	}
}