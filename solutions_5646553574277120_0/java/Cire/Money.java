/*
 * Eric Schneider
 * 5/10
 */

import java.util.*;

public class Money {
	boolean[] Obtainable;
	int V;
	int lastObst;
	Stack<Integer> Used;
	public Money(int v) {
		V=v;
		lastObst = 1;
		Obtainable = new boolean[V+10];
		Arrays.fill(Obtainable, false);
		Obtainable[0] = true;
		Used = new Stack<Integer>();
	}
	int smallest() {
		int i;
		for(i = lastObst; i < V+5; i++) {
			if (!Obtainable[i]) {
				lastObst = i;
				return i;
			}
		}
		lastObst=i;
		return i;
	}
	
	boolean add(int t, int C) {
		smallest();
		for(int i = V+1; i >=lastObst; i--) {
			if (!Obtainable[i]) {
				// Better pruning??
				for(int j=i-t; j>=Math.max(0, i-C*t); j-=t) {
					if (Obtainable[j]) {
						Obtainable[i] = true;
						break;
					}
				}
			}
		}
		return (smallest()<=V);
	}
	void init(int C) {
		for(int i:Used) {
			add(i,C);
		}
	}
	void greedy(int C) {
		while (smallest()<=V) {
			int t = smallest();
			add(t,C);
			Used.push(t);
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		//Monkey eng = new Brattleship();
		for(int i = 0; i < T; i++) {
			int C = in.nextInt();
			int D = in.nextInt();
			int V = in.nextInt();
			Money eng = new Money(V);
			for(int j = 0; j < D; j++) {
				eng.Used.push(in.nextInt());
			}
			eng.init(C);
			eng.greedy(C);
			System.out.println("Case #" + (i+1) + ": " + (eng.Used.size()-D));
		}
	}
			
}
