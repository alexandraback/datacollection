import java.util.*;

class Pair implements Comparable<Pair> {
	public int l0;
	public int l1;
	
	public int compareTo(Pair o) {
		// TODO Auto-generated method stub
		return (l1 - o.l1);
	}

	public String toString(){
		return("l0=" + l0 + ",l1=" + l1);
	}
}



public class ProblemB {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//Scanner sc = new Scanner(new File("c:\\B-small-attempt0.in"));
		int cases = sc.nextInt();

		for (int cs = 0; cs < cases; cs++) {

			int N = sc.nextInt();
			Pair[] L = new Pair[N];
			boolean vis[][] = new boolean[N][2];

			for (int i = 0; i < N; i++) {
				L[i] = new Pair();
				L[i].l0 = sc.nextInt();
				L[i].l1 = sc.nextInt();
			}

			Arrays.sort(L);
			

			int score = 0;
			int games = 0;
			boolean broken = false;

			while (!visAll(vis)) {
				boolean found = false;

				for (int i = 0; i < N; i++) {
					if ((L[i].l1 <= score) && !(vis[i][1])) {
						found = true;
						if (vis[i][0]) {
							score++;
						} else {
							score += 2;
						}
						vis[i][1] = true;
						games++;
					}
				}
				if (visAll(vis)) {
					break;
				}

				for (int i = N - 1; i >= 0; i--) {
					if ((L[i].l0 <= score) && (!vis[i][0]) && (!vis[i][1])) {
						found = true;
						score++;
						vis[i][0] = true;
						games++;
						break;
					}
				}

				if (!found) {
					broken = true;
					break;
				}
			}

			System.out.println("Case# " + (cs + 1) + ": "
					+ (broken ? "Too Bad" : ("" + games)));
		}
	}

	private static boolean visAll(boolean[][] l) {
		boolean ret = true;
		for (int i = 0; i < l.length; i++) {
			if (!l[i][1]) {
				ret = false;
				break;
			}
		}
		return ret;
	}

}
