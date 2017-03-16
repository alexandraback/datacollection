package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;

public class C1 {
	public static void main(String[] args) throws Exception {
		long time = System.currentTimeMillis();
		f2();
		System.out.println(System.currentTimeMillis() - time);
	}

	private static void f2() throws IOException {
		String[] values = new String[] { "1", "2", "3", "11", "22", "101",
				"111", "121", "202", "212", "1001", "1111", "2002", "10001",
				"10101", "10201", "11011", "11111", "11211", "20002", "20102",
				"100001", "101101", "110011", "111111", "200002", "1000001",
				"1001001", "1002001", "1010101", "1011101", "1012101",
				"1100011", "1101011", "1102011", "1110111", "1111111",
				"2000002", "2001002" };
		BufferedReader br = new BufferedReader(new FileReader("c.in"),
				1024 * 1024 * 2);
		BufferedWriter bw = new BufferedWriter(new FileWriter("cc.out"),
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
			String s = low.toString();
			int i = 0;
			while (true) {
				if (s.length() <= values[i].length()) {
					BigInteger xx = new BigInteger(values[i]);
					if (xx.compareTo(low) >= 0) {
						break;
					}
				}
				i++;
				if (i >= values.length) {
					break;
				}
			}
			int posInf = i;

			s = up.toString();
			while (true) {
				if (s.length() <= values[i].length()) {
					BigInteger xx = new BigInteger(values[i]);
					if (xx.compareTo(up) > 0) {
						break;
					}
				}
				i++;
				if (i >= values.length) {
					break;
				}
			}
			int posSup = i;
			no = posSup - posInf;

			sb.append("Case #" + count + ": " + no + "\n");
			count++;
		}

		// System.out.println(sb.toString());
		bw.write(sb.toString());
		br.close();
		bw.close();
	}

}
