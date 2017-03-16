import java.io.*;
import java.math.*;
import java.util.*;

class attack implements Comparable {
	public int d, x;
	public attack (int _d, int _x) {
		d = _d;
		x = _x;
	}
	@Override
	public int compareTo(Object arg0) {
		attack first = this, second = (attack)arg0;
		if (first.d != second.d)
			return first.d - second.d;
		if (first.x != second.x)
			return first.x - second.x;
		return 0;
	}
};


public class ProblemC {
	static Scanner scan = new Scanner (System.in);
	static PrintStream out = System.out;
	static int N;
	static int[] d, n, w, e, s, dd, dp, ds;
	static void test () {
		N = scan.nextInt();
		d = new int[N];
		n = new int[N];
		w = new int[N];
		e = new int[N];
		s = new int[N];
		dd = new int[N];
		dp = new int[N];
		ds = new int[N];
		
		for (int i = 0; i < N; ++i) {
			d[i] = scan.nextInt();
			n[i] = scan.nextInt();
			w[i] = scan.nextInt();
			e[i] = scan.nextInt();
			s[i] = scan.nextInt();
			dd[i] = scan.nextInt();
			dp[i] = scan.nextInt();
			ds[i] = scan.nextInt();
		}
		HashMap<Integer, Integer> hmm = new HashMap<Integer, Integer> ();
		TreeMap<attack, ArrayList<Integer>> strenthMap = new TreeMap<attack, ArrayList<Integer>> ();
		TreeMap<attack, ArrayList<Integer>> strenthMap2 = new TreeMap<attack, ArrayList<Integer>> ();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < n[i]; ++j) {
				int _d = d[i] + j * dd[i];
				int _w = w[i] + j * dp[i];
				int _e = e[i] + j * dp[i];
				int _s = s[i] + j * ds[i];
				for (int k = _w; k < _e; ++k) {
					attack att = new attack (_d, k);
					ArrayList<Integer> tmp = new ArrayList<Integer> ();
					ArrayList<Integer> tmp2 = new ArrayList<Integer> ();
					if (strenthMap.containsKey(att)) {
						tmp = strenthMap.get(att);
						tmp2 = strenthMap2.get(att);
					} 
					tmp.add(_s);
					tmp2.add(i*100+j);
					strenthMap.put(att, tmp);
					strenthMap2.put(att, tmp2);
				}
			}
		}
		HashSet<Integer> hs = new HashSet<Integer> ();
		
		for (attack at : strenthMap.keySet()) {
			int _d = at.d, _k = at.x;
			ArrayList<Integer> al = strenthMap.get(at);
			ArrayList<Integer> al2 = strenthMap2.get(at);
			
			for (int k = 0; k < al.size(); ++k) {
				int currentS = hmm.containsKey(_k) ? hmm.get(_k) : 0;
				if (al.get(k) > currentS) {
					hs.add(al2.get(k));
				}
			}
			int tmp = hmm.containsKey(_k) ? hmm.get(_k) : 0;
			for (Integer _s : al)
				tmp = Math.max(_s, tmp);
			hmm.put(_k, tmp);
		}
		out.println (hs.size());
	}

	
	public static void main (String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			out.print ("Case #" + i + ": ");
			test ();
		}
	}
}
