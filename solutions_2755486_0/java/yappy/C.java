import java.util.Scanner;

public class C {

	static class Tribe {
		int d, n, w, e, s, dd, dp, ds;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		for (int no = 1; no <= T; no++) {
			int N = in.nextInt();
			Tribe[] ts = new Tribe[N];
			for (int i = 0; i < N; i++) {
				ts[i] = new Tribe();
				ts[i].d = in.nextInt();
				ts[i].n = in.nextInt();
				ts[i].w = in.nextInt();
				ts[i].e = in.nextInt();
				ts[i].s = in.nextInt();
				ts[i].dd = in.nextInt();
				ts[i].dp = in.nextInt();
				ts[i].ds = in.nextInt();
			}
			int ans = 0;
			int[] wall = new int[1000];
			int[] nwall = new int[1000];
			for (int i = 0; i <= 676060; i++) {
				System.arraycopy(wall, 0, nwall, 0, wall.length);
				for (Tribe tr : ts) {
					if (i < tr.d)
						continue;
					if ((i - tr.d) % tr.dd != 0)
						continue;
					int k = (i - tr.d) / tr.dd;
					if (k >= tr.n)
						continue;
					int w = tr.w + tr.dp * k + 500;
					int e = tr.e + tr.dp * k + 500;
					int s = tr.s + tr.ds * k;
					// System.err.printf("%d: %d %d %d%n", i, w - 500, e - 500,
					// s);
					boolean suc = false;
					for (int x = w; x < e; x++) {
						if (wall[x] < s) {
							nwall[x] = Math.max(s, nwall[x]);
							suc = true;
						}
					}
					// System.err.println(suc);
					if (suc)
						ans++;
				}
				System.arraycopy(nwall, 0, wall, 0, wall.length);
			}
			System.out.printf("Case #%d: %d%n", no, ans);
		}
	}
}
