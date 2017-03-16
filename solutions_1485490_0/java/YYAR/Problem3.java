import java.math.BigInteger;
import java.util.Scanner;

public class Problem3 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int lines = scan.nextInt();

		for (int l = 0; l < lines; l++) {
			String output = null;
			int boxLine = scan.nextInt();
			int toyLine = scan.nextInt();

			long boxRemain[] = new long[100];
			long toyRemain[] = new long[100];

			long boxNum[] = new long[boxLine];
			// scan.nextLong();
			int boxType[] = new int[boxLine];
			// scan.nextInt();

			for (int i = 0; i < boxLine; i++) {
				boxNum[i] = scan.nextLong();
				boxType[i] = scan.nextInt();

				boxRemain[boxType[i] - 1] += boxNum[i];
			}

			long toyNum[] = new long[toyLine];
			int toyType[] = new int[toyLine];

			for (int i = 0; i < toyLine; i++) {
				toyNum[i] = scan.nextLong();
				toyType[i] = scan.nextInt();

				toyRemain[toyType[i] - 1] += toyNum[i];
			}

			int boxidx = 0;
			int toyidx = 0;

			long made = 0;
			while (boxidx < boxLine && toyidx < toyLine) {

				if (toyType[toyidx] != boxType[boxidx]) {
					long newBoxRemain_box[] = boxRemain.clone();
					// long newToyRemain_box[] = toyRemain.clone();

					// long newBoxRemain_toy[] = boxRemain.clone();
					long newToyRemain_toy[] = toyRemain.clone();

					int b = boxidx;
					// long boxTrash = 0L;
					while (b < boxLine) {
						if (toyType[toyidx] != boxType[b]) {
							// boxTrash += boxNum[b];
							newBoxRemain_box[boxType[b] - 1] -= boxNum[b];
							b++;
						} else
							break;
					}

					int t = toyidx;
					// long toyTrash = 0L;
					while (t < toyLine) {
						if (toyType[t] != boxType[boxidx]) {
							// toyTrash += toyNum[t];
							newToyRemain_toy[toyType[t] - 1] -= toyNum[t];
							t++;
						} else
							break;
					}

					long toyRemainSum = getRemain(newToyRemain_toy, boxRemain);
					long boxRemainSum = getRemain(toyRemain, newBoxRemain_box);

					if (boxRemainSum > toyRemainSum) {
						boxidx = b;
						boxRemain = newBoxRemain_box;
					} else {
						toyidx = t;
						toyRemain = newToyRemain_toy;
					}

				}

				if (boxidx < boxLine && toyidx < toyLine) {
					if (toyNum[toyidx] > boxNum[boxidx]) {
						made += boxNum[boxidx];
						boxRemain[boxType[boxidx] - 1] -= boxNum[boxidx];
						toyNum[toyidx] -= boxNum[boxidx];
						toyRemain[toyType[toyidx] - 1] -= boxNum[boxidx];
						boxidx++;
					} else {
						made += toyNum[toyidx];
						toyRemain[toyType[toyidx] - 1] -= toyNum[toyidx];
						boxNum[boxidx] -= toyNum[toyidx];
						boxRemain[boxType[boxidx] - 1] -= toyNum[toyidx];
						toyidx++;
						if (boxNum[boxidx] == 0)
							boxidx++;
					}
				}
			}

			System.out.println("Case #" + (l + 1) + ": " + made);
		}
	}

	private static long getRemain(long[] newToyRemain_toy, long[] boxRemain) {
		long sum = 0L;
		for (int i = 0; i < 100; i++) {
			if (newToyRemain_toy[i] < 0 || boxRemain[i] < 0)
				System.out.println("BUG!");
			sum += Math.min(newToyRemain_toy[i], boxRemain[i]);
		}
		return sum;
	}
}
