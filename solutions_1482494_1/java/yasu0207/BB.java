import java.util.*;
import java.io.*;


public class BB {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		System.setOut(new PrintStream(new File("B.out")));
		
		int T = sc.nextInt();
		for(int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int a[] = new int[N];
			int b[] = new int[N];
			boolean f[] = new boolean[N];
			PriorityQueue<E> QA = new PriorityQueue<E>();
			PriorityQueue<E> QB = new PriorityQueue<E>();
			int ans = 0;
			for(int i=0; i<N; i++) {
				a[i] = sc.nextInt();
				b[i] = sc.nextInt();
				QA.add(new E(a[i], b[i], i));
				QB.add(new E(b[i], 0, i));
			}
			int st = 0;
			L: for(;!QB.isEmpty();) {
				int x = QB.peek().a;
				int id = QB.poll().id;
				if(st >= x) {
					if(f[id]) {
						st++;
						ans++;
					} else {
						st += 2;
						ans++;
						f[id] = true;
					}
				} else {
					for(;!QA.isEmpty() && st < x;) {
						int y = QA.peek().a;
						int iid = QA.poll().id;
						if(f[iid]) continue;
						if(y > st) {
							ans = 1 << 29;
							break L;
						}
						f[iid] = true;
						ans++;
						st++;
					}
					if(st < x) {
						ans = 1 << 29;
						break L;
					}
					if(f[id]) {
						st++;
						ans++;
					} else {
						st += 2;
						ans++;
						f[id] = true;
					}
				}
			}
			if (ans < 1 << 29)System.out.printf("Case #%d: %d\n", tc, ans);
			else System.out.printf("Case #%d: Too Bad\n", tc);
		}
	}
	static class E implements Comparable<E> {
		int a, b, id;
		E(int a, int b, int id) {
			this.a = a;
			this.b = b;
			this.id = id;
		}
		@Override
		public int compareTo(E e) {
			return a != e.a ? a - e.a: e.b - b;
		}
	}
}
