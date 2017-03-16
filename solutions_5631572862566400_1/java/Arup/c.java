import java.util.*;

public class c {

	public static int n;
	public static int[] bff;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {


			n = stdin.nextInt();
			bff = new int[n];
			for (int i=0; i<n; i++)
				bff[i] = stdin.nextInt()-1;

			int[] cyclelen = new int[n];
			Arrays.fill(cyclelen, -1);


			// 0 means not in a cycle.

			for (int i=0; i<n; i++) {
				if (cyclelen[i] == -1) {

					ArrayList<Integer> curChain = new ArrayList<Integer>();
					boolean[] used = new boolean[n];
					curChain.add(i);
					used[i] = true;
					int next = i;
					while (true) {
						next = bff[next];
						curChain.add(next);
						if (used[next]) break;
						used[next] = true;
					}

					int loc = 0;
					while (curChain.get(loc) != next) loc++;
					int ans = curChain.size() - 1 - loc;
					for (int j=loc; j<curChain.size(); j++)
						cyclelen[curChain.get(j)] = ans;
					for (int j=0; j<loc; j++)
						cyclelen[curChain.get(j)] = 0;

				}
			}

			// reg cycle.
			int res = cyclelen[0];
			for (int i=1; i<n; i++)
				res = Math.max(res, cyclelen[i]);

			// just in case
			int[] indeg = new int[n];
			for (int i=0; i<n; i++)
				indeg[bff[i]]++;

			ArrayList[] revGraph = new ArrayList[n];
			for (int i=0; i<n; i++)
				revGraph[i] = new ArrayList<Integer>();
			for (int i=0; i<n; i++)
				revGraph[bff[i]].add(i);

			int other = 0;
			// Look for in cycle len 2.
			for (int i=0; i<n; i++) {

				if (bff[bff[i]] == i) {
					int v1 = i;
					int v2 = bff[i];
					int[] memo = new int[n];
					Arrays.fill(memo, -1);
					int tail1 = revGraph[v1].size() > 1 ? getTail(revGraph, v1, memo, v2) : 1;
					Arrays.fill(memo, -1);
					int tail2 = revGraph[v2].size() > 1 ? getTail(revGraph, v2, memo, v1) : 1;
					other += (tail1+tail2);
				}

			}

			res = Math.max(res, other/2);


			System.out.println("Case #"+loop+": "+res);
		}
	}

	public static int getTail(ArrayList[] revGraph, int v, int[] memo, int skip) {

		if (memo[v] != -1) return memo[v];
		if (revGraph[v].size() == 0) return 1;

		int best = 0;
		for (int i=0; i<revGraph[v].size(); i++) {
			int next = ((ArrayList<Integer>)revGraph[v]).get(i);
			if (next == skip) continue;
			int tmpRes = getTail(revGraph, next, memo, skip);
			best = Math.max(best, tmpRes+1);
		}
		memo[v] = best;
		return best;
	}
}