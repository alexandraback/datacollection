import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;


public class B {

	static class P { 
		int a,b;
		int st;

		public P(int a, int b) {
			super();
			this.a = a;
			this.b = b;
			st = 0;
		}

	}
	
	static class Pc1 implements Comparator<P> {

		@Override
		public int compare(P arg0, P arg1) {
			int c = arg0.b - arg1.b;
			if(c != 0)
				return c;
			return arg0.a - arg1.a;
		}
		
	}
	
	static class Pc2 implements Comparator<P> {

		@Override
		public int compare(P arg0, P arg1) {
			int c = arg1.b - arg0.b;
			if(c != 0)
				return c;
			return arg1.a - arg0.a;
		}
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt();
			int[] a = new int[N];
			int[] b = new int[N];
			P[] d = new P[N];
			for (int j = 0; j < N; j++) {
				a[j] = sc.nextInt();
				b[j] = sc.nextInt();
				d[j] = new P(a[j], b[j]);
			}
			
			Arrays.sort(d, new Pc2());

			
			PriorityQueue<P> pq1 = new PriorityQueue<B.P>(N, new Pc1());
			LinkedList<P> list = new LinkedList<P>();
			for (int j = 0; j < d.length; j++) {
				pq1.add(d[j]);
				list.addLast(d[j]);
			}
			

			int m = 0;
			int r = 0;
			boolean bb = true;

			while(!pq1.isEmpty()) {
				P first = pq1.peek();
				if(first.b <= r) {
					if(first.st > 0) {
						++r;
					} else {
						r += 2;
					}
					++m;
					pq1.poll();
					list.remove(first);
				} else {
					boolean bf = false;
					for (int j = 0; j < list.size(); j++) {
						P curr = list.get(j);
						if(curr.st == 0 && curr.a <= r) {
							++r;
							++m;
							curr.st = 1;
							bf = true;
							break;
						}
					}
					if(!bf) {
						bb = false;
						break;
					}
				}
			}
			

			
			if(bb) {
				System.out.println("Case #" + i+ ": " + m);
			} else {
				System.out.println("Case #" + i+ ": Too Bad");
			}
		}
	}

}
