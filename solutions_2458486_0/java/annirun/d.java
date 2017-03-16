import java.util.Scanner;

/*

 3
 1 4
 1
 1 0
 1 2 1 3
 2 0
 3 1 2
 3 3
 1 1 1
 1 0
 1 0
 1 0
 1 1
 2
 1 1 1

 */
public class d {
	static int[] heldKeys;
	static chest[] chests;
	static holder[] memo;

	static class chest {
		boolean opened;
		int key;
		int[] inside;
	}

	static class holder {
		String s;

		public holder(String i) {
			s = i;
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();

		for (int i = 0; i < cases; i++) {
			int k = in.nextInt();
			int n = in.nextInt();

			int highestKey = 0;

			int[] keys = new int[k];
			for (int j = 0; j < keys.length; j++) {
				keys[j] = in.nextInt();
				highestKey = Math.max(highestKey, keys[j]);
			}

			chests = new chest[n];
			memo = new holder[1 << n];
			for (int j = 0; j < chests.length; j++) {
				chests[j] = new chest();
				chests[j].key = in.nextInt();
				highestKey = Math.max(highestKey, chests[j].key);
				chests[j].inside = new int[in.nextInt()];

				for (int a = 0; a < chests[j].inside.length; a++) {
					chests[j].inside[a] = in.nextInt();
					highestKey = Math.max(highestKey, chests[j].inside[a]);
				}
			}

			heldKeys = new int[highestKey + 1];
			for (int j = 0; j < keys.length; j++) {
				heldKeys[keys[j]]++;
			}

			String s = recurse(0).s;
			System.out.printf("Case #%d:%s\n", i + 1, s == null ? " IMPOSSIBLE"
					: s);
		}
	}

	private static holder recurse(int n) {
		if (n+1  >= memo.length)
			return new holder("");
		if (memo[n] != null)
			return memo[n];

		for (int i = 0; i < chests.length; i++) {
			if (chests[i].opened == false && heldKeys[chests[i].key] > 0) {
				chests[i].opened = true;
				heldKeys[chests[i].key]--;
				for (int keyNum : chests[i].inside) {
					heldKeys[keyNum]++;
				}

				String s = recurse(n | (1 << i)).s;

				if (s != null)
					return memo[n] = new holder(" " + (i + 1) + s);

				heldKeys[chests[i].key]++;
				chests[i].opened = false;
				for (int keyNum : chests[i].inside) {
					heldKeys[keyNum]--;
				}
			}
		}
		return memo[n] = new holder(null);
	}
}
