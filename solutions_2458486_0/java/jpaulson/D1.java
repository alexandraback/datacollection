import java.util.*;

public class D1 {
	static int[] T;
	static List<List<Integer>> R;
	
	static int set_to_int(boolean[] SET) {
		int x = 0;
		for(int i=0; i<SET.length; i++)
			if(SET[i])
				x |= 1<<i;
		return x;
	}
	
	static int n;
	static boolean[] SEEN;
	static boolean[] DP;
	static boolean ok(boolean[] DONE, int[] keys) {
		int set = set_to_int(DONE);
		if(Integer.bitCount(set) == n) return true;
		if(SEEN[set]) return DP[set];
		SEEN[set] = true;
		
		for(int i=0; i<n; i++) {
			if(!DONE[i] && keys[T[i]]>=1) {
				keys[T[i]]--;
				for(Integer key : R.get(i))
					keys[key]++;
				DONE[i] = true;
				boolean was_ok = ok(DONE, keys);
				DONE[i] = false;
				keys[T[i]]++;
				for(Integer key : R.get(i))
					keys[key]--;
				
				if(was_ok) return DP[set] = true;
			}
		}
		return DP[set] = false;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int TT = in.nextInt();
		CAS: for(int cas=1; cas<=TT; cas++) {
			int k = in.nextInt();
			n = in.nextInt();
			
			DP = new boolean[1<<n];
			SEEN = new boolean[1<<n];
			
			T = new int[n];
			R = new ArrayList<List<Integer>>();
			for(int i=0; i<n; i++) R.add(new ArrayList<Integer>());
			int[] keys = new int[200];
			for(int i=0; i<k; i++)
				keys[in.nextInt()-1]++;
			for(int i=0; i<n; i++) {
				T[i] = in.nextInt()-1;
				int ki = in.nextInt();
				for(int j=0; j<ki; j++)
					R.get(i).add(in.nextInt()-1);
			}
			
			int[] ANS = new int[n];
			boolean[] DONE = new boolean[n];
			//System.out.println(ok(DONE, keys));
			//System.exit(0);
			TIME: for(int t=0; t<n; t++) {
				for(int i=0; i<n; i++) {
					if(!DONE[i] && keys[T[i]]>=1) {
						keys[T[i]]--;
						for(Integer key : R.get(i))
							keys[key]++;
						DONE[i] = true;
						if(ok(DONE, keys)) {
							ANS[t] = i;
							continue TIME;
						}
						DONE[i] = false;
						keys[T[i]]++;
						for(Integer key : R.get(i))
							keys[key]--;
					}
				}
				System.out.printf("Case #%d: IMPOSSIBLE\n", cas);
				continue CAS;
			}
			System.out.printf("Case #%d:", cas);
			for(int t=0; t<n; t++)
				System.out.printf(" %d", ANS[t]+1);
			System.out.println();
		}
	}
}
