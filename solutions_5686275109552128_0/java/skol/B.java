import java.util.Scanner;


public class B {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int D = sc.nextInt();
			int[] p = new int[D];
			for (int i = 0; i < D; i++)
				p[i] = sc.nextInt();
			int best = 1000;
			for (int eat = 1; eat <= 1000; eat++) {
				int time = solve(p, eat);
				best = Math.min(time, best);
			}
			
			System.out.printf("Case #%d: %d\n", t, best);
		}
	}

	private static int solve(int[] p, int eat) {
		int special = 0;
		for (int i = 0; i < p.length; i++)
			special += (p[i] - 1)/eat;
		return special + eat;
	}

}
