import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class TrainCars {
	public static final int MOD = 1_000_000_007;
	public int getNum(List<String> pieces) {
		int[] full = new int[26];
		outer:
		for (Iterator<String> it = pieces.iterator(); it.hasNext(); ) {
			String piece = it.next();
			char c = piece.charAt(0);
			for (char cc : piece.toCharArray()) {
				if (cc != c) continue outer;
			}
			full[c - 'a']++;
			it.remove();
		}
		long count = 1;
		for (int f : full) {
			count *= fact(f);
			count %= MOD;
		}
		boolean[] special = new boolean[26];
		outer2:
		for (char c = 'a'; c <= 'z'; c++) {
			if (full[c - 'a'] > 0) {
				for (String piece : pieces) {
					if (piece.contains("" + c)) continue outer2;
				}
				special[c - 'a'] = true;
			}
		}
		for (char c = 'a'; c <= 'z'; c++) {
			List<String> list = new LinkedList<>();
			for (String piece : pieces) {
				if (piece.contains("" + c)) list.add(piece);
			}
			if (list.size() > 2) return 0;
			if (list.size() == 2) {
				pieces.removeAll(list);
				String newPiece = list.get(0);
				if (newPiece.charAt(0) == c) newPiece = list.get(1) + newPiece;
				else newPiece += list.get(1);
				pieces.add(newPiece);
			}
		}
		for (String piece : pieces) {
			if (!isValid(piece)) return 0;
		}
		int specialCount = pieces.size();
		for (boolean spec : special) if (spec) specialCount++;
		count *= fact(specialCount);
		count %= MOD;
		return (int)count;
	}
	private static boolean isValid(String piece) {
		Set<Character> chars = new HashSet<>();
		char cur = '*';
		for (char c : piece.toCharArray()) {
			if (c != cur) {
				if (chars.contains(c)) return false;
				chars.add(c);
				cur = c;
			}
		}
		return true;
	}
	private static int fact(int n) {
		if (n == 0) return 1;
		long f = 1;
		for (int i = 1; i <= n; i++) {
			f *= i;
			f %= MOD;
		}
		return (int)f;
	}
	public static void main(String[] args) {
		try (final Scanner in = new Scanner(System.in)) {
			final int t = Integer.parseInt(in.nextLine());
			for (int i = 1; i <= t; i++) {
				in.nextLine();
				System.out.printf("Case #%s: %s%n", i, new TrainCars().getNum(new ArrayList<>(Arrays.asList(in.nextLine().split(" ")))));
			}
		}
	}
}
