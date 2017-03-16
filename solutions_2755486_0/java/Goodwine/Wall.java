import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Wall {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int _ = 1; _ <= t; _++) {
			System.out.println("Case #" + _ + ": " + solve(sc.nextInt(), sc));
		}

	}

	private static int solve(int n, Scanner sc) {
		int[] wall = new int[5000];
		List<Integer> from = new ArrayList<>();
		List<Integer> to = new ArrayList<>();
		int mid = wall.length / 2;
		int s = 0;
		List<Attack> tribes = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			Attack a = new Attack();
			a.d = sc.nextInt();
			a.n = sc.nextInt();
			a.w = sc.nextInt();
			a.e = sc.nextInt();
			a.s = sc.nextInt();
			a.dd = sc.nextInt();
			a.dt = sc.nextInt();
			a.ds = sc.nextInt();
			tribes.add(a);
		}
		while (true) {
			int today = -1;
			for (Attack a : tribes) {
				int d = a.day();
				if (d >= 0 && (today < 0 || d < today))
					today = d;
			}
			if (today < 0)
				break;
			int max = 0;
			for (Attack a : tribes) {
				if (a.a(today)) {
					for (int i = mid + a.w; i < mid + a.e; i++) {
						if (wall[i] < a.s) {
							s++;
							from.add(mid + a.w);
							to.add(mid + a.e);
							if (a.s > max)
								max = a.s;
							break;
						}
					}
					a.move();
				}
			}
			while (from.size() > 0) {
				for (int i = from.get(0); i < to.get(0); i++) {
					wall[i] = max;
				}
				from.remove(0);
				to.remove(0);
			}
		}
		return s;
	}
}

class Attack {
	int d;
	int n;
	int w;
	int e;
	int s;
	int dd;
	int dt;
	int ds;

	public boolean a(int today) {
		if (today != d || n <= 0)
			return false;
		return true;
	}

	public void move() {
		d += dd;
		w += dt;
		e += dt;
		s += ds;
		n--;
	}

	public int day() {
		if (n <= 0)
			return -1;
		return d;
	}
}