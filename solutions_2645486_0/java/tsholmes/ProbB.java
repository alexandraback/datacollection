import java.util.Scanner;


public class ProbB {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			
			int[] v = new int[N];
			for (int i = 0; i < N; i++) {
				v[i] = in.nextInt();
			}
			
			int res = search(E,R,N,v,0,E);
			
			System.out.printf("Case #%d: %d%n", caseNum, res);
		}
	}
	
	private static int search(int E, int R, int N, int[] v, int i, int cur) {
		if (i == N) return 0;
		
		int max = 0;
		
		for (int spend = 0; spend <= cur; spend++) {
			int gain = v[i] * spend + search(E,R,N,v,i+1,Math.min(cur-spend+R,E));
			max = Math.max(max,gain);
		}
		
		return max;
	}
}
