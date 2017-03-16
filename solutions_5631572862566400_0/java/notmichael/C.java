import java.util.*;

public class C {

	public static void main(String[] args) {
		C c = new C();
		c.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int n = Integer.parseInt(in.nextLine());
			ArrayList<HashSet<Integer>> inc = new ArrayList<>();
			for (int i=0; i<n; i++) {
				inc.add(new HashSet<>());
			}
			int[] out = new int[n];
			String[] split = in.nextLine().split(" ");
			for (int i=0; i<n; i++) {
				int f = Integer.parseInt(split[i]);
				out[i] = f-1;
				inc.get(f-1).add(i);
			}
			int max = 0;
			boolean[] visited = new boolean[n];
			for (int i=0; i<n; i++) {
				if (!visited[i]) {
					int len = 1;
					HashSet<Integer> temp = new HashSet<>();
					temp.add(i);
					int j = out[i];
					while (!visited[j] && !temp.contains(j)) {
						temp.add(j);
						len++;
						j = out[j];
					}
					if (j==i) {
						max = Math.max(len,max);
						for (Integer k: temp) {
							visited[k] = true;
						}
					}
				}
			}
			ArrayList<int[]> pairs = new ArrayList<>();
			for (int i=0; i<n; i++) {
				int j = out[i];
				if (j>i && out[j]==i) {
					pairs.add(new int[]{i,j});
				}
			}
			int other = 0;
			for (int[] p: pairs) {
				ArrayDeque<int[]> q = new ArrayDeque<>();
				for (Integer i: inc.get(p[0])) {
					if (i!=p[1])
					q.add(new int[]{i,1});
				}
				int left = 0;
				while (!q.isEmpty()) {
					int[] off = q.poll();
					left = Math.max(left,off[1]);
					for (Integer i: inc.get(off[0])) {
						q.add(new int[]{i,off[1]+1});
					}
				}
				int right = 0;
				for (Integer i: inc.get(p[1])) {
					if (i!=p[0])
					q.add(new int[]{i,1});
				}
				while (!q.isEmpty()) {
					int[] off = q.poll();
					right = Math.max(right,off[1]);
					for (Integer i: inc.get(off[0])) {
						q.add(new int[]{i,off[1]+1});
					}
				}
				other += left+right+2;
			}
			max = Math.max(other,max);
			System.out.printf("Case #%d: %d\n",a+1,max);
		}
	}

}