package gcj2012.round1b;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class C {
	public static void main(String args[]) {
		new C();
	}

	Map<Integer, List<Integer>> tree;
	boolean is_finish;

	public C() {
		Scanner scan = new Scanner(System.in);
		tree = new TreeMap<Integer, List<Integer>>();

		int T = scan.nextInt();
		for(int x=1; x<=T; x++) {
			int N = scan.nextInt();
			List<Integer> list = new ArrayList<Integer>();
			for(int i=0; i<N; i++) {
				list.add(scan.nextInt());
			}

			is_finish = false;
			tree.clear();
			System.out.printf("Case #%d:\n", x);
			for(int i=1; i<N; i++) {
				solve(list, new ArrayList<Integer>(), 0, 0, i);
			}
		}
	}

	public void solve(List<Integer> s, List<Integer> close, int sum, int last_i, int d) {
		if(is_finish) return;

		if(d==0) {
			if(tree.containsKey(sum)) {
				List<Integer> set1 = tree.get(sum);
				int n = set1.size();
				for(int i=0; i<n; i++) {
					System.out.printf("%d ", set1.get(i));
				}
				System.out.println();

				int m = close.size();
				for(int i=0; i<m; i++) {
					System.out.printf("%d ", close.get(i));
				}
				System.out.println();

				is_finish = true;
			}

			tree.put(sum, close);
			return;
		}

		int n = s.size();
		for(int i=last_i; i<n; i++) {
			int m = s.get(i);
			int new_sum = sum + m;
			List<Integer> list = new ArrayList<Integer>();
			List<Integer> new_close = list_copy(close);
			new_close.add(m);
			for(int j=0; j<n; j++) {
				if(i != j) {
					list.add(s.get(j));
				}
			}
			solve(list, new_close, new_sum, i, d-1);
		}
	}

	public List<Integer> list_copy(List<Integer> list) {
		int n = list.size();
		List<Integer> ret = new ArrayList<Integer>();
		for(int i=0; i<n; i++) {
			ret.add(list.get(i));
		}
		return ret;
	}
}
