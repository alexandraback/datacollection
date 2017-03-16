import java.util.*;
public class C {
	static long [][] A;
	static long [][] B;
	static HashMap<State,Long> DP;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int TT = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=TT; ++ii) {
			DP = new HashMap<State,Long>();
			int N = sc.nextInt();
			int M = sc.nextInt();
			A = new long [N][2];
			B = new long [M][2];
			for (int i = 0; i<N; ++i) {
				A[i][0] = sc.nextLong();
				A[i][1] = sc.nextLong();
			}
			for (int i = 0; i<M; ++i) {
				B[i][0] = sc.nextLong();
				B[i][1] = sc.nextLong();
			}
			State init = new State(0 , 0);
			long ans = recurse(init);
			
			
			System.out.printf("Case #%d: %d\n", ii, ans);
		}
	
	}
	public static long recurse(State s) {
		if (s.i >= A.length || s.j >= B.length) return 0;
		if (DP.containsKey(s)) return DP.get(s);
		long ANS = 0;
		if (A[s.i][1] == B[s.j][1]) {
			if (s.ai < s.bj) 
				ANS = s.ai + recurse(new State(s.i+1, s.j, -1, s.bj-s.ai));
			else
				ANS = s.bj + recurse(new State(s.i, s.j+1, s.ai-s.bj, -1));
			
		} else {
			
			ANS = Math.max(ANS, recurse(new State(s.i+1,s.j,-1,s.bj)));
			ANS = Math.max(ANS, recurse(new State(s.i,s.j+1,s.ai,-1)));
			
		}
		DP.put(s, ANS);
		return ANS;
	}
	
	static class State {
		int i,j;
		long ai,bj;
		public State (int ii, int jj, long ai2, long bj2) {
			i = ii;
			j = jj;
			ai = (ai2 < 0 && i < A.length) ? A[i][0] : ai2;
			bj = (bj2 < 0 && j < B.length) ? B[j][0] : bj2;
		}
		
		
		public State (int ii, int jj) {
			i = ii; j=jj;
			ai = A[i][0];
			bj = B[j][0];
		}
		public int hashCode() {
			return (int)(i+j+ai+bj);
		}
		public boolean euqals (Object o){  return equals((State)o);}
		public boolean equals(State s) {
			return (i == s.i && j == s.j && ai == s.ai && bj == s.bj);
		}
	
	}

	
}