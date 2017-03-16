package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;

public class C {
	public static void main(String[] args) throws Exception {
		// long time = System.currentTimeMillis();
		// HashMap<Integer, List<String>> pals = new HashMap<Integer,
		// List<String>>();
		// String[] pals1 = new String[] { "1", "2", "3", "4", "5", "6", "7",
		// "8",
		// "9" };
		// List<String> asList = Arrays.asList(pals1);
		// pals.put(1, asList);
		// for (int i = 2; i <= 5; i++) {
		// List<String> list = new ArrayList<String>();
		// List<String> prev = pals.get(i - 1);
		// if (i % 2 == 1) {
		// for (String x : prev) {
		// String left = x.substring(0, x.length() / 2);
		// String right = x.substring(x.length() / 2);
		// for (int j = 0; j <= 9; j++) {
		// String p = left + j + right;
		// list.add(p);
		// }
		// }
		// } else {
		// for (String x : prev) {
		// String left = x.substring(0, x.length() / 2);
		// String right = x.substring(x.length() / 2);
		// String p = left + right.charAt(0) + right;
		// list.add(p);
		// }
		// }
		// pals.put(i, list);
		// prev = list;
		// // System.out.println(System.currentTimeMillis() - time);
		// }
		// System.out.println(pals.get(1));
		// System.out.println(pals.get(2));
		// System.out.println(pals.get(3));
		// System.out.println(pals.get(4));
		// System.out.println(pals.get(5));
		f1();
	}

	private static void f1() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("c.in"),
				1024 * 1024 * 2);
		BufferedWriter bw = new BufferedWriter(new FileWriter("c.out"),
				1024 * 1024 * 2);

		int t = Integer.parseInt(br.readLine());
		int count = 1;
		StringBuilder sb = new StringBuilder();

		while (count <= t) {
			String line = br.readLine();
			int index = line.indexOf(' ');

			BigDecimal lowD = new BigDecimal(line.substring(0, index));
			lowD = BigDecimal.valueOf(Math.sqrt(lowD.doubleValue()));
			String lowS = lowD.toPlainString();
			int index1 = lowS.indexOf('.');
			BigInteger frac = new BigInteger(lowS.substring(index1 + 1));
			BigInteger low = new BigInteger(lowS.substring(0, index1));
			if (frac.compareTo(BigInteger.ZERO) > 0) {
				low = low.add(BigInteger.ONE);
			}

			BigDecimal upD = new BigDecimal(line.substring(index + 1));
			upD = BigDecimal.valueOf(Math.sqrt(upD.doubleValue()));
			String upS = upD.toPlainString();
			index1 = upS.indexOf('.');
			BigInteger up = null;
			if (index1 > 0) {
				up = new BigInteger(upS.substring(0, index1));
			} else {
				up = new BigInteger(upS);
			}

			int no = 0;
			for (; up.compareTo(low) >= 0; low = low.add(BigInteger.ONE)) {
				if (palindrom(low.toString())) {
					if (palindrom(low.multiply(low).toString())) {
						no++;
					}
				}
			}
			sb.append("Case #" + count + ": " + no + "\n");
			count++;
		}

		System.out.println(sb.toString());
		bw.write(sb.toString());
		br.close();
		bw.close();
	}

	private static boolean palindrom(String string) {
		int i = 0;
		int j = string.length() - 1;
		while (i <= j) {
			if (string.charAt(i) != string.charAt(j)) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
}
