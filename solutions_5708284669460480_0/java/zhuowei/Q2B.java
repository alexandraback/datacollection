import java.util.*;

public class Q2B {

	public static double countit(String a, String t) {
		int c = 0;
		int i = 0;
		while ((i = a.indexOf(t, i) + 1) != 0) c++;
		return c;
	}

	public static double doFanout(String keyboard, String target, String already, int s) {
		if (s == 0) {
			return countit(already, target);
		}
		double prob = 1.0 / keyboard.length();
		double ret = 0.0;
		for (int i = 0; i < keyboard.length(); i++) {
			char c = keyboard.charAt(i);
			double retval = doFanout(keyboard, target, already + c, s-1);
			ret += prob*retval;
		}
		return ret;
	}

	public static String[] doPlace(String in, String sub, int count, Map<Integer, String[]> cache) {
		if (count == 0) return new String[]{in};
		String[] cached = cache.get(count);
		if (cached != null) return cached;
		String[] nin = doPlace(in, sub, count-1, cache);
		HashSet<String> set = new HashSet<>();
		for(String s: nin) {
			for (int i = 0; i <= s.length() - sub.length(); i++) {
				String displaced = s.substring(i, i+sub.length());
				if (displaced.equals(sub)) continue;
				boolean canPlace = true;
				for (int j = 0; j < sub.length(); j++) {
					if (displaced.charAt(j) != '~' && displaced.charAt(j) != sub.charAt(j)) {
						canPlace = false;
						break;
					}
				}
				if (canPlace) {
					String newS = s.substring(0, i) + sub + s.substring(i+sub.length());
					set.add(newS);
				}
			}
		}
		cached = set.toArray(new String[0]);
		cache.put(count, cached);
		return cached;
	}

	public static double solve(String keyboard, String target, int s) {
		// is it even possible?
		int[] keyboardCount = new int[0x100];
		int[] targetCount = new int[0x100];
		for (int i = 0; i < keyboard.length(); i++) {
			keyboardCount[keyboard.charAt(i)]++;
		}
		double[] chance = new double[0x100];
		for (int i = 0; i < 0x100; i++) {
			chance[i] = ((double) keyboardCount[i]) / keyboard.length();
		}
		for (int i = 0; i < target.length(); i++) {
			targetCount[target.charAt(i)]++;
			if (keyboardCount[target.charAt(i)] == 0) {
				return 0;
			}
		}
		int subseq = target.length();
		// find length with repeats
		for (int i = target.length() - 1; i > 0; i--) {
			if (target.substring(i).equals(target.substring(0, target.length() - i))) {
				subseq = i;
			}
		}
		int maxRepeats = ((s - target.length()) / subseq) + 1;
		// possibility = sum from 1 to maxrepeats (chance of getting exactly (num) copie of the word)
		double expected = doFanout(keyboard, target, "", s);
		return maxRepeats - expected;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for (int i = 0; i < numCases; i++) {
			int k = scan.nextInt();
			int l = scan.nextInt();
			int s = scan.nextInt();
			String keyboard = scan.next();
			String target = scan.next();
			double d = solve(keyboard, target, s);
			System.out.println("Case #" + (i + 1) + ": " + d);
		}
	}
}