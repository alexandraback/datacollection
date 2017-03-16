package gcj.round1a;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class B {
	public static void main(String args[]) {
		new B();
	}

	public B() {
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		List<Pair> list = new ArrayList<Pair>();

		for(int x=0; x<T; x++) {
			list.clear();

			int N = scan.nextInt();
			for(int i=0; i<N; i++) {
				int first = scan.nextInt();
				int second = scan.nextInt();
				list.add(new Pair(first, second));
			}

			Collections.sort(list);
			int n_star = 0;
			int n_trial = 0;
			boolean is_bad = false;

			for(int i=0; i<N; i++) {
				Pair p = list.get(i);
				is_bad = false;

				while(n_star < p.second) {
					boolean is_change = false;
					for(int j=N-1; j>=0; j--) {
						Pair q = list.get(j);
						if(q.end_first) continue;

						if(n_star >= q.first) {
							n_star += 1;
							n_trial++;
							q.end_first = true;
							is_change = true;
						}

						if(n_star >= p.second) break;
					}

					if(!is_change) {
						is_bad = true;
						break;
					}
				}

				if(is_bad) break;

				n_star += p.end_first ? 1 : 2;
				n_trial++;
				p.end_first = true;
				p.end_second = true;
			}

			System.out.printf("Case #%d: ", x+1);
			if(is_bad) System.out.println("Too Bad");
			else System.out.printf("%d\n", n_trial);
		}
	}

	public static class Pair implements Comparable<Pair> {
		int first;
		int second;
		boolean end_first;
		boolean end_second;

		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
			end_first = false;
			end_second = false;
		}

		public int compareTo(Pair p) {
			if(second == p.second) {
				return p.first - first;
			}

			return second - p.second;
		}
	}
}
