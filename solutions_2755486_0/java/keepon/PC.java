package Round1C.PC;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class PC {

	public static class Tribe {
		int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;

		public Tribe() {
		}
	}

	public static class Attack {
		int di, wi, ei, si;

		public Attack(int di, int wi, int ei, int si) {
			super();
			this.di = di;
			this.wi = wi;
			this.ei = ei;
			this.si = si;
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = null;
		try {
			sc = new Scanner(new FileInputStream("C-small-attempt0.in"));
			int T = sc.nextInt();
			for (int task = 1; task <= T; task++) {
				int N = sc.nextInt();
				List<Attack> attacks = new ArrayList<Attack>();
				Tribe[] tribes = new Tribe[N];
				for (int i = 0; i < N; i++) {
					tribes[i] = new Tribe();
					tribes[i].di = sc.nextInt();
					tribes[i].ni = sc.nextInt();
					tribes[i].wi = sc.nextInt();
					tribes[i].ei = sc.nextInt();
					tribes[i].si = sc.nextInt();
					tribes[i].delta_di = sc.nextInt();
					tribes[i].delta_pi = sc.nextInt();
					tribes[i].delta_si = sc.nextInt();
					attacks.addAll(generateAttacks(tribes[i]));
				}
				// sort by date
				Collections.sort(attacks, new Comparator<Attack>() {
					@Override
					public int compare(Attack lhs, Attack rhs) {
						return (lhs.di - rhs.di);
					}
				});

				System.out.println("Case #" + task + ": "
						+ successfulAttacks(attacks));
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} finally {
			if (sc != null) {
				sc.close();
			}
		}
	}

	private static int successfulAttacks(List<Attack> attacks) {
		int success = 0;
		int W = Integer.MAX_VALUE, E = Integer.MIN_VALUE;
		for (Attack att : attacks) {
			W = Math.min(W, att.wi);
			E = Math.max(E, att.ei);
		}
		int[] strength = new int[(E - W)];
		int day = -1;
		for (int i = 0; i < attacks.size(); i++) {
			if (attacks.get(i).di > day) {
				// raise
				for (int j = i - 1; j >= 0 && attacks.get(j).di == day; j--) {
					int w = (attacks.get(j).wi - W);
					int e = (attacks.get(j).ei - W);
					for (int x = w; x < e; x++) {
						strength[x] = Math.max(strength[x], attacks.get(j).si);
					}
				}
				day = attacks.get(i).di;
			}
			int w = (attacks.get(i).wi - W);
			int e = (attacks.get(i).ei - W);
			int flag = 0;
			for (int x = w; x < e; x++) {
				if (strength[x] < attacks.get(i).si) {
					flag = 1;
				}
			}
			success += flag;
		}
		return success;
	}

	private static List<Attack> generateAttacks(Tribe tribe) {
		List<Attack> result = new ArrayList<Attack>();
		int di = tribe.di;
		int wi = tribe.wi;
		int ei = tribe.ei;
		int si = tribe.si;
		for (int i = 0; i < tribe.ni; i++) {
			result.add(new Attack(di, wi, ei, si));
			di += tribe.delta_di;
			wi += tribe.delta_pi;
			ei += tribe.delta_pi;
			si += tribe.delta_si;
		}
		return result;
	}

}
