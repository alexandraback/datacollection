import java.io.File;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class oneBD {
	public static void main(String[] args) {
		try {
			Scanner s = new Scanner(new File(args[0]));
			int N = s.nextInt();
			BigDecimal r, t, m;

			BigDecimal one = new BigDecimal(1);
			BigDecimal two = new BigDecimal(2);
			BigDecimal four = new BigDecimal(4);
			BigDecimal eight = new BigDecimal(8);
			for (int n = 0; n < N; n++) {
				r = s.nextBigDecimal();
				t = s.nextBigDecimal();
				m = one.subtract(r.multiply(two))
						.add(sqrt(
								four.multiply(r).multiply(r)
										.subtract(four.multiply(r)).add(one)
										.add(eight.multiply(t)), 1))
						.divide(four).setScale(0,RoundingMode.FLOOR);
				System.out.println("Case " + "#" + (n + 1) +": "+ m);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static BigDecimal sqrt(BigDecimal in, int scale) {
		BigDecimal sqrt = new BigDecimal(1);
		sqrt.setScale(scale + 3, RoundingMode.FLOOR);
		BigDecimal store = new BigDecimal(in.toString());
		boolean first = true;
		do {
			if (!first) {
				store = new BigDecimal(sqrt.toString());
			} else
				first = false;
			store.setScale(scale + 3, RoundingMode.FLOOR);
			sqrt = in
					.divide(store, scale + 3, RoundingMode.FLOOR)
					.add(store)
					.divide(BigDecimal.valueOf(2), scale + 3,
							RoundingMode.FLOOR);
		} while (!store.equals(sqrt));
		return sqrt.setScale(scale, RoundingMode.FLOOR);
	}
}