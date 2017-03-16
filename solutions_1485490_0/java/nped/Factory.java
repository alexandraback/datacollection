import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Factory {

	private static BufferedReader bufferedReader = new BufferedReader(
			new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		String line = bufferedReader.readLine();
		int cases = Integer.parseInt(line);

		for (int i = 1; i <= cases; i++) {
			line = bufferedReader.readLine();

			String[] split = line.split(" ");
			int N = Integer.parseInt(split[0]);
			int M = Integer.parseInt(split[1]);

			long[] boxes = new long[2 * N];
			long[] toys = new long[2 * M];

			line = bufferedReader.readLine();
			split = line.split(" ");
			for (int j = 0; j < 2 * N; j++) {
				boxes[j] = Long.parseLong(split[j]);
			}

			line = bufferedReader.readLine();
			split = line.split(" ");
			for (int j = 0; j < 2 * M; j++) {
				toys[j] = Long.parseLong(split[j]);
			}

			int boxIndex = 0;
			int toysIndex = 0;

			long boxAmount = boxes[boxIndex];
			long boxType = boxes[boxIndex + 1];
			long toyAmount = toys[toysIndex];
			long toyType = toys[toysIndex + 1];

			BigInteger answer = solve(boxes, toys, boxIndex, toysIndex,
					boxAmount, boxType, toyAmount, toyType, "*");

			System.out.println("Case #" + i + ": " + answer);
		}
	}

	private static BigInteger solve(long[] boxes, long[] toys, int boxIndex,
			int toysIndex, long boxAmount, long boxType, long toyAmount,
			long toyType, String id) {
		BigInteger successes = BigInteger.ZERO;

		/*
		 * System.err.println("ID: " + id + " boxIndex: " + boxIndex +
		 * " toyIndex: " + toysIndex + " boxType: " + boxType + " boxAmount: " +
		 * boxAmount + " toyType: " + toyType + " toyAmount: " + toyAmount);
		 */
		if (boxType == toyType) {
			successes = successes.add(new BigInteger(Math.min(toyAmount,
					boxAmount) + ""));

			/*
			 * System.err.println("ID: " + id + ", Added " + Math.min(toyAmount,
			 * boxAmount) + " to successes, now we have " + successes);
			 */
			if (boxAmount < toyAmount) {
				boxIndex += 2;
				toyAmount -= boxAmount;

				id = id + "o";

				if (boxIndex < boxes.length) {
					boxAmount = boxes[boxIndex];
					boxType = boxes[boxIndex + 1];
				} else {
					return successes;
				}

			} else if (toyAmount < boxAmount) {
				toysIndex += 2;
				boxAmount -= toyAmount;

				id = id + "L";

				if (toysIndex < toys.length) {
					toyAmount = toys[toysIndex];
					toyType = toys[toysIndex + 1];
				} else {
					return successes;
				}
			} else {
				boxIndex += 2;
				toysIndex += 2;

				id = id + "{oL}";

				if (boxIndex < boxes.length) {
					boxAmount = boxes[boxIndex];
					boxType = boxes[boxIndex + 1];
				} else {
					return successes;
				}

				if (toysIndex < toys.length) {
					toyAmount = toys[toysIndex];
					toyType = toys[toysIndex + 1];
				} else {
					return successes;
				}
			}
			return successes.add(solve(boxes, toys, boxIndex, toysIndex,
					boxAmount, boxType, toyAmount, toyType, id + "!"));
		}

		BigInteger res1 = BigInteger.ZERO;
		BigInteger res2 = BigInteger.ZERO;

		if (boxIndex + 3 < boxes.length) {
			res1 = solve(boxes, toys, boxIndex + 2, toysIndex,
					boxes[boxIndex + 2], boxes[boxIndex + 3], toyAmount,
					toyType, id + "0");
		}

		if (toysIndex + 3 < toys.length) {
			res2 = solve(boxes, toys, boxIndex, toysIndex + 2, boxAmount,
					boxType, toys[toysIndex + 2], toys[toysIndex + 3], id + "1");
		}

		if (res1.compareTo(res2) > 0) {
			return successes.add(res1);
		} else {
			return successes.add(res2);
		}

	}

}
