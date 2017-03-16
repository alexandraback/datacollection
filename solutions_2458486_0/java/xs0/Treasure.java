import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.HashSet;

public class Treasure {
	static class Chest {
		private int index;
		private int needKey;
		private int[] provides;

		Chest(int index, int needKey, int[] providesKeys) {
			this.index = index;
			this.needKey = needKey;
			this.provides = providesKeys;
		}
	}
	
	static void getKeys(Chest[] chests, int bits, int[] begin, int[] out) {
		int n = chests.length;
		System.arraycopy(begin, 0, out, 0, begin.length);
		for (int a = 0; a < n; a++) {
			int bit = 1 << a;
			if ((bits & bit) == 0)
				continue;
			Chest c = chests[a];
			out[c.needKey]--;
			for (int p : c.provides)
				out[p]++;
		}
	}

	private static int[] go(Chest[] chests, int first, int last, int[] haveKeys) {
		int nChests = chests.length;
		
		HashSet<Integer> ok = new HashSet<>();
		ArrayDeque<Integer> q = new ArrayDeque<>();
		
		ok.add(0);
		q.add(0);
		
		int[] state = haveKeys.clone();
		while (!q.isEmpty()) {
			int i = q.pollFirst();
			getKeys(chests, i, haveKeys, state);
				
			for (int a = 0; a < nChests; a++) {
				if ((i & (1 << a)) != 0)
					continue;
				if (state[chests[a].needKey] > 0) {
					Integer add = i | (1 << a);
					if (ok.add(add))
						q.add(add);
				}
			}
		}
		
		Integer want = (1 << nChests) - 1;
		if (!ok.contains(want))
			return null;

		HashSet<Integer> reachesEnd = new HashSet<>();
		q.add(want);
		reachesEnd.add(want);
		
		while (!q.isEmpty()) {
			int have = q.pollFirst();
			for (int c = 0; c < nChests; c++) {
				int bit = 1 << c;
				if ((have & bit) == 0)
					continue;
				Integer check = have & ~bit;
				if (ok.contains(check)) {
					getKeys(chests, have & ~bit, haveKeys, state);
					if (state[chests[c].needKey] > 0) {
						if (reachesEnd.add(check)) {
							q.add(check);
						}
					}
				}
			}
		}

		int already = 0;
		int[] out = new int[nChests];

		op:
		for (int outPos = 0; outPos < nChests; outPos++) {
			for (int chest = 0; chest < nChests; chest++) {
				int bit = 1 << chest;
				if ((already & bit) != 0)
					continue;

				if (!reachesEnd.contains(already | bit))
					continue;
				
				getKeys(chests, already, haveKeys, state);
				if (state[chests[chest].needKey] > 0) {
					out[outPos] = chests[chest].index + 1;
					already |= bit;
					continue op;
				}
			}
			throw new IllegalStateException();
		}
		return out;
	}

	
	static void go(String inputFile) throws IOException {
		LineNumberReader in = new LineNumberReader(new FileReader(inputFile));
		FileWriter out = new FileWriter(inputFile + ".out");
		
		int nCases = Integer.parseInt(in.readLine());
		for (int c = 1; c <= nCases; c++) {
			int[] tmp = toInts(in.readLine().trim());
			int haveKeys = tmp[0];
			int nChests = tmp[1];
			
			int[] initialKeys = new int[210];
			int[] ik = toInts(in.readLine().trim());
			for (int a = 0; a < haveKeys; a++)
				initialKeys[ik[a] - 1]++;
			
			int[] allKeys = initialKeys.clone();
			int[] needKeys = new int[210];
			
			Chest[] chests = new Chest[nChests];
			for (int a = 0; a < nChests; a++) {
				int[] data = toInts(in.readLine().trim());
				int needKey = data[0] - 1;
				needKeys[needKey]++;
				int nProvides = data[1];
				int[] provides = new int[nProvides];
				for (int b = 0; b < nProvides; b++) {
					int k = provides[b] = data[2 + b] - 1;
					allKeys[k]++;
				}
				chests[a] = new Chest(a, needKey, provides);
			}
			
			int[] resChests = go(chests, 0, nChests, initialKeys);
			String res;
			
			
			if (resChests != null) {
				res = mkRes(resChests);
			} else {
				res = "IMPOSSIBLE";
			}
			
			out.write("Case #" + c + ": " + res + "\n");
			System.out.println("Case #" + c + ": " + res);
		}
		out.close();
	}
	
	static String mkRes(int[] resChests) {
		StringBuilder sb = new StringBuilder();
		for (int a = 0; a < resChests.length; a++) {
			if (a > 0)
				sb.append(' ');
			sb.append(resChests[a]);
		}
		return sb.toString();
	}
	
	static int[] toInts(String s) {
		String[] tmp = s.trim().split(" ");
		int n = tmp.length;
		int[] res = new int[n];
		for (int a = 0; a < n; a++)
			res[a] = Integer.parseInt(tmp[a]);
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		LineNumberReader sysIn = new LineNumberReader(new InputStreamReader(System.in));
		String line;
		while ((line = sysIn.readLine()) != null) {
			go(line.trim());
		}
	}
}
