import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class C {
	public static final String FILENAME = "C-small-attempt0";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner sc = new Scanner(in);
		C c = new C();
		int T = sc.nextInt();
		for(int i = 1; i <= T; i++) {
			int N = sc.nextInt();
			int[] d = new int[N];
			int[] n = new int[N];
			Interval[] inter = new Interval[N];
			int[] delta_d = new int[N];
			int[] delta_p = new int[N];
			int[] delta_s = new int[N];
			for (int j = 0; j < N; j++) {
				d[j] = sc.nextInt();
				n[j] = sc.nextInt();
				inter[j] = c.new Interval(sc.nextInt(), sc.nextInt(), sc.nextInt());
				delta_d[j] = sc.nextInt();
				delta_p[j] = sc.nextInt();
				delta_s[j] = sc.nextInt();
			}
			
			List<Interval> wall = new LinkedList<Interval>();
			int ret = 0;
			int alive = N;
			
			while(alive > 0) {
				//find attackers
				int min = -1;
				boolean[] attack = new boolean[N];
				for (int j = 0; j < N; j++) {
					if(d[j] != -1) {
						if(min == -1 || d[j] < min) {
							attack = new boolean[N];
							min = d[j];
						}
						if(d[j] == min) {
							attack[j] = true;
						}
					}
				}
				
				//attack
				for (int j = 0; j < N; j++) {
					if(attack[j]) {
						List<Interval> hi = new LinkedList<Interval>();
						for (Interval ti: wall) {
							if(inter[j].s <= ti.s) {
								hi = ti.union(hi);
							}
						}
						boolean success = true;
						for (Interval ti: hi) {
							if(ti.contains(inter[j])) {
								success = false;
							}
						}
						if(success) {
							ret++;
						}
					}
				}
				
				//update wall
				for (int j = 0; j < N; j++) {
					if(attack[j]) {
						wall.add(inter[j].clone());
					}
				}
				
				//update tribes
				for (int j = 0; j < N; j++) {
					if(attack[j]) {
						d[j] += delta_d[j];
						n[j]--;
						inter[j].w += delta_p[j];
						inter[j].e += delta_p[j];
						inter[j].s += delta_s[j];
						if(n[j] == 0) {
							alive--;
							d[j] = -1;
						}
					}
					if(d[j] != -1) {
						d[j] -= min;
					}
				}
			}
			
			//output
			out.write("Case #"+i+": "+ret+"\n");
		}
		in.close();
		out.close();
	}
	
	class Interval {
		int w;
		int e;
		int s;
		
		public Interval(int w, int e, int s) {
			this.w = w;
			this.e = e;
			this.s = s;
		}
		
		public boolean intersects(Interval i) {
			return !(e < i.w || w > i.e);
		}
		
		public boolean contains(Interval i) {
			return w <= i.w && e >= i.e;
		}
		
		public List<Interval> union(List<Interval> l) {
			int nw = w;
			int ne = e;
			int ns = s;
			List<Interval> intersect = new LinkedList<Interval>();
			for (Interval i: l) {
				if(intersects(i)) {
					intersect.add(i);
					nw = Math.min(nw, i.w);
					ne = Math.max(ne, i.e);
					ns = Math.min(ns, i.s);
				}
			}
			l.removeAll(intersect);
			l.add(new Interval(nw, ne, ns));
			return l;
		}
		
		public Interval clone() {
			return new Interval(w, e, s);
		}
	}
}
