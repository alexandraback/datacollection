import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {
	public static void main(String[] args) {

		String curBinary6 = "100000";
		String output6 = "output_6_3.txt";
		run(curBinary6, output6, 3);

		String curBinary16 = "1000000000000000";
		String output16 = "output_16_50.txt";
		run(curBinary16, output16, 50);

		String curBinary32 = "10000000000000000000000000000000";
		String output32 = "output_32_500.txt";
		run(curBinary32, output32, 500);

		Verify.check();
	}

	private static void run(String curBinary, String output, int results) {
		PrintWriter printer = null;
		List<Integer> primes = getPrimeList();
		try {
			printer = new PrintWriter(new FileWriter(output));

			printer.println("Case #1:");

			for (int test = 0; test < results; test++) {
				curBinary = getNextValidBinary(curBinary);

				Map<Integer, Integer> result = new HashMap<>();
				boolean ok = true;
				for (int base = 2; base <= 10; base++) {
					BigInteger convertedValue = convertToBase(curBinary, base);
					for (int prime : primes) {
						if (convertedValue.mod(new BigInteger(String.valueOf(prime))).compareTo(new BigInteger("0")) == 0) {
							result.put(base, prime);
							break;
						}
					}
					if (!result.containsKey(base)) {
						//throw new IllegalArgumentException("Need more primes: binary: " + curBinary + " -> ("+base+")" + convertedValue.toString());
						test--;
						ok = false;
						break;
					}
				}

				if (ok) {
					printer.println(String.format("%s %d %d %d %d %d %d %d %d %d", curBinary, result.get(2), result.get(3),
							result.get(4), result.get(5), result.get(6), result.get(7), result.get(8), result.get(9), result.get(10)));
				}
			}

		} catch(IOException e) {
			System.out.println(e.getMessage());
		} finally {
			if (printer != null) {
				printer.flush();
				printer.close();
			}
		}
	}

	private static boolean isValid(String binary) {
		return binary.charAt(0) == '1' && binary.charAt(binary.length() - 1) == '1';
	}

	private static String increment(String binary) {
		return new BigInteger(binary, 2).add(new BigInteger("1")).toString(2);
	}

	private static String getNextValidBinary(String binary) {
		String next = increment(binary);
		while (!isValid(next))
			next = increment(next);
		return next;
	}

	private static BigInteger convertToBase(String binary, int base) {
		return new BigInteger(binary, base);
	}

	private static List<Integer> getPrimeList() {
		List<Integer> primes = new ArrayList<>();
		primes.add(2);
		primes.add(3);
		primes.add(5);
		primes.add(7);
		primes.add(11);
		primes.add(13);
		primes.add(17);
		primes.add(19);
		primes.add(23);
		primes.add(29);
		primes.add(31);
		primes.add(37);
		primes.add(41);
		primes.add(43);
		primes.add(47);
		primes.add(53);
		primes.add(59);
		primes.add(61);
		primes.add(67);
		primes.add(71);
		primes.add(73);
		primes.add(79);
		primes.add(83);
		primes.add(89);
		primes.add(97);
		primes.add(101);
		primes.add(103);
		primes.add(107);
		primes.add(109);
		primes.add(113);
		primes.add(127);
		primes.add(131);
		primes.add(137);
		primes.add(139);
		primes.add(149);
		primes.add(151);
		primes.add(157);
		primes.add(163);
		primes.add(167);
		primes.add(173);
		primes.add(179);
		primes.add(181);
		primes.add(191);
		primes.add(193);
		primes.add(197);
		primes.add(199);
		primes.add(211);
		primes.add(223);
		primes.add(227);
		primes.add(229);
		primes.add(233);
		primes.add(239);
		primes.add(241);
		primes.add(251);
		primes.add(257);
		primes.add(263);
		primes.add(269);
		primes.add(271);
		primes.add(277);
		primes.add(281);
		primes.add(283);
		primes.add(293);
		primes.add(307);
		primes.add(311);
		primes.add(313);
		primes.add(317);
		primes.add(331);
		primes.add(337);
		primes.add(347);
		primes.add(349);
		primes.add(353);
		primes.add(359);
		primes.add(367);
		primes.add(373);
		primes.add(379);
		primes.add(383);
		primes.add(389);
		primes.add(397);
		primes.add(401);
		primes.add(409);
		primes.add(419);
		primes.add(421);
		primes.add(431);
		primes.add(433);
		primes.add(439);
		primes.add(443);
		primes.add(449);
		primes.add(457);
		primes.add(461);
		primes.add(463);
		primes.add(467);
		primes.add(479);
		primes.add(487);
		primes.add(491);
		primes.add(499);
		primes.add(503);
		primes.add(509);
		primes.add(521);
		primes.add(523);
		primes.add(541);
		return primes;
	}
}
