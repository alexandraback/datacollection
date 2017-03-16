package codejam2016r1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class r_c {
	static int doit(int[] x) {
		int maxc=0;
		boolean[] added = new boolean[x.length-1];
		HashMap<Integer, Integer> pair2res = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> pair2lt = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> st2num = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> st2lt = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> lt2res = new HashMap<Integer, Integer>();
		for (int i=1;i<x.length;i++) {
			Arrays.fill(added, false);
			int stnum=i;
			added[i-1]=true;
			int last = stnum;
			int next = x[stnum];
			while (true) {
				if (added[next-1]==true) {
					break;
				}
				added[next-1]=true;
				last = next;
				next = x[next];
			}
			if (x[next]==last) {
				int n =0;
				for (boolean b : added) if (b) n++;
				st2num.put(stnum, n);
				st2lt.put(stnum, next);
				int key=Math.min(next, last);
				Integer ori =0;
				if (pair2res.get(key) != null) ori=pair2res.get(key);
				if (n>ori) {
					pair2res.put(key, n);
					pair2lt.put(key, last);
				}
				Integer ori2 =0;
				if (lt2res.get(next) != null) ori2=lt2res.get(next);
				if (n>ori2) {
					lt2res.put(next, n);
				}
			}
			else if (stnum==next) {
				int n =0;
				for (boolean b : added) if (b) n++;
				maxc = Math.max(maxc, n);
			}
		}
//		int maxm = 0;
//		for (Integer v : pair2res.values()) maxm+=v;
//		int maxcp =0;
//		for (Integer key : pair2res.keySet()) {
//			Integer v = pair2res.get(key);
//			Integer last = pair2lt.get(key);
//			Integer addv = lt2res.get(last);
//			if (addv!=null) v+=addv-2;
//			maxcp = Math.max(maxcp, v);
//		}
//		System.out.println("pair2res"+pair2res);
//		System.out.println("pair2lt"+pair2lt);
//		System.out.println("st2num"+st2num);
//		System.out.println("st2lt"+st2lt);
//		System.out.println("lt2res"+lt2res);
//		System.out.println("------");
		int maxm=0;
		int submax=0;
		for (Integer key : pair2res.keySet()) {
			Integer v = pair2res.get(key);
			Integer last = pair2lt.get(key);
			Integer addv = lt2res.get(last);
			if (addv!=null) submax = Math.max(addv, submax);
			maxm += v;
		}
		maxm += submax-2;
		int max = Math.max(maxm, maxc);
		return max;
	}
	static public void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("d:/C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter("d:/out");
		int cn = sc.nextInt();
		for (int casei=0;casei<cn;casei++) {
			int N = sc.nextInt();
			int[] x = new int[N+1];
			for (int i=1;i<=N;i++) {
				x[i]=sc.nextInt();
			}
			pw.printf("Case #%d: %d\n", casei+1, doit(x));
		}
		sc.close();
		pw.close();
	}
}
