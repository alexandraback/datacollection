package boy0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Vector;

// Problem A. Osmos
public class R1B_A {

	public static void main(String[] args) throws IOException {
		String strLine;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		R1B_A me = new R1B_A();

		// me.init();

		strLine = br.readLine();
		int T = Integer.parseInt(strLine);
		String[] as;
		long a;
		int n;
		Vector<Long> nv;
		int y;
		for (int x = 1; x <= T; x++) {
			strLine = br.readLine();
			as = strLine.split(" ");
			a = Long.parseLong(as[0]);
			n = Integer.parseInt(as[1]);
			nv = new Vector<Long>(n);
			strLine = br.readLine();
			as = strLine.split(" ");
			for (int i = 0; i < n; i++) {
				nv.add(Long.parseLong(as[i]));
			}
			Collections.sort(nv);
			min_op = Integer.MAX_VALUE;
			y = me.osmos(a, nv, 0);
			System.out.println("Case #" + x + ": " + y);
		}
	}

	private static int min_op = 0;

	public int osmos(long a, Vector<Long> nv, int op) {
		long mote;
		if (nv.size() > 0) {
			mote = nv.get(0).longValue();
		} else {
			if (op < min_op) {
				min_op = op;
			}
			return min_op;
		}
		while (a > mote) {
			a = a + mote;
			nv.remove(0);
			if (nv.size() > 0) {
				mote = nv.get(0).longValue();
			} else {
				if (op < min_op) {
					min_op = op;
				}
				return min_op;
			}
		}
		// 막힌경우 + or - 두가지 선택
		// +
		if (a > 1) {
			long a2 = a;
			Vector<Long> nv2 = new Vector<Long>(nv);
			int op2 = op;
			while (a2 <= mote) {
				a2 = a2 + a2 - 1;
				op2++;
			}
			osmos(a2, nv2, op2);
		}
		// -
		nv.remove(0);
		osmos(a, nv, op + 1);

		return min_op;
	}

}
