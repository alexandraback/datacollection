package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;


public class R1C_2013_B {

	static class Tribe {
		int nextDay;
		int attacksLeft;
		int left,right;
		int stregth, deltaStrength;
		int deltaX;
		int deltaDay;
		int num;
		public Tribe(int ix,int nextDay, int attacksLeft, int left, int right,
				int stregth, int deltaStrength, int deltaX, int deltaDay) {
			super();
			this.nextDay = nextDay;
			this.attacksLeft = attacksLeft;
			this.left = left;
			this.right = right;
			this.stregth = stregth;
			this.deltaStrength = deltaStrength;
			this.deltaX = deltaX;
			this.deltaDay = deltaDay;
			this.num = ix;
		}
		
		void update() {
			stregth += deltaStrength;
			nextDay += deltaDay;
			left += deltaX;
			right += deltaX;
			attacksLeft -= 1;
		}
		
		boolean wins(int[] Hs, int center) {
			for (int i=left; i<right; i++) {
				if (Hs[i+center]<stregth) {
					return true;
				}
			}
			return false;
		}

		public void raise(int[] hs, int center) {
			for (int i=left; i<right; i++) {
				if (Hs[i+center]<stregth) {
					Hs[i+center]=stregth;
				}
			}			
		}
	}
	
	static final int center = 1000;
	static int[] Hs = new int[center*2+1];
	
	static void print() {
		for (int i=-20; i<=20; i++) {
			if (i==0) {
				
				System.err.print("[");
			}
			System.err.print(Hs[i+center]+" ");
			if (i==0) {
				
				System.err.print("]");
			}
		}
		System.err.println("");
	}
	
	static long run(List<Tribe> tribes) {
		Arrays.fill(Hs,0);
		
		PriorityQueue<Tribe> q = new PriorityQueue<Tribe>(tribes.size(), new Comparator<Tribe>() {
			@Override
			public int compare(Tribe o1, Tribe o2) {
				return o1.nextDay-o2.nextDay;
			}
			
		});
		q.addAll(tribes);
		int succeeded = 0;
		while (q.size()>0) {
			
			int day = q.peek().nextDay;
			
			System.err.println("Day "+day);
			List<Tribe> attacked = new LinkedList<Tribe>();
			while (!q.isEmpty() && q.peek().nextDay==day) {
				Tribe t = q.poll();
//				System.err.println("Tribe "+t.num);
				if (t.wins(Hs,center)) {
//					System.err.println("Tribe "+t.num+" wins at height "+t.stregth);
					succeeded ++;
				} else {
//					System.err.println("Tribe "+t.num+" does not win");
				}
				attacked.add(t);
			}
			for (Tribe t: attacked) {
				t.raise(Hs,center);
				t.update();
				if (t.attacksLeft>0) { 
					q.add(t);
				}
			}
//			System.err.println("End of day "+day+"...");
			//print();
			
		}
		return succeeded;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		FileWriter fw = new FileWriter(new File("/home/herchu/tc/eclipse/tc/src/gcj/run.out"));
		int cases = Integer.parseInt(br.readLine());
		for (int cc=1; cc<=cases; cc++) {
			int N = Integer.parseInt(br.readLine());
			
			List<Tribe> tribes = new ArrayList<Tribe>();
			for (int i=0; i<N; i++) {
				int di,ni,wi,ei,si,deltad,deltap,deltas;
				String ss[] = br.readLine().split(" ");
				di = Integer.parseInt(ss[0]);
				ni = Integer.parseInt(ss[1]);
				wi = Integer.parseInt(ss[2]);
				ei = Integer.parseInt(ss[3]);
				si = Integer.parseInt(ss[4]);
				deltad = Integer.parseInt(ss[5]);
				deltap = Integer.parseInt(ss[6]);
				deltas = Integer.parseInt(ss[7]);
				
				Tribe t = new Tribe(i, di, ni, wi, ei, si, deltas, deltap, deltad);
				tribes.add(t);
			}
			
			long ret = run(tribes);
			String sss = String.format("Case #%d: %d", cc, ret);
			System.out.println(sss);
			fw.write(sss+"\n");
		}
		fw.flush();
		fw.close();
	}
}
