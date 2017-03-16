import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Problem {

	static class Interval {
		final int w;
		final int e;

		Interval(int w, int e) {
			this.w = w;
			this.e = e;
		}
	}

	static class Attack implements Comparable<Attack> {
		final int tribe;
		final int d;
		final int w;
		final int e;
		final int s;

		Attack(int tribe, int d, int w, int e, int s) {
			this.tribe = tribe;
			this.d = d;
			this.w = w;
			this.e = e;
			this.s = s;
		}

		@Override
		public int compareTo(Attack o) {
			return d - o.d;
		}
	}

	public static boolean doAttack(Attack attack, int[] wall, int[] wall_spaces, int wall_0, int[] new_wall, int[] new_wall_spaces) {
		boolean success = false;
		if (wall[attack.w + wall_0] < attack.s) {
			success = true;
			if (new_wall[attack.w + wall_0] < attack.s) {
				new_wall[attack.w + wall_0] = attack.s;
			}
		}
		for (int pos = attack.w + wall_0 + 1; pos <= attack.e + wall_0; ++pos) {
			if (wall[pos] < attack.s) {
				success = true;
				if (new_wall[pos] < attack.s) {
					new_wall[pos] = attack.s;
				}
			}
			if (wall_spaces[pos] < attack.s) {
				success = true;
				if (new_wall_spaces[pos] < attack.s) {
					new_wall_spaces[pos] = attack.s;
				}
			}
		}

		System.out.println("Tribe #" + attack.tribe + " attacked the wall from " + attack.w + " to " + attack.e + " with " + attack.s
				+ " strength and the attack " + (success ? "succeeded" : "failed") + "!");

		return success;
	}

	public static int calc(int N, int[] d, int[] n, int[] w, int[] e, int[] s, int[] delta_d, int[] delta_p, int[] delta_s) {
		PriorityQueue<Attack> attacks = new PriorityQueue<>();
		for (int i = 0; i < N; ++i) {
			int act_d = d[i];
			int act_w = w[i];
			int act_e = e[i];
			int act_s = s[i];

			for (int j = 0; j < n[i]; ++j) {
				attacks.add(new Attack(i + 1, act_d, act_w, act_e, act_s));

				act_d += delta_d[i];
				act_w += delta_p[i];
				act_e += delta_p[i];
				act_s += delta_s[i];
			}
		}

		System.out.println("Added " + attacks.size() + " attacks!");

		int success = 0;

		int[] wall = new int[2001];
		int[] wall_spaces = new int[2001];
		int wall_0 = 1000;
		while (!attacks.isEmpty()) {
			int[] new_wall = wall.clone();
			int[] new_wall_spaces = wall_spaces.clone();

			ArrayList<Attack> act_attacks = new ArrayList<>();
			Attack attack = attacks.remove();
			act_attacks.add(attack);
			while (!attacks.isEmpty() && attacks.peek().d == attack.d) {
				act_attacks.add(attacks.remove());
			}
			System.out.println("Day " + attack.d + " : " + act_attacks.size() + " attacks!");
			for (Attack act_attack : act_attacks) {
				if (doAttack(act_attack, wall, wall_spaces, wall_0, new_wall, new_wall_spaces)) {
					++success;
				}
			}

			wall = new_wall;
			wall_spaces = new_wall_spaces;
		}

		return success;
	}

	public static void solve(String file) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("./" + file + ".in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("./" + file + ".out"), false));

		try {
			int num = Integer.parseInt(reader.readLine());

			String[] cols;
			for (int test_id = 1; test_id <= num; ++test_id) {
				int N = Integer.parseInt(reader.readLine());

				int[] d = new int[N];
				int[] n = new int[N];
				int[] w = new int[N];
				int[] e = new int[N];
				int[] s = new int[N];
				int[] delta_d = new int[N];
				int[] delta_p = new int[N];
				int[] delta_s = new int[N];

				for (int i = 0; i < N; ++i) {
					cols = reader.readLine().split("\\s");
					d[i] = Integer.parseInt(cols[0]);
					n[i] = Integer.parseInt(cols[1]);
					w[i] = Integer.parseInt(cols[2]);
					e[i] = Integer.parseInt(cols[3]);
					s[i] = Integer.parseInt(cols[4]);
					delta_d[i] = Integer.parseInt(cols[5]);
					delta_p[i] = Integer.parseInt(cols[6]);
					delta_s[i] = Integer.parseInt(cols[7]);
				}

				System.err.println("Case #" + test_id);

				writer.write("Case #" + test_id + ": " + calc(N, d, n, w, e, s, delta_d, delta_p, delta_s));
				writer.newLine();

			}
		} finally {
			writer.close();
			reader.close();
		}
	}

	public static void main(String[] args) throws Exception {
		solve("C-small-attempt0");
	}

}
