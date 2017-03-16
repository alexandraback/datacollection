import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Vector;

public class TypewriterMonkey {
	public static void main(String[] args) throws IOException {
		String[] input;
		if (args.length > 0) { input = args; }
		else {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String x = null;
			int size = Integer.parseInt(in.readLine()) * 3;
			input = new String[size];
			for (int i=0; i<size; i++) {
				input[i] = in.readLine();
			}
		}
		solve(input);
	}
	
	public static void solve(String[] input) {
		int counter = 1;
		int l;
		String kb, target;
		Vector<String> all;
		int total;
		double result;
		int bananas;
		int maxBan;
		for (int i=0; i<input.length; i+=3) {
			l = Integer.parseInt(input[i].split(" ")[2]);
			kb = sortString(input[i+1]);
			target = input[i+2];
			if (!sanityCheck(kb, sortString(target))) {
				result = 0.0;
			}
			else {
				all = createAll(l, kb);
				total = 0;
				bananas = 0;
				for (String s: all) {
					maxBan = 0;
					for (int j=0; j<=s.length()-target.length(); j++) {
						if (s.substring(j, j+target.length()).contains(target)) {
							total++;
							maxBan++;
						}
					}
					if (maxBan > bananas) { bananas = maxBan; }
				}
				result = bananas - (1.0 * total / all.size());
			}
			System.out.println("Case #" + counter + ": " + result);
			counter++;
		}
	}
	
	public static Vector<String> createAll(int length, String kb) {
		char[] t = new char[length];
		int[] count = new int[length];
		Vector<String> all = new Vector<>();
		for (int i=0; i<t.length; i++) { t[i] = kb.charAt(0); }
		int slot;
		boolean ok = true;
		while (ok) {
			slot = length - 1;
			for (int i=0; i<t.length; i++) {
				t[i] = kb.charAt(count[i]);
			}
			all.add(new String(t));
			count[slot]++;
			while (count[slot] >= kb.length()) {
				count[slot] = 0;
				slot--;
				if (slot < 0) {
					ok = false;
					break;
				}
				count[slot]++;
			}
		}
		return all;
	}
	
	public static boolean sanityCheck(String kb, String target) {
		for (int i=0; i<target.length(); i++) {
			if (!kb.contains(""+target.charAt(i))) { return false; }
		}
		return true;
	}
	
	public static String sortString(String s) {
		char[] c = s.toCharArray();
		Arrays.sort(c);
		return new String(c);
	}
}