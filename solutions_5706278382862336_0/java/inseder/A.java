package codejam_round2_14;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class A {

	public static long gdc(long a, long b) {
		if (a == 0 || b == 0) {
			return 0;
		}

		if (b > a) {
			long t = a;
			a = b;
			b = t;
		}

		while (a % b != 0) {
			long t = a % b;
			a = b;
			b = t;
		}
		return b;
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {

		BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in), 1024 * 1024 * 2);

		int t = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		for (int x = 1; x <= t; x++) {
			String line = br.readLine();
			int index = line.indexOf('/');
			long a = Long.parseLong(line.substring(0, index));
			long b = Long.parseLong(line.substring(index + 1));
			long gdc = gdc(a, b);
			if (gdc > 1) {
				a /= gdc;
				b /= gdc;
			}

			long bb = b;
			int k = 0;
			boolean ok = true;
			while (bb > 1) {
				if ((bb & 1) != 0) {
					ok = false;
					break;
				}
				k++;
				bb /= 2;
			}

			if (!ok) {
				sb.append("Case #" + x + ": impossible\n");
			} else {
				a *= (1L << (40 - k));
				long v = 1;
				k = 0;
				while (v <= a) {
					v *= 2;
					k++;
				}
				sb.append("Case #" + x + ": " + (40 - k + 1) + "\n");
			}

		}
		BufferedWriter bw = new BufferedWriter(new FileWriter("ii/outAJam.txt"));
		bw.write(sb.toString());
		bw.close();
		System.out.println(sb.toString());
	}

	public static int[] readArrayLine(String line, int n) {
		int[] ret = new int[n];
		int start = 0;
		int end = line.indexOf(' ', start);
		for (int i = 0; i < n; i++) {
			if (end > 0)
				ret[i] = Integer.parseInt(line.substring(start, end));
			else
				ret[i] = Integer.parseInt(line.substring(start));
			start = end + 1;
			end = line.indexOf(' ', start);
		}
		return ret;
	}
}
