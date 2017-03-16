import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import javax.print.attribute.standard.PrintQuality;


public class A {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		String line;
		StringTokenizer tok;
		for (int ii = 0; ii < T; ii++) {
			line = br.readLine();
			tok = new StringTokenizer(line);
			int A = Integer.parseInt(tok.nextToken());
			int N = Integer.parseInt(tok.nextToken());
			tok = new StringTokenizer(br.readLine());
			int[] a = new int[N];
			for (int i = 0; i < a.length; i++) {
				a[i] = Integer.parseInt(tok.nextToken());
			}
			System.out.printf("Case #%d: %d\n", ii+1, solve(A, N, a));
		}
	}

	public static int solve(int A, int N, int[] a) {
		if (A == 1) {
			return N;
		}
		Arrays.sort(a);
		PriorityQueue<State> q = new PriorityQueue<>();
		q.add(new State(A, 0, 0));
		while ( q.isEmpty() == false ) {
			State act = q.poll();
			if (act.idx == N) {
				return act.ops;
			}
			if (act.size > a[act.idx] ) {
				State ns = new State(act.size + a[act.idx], act.ops, act.idx + 1 );
				q.add(ns);
			} else {
				// add new
				if (act.size > 1) {
					State ns = new State(act.size + act.size - 1, act.ops + 1, act.idx );
					q.add(ns);
				}
				// remove act
				State ns = new State(act.size, act.ops + 1, act.idx + 1);
				q.add(ns);
			}
		}
		throw new IllegalStateException();
	}

	static class State implements Comparable<State>{
		
		long size;
		int ops;
		int idx;

		public State(long size, int ops, int idx) {
			this.size = size;
			this.ops = ops;
			this.idx = idx;
		}

		@Override
		public int compareTo(State o) {
			return Integer.valueOf(this.ops).compareTo(o.ops);
		}
		
	}

}
