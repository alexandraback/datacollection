package y2013r1c;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class C {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		int ntests = Integer.parseInt(reader.readLine());
		for (int test = 1; test <= ntests; test++) {
			int N = Integer.parseInt(reader.readLine());
			Map<Integer, List<Attack>> attacks = new TreeMap<Integer, List<Attack>>();
			for (int tribe = 0; tribe < N; tribe++) {
				String f[] = reader.readLine().split(" ");
				int d = Integer.parseInt(f[0]);
				int n = Integer.parseInt(f[1]);
				int w = Integer.parseInt(f[2]);
				int e = Integer.parseInt(f[3]);
				int s = Integer.parseInt(f[4]);
				int delta_d = Integer.parseInt(f[5]);
				int delta_p = Integer.parseInt(f[6]);
				int delta_s = Integer.parseInt(f[7]);

				for (int i = 0; i < n; i++) {
					if (!attacks.containsKey(d))
						attacks.put(d, new ArrayList<Attack>());
					attacks.get(d).add(new Attack(d, w, e, s));
					d += delta_d;
					w += delta_p;
					e += delta_p;
					s += delta_s;
				}
			}
			int[] wall = new int[2 * 676060 + 1];
			int suc = 0;
			for (Integer day : attacks.keySet()) {
				List<Attack> todayAttacks = attacks.get(day);
				for (Attack a : todayAttacks)
					for (int i = a.from; i < a.to; i++)
						if (wall[i + 676060] < a.strength) {
							suc++;
							break;
						}
				for (Attack a : todayAttacks)
					for (int i = a.from; i < a.to; i++)
						if (wall[i + 676060] < a.strength)
							wall[i + 676060] = a.strength;
			}
			System.out.println("Case #" + test + ": " + suc);
		}
	}

	static class Attack {
		int day;
		int from, to;
		int strength;

		public Attack(int day, int from, int to, int strength) {
			this.day = day;
			this.from = from;
			this.to = to;
			this.strength = strength;
		}

		@Override
		public String toString() {
			return "day=" + day + ", from=" + from + ", to=" + to
					+ ", strength=" + strength;
		}

	}
}
