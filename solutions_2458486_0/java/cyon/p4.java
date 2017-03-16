package qual;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class p4 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}

	private static final int MAX = 41;
	private static int[] vis;
	private static ArrayList<Chest> ktc[]; 
	private static int N;
	
	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int k=Integer.parseInt(st.nextToken());
		N=Integer.parseInt(st.nextToken());
		int[]ck = new int[MAX];
		ktc = new ArrayList[MAX];
		vis = new int[1 << (N+1)];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<k;i++) {
			ck[Integer.parseInt(st.nextToken())-1]++;
		}
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int key = Integer.parseInt(st.nextToken())-1;
			int ka=Integer.parseInt(st.nextToken());
			int keys[] = new int[ka];
			for(int j=0;j<ka;j++)
				keys[j] = Integer.parseInt(st.nextToken())-1;
			Chest c = new Chest(i,key,ka,keys);
			if(ktc[key]==null) ktc[key] = new ArrayList<Chest>();
			ktc[key].add(c);
		}
		for(int i=0;i<ktc.length;i++) {
			if(ktc[i]!=null) {
				Collections.sort(ktc[i]);
			}
		}
//		for(int i=0;i<ktc.length;i++)
//			if(ktc[i] != null)
//				debug(i,ktc[i]);
		
		LinkedList<Integer> seq = new LinkedList<Integer>();
		boolean res = go(0,ck,seq);
		if(!res) return "IMPOSSIBLE";
		StringBuilder sb = new StringBuilder();
		for(Integer i : seq) sb.append(i+1).append(" ");
		sb.deleteCharAt(sb.length()-1);
		return sb.toString();
	}
	
	public static boolean go(int state, int[] keys, LinkedList<Integer> seq) {
		//debug(state, vis[state], (1<<N)-1,keys, seq);
		if (vis[state] == 1)
			return false;
		if (state == (1 << N) - 1)
			return true;
		boolean res = false;
		TreeSet<Chest> reachablec = new TreeSet<Chest>();
		for (int k = 0; k < keys.length; k++) {
			if (keys[k] == 0 || ktc[k] == null)
				continue;
			for (Chest c : ktc[k]) {
				int nstate = (1 << c.id) | state;
				if (nstate == state)
					continue;
				reachablec.add(c);
			}
		}
		for (Chest c : reachablec) {
			int nstate = (1 << c.id) | state;
			if (nstate == state)
				continue;
			seq.add(c.id);
			keys[c.key]--;
			c.inc(keys);
			boolean res0 = go(nstate, keys, seq);
			if (res0) {
				res = true;
				break;
			}
			c.dec(keys);
			keys[c.key]++;
			seq.removeLast();
		}
		vis[state] = 1;
		return res;
	}

	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
	
	private static final class Chest implements Comparable<Chest>{
		int id;
		int key;
		int[]kidx;
		int k;
		public Chest(int id, int key, int k,int[] kidx) {
			super();
			this.id = id;
			this.k = k;
			this.kidx = kidx;
			this.key = key;
		}
		public void inc(int[] keys) {
			for(int i=0;i<kidx.length;i++)
				keys[kidx[i]]++;
		}
		public void dec(int[] keys) {
			for(int i=0;i<kidx.length;i++)
				keys[kidx[i]]--;
		}
		public int compareTo(Chest o) {
			return id - o.id;
		}
		public String toString() {
			return "("+id+","+key+")";
		}
	}
}
