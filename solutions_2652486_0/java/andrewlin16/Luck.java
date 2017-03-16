import java.util.*;

public class Luck {
	public static void main(String[]Z) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			System.out.printf("Case #%d:\n", t);
			
			int R = in.nextInt();
			int N = in.nextInt();
			int M = in.nextInt();
			int K = in.nextInt();
			
			int[] perm = new int[N];
			for (int n = 0; n < N; n++) {
				perm[n] = 2;
			}
			
			List<CSet> cards = new ArrayList<CSet>();
			
			while (perm[0] <= M) {
				boolean go = true;
				
				for (int n = 1; go && n < N; n++) {
					if (perm[n] < perm[n-1]) {
						go = false;
					}
				}
				
				if (go) {
					cards.add(new CSet(perm));
				}
				
				perm[N-1]++;
				
				for (int n = N-1; n > 0; n--) {
					if (perm[n] > M) {
						perm[n] = 2;
						perm[n-1]++;
					}
				}
			}
			
			//System.out.println(cards);
			
			for (int r = 0; r < R; r++) {
				List<CSet> tcards = new ArrayList<CSet>(cards);
				
				for (int k = 0; k < K; k++) {
					int prod = in.nextInt();
					
					ListIterator<CSet> iter = tcards.listIterator();
					
					while (iter.hasNext()) {
						CSet set = iter.next();
						
						if (!set.prods.contains(prod)) {
							iter.remove();
						}
					}
				}
				
				//System.out.println(tcards);
				
				// pick a random one???
				
				int i = (int) (Math.random() * tcards.size());
				CSet s = tcards.get(i);
				System.out.println(s.sas(s.n));
			}
		}
	}
}

class CSet {
	int[] n;
	Set<Integer> prods;
	
	public CSet(int[] cs) {
		n = new int[cs.length];
		
		for (int N = 0; N < n.length; N++) {
			n[N] = cs[N];
		}
		
		prods = new TreeSet<Integer>();
		
		genProds(0, 1);
	}
	
	public void genProds(int i, int prod) {
		prods.add(prod);
		
		if (i < n.length) {
			genProds(i+1, prod);
			genProds(i+1, prod * n[i]);
		}
	}
	
	public String toString() {
		return "{Cards " + sas(n) + ": " + prods + "}";
	}
	
	public String sas(int[] ns) {
		String a = "";
		
		for (int n: ns) {
			a += n;
		}
		
		return a;
	}
}
