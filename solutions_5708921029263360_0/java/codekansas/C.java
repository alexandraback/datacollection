package qualC2016;

import java.util.*;

public class C {
	public static void main(String... args) {
		Scanner s = new Scanner(System.in);
		
		final int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			J = s.nextInt();
			P = s.nextInt();
			S = s.nextInt();
			K = s.nextInt();
			
			System.out.printf("Case #%d: ", t);
			solve();
		}
		
		s.close();
	}
	
	static void solve() {
		int[][] js = new int[J][S], jp = new int[J][P], ps = new int[P][S];
		List<String> combos = new ArrayList<>();

		for (int j = 0; j < J; j++) {
			for (int p = 0; p < P; p++) {
				for (int s = 0; s < S; s++){
					if (ps[p][s] == K || js[j][s] == K || jp[j][p] == K) continue;
					
					combos.add((j+1) + " " + (p+1) + " " + (s+1));
					jp[j][p]++;
					js[j][s]++;
					ps[p][s]++;
				}
			}
		}
		
		System.out.println(combos.size());
		for (String s : combos) {
			System.out.println(s);
		}
	}
	
	static int J, P, S, K;
}
