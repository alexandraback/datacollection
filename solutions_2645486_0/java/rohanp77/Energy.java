import java.io.*;
import java.math.*;
import java.util.*;

import org.omg.CORBA.LongSeqHelper;

public class Energy {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	static String NAME = "energy";
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(NAME+".in"));
		out = new PrintWriter(new FileWriter(NAME+".out"));
		
		int tt = nextInt();
		for (int t=1; t<=tt; t++) {
			out.printf("Case #%d: ", t);
			
			long energy = nextLong(), regain = nextLong();
			int num = nextInt();
			State[] acts = new State[num];
			for (int i=0; i<num; i++)
				acts[i] = new State(i, nextLong());
			Arrays.sort(acts);
			long ans = 0;
			long[] max = new long[num]; //max ENTRY energy
			long[] min = new long[num]; //min EXIT energy
			Arrays.fill(max, energy);
			
			for (int i=0; i<acts.length; i++) {
				int ind = acts[i].ind;
				long use = max[ind] - min[ind];
				ans += use * acts[i].val;
				for (int j=1; j+ind<max.length; j++) {
					long next = min[ind] + j*regain;
					if (max[j+ind] <= next)
						break;
					else
						max[j+ind] = next;
				}
				for (int j=1; ind-j>=0; j++) {
					long next = max[ind] - j*regain;
					if (min[ind-j] >= next)
						break;
					else
						min[ind-j] = next;
				}
			}
			
			out.println(ans);
		}
		
		in.close();
		out.close();
	}
	
	private static class State implements Comparable<State>{
		int ind;
		long val;
		public State(int ind, long val) {
			super();
			this.ind = ind;
			this.val = val;
		}
		@Override
		public int compareTo(State o) {
			return -Long.valueOf(val).compareTo(o.val);
		}
	}
}
