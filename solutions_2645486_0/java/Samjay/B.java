package con2013R1A;

import java.io.*;
import java.util.*;

public class B {

	private static final String islarge = "-large";
	private static final String fileName = "results/con2013R1A/"+B.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	static class P implements Comparable<P>{
		int id, val;
		public P(int id, int val) {
			this.id=id;this.val=val;
		}
		@Override
		public int compareTo(P p) {
			return this.val >= p.val?-1:1;
		}
		
	}
	
	static int[] ns;
	private void solve() {
		int MAX = in.nextInt();
		int regain = in.nextInt();
		int N = in.nextInt();
		long sum=0;
		ns = new int[N];
		P[] ps = new P[N];
		int[]left=new int[N];
		long total = 0;
		for(int i=0;i<N;i++){
			ns[i]=in.nextInt();
			sum+=ns[i];
			ps[i] = new P(i,ns[i]);
			left[i]=MAX;
		}
		if(regain >= MAX){
			total=(sum*MAX);
		}else{
			Arrays.sort(ps);
			for(int i=0;i<N;i++){
				total+=ps[i].val*left[ps[i].id];
				int am = 0, id=ps[i].id;
				while(id<N && am<MAX && left[id]>am){
					left[id] = am;
					id++;am+=regain;
				}
				id=ps[i].id-1;
				am=regain;
				while(id >= 0 && am < MAX && left[id] > am){
					left[id] = am;
					id--;am+=regain;
				}
			}
		}		
		System.out.println(total);
		out.println(total);
	}

	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
