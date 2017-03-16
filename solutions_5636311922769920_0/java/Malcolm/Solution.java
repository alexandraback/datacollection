import java.lang.*;
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Solution {

	public static List<BigInteger> tiles(int k, int c) {
		List<BigInteger> result = new ArrayList<>();

		if (k == 1) {
			result.add(BigInteger.ONE);
			return result;
		}

		List<BigInteger> allTiles = new ArrayList<>();
		for (int n = 1; n <= k; n++) {
			allTiles.add(BigInteger.valueOf(n));
		}

		if (c == 1) {
			return allTiles;
		}

		for (Iterator<BigInteger> it = allTiles.iterator(); it.hasNext(); ) {
			BigInteger i = it.next();
			BigInteger j = it.hasNext() ? it.next() : i;
			result.add(tile(i, j, k, c));
		}

		return result;
	}

	public static BigInteger tile(BigInteger i, BigInteger j, int k, int c) {
		// return (int) Math.pow(k, c - 1) * (i - 1) + j;
		return BigInteger.valueOf(k).pow(c - 1).multiply(i.subtract(BigInteger.ONE)).add(j);
	}

	public static void main(String[] args) {
		try (InputStreamReader isr = new InputStreamReader(System.in);
				BufferedReader br = new BufferedReader(isr);
				Scanner scanner = new Scanner(br);) {
			int t = scanner.nextInt();
			for (int i = 1; i <= t; i++) {
				int k = scanner.nextInt();
				int c = scanner.nextInt();
				int s = scanner.nextInt();

				List<BigInteger> tiles = tiles(k, c);
				if (s < tiles.size()) {
					System.out.println("case #" + i + ": IMPOSSIBLE");
					continue;
				}

				System.out.print("case #" + i + ":");
				for (BigInteger n: tiles) {
					System.out.print(" " + n);
				}
				System.out.println();
			}
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
}
