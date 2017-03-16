import java.util.*;

public class Treasure {
	public static void main(String[]Z) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			int K = in.nextInt();
			int N = in.nextInt();
			
			List<Integer> keys = new ArrayList<Integer>();
			
			for (int k = 0; k < K; k++) {
				keys.add(in.nextInt());
			}
			
			Chest[] chests = new Chest[N];
			
			for (int n = 0; n < N; n++) {
				int key = in.nextInt();
				int kk = in.nextInt();
				
				Set<Integer> keyset = new TreeSet<Integer>();
				
				for (int k = 0; k < kk; k++) {
					keyset.add(in.nextInt());
				}
				
				chests[n] = new Chest(key, keyset);
			}
			
			List<Integer> ans = solve(keys, chests, new ArrayList<Integer>());
			
			if (ans != null) {
				System.out.printf("Case #%d:", t);
				
				for (int i : ans) {
					System.out.printf(" %d", i);
				}
				
				System.out.println();
			} else {
				System.out.printf("Case #%d: IMPOSSIBLE\n", t);
			}
		}
	}
	
	public static List<Integer> solve(List<Integer> keys, Chest[] chests, 
			List<Integer> answer) {
		
		//System.out.println("Testing: " + keys + " -- " + answer);
		
		if (answer.size() >= chests.length) {
			//System.out.println("Found answer!");
			return answer;
		}
		
		if (keys.isEmpty()) {
			//System.out.println("ran out of keys");
			return null;
		}
		
		for (int x = 0; x < chests.length; x++) {
			if (keys.contains(chests[x].type)) {
				List<Integer> ckeys = new ArrayList<Integer>(keys);
				ckeys.remove((Integer) chests[x].type);
				ckeys.addAll(chests[x].keys);
				
				List<Integer> cans = new ArrayList<Integer>(answer);
				cans.add(x+1);
				
				List<Integer> attempt = solve(ckeys, chests, cans);
				
				if (attempt != null) {
					return attempt;
				}
			}
		}
		
		return null;
	}
}

class Chest {
	int type;
	Set<Integer> keys;
	
	public Chest(int t, Set<Integer> k) {
		type = t;
		keys = k;
	}
}
