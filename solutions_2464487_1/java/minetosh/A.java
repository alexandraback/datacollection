import java.io.*;
import java.util.*;
import java.math.*;

public class A {
	public static void main(String args[]) {
		try {
			InputStreamReader isr = null;
			try {
				isr = new InputStreamReader(System.in, "UTF-8");
				BufferedReader br = null;
				try {
					br = new BufferedReader(isr);
					new A().go(br);
				} finally {
					if (br != null) br.close();
				}
			} finally {
				if (isr != null) isr.close();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public void go(BufferedReader br) throws Exception {
		int num = Integer.parseInt(br.readLine());
		for (int n = 1; n <= num; n++)
			solve(n, br);
	}

	public void solve(int num, BufferedReader br) throws Exception {
		String lines[] = br.readLine().split(" ");
		long r = Long.parseLong(lines[0]);
		long t = Long.parseLong(lines[1]);

		long hani1 = 0;
		long hani2 = 1000000000000000000L;
		long hanin = 1;
		for (int i = 0; i < 10000; i++) {
			hanin = (hani1 + hani2) / 2;
			BigDecimal manaka = func(r, t, hanin);
			if (manaka.signum() == 1)
				hani2 = hanin;
			else
				hani1 = hanin;
		}
		System.out.println("Case #" + num + ": " + hanin);
	}

	public BigDecimal func(long r, long t, long n) {
		BigDecimal br = new BigDecimal(r);
		BigDecimal bt = new BigDecimal(t);
		BigDecimal bn = new BigDecimal(n);
		BigDecimal b2 = new BigDecimal(2);
		BigDecimal b3 = new BigDecimal(3);
		BigDecimal bpi = new BigDecimal(Math.PI);

		BigDecimal mae = br.multiply(b2).add(b3.negate()).multiply(bn);
		BigDecimal ato = bn.add(BigDecimal.ONE).multiply(bn).multiply(b2);
		return mae.add(ato).add(bt.negate());
	}
}
