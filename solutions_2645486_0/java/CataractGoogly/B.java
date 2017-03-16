import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {

	public static void main(String[] args) {
		try {
			File fin = new File("B-small-attempt0.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("B-small-out.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int E = sc.nextInt();
				int R = sc.nextInt();
				int N = sc.nextInt();
				int[] v = new int[N];
				for (int i=0; i<N; i++) {
					v[i] = sc.nextInt();
				}
				pw.write("Case #" + cn + ": " + solve(E, R, v) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static int[][] dp;

	private static int solve(int e, int r, int[] v) {
		dp = new int[16][16];
		for (int i=0; i<16; i++) {
			for (int j=0; j<16; j++) {
				dp[i][j] = -1;
			}
		}
		return doit(e, r, v, 0, e);
	}

	static int doit(int e, int r, int[] v, int idx, int energy) {
		if (idx == v.length) {
			return 0;
		}
		if (dp[idx][energy] >= 0)
			return dp[idx][energy];
		int ret = 0;
		for (int spend=0; spend<=energy; spend++) {
			int newEnergy = Math.min(energy-spend+r, e);
			ret = Math.max(ret, spend*v[idx] + doit(e, r, v, idx+1, newEnergy));
		}
		dp[idx][energy] = ret;
		return ret;
	}

}
