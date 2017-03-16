import java.io.*;
import java.util.*;

public class C {
	public static void main(String args[]) {
		try {
			InputStreamReader isr = null;
			try {
				isr = new InputStreamReader(System.in, "UTF-8");
				BufferedReader br = null;
				try {
					br = new BufferedReader(isr);
					new C().go(br);
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
		ArrayList<Long> ksArray = new ArrayList<Long>();
		for (long n = 1; n <= 10000000; n++) {
			if (isKaibun(n))
				if (isKaibun(n * n))
					ksArray.add(n * n);
		}
		System.out.println(ksArray);
		Long ksL[] = ksArray.toArray(new Long[0]);
		long ks[] = new long[ksL.length];
		for (int i = 0; i < ksL.length; i++)
			ks[i] = ksL[i].longValue();

		int num = Integer.parseInt(br.readLine());
		String lines[] = null;
		for (int n = 1; n <= num; n++) {
			lines = br.readLine().split(" ");
			long a = Long.parseLong(lines[0]);
			long b = Long.parseLong(lines[1]);
			solve(n, ks, a, b);
		}
	}

	public boolean isKaibun(long n2) {
		String n2s = new Long(n2).toString();
		int l = n2s.length();
		for (int i = 0; i < l / 2; i++)
			if (n2s.charAt(i) != n2s.charAt(l - 1 - i))
				return false;
		return true;
	}

	public void solve(int n, long ks[], long a, long b) {
		int mae = Arrays.binarySearch(ks, a);
		if (mae >= 0)
			mae = mae;
		else
			mae = -(mae + 1);

		int ato = Arrays.binarySearch(ks, b);
		if (ato >= 0)
			ato = ato + 1;
		else
			ato = -(ato + 1);

		System.out.println("Case #" + n + ": " + (ato - mae));
	}
}
