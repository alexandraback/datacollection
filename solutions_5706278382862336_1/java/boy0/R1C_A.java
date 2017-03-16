package boy0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class R1C_A {
	// Problem A. Part Elf
	public static void main(String[] args) throws IOException {
		String strLine;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		R1C_A me = new R1C_A();

//		me.init();

		strLine = br.readLine();
		int T = Integer.parseInt(strLine);
		String[] as;
		long p, q;
		int y;
		for (int x = 1; x <= T; x++) {
			strLine = br.readLine();
			as = strLine.split("/");
			p = Long.parseLong(as[0]);
			q = Long.parseLong(as[1]);
			y = me.exec1(p, q);
			if (y == -1) {
				System.out.println("Case #" + x + ": impossible");
			} else {
				System.out.println("Case #" + x + ": " + y);
			}
		}
	}

	public int exec1(long p, long q) {
		int p0 = count_end_0bit(p);
		int q0 = count_end_0bit(q);
		int y = q0 - p0;
		
		q = q >> q0;
		if (q != 1) {
			p = p >> p0;
			if (p%q != 0) {
				return -1;	// impossible
			} else {
				y -= count_bit(p/q) - 1;
			}
		} else {
			y -= count_bit(p) - 1;
		}

		return y;
	}

	private int count_end_0bit(long num) {
		int count = 0;
		if (num == 0) return 0;
		while (true) {
			if ((num & 1) == 0) {
				count++;
				num = num >> 1;
			} else {
				break;
			}
		}
		return count;
	}
	
	private int count_bit(long num) {
		int count = 0;
		if (num == 0) return 0;
		while (num > 0) {
			count++;
			num = num >> 1;
		}
		return count;
	}

}
