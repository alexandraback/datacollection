import java.util.*;

class pair implements Comparable<pair> {

	public int ord;
	public int value;

	public pair(int a, int b) {
		ord = a;
		value = b;
	}

	public int compareTo(pair p) {

		if (this.value != p.value)
			return this.value - p.value;
		return this.ord - p.ord;
	}
}

public class b2 {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int T = stdin.nextInt();

		for (int loop=1; loop<=T; loop++) {

			int N = stdin.nextInt();

			pair[] low = new pair[N];
			pair[] high = new pair[N];

			for (int i=0; i<N; i++) {
				int first = stdin.nextInt();
				low[i] = new pair(i, first);
				int second = stdin.nextInt();
				high[i] = new pair(i, second);
			}

			//Arrays.sort(low);
			Arrays.sort(high);
			int ans = solve(low, high);

			if (ans == 1000000)
				System.out.println("Case #"+loop+": Too Bad");
			else
				System.out.println("Case #"+loop+": "+ans);
		}
	}

	public static int solve(pair[] low, pair[] high) {

		// extra is how many times we solve at one star.
		int N = low.length;
		int best = 1000000;
		for (int mask=0; mask< (int)(Math.pow(2,N)+.01); mask++) {

			if (canSolve(low, high, mask)) {

				int bits = numbits(mask);
				if (bits+N < best)
					best = bits+N;
			}

		}

		return best;

	}

	public static int numbits(int val) {

		int ans = 0;
		while (val > 0) {
			if (val%2 == 1)
				ans++;
			val /= 2;
		}
		return ans;
	}

	public static boolean haszero(int[] array) {

		for (int i=0; i<array.length; i++)
			if (array[i] == 0)
				return true;
		return false;
	}

	public static int findbest(pair[] low, int[] visited) {

		int best = -1;
		for (int i=0; i<visited.length; i++)
			if (visited[i] == 0) {
				if (best == -1)
					best = i;
				else if (low[i].value < low[best].value)
					best = i;
			}
		return best;
	}

	public static boolean canSolve(pair[] low, pair[] high, int mask) {

		int N = low.length;
		int[] visited = new int[N];


		for (int i=0; i<N; i++) {
			if ((mask & 1) == 1)
				visited[i] = 0;
			else
				visited[i] = -1;
			mask = mask >> 1;
		}

		int highi = 0;
		int stars = 0;
		while (highi < N) {

			if (haszero(visited)) {

				//find best low guy
				int lowi = findbest(low, visited);

				if (low[lowi].value <= high[highi].value) {

					if (stars >= low[lowi].value) {
						stars++;
						visited[lowi] = 1;
						lowi++;

					}
					else
						return false;

				}
				else {

					if (stars >= high[highi].value) {


						// Update stars.
						if (visited[high[highi].ord] == 1)
							stars++;
						else {
							stars += 2;
						}
						highi++;
					}
					else
						return false;


				}

			} // end biggest if
			else {

					if (stars >= high[highi].value) {


						// Update stars.
						if (visited[high[highi].ord] == 1)
							stars++;
						else {
							stars += 2;
						}
						highi++;
					}
					else
						return false;
			}

		} // ends while

		return true;
	}
}