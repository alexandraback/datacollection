import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class TrainCars {
	public final int MOD = 1_000_000_007;
	public int getNum(List<String> pieces) {
		return this.getNum("", pieces);
	}
	public int getNum(String train, List<String> pieces) {
		if (pieces.isEmpty()) {
			Set<Character> chars = new HashSet<>();
			char cur = '*';
			for (char c : train.toCharArray()) {
				if (c != cur) {
					if (chars.contains(c)) return 0;
					chars.add(c);
					cur = c;
				}
			}
			return 1;
		}
		int count = 0;
		for (String piece : pieces) {
			List<String> newPieces = new LinkedList<>(pieces);
			newPieces.remove(piece);
			count += this.getNum(train + piece, newPieces);
			count %= MOD;
		}
		return count;
	}
	public static void main(String[] args) {
		try (final Scanner in = new Scanner(System.in)) {
			final int t = Integer.parseInt(in.nextLine());
			for (int i = 1; i <= t; i++) {
				in.nextLine();
				System.out.printf("Case #%s: %s%n", i, new TrainCars().getNum(Arrays.asList(in.nextLine().split(" "))));
			}
		}
	}
}
