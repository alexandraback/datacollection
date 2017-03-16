package qualA2016;

import java.util.*;

public class B {
	public static void main(String... args) {
		Scanner s = new Scanner(System.in);
		
		final int T = s.nextInt();
		
		for (int t = 1; t <= T; t++) {
			N = s.nextInt();
			lists = new int[2*N-1][N];
			
			for (int i = 0; i < 2*N-1; i++) {
				for (int j = 0; j < N; j++) {
					lists[i][j] = s.nextInt();
				}
			}
			
			System.out.printf("Case #%d: %s\n", t, solve());
		}
		
		s.close();
	}
	
	static int N;
	static int[][] lists;
	
	static String solve() {
		Arrays.sort(lists, new Comparator<int[]>() {
			@Override
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		Map<Integer,Integer> m = new HashMap<>();
		
		for (int[] ll : lists) {
			for (int l : ll) {
				if (m.containsKey(l)) {
					m.put(l, m.get(l) + 1);
				} else {
					m.put(l, 1);
				}
			}
		}
		
		List<Integer> l = new ArrayList<>(N);
		
		for (Map.Entry<Integer, Integer> e : m.entrySet()) {
			int v = e.getValue();
			if (v % 2 == 1) {
				l.add(e.getKey());
			}
		}
		
		Collections.sort(l);
		StringBuilder sb = new StringBuilder();
		for (Integer i : l) {
			sb.append(i);
			sb.append(' ');
		}
		
		return sb.toString();
	}
}
