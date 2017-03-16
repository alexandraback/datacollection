import java.util.*;

public class c {

	public static int n;
	public static int[] bffs;
	public static ArrayList<Integer>[] adjs, revs;
	public static int max;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
//gen();
		int t = in.nextInt();

		for(int caseN = 1; caseN <= t; caseN++) {
			n = in.nextInt();
			bffs = new int[n];
			//revs = new int[n];
			revs = new ArrayList[n];
			for(int i = 0; i < n; i++)
				revs[i] = new ArrayList<Integer>();

			for(int i = 0; i < n; i++) {
				bffs[i] = in.nextInt() - 1;
				revs[bffs[i]].add(i);
			}

			DisjointSet dSet = new DisjointSet(n);
			for(int i = 0; i < n; i++) {
				int a = i;
				int b = bffs[i];
				dSet.union(a, b);

			}

			//ArrayList<Integer> maxCycles = new ArrayList<Integer>();
			//ArrayList<Integer> maxLines = new ArrayList<Integer>();

			int maxCycle = 0;
			int maxLine = 0;

			ArrayList<Integer>[] sets = new ArrayList[n];
			for(int i = 0; i < n; i++)
				sets[i] = new ArrayList<Integer>();
			for(int i = 0; i < n; i++) {
				int par = dSet.find(i);
				sets[par].add(i);
			}
			boolean[] vis = new boolean[n];
			for(ArrayList<Integer> set : sets) {
				if(set.size() == 0) continue;
				int tempMaxCycle = 0;
				int tempMaxLine = 0;
				for(int start : set) {
					vis[start] = true;
					//System.out.println("Starting at " + start);
					int[] temp = go(vis, start, start, 1);
					vis[start] = false;
					tempMaxCycle = Math.max(tempMaxCycle, temp[0]);
					tempMaxLine = Math.max(tempMaxLine, temp[1]);
				}
				//System.out.println(tempMaxCycle + "  " + tempMaxLine);
				maxCycle = Math.max(maxCycle, tempMaxCycle);
				maxLine += tempMaxLine;
			}

			System.out.println("Case #" + caseN + ": " + Math.max(maxLine, maxCycle));
		}

	}

	public static int[] go(boolean[] vis, int first, int cur, int len) {
		//System.out.println("    at " + cur + "    " + len);
		int maxCycle = 0;
		int maxLine = 0;

		int next = bffs[cur];
			if(vis[next]) {
				if(first != next) {
					if(bffs[next] == cur) {
						maxLine = Math.max(maxLine, len);
						int temp = go2(vis, first, cur, len);
						maxLine = Math.max(maxLine, temp);
					}
				} else {
					maxCycle = Math.max(maxCycle, len);
					if(len == 2)
						maxLine = Math.max(maxLine, len);
				}
			} else {
				vis[next] = true;
				int[] temp = go(vis, first, next, len + 1);
				maxCycle = Math.max(maxCycle, temp[0]);
				maxLine = Math.max(maxLine, temp[1]);
				vis[next] = false;
			}

		return new int[]{maxCycle, maxLine};
	}

	//travel reverse edges now.
	public static int go2(boolean[] vis, int first, int cur, int len) {
		//System.out.println("    rev at " + cur + "    " + len);
		int maxCycle = len;

		for(int next : revs[cur]) {
			if(vis[next]) {
				continue;
			} else {
				vis[next] = true;
				int temp = go2(vis, first, next, len + 1);
				maxCycle = Math.max(maxCycle, temp);
				vis[next] = false;
			}
		}
		return maxCycle;
	}

	public static void gen() {
		System.out.println(100);
		Random rand = new Random();
		for(int caseN = 0; caseN < 100; caseN++) {
			int n = rand.nextInt(999) + 2;
			System.out.println(n);
			for(int i = 1; i <= n; i++) {
				int a = i;
				while(a == i) a = rand.nextInt(n) + 1;
				System.out.print(a + " ");
			}
			System.out.println();
		}

		System.exit(0);
	}

static class DisjointSet {
	int[] set;
	
	public DisjointSet(int n) { // O(n)
		set = new int[n];
		for (int i = 0; i < n; i++)
			set[i] = i;
	}
	
	public int find(int i) { // O(1)
		return set[i] = (set[i] == i ? i : find(set[i]));
	}
	
	public void union(int a, int b) { // O(1)
		if(find(a) == find(b)) return;
		set[find(a)] = find(b);
	}
}

	public static void go(int[] arr, boolean[] used, int pos) {
		//System.out.println(Arrays.toString(arr));
		boolean good = true;
		for(int i = 0; i < pos; i++) {
			int prev = (i + pos - 1) % (pos);
			int next = (i + 1) % (pos);
			//System.out.println(prev + " " + next);
			if(bffs[arr[i]] != arr[prev] && bffs[arr[i]] != arr[next]) {
				good = false;
				break;
			}
		}
		if(good)
			max = Math.max(max, pos);

		if(pos == n) {
			good = true;
			for(int i = 0; i < pos; i++) {
				int prev = (i + pos - 1) % (pos);
				int next = (i + 1) % (pos);
				//System.out.println(prev + " " + next);
				if(bffs[arr[i]] != arr[prev] && bffs[arr[i]] != arr[next]) {
					good = false;
					break;
				}
			}
if(good)
			max = Math.max(max, pos);
			return;
		}

		for(int next = 0; next < n; next++) {
			if(used[next]) continue;
			used[next] = true;
			arr[pos] = next;
			go(arr, used, pos + 1);
			used[next] = false;
		}
	}

}